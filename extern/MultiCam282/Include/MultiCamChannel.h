/*---------------------------------------------------------------------*\
|	This is a part of the Euresys Classes C++ library.					|
|	Copyright (C) Euresys												|
|	All rights reserved.												|
|																		|
|	This source code is only intended as a supplement to the			|
|	samples illustrating the use the driver API and related				|
|	electronic documentation provided at this subject.					|
|	See these sources for detailed information regarding the			|
|	Euresys MultiCam product.											|
\*---------------------------------------------------------------------*/
/*---------------------------------------------------------------------*\
|	MultiCamChannel.h: interface for the CMultiChannel class.			|
|	31/5/2000: First issue			 Godefroid Dislaire					|
|	1.	Macro definitions												|
|	2.	CMultiCamBoard		definition									|
|	3.	CMultiCamBase		definition									|
|	4.	CMultiCamChannel	definition									|
|	5.	CMultiCamProcessor	definition									|
|	6.	static BoarList managment functions								|
|	2.	CMultiCamBoard		implementatuo								|
|	3.	CMultiCamBase													|
|	4.	CMultiCamChannel												|
|	5.	CMultiCamProcessor												|
\*---------------------------------------------------------------------*/
#ifndef _INC_COMMDLG
#include "Commdlg.h"//openfilename
#endif

#pragma warning (disable : 4786)
#include <list>
#pragma warning (default : 4786)

#include <easy.h>
#include <eImage.h>
#include <multicam.h>

#define CHANNEL_CTL 0
#define CHANNEL_VCAM 1
#define CHANNEL_SYNC 2
#define CHANNEL_SCAN 3
#define MAX_BOARD	32
#if !defined(_MULTICHANNEL_H____INCLUDED_)
#define _MULTICHANNEL_H____INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/*=====================================================================*\
|	1.	Macro definitions												|
\*=====================================================================*/

