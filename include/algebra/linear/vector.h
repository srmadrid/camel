/******************************************************************************
 * Filename: vector.h
 * 
 * Description:
 *      Declarations for the vector manipulation functions of CAMEL.
 *
 * Author: Sergio Madrid
 * Created on: 7/11/2023
 * 
 * Copyright (c) 2023 Sergio Madrid. All rights reserved.
 * Licensed under the MIT License. See LICENSE in the project root for
 * license information.
 *****************************************************************************/

#ifndef CAMEL_VECTOR
#define CAMEL_VECTOR


#include <stdlib.h>
#include <math.h>

#include "../../core/core.h"


/******************************************************************************
 * Struct: CML_Vector
 * 
 * Description:
 *      Represents a mathematical vector with components stored in a 
 *      dynamically allocated array. This struct is used throughout the CAMEL
 *      library to represent vectors in N-dimensional space.
 *
 * Fields:
 *      size_t n - The number of elements in the vector.
 *      f64 *data - A pointer to the dynamically allocated array of components.
 *
 * Notes:
 *      The 'data' pointer should be managed using cml_vector_init and
 *      cml_vector_free functions to ensure proper memory management. The 'n'
 *      should always reflect the number of allocated elements in 'data'.
 *****************************************************************************/
typedef struct {
    size_t n;
    f64 *data;
} CML_Vector;


/******************************************************************************
 * Function: cml_vector_init
 * 
 * Description:
 *      Initializes a vector of size 'n' to 0.
 *
 * Parameters:
 *      CML_Vector *v - The vector to be initialized.
 *      size_t n      - Size of the vector.
 * 
 * Returns:
 *      A pointer to the allocated CML_Vector.
 *****************************************************************************/
CAMEL_API CML_Status clm_vector_init(CML_Vector *v, size_t n);


/******************************************************************************
 * Function: cml_vector_free
 * 
 * Description:
 *      Frees the memory of the input CML_Vector.
 *
 * Parameters:
 *      CML_Vector *v - The pointer to the CML_Vector you want to free.
 * 
 * Returns:
 *      Void.
 *****************************************************************************/
CAMEL_API void cml_vector_free(CML_Vector *v);


/******************************************************************************
 * Function: cml_vector_add
 * 
 * Description:
 *      Adds two CML_Vector and writes the result to the out CML_Vector. Both 
 *      intput CML_Vector must have the same number of elements.
 *
 * Parameters:
 *      CML_Vector *v   - The first vector operand.
 *      CML_Vector *w   - The second vector operand.
 *      CML_Vector *out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector_add(const CML_Vector *v, const CML_Vector *w, CML_Vector *out);


/******************************************************************************
 * Function: cml_vector_sub
 * 
 * Description:
 *      Subtracts two CML_Vector and writes the result to the out CML_Vector. Both 
 *      intput CML_Vector must have the same number of elements.
 *
 * Parameters:
 *      CML_Vector *v   - The first vector operand.
 *      CML_Vector *w   - The second vector operand.
 *      CML_Vector *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector_sub(const CML_Vector *v, const CML_Vector *w, CML_Vector *out);


/******************************************************************************
 * Function: cml_vector_scale
 * 
 * Description:
 *      Multiplies a CML_Vector by a scalar, and writes the result to the out 
 *      CML_Vector.
 *
 * Parameters:
 *      CML_Vector *v   - The vector operand.
 *      double      t   - The scalar.
 *      CML_Vector *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector_scale(const CML_Vector *v, f64 t, CML_Vector *out);


/******************************************************************************
 * Function: cml_vector_mod
 * 
 * Description:
 *      Calculates the modulus of the input CML_Vector.
 *
 * Parameters:
 *      CML_Vector *v - The input vector.
 * 
 * Returns:
 *      The modulus of the input CML_Vector.
 *****************************************************************************/
CAMEL_API f64 cml_vector_mod(const CML_Vector *v);


/******************************************************************************
 * Function: cml_vector_norm
 * 
 * Description:
 *      Normalizes the input CML_Vector and writes it to the out CML_Vector.
 *
 * Parameters:
 *      CML_Vector *v   - The input vector.
 *      CML_Vector *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector_norm(const CML_Vector *v, CML_Vector *out);


/******************************************************************************
 * Function: cml_vector_dot
 * 
 * Description:
 *      Normalizes the input CML_Vector and writes it to the out CML_Vector.
 *
 * Parameters:
 *      CML_Vector *v   - The first input vector.
 *      CML_Vector *w   - The second input vector.
 * 
 * Returns:
 *      The dot product of the input vectors.
 *****************************************************************************/
