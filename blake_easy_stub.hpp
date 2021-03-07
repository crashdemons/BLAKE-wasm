
#include "blake224.hpp"
#include "blake256.hpp"
#include "blake384.hpp"
#include "blake512.hpp"
#include <cstdlib>


typedef struct blake_state_easy{
	unsigned int bitlength;
	void* internal_state;
} blake_state_easy;


LIBRARY_EXTERN blake_state_easy* blake_init_easy(unsigned int d);

LIBRARY_EXTERN void blake_update_easy(blake_state_easy* ctx, const uint8_t *in, uint64_t inlen);

LIBRARY_EXTERN void blake_final_easy(blake_state_easy* ctx, uint8_t *out);

LIBRARY_EXTERN void blake_cleanup_easy(blake_state_easy* ctx);

LIBRARY_EXTERN int version();

