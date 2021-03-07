#include "blake.hpp"
LIBRARY_EXTERN void blake384_init( state384 *S );
LIBRARY_EXTERN void blake384_update( state384 *S, const uint8_t *in, uint64_t inlen );
LIBRARY_EXTERN void blake384_final( state384 *S, uint8_t *out );



