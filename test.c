#include <cdefBF527.h>
#include <gcc.h>
#include <fract_complex.h>
#include <complex_bf.h>
#include <fract_math.h>
#include <math.h>
#include <flt2fr.h>

#define PI 3.14159265
#define GRAD_2_RAD 0.017453293
//#define ALPHA (45 * GRAD_2_RAD)
#define ALPHA (PI / 4)

int main()
{

	//complex_fract16 complex_1 = {.re = 0, .im = 200};
	//complex_fract16 complex_1 = {.re = float_to_fract16(0), .im = float_to_fract16(-0.51)};
	complex_fract16 complex_1 = {.re = 0, .im = 2<<5};
	//complex_fract16 complex_2 = {.re = 3, .im = 4};
	
	complex_float complex_float_1 = {.re = 0, .im = 2};
	
	//complex_fract16 complex_rotate = {.re = cos(PI/2), .im = sin(PI/2)};
	//complex_fract16 complex_rotate = {.re = 0, .im = 1};
	//complex_fract16 complex_rotate = {.re = 0, .im = float_to_fract16(0.51)};
	//complex_fract16 complex_rotate = {.re = 0, .im = 2<<5};
	complex_fract16 complex_rotate = {.re = float_to_fract16(cos(ALPHA)), .im = float_to_fract16(sin(ALPHA))};
	//complex_float complex_float_rotate = {.re = 0, .im = 1};
	complex_float complex_float_rotate = {.re = cos(ALPHA), .im = sin(ALPHA)};
	
	volatile complex_fract16 complex_3 = {.re = 0, .im = 1};
	volatile complex_float complex_float_3 = {.re = 0, .im = 1};
	
	
	//fract16 fract_test1 = float_to_fract16(0.25);//0.25r;
	//fract16 fract_test2 = 0.25r;
	//fract16 fract_test3 = 0x2000;
	//fract16 fract_test4 = 0xAF;
	//fract16 fract_test5 = 55;
	
	//fract_test3 = add_fr1x16(fract_test1, fract_test2);
	//complex_3 = cadd_fr16(complex_1, complex_2);
	//complex_3 = csub_fr16(complex_1, complex_2);
	unsigned int debug_start = 0xFEED;
	complex_3 = cmlt_fr16(complex_1, complex_rotate);
	unsigned int debug_start = 0xFEEF;
	complex_float_3 = cmltf(complex_float_1, complex_float_rotate);
	unsigned int debug_end = 0xBEEF;
	
	float debug_re = fract16_to_float(complex_3.re);
	float debug_im = fract16_to_float(complex_3.im);
	
	//fract_test1 = fract_test1 * 2;
	
	//short *integer = &fract_test1;
	
	
	return 0;
}


complex_fract16 transform(complex_fract16 vect, complex_fract16 translation, complex_fract16 rotation)
{
	return cmlt_fr16(csub_fr16(vect, translation), rotation);
}


