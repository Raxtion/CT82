/* SPEEDYWEB.H - Parameters for the WEB processors */
/* History: */
/*		00/06/27	Joel Harhellier		First issue */


#ifndef __SPEEDY_WEB__
#define __SPEEDY_WEB__

#define MC_ProcessType_RLC8      	1
#define MC_ProcessType_SHADING8		2
#define MC_ProcessType_SHADINGRGB   3

struct MC_PROC_RGBLUT
{
	UINT8 Red[256];
	UINT8 Green[256];
	UINT8 Blue[256];
};

#define MAKE_RGB_GAIN(R, G, B) (B | (G << 10) | (R << 20))
#define MAKE_RGB_LEVEL(R, G, B) (B | (G << 10) | (R << 20))


#endif	/* __SPEEDY_WEB__ */

