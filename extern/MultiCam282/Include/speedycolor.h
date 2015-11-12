/* SPEEDYCOLOR.H - Parameters for the COLOR processors */
/* History: */
/*		00/06/27	Joel Harhellier		First issue */


#ifndef __SPEEDY_COLOR__
#define __SPEEDY_COLOR__

#define MC_ProcessType_BAYER	        100

#define MC_Operation_BAYER_USE_LUT		0x00000001
#define MC_Flags_BAYER_USE_LUT			0x00000001
#define MC_Operation_BAYER_EVEN_COL		0x00000002
#define MC_Flags_BAYER_EVEN_COL			0x00000002
#define MC_Operation_BAYER_EVEN_ROW		0x00000004
#define MC_Flags_BAYER_EVEN_ROW			0x00000004

struct MC_PROC_BAYER_LOOKUP
{
	UINT8 RedLut[256];
	UINT8 GreenLut[256];
	UINT8 BlueLut[256];
};


#endif	/* __SPEEDY_COLOR__ */

