
# Fixed Size Linear Algebra

This module deals with fixed size vectors and matrices, up to 4x4 (for variable size vectors and matrices, see [Variable Size Linear Algebra](vlinear.md)). This module is optimized for speed, and is offered as header only or compiled, to give the user maximum flexibility and performance; for this same reason, the functions in this module are not generic, and only work with the types specified below and do not check for errors (except for matrix inversion, where invertibility is checked beforehand), if the inputs are correctly allocated they will work as expected, but if they are not, the behavior is undefined.

**Module Location**: ```include/algebra/linear/flinear/flinear.h```

**Usage Options:** Header only or compiled.

## Table of Contents

- [Vectors](#vectors)
- [Matrices](#matrices)

## Vectors

Vectors represent a point in space, or a direction. This module includes vectors of size 2, 3 and 4.

### File Locations

- Header only: ```include/algebra/linear/flinear/fvector.h```
- Compiled: ```include/algebra/linear/flinear/cfvector.h``` and ```src/algebra/linear/flinear/cfvector.c```

### Types

- ```CML_Vector2```: 2D Vector. This is a ```union``` of a  ```struct``` with two ```f64``` fields, ```x``` and ```y```, and a two element array.
- ```CML_Vector3```: 3D Vector. This is a ```union``` of a  ```struct``` with three ```f64``` fields, ```x```, ```y``` and ```z```, and a three element array.
- ```CML_Vector4```: 4D Vector. This is a ```union``` of a  ```struct``` with four ```f64``` fields, ```x```, ```y```, ```z``` and ```w```, and a four element array.

### Functions

**Note**: The functions in this module are named according to the [common convention](../../../README.md#functions): ```cmlc_<type>_<function>_<type>``` for the compiled version, and ```cml_<type>_<function>_<type>``` for the header only version. For simplicity, only the header only version will be shown here, but the compiled version is also available. ```<vector>``` indicates any vector type specified above.

| Function | Description | Mathematical Notation |
| --- | --- | --- |
| ```cml_<vector>_add(<vector> *v, <vector> *w, <vector> *out)``` | Adds two vectors of the same dimension, stores the result in ```out``` and returns a status code. | $\vec{v} + \vec{w} = \begin{bmatrix} v_{1} + w_{1} \\ v_{2} + w_{2} \\ \vdots \\ v_{n} + w_{n}\end{bmatrix}$ |
| ```cml_<vector>_sub(<vector> *v, <vector> *w, <vector> *out)``` | Subtracts two vectors of the same dimension, stores the result in ```out``` and returns a status code. | $\vec{v} + \vec{w} = \begin{bmatrix} v_{1} - w_{1} \\ v_{2} - w_{2} \\ \vdots \\ v_{n} - w_{n}\end{bmatrix}$ |
| ```cml_<vector>_scale(<vector> *v, f64 t, <vector> *out)``` | Multiplies a vector by a scalar, stores the result in ```out``` and returns a status code. | $\vec{v} \cdot t = \begin{bmatrix} v_{1} \cdot t \\ v_{2} \cdot t \\ \vdots \\ v_{n} \cdot t\end{bmatrix}$ |
| ```cml_<vector>_mod(<vector> *v)``` | Calculates the modulus of the input vector and returns it. | $\lvert\lvert\vec{v}\rvert\rvert = \sqrt{\sum_{i=1}^{n} {v}_{i}^{2}}$ |
| ```cml_<vector>_mod(<vector> *v)``` | Calculates the squared modulus of the input vector and returns it. | $\lvert\lvert\vec{v}\rvert\rvert^{2} = \sum_{i=1}^{n} {v}_{i}^{2}$ |
| ```cml_<vector>_norm(<vector> *v, <vector> *out)``` | Calculates the normalized vector of the input vector, stores it in ```out``` and returns a status code. | $\hat{v} = \frac{\vec{v}}{\lvert\lvert\vec{v}\rvert\rvert}$ |

## Matrices

[↑ Back to Top](#fixed-size-linear-algebra)\
[← Back to Main Documentation Index](../../../README.md)\
[← Back to Algebra Overview](../algebra.md)
