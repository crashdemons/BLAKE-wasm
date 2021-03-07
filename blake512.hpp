#include "blake.hpp"
LIBRARY_EXTERN void blake512_init( state512 *S );
LIBRARY_EXTERN void blake512_update( state512 *S, const uint8_t *in, uint64_t inlen );
LIBRARY_EXTERN void blake512_final( state512 *S, uint8_t *out );



