/*
 * blackfin-2d-vector-transformation 
 * 
 * Copyright (c) Frederik Wenigwieser, frederik.wenigwieser@gmail.com
 */


#include <cdefBF527.h>
#include <gcc.h>
#include <fract_complex.h>
#include <complex_bf.h>
#include <fract_math.h>
#include <math.h>
#include <flt2fr.h>
#include <fract2float_conv.h>
#include <inttypes.h>
#include <complex_bf.h>


#define GRAD_2_RAD (M_PI / 180)
#define POST_COMMA_BITS 5
#define POST_COMMA_BITMASK 0x1F

#define PRE_COMMA_BITS 10

complex_fract16 transform(complex_fract16 vect, complex_fract16 translation, complex_fract16 rotation);
complex_float float_transform(complex_float vect, complex_float translation, complex_float rotation);

int main()
{
    complex_fract16 vect1 = {.re = (float_to_fract16(2.0 / (2 << PRE_COMMA_BITS))), 
                             .im = (float_to_fract16(2.0 / (2 << PRE_COMMA_BITS)))};
							 
	
    complex_fract16 translation =  {.re = (float_to_fract16(0.0 / (2 << PRE_COMMA_BITS))), 
                                    .im = (float_to_fract16(0.0 / (2 << PRE_COMMA_BITS)))};
									
	// represents rotation by 45 counter clockwise
    complex_fract16 rotation = {.re = float_to_fract16(cos(45 * GRAD_2_RAD)), 
                                .im = float_to_fract16(sin(45 * GRAD_2_RAD))};
	
	complex_fract16 result =  transform(vect1, translation, rotation);
	
	float result_x_fl = fract16_to_float(result.re) * (2 << PRE_COMMA_BITS);
	float result_y_fl = fract16_to_float(result.im) * (2 << PRE_COMMA_BITS);
	
//////////////////FLOAT
    complex_float vect1_fl = {.re = 2, 
                              .im = 2};
							 
	
    complex_float translation_fl =  {.re = 0, 
                                     .im = 0};
	// represents rotation by 45 counter clockwise
    complex_float rotation_fl = {.re = cos(45 * GRAD_2_RAD), 
                                 .im = sin(45 * GRAD_2_RAD)};
	
	complex_float result_fl = float_transform(vect1_fl, translation_fl, rotation_fl);
	

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

/**
  * @brief  translates and then rotates a vector
  * @param  vect: input vector
  * @param  translation: represents the translation from the old to the new coordinate system
  * @param  rotation: represents the rotation of the new coordinate system in a complex number
  * @retval ouptput vect transformed to new coordinate system
  */
complex_float float_transform(complex_float vect, complex_float translation, complex_float rotation)
{
	return cmltf(csubf(vect, translation), rotation);
}

