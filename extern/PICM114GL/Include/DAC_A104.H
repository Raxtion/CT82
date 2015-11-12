#ifndef __DAC_A104_H__
#define __DAC_A104_H__


#include "Type_def.h"



//==== Define Coarse Gain Register =======
#define COARSE_CAIN_10V			0x00
#define COARSE_CAIN_10V_2564	0x01
#define COARSE_CAIN_10V_5263	0x02



//========= Function Definition =========
#ifdef __cplusplus
extern "C" {
#endif

I16 PASCAL _mnet_ao4_get_hardware_info( U16 RingNo, U16 SlaveIP, U8 *DeviceID, U8 *VHDL_Version );
I16 PASCAL _mnet_ao4_initial( U16 RingNo, U16 SlaveIP );

I16 PASCAL _mnet_ao4_initial_reset( U16 RingNo, U16 SlaveIP, U8 Enable);

I16 PASCAL _mnet_ao4_reset_DAC( U16 RingNo, U16 SlaveIP );

I16 PASCAL _mnet_ao4_clear_output_all( U16 RingNo, U16 SlaveIP );
I16 PASCAL _mnet_ao4_set_output( U16 RingNo, U16 SlaveIP, U8 ChannelNo, I16 SetValue );
I16 PASCAL _mnet_ao4_set_voltage( U16 RingNo, U16 SlaveIP, U8 ChannelNo, F64 Voltage );
I16 PASCAL _mnet_ao4_set_voltage1( U16 RingNo, U16 SlaveIP, U8 ChannelNo, F64 Voltage, I16 *Value );
I16 PASCAL _mnet_ao4_set_output_all( U16 RingNo, U16 SlaveIP, I16 SetValue1, I16 SetValue2, I16 SetValue3, I16 SetValue4 );
I16 PASCAL _mnet_ao4_set_voltage_all( U16 RingNo, U16 SlaveIP, F64 Voltage1, F64 Voltage2, F64 Voltage3, F64 Voltage4 );
I16 PASCAL _mnet_ao4_set_voltage_all1( U16 RingNo, U16 SlaveIP, F64 Voltage1, F64 Voltage2, F64 Voltage3, F64 Voltage4, I16 *Value1, I16 *Value2, I16 *Value3, I16 *Value4 );

I16 PASCAL _mnet_ao4_set_coarse_gain( U16 RingNo, U16 SlaveIP, U8 ChannelNo, I16 SetValue );
I16 PASCAL _mnet_ao4_set_fine_gain( U16 RingNo, U16 SlaveIP, U8 ChannelNo, I16 SetValue );
I16 PASCAL _mnet_ao4_set_offset( U16 RingNo, U16 SlaveIP, U8 ChannelNo, I16 SetValue );

I16 PASCAL _mnet_ao4_get_ARM_code_version(U16 RingNo, U16 SlaveIP , U16 *ReadData);

//
#ifdef __cplusplus
}
#endif



#endif //__DAC_A104_H__


