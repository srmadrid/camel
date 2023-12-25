# Camel

Camel is a C mathematics library, which aims to provide a simple and easy to use API for a wide array of mathematical operations. It is written in C99, and is cross-platform. It is currently in development, so it is not recommended to use it in production. It is licensed under the MIT license.

## Table of Contents   
- [Features](#features)
- [Installation](#installation)
- [Compile](#compile)
- [Usage](#usage)
- [To-Do](#to-do)


## Features
The library is structured in modules, each module centered around a specific mathematical branch. The modules are:
- [Core](doc/core/core.md)
    - [Arbitrary Precision Arithmetic](doc/core/bignum.md)
    - [Data Structures](doc/core/dstructs.md)
    - [Expression Parsing](doc/core/expression.md)
- [Algebra](doc/algebra/algebra.md)
    - [Linear Algebra](doc/algebra/linear/linear.md)
        - [Fixed Size Linear Algebra](doc/algebra/linear/flinear.md)
        - [Variable Size Linear Algebra](doc/algebra/linear/vlinear.md)
    - [Abstract Algebra](doc/algebra/abstract.md)
- [Calculus](doc/calculus/calculus.md)
- [Geometry](doc/geometry/geometry.md)
- [Number Theory](doc/numtheory/numtheory.md)
- [Statistics](doc/statistics/statistics.md)


## Compile

To compile the project, run ```make``` in the root directory of the project. This will create a ```camel``` shared library in the root directory of the project. It will automatically detect the platform and compile the appropriate version of the library, so in linux it will compile the ```camel.so``` library and in windows it will compile the ```camel.dll``` library. To compile the tests, first make sure to have compiled the library beforehand, then run ```make test``` in the root directory of the project. This will create a ```test``` executable in the test directory of the project. It will automatically detect the platform and compile the appropriate version of the executable, so in linux it will compile the ```test``` executable and in windows it will compile the ```test.exe``` executable. To clean the project, run ```make clean``` in the root directory of the project. This will remove the ```camel``` shared library (keep in mind, if you delete the shared library the ```test``` executable won't run). To clean the tests, run ```make clean-test``` in the root directory of the project. This will remove the ```test``` executable. To clean the project and the tests, run ```make clean-all``` in the root directory of the project. This will remove the ```camel``` shared library and the ```test``` executable.


## Usage

### Matrices
Vectors are represented as row vectors inside matrices.

### Testing module

To use the testing module first create a file that within the ```main``` function will run all the tests. After that:
- [1] Create a ```CML_Test``` object which will hold all testing functions (testing registry), a uint ```test_count``` which will hold the number of tests, and a uint ```expected_count``` which will hold the number of tests you want to execute (make sure they are enough). Finally execute the ```cml_test_init``` function with the ```CML_Test``` object as the first argument, the ```test_count``` as the second argument, and the ```expected_count``` as the third argument to initialize the array that will hold the testing functions.
- [2] In a different file, or the same one, begin creating the testing functions. Each testing function must return a ```CML_TestResult``` object, which holds the result of the test (```CML_Bool```: ```CML_TRUE``` or ```CML_FALSE```) and a debug message of the test in case it fails (if it doesn't fail, it is not necessary to fill this field).
- [3] Once all the testing functions are created, you have to register them into the registry created in [1]. To do this, use the ```cml_test_register``` function with the ```CML_Test``` object as the first argument, the ```test_count``` as the second argument, the testing function as the third argument, and the name of the test as the fourth argument. If you have tests in different files, it is suggested that you create "envelope" functions that register all of the testing functions of the file, and in the main file using that "envelope" function to register all the tests.
- [4] Finally, in the ```main``` function, execute the ```cml_test_run``` function with the ```CML_Test``` object as the first argument, and the ```test_count``` as the second argument. This will run all the tests and print the results.

For a complete example, explore the ```test``` directory, where you will find all the official tests. Here are some of the important files:
- [1] ```mtest.c```: Here you will find the ```main``` function that runs all the tests, as well as all the setup.


## To-Do

- [ ] Create documentation
- [ ] Create examples
