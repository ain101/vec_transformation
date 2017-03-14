#include <cdefBF527.h>
#include <gcc.h>
#include <fract_complex.h>
#include <complex_bf.h>
#include <fract_math.h>
#include <math.h>
#include <flt2fr.h>

#define PI 3.14159265
#define GRAD_2_RAD (PI / 180)
//#define ALPHA (45 * GRAD_2_RAD)
//#define ALPHA (PI / 4)

#define POST_COMMA_BITS 5

complex_fract16 transform(complex_fract16 vect, complex_fract16 translation, complex_fract16 rotation);

int main()
{
	// .re represents x; .im represents y
	complex_fract16 vect1 = {.re = 2 << POST_COMMA_BITS, 
							 .im = 0 << POST_COMMA_BITS};
							 
	
	complex_fract16 translation =  {.re = 1 << POST_COMMA_BITS, 
									.im = 1 << POST_COMMA_BITS};
	// represents rotation by 90° clockwise
	complex_fract16 rotation = {.re = float_to_fract16(cos(90 * GRAD_2_RAD)), 
								.im = float_to_fract16(sin(90 * GRAD_2_RAD))};
	
	
	complex_fract16 result =  transform(vect1, translation, rotation);
	
	float result_x = result.re >> POST_COMMA_BITS;
	float result_y = result.im >> POST_COMMA_BITS;
	
	//while(1);
	
	return 0;
}

/**
  * @brief  translates and rotates a vector
  * @param  vect: input vector
  * @param  translation: represents the translation from the old to the new coordinate system
  * @param  rotation: represents the rotation of the new coordinate system in a complex number
  * @retval ouptput vect transformed to new coordinate system
  */
complex_fract16 transform(complex_fract16 vect, complex_fract16 translation, complex_fract16 rotation)
{
	return cmlt_fr16(csub_fr16(vect, translation), rotation);
}


