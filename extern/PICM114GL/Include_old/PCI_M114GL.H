
#include "type_def.h"
#include <windows.h>



#ifdef __cplusplus
extern "C" {
#endif
	
	typedef void (PASCAL *MNetCbk)(U16 RingNo);
	typedef void (PASCAL *PM114GLUserCbk)(U16 SwitchCardNo,LPVOID Param1,LPVOID Param2);


///////M114G SYSTEM OPERATE	
	I16 PASCAL _M114GL_open(I16 *existcards);
	I16 PASCAL _M114GL_close();
	I16 PASCAL _M114GL_initial( U16 SwitchCardNo);
	I16 PASCAL _M114GL_open_mnet(U16 SwitchCardNo);
	I16 PASCAL _M114GL_close_mnet(U16 SwitchCardNo);
	I16 PASCAL _M114GL_get_start_ring_num( U16 CardSwitchNo , U16 *RingNo);
	I16 PASCAL _M114GL_set_ring_config( U16 SwitchCardNo , U16 commSpd);
	I16 PASCAL _M114GL_get_io_status(U16 SwitchCardNo,U16 AxisNo, U16 *io_sts);
	I16 PASCAL _M114GL_motion_done(U16 SwitchCardNo,U16 AxisNo);
////////SERVO SIGNAL CONFIGURATION
	///////SERVO IO CONFIGURATION
	I16 PASCAL _M114GL_set_alm(U16 SwitchCardNo,U16 AxisNo, U16 alm_logic, U16 alm_mode);
	I16 PASCAL _M114GL_set_el(U16 SwitchCardNo,U16 AxisNo, U16 el_mode);
	I16 PASCAL _M114GL_set_inp(U16 SwitchCardNo,U16 AxisNo, U16 inp_enable, U16 inp_logic);
	I16 PASCAL _M114GL_set_erc(U16 SwitchCardNo,U16 AxisNo, U16 erc_logic, U16 erc_on_time);
	I16 PASCAL _M114GL_set_servo(U16 SwitchCardNo,U16 AxisNo, U16 on_off);
	I16 PASCAL _M114GL_set_sd(U16 SwitchCardNo,U16 AxisNo, U16 enable,U16 sd_logic, U16 sd_latch, U16 sd_mode);
	I16 PASCAL _M114GL_set_ralm(U16 SwitchCardNo,U16 AxisNo, U16 on_off);
	I16 PASCAL _M114GL_set_auto_erc(U16 SwitchCardNo,U16 AxisNo, U16 auto_erc_logic);
	I16 PASCAL _M114GL_set_erc_on(U16 SwitchCardNo,U16 AxisNo, U16 on_off);
	I16 PASCAL _M114GL_set_ell(U16 SwitchCardNo,U16 AxisNo, U16 ell_logic);
	I16 PASCAL _M114GL_set_mechanical_input_filter(U16 SwitchCardNo,U16 AxisNo, U16 on_off);
	//////MOTION COUNTER CONTROL
	I16 PASCAL _M114GL_get_position(U16 SwitchCardNo,U16 AxisNo, F64 *pos);
	I16 PASCAL _M114GL_set_position(U16 SwitchCardNo,U16 AxisNo, F64 pos);
	I16 PASCAL _M114GL_get_command(U16 SwitchCardNo,U16 AxisNo, I32 *cmd);
	I16 PASCAL _M114GL_set_command(U16 SwitchCardNo,U16 AxisNo, I32 cmd);
	I16 PASCAL _M114GL_get_error_counter(U16 SwitchCardNo,U16 AxisNo, I16 *error);
	I16 PASCAL _M114GL_reset_error_counter(U16 SwitchCardNo,U16 AxisNo);
	I16 PASCAL _M114GL_get_general_counter(U16 SwitchCardNo,U16 AxisNo, F64 *GetValue);
	I16 PASCAL _M114GL_set_general_counter(U16 SwitchCardNo,U16 AxisNo,I16 CntSrc, F64 SetValue);
	I16 PASCAL _M114GL_get_target_pos(U16 SwitchCardNo,U16 AxisNo, F64 *pos);
	I16 PASCAL _M114GL_set_target_pos(U16 SwitchCardNo,U16 AxisNo, F64 Pos);
	I16 PASCAL _M114GL_get_rest_command(U16 SwitchCardNo,U16 AxisNo, I32 *rest_command);
	I16 PASCAL _M114GL_check_rdp(U16 SwitchCardNo,U16 AxisNo, I32 *rdp_command);
	//Pulse Input/Output Configuration
	I16 PASCAL _M114GL_set_pls_outmode(U16 SwitchCardNo,U16 AxisNo, U16 pls_outmode);
	I16 PASCAL _M114GL_set_pls_iptmode(U16 SwitchCardNo,U16 AxisNo, U16 pls_iptmode, U16 pls_logic);
	I16 PASCAL _M114GL_set_feedback_src(U16 SwitchCardNo,U16 AxisNo, U16 Src);
	///////HOMING 
	I16 PASCAL _M114GL_set_home_config(U16 SwitchCardNo,U16 AxisNo,U16 home_mode,U16 org_logic,U16 ez_logic,U16 ez_count,U16 erc_out);
	I16 PASCAL _M114GL_home_move(U16 SwitchCardNo,U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc);
	I16 PASCAL _M114GL_escape_home(U16 SwitchCardNo,U16 AxisNo, F64 StrVel,F64 MaxVel,F64 Tacc);
	I16 PASCAL _M114GL_home_search(U16 SwitchCardNo,U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc, F64 ORGOffset);

///////Motion COMMAND
	//PTP     MOVE
	I16 PASCAL _M114GL_start_tr_move(U16 SwitchCardNo,U16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_ta_move(U16 SwitchCardNo,U16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_sr_move(U16 SwitchCardNo,U16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	I16 PASCAL _M114GL_start_sa_move(U16 SwitchCardNo,U16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	I16 PASCAL _M114GL_set_move_ratio(U16 SwitchCardNo,U16 AxisNo, F64 move_ratio);
	I16 PASCAL _M114GL_p_change(U16 SwitchCardNo,U16 AxisNo, F64 NewPos);
	I16 PASCAL _M114GL_backlash_comp(U16 SwitchCardNo,U16 AxisNo,U16 BCompPulse);
	I16 PASCAL _M114GL_suppress_vibration(U16 SwitchCardNo,U16 AxisNo,U16 ReverseTime,U16 ForwardTime);
	I16 PASCAL _M114GL_set_idle_pulse(U16 SwitchCardNo,U16 AxisNo,U16 idl_pulse);

	//VELOCITY MOVE
	I16 PASCAL _M114GL_tv_move(U16 SwitchCardNo,U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc);
	I16 PASCAL _M114GL_sv_move(U16 SwitchCardNo,U16 AxisNo, F64 StrVel, F64 MaxVel, F64 Tacc, F64 SVacc);
	I16 PASCAL _M114GL_v_change(U16 SwitchCardNo,U16 AxisNo, F64 NewVel, F64 Time);
	I16 PASCAL _M114GL_fix_speed_range(U16 SwitchCardNo,U16 AxisNo, F64 MaxVel);
	I16 PASCAL _M114GL_unfix_speed_range(U16 SwitchCardNo,U16 AxisNo);
	I16 PASCAL _M114GL_get_current_speed(U16 SwitchCardNo,U16 AxisNo, F64 *speed);
	I16 PASCAL _M114GL_verify_speed(F64 StrVel,F64 MaxVel,F64 *minAccT,F64 *maxAccT, F64 MaxSpeed);

	//STOP 
	I16 PASCAL _M114GL_emg_stop(U16 SwitchCardNo,U16 AxisNo);
	I16 PASCAL _M114GL_sd_stop(U16 SwitchCardNo,U16 AxisNo,F64 Tdec);

	//2D PTP
	I16 PASCAL _M114GL_start_tr_line2(U16 SwitchCardNo, U16 *AxisArray, F64 DistX, F64 DistY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_ta_line2(U16 SwitchCardNo, U16 *AxisArray, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_sr_line2(U16 SwitchCardNo, U16 *AxisArray, F64 DistX, F64 DistY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	I16 PASCAL _M114GL_start_sa_line2(U16 SwitchCardNo, U16 *AxisArray, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);

	//3D PTP
	I16 PASCAL _M114GL_start_tr_line3(U16 SwitchCardNo,U16 *AxisArray, F64 DistX, F64 DistY, F64 DistZ, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_ta_line3(U16 SwitchCardNo,U16 *AxisArray, F64 PosX, F64 PosY, F64 PosZ, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_sr_line3(U16 SwitchCardNo,U16 *AxisArray, F64 DistX, F64 DistY, F64 DistZ, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	I16 PASCAL _M114GL_start_sa_line3(U16 SwitchCardNo,U16 *AxisArray, F64 PosX, F64 PosY, F64 PosZ, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);

	//4D PTP
	I16 PASCAL _M114GL_start_tr_line4(U16 SwitchCardNo,F64 DistX, F64 DistY, F64 DistZ, F64 DistU, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_ta_line4(U16 SwitchCardNo, F64 PosX, F64 PosY, F64 PosZ, F64 PosU, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_sr_line4(U16 SwitchCardNo,F64 DistX, F64 DistY, F64 DistZ, F64 DistU, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	I16 PASCAL _M114GL_start_sa_line4(U16 SwitchCardNo, F64 PosX, F64 PosY, F64 PosZ, F64 PosU, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	
	//2D Arc
	I16 PASCAL _M114GL_get_arc_data_from_3points( F64 x0, F64 y0, F64 x1, F64 y1,F64 x2, F64 y2,F64 *Cx, F64 *Cy,U16 *Dir);
	I16 PASCAL _M114GL_arc_get_center(F64 Sx, F64 Sy, F64 Ex, F64 Ey, F64 Radius, U16 DIR, F64 *Cx, F64 *Cy);
	I16 PASCAL _M114GL_start_tr_arc2(U16 SwitchCardNo,U16 *AxisArray, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel,F64 MaxVel, F64 Tacc,F64 Tdec);
	I16 PASCAL _M114GL_start_ta_arc2(U16 SwitchCardNo,U16 *AxisArray, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec);
	I16 PASCAL _M114GL_start_sr_arc2(U16 SwitchCardNo, U16 *AxisArray, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel,F64 MaxVel, F64 Tacc,F64 Tdec,F64 SVacc,F64 SVdec);
	I16 PASCAL _M114GL_start_sa_arc2(U16 SwitchCardNo, U16 *AxisArray, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec,F64 SVacc,F64 SVdec);

	// CYLINDER SURFACE MOTION
	I16 PASCAL _M114GL_start_tr_arc_xyz(U16 SwitchCardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, F64 DistZ,I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec);
	I16 PASCAL _M114GL_start_ta_arc_xyz(U16 SwitchCardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey,F64 PosZ, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec);
	I16 PASCAL _M114GL_start_sr_arc_xyz(U16 SwitchCardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, F64 DistZ, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec, F64 SVacc,F64 SVdec);
	I16 PASCAL _M114GL_start_sa_arc_xyz(U16 SwitchCardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey,F64 PosZ, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec, F64 SVacc,F64 SVdec);

	// CONTINUE MOTION
	I16 PASCAL _M114GL_set_continuous_move(U16 SwitchCardNo,U16 AxisNo, U16 conti_logic);
	I16 PASCAL _M114GL_check_continuous_buffer(U16 SwitchCardNo,U16 AxisNo);
	I16 PASCAL _M114GL_get_continuous_buffer_status(U16 SwitchCardNo,U16 AxisNo);
	I16 PASCAL _M114GL_cancel_continuous_buffer(U16 SwitchCardNo,U16 AxisNo);

	I16 PASCAL _M114GL_start_tr_move_conti(U16 SwitchCardNo,U16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_ta_move_conti(U16 SwitchCardNo,U16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_sr_move_conti(U16 SwitchCardNo,U16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	I16 PASCAL _M114GL_start_sa_move_conti(U16 SwitchCardNo,U16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);

	I16 PASCAL _M114GL_start_tr_line2_conti(U16 SwitchCardNo, U16 *AxisArray, F64 DistX, F64 DistY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_ta_line2_conti(U16 SwitchCardNo, U16 *AxisArray, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_sr_line2_conti(U16 SwitchCardNo, U16 *AxisArray, F64 DistX, F64 DistY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	I16 PASCAL _M114GL_start_sa_line2_conti(U16 SwitchCardNo, U16 *AxisArray, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);

	I16 PASCAL _M114GL_start_tr_line3_conti(U16 SwitchCardNo, U16 *AxisArray, F64 DistX, F64 DistY,F64 DistZ, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_ta_line3_conti(U16 SwitchCardNo, U16 *AxisArray, F64 PosX, F64 PosY, F64 PosZ, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_sr_line3_conti(U16 SwitchCardNo,U16 *AxisArray, F64 DistX, F64 DistY, F64 DistZ, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	I16 PASCAL _M114GL_start_sa_line3_conti(U16 SwitchCardNo,U16 *AxisArray, F64 PosX, F64 PosY, F64 PosZ, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);

	I16 PASCAL _M114GL_start_tr_arc2_conti(U16 SwitchCardNo, U16 *AxisArray, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel,F64 MaxVel, F64 Tacc,F64 Tdec);
	I16 PASCAL _M114GL_start_ta_arc2_conti(U16 SwitchCardNo, U16 *AxisArray, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec);
	I16 PASCAL _M114GL_start_sr_arc2_conti(U16 SwitchCardNo, U16 *AxisArray, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, I16 DIR, F64 StrVel,F64 MaxVel, F64 Tacc,F64 Tdec,F64 SVacc,F64 SVdec);
	I16 PASCAL _M114GL_start_sa_arc2_conti(U16 SwitchCardNo, U16 *AxisArray, F64 Cx, F64 Cy, F64 Ex, F64 Ey, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec,F64 SVacc,F64 SVdec);

	I16 PASCAL _M114GL_start_tr_arc_xyz_conti(U16 SwitchCardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, F64 DistZ,I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec);
	I16 PASCAL _M114GL_start_ta_arc_xyz_conti(U16 SwitchCardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey,F64 PosZ, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec);
	I16 PASCAL _M114GL_start_sr_arc_xyz_conti(U16 SwitchCardNo, F64 OffsetCx, F64 OffsetCy, F64 OffsetEx, F64 OffsetEy, F64 DistZ, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec, F64 SVacc,F64 SVdec);
	I16 PASCAL _M114GL_start_sa_arc_xyz_conti(U16 SwitchCardNo, F64 Cx, F64 Cy, F64 Ex, F64 Ey,F64 PosZ, I16 DIR, F64 StrVel, F64 MaxVel, F64 Tacc,F64 Tdec, F64 SVacc,F64 SVdec);

	I16 PASCAL _M114GL_start_tr_line4_conti(U16 SwitchCardNo,F64 DistX, F64 DistY, F64 DistZ, F64 DistU, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_ta_line4_conti(U16 SwitchCardNo, F64 PosX, F64 PosY, F64 PosZ, F64 PosU, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_start_sr_line4_conti(U16 SwitchCardNo,F64 DistX, F64 DistY, F64 DistZ, F64 DistU, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	I16 PASCAL _M114GL_start_sa_line4_conti(U16 SwitchCardNo, F64 PosX, F64 PosY, F64 PosZ, F64 PosU, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
/////// GENERAL AXIS IO	
	I16 PASCAL _M114GL_axis_input(U16 SwitchCardNo, U16 *input_sts);
	I16 PASCAL _M114GL_axis_output(U16 SwitchCardNo, U16 ChannelNo, U16 on_off);

////////COUNTER LATCH
	I16 PASCAL _M114GL_set_ltc_logic(U16 SwitchCardNo, U16 AxisNo, U16 ltc_logic);
	I16 PASCAL _M114GL_get_latch_data(U16 SwitchCardNo,U16 AxisNo,U16 LatchNo,F64 *Pos);

	I16 PASCAL _M114GL_set_FIFO_latch_src(U16 SwitchCardNo,U16 AxisCounterNo,U16 LatchInputNo,U16 Enable);
	I16 PASCAL _M114GL_reset_latch_data(U16 SwitchCardNo);
	I16 PASCAL _M114GL_get_latch_FIFO_length(U16 SwitchCardNo,U16 *length);
	I16 PASCAL _M114GL_get_latch_data_from_buffer(U16 SwitchCardNo,U16 BufferNo,U16 *AxisCounterNo,U16 *LatchDataCnt,I32 *LatchDataTable);

///////INTERRUPT
	I16 PASCAL _M114GL_set_int_factor(U16 SwitchCardNo,U16 AxisNo, U32 int_factor );
	I16 PASCAL _M114GL_int_control(U16 SwitchCardNo,U16 IntType);
	I16 PASCAL _M114GL_int_enable(U16 SwitchCardNo,HANDLE *phEvent);
	I16 PASCAL _M114GL_int_disable(U16 SwitchCardNo);
	I16 PASCAL _M114GL_int_link( U16 SwitchCardNo, PM114GLUserCbk CbkFunc);
	I16 PASCAL _M114GL_get_int_status(U16 SwitchCardNo,U16 AxisNo, U32 *error_int_status, U32 *event_int_status);

////// Load Config file
	I16 PASCAL _M114GL_config_from_file(U16 SwitchCardNo,char *file_name);

////////COUNTER COMPARATOR
	I16 PASCAL _M114GL_set_general_comparator(U16 SwitchCardNo,U16 AxisNo,U16 CmpSrc,U16 CmpMethod,U16 CmpAction, F64 Data);
	I16 PASCAL _M114GL_set_trigger_comparator(U16 SwitchCardNo,U16 AxisNo, U16 CmpSrc, U16 CmpMethod, F64 Data);
	I16 PASCAL _M114GL_set_trigger_type(U16 SwitchCardNo,U16 AxisNo,U16 TriggerType);
	I16 PASCAL _M114GL_check_compare_data(U16 SwitchCardNo,U16 AxisNo, U16 CompType, F64 *Pos);
	I16 PASCAL _M114GL_check_compare_status(U16 SwitchCardNo,U16 AxisNo, U16 *cmp_sts);

	I16 PASCAL _M114GL_set_auto_trigger_comparator(U16 SwitchCardNo,U16 CompareNo,U16 AxisCounterNo,U16 DIR,I32 Start, U16 Interval, U32 TriggerNum);
	I16 PASCAL _M114GL_start_auto_trigger( U16 SwitchCardNo, U16 CompareNo,U16 On_Off);
	I16 PASCAL _M114GL_set_auto_compare_counter(U16 SwitchCardNo,U16 CompareNo,I32 SetValue);
	I16 PASCAL _M114GL_set_trigger_pulsewidth(U16 SwitchCardNo,U16 CompareNo,U16 PulseWidth);
	I16 PASCAL _M114GL_set_axis_counter(U16 SwitchCardNo,U16 AxisCounterNo,U16 CntMode,U16 CntDir,I32 SetValue);
	I16 PASCAL _M114GL_get_axis_counter(U16 SwitchCardNo,U16 AxisCounterNo,I32 *SetValue);
	I16 PASCAL _M114GL_set_axis_counter_value(U16 SwitchCardNo,U16 AxisCounterNo,I32 SetValue);
	I16 PASCAL _M114GL_set_axis_counter_param(U16 SwitchCardNo,U16 AxisCounterNo,U16 CntMode,U16 CntDir);
//////Soft limit
	I16 PASCAL _M114GL_set_soft_limit(U16 SwitchCardNo,U16 AxisNo, I32 PLimit, I32 NLimit );
	I16 PASCAL _M114GL_enable_soft_limit(U16 SwitchCardNo,U16 AxisNo, I16 Action );
	I16 PASCAL _M114GL_disable_soft_limit(U16 SwitchCardNo,U16 AxisNo);

//////Soft STA STP signal
	I16 PASCAL _M114GL_set_soft_sta_signal(U16 SwitchCardNo, I16 on_off);
	I16 PASCAL _M114GL_set_soft_stp_signal(U16 SwitchCardNo, I16 on_off);

//////Sync Line2 
	// triggered by the external signals STA/STP
	I16 PASCAL _M114GL_sync_start_tr_move(U16 SwitchCardNo, U16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_sync_start_ta_move(U16 SwitchCardNo, U16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_sync_start_sr_move(U16 SwitchCardNo, U16 AxisNo, F64 Dist, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	I16 PASCAL _M114GL_sync_start_sa_move(U16 SwitchCardNo, U16 AxisNo, F64 Pos, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	//  Automatically triggered when the command was written
	I16 PASCAL _M114GL_autosync_start_tr_line2(U16 SwitchCardNo, U16 *AxisArray, F64 DistX, F64 DistY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_autosync_start_ta_line2(U16 SwitchCardNo, U16 *AxisArray, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec);
	I16 PASCAL _M114GL_autosync_start_sr_line2(U16 SwitchCardNo, U16 *AxisArray, F64 DistX, F64 DistY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);
	I16 PASCAL _M114GL_autosync_start_sa_line2(U16 SwitchCardNo, U16 *AxisArray, F64 PosX, F64 PosY, F64 StrVel, F64 MaxVel, F64 Tacc, F64 Tdec, F64 SVacc, F64 SVdec);

/////// SECURITY OPERATION
	I16 PASCAL _M114GL_get_card_series_number(U16 SwitchCardNo,U8 *NumArray);
	I16 PASCAL _M114GL_get_card_product_key(U16 SwitchCardNo,U8 *KeyNumArray);
	I16 PASCAL _M114GL_get_retain_data(U16 SwitchCardNo,U16 PageNo,U8 *DataArray);
	I16 PASCAL _M114GL_set_retain_data(U16 SwitchCardNo,U16 PageNo,U8 *DataArray);
#ifdef __cplusplus
}
#endif
