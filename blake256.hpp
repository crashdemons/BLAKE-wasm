#include "blake.hpp"
LIBRARY_EXTERN void blake256_init( state256 *S );
LIBRARY_EXTERN void blake256_update( state256 *S, const uint8_t *in, uint64_t inlen );
LIBRARY_EXTERN void blake256_final( state256 *S, uint8_t *out );