#define INITIALIZE_MULTICAM()\
DWORD CMultiCamBase::s_InstanceNumber=0;\
BOARDLIST	CMultiCamBoard::m_BoardList;
/*---------------------------------------------------------------------*\
|	CMultiCamChannel Macro definitions									|
\*---------------------------------------------------------------------*/
#define DEFINE_MULTICAMCHANNEL_CALLBACK(ClassName,ChannelCallBackFuncName,ReturnType)\
static void _stdcall _##ChannelCallBackFuncName##_eVision(PMCCALLBACKINFO cbInfo)\
{\
	INT32 EImageContext;\
	McGetParamInt(cbInfo->SignalInfo,MC_SurfaceContext,&EImageContext);\
	((ClassName*)cbInfo->Context)->ChannelCallBackFuncName((ReturnType)EImageContext,cbInfo->Signal,(BOOL)cbInfo->Reserved);\
}\
static void _stdcall _##ChannelCallBackFuncName##_Surface(PMCCALLBACKINFO cbInfo)\
{\
	((ClassName*)cbInfo->Context)->ChannelCallBackFuncName((ReturnType)cbInfo ,cbInfo->Signal , (BOOL)cbInfo->Reserved);\
}
#define REGISTER_MULTICAMCHANNEL_CALLBACK(Server,ChannelCallBackFuncName)\
{\
	INT32 type = Server.GetCallBackType();\
	if(type == 1){\
		McRegisterCallback (Server, _##ChannelCallBackFuncName##_eVision, this);\
	}else if(type == 2){\
		McRegisterCallback (Server, _##ChannelCallBackFuncName##_Surface, this);\
	}\
	McSetParamInt(Server, MC_SignalEnable, MC_SignalEnable_PROCESSING);\
}

/*---------------------------------------------------------------------*\
|	CMultiCamProcessor Macro definitions								|
\*---------------------------------------------------------------------*/
#define DEFINE_MULTICAMPROCESSOR_CALLBACK(ClassName,ProcessorCallBackFuncName,ReturnType)\
static void _stdcall _##ProcessorCallBackFuncName##_eVision(PMCCALLBACKINFO cbInfo)\
{\
	INT32 EImageContext;\
	McGetParamInt(cbInfo->SignalInfo,MC_SurfaceContext,&EImageContext);\
	((ClassName*)cbInfo->Context)->ProcessorCallBackFuncName((ReturnType)EImageContext,cbInfo->Signal,(BOOL)cbInfo->Reserved);\
}\
static void _stdcall _##ProcessorCallBackFuncName##_Surface(PMCCALLBACKINFO cbInfo)\
{\
	((ClassName*)cbInfo->Context)->ProcessorCallBackFuncName((ReturnType)cbInfo ,cbInfo->Signal , (BOOL)cbInfo->Reserved);\
}
#define REGISTER_MULTICAMPROCESSOR_CALLBACK(Server,ProcessorCallBackFuncName)\
{\
	INT32 type = 1;\
	if(type == 1){\
		McRegisterCallback (Server, _##ProcessorCallBackFuncName##_eVision, this);\
	}else if(type == 2){\
		McRegisterCallback (Server, _##ProcessorCallBackFuncName##_Surface, this);\
	}\
	McSetParamInt(Server, MC_SignalEnable, MC_SignalEnable_PROCESSING);\
}
/*---------------------------------------------------------------------*\
|	Utilities Macro definitions											|
\*---------------------------------------------------------------------*/
#define CHECKFUNCTION(Function) {MCSTATUS status = Function; if (status != MC_OK) return status;}
enum CallBackTypes{
	CallBackType_undefined = 0,
	CallBackType_eVision,
	CallBackType_User
};

using namespace std ;
class CMultiCamBoard;
class CMultiCamChannel;
class CMultiCamProcessor;
typedef list<CMultiCamBoard*> BOARDLIST;
typedef list<CMultiCamChannel*> CHANNELLIST;
typedef list<CMultiCamProcessor*> PROCESSORLIST;

/*=====================================================================*\
|	2.	CMultiCamBoard definitions										|
\*=====================================================================*/

class CMultiCamBoard{
public:
	//Construction
	CMultiCamBoard(INT32 DriverIndex);
	virtual ~CMultiCamBoard();

	static BOARDLIST		m_BoardList;

protected:
	INT32					m_DriverIndex;
	INT32					m_BoardType;
	INT32					m_BoardSerialNb;
	INT32					m_PciPos;
	char					m_BoardId[64];
	char					m_BoardName[64];
	char					m_BoardEvolutionNb[64];
	char					m_BoardModuleName[64];

	CHANNELLIST				m_ChannelList;
public:
	HRESULT					AddChannel(CMultiCamChannel* pMultiCamChannel);
	HRESULT					RemoveChannel(CMultiCamChannel* pMultiCamChannel);
	HRESULT					IsIdle();
	HRESULT					InitializeParameters();
	INT32					DriverIndex()	{return m_DriverIndex;}
	INT32					BoardType()		{return m_BoardType;}
};
	
/*=====================================================================*\
|	3.	CMultiCamBase definition										|
\*=====================================================================*/

class CMultiCamBase{
public:
	static DWORD	s_InstanceNumber;
	//Construction
	CMultiCamBase();
	virtual ~CMultiCamBase();
protected:
	MCHANDLE				m_hMultiCamObject;
	CMultiCamBoard*			m_pMultiCamBoard;

	void**					m_ppImageBuffer;	
	MCHANDLE*				m_phSurface;
	EGenericROI**			m_ppROIList;
	DWORD					m_SurfaceNumber;

	DWORD					m_ImageSizeX, m_ImageSizeY;
	DWORD					m_ImageSize;
	DWORD					m_PixelSize;
	DWORD					m_SurfaceSizeX, m_SurfaceSizeY;
	DWORD					m_SurfaceSize;

	DWORD					m_CameraMode;

	HRESULT			InitializeDriver();
	HRESULT			MultiCamTerminate();
	
	HRESULT			AddSurfacesToCluster(DWORD SurfaceNumber,MCHANDLE* phSurface=NULL);
	virtual HRESULT			ComputeImageSize();

public:
	operator		MCHANDLE()			{return m_hMultiCamObject;}
	MCHANDLE		GetHdl()			{return m_hMultiCamObject;}
	CMultiCamBoard*	GetBoard()			{return m_pMultiCamBoard;}

	HRESULT			SetParam(MCPARAMID Param, INT32 ValueInt){
						return McSetParamInt(m_hMultiCamObject,Param,ValueInt);
					}
	HRESULT			SetParam(PCCHAR ParamName, INT32 ValueInt){
						return McSetParamNmInt(m_hMultiCamObject,ParamName,ValueInt);
					}
	HRESULT			SetParam(MCPARAMID Param, PCCHAR ValueStr){
						return McSetParamStr(m_hMultiCamObject, Param, ValueStr);
					}
	HRESULT			SetParam(PCCHAR ParamName, PCCHAR ValueStr){
						return McSetParamNmStr(m_hMultiCamObject,ParamName,ValueStr);
					}
	HRESULT			SetParam(MCPARAMID Param, FLOAT64 ValueFloat){		
						return McSetParamFloat(m_hMultiCamObject, Param, ValueFloat);
					}
	HRESULT			SetParam(PCCHAR ParamName, FLOAT64 ValueFloat){
						return McSetParamNmFloat(m_hMultiCamObject, ParamName, ValueFloat);
					}
	HRESULT			SetParam(MCPARAMID Param, MCHANDLE ValueInst){
						return McSetParamInst(m_hMultiCamObject, Param, ValueInst);
					}
	HRESULT			SetParam(PCCHAR ParamName, MCHANDLE ValueInst){
						return McSetParamNmInst(m_hMultiCamObject, ParamName, ValueInst);
					}

	HRESULT			GetParam(MCPARAMID Param, PINT32 pValueInt){
						return McGetParamInt(m_hMultiCamObject, Param, pValueInt);
					}
	HRESULT			GetParam(PCCHAR ParamName, PINT32 pValueInt){
						return McGetParamNmInt(m_hMultiCamObject,ParamName,pValueInt);
					}
	HRESULT			GetParam(MCPARAMID Param, PCHAR ValueStr, UINT32 MaxLength){
						return McGetParamStr(m_hMultiCamObject,Param,ValueStr,MaxLength);
					}
	HRESULT			GetParam(PCCHAR ParamName, PCHAR ValueStr, UINT32 MaxLength){
						return McGetParamNmStr(m_hMultiCamObject,ParamName, ValueStr,MaxLength);
					}
	HRESULT			GetParam(MCPARAMID Param, PFLOAT64 pValueFloat){
						return McGetParamFloat(m_hMultiCamObject,Param,pValueFloat);
					}
	HRESULT			GetParam(PCCHAR ParamName, PFLOAT64 pValueFloat){
						return McGetParamNmFloat(m_hMultiCamObject,ParamName,pValueFloat);
					}
	HRESULT			GetParam(MCPARAMID Param, PMCHANDLE hValueInst){
						return McGetParamInst(m_hMultiCamObject,Param,hValueInst);
					}
	HRESULT			GetParam(PCCHAR ParamName, PMCHANDLE hValueInst){
						return McGetParamNmInst(m_hMultiCamObject,ParamName,hValueInst);
					}

	EGenericROI*	GetImage(unsigned long Index){
						if(m_ppROIList!=NULL) 
							return m_ppROIList[(Index+m_SurfaceNumber)%m_SurfaceNumber];
						return NULL;
					}
	void*			GetBuffer(unsigned long Index){
						if(m_ppImageBuffer!=NULL)
							return m_ppImageBuffer[(Index+m_SurfaceNumber)%m_SurfaceNumber];
						return NULL;
					}
	SIZE			ImageSize()			{SIZE sz ={m_ImageSizeX, m_ImageSizeY};return sz;}
	DWORD			BufferSize()		{return m_ImageSize;}
	SIZE			SurfaceSize()		{SIZE sz ={m_SurfaceSizeX, m_SurfaceSizeY};return sz;}
	DWORD			PixelSize()			{return m_PixelSize;}
	DWORD			CameraMode()		{return m_CameraMode;}
};

/*=====================================================================*\
|	4.	CMultiCamChannel definition										|
\*=====================================================================*/

class CMultiCamChannel : public CMultiCamBase
{
public:
//Construction
	CMultiCamChannel();
	virtual ~CMultiCamChannel();

protected:
	CMultiCamProcessor*		m_pProcessor;

	DWORD					m_CallBackType;
	BOOL					m_bMemoryAllocatedByUser;	

	TCHAR					m_CameraDirectory[MAX_PATH];
	TCHAR					m_MpfFullPath[MAX_PATH];
	TCHAR					m_CamFullPath[MAX_PATH];
	TCHAR					m_MpfName[MAX_PATH];
	TCHAR					m_CamName[MAX_PATH];

	INT32					m_ErrorMode;
protected:
//internal function
	HRESULT					LinkToBoard(int Board);
	HRESULT					SearchCamMpf(TCHAR* Model, TCHAR* Cam, TCHAR* GammaConnector);
	HRESULT					PreCreate_Mpf_Cam_Board(const TCHAR* Model, 
											const TCHAR* Cam,
											const TCHAR* Directory = NULL,
											int Board=0);
	HRESULT					CreateSurfaces(DWORD SurfaceNumber);
	HRESULT					CreateSurfacesFromROIList(DWORD SurfaceNumber,EGenericROI** ppROIList);

public:
//public functions
	HRESULT				Create(	unsigned long SurfaceNumber=3,
							int Board=0,
							TCHAR* GammaConnector = NULL);
	HRESULT				Create(	EGenericROI** ppROIList,
							unsigned long SurfaceNumber,
							INT32 Board=0,
							TCHAR* GammaConnector = NULL);
	HRESULT				Create(	MCHANDLE* phSurface,			//MCHANDLE or ECHANDLE are UINT32 
							unsigned long SurfaceNumber,
							INT32 Board=0,
							TCHAR* GammaConnector = NULL);
	HRESULT				Create(	const TCHAR* Model, // as GammaConnector
							const TCHAR* Cam,							
							unsigned long SurfaceNumber=3,
							const TCHAR* Directory = NULL,
							int Board=0);
	HRESULT				Create(	const TCHAR* Model, // as GammaConnector
							const TCHAR* Cam,							
							EGenericROI** ppROIList,
							unsigned long SurfaceNumber,
							const TCHAR* Directory = NULL,
							INT32 Board=0);
	HRESULT				Create(	const TCHAR* Model, // as GammaConnector 
							const TCHAR* Cam,							
							MCHANDLE* phSurface,			//MCHANDLE or ECHANDLE are UINT32 
							unsigned long SurfaceNumber,
							const TCHAR* Directory = NULL,
							INT32 Board=0);


	HRESULT				Grab(DWORD GrabCount=1);
	HRESULT				Live();
	HRESULT				Stop();

	HRESULT				AttachProcessor(CMultiCamProcessor* pProcessor);
	void				DetachProcessor()	{m_pProcessor = NULL;}

	CMultiCamProcessor* Processor()			{return m_pProcessor;};
	
	LPTSTR				CameraDirectory()	{return m_CameraDirectory;};
	LPTSTR				MpfFullPath()		{return m_MpfFullPath;};
	LPTSTR				CamFullPath()		{return m_CamFullPath;};
	LPTSTR				MpfName()			{return m_MpfName;};
	LPTSTR				CamName()			{return m_CamName;};

	int					GetCallBackType()	{return m_CallBackType;}

	INT32			State(){ 
						INT32 State; 
						McGetParamInt (m_hMultiCamObject, MC_ChannelState,&State); 
						return State;
					}	

	HRESULT			SetErrorMode(INT32	ErrorMode){
						m_ErrorMode = ErrorMode;
						if (m_hMultiCamObject !=NULL)
							return McSetParamInt(MC_CONFIGURATION,MC_ErrorHandling,m_ErrorMode);
						return E_FAIL;
					}
};

/*=====================================================================*\
|	5.	CMultiCamProcessor definition									|
\*=====================================================================*/


class CMultiCamProcessor : public CMultiCamBase {
public:
	CMultiCamProcessor();
	virtual ~CMultiCamProcessor();

	CMultiCamChannel*	m_pChannel;

	INT32				m_ProcessorId;

	INT32				ProcessorId()			{return m_ProcessorId;}

	virtual HRESULT		ComputeImageSize();
	HRESULT				Create(CMultiCamChannel* pChannel,LPCTSTR SpeedyName,INT32 ProcessorId = 0);
	HRESULT				AddSurfaces(DWORD SurfaceNumber, DWORD	ColorFormat);
};

/*=====================================================================*\
|	6.	static BoardList managment functions							|
\*=====================================================================*/

static void __stdcall DeleteMultiCamBoardList(){
	BOARDLIST::iterator iter;
	if(CMultiCamBoard::m_BoardList.empty())
		return;
	for(iter =  CMultiCamBoard::m_BoardList.begin();
		iter != CMultiCamBoard::m_BoardList.end();++iter){
		if((*iter)!= NULL) 
			delete (*iter);
	}
	CMultiCamBoard::m_BoardList.clear();
};
static HRESULT __stdcall GetMultiCamBoardPtr(DWORD DriverIndex,CMultiCamBoard* &pMultiCamBoard){
	pMultiCamBoard = NULL;
	BOARDLIST::iterator iter;
	if(!CMultiCamBoard::m_BoardList.empty()){
		for(iter =  CMultiCamBoard::m_BoardList.begin();
			iter != CMultiCamBoard::m_BoardList.end();++iter){
				if((*iter)->DriverIndex()==DriverIndex){ 
					pMultiCamBoard = *iter;
					return S_OK;
				}
		}
	}
	
	pMultiCamBoard = new CMultiCamBoard(DriverIndex);
	pMultiCamBoard->InitializeParameters();
	CMultiCamBoard::m_BoardList.insert(CMultiCamBoard::m_BoardList.end(),pMultiCamBoard);
	return S_OK;
}

/*=====================================================================*\
|	7.	CMultiCamBoard implementation									|
\*=====================================================================*/

inline CMultiCamBoard::CMultiCamBoard(INT32 DriverIndex){
	m_ChannelList.clear();
	m_DriverIndex = DriverIndex;
	m_BoardType = 0;
}
inline CMultiCamBoard::~CMultiCamBoard(){
}
inline HRESULT CMultiCamBoard::IsIdle(){
	INT32 state;
	CHANNELLIST::iterator iter;
	if(m_ChannelList.empty())
		return S_OK;
	for(iter =  m_ChannelList.begin(); iter != m_ChannelList.end();++iter){
		(*iter)->GetParam(MC_ChannelState, &state);
		if(state == MC_ChannelState_ACTIVE){ 
			MessageBox(NULL,"In order to create a new channel,\nall channels must be stopped",NULL,MB_OK);
			return E_FAIL;
		}
	}
	return S_OK;
}
inline HRESULT CMultiCamBoard::InitializeParameters(){
	MCSTATUS status;
	status = McSetParamInt(MC_CONFIGURATION, MC_DriverIndex, m_DriverIndex);
	status = McGetParamStr(MC_CONFIGURATION, MC_BoardIdentifier, m_BoardId, sizeof(m_BoardId));
	status = McGetParamInt(MC_CONFIGURATION, MC_BoardType, &m_BoardType);
	status = McGetParamStr(MC_CONFIGURATION, MC_NameBoard, m_BoardName, sizeof(m_BoardName));
	status = McGetParamInt(MC_CONFIGURATION, MC_SerialNumber, &m_BoardSerialNb);
	status = McGetParamStr(MC_CONFIGURATION, MC_EvolutionNumber, m_BoardEvolutionNb, sizeof(m_BoardEvolutionNb));

	status = McGetParamStr(MC_CONFIGURATION, MC_ModuleType, m_BoardModuleName, sizeof(m_BoardModuleName));
	status = McGetParamInt(MC_CONFIGURATION, MC_PciPosition, &m_PciPos);
	return S_OK;
}
inline HRESULT CMultiCamBoard::AddChannel(CMultiCamChannel* pMultiCamChannel){
	MCSTATUS status = McSetParamInt(pMultiCamChannel->GetHdl(), MC_DriverIndex, m_DriverIndex);
	if(status == MC_OK){
		m_ChannelList.insert(m_ChannelList.end(),pMultiCamChannel);
		return S_OK;
	}
	AfxMessageBox("Cannot link the new channel with selected board", MB_ICONERROR | MB_OK);
	return E_FAIL;
}

inline HRESULT CMultiCamBoard::RemoveChannel(CMultiCamChannel* pMultiCamChannel){
	CHANNELLIST::iterator iter;
	if(m_ChannelList.empty())
		return E_FAIL;
	for(iter =  m_ChannelList.begin(); iter != m_ChannelList.end();++iter){
		if((*iter) == pMultiCamChannel){ 
			iter = m_ChannelList.erase(iter);
		}
	}
	return S_OK;
}

/*=====================================================================*\
|	8.	CMultiCamBase implementation									|
\*=====================================================================*/

inline CMultiCamBase::CMultiCamBase(){	
	m_hMultiCamObject = NULL;
	m_pMultiCamBoard = NULL;
	if(s_InstanceNumber++==0){
		CMultiCamBoard::m_BoardList.clear();
		InitializeDriver();
	}
}
inline CMultiCamBase::~CMultiCamBase(){
	s_InstanceNumber--;

	if(s_InstanceNumber==0){
		DeleteMultiCamBoardList();
		MultiCamTerminate();
	}
}
inline HRESULT	CMultiCamBase::AddSurfacesToCluster(DWORD SurfaceNumber,MCHANDLE* phSurface){
	if (phSurface == NULL)
		return E_FAIL;
	for (DWORD i=0; i<SurfaceNumber ;i++){
		// Associate surface with channel
		CHECKFUNCTION(McSetParamInst(m_hMultiCamObject, MC_Cluster+i, phSurface[i]))
	}
	// Set Channel to AUTO cluster mode 
	CHECKFUNCTION(McSetParamInt (m_hMultiCamObject, MC_ClusterMode, MC_ClusterMode_AUTO)) 

	return S_OK;
}
inline HRESULT CMultiCamBase::ComputeImageSize(){
	// Retrieve image parameters
	CHECKFUNCTION(McGetParamInt(m_hMultiCamObject, MC_ImageSizeX, (int*)&m_ImageSizeX))
	CHECKFUNCTION(McGetParamInt(m_hMultiCamObject, MC_ImageSizeY, (int*)&m_ImageSizeY))
	// Check the pixel-size
	CHECKFUNCTION(McGetParamInt(m_hMultiCamObject, MC_ImagePixelSize, (int*)&m_PixelSize))
	m_ImageSize = m_ImageSizeY * m_ImageSizeX * m_PixelSize;
	return S_OK;
}
/*---------------------------------------------------------------------*\
|	functions depending on the static (i.e. unique for all instances of	|
|	the class) variable counter s_InstanceNumber. for earch instance	|
|	creation/destruction, the counter changes (++/--).		 			|
|	s_InstanceNumber:  0--->1 => InitializeDriver()						|
|	s_InstanceNumber:  1--->0 => MultiCamTerminate()					|
\*---------------------------------------------------------------------*/
inline HRESULT	CMultiCamBase::MultiCamTerminate(){
	// Disable image acquisitions
	//CHECKFUNCTION(McStopAcq())
	// Terminate communication with the driver
	CHECKFUNCTION(McCloseDriver())
	::Beep(500,20);
	return S_OK ;	
}

inline HRESULT	CMultiCamBase::InitializeDriver(){
	// Establish communication with the driver
	MCSTATUS status;

	status = McOpenDriver(NULL);

	if (status != MC_OK) {
		AfxMessageBox("Cannot open driver", MB_ICONERROR | MB_OK);
		return FALSE;
	}
	// Enable image acquisitions
	CHECKFUNCTION( McStartAcq())

	return S_OK;	
}

/*=====================================================================*\
|	9.	CMultiCamChannel implementation									|
\*=====================================================================*/

/*---------------------------------------------------------------------*\
|	Constructor/destructor												|
\*---------------------------------------------------------------------*/
inline CMultiCamChannel::CMultiCamChannel(){
	m_pProcessor = NULL;

	m_phSurface = NULL;
	m_ppImageBuffer = NULL;
	m_ppROIList = NULL;
	m_ImageSizeX = m_ImageSizeY =0;
	m_SurfaceSizeX = m_SurfaceSizeY = m_SurfaceSize = 0;
	m_PixelSize = 0;
	m_SurfaceNumber = 3;
	m_CallBackType = 0;
	m_bMemoryAllocatedByUser = FALSE;
	m_ErrorMode = MC_ErrorHandling_MSGBOX;
	m_CameraMode = 0;
}
inline CMultiCamChannel::~CMultiCamChannel(){
	MCSTATUS status = McSetParamInt (m_hMultiCamObject, MC_ChannelState, MC_ChannelState_IDLE); 
	if (status != MC_OK) return;
	
	status = McDelete(m_hMultiCamObject);
	if (status != MC_OK) return;

	if(m_phSurface){
		for(DWORD i=0;i<m_SurfaceNumber;i++){
			status = McDelete(m_phSurface[i]);
			if (status != MC_OK) return;
		}
		delete m_phSurface;
		m_phSurface = NULL;
	}
	if(m_bMemoryAllocatedByUser ==FALSE){
		if(m_ppROIList!=NULL){
			for( DWORD i = 0; i<m_SurfaceNumber;i++){
				if(m_ppROIList[i] !=NULL){
					delete m_ppROIList[i];
				}
			}
			delete m_ppROIList;
			m_ppROIList = NULL;
		}		
		if(m_ppImageBuffer!=NULL){
			for( DWORD i = 0; i<m_SurfaceNumber;i++){
				if (m_ppImageBuffer[i]!=NULL)
					VirtualFree(m_ppImageBuffer[i], 0, MEM_RELEASE);
			}
			delete m_ppImageBuffer;
			m_ppImageBuffer = NULL;
		}
	}
	if(m_pMultiCamBoard != NULL)
		m_pMultiCamBoard->RemoveChannel(this);
}

/*---------------------------------------------------------------------*\
|	Channel creation functions											|
|		Create call PreCreate_Mpf_Cam_Board								|
|					CreateSurfaces										|
\*---------------------------------------------------------------------*/

inline HRESULT	CMultiCamChannel::SearchCamMpf(TCHAR* Model, TCHAR* Cam, TCHAR* GammaConnector){
	TCHAR ModelFullPath[MAX_PATH]= "\0";
	TCHAR CamFullPath[MAX_PATH]= "\0";
	OPENFILENAME ofn;       // common dialog box structure
	
	if((m_pMultiCamBoard->BoardType() > 3) && (GammaConnector == NULL)){
		MessageBox(NULL,"you must specify the GammaConnector parameter",NULL,MB_OK);
		return E_FAIL;
	}
	if(m_pMultiCamBoard->BoardType() <= 3){
		// Initialize OPENFILENAME
		ZeroMemory(&ofn, sizeof(OPENFILENAME));
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.hwndOwner = NULL;
		ofn.lpstrFile = ModelFullPath;
		ofn.nMaxFile = sizeof(ModelFullPath);
		ofn.lpstrFilter = "Model\0*.mpf\0";
		ofn.nFilterIndex = NULL;
		ofn.lpstrFileTitle = Model;
		ofn.nMaxFileTitle = MAX_PATH;
		ofn.lpstrInitialDir = m_CameraDirectory;
		ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST| OFN_PATHMUSTEXIST;
		// Display the Open dialog box. 
		if (GetOpenFileName(&ofn)!=TRUE)	
			return E_FAIL;			

	}else{
		_tcscpy(Model, GammaConnector);
	}
	// Initialize OPENFILENAME
	ZeroMemory(&ofn, sizeof(OPENFILENAME));
	ofn.lStructSize = sizeof(OPENFILENAME);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = CamFullPath;
	ofn.nMaxFile = sizeof(CamFullPath);
	ofn.lpstrFilter = "0Camera\0*.cam\0";
	ofn.nFilterIndex = NULL;
	ofn.lpstrFileTitle = Cam;
	ofn.nMaxFileTitle = MAX_PATH;
	ofn.lpstrInitialDir = m_CameraDirectory;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	// Display the Open dialog box. 
	if (GetOpenFileName(&ofn)!=TRUE)
		return E_FAIL;

	return S_OK;
}
inline HRESULT	CMultiCamChannel::Create(	unsigned long SurfaceNumber,
											int Board,
											TCHAR* GammaConnector){
	if(LinkToBoard(Board) == E_FAIL)
		return E_FAIL;
	TCHAR Model[MAX_PATH]= "\0";
	TCHAR Cam[MAX_PATH]= "\0";
	if(SearchCamMpf(Model,Cam, GammaConnector)!=S_OK)
		return E_FAIL;
	return Create( Model,Cam,SurfaceNumber,NULL,Board);
}

inline HRESULT	CMultiCamChannel::Create(	const TCHAR* Model, 
											const TCHAR* Cam,							
											unsigned long SurfaceNumber,
											const TCHAR* Directory,
											int Board){
	if(LinkToBoard(Board) == E_FAIL)
		return E_FAIL;
	m_CallBackType=	CallBackType_eVision;
	m_bMemoryAllocatedByUser = FALSE;

	m_SurfaceNumber=SurfaceNumber;

	if(PreCreate_Mpf_Cam_Board(Model,Cam,Directory,Board)!=S_OK)
		return E_FAIL;
	if(CreateSurfaces(SurfaceNumber)!=S_OK)
		return E_FAIL;
	if(CreateSurfacesFromROIList(SurfaceNumber,m_ppROIList)!=S_OK)
		return E_FAIL;
	return AddSurfacesToCluster(SurfaceNumber,m_phSurface);
}
inline HRESULT	CMultiCamChannel::Create(	EGenericROI** ppROIList,
											unsigned long SurfaceNumber,
											INT32 Board,
											TCHAR* GammaConnector){
	if(LinkToBoard(Board) == E_FAIL)
		return E_FAIL;
	TCHAR Model[MAX_PATH]= "\0";
	TCHAR Cam[MAX_PATH]= "\0";

	return Create(Model, Cam,ppROIList,SurfaceNumber,NULL,Board);
}

inline HRESULT	CMultiCamChannel::Create(	const TCHAR* Model, 
											const TCHAR* Cam,
											EGenericROI** ppROIList,
											unsigned long SurfaceNumber,
											const TCHAR* Directory,
											INT32 Board){
	if(LinkToBoard(Board) == E_FAIL)
		return E_FAIL;
	m_CallBackType=CallBackType_eVision;
	m_bMemoryAllocatedByUser = TRUE;

	m_ppROIList = ppROIList;
	m_SurfaceNumber=SurfaceNumber;	

	if(PreCreate_Mpf_Cam_Board(Model,Cam,Directory,Board)!=S_OK)
		return E_FAIL;
	if(CreateSurfacesFromROIList(m_SurfaceNumber,m_ppROIList)!=S_OK)
		return E_FAIL;
	return AddSurfacesToCluster(m_SurfaceNumber,m_phSurface);
}
inline HRESULT	CMultiCamChannel::Create(	MCHANDLE* phSurface,
											unsigned long SurfaceNumber,
											INT32 Board,
											TCHAR* GammaConnector){
	if(LinkToBoard(Board) == E_FAIL)
		return E_FAIL;
	TCHAR Model[MAX_PATH]= "\0";
	TCHAR Cam[MAX_PATH]= "\0";
	if(SearchCamMpf(Model,Cam, GammaConnector)!=S_OK)
		return E_FAIL;
	return Create(Model, Cam,phSurface,SurfaceNumber,NULL,Board);
}
inline HRESULT	CMultiCamChannel::Create(	const TCHAR* Model, 
											const TCHAR* Cam,
											MCHANDLE* phSurface,
											unsigned long SurfaceNumber,
											const TCHAR* Directory,
											INT32 Board){
	if(LinkToBoard(Board) == E_FAIL)
		return E_FAIL;
	m_CallBackType=CallBackType_User;
	m_bMemoryAllocatedByUser = TRUE;
	
	m_SurfaceNumber=SurfaceNumber;

	if(PreCreate_Mpf_Cam_Board(Model,Cam,Directory,Board)!=S_OK)
		return E_FAIL;
	return AddSurfacesToCluster(m_SurfaceNumber,phSurface);
}
/*-------------------------------------------------------------*\
|		CallBackType			m_bMemoryAllocatedByUser
|		eVision					FALSE
|		eVision					TRUE
|		User					TRUE
\*-------------------------------------------------------------*/
inline HRESULT	CMultiCamChannel::LinkToBoard(int Board){
	if(GetMultiCamBoardPtr(Board,m_pMultiCamBoard)!=S_OK){
		MessageBox(NULL,"No Board corresponding to DriverIndex",NULL,MB_OK);
		return E_FAIL;
	}
	return S_OK;
}
inline HRESULT	CMultiCamChannel::PreCreate_Mpf_Cam_Board(
									const TCHAR* Model, 
									const TCHAR* Cam,
									const TCHAR* Directory,
									int Board){

	if(m_pMultiCamBoard->IsIdle()!=S_OK)
		return E_FAIL;

	if(Directory!=NULL)
		_tcscpy(m_CameraDirectory,Directory);
	else{
		//find camera folder path
		m_CameraDirectory[0] = 0;
		HKEY hKey;
		DWORD valueType, valueSize;
		if (RegOpenKeyEx(HKEY_CURRENT_USER,
						 "Software\\EURESYS\\EasyGrab\\Settings",
						 0,
						 KEY_READ,
						 &hKey) == ERROR_SUCCESS) {
			valueSize = sizeof(m_CameraDirectory);
			if (RegQueryValueEx(hKey, "CUSTOM_CAMERAS", NULL, &valueType, (LPBYTE)m_CameraDirectory, &valueSize) != ERROR_SUCCESS ||
				valueType != REG_SZ)
				m_CameraDirectory[0] = 0;
			RegCloseKey(hKey);
		}
	}
	
	_tcscpy(m_CamName,Cam);
	_stprintf(m_CamFullPath,"%s\\%s",m_CameraDirectory,m_CamName);

	TCHAR ModelTest[30];
	int a,b,c,d;

	if(m_pMultiCamBoard->BoardType()<=3){		//Multi 
		_tcscpy(m_MpfName,Model);
		_stprintf(m_MpfFullPath,"%s\\%s",m_CameraDirectory,m_MpfName); 
		//ChannelMode:		
		_tcscpy(ModelTest,m_MpfName);
	}else{										//Gamma
		_tcscpy(m_MpfFullPath,Model);
		//ChannelMode:
		GetParam(MC_Operation,ModelTest,30);		
	}
	a= _tcsnicmp(ModelTest,"Scan",4);
	b= _tcsnicmp(ModelTest,"Ctl",3);
	c= _tcsnicmp(ModelTest,"Sync",4);
	d= _tcsnicmp(ModelTest,"Vcam",4);
	if (a==0) // Mode Scan
		m_CameraMode = CHANNEL_SCAN;
	if (b==0)
		m_CameraMode = CHANNEL_CTL;
	if (c==0)
		m_CameraMode = CHANNEL_SYNC;//Mode Sync
	if (d==0)
		m_CameraMode = CHANNEL_VCAM;//Mode Vcam


	SetErrorMode(m_ErrorMode);	
	//========================================================================
	// Channel(s) creation									--->>>
	//	
	CHECKFUNCTION(McCreateNm(m_MpfFullPath, &m_hMultiCamObject))
	//
	// Channel(s) creation									<<<---	
	//========================================================================

	//========================================================================
	// Channel(s) initialization								--->>>
	//	
	// Load cam file if needed
	CHECKFUNCTION(McSetParamStr(m_hMultiCamObject, MC_CamFile, m_CamFullPath))

	// Associate with a board
	return m_pMultiCamBoard->AddChannel(this);
	// default error handling to MSGBOX - user can be modify m_ErrorType  before 
	// creation by SetErrorMode(INT32	ErrorHandlingMode)
	//
	// Channel(s) initialization								<<<---	
	//========================================================================
}
/*-------------------------------------------------------------*\
|		CallBackType			m_bMemoryAllocatedByUser
|		eVision					FALSE
\*-------------------------------------------------------------*/
inline HRESULT	CMultiCamChannel::CreateSurfaces(DWORD SurfaceNumber){	
	if(m_ppImageBuffer==NULL)
		m_ppImageBuffer = new PVOID[SurfaceNumber];
	m_ppROIList = new EGenericROI*[SurfaceNumber];
	ComputeImageSize();
	for (DWORD i=0; i<SurfaceNumber ;i++){
		m_ppImageBuffer[i] = VirtualAlloc(NULL, m_ImageSize, MEM_COMMIT, PAGE_READWRITE);
		if (m_ppImageBuffer [i] == NULL) {
			//DisplayError("Cannot allocate image buffer", 0);
			return E_FAIL;
		}		
		// Set the EImage... object to the appropriate size 
		switch (m_PixelSize){
			case 1:// 8-bit monochrome
				m_ppROIList[i] = new EImageBW8(m_ImageSizeX,m_ImageSizeY);
				((EImageBW8*)m_ppROIList[i])->SetImagePtr(m_ppImageBuffer[i]);
				break;
			case 2:// 16-bit monochrome
				m_ppROIList[i] = new EImageBW16(m_ImageSizeX,m_ImageSizeY);
				((EImageBW16*)m_ppROIList[i])->SetImagePtr(m_ppImageBuffer[i]);
				break;
			case 3:	// 24 bits RGB color
				m_ppROIList[i] = new EImageC24(m_ImageSizeX,m_ImageSizeY);
				((EImageC24*)m_ppROIList[i])->SetImagePtr(m_ppImageBuffer[i]);
				break;
			default:
				return E_FAIL;
		}
	}
	return S_OK;
}
/*-------------------------------------------------------------*\
|		CallBackType			m_bMemoryAllocatedByUser
|		eVision					FALSE
|		eVision					TRUE
\*-------------------------------------------------------------*/
inline HRESULT	CMultiCamChannel::CreateSurfacesFromROIList(DWORD SurfaceNumber,EGenericROI** ppROIList){
	ComputeImageSize();
	if(m_phSurface==NULL)
		m_phSurface = new MCHANDLE[SurfaceNumber];
	if(m_ppImageBuffer==NULL){
		m_ppImageBuffer = new PVOID[SurfaceNumber];
		for (DWORD i=0; i<SurfaceNumber ;i++){
			switch (m_PixelSize){
				case 1:// 8-bit monochrome
					m_ppImageBuffer[i]=((EImageBW8*)ppROIList[i])->GetImagePtr();
					break;
				case 2:// 16-bit monochrome
					m_ppImageBuffer[i]=((EImageBW16*)ppROIList[i])->GetImagePtr();
					break;
				case 3:	// 24 bits RGB color
					m_ppImageBuffer[i]=((EImageC24*)ppROIList[i])->GetImagePtr();
					break;
				default:
					//DisplayError("Unsupported image format", 0);
					return E_FAIL;
			}			
		}
	}
	for (DWORD i=0; i<SurfaceNumber ;i++){
		// Create a surface
		CHECKFUNCTION(McCreate (MC_DEFAULT_SURFACE_HANDLE, &m_phSurface[i]))

		// Set surface parameters
		DWORD ImageSize=(INT32)ppROIList[i]->GetWidth()*(INT32)ppROIList[i]->GetHeight()*m_PixelSize;
		CHECKFUNCTION(McSetParamInt(m_phSurface[i], MC_SurfaceSize, ImageSize))

		// Set surface pitch
		CHECKFUNCTION(McSetParamInt(m_phSurface[i], MC_SurfacePitch, (INT32)ppROIList[i]->GetWidth()*m_PixelSize))

		// Set surface address
		CHECKFUNCTION(McSetParamInt(m_phSurface[i], MC_SurfaceAddr, (INT32)m_ppImageBuffer[i]))

		// Set surface context
		CHECKFUNCTION(McSetParamInt(m_phSurface[i], MC_SurfaceContext, (INT32)ppROIList[i]))
	}
	return S_OK;
}

inline HRESULT	CMultiCamChannel::Grab(DWORD GrabCount){
	// Set Channel to Idle state
	CHECKFUNCTION(McSetParamInt (m_hMultiCamObject, MC_ChannelState, MC_ChannelState_IDLE))	

	// Set GrabCount to "GrabCount" -> GrabCount acquisition
	CHECKFUNCTION(McSetParamInt (m_hMultiCamObject, MC_GrabCount, GrabCount)) 

	// Set Channel to Active state
	CHECKFUNCTION(McSetParamInt (m_hMultiCamObject, MC_ChannelState, MC_ChannelState_ACTIVE)) 

	return S_OK ;
}

inline HRESULT	CMultiCamChannel::Live(){
	// Set Channel to Idle state
	CHECKFUNCTION(McSetParamInt (m_hMultiCamObject, MC_ChannelState, MC_ChannelState_IDLE)) 

	// Set GrabCount to "-1" -> infinite acquisitions 
	CHECKFUNCTION(McSetParamInt (m_hMultiCamObject, MC_GrabCount, -1))

	// Set Channel to Active state
	CHECKFUNCTION(McSetParamInt (m_hMultiCamObject, MC_ChannelState, MC_ChannelState_ACTIVE)) 

	return TRUE ;
}
inline HRESULT	CMultiCamChannel::Stop(){
	// Set Channel to Idle state
	CHECKFUNCTION(McSetParamInt (m_hMultiCamObject, MC_ChannelState, MC_ChannelState_IDLE)) 

	return S_OK ;
}


inline HRESULT	CMultiCamChannel::AttachProcessor(CMultiCamProcessor* pProcessor){
	m_pProcessor = pProcessor;
	CHECKFUNCTION(McSetParamInt(pProcessor->GetHdl(), MC_DriverIndex, m_pMultiCamBoard->DriverIndex()))
	// Connect the processor with the channel
	CHECKFUNCTION(McSetParamInst(pProcessor->GetHdl(), MC_Source, m_hMultiCamObject))
	return S_OK;
}

/*=====================================================================*\
|	10.	CMultiCamProcessor implementation								|
\*=====================================================================*/

inline CMultiCamProcessor::CMultiCamProcessor(){
	INT32 m_ProcessorId = -1;
	m_pChannel = NULL;
	m_phSurface = NULL;
	m_ppImageBuffer = NULL;
	m_hMultiCamObject = NULL;
	m_ppROIList = NULL;
	m_ImageSizeX = m_ImageSizeY =0;
	m_PixelSize = 0;
	m_SurfaceNumber = 1;
}
inline CMultiCamProcessor::~CMultiCamProcessor(){
	MCSTATUS status;
	if(m_pChannel!=NULL){
		status= McSetParamInt (m_pChannel->GetHdl(), MC_ChannelState, MC_ChannelState_IDLE); 
		if (status != MC_OK) return;
	}
	status= McSetParamInt (m_pChannel->GetHdl(), MC_ProcessorState, MC_ProcessorState_OFF);
	m_pChannel->DetachProcessor();
	
	status = McDelete(m_hMultiCamObject);
	if (status != MC_OK) return;

	if(m_phSurface){
		for(DWORD i=0;i<m_SurfaceNumber;i++){
			status = McDelete(m_phSurface[i]);
			if (status != MC_OK) return;
		}
		delete m_phSurface;
		m_phSurface = NULL;
	}
	if(m_ppROIList!=NULL){
		for( DWORD i = 0; i<m_SurfaceNumber;i++){
			if(m_ppROIList[i] !=NULL){
				delete m_ppROIList[i];
			}
		}
		delete m_ppROIList;
		m_ppROIList = NULL;
	}		
	if(m_ppImageBuffer!=NULL){
		for( DWORD i = 0; i<m_SurfaceNumber;i++){
			if (m_ppImageBuffer[i]!=NULL)
				VirtualFree(m_ppImageBuffer[i], 0, MEM_RELEASE);
		}
		delete m_ppImageBuffer;
		m_ppImageBuffer = NULL;
	}
}
inline HRESULT	CMultiCamProcessor::Create(CMultiCamChannel* pChannel,LPCTSTR SpeedyName,INT32 ProcessorId){
	m_pChannel = pChannel;
	m_ProcessorId = ProcessorId;
	McCreate(MC_DEFAULT_PROCESSOR_HANDLE, &m_hMultiCamObject);
	McSetParamStr(m_hMultiCamObject, MC_ProcessFile, SpeedyName);
	McSetParamInt(m_hMultiCamObject, MC_ResourceId, ProcessorId);
	// Connect the processor with the channel
	if(pChannel->AttachProcessor(this) == S_OK)
		return S_OK;
	return E_FAIL;
}

inline HRESULT	CMultiCamProcessor::AddSurfaces(DWORD SurfaceNumber, DWORD	ColorFormat){	
	m_SurfaceNumber = SurfaceNumber;
	if(m_ppImageBuffer==NULL)
		m_ppImageBuffer = new PVOID[SurfaceNumber];
	m_ppROIList = new EGenericROI*[SurfaceNumber];
	m_PixelSize = ColorFormat;
	ComputeImageSize();
	for (DWORD i=0; i<SurfaceNumber ;i++){
		m_ppImageBuffer[i] = VirtualAlloc(NULL, m_ImageSize, MEM_COMMIT, PAGE_READWRITE);
		if (m_ppImageBuffer [i] == NULL) {
			//DisplayError("Cannot allocate image buffer", 0);
			return E_FAIL;
		}		
		// Set the EImage... object to the appropriate size 
		switch (m_PixelSize){
			case 1:// 8-bit monochrome
				m_ppROIList[i] = new EImageBW8(m_ImageSizeX,m_ImageSizeY);
				((EImageBW8*)m_ppROIList[i])->SetImagePtr(m_ppImageBuffer[i]);
				break;
			case 2:// 16-bit monochrome
				m_ppROIList[i] = new EImageBW16(m_ImageSizeX,m_ImageSizeY);
				((EImageBW16*)m_ppROIList[i])->SetImagePtr(m_ppImageBuffer[i]);
				break;
			case 3:	// 24 bits RGB color
				m_ppROIList[i] = new EImageC24(m_ImageSizeX,m_ImageSizeY);
				((EImageC24*)m_ppROIList[i])->SetImagePtr(m_ppImageBuffer[i]);
				break;
			default:
				return E_FAIL;
		}
	}
	if(m_phSurface==NULL)
		m_phSurface = new MCHANDLE[SurfaceNumber];
	for (i=0; i<SurfaceNumber ;i++){
		// Create a surface
		CHECKFUNCTION(McCreate (MC_DEFAULT_SURFACE_HANDLE, &m_phSurface[i]))

		// Set surface parameters
		DWORD ImageSize=(INT32)m_ppROIList[i]->GetWidth()*(INT32)m_ppROIList[i]->GetHeight()*m_PixelSize;
		CHECKFUNCTION(McSetParamInt(m_phSurface[i], MC_SurfaceSize, ImageSize))

		// Set surface pitch
		CHECKFUNCTION(McSetParamInt(m_phSurface[i], MC_SurfacePitch, (INT32)m_ppROIList[i]->GetWidth()*m_PixelSize))

		// Set surface plane,format
		CHECKFUNCTION(McSetParamInt(m_phSurface[i], MC_PlaneCount, 1))

		if(m_PixelSize!=m_pChannel->PixelSize()){
			switch(m_PixelSize){
			case 1:
				break;
			case 3:
				CHECKFUNCTION(McSetParamInt(m_phSurface[i], MC_SurfaceFormat, MC_SurfaceFormat_RGB24))
				break;
			}
		}
			
		// Set surface address
		CHECKFUNCTION(McSetParamInt(m_phSurface[i], MC_SurfaceAddr, (INT32)m_ppImageBuffer[i]))

		// Set surface context
		CHECKFUNCTION(McSetParamInt(m_phSurface[i], MC_SurfaceContext, (INT32)m_ppROIList[i]))
	}
	return AddSurfacesToCluster(SurfaceNumber,m_phSurface);
}
inline HRESULT CMultiCamProcessor::ComputeImageSize(){
	// Retrieve image parameters
	CHECKFUNCTION(McGetParamInt(m_pChannel->GetHdl(), MC_ImageSizeX, (int*)&m_ImageSizeX))
	CHECKFUNCTION(McGetParamInt(m_pChannel->GetHdl(), MC_ImageSizeY, (int*)&m_ImageSizeY))
	// Check the pixel-size
	//CHECKFUNCTION(McGetParamInt(m_pChannel->GetHdl(), MC_ImagePixelSize, (int*)&m_PixelSize))
	m_ImageSize = m_ImageSizeY * m_ImageSizeX * m_PixelSize;
	return S_OK;
}
#endif // !defined(_MULTICHANNEL_H____INCLUDED_)
