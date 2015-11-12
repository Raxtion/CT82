//---------------------------------------------------------------------------

#ifndef DominoVisionH
#define DominoVisionH
//---------------------------------------------------------------------------
#include "MultiCam.h"
#include <vector>

//---------------------------------------------------------------------------
class DominoVision
{
public:
//Palette
  BITMAPINFO *m_pGrayBitmapInfo;
  HPALETTE m_hGrayPalette;

//Euresys
  INT32 m_ImageSizeX[2];
  INT32 m_ImageSizeY[2];
  INT32 m_PixelSize[2];
  PUINT8 m_ImageBuffer[2],m_ImageBufferScale[2];   //for painting


  bool bInitial;
private:
  MCHANDLE m_ChannelInstance[2];
  MCHANDLE m_SurfaceInstance[2];
  //int m_SurfaceAddr;
  //TForm *m_pRefreshWnd;
  
public:
  TPoint m_ptSizeAllOrg;
  bool m_bValidImage[2];

  __fastcall DominoVision();
  __fastcall ~DominoVision();
  bool __fastcall Initial();
  bool __fastcall Terminate();
  bool __fastcall StartLive (int nCH);
  bool __fastcall StopLive (int nCH);
  bool __fastcall Grab(int nCH);
  bool __fastcall SetTrigMode(int nCH,bool bHard);

  void __fastcall CreateGrayPalette();
  void __fastcall CreateGrayBitmapInfo();
  void __fastcall ErrorDisplay(const char *Msg, int Code);
  void __fastcall SetExposureTime(int nCH,int nUs);
  
  
  int __fastcall GetGrabCount(int nCH);
  void __fastcall WaitValidImage(int nCH);

  bool __fastcall InitChannel(int nCH);
  bool __fastcall InitSurface(int nCH);

};

//---------------------------------------------------------------------------
#endif
