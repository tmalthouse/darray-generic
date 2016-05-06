# darray-generic
A type-generic, dynamic array (similar to C++'s vectors or Java's ArrayList), written in C using some macro trickery

### To install:
Move the `darray.h` file to wherever you keep your headers (the included `install.h` moves it to /usr/local/include/) 

### To use:

1. Create two files in your project directory. Call them something like `darray_types.c` and `darray_types.h` and set up include guards in the header file.
2. `#include<darray.h>` in both files
3. For each type you want to use in a Darray, add `darray_type(TYPENAME)` to `darray_types.c` and `darray_type_header(TYPENAME)` to `darray_types.h`.
4. `#include"darray_types.h"` in every file where you need the dynamic arrays.

### Functions:

`Darray_TYPE *new_darray_TYPE (int initial_count)`
--Allocates and returns a pointer to a new darray that holds the specified type (Remember to define that type of array, as specified in step 3 above).

`int darray_set_TYPE (Darray_TYPE *arr, T data, int index)`
--Sets element `index` to the value of `data`. Returns 0 if the assignment is successful, and -1 if the index is out of bounds.

`int darray_append_TYPE (Darray_TYPE *arr, T data)`
--Adds `data` to the end of the array, expanding if neccessary. Returns -1 if expansion fails.

`void free_darray_##T (Darray_##T *arr)`
--Frees the memory used by `arr`. It's important to use this function instead of calling `free(arr)` so that the internal buffer is freed as well.

###Example use:

File `darray_types.h`
`
\#ifndef EXAMPLE_H
\#define EXAMPLE_H

\#include<darray.h>

darray_type_header(uint16_t);//Creates function headers for a uint16_t Darray
\#endif
`

File `darray_types.c`
`
\#include<darray.h>
\#include"darray_types.h"

darray_type(uint16_t);

Darray_uint16_t *ptr = new_darray_uint16_t(20);

darray_append_uint16_t(ptr, 30);

darray_free_uint16_t();
`
