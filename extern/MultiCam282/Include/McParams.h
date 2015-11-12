// \\Yoko-tsuno\Transfer\Hardware\MsfCompiler\McParams.h Parameter Identifier File
// Created: 2002/04/29
// This file has been generated automatically and should not be modified
#ifndef _McParams_
#define _McParams_


#define MC_DriverIndex                           (MCPARAMID)(    0 << 14)
#define MC_PciPosition                           (MCPARAMID)(    1 << 14)
#define MC_BoardName                             (MCPARAMID)(    2 << 14)
#define MC_BoardIdentifier                       (MCPARAMID)(    3 << 14)
#define MC_NameBoard                             (MCPARAMID)(    4 << 14)
#define MC_SerialNumber                          (MCPARAMID)(    5 << 14)
#define MC_BoardType                             (MCPARAMID)(    6 << 14)
#define MC_BoardType_MULTI                         1
#define MC_BoardType_MULTIPLUS                     2
#define MC_BoardType_MULTIEXPRESS                  3
#define MC_BoardType_GAMMA                         4
#define MC_BoardType_ALPHA                         5
#define MC_BoardType_PRESTISSIMO                   6
#define MC_BoardType_VALUE                         7
#define MC_BoardType_EXPERT                        8
#define MC_ModuleType                            (MCPARAMID)(    7 << 14)
#define MC_ModuleType_NONE                         1
#define MC_ModuleType_DIG16                        2
#define MC_ModuleType_DIG32                        3
#define MC_ModuleType_DIG16_C_2K644                4
#define MC_ModuleType_DIG16_C_2K422                5
#define MC_ModuleType_DIG16_C_CUSTOM               6
#define MC_ModuleType_DIG32_B_8K644                7
#define MC_ModuleType_DIG32_B_2K422                8
#define MC_ModuleType_DIG32_B_CUSTOM               9
#define MC_ModuleType_DIG32_644                   10
#define MC_ModuleType_DIG32_C_2K422               11
#define MC_ModuleType_DIG32_C_CUSTOM              12
#define MC_ModuleType_DIG16_644                   13
#define MC_ModuleType_DIG16_422                   14
#define MC_ModuleType_DIG32_422                   15
#define MC_ModuleType_CAMERALINK                  16
#define MC_OemSafetyLock                         (MCPARAMID)(    8 << 14)
#define MC_OemSafetyKey                          (MCPARAMID)(    9 << 14)
#define MC_EvolutionNumber                       (MCPARAMID)(   10 << 14)
#define MC_CamFile                               (MCPARAMID)(   11 << 14)
#define MC_Cluster                               (MCPARAMID)(   12 << 14)
#define MC_ClusterMode                           (MCPARAMID)(   13 << 14)
#define MC_ClusterMode_AUTO                        1
#define MC_ClusterMode_MANUAL                      2
#define MC_ClusterMask                           (MCPARAMID)(   14 << 14)
#define MC_ClusterMask_NONE                        1
#define MC_ClusterMask_SKIP                        2
#define MC_ClusterMask_HOLD                        3
#define MC_ClusterMask_DELAY                       4
#define MC_ClusterMask_STOP                        5
#define MC_ChannelState                          (MCPARAMID)(   15 << 14)
#define MC_ChannelState_IDLE                       1
#define MC_ChannelState_ACTIVE                     2
#define MC_ChannelState_READY                      3
#define MC_LineIndex                             (MCPARAMID)(   16 << 14)
#define MC_SurfaceIndex                          (MCPARAMID)(   17 << 14)
#define MC_TriggerMode                           (MCPARAMID)(   18 << 14)
#define MC_TriggerMode_TIMER                       1
#define MC_TriggerMode_GRABBER                     2
#define MC_InitialPause                          (MCPARAMID)(   19 << 14)
#define MC_Pause                                 (MCPARAMID)(   20 << 14)
#define MC_InitialTrigger                        (MCPARAMID)(   21 << 14)
#define MC_Trigger                               (MCPARAMID)(   22 << 14)
#define MC_Trigger_PAUSE                           1
#define MC_Trigger_GOHIGH                          2
#define MC_Trigger_GOLOW                           3
#define MC_GrabCount                             (MCPARAMID)(   23 << 14)
#define MC_SignalEnable                          (MCPARAMID)(   24 << 14)
#define MC_SignalEnable_NONE                       1
#define MC_SignalEnable_PROCESSING                 2
#define MC_SignalEnable_FILLED                     3
#define MC_SignalEnable_OFF                        4
#define MC_SignalEnable_ON                         5
#define MC_SignalEvent                           (MCPARAMID)(   25 << 14)
#define MC_Usage                                 (MCPARAMID)(   26 << 14)
#define MC_SurfaceSize                           (MCPARAMID)(   27 << 14)
#define MC_SurfaceAddr                           (MCPARAMID)(   28 << 14)
#define MC_SurfacePitch                          (MCPARAMID)(   29 << 14)
#define MC_PlaneCount                            (MCPARAMID)(   30 << 14)
#define MC_SurfaceState                          (MCPARAMID)(   31 << 14)
#define MC_SurfaceState_FREE                       1
#define MC_SurfaceState_FILLING                    2
#define MC_SurfaceState_FILLED                     3
#define MC_SurfaceState_PROCESSING                 4
#define MC_SurfaceState_RESERVED                   5
#define MC_SurfaceContext                        (MCPARAMID)(   32 << 14)
#define MC_DebugMode                             (MCPARAMID)(   33 << 14)
#define MC_ResourceId                            (MCPARAMID)(   34 << 14)
#define MC_ResourceId_DSP1                         1
#define MC_ResourceId_DSP2                         2
#define MC_ResourceId_DSP12                        3
#define MC_ResourceId_DSP3                         3
#define MC_ResourceId_DSP4                         4
#define MC_Source                                (MCPARAMID)(   35 << 14)
#define MC_ProcessFile                           (MCPARAMID)(   36 << 14)
#define MC_Black                                 (MCPARAMID)(   37 << 14)
#define MC_White                                 (MCPARAMID)(   38 << 14)
#define MC_BlackProfile                          (MCPARAMID)(   39 << 14)
#define MC_WhiteProfile                          (MCPARAMID)(   40 << 14)
#define MC_ProcessType                           (MCPARAMID)(   41 << 14)
#define MC_ProcessorState                        (MCPARAMID)(   42 << 14)
#define MC_ProcessorState_OFF                      1
#define MC_ProcessorState_ON                       2
#define MC_FillCount                             (MCPARAMID)(   43 << 14)
#define MC_Gain                                  (MCPARAMID)(   44 << 14)
#define MC_PageDuration                          (MCPARAMID)(   45 << 14)
#define MC_OverrunCount                          (MCPARAMID)(   46 << 14)
#define MC_Level                                 (MCPARAMID)(   47 << 14)
#define MC_SurfaceLocation                       (MCPARAMID)(   48 << 14)
#define MC_SurfaceLocation_HOST                    1
#define MC_SurfaceLocation_DSP                     2
#define MC_ErrorHandling                         (MCPARAMID)(   49 << 14)
#define MC_ErrorHandling_NONE                      1
#define MC_ErrorHandling_MSGBOX                    2
#define MC_ErrorHandling_EXCEPTION                 3
#define MC_ErrorHandling_MSGEXCEPTION              4
#define MC_ForceTrig                             (MCPARAMID)(   50 << 14)
#define MC_ForceTrig_TRIG                          1
#define MC_ParamBlock                            (MCPARAMID)(   51 << 14)
#define MC_SurfaceFormat                         (MCPARAMID)(   52 << 14)
#define MC_SurfaceFormat_RAW                       1
#define MC_SurfaceFormat_RGB24                     2
#define MC_SurfaceFormat_PLANAR24                  3
#define MC_SurfaceFormat_SPLITX                    4
#define MC_Lookup                                (MCPARAMID)(   53 << 14)
#define MC_Flags                                 (MCPARAMID)(   54 << 14)
#define MC_HardwareKey                           (MCPARAMID)(   55 << 14)
#define MC_AcqTimeout_ms                         (MCPARAMID)(   56 << 14)
#define MC_LineTriggerViolation                  (MCPARAMID)(   57 << 14)
#define MC_FrameTriggerViolation                 (MCPARAMID)(   58 << 14)
#define MC_BoardTopology                         (MCPARAMID)(   59 << 14)
#define MC_BoardTopology_3_3_0                     1
#define MC_BoardTopology_2_3_1                     2
#define MC_BoardTopology_2_2_2                     3
#define MC_BoardTopology_2_2_1                     4
#define MC_BoardTopology_1_3_1                     5
#define MC_BoardTopology_1_1_2                     6
#define MC_BoardTopology_1_1_1                     7
#define MC_BoardTopology_2_2_11                    8
#define MC_BoardTopology_11_3_1                    9
#define MC_BoardTopology_11_11_2                  10
#define MC_BoardTopology_11_11_11                 11
#define MC_BoardTopology_0_3_1                    12
#define MC_BoardTopology_2_2_0                    13
#define MC_BoardTopology_2_2                      14
#define MC_BoardTopology_2_1                      15
#define MC_BoardTopology_1_1                      16
#define MC_BoardTopology_2_11                     17
#define MC_BoardTopology_11_11                    18
#define MC_BoardTopology_0_2                      19
#define MC_GrabberConfig                         (MCPARAMID)(   60 << 14)
#define MC_GrabberConfig_1_1_1                     1
#define MC_GrabberConfig_1_1_2                     2
#define MC_GrabberConfig_2_0                       3
#define MC_GrabberConfig_1_1                       4
#define MC_GrabberConfig_0_2                       5
#define MC_GrabberConfig_2_2_0                     6
#define MC_MPFRevision                           (MCPARAMID)(   61 << 14)
#define MC_BoardCount                            (MCPARAMID)(   62 << 14)
#define MC_RemainingGrab                         (MCPARAMID)(   63 << 14)
#define MC_ElapsedGrab                           (MCPARAMID)(   64 << 14)
#define MC_LineDelay                             (MCPARAMID)(   65 << 14)
#define MC_LutIndex                              (MCPARAMID)(   66 << 14)
#define MC_InputLut                              (MCPARAMID)(   67 << 14)
#define MC_SurfaceInfo                           (MCPARAMID)(   68 << 14)
#define MC_GrabDuration_us                       (MCPARAMID)(   69 << 14)
#define MC_SerialControlA                        (MCPARAMID)(   70 << 14)
#define MC_SerialControlB                        (MCPARAMID)(   71 << 14)
#define MC_TimeCode                              (MCPARAMID)(   72 << 14)
#define MC_TrigMode                              (MCPARAMID)(  512 << 14)
#define MC_TrigMode_INT                            1
#define MC_TrigMode_EXT                            2
#define MC_TrigMode_SOFT                           3
#define MC_TrigMode_ENC                            3
#define MC_TrigMode_EXTRC                          4
#define MC_TrigMode_AUTO                           5
#define MC_TrigMode_IMMEDIATE                      6
#define MC_TrigMode_HARD                           7
#define MC_TrigMode_COMBINED                       8
#define MC_TrigCtl                               (MCPARAMID)(  513 << 14)
#define MC_TrigCtl_TGOLOW                          1
#define MC_TrigCtl_TGOHIGH                         2
#define MC_TrigCtl_VGOLOW                          3
#define MC_TrigCtl_VGOHIGH                         4
#define MC_TrigFlt                               (MCPARAMID)(  514 << 14)
#define MC_ExpScl                                (MCPARAMID)(  515 << 14)
#define MC_ExpTrm                                (MCPARAMID)(  516 << 14)
#define MC_DataWidth                             (MCPARAMID)(  517 << 14)
#define MC_LinePeriod                            (MCPARAMID)(  518 << 14)
#define MC_ImagePixelSize                        (MCPARAMID)(  519 << 14)
#define MC_FramePeriod                           (MCPARAMID)(  520 << 14)
#define MC_SensorWidth                           (MCPARAMID)(  521 << 14)
#define MC_SensorHeight                          (MCPARAMID)(  522 << 14)
#define MC_ImageSizeX                            (MCPARAMID)(  523 << 14)
#define MC_ImageSizeY                            (MCPARAMID)(  524 << 14)
#define MC_ImageFlipY                            (MCPARAMID)(  525 << 14)
#define MC_ImageFlipY_OFF                          1
#define MC_ImageFlipY_ON                           2
#define MC_CameraChannels                        (MCPARAMID)(  526 << 14)
#define MC_AcqScl                                (MCPARAMID)(  527 << 14)
#define MC_AcqCount                              (MCPARAMID)(  528 << 14)
#define MC_AcqShift                              (MCPARAMID)(  529 << 14)
#define MC_AcqSplit                              (MCPARAMID)(  530 << 14)
#define MC_FrameShift                            (MCPARAMID)(  531 << 14)
#define MC_VcamCount                             (MCPARAMID)(  532 << 14)
#define MC_StrCtl                                (MCPARAMID)(  533 << 14)
#define MC_StrCtl_LOW                              1
#define MC_StrCtl_HIGH                             2
#define MC_StrCtl_PLSLOW                           3
#define MC_StrCtl_PLSHIGH                          4
#define MC_StrLvl                                (MCPARAMID)(  534 << 14)
#define MC_StrLvl_DIS                              1
#define MC_StrLvl_TTL                              2
#define MC_StrLvl_OC                               3
#define MC_StrLvl_OE                               4
#define MC_StrPos                                (MCPARAMID)(  535 << 14)
#define MC_StrDur                                (MCPARAMID)(  536 << 14)
#define MC_PendLines                             (MCPARAMID)(  537 << 14)
#define MC_FrameRstCtl                           (MCPARAMID)(  538 << 14)
#define MC_FrameRstCtl_TPLSLOW                     1
#define MC_FrameRstCtl_TPLSHIGH                    2
#define MC_FrameRstCtl_DPLSLOW                     3
#define MC_FrameRstCtl_DPLSHIGH                    4
#define MC_FrameRstPos                           (MCPARAMID)(  539 << 14)
#define MC_FrameRstDur                           (MCPARAMID)(  540 << 14)
#define MC_ExpMode                               (MCPARAMID)(  541 << 14)
#define MC_ExpMode_Reset_Width                     1
#define MC_ExpMode_Dual_Reset_Interval             2
#define MC_ExpMode_Reset_To_Expose_interval        3
#define MC_ExpDur                                (MCPARAMID)(  542 << 14)
#define MC_LineValCtl                            (MCPARAMID)(  543 << 14)
#define MC_LineValCtl_LOW                          1
#define MC_LineValCtl_HIGH                         2
#define MC_LineValCtl_TLOW                         3
#define MC_LineValCtl_THIGH                        4
#define MC_FrameValCtl                           (MCPARAMID)(  544 << 14)
#define MC_FrameValCtl_LOW                         1
#define MC_FrameValCtl_HIGH                        2
#define MC_FrameValCtl_TLOW                        3
#define MC_FrameValCtl_THIGH                       4
#define MC_FrameValFlt                           (MCPARAMID)(  545 << 14)
#define MC_FrameValFlt_0                           1
#define MC_FrameValFlt_4                           2
#define MC_FrameValFlt_16                          3
#define MC_FrameValFlt_64                          4
#define MC_ExpCtl                                (MCPARAMID)(  546 << 14)
#define MC_ExpCtl_TPLSLOW                          1
#define MC_ExpCtl_TPLSHIGH                         2
#define MC_ExpCtl_DPLSLOW                          3
#define MC_ExpCtl_DPLSHIGH                         4
#define MC_ClockPhase                            (MCPARAMID)(  547 << 14)
#define MC_ClockPhase_0                            1
#define MC_ClockPhase_90                           2
#define MC_ClockPhase_180                          3
#define MC_ClockPhase_270                          4
#define MC_DataDelay                             (MCPARAMID)(  548 << 14)
#define MC_DataDelay_NONE                          1
#define MC_DataDelay_SLIGHT                        2
#define MC_TestPat                               (MCPARAMID)(  549 << 14)
#define MC_TestPat_OFF                             1
#define MC_TestPat_ON                              2
#define MC_TestPat_LaneID                          3
#define MC_Line3Ctl                              (MCPARAMID)(  550 << 14)
#define MC_Line3Ctl_RESET                          1
#define MC_Line3Ctl_DLOW                           2
#define MC_Line3Ctl_DHIGH                          3
#define MC_Line3Ctl_TLOW                           4
#define MC_Line3Ctl_THIGH                          5
#define MC_Line3Ctl_EXPOSE                         6
#define MC_Line4Ctl                              (MCPARAMID)(  551 << 14)
#define MC_Line4Ctl_LOW                            1
#define MC_Line4Ctl_HIGH                           2
#define MC_Line4Ctl_REFCKA                         3
#define MC_Line5Ctl                              (MCPARAMID)(  552 << 14)
#define MC_Line5Ctl_EXPOSE                         1
#define MC_Line5Ctl_DLOW                           2
#define MC_Line5Ctl_DHIGH                          3
#define MC_Line5Ctl_TLOW                           4
#define MC_Line5Ctl_THIGH                          5
#define MC_Line5Ctl_RESET                          6
#define MC_Line6Ctl                              (MCPARAMID)(  553 << 14)
#define MC_Line6Ctl_LOW                            1
#define MC_Line6Ctl_HIGH                           2
#define MC_BitMask                               (MCPARAMID)(  554 << 14)
#define MC_RdoutTrm                              (MCPARAMID)(  555 << 14)
#define MC_SacqLoc                               (MCPARAMID)(  556 << 14)
#define MC_EacqLoc                               (MCPARAMID)(  557 << 14)
#define MC_ExpDurT                               (MCPARAMID)(  558 << 14)
#define MC_ImageSizeXModulo                      (MCPARAMID)(  559 << 14)
#define MC_PerScl                                (MCPARAMID)(  560 << 14)
#define MC_PerCnt                                (MCPARAMID)(  561 << 14)
#define MC_EncScl                                (MCPARAMID)(  562 << 14)
#define MC_RateCode                              (MCPARAMID)(  563 << 14)
#define MC_SensorLength                          (MCPARAMID)(  564 << 14)
#define MC_PageLength                            (MCPARAMID)(  565 << 14)
#define MC_LineForbidPos                         (MCPARAMID)(  566 << 14)
#define MC_LineSkipHold                          (MCPARAMID)(  567 << 14)
#define MC_LineSkipHold_SKIP                       1
#define MC_LineSkipHold_HOLD                       2
#define MC_LineRstCtl                            (MCPARAMID)(  568 << 14)
#define MC_LineRstCtl_PLSLOW                       1
#define MC_LineRstCtl_PLSHIGH                      2
#define MC_ExpCtl_PLSLOW                           1
#define MC_ExpCtl_PLSHIGH                          2
#define MC_FifoDepth                             (MCPARAMID)(  569 << 14)
#define MC_FifoWidth                             (MCPARAMID)(  570 << 14)
#define MC_FifoLineSize                          (MCPARAMID)(  571 << 14)
#define MC_BackendInterruptMask                  (MCPARAMID)(  572 << 14)
#define MC_ColorInputFormat                      (MCPARAMID)(  573 << 14)
#define MC_ColorInputFormat_SerialBGR              1
#define MC_ColorInputFormat_SerialRGB              2
#define MC_ColorInputFormat_ParallelRGB            3
#define MC_ColorOutputFormat                     (MCPARAMID)(  574 << 14)
#define MC_ColorOutputFormat_Packed24              1
#define MC_ColorOutputFormat_Planar8               2
#define MC_ColorOutputFormat_Planar16              3
#define MC_PageTrigMode                          (MCPARAMID)(  575 << 14)
#define MC_PageTrigMode_INT                        1
#define MC_PageTrigMode_EXT                        2
#define MC_PageTrigMode_DELAY                      3
#define MC_PageTrigMode_FVAL                       4
#define MC_PageTrigMode_SOFT                       5
#define MC_PageTrigCtl                           (MCPARAMID)(  576 << 14)
#define MC_PageTrigCtl_TGOLOW                      1
#define MC_PageTrigCtl_TGOHIGH                     2
#define MC_PageTrigCtl_VGOLOW                      3
#define MC_PageTrigCtl_VGOHIGH                     4
#define MC_PageTrigCtl_DGOLOW                      5
#define MC_PageTrigCtl_DGOHIGH                     6
#define MC_PageTrigFlt                           (MCPARAMID)(  577 << 14)
#define MC_PageDelay                             (MCPARAMID)(  578 << 14)
#define MC_FrameForbidPos                        (MCPARAMID)(  579 << 14)
#define MC_FrameSkipHold                         (MCPARAMID)(  580 << 14)
#define MC_FrameSkipHold_SKIP                      1
#define MC_FrameSkipHold_HOLD                      2
#define MC_PageSkipHold                          (MCPARAMID)(  581 << 14)
#define MC_PageSkipHold_SKIP                       1
#define MC_PageSkipHold_HOLD                       2
#define MC_Block                                 (MCPARAMID)(  582 << 14)
#define MC_Atom                                  (MCPARAMID)(  583 << 14)
#define MC_ChannelTopology                       (MCPARAMID)(  584 << 14)
#define MC_ChannelTopology_Single                  1
#define MC_ChannelTopology_DualXPair               2
#define MC_ChannelTopology_DualXTap                3
#define MC_ChannelTopology_DualXEnd                4
#define MC_ChannelTopology_DualYPair               5
#define MC_ChannelTopology_DualYEnd                6
#define MC_ChannelTopology_Triple                  7
#define MC_ChannelTopology_QuadX                   8
#define MC_CameraTimings                         (MCPARAMID)(  585 << 14)
#define MC_CameraTimings_Mono                      1
#define MC_CameraTimings_Duo                       2
#define MC_XChannels                             (MCPARAMID)(  586 << 14)
#define MC_YChannels                             (MCPARAMID)(  587 << 14)
#define MC_BlockSize                             (MCPARAMID)(  588 << 14)
#define MC_PixelComponents                       (MCPARAMID)(  589 << 14)
#define MC_BackEndProg                           (MCPARAMID)(  590 << 14)
#define MC_BackEndProg_AB12                        1
#define MC_BackEndProg_CD12                        2
#define MC_BackEndProg_AB24                        3
#define MC_BackEndProg_CD24                        4
#define MC_BackEndProg_ABCD22                      5
#define MC_BackEndProg_BGR24                       6
#define MC_BackEndProg_PLANAR8                     7
#define MC_BackEndProg_ABCD11                      8
#define MC_BackEndProg_X                           9
#define MC_DesiredLinePitch                      (MCPARAMID)(  591 << 14)
#define MC_EncoderPitch                          (MCPARAMID)(  592 << 14)
#define MC_MaxLineFrequency                      (MCPARAMID)(  593 << 14)
#define MC_PixelClockFrequency                   (MCPARAMID)(  594 << 14)
#define MC_LinePitch                             (MCPARAMID)(  595 << 14)
#define MC_MinLineFrequency                      (MCPARAMID)(  596 << 14)
#define MC_DesiredVCLKFrequency                  (MCPARAMID)(  597 << 14)
#define MC_EffectiveVCLKFrequency                (MCPARAMID)(  598 << 14)
#define MC_VCLKFrequencyError                    (MCPARAMID)(  599 << 14)
#define MC_Smin                                  (MCPARAMID)(  600 << 14)
#define MC_FVR                                   (MCPARAMID)(  601 << 14)
#define MC_Rmin                                  (MCPARAMID)(  602 << 14)
#define MC_Rmax                                  (MCPARAMID)(  603 << 14)
#define MC_MinEncoderFrequency                   (MCPARAMID)(  604 << 14)
#define MC_FrameCount                            (MCPARAMID)(  605 << 14)
#define MC_MoleculeSize                          (MCPARAMID)(  606 << 14)
#define MC_ZChannels                             (MCPARAMID)(  607 << 14)
#define MC_Alines                                (MCPARAMID)(  608 << 14)
#define MC_StartReadout                          (MCPARAMID)(  609 << 14)
#define MC_StartReadout_Auto                       1
#define MC_StartReadout_LineSync                   2
#define MC_StartReadout_Flex                       3
#define MC_StartReadout_FlexD                      4
#define MC_StartReadout_FlexU                      5
#define MC_FifoCap4                              (MCPARAMID)(  610 << 14)
#define MC_Exposure                              (MCPARAMID)(  611 << 14)
#define MC_MinExpose                             (MCPARAMID)(  612 << 14)
#define MC_ExpPscl                               (MCPARAMID)(  613 << 14)
#define MC_ExpTerm                               (MCPARAMID)(  614 << 14)
#define MC_PageCount                             (MCPARAMID)(  615 << 14)
#define MC_MinLinePeriod                         (MCPARAMID)(  616 << 14)
#define MC_MinResetWidth                         (MCPARAMID)(  617 << 14)
#define MC_ExpWidth                              (MCPARAMID)(  618 << 14)
#define MC_StrWidth                              (MCPARAMID)(  619 << 14)
#define MC_RstWidth                              (MCPARAMID)(  620 << 14)
#define MC_Str2Rst                               (MCPARAMID)(  621 << 14)
#define MC_MinRstWidth                           (MCPARAMID)(  622 << 14)
#define MC_ExpTrim                               (MCPARAMID)(  623 << 14)
#define MC_ExpTrimFactor                         (MCPARAMID)(  624 << 14)
#define MC_Periodic                              (MCPARAMID)(  625 << 14)
#define MC_DacCmd                                (MCPARAMID)(  626 << 14)
#define MC_DacCmd_DAC_A8                           1
#define MC_DacCmd_DAC_A9                           2
#define MC_DacCmd_DAC_B8                           3
#define MC_DacCmd_DAC_B9                           4
#define MC_DacData                               (MCPARAMID)(  627 << 14)
#define MC_Destination                           (MCPARAMID)(  628 << 14)
#define MC_Destination_PC                          1
#define MC_Destination_DSP1                        2
#define MC_Destination_DSP2                        3
#define MC_REFCKA_Frequency                      (MCPARAMID)(  629 << 14)
#define MC_Gating                                (MCPARAMID)(  630 << 14)
#define MC_Gating_POST                             1
#define MC_Gating_PRE                              2
#define MC_DataClockPolarity                     (MCPARAMID)(  631 << 14)
#define MC_DataClockPolarity_POS                   1
#define MC_DataClockPolarity_NEG                   2
#define MC_TimingClockSource                     (MCPARAMID)(  632 << 14)
#define MC_TimingClockSource_EXT                   1
#define MC_TimingClockSource_REFCKA                2
#define MC_EncSvalue                             (MCPARAMID)(  633 << 14)
#define MC_ReadoutTC                             (MCPARAMID)(  634 << 14)
#define MC_USS                                   (MCPARAMID)(  635 << 14)
#define MC_USOutM                                (MCPARAMID)(  636 << 14)
#define MC_USOutM_ABCD4                            1
#define MC_USOutM_ABCD2                            2
#define MC_USOutM_BADC2                            3
#define MC_USOutM_ACBD2                            4
#define MC_USOutM_CADB2                            5
#define MC_USOutM_BADC1                            6
#define MC_USOutM_DCBA1                            7
#define MC_USOutM_CBA1                             8
#define MC_USOutM_CBA3                             9
#define MC_USOutM_ABC3                            10
#define MC_USOutM_X                               11
#define MC_USOutM_ABCD1                           12
#define MC_ChannelOrder                          (MCPARAMID)(  637 << 14)
#define MC_ChannelOrder_Direct                     1
#define MC_ChannelOrder_Invert                     2
#define MC_DataLanes                             (MCPARAMID)(  638 << 14)
#define MC_DataLanes_P                             1
#define MC_DataLanes_R                             2
#define MC_DataLanes_PQ                            3
#define MC_DataLanes_PR                            4
#define MC_DataLanes_RS                            5
#define MC_DataLanes_PRS                           6
#define MC_DataLanes_PQRS                          7
#define MC_DataLanes_PQR                           8
#define MC_DataLanes_PRQS                          9
#define MC_DataLanes_PQS                          10
#define MC_DataLanes_RSQ                          11
#define MC_USOutD                                (MCPARAMID)(  639 << 14)
#define MC_USOutD_AB2                              1
#define MC_USOutD_AB1                              2
#define MC_USOutD_BA1                              3
#define MC_USOutD_CD2                              4
#define MC_USOutD_CD1                              5
#define MC_USOutD_DC1                              6
#define MC_USOutD_X                                7
#define MC_DualLaneComb                          (MCPARAMID)(  640 << 14)
#define MC_DualLaneComb_PQ                         1
#define MC_DualLaneComb_PR                         2
#define MC_ModuleID                              (MCPARAMID)(  641 << 14)
#define MC_FifoType                              (MCPARAMID)(  642 << 14)
#define MC_FifoType_Unknown                        1
#define MC_FifoType_TwoK                           2
#define MC_FifoType_EightK                         3
#define MC_ElectricalInterfaceType               (MCPARAMID)(  643 << 14)
#define MC_ElectricalInterfaceType_Unknown         1
#define MC_ElectricalInterfaceType_422             2
#define MC_ElectricalInterfaceType_644             3
#define MC_ElectricalInterfaceType_CameraLink      4
#define MC_Period                                (MCPARAMID)(  644 << 14)
#define MC_RGBLanes                              (MCPARAMID)(  645 << 14)
#define MC_RGBLanes_PRS                            1
#define MC_RGBLanes_PQR                            2
#define MC_RGBLanes_PQS                            3
#define MC_RGBLanes_RSQ                            4
#define MC_SWAP16                                (MCPARAMID)(  646 << 14)
#define MC_SWAP16_OFF                              1
#define MC_SWAP16_ON                               2
#define MC_Clanes                                (MCPARAMID)(  647 << 14)
#define MC_Clanes_X                                1
#define MC_Clanes_P                                2
#define MC_Clanes_R                                3
#define MC_Clanes_PQ                               4
#define MC_Clanes_PR                               5
#define MC_Clanes_RS                               6
#define MC_Clanes_P_Q                              7
#define MC_Clanes_P_R                              8
#define MC_Clanes_R_S                              9
#define MC_Clanes_PR_QS                           10
#define MC_Clanes_PQ_RS                           11
#define MC_Clanes_P_R_S                           12
#define MC_Clanes_P_Q_R                           13
#define MC_Clanes_P_Q_S                           14
#define MC_Clanes_R_S_Q                           15
#define MC_Clanes_P_Q_R_S                         16
#define MC_USLanes                               (MCPARAMID)(  648 << 14)
#define MC_USLanes_X                               1
#define MC_USLanes_P                               2
#define MC_USLanes_Q                               3
#define MC_USLanes_R                               4
#define MC_USLanes_S                               5
#define MC_USLanes_PQ                              6
#define MC_USLanes_PR                              7
#define MC_USLanes_RS                              8
#define MC_USLanes_PRS                             9
#define MC_USLanes_PQR                            10
#define MC_USLanes_PQS                            11
#define MC_USLanes_RSQ                            12
#define MC_USLanes_PRQS                           13
#define MC_USLanes_PQRS                           14
#define MC_CableAlign                            (MCPARAMID)(  649 << 14)
#define MC_CableAlign_Left                         1
#define MC_CableAlign_Right                        2
#define MC_CameraWidth                           (MCPARAMID)(  650 << 14)
#define MC_PortSize                              (MCPARAMID)(  651 << 14)
#define MC_Ubit                                  (MCPARAMID)(  652 << 14)
#define MC_Dbit                                  (MCPARAMID)(  653 << 14)
#define MC_Umask                                 (MCPARAMID)(  654 << 14)
#define MC_Dmask                                 (MCPARAMID)(  655 << 14)
#define MC_MSmask                                (MCPARAMID)(  656 << 14)
#define MC_LSmask                                (MCPARAMID)(  657 << 14)
#define MC_Dwidth                                (MCPARAMID)(  658 << 14)
#define MC_ALIGN                                 (MCPARAMID)(  659 << 14)
#define MC_ImagePixelAlign                       (MCPARAMID)(  660 << 14)
#define MC_ImagePixelAlign_Left                    1
#define MC_ImagePixelAlign_Right                   2
#define MC_CWidth                                (MCPARAMID)(  661 << 14)
#define MC_ModType                               (MCPARAMID)(  662 << 14)
#define MC_ModType_Unknown                         1
#define MC_ModType_NoModule                        2
#define MC_ModType_D16A                            3
#define MC_ModType_D32AB                           4
#define MC_ModType_D32B                            5
#define MC_ModType_D16C                            6
#define MC_ModType_D32C                            7
#define MC_ModType_CameraLink                      8
#define MC_NextTrigMode                          (MCPARAMID)(  663 << 14)
#define MC_TrigEdge                              (MCPARAMID)(  664 << 14)
#define MC_TrigEdge_GOHIGH                         1
#define MC_TrigEdge_GOLOW                          2
#define MC_TrigFilter                            (MCPARAMID)(  665 << 14)
#define MC_TrigFilter_OFF                          1
#define MC_TrigFilter_ON                           2
#define MC_TrigLine                              (MCPARAMID)(  666 << 14)
#define MC_TrigLine_NOM                            1
#define MC_TrigLine_ALT1                           2
#define MC_TrigLine_ALT2                           3
#define MC_TrigLine_ALT3                           4
#define MC_TrigLine_ALT4                           5
#define MC_MapConTim                             (MCPARAMID)(  667 << 14)
#define MC_MapConTim_XYZ                           1
#define MC_MapConTim_ZYX                           2
#define MC_MapConTim_YZX                           3
#define MC_MapConTim_XZY                           4
#define MC_MapConTim_ZXY                           5
#define MC_MapConTim_YXZ                           6
#define MC_MapDigTim                             (MCPARAMID)(  668 << 14)
#define MC_MapDigTim_ABD                           1
#define MC_MapDigTim_ACD                           2
#define MC_MapDigTim_ABC                           3
#define MC_MapDigTim_BCC                           4
#define MC_MapDigTim_BBC                           5
#define MC_MapDigTim_BCD                           6
#define MC_MapDigTim_BBD                           7
#define MC_MapTimCon                             (MCPARAMID)(  669 << 14)
#define MC_MapTimCon_TXYZ                          1
#define MC_MapTimCon_TZYX                          2
#define MC_MapTimCon_TYZX                          3
#define MC_MapTimCon_TXZY                          4
#define MC_MapTimCon_TZXY                          5
#define MC_MapTimCon_TYXZ                          6
#define MC_MapTimDig                             (MCPARAMID)(  670 << 14)
#define MC_MapTimDig_TXXZZ                         1
#define MC_MapTimDig_TXXXZ                         2
#define MC_MapTimDig_TXZZZ                         3
#define MC_MapTimDig_TXYZZ                         4
#define MC_MapTimDig_TXYYZ                         5
#define MC_MapTimDig_TXXYZ                         6
#define MC_MapLaneX1                             (MCPARAMID)(  671 << 14)
#define MC_MapLaneX1_OFF                           1
#define MC_MapLaneX1_A                             2
#define MC_MapLaneX2                             (MCPARAMID)(  672 << 14)
#define MC_MapLaneX2_OFF                           1
#define MC_MapLaneX2_B                             2
#define MC_MapLaneX3                             (MCPARAMID)(  673 << 14)
#define MC_MapLaneX3_OFF                           1
#define MC_MapLaneX3_A                             2
#define MC_MapLaneX3_C                             3
#define MC_MapLaneX3_CLK                           4
#define MC_MapLaneY1                             (MCPARAMID)(  674 << 14)
#define MC_MapLaneY1_OFF                           1
#define MC_MapLaneY1_A                             2
#define MC_MapLaneY1_C                             3
#define MC_MapLaneY1_D                             4
#define MC_MapLaneY2                             (MCPARAMID)(  675 << 14)
#define MC_MapLaneY2_OFF                           1
#define MC_MapLaneY2_B                             2
#define MC_MapLaneY2_D                             3
#define MC_MapLaneY3                             (MCPARAMID)(  676 << 14)
#define MC_MapLaneY3_OFF                           1
#define MC_MapLaneY3_B                             2
#define MC_MapLaneY3_C                             3
#define MC_MapLaneY3_D                             4
#define MC_MapLaneY3_CLK                           5
#define MC_MapLaneZ1                             (MCPARAMID)(  677 << 14)
#define MC_MapLaneZ1_OFF                           1
#define MC_MapLaneZ1_A                             2
#define MC_MapLaneZ1_C                             3
#define MC_MapLaneZ2                             (MCPARAMID)(  678 << 14)
#define MC_MapLaneZ2_OFF                           1
#define MC_MapLaneZ2_B                             2
#define MC_MapLaneZ2_C                             3
#define MC_MapLaneZ2_D                             4
#define MC_MapLaneZ3                             (MCPARAMID)(  679 << 14)
#define MC_MapLaneZ3_OFF                           1
#define MC_MapLaneZ3_CLK                           2
#define MC_ClkSynth1                             (MCPARAMID)(  680 << 14)
#define MC_ClkSynth2                             (MCPARAMID)(  681 << 14)
#define MC_Connector                             (MCPARAMID)(  682 << 14)
#define MC_Connector_X                             1
#define MC_Connector_Y                             2
#define MC_Connector_Z                             3
#define MC_Connector_XBIS                          4
#define MC_Connector_YBIS                          5
#define MC_Connector_ZBIS                          6
#define MC_GrabWindow                            (MCPARAMID)(  683 << 14)
#define MC_GrabWindow_STD                          1
#define MC_GrabWindow_NOBLACK                      2
#define MC_GrabWindow_NOLOSS                       3
#define MC_GrabWindow_MAN                          4
#define MC_GrbCount                              (MCPARAMID)(  684 << 14)
#define MC_OffsetX_Tk                            (MCPARAMID)(  685 << 14)
#define MC_OffsetY_Ln                            (MCPARAMID)(  686 << 14)
#define MC_LineDurTrim                           (MCPARAMID)(  687 << 14)
#define MC_CableComp                             (MCPARAMID)(  688 << 14)
#define MC_Filter                                (MCPARAMID)(  689 << 14)
#define MC_Filter_NONE                             1
#define MC_Filter_10MHZ                            2
#define MC_Filter_5MHZ                             3
#define MC_Filter_5MHZ_PAL                         4
#define MC_Filter_5MHZ_NTSC                        5
#define MC_CalPat                                (MCPARAMID)(  690 << 14)
#define MC_CalPat_NONE                             1
#define MC_CalPat_CAL                              2
#define MC_CalPat_TPG                              3
#define MC_LutEn                                 (MCPARAMID)(  691 << 14)
#define MC_LutEn_OFF                               1
#define MC_LutEn_ON                                2
#define MC_ImageBufLoc                           (MCPARAMID)(  692 << 14)
#define MC_LutBufLoc                             (MCPARAMID)(  693 << 14)
#define MC_ConnectLoc                            (MCPARAMID)(  694 << 14)
#define MC_ConnectLoc_UPPER                        1
#define MC_ConnectLoc_CENTER                       2
#define MC_ConnectLoc_LOWER                        3
#define MC_TimUnit                               (MCPARAMID)(  695 << 14)
#define MC_TimUnit_TX                              1
#define MC_TimUnit_TY                              2
#define MC_TimUnit_TZ                              3
#define MC_DigUnit1                              (MCPARAMID)(  696 << 14)
#define MC_DigUnit1_A                              1
#define MC_DigUnit1_B                              2
#define MC_DigUnit1_C                              3
#define MC_DigUnit1_D                              4
#define MC_DigUnit2                              (MCPARAMID)(  697 << 14)
#define MC_DigUnit2_NONE                           1
#define MC_DigUnit2_A                              2
#define MC_DigUnit2_B                              3
#define MC_DigUnit2_C                              4
#define MC_DigUnit2_D                              5
#define MC_DigUnit3                              (MCPARAMID)(  698 << 14)
#define MC_DigUnit3_NONE                           1
#define MC_DigUnit3_A                              2
#define MC_DigUnit3_B                              3
#define MC_DigUnit3_C                              4
#define MC_DigUnit3_D                              5
#define MC_SelClkSynth                           (MCPARAMID)(  699 << 14)
#define MC_SelClkSynth_NONE                        1
#define MC_SelClkSynth_CLK1                        2
#define MC_SelClkSynth_CLK2                        3
#define MC_Camera                                (MCPARAMID)(  700 << 14)
#define MC_Camera_CCIR                             1
#define MC_Camera_EIA                              2
#define MC_Camera_CV_M1                            3
#define MC_Camera_CV_M10C                          4
#define MC_Camera_CV_M10E                          5
#define MC_Camera_CV_M50                           6
#define MC_Camera_XC_55                            7
#define MC_Camera_SIMUL                            8
#define MC_Camera_CV_M40                           9
#define MC_Camera_CUSTOM                          10
#define MC_Camera_XC_HR300                        11
#define MC_CamConfig                             (MCPARAMID)(  701 << 14)
#define MC_CamConfig_STD                           1
#define MC_CamConfig_TEST                          2
#define MC_CamConfig_I50SA                         3
#define MC_CamConfig_I60SA                         4
#define MC_CamConfig_P25SA                         5
#define MC_CamConfig_P30SA                         6
#define MC_CamConfig_P50SA                         7
#define MC_CamConfig_P60SA                         8
#define MC_CamConfig_P25RA                         9
#define MC_CamConfig_P30RA                        10
#define MC_CamConfig_P50RA                        11
#define MC_CamConfig_P60RA                        12
#define MC_CamConfig_P12RD                        13
#define MC_CamConfig_P60RD                        14
#define MC_CamConfig_P100RA                       15
#define MC_Scanning                              (MCPARAMID)(  702 << 14)
#define MC_Scanning_PROGRESSIVE                    1
#define MC_Scanning_INTERLACE                      2
#define MC_Standard                              (MCPARAMID)(  703 << 14)
#define MC_Standard_CCIR                           1
#define MC_Standard_EIA                            2
#define MC_PixelClk_Hz                           (MCPARAMID)(  704 << 14)
#define MC_LineRate_Hz                           (MCPARAMID)(  705 << 14)
#define MC_HCsyncDur_ns                          (MCPARAMID)(  706 << 14)
#define MC_HCsyncBfr_ns                          (MCPARAMID)(  707 << 14)
#define MC_HCSyncAft_ns                          (MCPARAMID)(  708 << 14)
#define MC_Vtotal_Ln                             (MCPARAMID)(  709 << 14)
#define MC_Vactive_Ln                            (MCPARAMID)(  710 << 14)
#define MC_VCsyncAft_Ln                          (MCPARAMID)(  711 << 14)
#define MC_VsyncAft_Ln                           (MCPARAMID)(  712 << 14)
#define MC_HdriveDur_ns                          (MCPARAMID)(  713 << 14)
#define MC_VdriveDur_Ln                          (MCPARAMID)(  714 << 14)
#define MC_HsyncDly_ns                           (MCPARAMID)(  715 << 14)
#define MC_HdriveDly_ns                          (MCPARAMID)(  716 << 14)
#define MC_HVdriveCtl                            (MCPARAMID)(  717 << 14)
#define MC_HVdriveCtl_NONE                         1
#define MC_HVdriveCtl_TTL                          2
#define MC_HVdriveCtl_DIFF                         3
#define MC_HVdriveEdge                           (MCPARAMID)(  718 << 14)
#define MC_HVdriveEdge_GOLOW                       1
#define MC_HVdriveEdge_GOHIGH                      2
#define MC_PixelClkCtl                           (MCPARAMID)(  719 << 14)
#define MC_PixelClkCtl_NONE                        1
#define MC_PixelClkCtl_TTL                         2
#define MC_PixelClkCtl_DIFF                        3
#define MC_PixelClkEdge                          (MCPARAMID)(  720 << 14)
#define MC_PixelClkEdge_GOHIGH                     1
#define MC_PixelClkEdge_GOLOW                      2
#define MC_VsyncCtl                              (MCPARAMID)(  721 << 14)
#define MC_VsyncCtl_NONE                           1
#define MC_VsyncCtl_TTL                            2
#define MC_VsyncCtl_DIFF                           3
#define MC_HsyncCtl                              (MCPARAMID)(  722 << 14)
#define MC_HsyncCtl_NONE                           1
#define MC_HsyncCtl_TTL                            2
#define MC_HsyncCtl_DIFF                           3
#define MC_HsyncEdge                             (MCPARAMID)(  723 << 14)
#define MC_HsyncEdge_GOLOW                         1
#define MC_HsyncEdge_GOHIGH                        2
#define MC_VsyncEdge                             (MCPARAMID)(  724 << 14)
#define MC_VsyncEdge_GOLOW                         1
#define MC_VsyncEdge_GOHIGH                        2
#define MC_ICS9161Code                           (MCPARAMID)(  725 << 14)
#define MC_SyncMode                              (MCPARAMID)(  726 << 14)
#define MC_SyncMode_MASTER                         1
#define MC_SyncMode_ANALOG                         2
#define MC_SyncMode_DIGITAL                        3
#define MC_VCgatePos_Ln                          (MCPARAMID)(  727 << 14)
#define MC_Operation                             (MCPARAMID)(  728 << 14)
#define MC_Operation_SYNC                          1
#define MC_Operation_VCAM                          2
#define MC_Operation_CTL                           3
#define MC_Cable                                 (MCPARAMID)(  729 << 14)
#define MC_Cable_A15_C01                           1
#define MC_Cable_A15_C02                           2
#define MC_Cable_A15_C03                           3
#define MC_Cable_A15_C04                           4
#define MC_Cable_A15_C05                           5
#define MC_FrameRstEdge                          (MCPARAMID)(  730 << 14)
#define MC_FrameRstEdge_GOLOW                      1
#define MC_FrameRstEdge_GOHIGH                     2
#define MC_LineDur_Tk                            (MCPARAMID)(  731 << 14)
#define MC_LineDur_ns                            (MCPARAMID)(  732 << 14)
#define MC_SampleClk_Hz                          (MCPARAMID)(  733 << 14)
#define MC_TCU_ps                                (MCPARAMID)(  734 << 14)
#define MC_Hactive_ns                            (MCPARAMID)(  735 << 14)
#define MC_Hactive_Tk                            (MCPARAMID)(  736 << 14)
#define MC_GrabSizeX_Tk                          (MCPARAMID)(  737 << 14)
#define MC_GrabSizeX_ns                          (MCPARAMID)(  738 << 14)
#define MC_GrabPosX_ns                           (MCPARAMID)(  739 << 14)
#define MC_X_ACQOn                               (MCPARAMID)(  740 << 14)
#define MC_X_ACQOff                              (MCPARAMID)(  741 << 14)
#define MC_ClmDur_ns                             (MCPARAMID)(  742 << 14)
#define MC_ClmPos_ns                             (MCPARAMID)(  743 << 14)
#define MC_X_CLMOn                               (MCPARAMID)(  744 << 14)
#define MC_X_CLMOff                              (MCPARAMID)(  745 << 14)
#define MC_X_HPLL                                (MCPARAMID)(  746 << 14)
#define MC_X_ENDR                                (MCPARAMID)(  747 << 14)
#define MC_X_HOn                                 (MCPARAMID)(  748 << 14)
#define MC_X_HOff                                (MCPARAMID)(  749 << 14)
#define MC_X_MIDX                                (MCPARAMID)(  750 << 14)
#define MC__VActive                              (MCPARAMID)(  751 << 14)
#define MC_GrabSizeY_Ln                          (MCPARAMID)(  752 << 14)
#define MC_GrabPosY_Ln                           (MCPARAMID)(  753 << 14)
#define MC_ADelay1_ns                            (MCPARAMID)(  754 << 14)
#define MC_ADelay2_ns                            (MCPARAMID)(  755 << 14)
#define MC_ADelay3_ns                            (MCPARAMID)(  756 << 14)
#define MC_DDelay2                               (MCPARAMID)(  757 << 14)
#define MC_DDelay3                               (MCPARAMID)(  758 << 14)
#define MC_AcqStep                               (MCPARAMID)(  759 << 14)
#define MC__MIDXQ                                (MCPARAMID)(  760 << 14)
#define MC__ASEL                                 (MCPARAMID)(  761 << 14)
#define MC__BSEL                                 (MCPARAMID)(  762 << 14)
#define MC__CSEL                                 (MCPARAMID)(  763 << 14)
#define MC__DSEL                                 (MCPARAMID)(  764 << 14)
#define MC__PShift1                              (MCPARAMID)(  765 << 14)
#define MC__PShift2                              (MCPARAMID)(  766 << 14)
#define MC__Dig321Mask                           (MCPARAMID)(  767 << 14)
#define MC__VCODIV                               (MCPARAMID)(  768 << 14)
#define MC__SELH                                 (MCPARAMID)(  769 << 14)
#define MC__SELH_NONE                              1
#define MC__SELH_HDS                               2
#define MC__SELH_DETS                              3
#define MC__SELH_QS                                4
#define MC__SELV                                 (MCPARAMID)(  770 << 14)
#define MC__SELV_NONE                              1
#define MC__SELV_VDS                               2
#define MC__SELV_DETV                              3
#define MC__ASSY11                               (MCPARAMID)(  771 << 14)
#define MC__ASSY12                               (MCPARAMID)(  772 << 14)
#define MC__ASSY13                               (MCPARAMID)(  773 << 14)
#define MC__ASSY14                               (MCPARAMID)(  774 << 14)
#define MC__ASSY21                               (MCPARAMID)(  775 << 14)
#define MC__ASSY22                               (MCPARAMID)(  776 << 14)
#define MC__ASSY23                               (MCPARAMID)(  777 << 14)
#define MC__ASSY24                               (MCPARAMID)(  778 << 14)
#define MC__SIZX                                 (MCPARAMID)(  779 << 14)
#define MC__SIZY                                 (MCPARAMID)(  780 << 14)
#define MC__STARTU1                              (MCPARAMID)(  781 << 14)
#define MC__STARTU2                              (MCPARAMID)(  782 << 14)
#define MC__STARTD1                              (MCPARAMID)(  783 << 14)
#define MC__STARTD2                              (MCPARAMID)(  784 << 14)
#define MC__STEPX                                (MCPARAMID)(  785 << 14)
#define MC__STEPY                                (MCPARAMID)(  786 << 14)
#define MC__OFSU                                 (MCPARAMID)(  787 << 14)
#define MC__OFSD                                 (MCPARAMID)(  788 << 14)
#define MC__SELINC                               (MCPARAMID)(  789 << 14)
#define MC__SELINC_EOL                             1
#define MC__SELINC_EOF                             2
#define MC__SELINC_EOL2                            3
#define MC__SELINC_EOF2                            4
#define MC__YChannels                            (MCPARAMID)(  790 << 14)
#define MC__TFINC                                (MCPARAMID)(  791 << 14)
#define MC_SWICodeMask                           (MCPARAMID)(  792 << 14)
#define MC_SASCodeMask                           (MCPARAMID)(  793 << 14)
#define MC_EAPCodeMask                           (MCPARAMID)(  794 << 14)
#define MC_NOWCodeMask                           (MCPARAMID)(  795 << 14)
#define MC_Gain1Ctl                              (MCPARAMID)(  796 << 14)
#define MC_Gain1Ctl_LIN                            1
#define MC_Gain1Ctl_p3DB                           2
#define MC_Gain1Ctl_p2DB                           3
#define MC_Gain1Ctl_p1DB                           4
#define MC_Gain1Ctl_0DB                            5
#define MC_Gain1Ctl_m1DB                           6
#define MC_Gain1Ctl_m2DB                           7
#define MC_Gain1Ctl_m3DB                           8
#define MC_Gain1                                 (MCPARAMID)(  797 << 14)
#define MC_Offset1                               (MCPARAMID)(  798 << 14)
#define MC_Gain2Ctl                              (MCPARAMID)(  799 << 14)
#define MC_Gain2Ctl_LIN                            1
#define MC_Gain2Ctl_p3DB                           2
#define MC_Gain2Ctl_p2DB                           3
#define MC_Gain2Ctl_p1DB                           4
#define MC_Gain2Ctl_0DB                            5
#define MC_Gain2Ctl_m1DB                           6
#define MC_Gain2Ctl_m2DB                           7
#define MC_Gain2Ctl_m3DB                           8
#define MC_Gain2                                 (MCPARAMID)(  800 << 14)
#define MC_Offset2                               (MCPARAMID)(  801 << 14)
#define MC_Gain3Ctl                              (MCPARAMID)(  802 << 14)
#define MC_Gain3Ctl_LIN                            1
#define MC_Gain3Ctl_p3DB                           2
#define MC_Gain3Ctl_p2DB                           3
#define MC_Gain3Ctl_p1DB                           4
#define MC_Gain3Ctl_0DB                            5
#define MC_Gain3Ctl_m1DB                           6
#define MC_Gain3Ctl_m2DB                           7
#define MC_Gain3Ctl_m3DB                           8
#define MC_Gain3                                 (MCPARAMID)(  803 << 14)
#define MC_Offset3                               (MCPARAMID)(  804 << 14)
#define MC_NominalGainACode                      (MCPARAMID)(  805 << 14)
#define MC_NominalGainBCode                      (MCPARAMID)(  806 << 14)
#define MC_NominalGainCCode                      (MCPARAMID)(  807 << 14)
#define MC_NominalGainDCode                      (MCPARAMID)(  808 << 14)
#define MC__NominalGain1Code                     (MCPARAMID)(  809 << 14)
#define MC__NominalGain2Code                     (MCPARAMID)(  810 << 14)
#define MC__NominalGain3Code                     (MCPARAMID)(  811 << 14)
#define MC__Gain1Code                            (MCPARAMID)(  812 << 14)
#define MC__Gain2Code                            (MCPARAMID)(  813 << 14)
#define MC__Gain3Code                            (MCPARAMID)(  814 << 14)
#define MC_X_IPLLOn                              (MCPARAMID)(  815 << 14)
#define MC_X_IPLLOff                             (MCPARAMID)(  816 << 14)
#define MC_ModuleType_Unknown                      1
#define MC_ModuleType_NoModule                     2
#define MC_ModuleType_D16A                         3
#define MC_ModuleType_D32AB                        4
#define MC_ModuleType_D32B                         5
#define MC_ModuleType_D16C                         6
#define MC_ModuleType_D32C                         7
#define MC_NextTrigMode_REPEAT                     1
#define MC_NextTrigMode_HARD                       2
#define MC_NextTrigMode_SOFT                       3
#define MC_NextTrigMode_COMBINED                   4
#define MC_AcqMode                               (MCPARAMID)(  817 << 14)
#define MC_AcqMode_GRABBER                         1
#define MC_AcqMode_TIMER                           2
#define MC_AcqMode_SYSTEM                          3
#define MC_TrigCtl_TTL                             1
#define MC_JumperCK                              (MCPARAMID)(  818 << 14)
#define MC_JumperCK_CKDPOS                         1
#define MC_JumperCK_CKDNEG                         2
#define MC_JumperCK_CKSPOS                         3
#define MC_JumperCK_CKSNEG                         4
#define MC_JumperCK_ZLANE                          5
#define MC_JumperCK_EMPTY                          6
#define MC_JumperL1                              (MCPARAMID)(  819 << 14)
#define MC_JumperL1_DT                             1
#define MC_JumperL1_DU                             2
#define MC_JumperL1_ST                             3
#define MC_JumperL1_SU                             4
#define MC_JumperL2                              (MCPARAMID)(  820 << 14)
#define MC_JumperL2_DT                             1
#define MC_JumperL2_DU                             2
#define MC_JumperL2_ST                             3
#define MC_JumperL2_SU                             4
#define MC_JumperH                               (MCPARAMID)(  821 << 14)
#define MC_JumperH_TTL                             1
#define MC_JumperH_DPOS                            2
#define MC_JumperH_DNEG                            3
#define MC_JumperV                               (MCPARAMID)(  822 << 14)
#define MC_JumperV_TTL                             1
#define MC_JumperV_DPOS                            2
#define MC_JumperV_DNEG                            3
#define MC_ADresolution                          (MCPARAMID)(  823 << 14)
#define MC_ADresolution_8BIT                       1
#define MC_ADresolution_10BIT                      2
#define MC_LineDurTrimOK                         (MCPARAMID)(  824 << 14)
#define MC_LineDurTrimOK_YES                       1
#define MC_LineDurTrimOK_NO                        2
#define MC_OffsetX_Px                            (MCPARAMID)(  825 << 14)
#define MC_WindowX_Px                            (MCPARAMID)(  826 << 14)
#define MC_WindowY_Ln                            (MCPARAMID)(  827 << 14)
#define MC_WindowX_Tk                            (MCPARAMID)(  828 << 14)
#define MC_VdriveDly_Ln                          (MCPARAMID)(  829 << 14)
#define MC_Expose_us                             (MCPARAMID)(  830 << 14)
#define MC_ExposeTrim                            (MCPARAMID)(  831 << 14)
#define MC_TrueExp_us                            (MCPARAMID)(  832 << 14)
#define MC_StrobeLevel                           (MCPARAMID)(  833 << 14)
#define MC_StrobeLevel_PLSHIGH                     1
#define MC_StrobeLevel_PLSLOW                      2
#define MC_StrobeLevel_HIGH                        3
#define MC_StrobeLevel_LOW                         4
#define MC_StrobeDur                             (MCPARAMID)(  834 << 14)
#define MC_StrobePos                             (MCPARAMID)(  835 << 14)
#define MC_StrobeCtl                             (MCPARAMID)(  836 << 14)
#define MC_StrobeCtl_NONE                          1
#define MC_StrobeCtl_TTL                           2
#define MC_StrobeLine                            (MCPARAMID)(  837 << 14)
#define MC_StrobeLine_NOM                          1
#define MC_StrobeLine_ALT1                         2
#define MC_StrobeLine_ALT2                         3
#define MC_StrobeLine_ALT3                         4
#define MC_StrobeLine_ALT4                         5
#define MC_GainCtl                               (MCPARAMID)(  838 << 14)
#define MC_GainCtl_LIN                             1
#define MC_GainCtl_p3DB                            2
#define MC_GainCtl_p2DB                            3
#define MC_GainCtl_p1DB                            4
#define MC_GainCtl_0DB                             5
#define MC_GainCtl_m1DB                            6
#define MC_GainCtl_m2DB                            7
#define MC_GainCtl_m3DB                            8
#define MC_GainTrim1                             (MCPARAMID)(  839 << 14)
#define MC_GainTrim2                             (MCPARAMID)(  840 << 14)
#define MC_GainTrim3                             (MCPARAMID)(  841 << 14)
#define MC_Offset                                (MCPARAMID)(  842 << 14)
#define MC_OffsetTrim1                           (MCPARAMID)(  843 << 14)
#define MC_OffsetTrim2                           (MCPARAMID)(  844 << 14)
#define MC_OffsetTrim3                           (MCPARAMID)(  845 << 14)
#define MC__Offset1Code                          (MCPARAMID)(  846 << 14)
#define MC__Offset2Code                          (MCPARAMID)(  847 << 14)
#define MC__Offset3Code                          (MCPARAMID)(  848 << 14)
#define MC__Tk_Px                                (MCPARAMID)(  849 << 14)
#define MC___MSFBuild                            (MCPARAMID)(  850 << 14)
#define MC___MSFError                            (MCPARAMID)(  851 << 14)
#define MC_PinGATE                               (MCPARAMID)(  852 << 14)
#define MC_PinGATE_UNUSED                          1
#define MC_PinGATE_VSYNC                           2
#define MC_PinVIO                                (MCPARAMID)(  853 << 14)
#define MC_PinVIO_UNUSED                           1
#define MC_PinVIO_VSYNC                            2
#define MC_Cable_A15_C06                           6
#define MC_Cable_A15_C07                           7
#define MC_Premier                               (MCPARAMID)(  854 << 14)
#define MC_Premier_AA                              1
#define MC_Premier_BB                              2
#define MC_Premier_CC                              3
#define MC_Premier_DD                              4
#define MC_Premier_ZZ                              5
#define MC_ParamIn2                              (MCPARAMID)(  855 << 14)
#define MC_Auteur                                (MCPARAMID)(  856 << 14)
#define MC_Auteur_TOI                              1
#define MC_Auteur_MOI                              2
#define MC_Auteur_EUX                              3
#define MC_Auteur_NOUS                             4
#define MC_Auteur_LUI                              5
#define MC_Menteur                               (MCPARAMID)(  857 << 14)
#define MC_ParamIn8                              (MCPARAMID)(  858 << 14)
#define MC_ParamOut1                             (MCPARAMID)(  859 << 14)
#define MC_ParamOut1_XX                            1
#define MC_ParamOut1_YY                            2
#define MC_ParamOut1_ZZ                            3
#define MC_Carton                                (MCPARAMID)(  860 << 14)
#define MC_Carton_ALPHA                            1
#define MC_Carton_BETA                             2
#define MC_Carton_GAMMA                            3
#define MC_Carton_DELTA                            4
#define MC_ParamOut4                             (MCPARAMID)(  861 << 14)
#define MC_ParamOut5                             (MCPARAMID)(  862 << 14)
#define MC_Arthur                                (MCPARAMID)(  863 << 14)
#define MC_Arthur_X                                1
#define MC_Arthur_Y                                2
#define MC_Arthur_Z                                3
#define MC_Acteur                                (MCPARAMID)(  864 << 14)
#define MC_Acteur_JOE                              1
#define MC__CFG                                  (MCPARAMID)(  865 << 14)
#define MC__CFG_MONOCAM                            1
#define MC__CFG_DUOCAMA                            2
#define MC__CFG_DUOCAMB                            3
#define MC_TapCount                              (MCPARAMID)(  866 << 14)
#define MC__Bend16                               (MCPARAMID)(  867 << 14)
#define MC__Bend15                               (MCPARAMID)(  868 << 14)
#define MC__Bend14                               (MCPARAMID)(  869 << 14)
#define MC__Bend13                               (MCPARAMID)(  870 << 14)
#define MC__Bend12                               (MCPARAMID)(  871 << 14)
#define MC__Bend11                               (MCPARAMID)(  872 << 14)
#define MC__Bend10                               (MCPARAMID)(  873 << 14)
#define MC__Bend9                                (MCPARAMID)(  874 << 14)
#define MC__Bend8                                (MCPARAMID)(  875 << 14)
#define MC__Bend7                                (MCPARAMID)(  876 << 14)
#define MC__Bend6                                (MCPARAMID)(  877 << 14)
#define MC__Bend5                                (MCPARAMID)(  878 << 14)
#define MC__Bend4                                (MCPARAMID)(  879 << 14)
#define MC__Bend3                                (MCPARAMID)(  880 << 14)
#define MC__Bend2                                (MCPARAMID)(  881 << 14)
#define MC__Bend1                                (MCPARAMID)(  882 << 14)
#define MC_CamCount                              (MCPARAMID)(  883 << 14)
#define MC_ChannelTopology_QUADXTAP                9
#define MC_BackEndProg_ABC34                      10
#define MC_BackEndProg_ABCD44                     11
#define MC_BackEndOption                         (MCPARAMID)(  884 << 14)
#define MC_TimingClockFrequency                  (MCPARAMID)(  885 << 14)
#define MC_TapCount_ONE                            1
#define MC_TapCount_TWO                            2
#define MC_TapCount_THREE                          3
#define MC_TapCount_FOUR                           4
#define MC_TapCount_TWO_Y_END                      5
#define MC_USOutM_ABC1                            13
#define MC_BlockCount                            (MCPARAMID)(  886 << 14)
#define MC_PlaneTopology                         (MCPARAMID)(  887 << 14)
#define MC_PlaneTopology_SINGLE                    1
#define MC_PlaneTopology_MULTIPLE                  2
#define MC_Line1Cfg                              (MCPARAMID)(  888 << 14)
#define MC_Line1Cfg_DIFF_IN_T                      1
#define MC_Line1Cfg_TTL_IN_Z                       2
#define MC_RX1                                   (MCPARAMID)(  889 << 14)
#define MC_TX1                                   (MCPARAMID)(  890 << 14)
#define MC_Line2Cfg                              (MCPARAMID)(  891 << 14)
#define MC_Line2Cfg_DIFF_IN_T                      1
#define MC_Line2Cfg_TTL_IN_Z                       2
#define MC_RX2                                   (MCPARAMID)(  892 << 14)
#define MC_TX2                                   (MCPARAMID)(  893 << 14)
#define MC_SX12                                  (MCPARAMID)(  894 << 14)
#define MC_Line3Cfg                              (MCPARAMID)(  895 << 14)
#define MC_Line3Cfg_DIFF_OUT                       1
#define MC_Line3Cfg_TTL_OUT                        2
#define MC_Line4Cfg                              (MCPARAMID)(  896 << 14)
#define MC_Line4Cfg_DIFF_OUT                       1
#define MC_Line4Cfg_DIFF_IN_T                      2
#define MC_Line4Cfg_TTL_IN_Z                       3
#define MC_RX4                                   (MCPARAMID)(  897 << 14)
#define MC_TX4                                   (MCPARAMID)(  898 << 14)
#define MC_SX34                                  (MCPARAMID)(  899 << 14)
#define MC_Line5Cfg                              (MCPARAMID)(  900 << 14)
#define MC_Line5Cfg_DIFF_OUT                       1
#define MC_Line5Cfg_TTL_OUT                        2
#define MC_Line6Cfg                              (MCPARAMID)(  901 << 14)
#define MC_Line6Cfg_DIFF_OUT                       1
#define MC_Line6Cfg_TTL_OUT                        2
#define MC_SX56                                  (MCPARAMID)(  902 << 14)
#define MC_Line6Ctl_RESET                          3
#define MC_Line6Ctl_EXPOSE                         4
#define MC_Line4Ctl_DCLKIN                         4
#define MC_TPFrequencyRatio                      (MCPARAMID)(  903 << 14)
#define MC__DCGComb                              (MCPARAMID)(  904 << 14)
#define MC__DCGComb_NO                             1
#define MC__DCGComb_YES                            2
#define MC_TimUnitN                              (MCPARAMID)(  905 << 14)
#define MC_TimUnitN_UNKNOWN                        1
#define MC_TimUnitN_FREE                           2
#define MC_TimUnitN_USEDX                          3
#define MC_TimUnitN_USEDY                          4
#define MC_TimUnitN_CONFLICT                       5
#define MC_MapConTim_XY                            7
#define MC_MapDigTim_NONE                          8
#define MC_MapTimCon_TXY                           7
#define MC_MapTimDig_TXX                           7
#define MC_MapTimDig_TXY                           8
#define MC_MapLaneY1_B                             5
#define MC_MapLaneX1_B                             3
#define MC_MapLaneX2_A                             3
#define MC_MapLaneY2_A                             4
#define MC__BoardType                            (MCPARAMID)(  906 << 14)
#define MC__BoardType__ALPHA                       1
#define MC__BoardType__GAMMA                       2
#define MC_MapConTim_YX                            8
#define MC_MapTimCon_TYX                           8
#define MC_VCSync                                (MCPARAMID)(  907 << 14)
#define MC_VCSync_NO                               1
#define MC_VCSync_YES                              2
#define MC__Integer1                             (MCPARAMID)(  908 << 14)
#define MC__SlowMode                             (MCPARAMID)(  909 << 14)
#define MC__SlowMode_OFF                           1
#define MC__SlowMode_ON                            2
#define MC_Expose_Tk                             (MCPARAMID)(  910 << 14)
#define MC__ST_StrxCtl                           (MCPARAMID)(  911 << 14)
#define MC__ST_StrxCtl_High                        1
#define MC__ST_StrxCtl_Low                         2
#define MC__ST_StryCtl                           (MCPARAMID)(  912 << 14)
#define MC__ST_StryCtl_High                        1
#define MC__ST_StryCtl_Low                         2
#define MC__ST_StrzCtl                           (MCPARAMID)(  913 << 14)
#define MC__ST_StrzCtl_High                        1
#define MC__ST_StrzCtl_Low                         2
#define MC__ST_TVxCtl                            (MCPARAMID)(  914 << 14)
#define MC__ST_TVxCtl_High                         1
#define MC__ST_TVxCtl_Low                          2
#define MC__ST_TVxCtl_Input                        3
#define MC__ST_TVyCtl                            (MCPARAMID)(  915 << 14)
#define MC__ST_TVyCtl_High                         1
#define MC__ST_TVyCtl_Low                          2
#define MC__ST_TVyCtl_Input                        3
#define MC__ST_TVzCtl                            (MCPARAMID)(  916 << 14)
#define MC__ST_TVzCtl_High                         1
#define MC__ST_TVzCtl_Low                          2
#define MC__ST_TVzCtl_Input                        3
#define MC__ST_THxCtl                            (MCPARAMID)(  917 << 14)
#define MC__ST_THxCtl_High                         1
#define MC__ST_THxCtl_Low                          2
#define MC__ST_THxCtl_Input                        3
#define MC__ST_THyCtl                            (MCPARAMID)(  918 << 14)
#define MC__ST_THyCtl_High                         1
#define MC__ST_THyCtl_Low                          2
#define MC__ST_THyCtl_Input                        3
#define MC__ST_THzCtl                            (MCPARAMID)(  919 << 14)
#define MC__ST_THzCtl_High                         1
#define MC__ST_THzCtl_Low                          2
#define MC__ST_THzCtl_Input                        3
#define MC__ST_TExCtl                            (MCPARAMID)(  920 << 14)
#define MC__ST_TExCtl_High                         1
#define MC__ST_TExCtl_Low                          2
#define MC__ST_TExCtl_Input                        3
#define MC__ST_TEyCtl                            (MCPARAMID)(  921 << 14)
#define MC__ST_TEyCtl_High                         1
#define MC__ST_TEyCtl_Low                          2
#define MC__ST_TEyCtl_Input                        3
#define MC__ST_TEzCtl                            (MCPARAMID)(  922 << 14)
#define MC__ST_TEzCtl_High                         1
#define MC__ST_TEzCtl_Low                          2
#define MC__ST_TEzCtl_Input                        3
#define MC__ST_TGxCtl                            (MCPARAMID)(  923 << 14)
#define MC__ST_TGxCtl_High                         1
#define MC__ST_TGxCtl_Low                          2
#define MC__ST_TGxCtl_Input                        3
#define MC__ST_TGyCtl                            (MCPARAMID)(  924 << 14)
#define MC__ST_TGyCtl_High                         1
#define MC__ST_TGyCtl_Low                          2
#define MC__ST_TGyCtl_Input                        3
#define MC__ST_TGzCtl                            (MCPARAMID)(  925 << 14)
#define MC__ST_TGzCtl_High                         1
#define MC__ST_TGzCtl_Low                          2
#define MC__ST_TGzCtl_Input                        3
#define MC__ST_TRxCtl                            (MCPARAMID)(  926 << 14)
#define MC__ST_TRxCtl_High                         1
#define MC__ST_TRxCtl_Low                          2
#define MC__ST_TRxCtl_Input                        3
#define MC__ST_TRyCtl                            (MCPARAMID)(  927 << 14)
#define MC__ST_TRyCtl_High                         1
#define MC__ST_TRyCtl_Low                          2
#define MC__ST_TRyCtl_Input                        3
#define MC__ST_TRzCtl                            (MCPARAMID)(  928 << 14)
#define MC__ST_TRzCtl_High                         1
#define MC__ST_TRzCtl_Low                          2
#define MC__ST_TRzCtl_Input                        3
#define MC__ST_Out1Ctl                           (MCPARAMID)(  929 << 14)
#define MC__ST_Out1Ctl_High                        1
#define MC__ST_Out1Ctl_Low                         2
#define MC__ST_Out2Ctl                           (MCPARAMID)(  930 << 14)
#define MC__ST_Out2Ctl_High                        1
#define MC__ST_Out2Ctl_Low                         2
#define MC__ST_Out3Ctl                           (MCPARAMID)(  931 << 14)
#define MC__ST_Out3Ctl_High                        1
#define MC__ST_Out3Ctl_Low                         2
#define MC__ST_Out4Ctl                           (MCPARAMID)(  932 << 14)
#define MC__ST_Out4Ctl_High                        1
#define MC__ST_Out4Ctl_Low                         2
#define MC_Destination_DSP12                       4
#define MC__ST_aFilter                           (MCPARAMID)(  933 << 14)
#define MC__ST_aFilter_NONE                        1
#define MC__ST_aFilter_10MHZ                       2
#define MC__ST_aFilter_5MHZ                        3
#define MC__ST_aFilter_5MHZ_PAL                    4
#define MC__ST_aFilter_5MHZ_NTSC                   5
#define MC__ST_bFilter                           (MCPARAMID)(  934 << 14)
#define MC__ST_bFilter_NONE                        1
#define MC__ST_bFilter_10MHZ                       2
#define MC__ST_bFilter_5MHZ                        3
#define MC__ST_bFilter_5MHZ_PAL                    4
#define MC__ST_bFilter_5MHZ_NTSC                   5
#define MC_CamConfig_P25RD                        16
#define MC__TIMATIM                              (MCPARAMID)(  935 << 14)
#define MC__DIGATIM                              (MCPARAMID)(  936 << 14)
#define MC_CamConfig_P30RD                        17
#define MC_Clanes_qP_QS                           17
#define MC_Clanes_sR_SQ                           18
#define MC_MMmask                                (MCPARAMID)(  937 << 14)
#define MC_GrabberConfig_0_3_1                     7
#define MC__ASSY31                               (MCPARAMID)(  938 << 14)
#define MC__ASSY32                               (MCPARAMID)(  939 << 14)
#define MC__ASSY33                               (MCPARAMID)(  940 << 14)
#define MC__ASSY34                               (MCPARAMID)(  941 << 14)
#define MC__PShiftA                              (MCPARAMID)(  942 << 14)
#define MC__PShiftB                              (MCPARAMID)(  943 << 14)
#define MC__PShiftC                              (MCPARAMID)(  944 << 14)
#define MC__PShiftD                              (MCPARAMID)(  945 << 14)
#define MC__PShift3                              (MCPARAMID)(  946 << 14)
#define MC__CPHASE                               (MCPARAMID)(  947 << 14)
#define MC__CPHASE_INDEPENDENT                     1
#define MC__CPHASE_GROUPED                         2
#define MC_Camera_HV_C20AEK                       12
#define MC_Camera_XC_003                          13
#define MC__RSTFIFO                              (MCPARAMID)(  948 << 14)
#define MC__RSTFIFO_DISABLED                       1
#define MC__RSTFIFO_ENABLED                        2
#define MC__Fields                               (MCPARAMID)(  949 << 14)
#define MC__UpField                              (MCPARAMID)(  950 << 14)
#define MC__STARTU3                              (MCPARAMID)(  951 << 14)
#define MC__STARTD3                              (MCPARAMID)(  952 << 14)
#define MC_Cable_A15_C08                           8
#define MC_Cable_A15_C09                           9
#define MC_LutSelect1                            (MCPARAMID)(  953 << 14)
#define MC_LutSelect2                            (MCPARAMID)(  954 << 14)
#define MC_LutSelect3                            (MCPARAMID)(  955 << 14)
#define MC_InputFilter                           (MCPARAMID)(  956 << 14)
#define MC_InputFilter_NONE                        1
#define MC_InputFilter_10MHZ                       2
#define MC_InputFilter_5MHZ                        3
#define MC_InputFilter_5MHZ_PAL                    4
#define MC_InputFilter_5MHZ_NTSC                   5
#define MC_VideoFilter                           (MCPARAMID)(  957 << 14)
#define MC_VideoFilter_NONE                        1
#define MC_VideoFilter_10MHZ                       2
#define MC_VideoFilter_5MHZ                        3
#define MC_VideoFilter_5MHZ_PAL                    4
#define MC_VideoFilter_5MHZ_NTSC                   5
#define MC_SYNCLoadSet                           (MCPARAMID)(  958 << 14)
#define MC_VCAMLoadSet                           (MCPARAMID)(  959 << 14)
#define MC_SWISet                                (MCPARAMID)(  960 << 14)
#define MC_SASSet                                (MCPARAMID)(  961 << 14)
#define MC_EAPSet                                (MCPARAMID)(  962 << 14)
#define MC_NOWSet                                (MCPARAMID)(  963 << 14)
#define MC___MSFError_Check                      (MCPARAMID)(  964 << 14)
#define MC___MSFError_Check_PASS                   1
#define MC___MSFError_Check_FAIL                   2
#define MC___GrabberConfig_Check                 (MCPARAMID)(  965 << 14)
#define MC___GrabberConfig_Check_PASS              1
#define MC___GrabberConfig_Check_FAIL              2
#define MC___Alpha_TimUnitN_Check                (MCPARAMID)(  966 << 14)
#define MC___Alpha_TimUnitN_Check_PASS             1
#define MC___Alpha_TimUnitN_Check_FAIL             2
#define MC___Alpha_SyncMode_Check                (MCPARAMID)(  967 << 14)
#define MC___Alpha_SyncMode_Check_PASS             1
#define MC___Alpha_SyncMode_Check_FAIL             2
#define MC___Alpha_ADresolution_Check            (MCPARAMID)(  968 << 14)
#define MC___Alpha_ADresolution_Check_PASS         1
#define MC___Alpha_ADresolution_Check_FAIL         2
#define MC___Alpha_CalPat_Check                  (MCPARAMID)(  969 << 14)
#define MC___Alpha_CalPat_Check_PASS               1
#define MC___Alpha_CalPat_Check_FAIL               2
#define MC_GrabberConfig_Filter                  (MCPARAMID)(  970 << 14)
#define MC_TrigMode_Filter                       (MCPARAMID)(  971 << 14)
#define MC_Connector_Filter                      (MCPARAMID)(  972 << 14)
#define MC_ConnectLoc_Filter                     (MCPARAMID)(  973 << 14)
#define MC_ADresolution_Filter                   (MCPARAMID)(  974 << 14)
#define MC_CalPat_Filter                         (MCPARAMID)(  975 << 14)
#define MC_ChannelTopology_Filter                (MCPARAMID)(  976 << 14)
#define MC_SyncMode_Filter                       (MCPARAMID)(  977 << 14)
#define MC_Cable_Filter                          (MCPARAMID)(  978 << 14)
#define MC_Camera_KP_F3                           14
#define MC_Camera_KP_F3W                          15
#define MC_Camera_Generic                         16
#define MC_Camera_Generic_RGB                     17
#define MC_NextTrigMode_SAME                       5
#define MC_CamConfig_I50RA                        18
#define MC_Cable_A15_C10                          10
#define MC_X_VRSTOn                              (MCPARAMID)(  979 << 14)
#define MC_X_VRSTOff                             (MCPARAMID)(  980 << 14)
#define MC__DeltaX_SIGEOL_RSTOn                  (MCPARAMID)(  981 << 14)
#define MC__DeltaX_SIGEOL_RSTOff                 (MCPARAMID)(  982 << 14)
#define MC_Camera_HV_C20AP                        12
#define MC_Operation_SPECIAL                       4
#define MC_HV_C20AP_AsyncLoadSet                 (MCPARAMID)(  983 << 14)
#define MC_CamConfig_P100SA                       19
#define MC_HReset                                (MCPARAMID)(  984 << 14)
#define MC_HReset_NO                               1
#define MC_HReset_YES                              2
#define MC__ETimebase                            (MCPARAMID)(  985 << 14)
#define MC__ETimebase_READOUT_TIMER                1
#define MC__ETimebase_TIMING_CLOCK                 2
#define MC__E_Tk                                 (MCPARAMID)(  986 << 14)
#define MC__ESpan_us                             (MCPARAMID)(  987 << 14)
#define MC__ESpan_Tk                             (MCPARAMID)(  988 << 14)
#define MC__EXPOn_E                              (MCPARAMID)(  989 << 14)
#define MC__EXPOff_E                             (MCPARAMID)(  990 << 14)
#define MC__ExposeWidth_E                        (MCPARAMID)(  991 << 14)
#define MC__StrobeWidth_E                        (MCPARAMID)(  992 << 14)
#define MC__STROn_E                              (MCPARAMID)(  993 << 14)
#define MC__STROff_E                             (MCPARAMID)(  994 << 14)
#define MC__EXPWidth_E                           (MCPARAMID)(  995 << 14)
#define MC__STRWidth_E                           (MCPARAMID)(  996 << 14)
#define MC__ENDE_E                               (MCPARAMID)(  997 << 14)
#define MC_ExpEdge                               (MCPARAMID)(  998 << 14)
#define MC_ExpEdge_GOLOW                           1
#define MC_ExpEdge_GOHIGH                          2
#define MC__TrueExp_Tk                           (MCPARAMID)(  999 << 14)
#define MC__ExposeTrim_pc                        (MCPARAMID)( 1000 << 14)
#define MC_CamConfig_P100RA_G                     20
#define MC_ExposeOverlap                         (MCPARAMID)( 1001 << 14)
#define MC_ExposeOverlap_FORBID                    1
#define MC_ExposeOverlap_ALLOW                     2
#define MC__TrigLine                             (MCPARAMID)( 1002 << 14)
#define MC_D4Input                               (MCPARAMID)( 1003 << 14)
#define MC_D4Input_ON                              1
#define MC_D4Input_OFF                             2
#define MC__Category                             (MCPARAMID)( 1004 << 14)
#define MC__Category_Camera_Specification          1
#define MC__Category_Camera_Timing                 2
#define MC__Category_Camera_Features               3
#define MC__Category_Line_Scan_Features            4
#define MC__Category_Trigger_Control               5
#define MC__Category_Exposure_Control              6
#define MC__Category_Strobe_Control                7
#define MC__Category_Board_Linkage                 8
#define MC__Category_Board_Configuration           9
#define MC__Category_Grabber_Configuration        10
#define MC__Category_Grabber_Timing               11
#define MC__Category_Grabber_Conditioning         12
#define MC__Category_Cluster_Linkage              13
#define MC_CamConfig_FACTORY                      21
#define MC_TapStructure                          (MCPARAMID)( 1005 << 14)
#define MC_TapStructure_SINGLE_A                   1
#define MC_TapStructure_DUAL_A                     2
#define MC_TapStructure_TRIPLE_A                   3
#define MC_Manufacturer                          (MCPARAMID)( 1006 << 14)
#define MC_Manufacturer_NONE                       1
#define MC_Manufacturer_HITACHI                    2
#define MC_Manufacturer_JAI                        3
#define MC_Manufacturer_SONY                       4
#define MC_Imaging                               (MCPARAMID)( 1007 << 14)
#define MC_Imaging_AREA                            1
#define MC_Spectrum                              (MCPARAMID)( 1008 << 14)
#define MC_Spectrum_BW                             1
#define MC_Spectrum_COLOR                          2
#define MC_Spectrum_IR                             3
#define MC_DataLink                              (MCPARAMID)( 1009 << 14)
#define MC_DataLink_ANALOG                         1
#define MC_ColorMethod                           (MCPARAMID)( 1010 << 14)
#define MC_ColorMethod_NONE                        1
#define MC_ColorMethod_PRISM                       2
#define MC_ColorMethod_RGB                         3
#define MC_Expose                                (MCPARAMID)( 1011 << 14)
#define MC_Expose_PLSTRG                           3
#define MC_Expose_PLSCTL                           4
#define MC_Expose_WIDTH                            5
#define MC_Expose_INTCTL                           6
#define MC_Expose_INTPRM                           7
#define MC_Expose_EXTPRM                           8
#define MC_Readout                               (MCPARAMID)( 1012 << 14)
#define MC_Readout_PLSTRG                          1
#define MC_Readout_WIDTH                           2
#define MC_Readout_INTCTL                          3
#define MC__Category_Channel_Management           14
#define MC__Category_Exception_Management         15
#define MC__Category_Board_Information            16
#define MC__ScanMode                             (MCPARAMID)( 1013 << 14)
#define MC__ScanMode_PROGRESSIVE                   1
#define MC__ScanMode_INTERLACE                     2
#define MC_ENDSet                                (MCPARAMID)( 1014 << 14)
#define MC_EncoderTrim                           (MCPARAMID)( 1015 << 14)
#define MC__BitCalcArg                           (MCPARAMID)( 1016 << 14)
#define MC__XTALTrim                             (MCPARAMID)( 1017 << 14)
#define MC__REFCKATrim                           (MCPARAMID)( 1018 << 14)
#define MC__BoardType__VALUE                       3
#define MC__BoardType__EXPERT                      4
#define MC_Camera_Generic_Dual                    18
#define MC_Camera_1000m                           19
#define MC_TapStructure_SINGLE_B                   4
#define MC_TapStructure_SINGLE_W                   5
#define MC_TapStructure_DUAL_B                     6
#define MC_TapStructure_DUAL_B2                    7
#define MC_TapStructure_DUAL_W                     8
#define MC_TapStructure_DUAL_W2                    9
#define MC_TapStructure_TRIPLE_B                  10
#define MC_TapStructure_TRIPLE_W                  11
#define MC_TapStructure_QUAD_B                    12
#define MC_TapStructure_QUAD_B2                   13
#define MC_TapStructure_QUAD_B4                   14
#define MC_TapStructure_OCTAL_B2                  15
#define MC_TapStructure_Filter                   (MCPARAMID)( 1019 << 14)
#define MC_Operation_PAGE                          5
#define MC_Operation_WEB                           6
#define MC_Manufacturer_ADIMEC                     5
#define MC_DataLink_CAMERALINK                     2
#define MC_DataClk_Hz                            (MCPARAMID)( 1020 << 14)
#define MC_Hactive_Px                            (MCPARAMID)( 1021 << 14)
#define MC_HsyncAft_ns                           (MCPARAMID)( 1022 << 14)
#define MC_VsyncPst_Ln                           (MCPARAMID)( 1023 << 14)
#define MC_HsyncPst_ns                           (MCPARAMID)( 1024 << 14)
#define MC_VgatePos_Ln                           (MCPARAMID)( 1025 << 14)
#define MC_CameraDataWidth                       (MCPARAMID)( 1026 << 14)
#define MC_CameraDataWidth_8BIT                    1
#define MC_CameraDataWidth_10BIT                   2
#define MC_CameraDataWidth_12BIT                   3
#define MC_CameraDataWidth_14BIT                   4
#define MC_CameraDataWidth_16BIT                   5
#define MC_PixelClkCtl_BUILTIN                     4
#define MC_PixelClkEdge_BUILTIN                    3
#define MC_HsyncCtl_BUILTIN                        4
#define MC_VsyncCtl_BUILTIN                        4
#define MC_ResetCtl                              (MCPARAMID)( 1027 << 14)
#define MC_ResetCtl_NONE                           1
#define MC_ResetCtl_TTL                            2
#define MC_ResetCtl_DIFF                           3
#define MC_ResetEdge                             (MCPARAMID)( 1028 << 14)
#define MC_ResetEdge_GOHIGH                        1
#define MC_ResetEdge_GOLOW                         2
#define MC_AuxResetCtl                           (MCPARAMID)( 1029 << 14)
#define MC_AuxResetCtl_NONE                        1
#define MC_AuxResetCtl_TTL                         2
#define MC_AuxResetCtl_DIFF                        3
#define MC_AuxResetEdge                          (MCPARAMID)( 1030 << 14)
#define MC_AuxResetEdge_GOHIGH                     1
#define MC_AuxResetEdge_GOLOW                      2
#define MC_ResetDur                              (MCPARAMID)( 1031 << 14)
#define MC_ResetPos                              (MCPARAMID)( 1032 << 14)
#define MC_ExposeMin_us                          (MCPARAMID)( 1033 << 14)
#define MC_ExposeMax_us                          (MCPARAMID)( 1034 << 14)
#define MC_FvalMode                              (MCPARAMID)( 1035 << 14)
#define MC_FvalMode_FN                             1
#define MC_FvalMode_FA                             2
#define MC_FvalMode_FC                             3
#define MC_FvalMode_PC                             4
#define MC_LvalMode                              (MCPARAMID)( 1036 << 14)
#define MC_LvalMode_LA                             1
#define MC_LvalMode_LP                             2
#define MC_LvalMode_LB                             3
#define MC_LvalMode_LC                             4
#define MC_DvalMode                              (MCPARAMID)( 1037 << 14)
#define MC_DvalMode_DN                             1
#define MC_DvalMode_DG                             2
#define MC_DvalMode_DC                             3
#define MC_Cable_CL_C01                           11
#define MC__Category_Cable_Features               17
#define MC__Category_Encoder_Control              18
#define MC_PageDelay_Ln                          (MCPARAMID)( 1038 << 14)
#define MC_PageLength_Ln                         (MCPARAMID)( 1039 << 14)
#define MC_GrabberDataWidth                      (MCPARAMID)( 1040 << 14)
#define MC_GrabberDataWidth_8BIT                   1
#define MC_GrabberDataWidth_10BIT                  2
#define MC_GrabberDataWidth_12BIT                  3
#define MC_GrabberDataWidth_14BIT                  4
#define MC_GrabberDataWidth_16BIT                  5
#define MC__CDC_SRC                              (MCPARAMID)( 1041 << 14)
#define MC__CDC_SRC_CAMERA                         1
#define MC__CDC_SRC_TPG                            2
#define MC__CDC_ISIZE                            (MCPARAMID)( 1042 << 14)
#define MC__CDC_ISIZE_BASE8                        1
#define MC__CDC_ISIZE_BASE10                       2
#define MC__CDC_ISIZE_BASE12                       3
#define MC__CDC_ISIZE_BASE14                       4
#define MC__CDC_ISIZE_BASE16                       5
#define MC__CDC_ALIGN                            (MCPARAMID)( 1043 << 14)
#define MC__CDC_ALIGN_BYTE                         1
#define MC__CDC_ALIGN_WORDMS                       2
#define MC__CDC_ALIGN_WORDLS                       3
#define MC__CDC_FALLOC1                          (MCPARAMID)( 1044 << 14)
#define MC__CDC_FALLOC1_256_0                      1
#define MC__CDC_FALLOC1_128_0                      2
#define MC__CDC_FALLOC1_128_128                    3
#define MC__CDC_FALLOC1_64_0                       4
#define MC__CDC_FALLOC1_64_64                      5
#define MC__CDC_FALLOC1_64_128                     6
#define MC__CDC_FALLOC1_64_192                     7
#define MC__CDC_FALLOC2                          (MCPARAMID)( 1045 << 14)
#define MC__CDC_FALLOC2_256_0                      1
#define MC__CDC_FALLOC2_128_0                      2
#define MC__CDC_FALLOC2_128_128                    3
#define MC__CDC_FALLOC2_64_0                       4
#define MC__CDC_FALLOC2_64_64                      5
#define MC__CDC_FALLOC2_64_128                     6
#define MC__CDC_FALLOC2_64_192                     7
#define MC__CDC_FALLOC3                          (MCPARAMID)( 1046 << 14)
#define MC__CDC_FALLOC3_256_0                      1
#define MC__CDC_FALLOC3_128_0                      2
#define MC__CDC_FALLOC3_128_128                    3
#define MC__CDC_FALLOC3_64_0                       4
#define MC__CDC_FALLOC3_64_64                      5
#define MC__CDC_FALLOC3_64_128                     6
#define MC__CDC_FALLOC3_64_192                     7
#define MC__CBA_FALLOC1                          (MCPARAMID)( 1047 << 14)
#define MC__CBA_FALLOC1_256_0                      1
#define MC__CBA_FALLOC1_128_0                      2
#define MC__CBA_FALLOC1_128_128                    3
#define MC__CBA_FALLOC1_64_0                       4
#define MC__CBA_FALLOC1_64_64                      5
#define MC__CBA_FALLOC1_64_128                     6
#define MC__CBA_FALLOC1_64_192                     7
#define MC__CBA_FALLOC2                          (MCPARAMID)( 1048 << 14)
#define MC__CBA_FALLOC2_256_0                      1
#define MC__CBA_FALLOC2_128_0                      2
#define MC__CBA_FALLOC2_128_128                    3
#define MC__CBA_FALLOC2_64_0                       4
#define MC__CBA_FALLOC2_64_64                      5
#define MC__CBA_FALLOC2_64_128                     6
#define MC__CBA_FALLOC2_64_192                     7
#define MC__CBA_FALLOC3                          (MCPARAMID)( 1049 << 14)
#define MC__CBA_FALLOC3_256_0                      1
#define MC__CBA_FALLOC3_128_0                      2
#define MC__CBA_FALLOC3_128_128                    3
#define MC__CBA_FALLOC3_64_0                       4
#define MC__CBA_FALLOC3_64_64                      5
#define MC__CBA_FALLOC3_64_128                     6
#define MC__CBA_FALLOC3_64_192                     7
#define MC__CBA_FALLOC4                          (MCPARAMID)( 1050 << 14)
#define MC__CBA_FALLOC4_256_0                      1
#define MC__CBA_FALLOC4_128_0                      2
#define MC__CBA_FALLOC4_128_128                    3
#define MC__CBA_FALLOC4_64_0                       4
#define MC__CBA_FALLOC4_64_64                      5
#define MC__CBA_FALLOC4_64_128                     6
#define MC__CBA_FALLOC4_64_192                     7
#define MC__WIC                                  (MCPARAMID)( 1051 << 14)
#define MC__WIC_ONE                                1
#define MC__WIC_TWO                                2
#define MC__WIC_THREE                              3
#define MC__WIC_FOUR                               4
#define MC__CBA_SHIFT1                           (MCPARAMID)( 1052 << 14)
#define MC__CBA_SHIFT2                           (MCPARAMID)( 1053 << 14)
#define MC__CBA_SHIFT3                           (MCPARAMID)( 1054 << 14)
#define MC__CBA_SHIFT4                           (MCPARAMID)( 1055 << 14)
#define MC_Connector_X_Y                           7
#define MC__CBA_GROUP1                           (MCPARAMID)( 1056 << 14)
#define MC__ASSY                                 (MCPARAMID)( 1057 << 14)
#define MC__ASSY_ONE                               1
#define MC__ASSY_TWO                               2
#define MC__ASSY_THREE                             3
#define MC__ASSY_FOUR                              4
#define MC__CBA_GROUP2                           (MCPARAMID)( 1058 << 14)
#define MC__CBA_GROUP3                           (MCPARAMID)( 1059 << 14)
#define MC__CDC_ISIZE_MEDIUM8                      6
#define MC__CDC_ISIZE_MEDIUM10                     7
#define MC__CDC_ISIZE_MEDIUM12                     8
#define MC__CAM                                  (MCPARAMID)( 1060 << 14)
#define MC__CAM_MONOCAM                            1
#define MC__CAM_DUOCAM                             2
#define MC__CTA_START01                          (MCPARAMID)( 1061 << 14)
#define MC__CTA_START11                          (MCPARAMID)( 1062 << 14)
#define MC__CTA_START02                          (MCPARAMID)( 1063 << 14)
#define MC__CTA_START12                          (MCPARAMID)( 1064 << 14)
#define MC__BW                                   (MCPARAMID)( 1065 << 14)
#define MC__ISIZX                                (MCPARAMID)( 1066 << 14)
#define MC__ISIZYF                               (MCPARAMID)( 1067 << 14)
#define MC__ISIZY                                (MCPARAMID)( 1068 << 14)
#define MC__WX                                   (MCPARAMID)( 1069 << 14)
#define MC__WY                                   (MCPARAMID)( 1070 << 14)
#define MC__DirX1                                (MCPARAMID)( 1071 << 14)
#define MC__DirX2                                (MCPARAMID)( 1072 << 14)
#define MC__DirX3                                (MCPARAMID)( 1073 << 14)
#define MC__DirY1                                (MCPARAMID)( 1074 << 14)
#define MC__DirY2                                (MCPARAMID)( 1075 << 14)
#define MC__DirY3                                (MCPARAMID)( 1076 << 14)
#define MC_ImagePitch                            (MCPARAMID)( 1077 << 14)
#define MC__PITCH1                               (MCPARAMID)( 1078 << 14)
#define MC__PITCH2                               (MCPARAMID)( 1079 << 14)
#define MC__PITCH3                               (MCPARAMID)( 1080 << 14)
#define MC__InterlaceFactor                      (MCPARAMID)( 1081 << 14)
#define MC__CTA_STEPX1                           (MCPARAMID)( 1082 << 14)
#define MC__CTA_STEPX2                           (MCPARAMID)( 1083 << 14)
#define MC__CTA_STEPX3                           (MCPARAMID)( 1084 << 14)
#define MC__CTA_STEPY1                           (MCPARAMID)( 1085 << 14)
#define MC__CTA_STEPY2                           (MCPARAMID)( 1086 << 14)
#define MC__CTA_STEPY3                           (MCPARAMID)( 1087 << 14)
#define MC__OFSD1                                (MCPARAMID)( 1088 << 14)
#define MC__OFSD2                                (MCPARAMID)( 1089 << 14)
#define MC__OFSD3                                (MCPARAMID)( 1090 << 14)
#define MC__OFSU1                                (MCPARAMID)( 1091 << 14)
#define MC__OFSU2                                (MCPARAMID)( 1092 << 14)
#define MC__OFSU3                                (MCPARAMID)( 1093 << 14)
#define MC__CTA_OFSD1                            (MCPARAMID)( 1094 << 14)
#define MC__CTA_OFSD2                            (MCPARAMID)( 1095 << 14)
#define MC__CTA_OFSD3                            (MCPARAMID)( 1096 << 14)
#define MC__CTA_OFSU1                            (MCPARAMID)( 1097 << 14)
#define MC__CTA_OFSU2                            (MCPARAMID)( 1098 << 14)
#define MC__CTA_OFSU3                            (MCPARAMID)( 1099 << 14)
#define MC__CTA_SELINC                           (MCPARAMID)( 1100 << 14)
#define MC__CTA_SELINC_EOL                         1
#define MC__CTA_SELINC_EOF                         2
#define MC__CTA_SELINC_EOL2                        3
#define MC__CTA_SELINC_EOF2                        4
#define MC__Xchannels                            (MCPARAMID)( 1101 << 14)
#define MC__CTA_OFS01                            (MCPARAMID)( 1102 << 14)
#define MC__CTA_OFS11                            (MCPARAMID)( 1103 << 14)
#define MC__CTA_OFS02                            (MCPARAMID)( 1104 << 14)
#define MC__CTA_OFS12                            (MCPARAMID)( 1105 << 14)
#define MC__CTA_TFINC                            (MCPARAMID)( 1106 << 14)
#define MC__CBA_PSHIFT1                          (MCPARAMID)( 1107 << 14)
#define MC__CBA_PSHIFT2                          (MCPARAMID)( 1108 << 14)
#define MC__CBA_PSHIFT3                          (MCPARAMID)( 1109 << 14)
#define MC__CBA_PSHIFT4                          (MCPARAMID)( 1110 << 14)
#define MC_CamConfig_P25SC_S8                     22
#define MC_CamConfig_P25SC_S10                    23
#define MC_CamConfig_P50SC_D8                     24
#define MC_CamConfig_P50SC_D10                    25
#define MC_HsyncAft_Tk                           (MCPARAMID)( 1111 << 14)
#define MC_HsyncPst_Tk                           (MCPARAMID)( 1112 << 14)
#define MC__PITCH1_mw                            (MCPARAMID)( 1113 << 14)
#define MC__PITCH2_mw                            (MCPARAMID)( 1114 << 14)
#define MC__PITCH3_mw                            (MCPARAMID)( 1115 << 14)
#define MC__SIZX_mw                              (MCPARAMID)( 1116 << 14)
#define MC__STARTU1_mw                           (MCPARAMID)( 1117 << 14)
#define MC__STARTU2_mw                           (MCPARAMID)( 1118 << 14)
#define MC__STARTU3_mw                           (MCPARAMID)( 1119 << 14)
#define MC__STARTD1_mw                           (MCPARAMID)( 1120 << 14)
#define MC__STARTD2_mw                           (MCPARAMID)( 1121 << 14)
#define MC__STARTD3_mw                           (MCPARAMID)( 1122 << 14)
#define MC__OFSU1_mw                             (MCPARAMID)( 1123 << 14)
#define MC__OFSU2_mw                             (MCPARAMID)( 1124 << 14)
#define MC__OFSU3_mw                             (MCPARAMID)( 1125 << 14)
#define MC__OFSD1_mw                             (MCPARAMID)( 1126 << 14)
#define MC__OFSD2_mw                             (MCPARAMID)( 1127 << 14)
#define MC__OFSD3_mw                             (MCPARAMID)( 1128 << 14)
#define MC__IPitch_mw                            (MCPARAMID)( 1129 << 14)
#define MC__Pitch_mw                             (MCPARAMID)( 1130 << 14)
#define MC_GrabSizeX_Px                          (MCPARAMID)( 1131 << 14)
#define MC_CamConfig_P50SC                        26
#define MC_GrabberDataWidth_Filter               (MCPARAMID)( 1132 << 14)
#define MC_GrabSizeXStep_Px                      (MCPARAMID)( 1133 << 14)
#define MC_CamConfig_Filter                      (MCPARAMID)( 1134 << 14)
#define MC__VLC_LCNT                             (MCPARAMID)( 1135 << 14)
#define MC__VLC_LBFR                             (MCPARAMID)( 1136 << 14)
#define MC__VLC_LAFT                             (MCPARAMID)( 1137 << 14)
#define MC__VLC_DCNT                             (MCPARAMID)( 1138 << 14)
#define MC__VLC_DBFR                             (MCPARAMID)( 1139 << 14)
#define MC__VLC_DAFT                             (MCPARAMID)( 1140 << 14)
#define MC__x_INDEX                              (MCPARAMID)( 1141 << 14)
#define MC__D1_INDEX                             (MCPARAMID)( 1142 << 14)
#define MC__D2_INDEX                             (MCPARAMID)( 1143 << 14)
#define MC__D3_INDEX                             (MCPARAMID)( 1144 << 14)
#define MC__D4_INDEX                             (MCPARAMID)( 1145 << 14)
#define MC_FutureUseLoadSet                      (MCPARAMID)( 1146 << 14)
#define MC_DigUnit1_E                              5
#define MC_DigUnit1_F                              6
#define MC_DigUnit1_G                              7
#define MC_DigUnit1_H                              8
#define MC_Camera_A201b                           21
#define MC_CamConfig_P30SC                        27
#define MC_Manufacturer_BASLER                     6
#define MC_Cable_CL_C02                           12
#define MC_LinePitch_Filter                      (MCPARAMID)( 1147 << 14)
#define MC_PageDelay_Ln_Filter                   (MCPARAMID)( 1148 << 14)
#define MC_PageLength_Ln_Filter                  (MCPARAMID)( 1149 << 14)
#define MC_EncoderPitch_Filter                   (MCPARAMID)( 1150 << 14)
#define MC_Camera_Filter                         (MCPARAMID)( 1151 << 14)
#define MC_Operation_Filter                      (MCPARAMID)( 1152 << 14)
#define MC___Unsupported_Parameter_Filter        (MCPARAMID)( 1153 << 14)
#define MC_MAN_GrabWindow_Filter                 (MCPARAMID)( 1154 << 14)
#define MC_Camera_A202k                           22
#define MC_Camera_Manufacturer_Filter            (MCPARAMID)( 1155 << 14)
#define MC_CableName                             (MCPARAMID)( 1156 << 14)
#define MC_CableName_CameraLink_Standard           1
#define MC_CableName_Basler_Channel_Link           2
#define MC___CamConfig_Check                     (MCPARAMID)( 1157 << 14)
#define MC___CamConfig_Check_PASS                  1
#define MC___CamConfig_Check_FAIL                  2
#define MC_CamConfig_P48SC                        28
#define MC_ResetLine                             (MCPARAMID)( 1158 << 14)
#define MC_ResetLine_CC1                           1
#define MC_ResetLine_CC2                           2
#define MC_ResetLine_CC3                           3
#define MC_ResetLine_CC4                           4
#define MC_AuxresetLine                          (MCPARAMID)( 1159 << 14)
#define MC_AuxresetLine_CC1                        1
#define MC_AuxresetLine_CC2                        2
#define MC_AuxresetLine_CC3                        3
#define MC_AuxresetLine_CC4                        4
#define MC_CamConfig_P50SM                        29
#define MC__ClkSynthReq                          (MCPARAMID)( 1160 << 14)
#define MC__ClkSynthReq_NONE                       1
#define MC__ClkSynthReq_CS1                        2
#define MC__ClkSynthReq_CS2                        3
#define MC_ClkSynth1_UNKNOWN                       1
#define MC_ClkSynth1_FREE                          2
#define MC_ClkSynth1_USEDX                         3
#define MC_ClkSynth1_USEDY                         4
#define MC_ClkSynth1_USEDZ                         5
#define MC_ClkSynth2_UNKNOWN                       1
#define MC_ClkSynth2_FREE                          2
#define MC_ClkSynth2_USEDX                         3
#define MC_ClkSynth2_USEDY                         4
#define MC_ClkSynth2_USEDZ                         5
#define MC_ClkSynth1_XXX                           6
#define MC_ClkSynth2_XXX                           6
#define MC___Gamma_ClkSynth_Check                (MCPARAMID)( 1161 << 14)
#define MC___Gamma_ClkSynth_Check_PASS             1
#define MC___Gamma_ClkSynth_Check_FAIL             2
#define MC_ClkSynth1_Hz                          (MCPARAMID)( 1162 << 14)
#define MC_ClkSynth2_Hz                          (MCPARAMID)( 1163 << 14)
#define MC__VerticalSyncMode                     (MCPARAMID)( 1164 << 14)
#define MC__VerticalSyncMode_ANALOG                1
#define MC__VerticalSyncMode_DIGITAL               2
#define MC__VerticalSyncMode_MASTER                3
#define MC__SYNC_Line1_Type                      (MCPARAMID)( 1165 << 14)
#define MC_TimUnitN_XXX                            6
#define MC__SSC                                  (MCPARAMID)( 1166 << 14)
#define MC__SSC_CCIR                               1
#define MC__SSC_EIA                                2
#define MC__SSC_CCIR_2                             3
#define MC__SSC_EIA_2                              4
#define MC__SSC_OUTOFRANGE                         5
#define MC__SELH_SSC                               5
#define MC__SYNC_Line1_Type_BLANK_VRSTOFF          1
#define MC__SYNC_Line1_Type_BLANK_VRSTON           2
#define MC__SYNC_Line1_Dur                       (MCPARAMID)( 1167 << 14)
#define MC__SYNC_Line2_Type                      (MCPARAMID)( 1168 << 14)
#define MC__SYNC_Line2_Type_BLANK_VRSTOFF          1
#define MC__SYNC_Line2_Dur                       (MCPARAMID)( 1169 << 14)
#define MC__SYNC_Line3_Type                      (MCPARAMID)( 1170 << 14)
#define MC__SYNC_Line3_Type_ACQ_VRSTOFF            1
#define MC__SYNC_Line3_Dur                       (MCPARAMID)( 1171 << 14)
#define MC__SYNC_Line4_Type                      (MCPARAMID)( 1172 << 14)
#define MC__SYNC_Line4_Type_ACQ_VRSTOFF            1
#define MC__SYNC_Line4_Type_ACQ_VRSTON             2
#define MC__SYNC_Line4_Dur                       (MCPARAMID)( 1173 << 14)
#define MC__SYNC_Line5_Type                      (MCPARAMID)( 1174 << 14)
#define MC__SYNC_Line5_Type_BLANK_VRSTOFF          1
#define MC__SYNC_Line5_Type_BLANK_VRSTON           2
#define MC__SYNC_Line5_Dur                       (MCPARAMID)( 1175 << 14)
#define MC__SYNC_Acq_Dur                         (MCPARAMID)( 1176 << 14)
#define MC__SYNC_Vrst_Dur                        (MCPARAMID)( 1177 << 14)
#define MC__SYNC_RefV2Acq_Gap                    (MCPARAMID)( 1178 << 14)
#define MC__SYNC_Field_Dur                       (MCPARAMID)( 1179 << 14)
#define MC__SYNC_Eacq2Vrst_Gap                   (MCPARAMID)( 1180 << 14)
#define MC__SYNC_Vrst2Bacq_Gap                   (MCPARAMID)( 1181 << 14)
#define MC__SYNC_Vtotal_Check                    (MCPARAMID)( 1182 << 14)
#define MC__SYNC_Eacq2Vrst_Phase                 (MCPARAMID)( 1183 << 14)
#define MC__SYNC_Eacq2Vrst_Phase_BEFORE            1
#define MC__SYNC_Eacq2Vrst_Phase_SAME              2
#define MC__SYNC_Eacq2Vrst_Phase_AFTER             3
#define MC_ClkSynth1_OFF                           7
#define MC_ClkSynth1_TX                            8
#define MC_ClkSynth1_TY                            9
#define MC_ClkSynth1_TZ                           10
#define MC_ClkSynth2_OFF                           7
#define MC_ClkSynth2_TX                            8
#define MC_ClkSynth2_TY                            9
#define MC_ClkSynth2_TZ                           10
#define MC__PllControl                           (MCPARAMID)( 1184 << 14)
#define MC__PllControl_YES                         1
#define MC__PllControl_NO                          2
#define MC_CamConfig_P50RM_G                      30
#define MC__DigUnit1                             (MCPARAMID)( 1185 << 14)
#define MC__DigUnit2                             (MCPARAMID)( 1186 << 14)
#define MC__DigUnit3                             (MCPARAMID)( 1187 << 14)
#define MC__TimUnit                              (MCPARAMID)( 1188 << 14)
#define MC_CSTSet                                (MCPARAMID)( 1189 << 14)
#define MC_WSTSet                                (MCPARAMID)( 1190 << 14)
#define MC_PixelClkLine                          (MCPARAMID)( 1191 << 14)
#define MC_PixelClkLine_CK                         1
#define MC_ResetLine_RST                           5
#define MC_ResetLine_EXP                           6
#define MC_ResetLine_GATE                          7
#define MC_ResetLine_HIO                           8
#define MC_ResetLine_VIO                           9
#define MC_ResetLine_DUAL                         10
#define MC_AuxResetLine_RST                        5
#define MC_AuxResetLine_EXP                        6
#define MC_AuxResetLine_GATE                       7
#define MC_AuxResetLine_HIO                        8
#define MC_AuxResetLine_VIO                        9
#define MC_AuxResetLine_DUAL                      10
#define MC_VsyncLine                             (MCPARAMID)( 1192 << 14)
#define MC_VsyncLine_RST                           1
#define MC_VsyncLine_EXP                           2
#define MC_VsyncLine_GATE                          3
#define MC_VsyncLine_HIO                           4
#define MC_VsyncLine_VIO                           5
#define MC_VsyncLine_DUAL                          6
#define MC_HsyncLine                             (MCPARAMID)( 1193 << 14)
#define MC_HsyncLine_RST                           1
#define MC_HsyncLine_EXP                           2
#define MC_HsyncLine_GATE                          3
#define MC_HsyncLine_HIO                           4
#define MC_HsyncLine_VIO                           5
#define MC_HsyncLine_DUAL                          6
#define MC_CableName_UNKNOWN                       3
#define MC_CableName_Single_Channel_R              4
#define MC_CableName_Single_Channel_RC             5
#define MC_CableName_Single_Channel_RGC_2          6
#define MC_CableName_Dual_Channel                  7
#define MC_CableName_Dual_Channel_RG               8
#define MC_CableName_Dual_Channel_RG_2             9
#define MC_CableName_Triple_Channel_R             10
#define MC_ColorMethod_Filter                    (MCPARAMID)( 1194 << 14)
#define MC_GCE_Filter                            (MCPARAMID)( 1195 << 14)
#define MC__TrueExp_us                           (MCPARAMID)( 1196 << 14)
#define MC_StrobeMode                            (MCPARAMID)( 1197 << 14)
#define MC_StrobeMode_Filter                     (MCPARAMID)( 1198 << 14)
#define MC_StrobeMode_NONE                         1
#define MC_StrobeMode_AUTO                         2
#define MC_StrobeMode_MAN                          3
#define MC_SampleTrim                            (MCPARAMID)( 1199 << 14)
#define MC_DigUnit2_Filter                       (MCPARAMID)( 1200 << 14)
#define MC_DigUnit3_Filter                       (MCPARAMID)( 1201 << 14)
#define MC_SampleTrim_Filter                     (MCPARAMID)( 1202 << 14)
#define MC_Manufacturer_MY_CAMERAS                 7
#define MC___GrabberTiming_Check                 (MCPARAMID)( 1203 << 14)
#define MC___GrabberTiming_Check_PASS              1
#define MC___GrabberTiming_Check_FAIL              2
#define MC__HDC_DCNT                             (MCPARAMID)( 1204 << 14)
#define MC__HBC_HPRE                             (MCPARAMID)( 1205 << 14)
#define MC__HBC_DBFR_Expected                    (MCPARAMID)( 1206 << 14)
#define MC__HBC_DBFR                             (MCPARAMID)( 1207 << 14)
#define MC__HBC_DBFR_Check                       (MCPARAMID)( 1208 << 14)
#define MC__HBC_DBFR_Check_PASS                    1
#define MC__HBC_DBFR_Check_FAIL                    2
#define MC__HAC_DAFT                             (MCPARAMID)( 1209 << 14)
#define MC__VBC_LBFR                             (MCPARAMID)( 1210 << 14)
#define MC__VAC_LAFT                             (MCPARAMID)( 1211 << 14)
#define MC__SCC_CC1                              (MCPARAMID)( 1212 << 14)
#define MC__SCC_CC1_CTL1                           1
#define MC__SCC_CC1_CTL2                           2
#define MC__SCC_CC1_XCTL2                          3
#define MC__SCC_CC1_LOW                            4
#define MC__SCC_CC1_CTL1n                          5
#define MC__SCC_CC1_CTL2n                          6
#define MC__SCC_CC1_XCTL2n                         7
#define MC__SCC_CC1_HIGH                           8
#define MC__SCC_CC2                              (MCPARAMID)( 1213 << 14)
#define MC__SCC_CC2_CTL1                           1
#define MC__SCC_CC2_CTL2                           2
#define MC__SCC_CC2_XCTL2                          3
#define MC__SCC_CC2_LOW                            4
#define MC__SCC_CC2_CTL1n                          5
#define MC__SCC_CC2_CTL2n                          6
#define MC__SCC_CC2_XCTL2n                         7
#define MC__SCC_CC2_HIGH                           8
#define MC__SCC_CC3                              (MCPARAMID)( 1214 << 14)
#define MC__SCC_CC3_CTL1                           1
#define MC__SCC_CC3_CTL2                           2
#define MC__SCC_CC3_XCTL2                          3
#define MC__SCC_CC3_LOW                            4
#define MC__SCC_CC3_CTL1n                          5
#define MC__SCC_CC3_CTL2n                          6
#define MC__SCC_CC3_XCTL2n                         7
#define MC__SCC_CC3_HIGH                           8
#define MC__SCC_CC4                              (MCPARAMID)( 1215 << 14)
#define MC__SCC_CC4_CTL1                           1
#define MC__SCC_CC4_CTL2                           2
#define MC__SCC_CC4_XCTL2                          3
#define MC__SCC_CC4_LOW                            4
#define MC__SCC_CC4_CTL1n                          5
#define MC__SCC_CC4_CTL2n                          6
#define MC__SCC_CC4_XCTL2n                         7
#define MC__SCC_CC4_HIGH                           8
#define MC_CC1Usage                              (MCPARAMID)( 1216 << 14)
#define MC_CC1Usage_SOFT                           1
#define MC_CC1Usage_LOW                            2
#define MC_CC1Usage_HIGH                           3
#define MC_CC1Usage_RESET                          4
#define MC_CC1Usage_AUXRESET                       5
#define MC_CC1Usage_ACQPHASE                       6
#define MC_CC1Usage_ACQSEQUENCE                    7
#define MC_CCxUsage_Filter                       (MCPARAMID)( 1217 << 14)
#define MC_CC2Usage                              (MCPARAMID)( 1218 << 14)
#define MC_CC2Usage_SOFT                           1
#define MC_CC2Usage_LOW                            2
#define MC_CC2Usage_HIGH                           3
#define MC_CC2Usage_RESET                          4
#define MC_CC2Usage_AUXRESET                       5
#define MC_CC2Usage_ACQPHASE                       6
#define MC_CC2Usage_ACQSEQUENCE                    7
#define MC_CC3Usage                              (MCPARAMID)( 1219 << 14)
#define MC_CC3Usage_SOFT                           1
#define MC_CC3Usage_LOW                            2
#define MC_CC3Usage_HIGH                           3
#define MC_CC3Usage_RESET                          4
#define MC_CC3Usage_AUXRESET                       5
#define MC_CC3Usage_ACQPHASE                       6
#define MC_CC3Usage_ACQSEQUENCE                    7
#define MC_CC4Usage                              (MCPARAMID)( 1220 << 14)
#define MC_CC4Usage_SOFT                           1
#define MC_CC4Usage_LOW                            2
#define MC_CC4Usage_HIGH                           3
#define MC_CC4Usage_RESET                          4
#define MC_CC4Usage_AUXRESET                       5
#define MC_CC4Usage_ACQPHASE                       6
#define MC_CC4Usage_ACQSEQUENCE                    7
#define MC__STRB                                 (MCPARAMID)( 1221 << 14)
#define MC__CID                                  (MCPARAMID)( 1222 << 14)
#define MC__OUT1                                 (MCPARAMID)( 1223 << 14)
#define MC__OUT2                                 (MCPARAMID)( 1224 << 14)
#define MC__OUT3                                 (MCPARAMID)( 1225 << 14)
#define MC__OUT4                                 (MCPARAMID)( 1226 << 14)
#define MC__VBC_LBFR_Expected                    (MCPARAMID)( 1227 << 14)
#define MC__VBC_LBFR_Check                       (MCPARAMID)( 1228 << 14)
#define MC__VBC_LBFR_Check_PASS                    1
#define MC__VBC_LBFR_Check_FAIL                    2
#define MC__VBC_VPRE                             (MCPARAMID)( 1229 << 14)
#define MC__VLC_LCINIT                           (MCPARAMID)( 1230 << 14)
#define MC_Camera_TM_1020_15CL                    23
#define MC_Camera_TM_1320_15CL                    24
#define MC_Camera_SVS282CSCL                      25
#define MC_Camera_SVS285MFCL                      26
#define MC_Camera_SVS285MSCL                      27
#define MC_CamConfig_P15SC                        31
#define MC_CamConfig_I10SC                        32
#define MC_CamConfig_P22SC                        33
#define MC_Manufacturer_PULNIX                     8
#define MC_Manufacturer_VISTEK                     9
#define MC_ColorMethod_BAYER                       4
#define MC__DRS_CPAR                             (MCPARAMID)( 1231 << 14)
#define MC__DRS_CSAP                             (MCPARAMID)( 1232 << 14)
#define MC__DRS_CFLD                             (MCPARAMID)( 1233 << 14)
#define MC__TRG_FTPOL_SAS                        (MCPARAMID)( 1234 << 14)
#define MC__TRG_FTPOL_SAS_NONE                     1
#define MC__TRG_FTPOL_SAS_DIRECT                   2
#define MC__TRG_FTPOL_SAS_INVERT                   3
#define MC__TRG_FTPOL_SAP                        (MCPARAMID)( 1235 << 14)
#define MC__TRG_FTPOL_SAP_NONE                     1
#define MC__TRG_FTPOL_SAP_DIRECT                   2
#define MC__TRG_FTPOL_SAP_INVERT                   3
#define MC_TrigFilter_MEDIUM                       3
#define MC_TrigFilter_STRONG                       4
#define MC__TRG_FTFLT                            (MCPARAMID)( 1236 << 14)
#define MC__TRG_FTFLT_NONE                         1
#define MC__TRG_FTFLT_200ns                        2
#define MC__TRG_FTFLT_3200ns                       3
#define MC_TrigLine_CAM                            6
#define MC__TRG_FTSEL_SAS                        (MCPARAMID)( 1237 << 14)
#define MC__TRG_FTSEL_SAS_DA1                      1
#define MC__TRG_FTSEL_SAS_DA2                      2
#define MC__TRG_FTSEL_SAS_CAMSIG                   3
#define MC__TRG_FTSEL_SAS_TRG                      4
#define MC__TRG_FTSEL_SAS_FORCE                    5
#define MC__TRG_FTSEL_SAP                        (MCPARAMID)( 1238 << 14)
#define MC__TRG_FTSEL_SAP_KEEP                     1
#define MC__TRG_FTSEL_SAP_FORCE                    2
#define MC__STM1_T1CLK                           (MCPARAMID)( 1239 << 14)
#define MC__STM1_T1CLK_PRESCALER                   1
#define MC__STM1_T1CLK_LTRIGS                      2
#define MC__STM1_T1CLK_PPLS                        3
#define MC__STM1_T1SCAL                          (MCPARAMID)( 1240 << 14)
#define MC__STM1_T1SCAL_100ns                      1
#define MC__STM1_T1SCAL_1us                        2
#define MC__STM1_T1SCAL_10us                       3
#define MC__STM1_T1SCAL_100us                      4
#define MC__STM1_T1SCAL_1ms                        5
#define MC__PRM1_T1POS_CTL1On                    (MCPARAMID)( 1241 << 14)
#define MC__PRM1_T1POS_CTL1Off                   (MCPARAMID)( 1242 << 14)
#define MC__PRM1_T1POS_PulseSq                   (MCPARAMID)( 1243 << 14)
#define MC__PRM1_T1POS_PulseEnd                  (MCPARAMID)( 1244 << 14)
#define MC___Timer1_Check                        (MCPARAMID)( 1245 << 14)
#define MC___Timer1_Check_PASS                     1
#define MC___Timer1_Check_FAIL                     2
#define MC__STM1_T1SCAL_OVER                       6
#define MC_Camera_SVS084MFCL                      28
#define MC_Camera_SVS084MSCL                      29
#define MC_Camera_SVS085MFCL                      30
#define MC_Camera_SVS085MSCL                      31
#define MC_Camera_SVS204MFCL                      32
#define MC_Camera_SVS204MSCL                      33
#define MC_CamConfig_P21SC                        34
#define MC_CamConfig_P42SC                        35
#define MC_CamConfig_P13SC                        36
#define MC_CamConfig_P25SC                        37
#define MC_CamConfig_P64SC                        38
#define MC_CamConfig_P94SC                        39
#define MC__T1Span_10ns                          (MCPARAMID)( 1246 << 14)
#define MC__T1_10ns                              (MCPARAMID)( 1247 << 14)
#define MC__EXPWidth_10ns                        (MCPARAMID)( 1248 << 14)
#define MC__EXPWidth_T1                          (MCPARAMID)( 1249 << 14)
#define MC__TRG_FTSEL                            (MCPARAMID)( 1250 << 14)
#define MC__TRG_FTSEL_DA1                          6
#define MC__TRG_FTSEL_DA2                          7
#define MC__TRG_FTSEL_CAMSIG                       8
#define MC__TRG_FTSEL_TRG                          9
#define MC__TRG_FTRIG_SAS                        (MCPARAMID)( 1251 << 14)
#define MC__TRG_FTRIG_SAS_KEEP                     1
#define MC__TRG_FTRIG_SAS_FORCE                    2
#define MC__TRG_FTRIG_EAP                        (MCPARAMID)( 1252 << 14)
#define MC__TRG_FTRIG_EAP_KEEP                     1
#define MC__TRG_FTRIG_EAP_FORCE                    2
#define MC__TRG_FTPOL_EAP                        (MCPARAMID)( 1253 << 14)
#define MC__TRG_FTPOL_EAP_NONE                     1
#define MC__TRG_FTPOL_EAP_DIRECT                   2
#define MC__TRG_FTPOL_EAP_INVERT                   3
#define MC_Camera_CV_A11                          34
#define MC_CamConfig_P30SM                        40
#define MC_CamConfig_P30RM_G                      41
#define MC_Cable_A15_C11                          13
#define MC_CableName_Single_Channel_RGC           11
#define MC_EASQet                                (MCPARAMID)( 1254 << 14)
#define MC_CamConfig_P30RG                        42
#define MC_CamConfig_P50RG                        43
#define MC__STM2_T2SCAL                          (MCPARAMID)( 1255 << 14)
#define MC__STM2_T2SCAL_100ns                      1
#define MC__STM2_T2SCAL_1us                        2
#define MC__STM2_T2SCAL_10us                       3
#define MC__STM2_T2SCAL_100us                      4
#define MC__STM2_T2SCAL_1ms                        5
#define MC__STM2_T2SCAL_OVER                       6
#define MC__PRM2_T2POS_CTL2On                    (MCPARAMID)( 1256 << 14)
#define MC__PRM2_T2POS_CTL2Off                   (MCPARAMID)( 1257 << 14)
#define MC__PRM2_T2POS_PulseEnd                  (MCPARAMID)( 1258 << 14)
#define MC__T2Span_10ns                          (MCPARAMID)( 1259 << 14)
#define MC_StrobeCtl_ITTL                          3
#define MC_StrobeCtl_IOC                           4
#define MC_StrobeCtl_IOE                           5
#define MC__EXPWidth_T2                          (MCPARAMID)( 1260 << 14)
#define MC__STRWidth_T2                          (MCPARAMID)( 1261 << 14)
#define MC__STROn_T2                             (MCPARAMID)( 1262 << 14)
#define MC__STROff_T2                            (MCPARAMID)( 1263 << 14)
#define MC_Imaging_LINE                            2
#define MC_Imaging_TDI                             3
#define MC_CamConfig_P15RG                        44
#define MC_Camera_XC_HR50                         35
#define MC_CamConfig_P60SM                        45
#define MC_CamConfig_P60RM_G                      46
#define MC_CamConfig_P60RA_G                      47
#define MC_CamConfig_P22RG                        48
#define MC__ACQV_Line1_Dur                       (MCPARAMID)( 1264 << 14)
#define MC__IDLEV_Line2_Type                     (MCPARAMID)( 1265 << 14)
#define MC__IDLEV_Line2_Type_BLANK_VRSTON          1
#define MC__IDLEV_Line2_Type_BLANK_VRSTOFF         2
#define MC__IDLEV_Line2_Dur                      (MCPARAMID)( 1266 << 14)
#define MC__ACQV_Line2_Dur                       (MCPARAMID)( 1267 << 14)
#define MC__ACQV_Line3_Dur                       (MCPARAMID)( 1268 << 14)
#define MC__ACQV_Line4_Dur                       (MCPARAMID)( 1269 << 14)
#define MC__ACQV_Acq_Dur                         (MCPARAMID)( 1270 << 14)
#define MC__ACQV_PreAcq_Dur                      (MCPARAMID)( 1271 << 14)
#define MC__ACQV_Total_Dur                       (MCPARAMID)( 1272 << 14)
#define MC_Camera_CS8530                          36
#define MC_Manufacturer_TELI                      10
#define MC_CamConfig_P48RG                        49
#define MC_Camera_CS8531                          37
#define MC_Camera_CS8531D                         38
#define MC_CamConfig_P120SM                       50
#define MC_CamConfig_P120RM_G                     51
#define MC_CamConfig_P30RA_G                      52
#define MC_CamConfig_P50RM                        53
#define MC_CamConfig_P60RM                        54
#define MC_CamConfig_P120RM                       55
#define MC_CamConfig_P30RM                        56
#define MC_ColorRegistration                     (MCPARAMID)( 1273 << 14)
#define MC_ColorRegistration_GB                    1
#define MC_ColorRegistration_BG                    2
#define MC_ColorRegistration_RG                    3
#define MC_ColorRegistration_GR                    4
#define MC_ImageColorRegistration                (MCPARAMID)( 1274 << 14)
#define MC_ImageColorRegistration_GB               1
#define MC_ImageColorRegistration_BG               2
#define MC_ImageColorRegistration_RG               3
#define MC_ImageColorRegistration_GR               4
#define MC__OffsetX0                             (MCPARAMID)( 1275 << 14)
#define MC__OffsetY0                             (MCPARAMID)( 1276 << 14)
#define MC_CamConfig_P30SD                        57
#define MC_VdriveLine                            (MCPARAMID)( 1277 << 14)
#define MC_VdriveLine_RST                          1
#define MC_VdriveLine_EXP                          2
#define MC_VdriveLine_GATE                         3
#define MC_VdriveLine_HIO                          4
#define MC_VdriveLine_VIO                          5
#define MC_VdriveLine_DUAL                         6
#define MC_HdriveLine                            (MCPARAMID)( 1278 << 14)
#define MC_HdriveLine_RST                          1
#define MC_HdriveLine_EXP                          2
#define MC_HdriveLine_GATE                         3
#define MC_HdriveLine_HIO                          4
#define MC_HdriveLine_VIO                          5
#define MC_HdriveLine_DUAL                         6
#define MC__TrimmedExpose_us                     (MCPARAMID)( 1279 << 14)
#define MC_PixelClkLine_NC                         2
#define MC_ResetLine_NC                           11
#define MC_AuxResetLine_NC                        11
#define MC_VsyncLine_NC                            7
#define MC_HsyncLine_NC                            7
#define MC_VdriveLine_NC                           7
#define MC_HdriveLine_NC                           7
#define MC_Cable_A15_C12                          14
#define MC_CableName_Triple_Channel_RG            12
#define MC__CDU_CAL                              (MCPARAMID)( 1280 << 14)
#define MC_Camera_SKCm141TC                       39
#define MC_CamConfig_P10SA                        58
#define MC_CamConfig_P10SM                        59
#define MC_CamConfig_P10RM                        60
#define MC_CamConfig_P10RA                        61
#define MC_Manufacturer_IKEGAMI                   11
#define MC_CableName_Triple_Channel_RGC_3         13
#define MC__PinUsed                              (MCPARAMID)( 1281 << 14)
#define MC_Camera_SKC_141TC                       40
#define MC_Camera_CV_M50C                         41
#define MC_CamConfig_I25SA                        62
#define MC_CamConfig_P50                          63
#define MC_CamConfig_P50SD                        64
#define MC_CamConfig_P50RD                        65
#define MC_CamConfig_P10SD                        66
#define MC_CamConfig_P10RD                        67
#define MC_CamConfig_P25RG                        68
#define MC_CamConfig_P64RG                        69
#define MC_CamConfig_P42RG                        70
#define MC_CamConfig_P94RG                        71
#define MC_Camera_STC_1000                        42
#define MC_CamConfig_P60SD                        72
#define MC_Manufacturer_SENTECH                   12
#define MC__DIS_FALT                             (MCPARAMID)( 1282 << 14)
#define MC__DIS_FALT_NORMAL                        1
#define MC__DIS_FALT_ALTERNATE                     2
#define MC__DIS_SPOL                             (MCPARAMID)( 1283 << 14)
#define MC__DIS_SPOL_DIRECT                        1
#define MC__DIS_SPOL_INVERT                        2
#define MC__DIS_FPOL                             (MCPARAMID)( 1284 << 14)
#define MC__DIS_FPOL_DIRECT                        1
#define MC__DIS_FPOL_INVERT                        2
#define MC__DIS_LPOL                             (MCPARAMID)( 1285 << 14)
#define MC__DIS_LPOL_DIRECT                        1
#define MC__DIS_LPOL_INVERT                        2
#define MC__DIS_DPOL                             (MCPARAMID)( 1286 << 14)
#define MC__DIS_DPOL_DIRECT                        1
#define MC__DIS_DPOL_INVERT                        2
#define MC__DRS_CPAR_NONE                          1
#define MC__DRS_CPAR_LVAL_AFT                      2
#define MC__DRS_CPAR_LVAL_BFR                      3
#define MC__DRS_CPAR_SPARE_AFT                     4
#define MC__DRS_CPAR_SPARE_BFR                     5
#define MC__DRS_CSAP_ONNEXTFVAL                    1
#define MC__DRS_CSAP_ONNEXTFVAL_PAR0               2
#define MC__DRS_CSAP_ONNEXTFVAL_PAR1               3
#define MC__DRS_CFLD_ONEFIELD                      1
#define MC__DRS_CFLD_TWOFIELDS                     2
#define MC__DRS_CACQ                             (MCPARAMID)( 1287 << 14)
#define MC__DRS_CACQ_LINE                          1
#define MC__DRS_CACQ_LINEandVALD                   2
#define MC__DRS_CEOL                             (MCPARAMID)( 1288 << 14)
#define MC__DRS_CEOL_DLAST                         1
#define MC__DRS_CEOL_DSTOP                         2
#define MC__DRS_CEOL_LVALE                         3
#define MC__DRS_CEOL_DVALE                         4
#define MC__DRS_CSOL                             (MCPARAMID)( 1289 << 14)
#define MC__DRS_CSOL_LVALS                         1
#define MC__DRS_CSOL_FVALSorLVALE                  2
#define MC__DRS_CSOL_FVALSorDLAST                  3
#define MC_Camera_NoCamera                        43
#define MC_LvalMode_LN                             5
#define MC_Camera_TMC_1000                        44
#define MC_Camera_TMC_6700                        45
#define MC_Camera_A501k                           46
#define MC_CamConfig_P60SC                        73
#define MC_CamConfig_P60RG                        74
#define MC_CamConfig_P74SC                        75
#define MC_CamConfig_P74RG                        76
#define MC_Cable_CL_C03                           15
#define MC_CableName_Pulnix_Adapter               14
#define MC_Camera_XC_8500CE                       47
#define MC_Cable_A15_C13                          16
#define MC_CableName_Dual_Channel_RG_2_A          15
#define MC_StrobeLine_Filter                     (MCPARAMID)( 1290 << 14)
#define MC_StrobeLine_STZ                          6
#define MC__CBA_GROUP4                           (MCPARAMID)( 1291 << 14)
#define MC__STB_STB_x                            (MCPARAMID)( 1292 << 14)
#define MC__STB_STB_x_FromCTL1_x                   1
#define MC__STB_STB_x_FromCTL2_x                   2
#define MC__STB_STB_x_FromXCTL2_x                  3
#define MC__STB_Qx1SRC                           (MCPARAMID)( 1293 << 14)
#define MC__STB_Qx1SRC_LOW                         1
#define MC__STB_Qx1SRC_HIGH                        2
#define MC__STB_Qx1SRC_FromSTB_X                   3
#define MC__STB_Qx1SRC_FromSTB_X_Inverted          4
#define MC__STB_x1STYL                           (MCPARAMID)( 1294 << 14)
#define MC__STB_x1STYL_TTLIN                       1
#define MC__STB_x1STYL_12VIN                       2
#define MC__STB_x1STYL_TTLOUT                      3
#define MC__STB_x1STYL_OCOUT                       4
#define MC__STB_x1STYL_OEOUT                       5
#define MC__STB_Qx2SRC                           (MCPARAMID)( 1295 << 14)
#define MC__STB_Qx2SRC_LOW                         1
#define MC__STB_Qx2SRC_HIGH                        2
#define MC__STB_Qx2SRC_FromSTB_X                   3
#define MC__STB_Qx2SRC_FromSTB_X_Inverted          4
#define MC__STB_x2STYL                           (MCPARAMID)( 1296 << 14)
#define MC__STB_x2STYL_TTLIN                       1
#define MC__STB_x2STYL_12VIN                       2
#define MC__STB_x2STYL_TTLOUT                      3
#define MC__STB_x2STYL_OCOUT                       4
#define MC__STB_x2STYL_OEOUT                       5
#define MC__STR_STR_X                            (MCPARAMID)( 1297 << 14)
#define MC__STR_STR_X_LOW                          1
#define MC__STR_STR_X_HIGH                         2
#define MC__STR_STR_X_FromSTB_X                    3
#define MC__STR_STR_X_FromSTB_X_Inverted           4
#define MC___StrobeStyle_Check                   (MCPARAMID)( 1298 << 14)
#define MC___StrobeStyle_Check_PASS                1
#define MC___StrobeStyle_Check_FAIL                2
#define MC_STRUsage                              (MCPARAMID)( 1299 << 14)
#define MC_STRUsage_IO                             1
#define MC_STRUsage_STROBE                         2
#define MC_A1Usage                               (MCPARAMID)( 1300 << 14)
#define MC_A1Usage_IO                              1
#define MC_A1Usage_STROBE                          2
#define MC_A2Usage                               (MCPARAMID)( 1301 << 14)
#define MC_A2Usage_IO                              1
#define MC_A2Usage_STROBE                          2
#define MC_DefaultLoadSet                        (MCPARAMID)( 1302 << 14)
#define MC__TRG_FTMOD                            (MCPARAMID)( 1303 << 14)
#define MC__TRG_FTMOD_SKIP                         1
#define MC__TRG_FTMOD_HOLD                         2
#define MC__TRG_FTRES_FB                         (MCPARAMID)( 1304 << 14)
#define MC__TRG_FTRES_FB_NO                        1
#define MC__TRG_FTRES_FB_YES                       2
#define MC__TRG_FTRES_T1                         (MCPARAMID)( 1305 << 14)
#define MC__TRG_FTRES_T1_NO                        1
#define MC__TRG_FTRES_T1_YES                       2
#define MC__TRG_FTRES_T2                         (MCPARAMID)( 1306 << 14)
#define MC__TRG_FTRES_T2_NO                        1
#define MC__TRG_FTRES_T2_YES                       2
#define MC__TRG_FTPOL_TE                         (MCPARAMID)( 1307 << 14)
#define MC__TRG_FTPOL_TE_NONE                      1
#define MC__TRG_FTPOL_TE_DIRECT                    2
#define MC__TRG_FTPOL_TE_INVERT                    3
#define MC__TRG_FTRIG_TE                         (MCPARAMID)( 1308 << 14)
#define MC__TRG_FTRIG_TE_KEEP                      1
#define MC__TRG_FTRIG_TE_FORCE                     2
#define MC_Camera_STC_1100b                       48
#define MC__DRS_CSOL_FVALSorEOL                    4
#define MC_TriggerSkipHold                       (MCPARAMID)( 1309 << 14)
#define MC_TriggerSkipHold_SKIP                    1
#define MC_TriggerSkipHold_HOLD                    2
#define MC_LineScanOnly_Filter                   (MCPARAMID)( 1310 << 14)
#define MC_ExposeRecovery_us                     (MCPARAMID)( 1311 << 14)
#define MC_ReadoutRecovery_us                    (MCPARAMID)( 1312 << 14)
#define MC__EXPOffWidthForbid_10ns               (MCPARAMID)( 1313 << 14)
#define MC__EXPOffWidth_T1                       (MCPARAMID)( 1314 << 14)
#define MC__LineDur_ns                           (MCPARAMID)( 1315 << 14)
#define MC__ReadoutDur_10ns                      (MCPARAMID)( 1316 << 14)
#define MC_Cable_A15_C14                          17
#define MC_CableName_Single_Channel_RGC_A         16
#define MC__EXPOffWidth_10ns                     (MCPARAMID)( 1317 << 14)
#define MC__MaxReadoutRate_Hz                    (MCPARAMID)( 1318 << 14)
#define MC__MaxTriggerRate_Hz                    (MCPARAMID)( 1319 << 14)
#define MC_CableName_Triple_Channel_RG_3          17
#define MC___IOLoopBack                          (MCPARAMID)( 1320 << 14)
#define MC___IOLoopBack_DISABLE                    1
#define MC___IOLoopBack_ENABLE                     2
#define MC_Camera_ICD_FA41                        49
#define MC_CableName_Single_Channel_R_A           18
#define MC_Camera_SKC_131                         50
#define MC_CamConfig_P12SA                        77
#define MC_CamConfig_P12SD                        78
#define MC_CamConfig_P12RA                        79
#define MC_Operation_LONG_EXPOSURE                 7
#define MC__Vtotal_Ln                            (MCPARAMID)( 1321 << 14)
#define MC_CamConfig_P50SM_L                      80
#define MC__VLC_LCSNS                            (MCPARAMID)( 1322 << 14)
#define MC__VLC_LCSNS_NORMAL                       1
#define MC__VLC_LCSNS_SENSE                        2
#define MC__VAC_VPOST                            (MCPARAMID)( 1323 << 14)
#define MC__VAC_VPOST_FVALE_Post                   1
#define MC__VAC_VPOST_FVALE_NoPost                 2
#define MC__VAC_VPOST_LVALE_NoPost                 3
#define MC__VAC_VPOST_LLAST_NoPost                 4
#define MC__CTA_SELFLH                           (MCPARAMID)( 1324 << 14)
#define MC__CTA_SELFLH_EOI                         1
#define MC__CTA_SELFLH_EOL                         2
#define MC_Camera_CV_A50C                         51
#define MC_CamConfig_P25SM_L                      81
#define MC_Camera_iMVS157                         52
#define MC_Manufacturer_FASTCOM                   13
#define MC_CC3Usage_READOUTALLOWED                 8
#define MC_CC4Usage_TRIGGERALLOWED                 8
#define MC__SCC_CC3_ACQUIREALLOWED                 9
#define MC__SCC_CC3_ACQUIREALLOWEDn               10
#define MC__SCC_CC4_TRIGGERALLOWED                 9
#define MC__SCC_CC4_TRIGGERALLOWEDn               10
#define MC__SCC_CC3_READOUTALLOWED                11
#define MC__SCC_CC3_READOUTALLOWEDn               12
#define MC__VactiveMax_Ln                        (MCPARAMID)( 1325 << 14)
#define MC_Camera_TM_6702                         53
#define MC_Cable_A15_C15                          19
#define MC_CableName_Single_Ch                    19
#define MC_CableName_Single_Channel_R_B           20
#define MC_Camera_VCC_870                         54
#define MC_CamConfig_P12SM                        82
#define MC_CamConfig_P12RM                        83
#define MC_Manufacturer_CIS                       14
#define MC_AreaScanOnly_Filter                   (MCPARAMID)( 1326 << 14)
#define MC_TrigCtl_ITTL                            5
#define MC_TrigCtl_I12V                            6
#define MC_TrigLine_TRG                            7
#define MC_TrigLine_Filter                       (MCPARAMID)( 1327 << 14)
#define MC_ColorMethod_TRILINEAR                   5
#define MC_LineRateMode                          (MCPARAMID)( 1328 << 14)
#define MC_LineRateMode_CAMERA                     1
#define MC_LineRateMode_PERIOD                     2
#define MC_LineRateMode_PULSE                      3
#define MC_LineRateMode_CONVERT                    4
#define MC_Period_us                             (MCPARAMID)( 1329 << 14)
#define MC_PeriodTrim                            (MCPARAMID)( 1330 << 14)
#define MC_LineTrigCtl                           (MCPARAMID)( 1331 << 14)
#define MC_LineTrigCtl_ITTL                        1
#define MC_LineTrigCtl_I12V                        2
#define MC_LineTrigCtl_TTL                         3
#define MC_LineTrigEdge                          (MCPARAMID)( 1332 << 14)
#define MC_LineTrigEdge_GOHIGH                     1
#define MC_LineTrigEdge_GOLOW                      2
#define MC_LineTrigFilter                        (MCPARAMID)( 1333 << 14)
#define MC_LineTrigFilter_OFF                      1
#define MC_LineTrigFilter_MEDIUM                   2
#define MC_LineTrigFilter_STRONG                   3
#define MC_LineTrigLine                          (MCPARAMID)( 1334 << 14)
#define MC_LineTrigLine_NOM                        1
#define MC_LineTrigLine_TRG                        2
#define MC_LineTrigLine_CAM                        3
#define MC_ConverterTrim                         (MCPARAMID)( 1335 << 14)
#define MC_MaxSpeed                              (MCPARAMID)( 1336 << 14)
#define MC_MinSpeed                              (MCPARAMID)( 1337 << 14)
#define MC__TRG_FTRES_EOF                        (MCPARAMID)( 1338 << 14)
#define MC__TRG_FTRES_EOF_NO                       1
#define MC__TRG_FTRES_EOF_YES                      2
#define MC_MAN_GrabWindowY_Filter                (MCPARAMID)( 1339 << 14)
#define MC_ImageFlipX                            (MCPARAMID)( 1340 << 14)
#define MC_ImageFlipX_OFF                          1
#define MC_CS3920_AsyncLoadSet                   (MCPARAMID)( 1341 << 14)
#define MC__Expose_us                            (MCPARAMID)( 1342 << 14)
#define MC_Camera_CS3920                          55
#define MC_CamConfig_I7SA                         84
#define MC_CamConfig_I7RA                         85
#define MC_Cable_A15_C16                          21
#define MC_CableName_Single_Channel_R_C           21
#define MC__CTA_SELFLH_EOI_S                       3
#define MC_Camera_CV_M4CL                         56
#define MC_CamConfig_P24SC                        86
#define MC_CamConfig_P24RG                        87
#define MC_CamConfig_I15SA                        88
#define MC_CamConfig_I15RA                        89
#define MC__TrimmedExpose_10ns                   (MCPARAMID)( 1343 << 14)
#define MC_Camera_CV_M50E                         57
#define MC_CamConfig_P60SM_L                      90
#define MC_CamConfig_I30SA                        91
#define MC_Camera_CV_A50E                         58
#define MC_CamConfig_P30SM_L                      92
#define MC_Camera_CV_M7CL                         59
#define MC_Camera_ICD_FA41E                       60
#define MC_CamConfig_P25RA_G                      93
#define MC_CamConfig_P50RA_G                      94
#define MC_StrobeCtl_Filter                      (MCPARAMID)( 1344 << 14)
#define MC_CamConfig_I60RA                        95
#define MC_CamConfig_I120SA                       96
#define MC_CamConfig_I120RA                       97
#define MC__HDC_DCADV                            (MCPARAMID)( 1345 << 14)
#define MC__HDC_DCADV_PERMANENT                    1
#define MC__HDC_DCADV_VALD                         2
#define MC_ImageFlipX_ON                           2
#define MC_MaxLineRate_Hz                        (MCPARAMID)( 1346 << 14)
#define MC_LineRateMode_Filter                   (MCPARAMID)( 1347 << 14)
#define MC__T2Span_T2                            (MCPARAMID)( 1348 << 14)
#define MC__PRM2_T2POS_1                         (MCPARAMID)( 1349 << 14)
#define MC__PRM2_T2PLS1_1                        (MCPARAMID)( 1350 << 14)
#define MC__PRM2_T2PLS2_1                        (MCPARAMID)( 1351 << 14)
#define MC__PRM2_T2POS_2                         (MCPARAMID)( 1352 << 14)
#define MC__PRM2_T2PLS1_2                        (MCPARAMID)( 1353 << 14)
#define MC__PRM2_T2PLS2_2                        (MCPARAMID)( 1354 << 14)
#define MC__PRM2_T2POS_3                         (MCPARAMID)( 1355 << 14)
#define MC__PRM2_T2PLS1_3                        (MCPARAMID)( 1356 << 14)
#define MC__PRM2_T2PLS2_3                        (MCPARAMID)( 1357 << 14)
#define MC__PRM2_T2POS_4                         (MCPARAMID)( 1358 << 14)
#define MC__PRM2_T2PLS1_4                        (MCPARAMID)( 1359 << 14)
#define MC__PRM2_T2PLS2_4                        (MCPARAMID)( 1360 << 14)
#define MC__PRM2_T2POS_5                         (MCPARAMID)( 1361 << 14)
#define MC__PRM2_T2PLS1_5                        (MCPARAMID)( 1362 << 14)
#define MC__PRM2_T2PLS2_5                        (MCPARAMID)( 1363 << 14)
#define MC__STM2_T2SEL                           (MCPARAMID)( 1364 << 14)
#define MC__STM2_T2SEL_OFF                         1
#define MC__STM2_T2SEL_OnLTRIGS                    2
#define MC__STM2_T2SEL_OnLTRIGE                    3
#define MC__STM2_T2SEL_OnPPLS                      4
#define MC__STM2_T2SEL_OnGO1                       5
#define MC__STM2_T2SEL_OnEND2                      6
#define MC__T2_10ns                              (MCPARAMID)( 1365 << 14)
#define MC__ResetDur_T2                          (MCPARAMID)( 1366 << 14)
#define MC__ReadoutDur_T2                        (MCPARAMID)( 1367 << 14)
#define MC__ExposureController                   (MCPARAMID)( 1368 << 14)
#define MC__ExposureController_CAMERA              1
#define MC__ExposureController_GRABBER             2
#define MC__Category_Timer1_Control               19
#define MC__Category_Timer2_Control               20
#define MC__TRG_LTPOL                            (MCPARAMID)( 1369 << 14)
#define MC__TRG_LTPOL_NONE                         1
#define MC__TRG_LTPOL_DIRECT                       2
#define MC__TRG_LTPOL_INVERT                       3
#define MC__TRG_LTFLT                            (MCPARAMID)( 1370 << 14)
#define MC__TRG_LTFLT_NONE                         1
#define MC__TRG_LTFLT_200ns                        2
#define MC__TRG_LTFLT_3200ns                       3
#define MC__TRG_LTSEL                            (MCPARAMID)( 1371 << 14)
#define MC__TRG_LTSEL_DA1                          1
#define MC__TRG_LTSEL_DA2                          2
#define MC__TRG_LTSEL_CAMSIG                       3
#define MC__TRG_LTSEL_TRG                          4
#define MC_Encoder_Filter                        (MCPARAMID)( 1372 << 14)
#define MC_LineTrigCtl_Filter                    (MCPARAMID)( 1373 << 14)
#define MC_LineTrig_Filter                       (MCPARAMID)( 1374 << 14)
#define MC_Period_Filter                         (MCPARAMID)( 1375 << 14)
#define MC_Perio_Filter                          (MCPARAMID)( 1376 << 14)
#define MC_A1Usage_TRIGGER                         3
#define MC_A1Usage_LINETRIGGER                     4
#define MC_A2Usage_TRIGGER                         3
#define MC_A2Usage_LINETRIGGER                     4
#define MC__TrigLineNeeded                       (MCPARAMID)( 1377 << 14)
#define MC__TrigLineNeeded_NO                      1
#define MC__TrigLineNeeded_YES                     2
#define MC__TrigLine_NONE                          3
#define MC__TrigLine_DA1                           4
#define MC__TrigLine_DA2                           5
#define MC__TrigLine_CAMSIG                        6
#define MC__TrigLine_TRG                           7
#define MC__LineTrigLineNeeded                   (MCPARAMID)( 1378 << 14)
#define MC__LineTrigLineNeeded_NO                  1
#define MC__LineTrigLineNeeded_YES                 2
#define MC__LineTrigLine                         (MCPARAMID)( 1379 << 14)
#define MC__LineTrigLine_NONE                      3
#define MC__LineTrigLine_DA1                       4
#define MC__LineTrigLine_CAMSIG                    5
#define MC__LineTrigLine_TRG                       6
#define MC__StrobeLine                           (MCPARAMID)( 1380 << 14)
#define MC__StrobeLine_NONE                        1
#define MC__StrobeLine_QA1                         2
#define MC__StrobeLine_QA2                         3
#define MC__StrobeLine_STR                         4
#define MC__Category_System_IO                    21
#define MC_TRGUsage                              (MCPARAMID)( 1381 << 14)
#define MC_TRGUsage_IO                             1
#define MC_TRGUsage_TRIGGER                        2
#define MC_TRGUsage_LINETRIGGER                    3
#define MC_TrigCtl_Filter                        (MCPARAMID)( 1382 << 14)
#define MC__TrimmedPeriod_10ns                   (MCPARAMID)( 1383 << 14)
#define MC__PG_10ns                              (MCPARAMID)( 1384 << 14)
#define MC__TrimmedK_1000                        (MCPARAMID)( 1385 << 14)
#define MC__SP_Ideal                             (MCPARAMID)( 1386 << 14)
#define MC_GrabField                             (MCPARAMID)( 1387 << 14)
#define MC_NextGrabField                         (MCPARAMID)( 1388 << 14)
#define MC__PM_Criteria                          (MCPARAMID)( 1389 << 14)
#define MC__PM_Criteria_NORMAL                     1
#define MC__PM_Criteria_WIDERANGE                  2
#define MC__PM_Criteria_HIGHRESOLUTION             3
#define MC__K_Criteria                           (MCPARAMID)( 1390 << 14)
#define MC__K_Criteria_NORMAL                      1
#define MC__K_Criteria_FASTUPDATE                  2
#define MC__K_Criteria_HIGHRESOLUTION              3
#define MC__Nmin                                 (MCPARAMID)( 1391 << 14)
#define MC__Mmin                                 (MCPARAMID)( 1392 << 14)
#define MC__PSClockFrequency_MHz                 (MCPARAMID)( 1393 << 14)
#define MC__TrimmedPeriod_PSC                    (MCPARAMID)( 1394 << 14)
#define MC__SP_Desired                           (MCPARAMID)( 1395 << 14)
#define MC__TrimmedK_10000                       (MCPARAMID)( 1396 << 14)
#define MC__SEmin_Desired                        (MCPARAMID)( 1397 << 14)
#define MC__Keff_10000                           (MCPARAMID)( 1398 << 14)
#define MC__CPM_PMSDIV_Update                    (MCPARAMID)( 1399 << 14)
#define MC__CPG_PGCNT_Update                     (MCPARAMID)( 1400 << 14)
#define MC__Vactive_Ln                           (MCPARAMID)( 1401 << 14)
#define MC__VCsyncAft_Ln                         (MCPARAMID)( 1402 << 14)
#define MC_GrabField_FLD                           1
#define MC_GrabField_UP                            2
#define MC_GrabField_DOWN                          3
#define MC_GrabField_FRAME                         4
#define MC_GrabField_UPDW                          5
#define MC_GrabField_DWUP                          6
#define MC_GrabField_NONE                          7
#define MC_NextGrabField_FLD                       1
#define MC_NextGrabField_UP                        2
#define MC_NextGrabField_DOWN                      3
#define MC_NextGrabField_FRAME                     4
#define MC_NextGrabField_UPDW                      5
#define MC_NextGrabField_DWUP                      6
#define MC_NextGrabField_KEEP                      7
#define MC_NextGrabField_SAME                      8
#define MC_NextGrabField_CHANGE                    9
#define MC_INTLoadSet                            (MCPARAMID)( 1403 << 14)
#define MC_MaxSpeed_Max                          (MCPARAMID)( 1404 << 14)
#define MC_MaxSpeed_Min                          (MCPARAMID)( 1405 << 14)
#define MC__RateConverterControl                 (MCPARAMID)( 1406 << 14)
#define MC__RateConverterControl_STANDARD          1
#define MC__RateConverterControl_EXTENDED          2
#define MC___Encoder_Check                       (MCPARAMID)( 1407 << 14)
#define MC___Encoder_Check_PASS                    1
#define MC___Encoder_Check_FAIL                    2
#define MC__CPG_PGSCAL_Key                       (MCPARAMID)( 1408 << 14)
#define MC__CPG_PGSCAL_Key_Top_Check             (MCPARAMID)( 1409 << 14)
#define MC__CPG_PGSCAL_Key_Top_Check_PASS          1
#define MC__CPG_PGSCAL_Key_Top_Check_FAIL          2
#define MC__CPM_PMISCAL_Key                      (MCPARAMID)( 1410 << 14)
#define MC__CPM_PMISCAL_Key_Top_Check            (MCPARAMID)( 1411 << 14)
#define MC__CPM_PMISCAL_Key_Top_Check_PASS         1
#define MC__CPM_PMISCAL_Key_Top_Check_FAIL         2
#define MC__CPM_PMSDIV_Top_Check                 (MCPARAMID)( 1412 << 14)
#define MC__CPM_PMSDIV_Top_Check_PASS              1
#define MC__CPM_PMSDIV_Top_Check_FAIL              2
#define MC__CPG_PGMOD                            (MCPARAMID)( 1413 << 14)
#define MC__CPG_PGMOD_OFF                          1
#define MC__CPG_PGMOD_FREE_RUN                     2
#define MC__CPG_PGMOD_PM_CONTROLLED                3
#define MC__CPM_PMISCAL                          (MCPARAMID)( 1414 << 14)
#define MC__CPM_PMSDIV                           (MCPARAMID)( 1415 << 14)
#define MC__CPG_PGCNT                            (MCPARAMID)( 1416 << 14)
#define MC__CPG_PGSCAL                           (MCPARAMID)( 1417 << 14)
#define MC__TrimmedK_10000_MAX                   (MCPARAMID)( 1418 << 14)
#define MC__TrimmedK_10000_MIN                   (MCPARAMID)( 1419 << 14)
#define MC__TrimmedKeff_10000                    (MCPARAMID)( 1420 << 14)
#define MC_MaxSpeedEffective                     (MCPARAMID)( 1421 << 14)
#define MC_MaxSpeed_Check_Key                    (MCPARAMID)( 1422 << 14)
#define MC_MaxSpeed_Check                        (MCPARAMID)( 1423 << 14)
#define MC_MaxSpeed_Check_PASS                     1
#define MC_MaxSpeed_Check_FAIL                     2
#define MC__TrimmedK_Check_Key                   (MCPARAMID)( 1424 << 14)
#define MC__TrimmedK_Check                       (MCPARAMID)( 1425 << 14)
#define MC__TrimmedK_Check_PASS                    1
#define MC__TrimmedK_Check_FAIL                    2
#define MC__SE_Factor_Key                        (MCPARAMID)( 1426 << 14)
#define MC__SE_Factor_Key_Top_Check              (MCPARAMID)( 1427 << 14)
#define MC__SE_Factor_Key_Top_Check_PASS           1
#define MC__SE_Factor_Key_Top_Check_FAIL           2
#define MC__SE_Factor                            (MCPARAMID)( 1428 << 14)
#define MC__M_Ratio                              (MCPARAMID)( 1429 << 14)
#define MC__M_Ratio_Top_Check                    (MCPARAMID)( 1430 << 14)
#define MC__M_Ratio_Top_Check_PASS                 1
#define MC__M_Ratio_Top_Check_FAIL                 2
#define MC__SP_Factor_Key                        (MCPARAMID)( 1431 << 14)
#define MC__SP_Factor_Key_Top_Check              (MCPARAMID)( 1432 << 14)
#define MC__SP_Factor_Key_Top_Check_PASS           1
#define MC__SP_Factor_Key_Top_Check_FAIL           2
#define MC__SP_Factor                            (MCPARAMID)( 1433 << 14)
#define MC_NextTrigMode_Filter                   (MCPARAMID)( 1434 << 14)
#define MC_MinSpeed_Check                        (MCPARAMID)( 1435 << 14)
#define MC_MinSpeed_Check_PASS                     1
#define MC_MinSpeed_Check_FAIL                     2
#define MC___Encoder_Warning_Check               (MCPARAMID)( 1436 << 14)
#define MC___Encoder_Warning_Check_PASS            1
#define MC___Encoder_Warning_Check_FAIL            2
#define MC__EncoderMaxSpeed                      (MCPARAMID)( 1437 << 14)
#define MC__EncoderMaxSpeed_Check                (MCPARAMID)( 1438 << 14)
#define MC__EncoderMaxSpeed_Check_PASS             1
#define MC__EncoderMaxSpeed_Check_FAIL             2
#define MC__EncoderMinSpeed                      (MCPARAMID)( 1439 << 14)
#define MC__EncoderMinSpeed_Check                (MCPARAMID)( 1440 << 14)
#define MC__EncoderMinSpeed_Check_PASS             1
#define MC__EncoderMinSpeed_Check_FAIL             2
#define MC_X_VRSTMID                             (MCPARAMID)( 1441 << 14)
#define MC__SYNC_Line1_Type_BLANK_VRSTMID          3
#define MC__SYNC_Line4_Type_ACQ_VRSTMID            3
#define MC__SYNC_Line5_Type_BLANK_VRSTMID          3
#define MC__SYNC_Line6_Type                      (MCPARAMID)( 1442 << 14)
#define MC__SYNC_Line6_Type_BLANK_VRSTOFF          1
#define MC__SYNC_Line6_Type_BLANK_VRSTON           2
#define MC__SYNC_Line6_Type_BLANK_VRSTMID          3
#define MC__SYNC_Line6_Dur                       (MCPARAMID)( 1443 << 14)
#define MC__SYNC_Line7_Type                      (MCPARAMID)( 1444 << 14)
#define MC__SYNC_Line7_Type_BLANK_VRSTOFF          1
#define MC__SYNC_Line7_Dur                       (MCPARAMID)( 1445 << 14)
#define MC__SYNC_Line8_Type                      (MCPARAMID)( 1446 << 14)
#define MC__SYNC_Line8_Type_ACQ_VRSTOFF            1
#define MC__SYNC_Line8_Type_ACQ_VRSTON             2
#define MC__SYNC_Line8_Type_ACQ_VRSTMID            3
#define MC__SYNC_Line8_Dur                       (MCPARAMID)( 1447 << 14)
#define MC__SYNC_Line9_Type                      (MCPARAMID)( 1448 << 14)
#define MC__SYNC_Line9_Type_BLANK_VRSTOFF          1
#define MC__SYNC_Line9_Type_BLANK_VRSTON           2
#define MC__SYNC_Line9_Type_BLANK_VRSTMID          3
#define MC__SYNC_Line9_Dur                       (MCPARAMID)( 1449 << 14)
#define MC__MID_Eacq2Vrst_Gap                    (MCPARAMID)( 1450 << 14)
#define MC__MID_Vrst2Bacq_Gap                    (MCPARAMID)( 1451 << 14)
#define MC__SYNC_Line10_Type                     (MCPARAMID)( 1452 << 14)
#define MC__SYNC_Line10_Type_ACQ_VRSTOFF           1
#define MC__SYNC_Line10_Dur                      (MCPARAMID)( 1453 << 14)
#define MC_MATLoadSet                            (MCPARAMID)( 1454 << 14)
#define MC__K_SP                                 (MCPARAMID)( 1455 << 14)
#define MC__M_SP                                 (MCPARAMID)( 1456 << 14)
#define MC__M_SP_10                              (MCPARAMID)( 1457 << 14)
#define MC__TrimmedK_16384                       (MCPARAMID)( 1458 << 14)
#define MC__K_SP_16384                           (MCPARAMID)( 1459 << 14)
#define MC__TrimmedK_131072                      (MCPARAMID)( 1460 << 14)
#define MC_VCSYNC1                               (MCPARAMID)( 1461 << 14)
#define MC_VCSYNC2                               (MCPARAMID)( 1462 << 14)
#define MC_BACK1                                 (MCPARAMID)( 1463 << 14)
#define MC_BACK2                                 (MCPARAMID)( 1464 << 14)
#define MC__VdriveDur_Ln                         (MCPARAMID)( 1465 << 14)
#define MC__VdriveDly_Ln                         (MCPARAMID)( 1466 << 14)
#define MC__L_16384                              (MCPARAMID)( 1467 << 14)
#define MC__INT_Eacq2Vrst_Gap                    (MCPARAMID)( 1468 << 14)
#define MC__INT_Vrst2Bacq_Gap                    (MCPARAMID)( 1469 << 14)
#define MC__SYNC_Line4_Type_BLANK_VRSTMID          4
#define MC__INITD1_SELV1                         (MCPARAMID)( 1470 << 14)
#define MC__INT_BEFORE                           (MCPARAMID)( 1471 << 14)
#define MC__INT_CHOIX                            (MCPARAMID)( 1472 << 14)
#define MC__Equalization                         (MCPARAMID)( 1473 << 14)
#define MC_TrigFilter_Filter                     (MCPARAMID)( 1474 << 14)
#define MC__TRG_FTFLT_100ns                        4
#define MC__TRG_FTFLT_500ns                        5
#define MC__TRG_FTFLT_2500ns                       6
#define MC_LineTrigFilter_Filter                 (MCPARAMID)( 1475 << 14)
#define MC__TRG_LTFLT_100ns                        4
#define MC__TRG_LTFLT_500ns                        5
#define MC__TRG_LTFLT_2500ns                       6
#define MC__STM1_T1CLK_EOL                         4
#define MC__EquaCCIR                             (MCPARAMID)( 1476 << 14)
#define MC_PageModeOnly_Filter                   (MCPARAMID)( 1477 << 14)
#define MC_AllButWebMode_Filter                  (MCPARAMID)( 1478 << 14)
#define MC__IndexField                           (MCPARAMID)( 1479 << 14)
#define MC_Camera_LD3521PGx                       61
#define MC_Camera_LD3522PGx                       62
#define MC_Camera_LD3523PGx                       63
#define MC_Camera_LD3541PGx                       64
#define MC_Camera_LD3542PGx                       65
#define MC_Camera_LD3543PGx                       66
#define MC_Camera_L101k                           67
#define MC_Camera_L103k                           68
#define MC_Camera_L104k                           69
#define MC_Camera_A301bc                          70
#define MC_CamConfig_L512SP                       98
#define MC_CamConfig_L1024SP                      99
#define MC_CamConfig_L2048SP                     100
#define MC_CamConfig_L1024RC                     101
#define MC_CamConfig_L1024RG                     102
#define MC_CamConfig_L2048RG                     103
#define MC_CamConfig_L2048RC                     104
#define MC_CamConfig_P80SC                       105
#define MC_CamConfig_P80RG                       106
#define MC_Manufacturer_PERKINELMER               15
#define MC_Camera_L301bc                          71
#define MC_CamConfig_L2098SP                     107
#define MC_CamConfig_L2098RC                     108
#define MC_CamConfig_L2098RG                     109
#define MC_Camera_L401k                           72
#define MC_Camera_L402k                           73
#define MC_Camera_L403k                           74
#define MC_CamConfig_L4096SP                     110
#define MC_CamConfig_L4096RC                     111
#define MC_CamConfig_L4096RG                     112
#define MC_Camera_P2_2x_06k40                     75
#define MC_Camera_P2_2x_08k40                     76
#define MC_CamConfig_L6144SP                     113
#define MC_CamConfig_L6144RC                     114
#define MC_CamConfig_L6144RG                     115
#define MC_CamConfig_L8192SP                     116
#define MC_CamConfig_L8192RC                     117
#define MC_CamConfig_L8192RG                     118
#define MC_Manufacturer_DALSA                     16
#define MC_CamConfig_L512RG                      119
#define MC_Camera_AVIIVA                          77
#define MC_CamConfig_L512RC                      120
#define MC_Manufacturer_ATMEL                     17
#define MC_Camera_P2_2x_01k40                     78
#define MC_Camera_P2_2x_02k40                     79
#define MC_Camera_P2_2x_04k40                     80
#define MC_Camera_AVIIVA0514                      81
#define MC_Camera_AVIIVA1014                      82
#define MC_Camera_AVIIVA2014                      83
#define MC_Camera_AVIIVA4010                      84
#define MC_ChannelTopology_DUALXMID               10
#define MC_FvalMode_LA                             5
#define MC_LvalMode_DG                             6
#define MC__DIS_LALT                             (MCPARAMID)( 1480 << 14)
#define MC__DIS_LALT_NORMAL                        1
#define MC__DIS_LALT_ALTERNATE                     2
#define MC__DIS_DALT                             (MCPARAMID)( 1481 << 14)
#define MC__DIS_DALT_NORMAL                        1
#define MC__DIS_DALT_ALTERNATE                     2
#define MC_Camera_TI_324A                         85
#define MC_CamConfig_I60SM                       121
#define MC_Manufacturer_NEC                       18
#define MC_CamConfig_P400SM                      122
#define MC_Camera_CV_A1                           86
#define MC_CamConfig_P16SA                       123
#define MC_CamConfig_P16RA                       124
#define MC_CamConfig_P16RA_G                     125
#define MC_CamConfig_P16SM                       126
#define MC_CamConfig_P16RM                       127
#define MC_CamConfig_P16RM_G                     128
#define MC_CamConfig_P16SD                       129
#define MC_CamConfig_P16RD                       130
#define MC_CamConfig_P16RD_G                     131
#define MC_Camera_CV_M77                          87
#define MC_Cable_A15_C17                          22
#define MC_CableName_Triple_Channel_RG_2          22
#define MC_CamConfig_P10RG                       132
#define MC_CamConfig_P10RC                       133
#define MC__CDC_ISIZE_8BIT                         9
#define MC__CDC_ISIZE_10BIT                       10
#define MC__CDC_ISIZE_12BIT                       11
#define MC__CDC_ISIZE_14BIT                       12
#define MC__CDC_ISIZE_16BIT                       13
#define MC__CDC_CLCFG                            (MCPARAMID)( 1482 << 14)
#define MC__CDC_CLCFG_BASE                         1
#define MC__CDC_CLCFG_MEDIUM                       2
#define MC__CDC_MTAP                             (MCPARAMID)( 1483 << 14)
#define MC__CDC_MTAP_ONETAP                        1
#define MC__CDC_MTAP_TWOTAPS                       2
#define MC__CDC_FSLIC                            (MCPARAMID)( 1484 << 14)
#define MC__CBA_DCEN1                            (MCPARAMID)( 1485 << 14)
#define MC__CBA_DCEN1_ENABLED                      1
#define MC__CBA_DCEN1_DISABLED                     2
#define MC__CBA_DCEN2                            (MCPARAMID)( 1486 << 14)
#define MC__CBA_DCEN2_ENABLED                      1
#define MC__CBA_DCEN2_DISABLED                     2
#define MC__CBA_DCEN3                            (MCPARAMID)( 1487 << 14)
#define MC__CBA_DCEN3_ENABLED                      1
#define MC__CBA_DCEN3_DISABLED                     2
#define MC__CDC_FSLIC_ONE256                       1
#define MC__CDC_FSLIC_TWO128                       2
#define MC__CDC_FSLIC_FOUR64                       3
#define MC__CDC_FSLIC_EIGHT32                      4
#define MC_TapStructure_TRIPLE_W2                 16
#define MC__W1_INDEX                             (MCPARAMID)( 1488 << 14)
#define MC__W2_INDEX                             (MCPARAMID)( 1489 << 14)
#define MC__W3_INDEX                             (MCPARAMID)( 1490 << 14)
#define MC__W4_INDEX                             (MCPARAMID)( 1491 << 14)
#define MC__GCL_CLCFG                            (MCPARAMID)( 1492 << 14)
#define MC__GCL_CLCFG_BASE                         1
#define MC__GCL_CLCFG_MEDIUM                       2
#define MC__AllAssyMask                          (MCPARAMID)( 1493 << 14)
#define MC__UsedAssyMask                         (MCPARAMID)( 1494 << 14)
#define MC_TrigLine_TRX                            8
#define MC_TrigLine_TRY                            9
#define MC_TrigLine_TRZ                           10
#define MC__StrobeLine_QB1                         5
#define MC__StrobeLine_QB2                         6
#define MC__StrobeLine_STX                         7
#define MC__StrobeLine_STY                         8
#define MC__StrobeLine_STZ                         9
#define MC_LineTrigLine_TRX                        4
#define MC_LineTrigLine_TRY                        5
#define MC_LineTrigLine_TRZ                        6
#define MC__LineTrigLine_DB1                       7
#define MC__LineTrigLine_TRX                       8
#define MC__LineTrigLine_TRY                       9
#define MC__LineTrigLine_TRZ                      10
#define MC__TRG_LTSEL_DB1                          5
#define MC__TRG_LTSEL_TRX                          6
#define MC__TRG_LTSEL_TRY                          7
#define MC__TRG_LTSEL_TRZ                          8
#define MC_TRXUsage                              (MCPARAMID)( 1495 << 14)
#define MC_TRXUsage_IO                             1
#define MC_TRXUsage_TRIGGER                        2
#define MC_TRXUsage_LINETRIGGER                    3
#define MC_TRYUsage                              (MCPARAMID)( 1496 << 14)
#define MC_TRYUsage_IO                             1
#define MC_TRYUsage_TRIGGER                        2
#define MC_TRYUsage_LINETRIGGER                    3
#define MC_TRZUsage                              (MCPARAMID)( 1497 << 14)
#define MC_TRZUsage_IO                             1
#define MC_TRZUsage_TRIGGER                        2
#define MC_TRZUsage_LINETRIGGER                    3
#define MC_STXUsage                              (MCPARAMID)( 1498 << 14)
#define MC_STXUsage_IO                             1
#define MC_STXUsage_STROBEX                        2
#define MC_STXUsage_STROBEY                        3
#define MC_STYUsage                              (MCPARAMID)( 1499 << 14)
#define MC_STYUsage_IO                             1
#define MC_STYUsage_STROBEX                        2
#define MC_STYUsage_STROBEY                        3
#define MC_STZUsage                              (MCPARAMID)( 1500 << 14)
#define MC_STZUsage_IO                             1
#define MC_STZUsage_STROBEX                        2
#define MC_STZUsage_STROBEY                        3
#define MC_B1Usage                               (MCPARAMID)( 1501 << 14)
#define MC_B1Usage_IO                              1
#define MC_B1Usage_STROBE                          2
#define MC_B2Usage                               (MCPARAMID)( 1502 << 14)
#define MC_B2Usage_IO                              1
#define MC_B2Usage_STROBE                          2
#define MC__STR_STR_X_FromSTB_Y                    5
#define MC__STR_STR_X_FromSTB_Y_Inverted           6
#define MC__STR_STR_Y                            (MCPARAMID)( 1503 << 14)
#define MC__STR_STR_Y_LOW                          1
#define MC__STR_STR_Y_HIGH                         2
#define MC__STR_STR_Y_FromSTB_X                    3
#define MC__STR_STR_Y_FromSTB_X_Inverted           4
#define MC__STR_STR_Y_FromSTB_Y                    5
#define MC__STR_STR_Y_FromSTB_Y_Inverted           6
#define MC__STR_STR_Z                            (MCPARAMID)( 1504 << 14)
#define MC__STR_STR_Z_LOW                          1
#define MC__STR_STR_Z_HIGH                         2
#define MC__STR_STR_Z_FromSTB_X                    3
#define MC__STR_STR_Z_FromSTB_X_Inverted           4
#define MC__STR_STR_Z_FromSTB_Y                    5
#define MC__STR_STR_Z_FromSTB_Y_Inverted           6
#define MC__TrigLine_CAMSIGA                       8
#define MC__TrigLine_DB1                           9
#define MC__TrigLine_DB2                          10
#define MC__TrigLine_CAMSIGB                      11
#define MC__TrigLine_TRGX                         12
#define MC__TrigLine_TRGY                         13
#define MC__TrigLine_TRGZ                         14
#define MC__TrigLine_TRX                          15
#define MC__TrigLine_TRY                          16
#define MC__TrigLine_TRZ                          17
#define MC__TRG_FTSEL_D1                          10
#define MC__TRG_FTSEL_D2                          11
#define MC__TRG_FTSEL_TRX                         12
#define MC__TRG_FTSEL_TRY                         13
#define MC__TRG_FTSEL_TRZ                         14
#define MC__LineTrigLine_CAMSIGA                  11
#define MC__LineTrigLine_CAMSIGB                  12
#define MC__TRG_LTSEL_D1                           9
#define MC__TRG_LTSEL_D2                          10
#define MC__CWR_SFA01                            (MCPARAMID)( 1505 << 14)
#define MC__CWR_SFA11                            (MCPARAMID)( 1506 << 14)
#define MC__CWR_SFA02                            (MCPARAMID)( 1507 << 14)
#define MC__CWR_SFA12                            (MCPARAMID)( 1508 << 14)
#define MC__CWR_SFA03                            (MCPARAMID)( 1509 << 14)
#define MC__CWR_SFA13                            (MCPARAMID)( 1510 << 14)
#define MC__CWR_SFA04                            (MCPARAMID)( 1511 << 14)
#define MC__CWR_SFA14                            (MCPARAMID)( 1512 << 14)
#define MC__STARTU4_mw                           (MCPARAMID)( 1513 << 14)
#define MC__STARTD4_mw                           (MCPARAMID)( 1514 << 14)
#define MC__DirX4                                (MCPARAMID)( 1515 << 14)
#define MC__DirY4                                (MCPARAMID)( 1516 << 14)
#define MC__CTA_STEPX4                           (MCPARAMID)( 1517 << 14)
#define MC__CTA_STEPY4                           (MCPARAMID)( 1518 << 14)
#define MC__CWR_WXP1                             (MCPARAMID)( 1519 << 14)
#define MC__CWR_WXP2                             (MCPARAMID)( 1520 << 14)
#define MC__CWR_WXP3                             (MCPARAMID)( 1521 << 14)
#define MC__CWR_WXP4                             (MCPARAMID)( 1522 << 14)
#define MC__CWR_NLA01                            (MCPARAMID)( 1523 << 14)
#define MC__CWR_NLA11                            (MCPARAMID)( 1524 << 14)
#define MC__CWR_NLA02                            (MCPARAMID)( 1525 << 14)
#define MC__CWR_NLA12                            (MCPARAMID)( 1526 << 14)
#define MC__CWR_NLA03                            (MCPARAMID)( 1527 << 14)
#define MC__CWR_NLA13                            (MCPARAMID)( 1528 << 14)
#define MC__CWR_NLA04                            (MCPARAMID)( 1529 << 14)
#define MC__CWR_NLA14                            (MCPARAMID)( 1530 << 14)
#define MC__CWR_NPA01                            (MCPARAMID)( 1531 << 14)
#define MC__CWR_NPA11                            (MCPARAMID)( 1532 << 14)
#define MC__CWR_NPA02                            (MCPARAMID)( 1533 << 14)
#define MC__CWR_NPA12                            (MCPARAMID)( 1534 << 14)
#define MC__CWR_NPA03                            (MCPARAMID)( 1535 << 14)
#define MC__CWR_NPA13                            (MCPARAMID)( 1536 << 14)
#define MC__CWR_NPA04                            (MCPARAMID)( 1537 << 14)
#define MC__CWR_NPA14                            (MCPARAMID)( 1538 << 14)
#define MC__CWR_WYP1                             (MCPARAMID)( 1539 << 14)
#define MC__CWR_WYP2                             (MCPARAMID)( 1540 << 14)
#define MC__CWR_WYP3                             (MCPARAMID)( 1541 << 14)
#define MC__CWR_WYP4                             (MCPARAMID)( 1542 << 14)
#define MC__PITCH4_mw                            (MCPARAMID)( 1543 << 14)
#define MC_Connector_M                             8
#define MC_Connector_A                             9
#define MC_Connector_B                            10
#define MC_ConnectLoc_BOTH                         4
#define MC___Connector_Check                     (MCPARAMID)( 1544 << 14)
#define MC___Connector_Check_PASS                  1
#define MC___Connector_Check_FAIL                  2
#define MC__CDC_TPG                              (MCPARAMID)( 1545 << 14)
#define MC__CDC_TPG_ENABLE                         1
#define MC__CDC_TPG_DISABLE                        2
#define MC__ASSYE11                              (MCPARAMID)( 1546 << 14)
#define MC__ASSYE12                              (MCPARAMID)( 1547 << 14)
#define MC__ASSYE13                              (MCPARAMID)( 1548 << 14)
#define MC__ASSYE14                              (MCPARAMID)( 1549 << 14)
#define MC__ASSYE15                              (MCPARAMID)( 1550 << 14)
#define MC__ASSYE16                              (MCPARAMID)( 1551 << 14)
#define MC__ASSYE17                              (MCPARAMID)( 1552 << 14)
#define MC__ASSYE18                              (MCPARAMID)( 1553 << 14)
#define MC__ASSYE21                              (MCPARAMID)( 1554 << 14)
#define MC__ASSYE22                              (MCPARAMID)( 1555 << 14)
#define MC__ASSYE23                              (MCPARAMID)( 1556 << 14)
#define MC__ASSYE24                              (MCPARAMID)( 1557 << 14)
#define MC__ASSYE25                              (MCPARAMID)( 1558 << 14)
#define MC__ASSYE26                              (MCPARAMID)( 1559 << 14)
#define MC__ASSYE27                              (MCPARAMID)( 1560 << 14)
#define MC__ASSYE28                              (MCPARAMID)( 1561 << 14)
#define MC__ASSYE31                              (MCPARAMID)( 1562 << 14)
#define MC__ASSYE32                              (MCPARAMID)( 1563 << 14)
#define MC__ASSYE33                              (MCPARAMID)( 1564 << 14)
#define MC__ASSYE34                              (MCPARAMID)( 1565 << 14)
#define MC__ASSYE35                              (MCPARAMID)( 1566 << 14)
#define MC__ASSYE36                              (MCPARAMID)( 1567 << 14)
#define MC__ASSYE37                              (MCPARAMID)( 1568 << 14)
#define MC__ASSYE38                              (MCPARAMID)( 1569 << 14)
#define MC__ASSYE41                              (MCPARAMID)( 1570 << 14)
#define MC__ASSYE42                              (MCPARAMID)( 1571 << 14)
#define MC__ASSYE43                              (MCPARAMID)( 1572 << 14)
#define MC__ASSYE44                              (MCPARAMID)( 1573 << 14)
#define MC__ASSYE45                              (MCPARAMID)( 1574 << 14)
#define MC__ASSYE46                              (MCPARAMID)( 1575 << 14)
#define MC__ASSYE47                              (MCPARAMID)( 1576 << 14)
#define MC__ASSYE48                              (MCPARAMID)( 1577 << 14)
#define MC__ASSY41                               (MCPARAMID)( 1578 << 14)
#define MC__ASSY42                               (MCPARAMID)( 1579 << 14)
#define MC__ASSY43                               (MCPARAMID)( 1580 << 14)
#define MC__ASSY44                               (MCPARAMID)( 1581 << 14)
#define MC__ASSYE51                              (MCPARAMID)( 1582 << 14)
#define MC__ASSYE52                              (MCPARAMID)( 1583 << 14)
#define MC__ASSYE53                              (MCPARAMID)( 1584 << 14)
#define MC__ASSYE54                              (MCPARAMID)( 1585 << 14)
#define MC__ASSYE55                              (MCPARAMID)( 1586 << 14)
#define MC__ASSYE56                              (MCPARAMID)( 1587 << 14)
#define MC__ASSYE57                              (MCPARAMID)( 1588 << 14)
#define MC__ASSYE58                              (MCPARAMID)( 1589 << 14)
#define MC__ASSYE61                              (MCPARAMID)( 1590 << 14)
#define MC__ASSYE62                              (MCPARAMID)( 1591 << 14)
#define MC__ASSYE63                              (MCPARAMID)( 1592 << 14)
#define MC__ASSYE64                              (MCPARAMID)( 1593 << 14)
#define MC__ASSYE65                              (MCPARAMID)( 1594 << 14)
#define MC__ASSYE66                              (MCPARAMID)( 1595 << 14)
#define MC__ASSYE67                              (MCPARAMID)( 1596 << 14)
#define MC__ASSYE68                              (MCPARAMID)( 1597 << 14)
#define MC__ASSYE71                              (MCPARAMID)( 1598 << 14)
#define MC__ASSYE72                              (MCPARAMID)( 1599 << 14)
#define MC__ASSYE73                              (MCPARAMID)( 1600 << 14)
#define MC__ASSYE74                              (MCPARAMID)( 1601 << 14)
#define MC__ASSYE75                              (MCPARAMID)( 1602 << 14)
#define MC__ASSYE76                              (MCPARAMID)( 1603 << 14)
#define MC__ASSYE77                              (MCPARAMID)( 1604 << 14)
#define MC__ASSYE78                              (MCPARAMID)( 1605 << 14)
#define MC__ASSYE81                              (MCPARAMID)( 1606 << 14)
#define MC__ASSYE82                              (MCPARAMID)( 1607 << 14)
#define MC__ASSYE83                              (MCPARAMID)( 1608 << 14)
#define MC__ASSYE84                              (MCPARAMID)( 1609 << 14)
#define MC__ASSYE85                              (MCPARAMID)( 1610 << 14)
#define MC__ASSYE86                              (MCPARAMID)( 1611 << 14)
#define MC__ASSYE87                              (MCPARAMID)( 1612 << 14)
#define MC__ASSYE88                              (MCPARAMID)( 1613 << 14)
#define MC__AllMyAssyMask                        (MCPARAMID)( 1614 << 14)
#define MC__c_INDEX                              (MCPARAMID)( 1615 << 14)
#define MC__D5_INDEX                             (MCPARAMID)( 1616 << 14)
#define MC__D6_INDEX                             (MCPARAMID)( 1617 << 14)
#define MC__D7_INDEX                             (MCPARAMID)( 1618 << 14)
#define MC__D8_INDEX                             (MCPARAMID)( 1619 << 14)
#define MC__W5_INDEX                             (MCPARAMID)( 1620 << 14)
#define MC__W6_INDEX                             (MCPARAMID)( 1621 << 14)
#define MC__W7_INDEX                             (MCPARAMID)( 1622 << 14)
#define MC__W8_INDEX                             (MCPARAMID)( 1623 << 14)
#define MC__CWR_SFA05                            (MCPARAMID)( 1624 << 14)
#define MC__CWR_SFA06                            (MCPARAMID)( 1625 << 14)
#define MC__CWR_SFA07                            (MCPARAMID)( 1626 << 14)
#define MC__CWR_SFA08                            (MCPARAMID)( 1627 << 14)
#define MC__CWR_NLA05                            (MCPARAMID)( 1628 << 14)
#define MC__CWR_NLA06                            (MCPARAMID)( 1629 << 14)
#define MC__CWR_NLA07                            (MCPARAMID)( 1630 << 14)
#define MC__CWR_NLA08                            (MCPARAMID)( 1631 << 14)
#define MC__CWR_WYP5                             (MCPARAMID)( 1632 << 14)
#define MC__CWR_WYP6                             (MCPARAMID)( 1633 << 14)
#define MC__CWR_WYP7                             (MCPARAMID)( 1634 << 14)
#define MC__CWR_WYP8                             (MCPARAMID)( 1635 << 14)
#define MC__PITCH5_mw                            (MCPARAMID)( 1636 << 14)
#define MC__PITCH6_mw                            (MCPARAMID)( 1637 << 14)
#define MC__PITCH7_mw                            (MCPARAMID)( 1638 << 14)
#define MC__PITCH8_mw                            (MCPARAMID)( 1639 << 14)
#define MC__STARTU5_mw                           (MCPARAMID)( 1640 << 14)
#define MC__STARTU6_mw                           (MCPARAMID)( 1641 << 14)
#define MC__STARTU7_mw                           (MCPARAMID)( 1642 << 14)
#define MC__STARTU8_mw                           (MCPARAMID)( 1643 << 14)
#define MC__DirX5                                (MCPARAMID)( 1644 << 14)
#define MC__DirX6                                (MCPARAMID)( 1645 << 14)
#define MC__DirX7                                (MCPARAMID)( 1646 << 14)
#define MC__DirX8                                (MCPARAMID)( 1647 << 14)
#define MC__DirY5                                (MCPARAMID)( 1648 << 14)
#define MC__DirY6                                (MCPARAMID)( 1649 << 14)
#define MC__DirY7                                (MCPARAMID)( 1650 << 14)
#define MC__DirY8                                (MCPARAMID)( 1651 << 14)
#define MC__CWR_NPA05                            (MCPARAMID)( 1652 << 14)
#define MC__CWR_NPA06                            (MCPARAMID)( 1653 << 14)
#define MC__CWR_NPA07                            (MCPARAMID)( 1654 << 14)
#define MC__CWR_NPA08                            (MCPARAMID)( 1655 << 14)
#define MC__CWR_WXP5                             (MCPARAMID)( 1656 << 14)
#define MC__CWR_WXP6                             (MCPARAMID)( 1657 << 14)
#define MC__CWR_WXP7                             (MCPARAMID)( 1658 << 14)
#define MC__CWR_WXP8                             (MCPARAMID)( 1659 << 14)
#define MC__CBA_PSHIFT5                          (MCPARAMID)( 1660 << 14)
#define MC__CBA_PSHIFT6                          (MCPARAMID)( 1661 << 14)
#define MC__CBA_PSHIFT7                          (MCPARAMID)( 1662 << 14)
#define MC__CBA_PSHIFT8                          (MCPARAMID)( 1663 << 14)
#define MC__PSHIFT                               (MCPARAMID)( 1664 << 14)
#define MC__MTAP                                 (MCPARAMID)( 1665 << 14)
#define MC_ChannelTopology_OCTALXTAP              11
#define MC__ASSY_EIGHT                             5
#define MC__WIC_EIGHT                              5
#define MC_Camera_XC_ST50CE                       88
#define MC_CamConfig_I50SM                       134
#define MC_Camera_CS8550D                         89
#define MC_CamConfig_I120SM                      135
#define MC_Cable_A15_C18                          23
#define MC_CableName_Single_Channel_RGC_B         23
#define MC__W_STEP                               (MCPARAMID)( 1666 << 14)
#define MC__WSTEP                                (MCPARAMID)( 1667 << 14)
#define MC__FBL_FBLIMIT                          (MCPARAMID)( 1668 << 14)
#define MC__FBSIZE                               (MCPARAMID)( 1669 << 14)
#define MC_Camera_L301kc                          90
#define MC_Camera_XC_ST70CE                       91
#define MC_ChannelTopology_QUADXPAIRTAP           12
#define MC_ChannelTopology_QUADXPAIREND           13
#define MC_ChannelTopology_QUADXPAIRMID           14
#define MC__Live                                 (MCPARAMID)( 1670 << 14)
#define MC__CPHASE1                              (MCPARAMID)( 1671 << 14)
#define MC__CPHASE2                              (MCPARAMID)( 1672 << 14)
#define MC__CPHASE3                              (MCPARAMID)( 1673 << 14)
#define MC__CPHASE4                              (MCPARAMID)( 1674 << 14)
#define MC__CPHASE5                              (MCPARAMID)( 1675 << 14)
#define MC__CPHASE6                              (MCPARAMID)( 1676 << 14)
#define MC__CPHASE7                              (MCPARAMID)( 1677 << 14)
#define MC__CPHASE8                              (MCPARAMID)( 1678 << 14)
#define MC_TapStructure_QUAD_W2                   17
#define MC__WMAX                                 (MCPARAMID)( 1679 << 14)
#define MC__D1_WINDEX                            (MCPARAMID)( 1680 << 14)
#define MC__D2_WINDEX                            (MCPARAMID)( 1681 << 14)
#define MC__D3_WINDEX                            (MCPARAMID)( 1682 << 14)
#define MC__D4_WINDEX                            (MCPARAMID)( 1683 << 14)
#define MC__D5_WINDEX                            (MCPARAMID)( 1684 << 14)
#define MC__D6_WINDEX                            (MCPARAMID)( 1685 << 14)
#define MC__D7_WINDEX                            (MCPARAMID)( 1686 << 14)
#define MC__D8_XINDEX                            (MCPARAMID)( 1687 << 14)
#define MC__D8_WINDEX                            (MCPARAMID)( 1688 << 14)
#define MC__VLC_OVRALIGN                         (MCPARAMID)( 1689 << 14)
#define MC__VLC_OVRALIGN_ONELINE                   1
#define MC__VLC_OVRALIGN_SIXTEENLINES              2


#endif // _\\Yoko-tsuno\Transfer\Hardware\MsfCompiler\McParams_
