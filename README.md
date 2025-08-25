# CVEC

**basic** <generic> dynamic array in C

## what is provided
CVEC_STRUCT(elem_type, struct_name) // implements the struct
CVEC_APPEND(v, n) // macro to append
CVEC_FREE(v) // you know this one
CVEC_NEW(elem_type, struct_name) // implements "new"
CVEC_IMPL_DA_APPEND(elem_type, struct_name) // implements "append"
CVEC_IMPL_DA(elem_type, struct_name) // implements the struct, "new" and "append"
CVEC_DA_AT(vec, i) // access items, python style
CVEC_DA_LAST(vec) // shorthand 

### Example
see main.c

### NOTE
- it works but it's just an experiment
- surely there are blind corners that are waiting to bite back


