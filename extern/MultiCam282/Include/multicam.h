// MULTICAM.H -- MULTICAM DRIVER API

#ifndef _MULTICAM_
#define _MULTICAM_

#if defined(WINAPI)
#define MCAPI WINAPI
#else
#if defined(__BORLANDC__)
#define MCAPI stdcall
#else
#define MCAPI _stdcall
#endif
#endif

#if defined(DLL_EXPORTS)
#define DLL_API __declspec(dllexport) MCAPI
#elif defined(__BORLANDC__)
#define DLL_API _import MCAPI
#else
#define DLL_API __declspec(dllimport) MCAPI
#endif

// MULTICAM PARAMETERS
//#if !defined(MPF_COMPILER) && !defined(MPF_DEBUGGER1)
#include "McParams.h"
#if !defined(DLL_EXPORTS)
#include "McParamsCompat1x.h"
#endif
//#endif

#ifdef __cplusplus
extern "C" {
#endif

// DATA TYPES

typedef unsigned int UINT32, *PUINT32;
typedef signed int INT32, *PINT32;
typedef unsigned short UINT16, *PUINT16;
typedef signed short INT16, *PINT16;
typedef unsigned char UINT8, *PUINT8;
typedef signed char INT8, *PINT8;
typedef char CHAR, *PCHAR;
typedef const char *PCCHAR;
typedef double FLOAT64, *PFLOAT64;
typedef void *PVOID;

typedef int MCSTATUS;
typedef UINT32 MCHANDLE, *PMCHANDLE;
typedef UINT32 MCPARAMID, *PMCPARAMID;
typedef int MCEVENT, MCSIGNAL;

// CALLBACK REASONS
#define MC_MAX_EVENTS					8
#define MC_SIG_SURFACE_PROCESSING		1
#define MC_SIG_SURFACE_FILLED			2
#define MC_SIG_UNRECOVERABLE_OVERRUN	3
#define MC_SIG_FRAMETRIGGER_VIOLATION	4
#define MC_SIG_START_EXPOSURE			5
#define MC_SIG_END_EXPOSURE				6
#define MC_SIG_ACQUISITION_FAILURE		7
#define MC_SIG_CLUSTER_UNAVAILABLE      8


// CALLBACK FUNCTION
typedef struct _MC_CALLBACK_INFO {
	PVOID Context;
	MCHANDLE Instance;
	MCSIGNAL Signal;
	UINT32 SignalInfo;
	UINT32 Reserved;
} MCCALLBACKINFO, *PMCCALLBACKINFO;
typedef void (MCAPI *PMCCALLBACK)(PMCCALLBACKINFO CbInfo);
typedef void (MCAPI *PMCCALLBACKEX)(PVOID Context);


// STATUS CODE
#define MC_MAX_ERRORS_STD		21
#define MC_OK					0
#define MC_NO_BOARD_FOUND		-1
#define MC_BAD_PARAMETER		-2
#define MC_IO_ERROR				-3
#define MC_INTERNAL_ERROR		-4
#define MC_NO_MORE_RESOURCES	-5
#define MC_IN_USE				-6
#define MC_NOT_SUPPORTED        -7
#define MC_DATABASE_ERROR		-8
#define MC_OUT_OF_BOUND			-9
#define MC_INSTANCE_NOT_FOUND   -10
#define MC_INVALID_HANDLE		-11
#define MC_TIMEOUT				-12
#define MC_INVALID_VALUE		-13
#define MC_RANGE_ERROR			-14
#define MC_BAD_HW_CONFIG		-15
#define MC_NO_EVENT				-16
#define MC_LICENSE_NOT_GRANTED	-17
#define MC_FATAL_ERROR			-18
#define MC_HW_EVENT_CONFLICT	-19
#define MC_FILE_NOT_FOUND       -20

#define MC_MAX_ERRORS_MPF		2
#define MC_MPF_ERROR_BASE		-100
#define MC_BAD_GRABBER_CONFIG	-101

// OBJECT CLASSES
#define MC_GRABBER_CLASS		0x6
#define MC_SURFACE_CLASS		0x4
#define MC_CHANNEL_CLASS		0x8
#define MC_VIEWER_CLASS			0xA
#define MC_CONFIG_CLASS			0x2
#define MC_PROCESSOR_CLASS		0xC


// DEFAULT INSTANCE TEMPLATES
#define MC_DEFAULT_GRABBER_HANDLE ((MC_GRABBER_CLASS << 28) | 0x0FFFFFFF)
#define MC_DEFAULT_SURFACE_HANDLE ((MC_SURFACE_CLASS << 28) | 0x0FFFFFFF)
#define MC_DEFAULT_CHANNEL_HANDLE ((MC_CHANNEL_CLASS << 28) | 0x0FFFFFFF)
#define MC_DEFAULT_VIEWER_HANDLE  ((MC_VIEWER_CLASS << 28) | 0x0FFFFFFF)
#define MC_DEFAULT_PROCESSOR_HANDLE ((MC_PROCESSOR_CLASS << 28) | 0x0FFFFFFF)
#define MC_PROCESSOR_MULTI_HANDLE   ((MC_PROCESSOR_CLASS << 28) | 0x0FFFFFFF)
#define MC_PROCESSOR_PRESTISSIMO_HANDLE ((MC_PROCESSOR_CLASS << 28) | 0x0FFEFFFF)

#define MC_CONFIGURATION          ((MC_CONFIG_CLASS << 28) | 0)

// GAMMA & ALPHA
#define MC_CHANNEL_GAMMA_X		   ((MC_CHANNEL_CLASS << 28) | 0x0001FFFF)
#define MC_CHANNEL_GAMMA_Y		   ((MC_CHANNEL_CLASS << 28) | 0x0002FFFF)
#define MC_CHANNEL_GAMMA_Z         ((MC_CHANNEL_CLASS << 28) | 0x0003FFFF)
#define MC_CHANNEL_GAMMA_XBIS	   ((MC_CHANNEL_CLASS << 28) | 0x0004FFFF)
#define MC_CHANNEL_GAMMA_YBIS      ((MC_CHANNEL_CLASS << 28) | 0x0005FFFF)
#define MC_CHANNEL_GAMMA_ZBIS	   ((MC_CHANNEL_CLASS << 28) | 0x0006FFFF)
#define MC_CHANNEL_ALPHA_X		   ((MC_CHANNEL_CLASS << 28) | 0x0007FFFF)
#define MC_CHANNEL_ALPHA_Y         ((MC_CHANNEL_CLASS << 28) | 0x0008FFFF)
#define MC_CHANNEL_VALUE_M         ((MC_CHANNEL_CLASS << 28) | 0x0009FFFF)
#define MC_CHANNEL_EXPERT_M		   ((MC_CHANNEL_CLASS << 28) | 0x000AFFFF)
#define MC_CHANNEL_EXPERT_A		   ((MC_CHANNEL_CLASS << 28) | 0x000BFFFF)
#define MC_CHANNEL_EXPERT_B        ((MC_CHANNEL_CLASS << 28) | 0x000CFFFF)


// DEFAULT PROCESSOR FUNCTION
#define MC_ProcessType_BYPASS		0


#if !defined(MC_DYNAMIC_BINDING)

// STATIC INSTANCE OBJECTS
// FUNCTIONS

// Driver connections
MCSTATUS DLL_API McOpenDriver(PCCHAR InstanceName);
MCSTATUS DLL_API McCloseDriver(void);

// Object creation / deletion
MCSTATUS DLL_API McCreate(MCHANDLE ModelInstance, PMCHANDLE Instance);
MCSTATUS DLL_API McCreateNm(PCCHAR ModelInstanceName, PMCHANDLE Instance);
MCSTATUS DLL_API McDelete(MCHANDLE Instance);

// Acquisition control
MCSTATUS DLL_API McStartAcq(void);
MCSTATUS DLL_API McStopAcq(void);

// Parameter handling
MCSTATUS DLL_API McSetParamInt(MCHANDLE Instance, MCPARAMID Param, INT32 ValueInt);
MCSTATUS DLL_API McSetParamNmInt(MCHANDLE Instance, PCCHAR ParamName, INT32 ValueInt);
MCSTATUS DLL_API McSetParamStr(MCHANDLE Instance, MCPARAMID Param, PCCHAR ValueStr);
MCSTATUS DLL_API McSetParamNmStr(MCHANDLE Instance, PCCHAR ParamName, PCCHAR ValueStr);
MCSTATUS DLL_API McSetParamFloat(MCHANDLE Instance, MCPARAMID Param, FLOAT64 ValueFloat);
MCSTATUS DLL_API McSetParamNmFloat(MCHANDLE Instance, PCCHAR ParamName, FLOAT64 ValueFloat);
MCSTATUS DLL_API McSetParamInst(MCHANDLE Instance, MCPARAMID Param, MCHANDLE ValueInst);
MCSTATUS DLL_API McSetParamNmInst(MCHANDLE Instance, PCCHAR ParamName, MCHANDLE ValueInst);

MCSTATUS DLL_API McGetParamInt(MCHANDLE Instance, MCPARAMID Param, PINT32 ValueInt);
MCSTATUS DLL_API McGetParamNmInt(MCHANDLE Instance, PCCHAR ParamName, PINT32 ValueInt);
MCSTATUS DLL_API McGetParamStr(MCHANDLE Instance, MCPARAMID Param, PCHAR ValueStr, UINT32 MaxLength);
MCSTATUS DLL_API McGetParamNmStr(MCHANDLE Instance, PCCHAR ParamName, PCHAR ValueStr, UINT32 MaxLength);
MCSTATUS DLL_API McGetParamFloat(MCHANDLE Instance, MCPARAMID Param, PFLOAT64 ValueFloat);
MCSTATUS DLL_API McGetParamNmFloat(MCHANDLE Instance, PCCHAR ParamName, PFLOAT64 ValueFloat);
MCSTATUS DLL_API McGetParamInst(MCHANDLE Instance, MCPARAMID Param, PMCHANDLE ValueInst);
MCSTATUS DLL_API McGetParamNmInst(MCHANDLE Instance, PCCHAR ParamName, PMCHANDLE ValueInst);

// Callback registration for an object
MCSTATUS DLL_API McRegisterCallback(MCHANDLE Instance, PMCCALLBACK CallBackFunction, PVOID Context);
MCSTATUS DLL_API McRegisterCallbackEx(MCHANDLE Instance, PMCCALLBACK CallBackFunction, PMCCALLBACKEX ThreadStart, PMCCALLBACKEX ThreadEnd, PVOID Context);

// Event Management
MCSTATUS DLL_API McWaitSignal(MCHANDLE Instance, MCSIGNAL Signal, UINT32 Timeout, PMCCALLBACKINFO Info);
MCSTATUS DLL_API McGetSignalInfo(MCHANDLE Instance, MCSIGNAL Signal, PMCCALLBACKINFO Info);

#endif	// MC_DYNAMIC_BINDING

#ifdef __cplusplus
};	// extern "C"
#endif

#endif		// _MULTICAM_
