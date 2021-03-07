#include "blake.hpp"
LIBRARY_EXTERN void blake224_init( state224 *S );
LIBRARY_EXTERN void blake224_update( state224 *S, const uint8_t *in, uint64_t inlen );
LIBRARY_EXTERN void blake224_final( state224 *S, uint8_t *out );

