#ifndef __ADC_A180_H__
#define __ADC_A180_H__



#include "Type_def.h"

// A180 device control definition
#define ADC_DEVICE_ENABLE 0x01
#define ADC_DEVICE_DISABLE 0x00
// DAC channel control definition
#define ADC_CHANNEL_ENABLE 0x01
#define ADC_CHANNEL_DISABLE 0x00
// Channel Definition
#define ADC_CHANNEL_0 0x00
#define ADC_CHANNEL_1 0x01
#define ADC_CHANNEL_2 0x02
#define ADC_CHANNEL_3 0x03
#define ADC_CHANNEL_4 0x04
#define ADC_CHANNEL_5 0x05
#define ADC_CHANNEL_6 0x06
#define ADC_CHANNEL_7 0x07
// Gain value definition
#define ADC_CHANNEL_GAIN_0 0x00
#define ADC_CHANNEL_GAIN_2 0x01
#define ADC_CHANNEL_GAIN_4 0x02
#define ADC_CHANNEL_GAIN_8 0x03

//Instruction Set of EEPROM AT25040A
#define AT25040A_WREN	0x06
#define AT25040A_WRDI	0x04
#define AT25040A_RDSR	0x05
#define AT25040A_WRSR	0x01
#define AT25040A_READ	0x03
#define AT25040A_WRITE	0x02


//===== A180 ADC module functions definition =============
#ifdef __cplusplus
extern "C" {
#endif

I16 PASCAL _mnet_ai8_initial( U16 RingNo, U16 SlaveIP );
I16 PASCAL _mnet_ai8_get_hardware_info( U16 RingNo, U16 SlaveIP, U8 *DeviceID, U8 *VHDL_Version );
I16 PASCAL _mnet_ai8_set_cycle_time( U16 RingNo, U16 SlaveIP, U8 SetValue );
I16 PASCAL _mnet_ai8_enable_device( U16 RingNo, U16 SlaveIP, U8 EnableDevice );
I16 PASCAL _mnet_ai8_enable_channel( U16 RingNo, U16 SlaveIP, U16 ChannelNo, U8 Enable );
I16 PASCAL _mnet_ai8_set_channel_gain( U16 RingNo, U16 SlaveIP, U16 ChannelNo, U8 Gain );
I16 PASCAL _mnet_ai8_get_value( U16 RingNo, U16 SlaveIP, U16 ChannelNo, I16 *GetValue );
I16 PASCAL _mnet_ai8_get_value_all( U16 RingNo, U16 SlaveIP, I16 *GetValue );
I16 PASCAL _mnet_ai8_get_voltage( U16 RingNo, U16 SlaveIP, U16 ChannelNo, F64 *Voltage );
I16 PASCAL _mnet_ai8_get_voltage_all( U16 RingNo, U16 SlaveIP, F64 *Voltage );

#ifdef __cplusplus
}
#endif

#endif //__ADC_A180_H__


