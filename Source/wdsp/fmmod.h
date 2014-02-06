/*  fmmod.h

This file is part of a program that implements a Software-Defined Radio.

Copyright (C) 2013 Warren Pratt, NR0V

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.

The author can be reached by email at  

warren@wpratt.com

*/

#ifndef _fmmod_h
#define _fmmod_h

typedef struct _fmmod
{
	int run;
	int size;
	double* in;
	double* out;
	double samplerate;
	double deviation;
	double f_low;
	double f_high;
	int ctcss_run;
	double ctcss_level;
	double ctcss_freq;
	// for pre-emphasis filter
	double* infilt;
	double* product;
	double* mults;
	fftw_plan CFor;
	fftw_plan CRev;
	// for ctcss gen
	double tscale;
	double tphase;
	double tdelta;
	// mod
	double sphase;
	double sdelta;
	// bandpass
	int bp_run;
	double bp_fc;
	double* bp_infilt;
	double* bp_product;
	double* bp_mults;
	fftw_plan bp_CFor;
	fftw_plan bp_CRev;
}fmmod, *FMMOD;

extern FMMOD create_fmmod (int run, int size, double* in, double* out, int rate, double dev, double f_low, double f_high, int ctcss_run, double ctcss_level, double ctcss_freq, int bp_run);

extern void destroy_fmmod (FMMOD a);

extern void flush_fmmod (FMMOD a);

extern void xfmmod (FMMOD a);

// TXA Properties

extern __declspec (dllexport) void SetTXAFMDeviation (int channel, double deviation);

extern __declspec (dllexport) void SetTXACTCSSFreq (int channel, double freq);

extern __declspec (dllexport) void SetTXACTCSSRun (int channel, int run);

#endif