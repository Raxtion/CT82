//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("fmChoiceMotor.cpp", frmChoiceMotor);
USEFORM("fmIOCheck.cpp", IOCheckDlg);
USEFORM("fmMachinParam.cpp", frmMachineParam);
USEFORM("fmMotorCheck.cpp", frmMotorCheck);
USEFORM("fmPassword.cpp", frmPassword);
USEFORM("fmProductParam.cpp", frmProductParam);
USEFORM("frmMain.cpp", fmMain);
USEFORM("frmPrivilege.cpp", fmPrivilege);
USEFORM("frmManual.cpp", fmManual);
USEFORM("frmOption.cpp", fmOption);
USEFORM("fmUserID.cpp", frmUserID);
USEFORM("frmShowNow.cpp", fmShowNow);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TfmMain), &fmMain);
         Application->CreateForm(__classid(TfmShowNow), &fmShowNow);
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