CAMEL_API f64 cml_vector_dot(const CML_Vector *v, const CML_Vector *w);



/******************************************************************************
 * Type: CML_Vector2
 * 
 * Description:
 *      Represents a 2 dimensional vector.
 *
 * Notes:
 *      The object is directly a 2 dimensional array of f64.
 *****************************************************************************/
typedef f64 CML_Vector2[2];


/******************************************************************************
 * Macro: CML_VECTOR2_ZERO
 * 
 * Description:
 *      Initializes a CML_Vector2 to 0.
 *****************************************************************************/
#define CML_VECTOR2_ZERO {0.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR2_I
 * 
 * Description:
 *      Initializes a CML_Vector2 to the unit vector in the i direction.
 *****************************************************************************/
#define CML_VECTOR2_I {1.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR2_J
 * 
 * Description:
 *      Initializes a CML_Vector2 to the unit vector in the j direction.
 *****************************************************************************/
#define CML_VECTOR2_J {0.0, 1.0}


/******************************************************************************
 * Macro: CML_VECTOR2_ONE
 * 
 * Description:
 *      Initializes a CML_Vector2 to 1.
 *****************************************************************************/
#define CML_VECTOR2_ONE {1.0, 1.0}



/******************************************************************************
 * Type: CML_Vector3
 * 
 * Description:
 *      Represents a 3 dimensional vector.
 *
 * Notes:
 *      The object is directly a 3 dimensional array of f64.
 *****************************************************************************/
typedef f64 CML_Vector3[3];


/******************************************************************************
 * Macro: CML_VECTOR3_ZERO
 * 
 * Description:
 *      Initializes a CML_Vector3 to 0.
 *****************************************************************************/
#define CML_VECTOR3_ZERO {0.0, 0.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR3_I
 * 
 * Description:
 *      Initializes a CML_Vector3 to the unit vector in the i direction.
 *****************************************************************************/
#define CML_VECTOR3_I {1.0, 0.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR3_J
 * 
 * Description:
 *      Initializes a CML_Vector3 to the unit vector in the j direction.
 *****************************************************************************/
#define CML_VECTOR3_J {0.0, 1.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR3_K
 * 
 * Description:
 *      Initializes a CML_Vector3 to the unit vector in the k direction.
 *****************************************************************************/
#define CML_VECTOR3_K {0.0, 0.0, 1.0}


/******************************************************************************
 * Macro: CML_VECTOR3_ONE
 * 
 * Description:
 *      Initializes a CML_Vector3 to 1.
 *****************************************************************************/
#define CML_VECTOR3_ONE {1.0, 1.0, 1.0}



/******************************************************************************
 * Type: CML_Vector4
 * 
 * Description:
 *      Represents a 4 dimensional vector.
 *
 * Notes:
 *      The object is directly a 4 dimensional array of f64.
 *****************************************************************************/
typedef f64 CML_Vector4[4];


/******************************************************************************
 * Macro: CML_VECTOR4_ZERO
 * 
 * Description:
 *      Initializes a CML_Vector4 to 0.
 *****************************************************************************/
#define CML_VECTOR4_ZERO {0.0, 0.0, 0.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR4_I
 * 
 * Description:
 *      Initializes a CML_Vector4 to the unit vector in the i direction.
 *****************************************************************************/
#define CML_VECTOR4_I {1.0, 0.0, 0.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR4_J
 * 
 * Description:
 *      Initializes a CML_Vector4 to the unit vector in the j direction.
 *****************************************************************************/
#define CML_VECTOR4_J {0.0, 1.0, 0.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR4_K
 * 
 * Description:
 *      Initializes a CML_Vector4 to the unit vector in the k direction.
 *****************************************************************************/
#define CML_VECTOR4_K {0.0, 0.0, 1.0, 0.0}


/******************************************************************************
 * Macro: CML_VECTOR4_L
 * 
 * Description:
 *      Initializes a CML_Vector4 to the unit vector in the l direction.
 *****************************************************************************/
#define CML_VECTOR4_L {0.0, 0.0, 0.0, 1.0}


/******************************************************************************
 * Macro: CML_VECTOR4_ONE
 * 
 * Description:
 *      Initializes a CML_Vector4 to 1.
 *****************************************************************************/
#define CML_VECTOR4_ONE {1.0, 1.0, 1.0, 1.0}



