# To-Do

## Documentation

## Expressions

Make the parser notation agnostic: it will be defined in a notation configuration file, and ship the library with some presets.

Like with strings, make a funxction to make temporary expressions so for example, a user can do cml_expression_solve(cml_expression_temp(cml_string_temp("f(g(x))^f(x)")), ...) to do things to temporary expressions, where g(x) and f(x) would have to be predefined.

For expression evaluation functions, take in a matrix (vectors of input variables, 1x1 if only one, alphabetioc order for more?) and return a matrix (1x1 for scalars, etc for matrices and vectors). Make some way to set some variables and other not, for example, for y = 1, get f(x) = x from f(x, y) = xy.

Before creating an expression have the user define any symbol (non number/operation) that is used within the expression. Incorporate latex symbols (maybe also custom operations defined by a function expression? For example, if convolution wasnt defined from the beginning, \ast could be predefined as \ast(f,g) = \int_{-\infty}^infty f(n)h(-n-k)dk, and then any expression with \ast would use this as the operation) and let the user set flags, like is it a variable, a function, a matrix, a parameter, a set, etc. Also, if something has a subiondex which is another symbol (for ex t_k), it must also be defined as such (for example, n for series, a_n); this could also be useful to access matrix elements>; then, by using an evaluation function and setting a value to that parameter, the expression could be evaluated for for ex k=3. Also be able to set constraints, mainly for parameters, like the type of variable (\in \mathbb{R}, \mathbb{C}, \mathbb{Z}) or its range (<= 5). Then, internally in a DArray, all symbols are stored (no duplicates allowed, for that use number subindices (a_1, a_2, a_k, a_j), but letter subindices must also be unique for a symbol) and when expressions use them, they just reference a specific element of the DArray so only one instance of that symbol is needed, saving memory. Store how many expressions use a symbol, and if the user wants to delete one, it must not be in use (refCount = 0).

When a mathematical object is created (something through an expression, or maybe even numerical objects, like matricwes) it is stored internally in the library, keeping track of all of them. If it is created with a name, like f(x) = x² or S = {1,2,3}, that name is used, if not, a random one is used (stored as something like u64). All are unique, and this way, through expressions the libary can ideantify already created objects, like creating an expression like g(x) = f(x)² (or f²) would use the preexistent f, and not set it to a variable. This could be optional, like if you want to use it, then the user must run cml_init() or something, and things could be stored in a CML_Darray. The array would always be NULL (global variable) unless the user runs cml_init(), in which case it gets initialized. Then, functions can have something like if (array) to check if the feature wants to be used.

Basic camel type: Matrix (1x1 for scalars, 1xn or nx1 for vectors (must be transposed if needed), nxm for matrices). The init function will take size, and type (CML_NumericType), and will initialize it to 0 (maybe make different init functions (identity, etc.)). 

Change exptkn_copy to use string copy instead of init.
Create lm function (analogous to that of R), and have a print function for it that prints the same info as R (optional to do the hypothesis tests). Do lm with option to choose algorithm (least sqiares, etc.).
Create the variance, covariance, mean, etc. functions that take a DArray.
Create a dataset type that holds a 2d Darray (DArray of DArrays), and a darray with a new CML_Type type, where it specifies the type of each column, as well as some info like, factor, discrete, numeric, etc.

