#define SENSOR_ON_DELAY 100
#define SENSOR_ON_TIMEOUT 3000
#define AXIS_TIMEOUT 10000
//-------------------------------DO----------------------------------------//
namespace DO
{
        enum DOList{
        FT_Flip	,
FT_Vac	,
FT_Locker	,
FT_Align	,
FT_Align2	,
Y005	,
Y006	,
Y007	,
RT_Flip	,
RT_Vac	,
RT_Locker	,
RT_Align	,
RT_Align2	,
Y013	,
Y014	,
Y015	,
SC_SSucker	,
SC_Csucker	,
SC_SSuckerVacOn	,
SC_CSuckerVacOn	,
SC_SSuckerDeVac	,
Sc_cSuckerDeVac	,
SC_SSuckerVacOff	,
SC_CSuckerVacOff	,
Y024	,
Y025	,
Y026	,
Y027	,
SR_Start	,
SR_Align	,
SR_Ready	,
SR2_OutGoing	,
SL_Dir	,
SL_Start	,
Y034	,
Y035	,
Y036	,
Y037	,
Y038	,
Y039	,
SR2_Start	,
SR2_PressWheel	,
SR2_PusherPush	,
SR2_PusherDown	,
Y044	,
Y045	,
Y046	,
Y047	,
SS_SSucker	,
SS_SpaSucker	,
SS_SVacOn	,
SS_SDeVac	,
SS_SpaVacOn	,
SS_SpaDeVac	,
SS_SVacOff	,
SS_SpaVacOff	,
StartBtnLamp	,
StopBtnLamp	,
ResetBtnLamp	,
RedLamp	,
GreenLamp	,
YellowLamp	,
Buzzer	,
Laser_BlowAir_Front	,
Laser_BlowAir_Rear	,
Blower	,
UnloaderEnough    ,
Y067	,
Y068	,
Y069	,
Y070	,
Y071	,
Y072	,
Y073	,
Y074	,
Y075	,
Y076	,
Y077	,
Y078	,
SafetyDoorByPass	
};
}

//-----------------------------------DI------------------------------------//
namespace DI
{
        enum DIList{
        FT_Positive	,
FT_Negative	,
FT_VacGauge	,
FT_LockerOn	,
FT_LockerOff	,
FT_AlignOff	,
FT_Align2Off	,
X007	,
RT_Positive	,
RT_Negative	,
RT_VacGauge	,
RT_LockerOn	,
RT_LockerOff	,
RT_AlignOff	,
RT_Align2Off	,
X015	,
SC_SSuckerUp	,
SC_SSuckerDown	,
SC_CSuckerUp	,
SC_CSuckerDown	,
SC_SSuckerVacGauge	,
SC_CSuckerVacGauge	,
SC_Laser1	,
SC_Laser2	,
X024	,
SR2_Exist	,
SR2_Inp	,
SR2_Exit	,
SR_Exist	,
SR_Inp	,
SR_Entry	,
X031	,
SL_Up	,
SL_Down	,
SpacerBoxExist	,
SL_Exist	,
IsSubstrate	,
SpacerBoxFull	,
SL_Inp	,
X039	,
SR2_PusherFwd	,
SR2_PusherBwd	,
SR2_PusherUp	,
SR2_PusherDown	,
SR2_PusherAlarm	,
X045	,
X046	,
SS_SSuckerColorSensor	,
SS_SSuckerUp	,
SS_SSuckerDown	,
SS_SpaSuckerUp	,
SS_SpaSuckerDown	,
SS_SSuckerVacGauge	,
SS_SpaSuckerVacGauge	,
X054	,
X055	,
StartBtn	,
StopBtn	,
ResetBtn	,
EmgBtn	,
MainAir	,
SafetyDoor	,
LaserComplete	,
OutReady	,
X064	,
SBT_NGBOX_EXIST	,
SBT_NGBOX_FULL	,
X067	,
FT_IN_FAN_ALM	,
FT_OUT_FAN_ALM	,
RT_IN_FAN_ALM	,
RT_OUT_FAN_ALM	,
X072	,
X073	,
X074	,
X075	,
X076	,
X077	,
X078	,
X079
        };
}