/******************************************************************************
 * Function: cml_vector2_add
 * 
 * Description:
 *      Adds two CML_Vector2 and writes the result to the out CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The first vector operand.
 *      CML_Vector2 *w   - The second vector operand.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector2_add(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out);


/******************************************************************************
 * Function: cml_vector2_sub
 * 
 * Description:
 *      Subtracts two CML_Vector2 and writes the result to the out CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The first vector operand.
 *      CML_Vector2 *w   - The second vector operand.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector2_sub(const CML_Vector2 *v, const CML_Vector2 *w, CML_Vector2 *out);


/******************************************************************************
 * Function: cml_vector2_scale
 * 
 * Description:
 *      Multiplies a CML_Vector2 by a scalar, and writes the result to the out 
 *      CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The vector operand.
 *      double       t   - The scalar.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector2_scale(const CML_Vector2 *v, f64 t, CML_Vector2 *out);


/******************************************************************************
 * Function: cml_vector2_mod
 * 
 * Description:
 *      Calculates the modulus of the input CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v - The input vector.
 * 
 * Returns:
 *      The modulus of the input CML_Vector2.
 *****************************************************************************/
CAMEL_API f64 cml_vector2_mod(const CML_Vector2 *v);


/******************************************************************************
 * Function: cml_vector2_norm
 * 
 * Description:
 *      Normalizes the input CML_Vector2 and writes it to the out CML_Vector2.
 *
 * Parameters:
 *      CML_Vector2 *v   - The input vector.
 *      CML_Vector2 *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector2_norm(const CML_Vector2 *v, CML_Vector2 *out);


/******************************************************************************
 * Function: cml_vector2_dot
 * 
 * Description:
 *      Calculates the dot product of the input CML_Vector2s.
 *
 * Parameters:
 *      CML_Vector2 *v   - The first input vector.
 *      CML_Vector2 *w   - The second input vector.
 * 
 * Returns:
 *      The dot product of the input vectors.
 *****************************************************************************/
CAMEL_API f64 cml_vector2_dot(const CML_Vector2 *v, const CML_Vector2 *w);


/******************************************************************************
 * Function: cml_vector2_eq
 * 
 * Description:
 *      Compares two CML_Vector4s for equality.
 * 
 * Parameters:
 *      CML_Vector2 *v - The first input vector.
 *      CML_Vector2 *w - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CAMEL_API CML_Bool cml_vector2_eq(const CML_Vector2 *v, const CML_Vector2 *w);


/******************************************************************************
 * Function: cml_vector2_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Vector2s.
 *
 * Parameters:
 *      CML_Vector2 *expected - Expected vector.
 *      CML_Vector2 *got - Result vector.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_vector2_debug(const CML_Vector2 *expected, const CML_Vector2 *got);



/******************************************************************************
 * Function: cml_vector3_add
 * 
 * Description:
 *      Adds two CML_Vector3 and writes the result to the out CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first vector operand.
 *      CML_Vector3 *w   - The second vector operand.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector3_add(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/******************************************************************************
 * Function: cml_vector3_sub
 * 
 * Description:
 *      Subtracts two CML_Vector3 and writes the result to the out CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first vector operand.
 *      CML_Vector3 *w   - The second vector operand.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector3_sub(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/******************************************************************************
 * Function: cml_vector3_scale
 * 
 * Description:
 *      Multiplies a CML_Vector3 by a scalar, and writes the result to the out 
 *      CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v   - The vector operand.
 *      double       t   - The scalar.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector3_scale(const CML_Vector3 *v, f64 t, CML_Vector3 *out);


/******************************************************************************
 * Function: cml_vector3_mod
 * 
 * Description:
 *      Calculates the modulus of the input CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v - The input vector.
 * 
 * Returns:
 *      The modulus of the input CML_Vector3.
 *****************************************************************************/
CAMEL_API f64 cml_vector3_mod(const CML_Vector3 *v);


/******************************************************************************
 * Function: cml_vector3_norm
 * 
 * Description:
 *      Normalizes the input CML_Vector3 and writes it to the out CML_Vector3.
 *
 * Parameters:
 *      CML_Vector3 *v   - The input vector.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector3_norm(const CML_Vector3 *v, CML_Vector3 *out);


/******************************************************************************
 * Function: cml_vector3_dot
 * 
 * Description:
 *      Calculates the dot product of the input CML_Vector3s.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first input vector.
 *      CML_Vector3 *w   - The second input vector.
 * 
 * Returns:
 *      The dot product of the input vectors.
 *****************************************************************************/
CAMEL_API f64 cml_vector3_dot(const CML_Vector3 *v, const CML_Vector3 *w);


