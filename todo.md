# To-Do

## Optimization

Test just like mult, the rest of the matrix operation (probably add and add_inplace are enough since the rest are the same but with other operations. Also with div, since division is slower).

## Priority

When a mathematical object is created (something through an expression, or maybe even numerical objects, like matricwes) it is stored internally in the library, keeping track of all of them. If it is created with a name, like f(x) = x² or S = {1,2,3}, that name is used, if not, a random one is used (stored as something like u64). All are unique, and this way, through expressions the libary can ideantify already created objects, like creating an expression like g(x) = f(x)² (or f²) would use the preexistent f, and not set it to a variable. This could be optional, like if you want to use it, then the user must run cml_init() or something, and things could be stored in a CML_Darray. The array would always be NULL (global variable) unless the user runs cml_init(), in which case it gets initialized. Then, functions can have something like if (array) to check if the feature wants to be used.

Maybe make it so if a matrix function receives no allocator (NULL), then it means the out matrix is already initialized, in that case, check size and type ...

Basic camel type: Matrix (1x1 for scalars, 1xn or nx1 for vectors (must be transposed if needed), nxm for matrices). The init function will take size, and type (CML_NumericType), and will initialize it to 0 (maybe make different init functions (identity, etc.)). 

Change exptkn_copy to use string copy instead of init.
Create lm function (analogous to that of R), and have a print function for it that prints the same info as R (optional to do the hypothesis tests). Do lm with option to choose algorithm (least sqiares, etc.).
Create the variance, covariance, mean, etc. functions that take a DArray.
Create a dataset type that holds a 2d Darray (DArray of DArrays), and a darray with a new CML_Type type, where it specifies the type of each column, as well as some info like, factor, discrete, numeric, etc.

