/*
 * blackfin-2d-vector-transformation 
 * 
 * Copyright (c) Frederik Wenigwieser, frederik.wenigwieser@gmail.com
 */


#include <cdefBF527.h>
#include <fract_complex.h>
#include <math.h>
#include <flt2fr.h>
#include <fract2float_conv.h>


#define GRAD_2_RAD (M_PI / 180)
#define PRE_COMMA_BITS 10

complex_fract16 transform(complex_fract16 vect, complex_fract16 translation, complex_fract16 rotation);

int main()
{
	// .re represents x; .im represents y
    complex_fract16 vect1 = {.re = (float_to_fract16( 2.5 / (2 << PRE_COMMA_BITS))), 
                             .im = (float_to_fract16(-2.0 / (2 << PRE_COMMA_BITS)))};
							 
	// represents translation of the new coordinate system in respect to the old
    complex_fract16 translation =  {.re = (float_to_fract16(1.0 / (2 << PRE_COMMA_BITS))), 
                                    .im = (float_to_fract16(1.0 / (2 << PRE_COMMA_BITS)))};
									
	// represents rotation of the new coordinate system in respect to the old
    complex_fract16 rotation = {.re = float_to_fract16(cos(45 * GRAD_2_RAD)), 
                                .im = float_to_fract16(sin(45 * GRAD_2_RAD))};
	
	complex_fract16 result =  transform(vect1, translation, rotation);
	
	float result_x_fl = fract16_to_float(result.re) * (2 << PRE_COMMA_BITS);
	float result_y_fl = fract16_to_float(result.im) * (2 << PRE_COMMA_BITS);

	//while(1);
	
	return 0;
}

/**
  * @brief  translates and then rotates a vector
  * @param  vect: input vector
  * @param  translation: represents the translation from the old to the new coordinate system
  * @param  rotation: represents the rotation of the new coordinate system in a complex number
  * @retval ouptput vect transformed to new coordinate system
  */
complex_fract16 transform(complex_fract16 vect, complex_fract16 translation, complex_fract16 rotation)
{
	return cmlt_fr16(csub_fr16(vect, translation), rotation);
}