/******************************************************************************
 * Function: cml_vector3_cross
 * 
 * Description:
 *      Calculates the cross product of the input CML_Vector3s.
 *
 * Parameters:
 *      CML_Vector3 *v   - The first input vector.
 *      CML_Vector3 *w   - The second input vector.
 *      CML_Vector3 *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector3_cross(const CML_Vector3 *v, const CML_Vector3 *w, CML_Vector3 *out);


/******************************************************************************
 * Function: cml_vector3_eq
 * 
 * Description:
 *      Compares two CML_Vector4s for equality.
 * 
 * Parameters:
 *      CML_Vector3 *v - The first input vector.
 *      CML_Vector3 *w - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CAMEL_API CML_Bool cml_vector3_eq(const CML_Vector3 *v, const CML_Vector3 *w);


/******************************************************************************
 * Function: cml_vector3_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Vector3s.
 *
 * Parameters:
 *      CML_Vector3 *expected - Expected vector.
 *      CML_Vector3 *got - Result vector.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_vector3_debug(const CML_Vector3 *expected, const CML_Vector3 *got);



/******************************************************************************
 * Function: cml_vector4_add
 * 
 * Description:
 *      Adds two CML_Vector4 and writes the result to the out CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v   - The first vector operand.
 *      CML_Vector4 *w   - The second vector operand.
 *      CML_Vector4 *out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector4_add(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out);


/******************************************************************************
 * Function: cml_vector4_sub
 * 
 * Description:
 *      Subtracts two CML_Vector4 and writes the result to the out CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v   - The first vector operand.
 *      CML_Vector4 *w   - The second vector operand.
 *      CML_Vector4 *out - The output vector.
 * 
 * Returns:
 *      Success (0) or error (<0) code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector4_sub(const CML_Vector4 *v, const CML_Vector4 *w, CML_Vector4 *out);


/******************************************************************************
 * Function: cml_vector4_scale
 * 
 * Description:
 *      Multiplies a CML_Vector4 by a scalar, and writes the result to the out 
 *      CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v   - The vector operand.
 *      double       t   - The scalar.
 *      CML_Vector4 *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector4_scale(const CML_Vector4 *v, f64 t, CML_Vector4 *out);


/******************************************************************************
 * Function: cml_vector4_mod
 * 
 * Description:
 *      Calculates the modulus of the input CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v - The input vector.
 * 
 * Returns:
 *      The modulus of the input CML_Vector4.
 *****************************************************************************/
CAMEL_API f64 cml_vector4_mod(const CML_Vector4 *v);


/******************************************************************************
 * Function: cml_vector4_norm
 * 
 * Description:
 *      Normalizes the input CML_Vector4 and writes it to the out CML_Vector4.
 *
 * Parameters:
 *      CML_Vector4 *v   - The input vector.
 *      CML_Vector4 *out - The output vector.
 * 
 * Returns:
 *      Success or error code.
 *****************************************************************************/
CAMEL_API CML_Status cml_vector4_norm(const CML_Vector4 *v, CML_Vector4 *out);


/******************************************************************************
 * Function: cml_vector4_dot
 * 
 * Description:
 *      Calculates the dot product of the input CML_Vector4s.
 *
 * Parameters:
 *      CML_Vector4 *v   - The first input vector.
 *      CML_Vector4 *w   - The second input vector.
 * 
 * Returns:
 *      The dot product of the input vectors.
 *****************************************************************************/
CAMEL_API f64 cml_vector4_dot(const CML_Vector4 *v, const CML_Vector4 *w);


/******************************************************************************
 * Function: cml_vector4_eq
 * 
 * Description:
 *      Compares two CML_Vector4s for equality.
 * 
 * Parameters:
 *      CML_Vector4 *v - The first input vector.
 *      CML_Vector4 *w - The second input vector.
 * 
 * Returns:
 *      CAMEL_TRUE if the vectors are equal, CAMEL_FALSE otherwise.
 *****************************************************************************/
CAMEL_API CML_Bool cml_vector4_eq(const CML_Vector4 *v, const CML_Vector4 *w);


/******************************************************************************
 * Function: cml_vector4_debug
 * 
 * Description:
 *      Returns a debug message comparing the input CML_Vector4s.
 *
 * Parameters:
 *      CML_Vector4 *expected - Expected vector.
 *      CML_Vector4 *got - Result vector.
 * 
 * Returns:
 *      A string containing the debug message.
 *****************************************************************************/
CAMEL_API char *cml_vector4_debug(const CML_Vector4 *expected, const CML_Vector4 *got);


#endif /* CAMEL_VECTOR */