- [ ] At some point, make latex manual for camel.
- [ ] Have two functions to calculate roots of polynomials, a standard 100% accurate one (slow) and an approximation one using the Newton method (fast).
- [ ] Add `CML_Allocator`, and make all the functions that require memory allocation to take one as a parameter.
- [ ] For the dstructs debug and eq functions, take eq and print functions for the elements.
- [ ] Change any function that returns a copy of an object to just return a pointer to the object, like `cml_darray_get`. Also, for functions that take objects, intead of making a copy (copying the pointers inside, so not really deep copyig) just use the input object, like in `cml_exptkn_init`.`
- [ ] Make a new library for visualization (graphs, charts, etc.). Like `svisual` but following the same naming style and conventions as Camel (animals, 3 letter prefixes, etc.).
- [ ] Make the following data structures:
  - [ ] ```CML_Queue``` - A queue.
  - [ ] ```CML_PriorityQueue``` - A priority queue.
  - [ ] ```CML_HashMap``` - A hash map.
  - [ ] ```CML_HashSet``` - A hash set.WW
  - [ ] ```CML_BSTree``` - A binary search tree.
  - [ ] ```CML_RBTree``` - A red black tree.
  - [ ] ```CML_AVLTree``` - An AVL tree.
  - [ ] ```CML_Trie``` - A trie.
  - [ ] ```CML_Graph``` - A graph.
  - [ ] Other more advanced or less common data structures, and others that require very complex algorithms for learning purposes.
- [ ] Create the same data structures but holding `CML_Element`, which would have `void *data`, `stride`, so the data structures can hold elements of different types, sort of like python.
- [ ] Maybe make the freeing functions take double pointers to also free the pointer itself (maybe pass as double pointer and take a bool to specify if the pointer should be freed or not).

## Documentation

- [ ] Explain in documentation that debug functions return c strings because they are intended to be printed directly to the console.

## Functions

- [ ] Add ```<matrix>``` eigenvalue and eigenvector functions, and ```<matrix>``` diagonalization functions:
  - [ ] ```cml_<matrix>_eigenvalues(<matrix> *A, <vector> *out)``` - Calculates the eigenvalues of ```A``` and stores them in ```out```.
  - [ ] ```cml_<matrix>_eigenvectors(<matrix> *A, <matrix> *out)``` - Calculates the eigenvectors of ```A``` and stores them in ```out```.
  - [ ] ```cml_<matrix>_eigendecomposition(<matrix> *A, <matrix> *V, <matrix> *D)``` - Calculates the eigenvalue decomposition ($A = VDV^T$) of ```A``` and stores them in ```V``` and ```D```.
  - [ ] ```cml_<matrix>_lu(<matrix> *A, <matrix> *L, <matrix> *U)``` - Calculates the LU decomposition ($A = LU$)of ```A``` and stores it in ```L``` and ```U```.
  - [ ] ```cml_<matrix>_qr(<matrix> *A, <matrix> *Q, <matrix> *R)``` - Calculates the QR decomposition ($A = QR$) of ```A``` and stores it in ```Q``` and ```R```.
  - [ ] ```cml_<matrix>_cholesky(<matrix> *A, <matrix> *U)``` - Calculates the Cholesky decomposition ($A = U^\dag U$) of ```A``` and stores it in ```U```.
  - [ ] ```cml_<matrix>_svd(<matrix> *A, <matrix> *U, <matrix> *S, <matrix> *V)``` - Calculates the SVD decomposition ($A = USV^T$) of ```A``` and stores it in ```U```, ```S```, and ```V```.
  - [ ] ```cml_<matrix>_schur(<matrix> *A, <matrix> *Q, <matrix> *U)``` - Calculates the Schur decomposition ($A = QUQ^{-1}$) of ```A``` and stores it in ```Q``` and ```U```.
- [ ] Add ```<matrix>``` transformations for square matrices:
  - [ ] ```cml_<matrix>_gen_scale(f32 x, f32 y, f32 z, <matrix> *out)``` - Generates a scaling matrix and stores it in ```out```.
  - [ ] ```cml_<matrix>_gen_invscale(<matrix> *scale, <matrix> *out)``` - Generates an inverse scaling matrix and stores it in ```out```.
  - [ ] ```cml_<matrix>_gen_shearx(f32 x, <matrix> *out)``` - Generates a shearing matrix along the x axis and stores it in ```out```.
  - [ ] ```cml_<matrix>_gen_shearx(f32 y, <matrix> *out)``` - Generates a shearing matrix along the y axis and stores it in ```out```.
  - [ ] ```cml_<matrix>_gen_shearx(f32 z, <matrix> *out)``` - Generates a shearing matrix along the z axis and stores it in ```out```.
  - [ ] ```cml_<matrix>_gen_invshear(<matrix> *shear, <matrix> *out)``` - Generates an inverse shearing matrix and stores it in ```out```.
  - [ ] ```cml_<matrix>_gen_translation(f32 x, f32 y, f32 z, <matrix> *out)``` - Generates a matrix and stores it in ```out```.
  - [ ] ```cml_<matrix>_gen_invtranslation(<matrix> *translation, <matrix> *out)``` - Generates an inverse translation matrix and stores it in ```out```.
  - [ ] ```cml_<matrix>_genlh_rotation(<vector> *axis, f32 angle,  <matrix> *out)``` - Generates a left handed rotation matrix along an axis and stores it in ```out```.
  - [ ] ```cml_<matrix>_genrh_rotation(<vector> *axis, f32 angle, <matrix> *out)``` - Generates a right handed rotation matrix along an axis and stores it in ```out```.
  - [ ] ```cml_<matrix>_gen_invrotation(<matrix> *rotation, <matrix> *out)``` - Generates an inverse rotation matrix and stores it in ```out```.
  - [ ] ```cml_<matrix>_genlh_lookat(<vector> *eye, <vector> *target, <vector> *up, <matrix> *out)``` - Generates a left handed look at matrix and stores it in ```out```.
  - [ ] ```cml_<matrix>_genrh_lookat(<vector> *eye, <vector> *target, <vector> *up, <matrix> *out)``` - Generates a right handed look at matrix and stores it in ```out```.
  - [ ] ```cml_<matrix>_gen_invlookat(<matrix> *lookat, <matrix> *out)``` - Generates an inverse look at matrix and stores it in ```out```.
  - [ ] ```cml_<matrix>_genlh_perspectiveno(f32 fov, f32 aspect, f32 near, f32 far, <matrix> *out)``` - Generates a left handed perspective matrix using the negtive one convention [-1,1] and stores it in ```out```.
  - [ ] ```cml_<matrix>_genlh_perspectivezo(f32 fov, f32 aspect, f32 near, f32 far, <matrix> *out)``` - Generates a left handed perspective matrix using the zero one convention [0,1] and stores it in ```out```.
  - [ ] ```cml_<matrix>_genrh_perspectiveno(f32 fov, f32 aspect, f32 near, f32 far, <matrix> *out)``` - Generates a right handed perspective matrix using the negtive one convention [-1,1] and stores it in ```out```.
  - [ ] ```cml_<matrix>_genrh_perspectivezo(f32 fov, f32 aspect, f32 near, f32 far, <matrix> *out)``` - Generates a right handed perspective matrix using the zero one convention [0,1] and stores it in ```out```.
  - [ ] ```cml_<matrix>_genlh_invperspective(<matrix> *perspective, <matrix> *out)``` - Generates a left handed inverse perspective matrix and stores it in ```out```.
  - [ ] ```cml_<matrix>_genrh_invperspective(<matrix> *perspective, <matrix> *out)``` - Generates a right handed inverse perspective matrix and stores it in ```out```.
  - [ ] ```cml_<matrix>_genlh_orthono(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far, <matrix> *out)``` - Generates a left handed orthographic matrix using the negtive one convention [-1,1] and stores it in ```out```.
  - [ ] ```cml_<matrix>_genlh_orthozo(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far, <matrix> *out)``` - Generates a left handed orthographic matrix using the zero one convention [0,1] and stores it in ```out```.
  - [ ] ```cml_<matrix>_genrh_orthono(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far, <matrix> *out)``` - Generates a right handed orthographic matrix using the negtive one convention [-1,1] and stores it in ```out```.
  - [ ] ```cml_<matrix>_genrh_orthozo(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far, <matrix> *out)``` - Generates a right handed orthographic matrix using the zero one convention [0,1] and stores it in ```out```.
  - [ ] ```cml_<matrix>_gen_invortho(<matrix> *orthographic, <matrix> *out)``` - Generates a left handed inverse orthographic matrix and stores it in ```out```.
  - [ ] ```cml_<matrix>_genlh_frustumno(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far, <matrix> *out)``` - Generates a left handed frustum matrix using the negtive one convention [-1,1] and stores it in ```out```.
  - [ ] ```cml_<matrix>_genlh_frustumzo(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far, <matrix> *out)``` - Generates a left handed frustum matrix using the zero one convention [0,1] and stores it in ```out```.
  - [ ] ```cml_<matrix>_genrh_frustumno(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far, <matrix> *out)``` - Generates a right handed frustum matrix using the negtive one convention [-1,1] and stores it in ```out```.
  - [ ] ```cml_<matrix>_genrh_frustumzo(f32 left, f32 right, f32 bottom, f32 top, f32 near, f32 far, <matrix> *out)``` - Generates a right handed frustum matrix using the zero one convention [0,1] and stores it in ```out```.
  - [ ] ```cml_<matrix>_gen_invfrustum(<matrix> *frustum, <matrix> *out)``` - Generates a left handed inverse frustum matrix and stores it in ```out```.
- [ ] Add SIMD support for fixed size linear algebra operations. This will be done through extra functions with prefixes like ```cml_avx_function```, ```cml_sse_function```, ```cml_neon_function```, etc. The functions will be implemented in the ```fmatrix_avx.h```, ```fmatrix_sse.h```, ```fmatrix_neon.```, etc. for header only versions, and ```fcmatrix_avx.h/c```, ```fcmatrix_sse.h/c```, ```fcmatrix_neon.h/c```, etc. for compiled versions. The library will detect the platform and the available SIMD intrinsics, and only let you use the functions that are available for your platform. For example, if you are on a platform that supports AVX, you will be able to use the ```cml_avx_function``` functions, but not the ```cml_sse_function``` or ```cml_neon_function``` functions.
- [ ] Test the matrices for OpenGL and Vulkan compatibility (i.e. row major vs column major).
- [ ] Once all vector and matrix operations are implemented, add the same for doubles, i.e. ```CML_Vector2``` -> ```CML_Vector2d```, ```CML_Vector3``` -> ```CML_Vector3d```, ```CML_Vector4``` -> ```CML_Vector4d```, ```CML_Matrix2x2``` -> ```CML_Matrix2x2d```, ```CML_Matrix3x3``` -> ```CML_Matrix3x3d```, ```CML_Matrix4x4``` -> ```CML_Matrix4x4d```, etc.
- [ ] Have a look at maybe offering a fortran interface, like ```cml_f90_function``` or f99 depending on if I use a specific fortran standard or not.
- [ ] Add a ```CML_Quaternion``` type.
- [ ] Separate all function implementations into separate files, like ```cmlc_vector2_add.c```, ```cmlc_vector2_add_f32.c```, etc. like glibc does.

## Investigate

- [ ] Investigate the possibility of using ```__builtin_cpu_supports``` to detect the available SIMD instructions.
- [ ] Investigate _BigInt(N).
