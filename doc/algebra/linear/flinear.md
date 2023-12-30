
# Fixed Size Linear Algebra

This module deals with fixed size vectors and matrices, up to 4x4 (for variable size vectors and matrices, see [Variable Size Linear Algebra](vlinear.md)). This module is optimized for speed, and is offered as header only or compiled, to give the user maximum flexibility and performance; for this same reason, the functions in this module are not generic, and only work with the types specified below and do not check for errors (except for matrix inversion, where invertibility is checked beforehand), if the inputs are correctly allocated they will work as expected, but if they are not, the behavior is undefined.

**Module Location**: ```include/algebra/linear/flinear/flinear.h```

**Usage Options:** Header only or compiled.

## Table of Contents

- [Vectors](#vectors)
- [Matrices](#matrices)

## Vectors

Vectors represent a point in space, or a direction. This module includes vectors of size 2, 3 and 4.

### Vector File Locations

- Header only: ```include/algebra/linear/flinear/fvector.h```
- Compiled: ```include/algebra/linear/flinear/cfvector.h``` and ```src/algebra/linear/flinear/cfvector.c```

### Vector Types

- ```CML_Vector2```: 2D Vector. This is a ```union``` of a  ```struct``` with two ```f64``` fields, ```x``` and ```y```, and a two element array.
- ```CML_Vector3```: 3D Vector. This is a ```union``` of a  ```struct``` with three ```f64``` fields, ```x```, ```y``` and ```z```, and a three element array.
- ```CML_Vector4```: 4D Vector. This is a ```union``` of a  ```struct``` with four ```f64``` fields, ```x```, ```y```, ```z``` and ```w```, and a four element array.

### Vector Initialization

Vectors can be initiallized in two ways:

- Using the macros (```<VECTOR>``` indicates any vector type specified above in capital letters):
  - ```CML_<VECTOR>_ZERO```: Initializes a vector to zero.
  - ```CML_<VECTOR>_I```: Initializes a vector to unit length in the x direction.
  - ```CML_<VECTOR>_J```: Initializes a vector to unit length in the y direction.
  - ```CML_<VECTOR>_K```: Initializes a vector to unit length in the z direction.
  - ```CML_<VECTOR>_L```: Initializes a vector to unit length in the w direction.
  - ```CML_<VECTOR>_ONE```: Initializes a vector to one.
  - ```CML_<VECTOR>(f64 x, f64 y, f64 z, f64 w)```: Initializes a vector to the specified values. **Note**: takes only the first two values for 2D vectors, the first three for 3D vectors and all four for 4D vectors.
- Using standard initialization ```<vector> v = {{x, y, z, w}}```: Initializes a vector to the specified values using standard notation. **Note**: two braces are needed because of the union.

### Vector Functions

**Note**: The functions in this module are named according to the [common convention](../../../README.md#functions): ```cmlc_<type>_<function>_<type>``` for the compiled version, and ```cml_<type>_<function>_<type>``` for the header only version. For simplicity, only the header only version will be shown here, but the compiled version is also available. ```<vector>``` indicates any vector type specified above.

| Function | Description | Mathematical Notation |
| --- | --- | --- |
| ```cml_<vector>_add(<vector> *v, <vector> *w, <vector> *out)``` | Adds two vectors of the same dimension and stores the result in ```out```. | $\vec{v} + \vec{w} = \begin{bmatrix} v_{1} + w_{1} \\ v_{2} + w_{2} \\ \vdots \\ v_{n} + w_{n}\end{bmatrix}$ |
| ```cml_<vector>_sub(<vector> *v, <vector> *w, <vector> *out)``` | Subtracts two vectors of the same dimension and stores the result in ```out```. | $\vec{v} + \vec{w} = \begin{bmatrix} v_{1} - w_{1} \\ v_{2} - w_{2} \\ \vdots \\ v_{n} - w_{n}\end{bmatrix}$ |
| ```cml_<vector>_scale(<vector> *v, f64 t, <vector> *out)``` | Multiplies a vector by a scalar and stores the result in ```out```. | $\vec{v} \cdot t = \begin{bmatrix} v_{1} \cdot t \\ v_{2} \cdot t \\ \vdots \\ v_{n} \cdot t\end{bmatrix}$ |
| ```cml_<vector>_mod(<vector> *v)``` | Calculates the modulus of the input vector and returns it. | $\lvert\lvert\vec{v}\rvert\rvert = \sqrt{\sum_{i=1}^{n} {v}_{i}^{2}}$ |
| ```cml_<vector>_mod2(<vector> *v)``` | Calculates the squared modulus of the input vector and returns it. | $\lvert\lvert\vec{v}\rvert\rvert^{2} = \sum_{i=1}^{n} {v}_{i}^{2}$ |
| ```cml_<vector>_norm(<vector> *v, <vector> *out)``` | Normalizes the input vector and stores it in ```out```. | $\hat{v} = \frac{\vec{v}}{\lvert\lvert\vec{v}\rvert\rvert}$ |
| ```cml_<vector>_dot(<vector> *v, <vector> *w)``` | Calculates the dot product of two vectors of the same dimension and returns it. | $\vec{v} \cdot \vec{w} = \sum_{i=1}^{n} v_{i} \cdot w_{i}$ |
| ```cml_vector3_cross(CML_Vector3 *v, CML_Vector3 *w, CML_Vector3 *out)``` | Calculates the cross product of two 3D vectors and stores it in ```out```. | $\vec{v} \times \vec{w} = \begin{bmatrix} v_{2} \cdot w_{3} - v_{3} \cdot w_{2} \\ v_{3} \cdot w_{1} - v_{1} \cdot w_{3} \\ v_{1} \cdot w_{2} - v_{2} \cdot w_{1} \end{bmatrix}$ |
| ```cml_<vector>_distance(<vector> *v, <vector> *w)``` | Calculates the distance between two vectors of the same dimension and returns it. | $d(\vec{v}, \vec{w}) = \lvert\lvert\vec{v}-\vec{w}\rvert\rvert = \sqrt{\sum_{i=1}^{n} (v_{i} - w_{i})^{2}}$ |
| ```cml_<vector>_distance2(<vector> *v, <vector> *w)``` | Calculates the squared distance between two vectors of the same dimension and returns it. | $d(\vec{v}, \vec{w})^{2} = \lvert\lvert\vec{v}-\vec{w}\rvert\rvert² = \sum_{i=1}^{n} (v_{i} - w_{i})^{2}$ |
| ```cml_<vector>_angle(<vector> *v, <vector> *w)``` | Calculates the angle between two vectors of the same dimension and returns it. | $\theta = \arccos{\frac{\vec{v} \cdot \vec{w}}{\lvert\lvert\vec{v}\rvert\rvert \cdot \lvert\lvert\vec{w}\rvert\rvert}}$ |
| ```cml_<vector>_projection(<vector> *v, <vector> *w, <vector> *out)``` | Calculates the projection of a vector onto another vector of the same dimension and stores it in ```out```. | $proj_{\vec{w}}(\vec{v}) = \frac{\vec{v} \cdot \vec{w}}{\lvert\lvert\vec{w}\rvert\rvert²} \cdot \vec{w}$ |
| ```cml_<vector>_reflect(<vector> *v, <vector> *normal, <vector> *out)``` | Calculates the reflection of a vector across the surface defined by the normal and stores it in ```out```. | $reflect_{\vec{n}}(\vec{v}) = \vec{v} - 2 \cdot proj_{\vec{n}}(\vec{v})$ |
| ```cml_<vector>_eq(<vector> *v, <vector> *w)``` | Checks if two vectors are equal and returns ```CML_True``` if they are, ```CML_False``` otherwise. | $\vec{v} = \vec{w}$ |
| ```cml_<vector>_debug(<vector> *expected, <vector> *got)``` | Returns a string containing the debug info of the input vectors. | $\vec{v}$ |

## Matrices

Matrices represent linear transformations. This module includes all matrices of sizes ranging from 2x2 to 4x4.

### Matrix File Locations

- Header only: ```include/algebra/linear/flinear/fmatrix.h```
- Compiled: ```include/algebra/linear/flinear/cfmatrix.h``` and ```src/algebra/linear/flinear/cfmatrix.c```

### Matrix Types

- ```CML_Matrix2x2```: 2x2 Matrix. This is a ```union``` of a  ```struct``` with four ```f64``` fields, ```m00```, ```m01```, ```m10``` and ```m11```, and a four element array.
- ```CML_Matrix2x3```: 2x3 Matrix. This is a ```union``` of a  ```struct``` with six ```f64``` fields, ```m00```, ```m01```, ```m02```, ```m10```, ```m11``` and ```m12```, and a six element array.
- ```CML_Matrix2x4```: 2x4 Matrix. This is a ```union``` of a  ```struct``` with eight ```f64``` fields, ```m00```, ```m01```, ```m02```, ```m03```, ```m10```, ```m11```, ```m12``` and ```m13```, and a eight element array.
- ```CML_Matrix3x2```: 3x2 Matrix. This is a ```union``` of a  ```struct``` with six ```f64``` fields, ```m00```, ```m01```, ```m10```, ```m11```, ```m20``` and ```m21```, and a six element array.
- ```CML_Matrix3x3```: 3x3 Matrix. This is a ```union``` of a  ```struct``` with nine ```f64``` fields, ```m00```, ```m01```, ```m02```, ```m10```, ```m11```, ```m12```, ```m20```, ```m21``` and ```m22```, and a nine element array.
- ```CML_Matrix3x4```: 3x4 Matrix. This is a ```union``` of a  ```struct``` with twelve ```f64``` fields, ```m00```, ```m01```, ```m02```, ```m03```, ```m10```, ```m11```, ```m12```, ```m13```, ```m20```, ```m21```, ```m22``` and ```m23```, and a twelve element array.
- ```CML_Matrix4x2```: 4x2 Matrix. This is a ```union``` of a  ```struct``` with eight ```f64``` fields, ```m00```, ```m01```, ```m10```, ```m11```, ```m20```, ```m21```, ```m30``` and ```m31```, and a eight element array.
- ```CML_Matrix4x3```: 4x3 Matrix. This is a ```union``` of a  ```struct``` with twelve ```f64``` fields, ```m00```, ```m01```, ```m02```, ```m10```, ```m11```, ```m12```, ```m20```, ```m21```, ```m22```, ```m30```, ```m31``` and ```m32```, and a twelve element array.
- ```CML_Matrix4x4```: 4x4 Matrix. This is a ```union``` of a  ```struct``` with sixteen ```f64``` fields, ```m00```, ```m01```, ```m02```, ```m03```, ```m10```, ```m11```, ```m12```, ```m13```, ```m20```, ```m21```, ```m22```, ```m23```, ```m30```, ```m31```, ```m32``` and ```m33```, and a sixteen element array.

### Matrix Initialization

Matrices can be initiallized in two ways:

- Using the macros (```<MATRIX>``` indicates any matrix type specified above in capital letters):
  - ```CML_<MATRIX>_ZERO```: Initializes a matrix to zero.
  - ```CML_<MATRIX>_IDENTITY```: Initializes a matrix to the identity matrix.
  - ```CML_<MATRIX>_ONE```: Initializes a matrix to one.
  - ```CML_<MATRIX>(f64 m00, f64 m01, f64 m02, f64 m03, f64 m10, f64 m11, f64 m12, f64 m13, f64 m20, f64 m21, f64 m22, f64 m23, f64 m30, f64 m31, f64 m32, f64 m33)```: Initializes a matrix to the specified values. **Note**: takes only the first four values for 2x2 matrices, the first six for 2x3 and 3x2 matrices, and so on.
- Using standard initialization ```<matrix> m = {{m00, m01, m02, m03, m10, m11, m12, m13, m20, m21, m22, m23, m30, m31, m32, m33}}```: Initializes a matrix to the specified values using standard notation. **Note**: two braces are needed because of the union.

### Matrix Functions

**Note**: The functions in this module are named according to the [common convention](../../../README.md#functions): ```cmlc_<type>_<function>_<type>``` for the compiled version, and ```cml_<type>_<function>_<type>``` for the header only version. For simplicity, only the header only version will be shown here, but the compiled version is also available. ```<matrix>``` indicates any matrix type specified above, ```<vector>``` indicates any vector type specified above. In the case of taking two different matrices or a vector as input, ```<matrixmxn>``` indicates any matrix type specified above, and ```<matrixnxp>``` indicates any matrix type specified above, where ```n``` is the number of columns of the first matrix and the number of rows of the second matrix; and ```<vectorn>``` indicates any vector type specified above, where ```n``` is the number of columns of the matrix. It will be secified like this as a way to signal correct dimensions.

| Function | Description | Mathematical Notation |
| --- | --- | --- |
| ```cml_<matrix>_add(<matrix> *A, <matrix> *B, <matrix> *out)``` | Adds two matrices of the same dimension and stores the result in ```out```. | $A + B = \begin{bmatrix} a_{11} + b_{11} & a_{12} + b_{12} & \cdots & a_{1n} + b_{1n} \\ a_{21} + b_{21} & a_{22} + b_{22} & \cdots & a_{2n} + b_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{m1} + b_{m1} & a_{m2} + b_{m2} & \cdots & a_{mn} + b_{mn} \end{bmatrix}$ |
| ```cml_<matrix>_sub(<matrix> *A, <matrix> *B, <matrix> *out)``` | Subtracts two matrices of the same dimension and stores the result in ```out```. | $A - B = \begin{bmatrix} a_{11} - b_{11} & a_{12} - b_{12} & \cdots & a_{1n} - b_{1n} \\ a_{21} - b_{21} & a_{22} - b_{22} & \cdots & a_{2n} - b_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{m1} - b_{m1} & a_{m2} - b_{m2} & \cdots & a_{mn} - b_{mn} \end{bmatrix}$ |
| ```cml_<matrix>_scale(<matrix> *A, f64 t, <matrix> *out)``` | Multiplies a matrix by a scalar and stores the result in ```out```. | $A \cdot t = \begin{bmatrix} a_{11} \cdot t & a_{12} \cdot t & \cdots & a_{1n} \cdot t \\ a_{21} \cdot t & a_{22} \cdot t & \cdots & a_{2n} \cdot t \\ \vdots & \vdots & \ddots & \vdots \\ a_{m1} \cdot t & a_{m2} \cdot t & \cdots & a_{mn} \cdot t \end{bmatrix}$ |
| ```cml_<matrixmxm>_mult(<matrixmxm> *A, <matrixmxm> *B, <matrixmxm> *out)``` | Multiplies two square matrices of the same dimension and stores the result in ```out```. | $ab_{ij} = \sum_{k=1}^{n} a_{ik} \cdot b_{kj}$ |
| ```cml_<matrixmxn>_mult_<matrixnxp>(<matrixmxn> *A, <matrixnxp> *B, <matrixmxp> *out)``` | Multiplies two matrices of the correct dimensions and stores the result in ```out```. | $ab_{ij} = \sum_{k=1}^{n} a_{ik} \cdot b_{kj}$ |
| ```cml_<matrixmxn>_mult_<vectorn>(<matrixmxn> *A, <vectorn> *v, <vectorm> *out)``` | Multiplies a matrix by a vector of the correct dimensions and stores the result in ```out```. **Note**: right vector multiplication, column vector. | $Av = \begin{bmatrix} a_{11} & a_{12} & \cdots & a_{1n} \\ a_{21} & a_{22} & \cdots & a_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{m1} & a_{m2} & \cdots & a_{mn} \end{bmatrix} \cdot \begin{bmatrix} v_{1} \\ v_{2} \\ \vdots \\ v_{n} \end{bmatrix} = \begin{bmatrix} a_{11} \cdot v_{1} + a_{12} \cdot v_{2} + \cdots + a_{1n} \cdot v_{n} \\ a_{21} \cdot v_{1} + a_{22} \cdot v_{2} + \cdots + a_{2n} \cdot v_{n} \\ \vdots \\ a_{m1} \cdot v_{1} + a_{m2} \cdot v_{2} + \cdots + a_{mn} \cdot v_{n} \end{bmatrix}$ |
| ```cml_<vectorm>_mult_<matrixmxn>(<vectorm> *v, <matrixmxn> *A, <vectorn> *out)``` | Multiplies a vector by a matrix of the correct dimensions and stores the result in ```out```. **Note**: left vector multiplication, transpose of column vector -> row vector. | $v^TA = \begin{bmatrix} v_{1} & v_{2} & \cdots & v_{m} \end{bmatrix} \cdot \begin{bmatrix} a_{11} & a_{12} & \cdots & a_{1n} \\ a_{21} & a_{22} & \cdots & a_{2n} \\ \vdots & \vdots & \ddots & \vdots \\ a_{m1} & a_{m2} & \cdots & a_{mn} \end{bmatrix} = \begin{bmatrix} v_{1} \cdot a_{11} + v_{2} \cdot a_{21} + \cdots + v_{m} \cdot a_{m1} & v_{1} \cdot a_{12} + v_{2} \cdot a_{22} + \cdots + v_{m} \cdot a_{m2} & \cdots & v_{1} \cdot a_{1n} + v_{2} \cdot a_{2n} + \cdots + v_{m} \cdot a_{mn} \end{bmatrix}$ |
| ```cml_<matrixmxm>_det(<matrixmxm> *A)``` | Calculates the determinant of a square matrix and returns it. | $\lvert A \rvert = \sum_{i=1}^{n} (-1)^{i+j} \cdot a_{ij} \cdot \lvert A_{ij} \rvert$ |
| ```cml_<matrixmxm>_inv(<matrixmxm> *A, <matrixmxm> *out)``` | Calculates the inverse of a square matrix and stores it in ```out```. If the matrix is singular, it returns a singular matrix error. | $A^{-1} = \frac{1}{\lvert A \rvert} \cdot adj(A)$ |
| ```cml_<matrixmxn>_transpose(<matrixmxn> *A, <matrixnxm> *out)``` | Calculates the transpose of matrix and stores it in ```out```. | $A^{T} = \begin{bmatrix} a_{11} & a_{21} & \cdots & a_{m1} \\ a_{12} & a_{22} & \cdots & a_{m2} \\ \vdots & \vdots & \ddots & \vdots \\ a_{1n} & a_{2n} & \cdots & a_{mn} \end{bmatrix}$ |
| ```cml_<matrixmxm>trace(<matrixmxm> *A)``` | Calculates the trace of a square matrix and returns it. | $tr(A) = \sum_{i=1}^{n} a_{ii}$ |
| ```cml_<matrix>_eq(<matrix> *A, <matrix> *B)``` | Checks if two matrices are equal and returns ```CML_True``` if they are, ```CML_False``` otherwise. | $A = B$ |

[↑ Back to Top](#fixed-size-linear-algebra)\
[← Back to Main Documentation Index](../../../README.md)\
[← Back to Algebra Overview](../algebra.md)
