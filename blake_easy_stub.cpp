#include "blake_easy_stub.hpp"

#include <iostream>
/*
void* mallocz(size_t size){
	void* p = malloc(size);
	memset(p, 0, size);
	return p;
}
*/
blake_state_easy* blake_init_easy(unsigned int digestBits){
	blake_state_easy* ctx = (blake_state_easy*) malloc(sizeof(blake_state_easy));
	ctx->bitlength = digestBits;
	switch(ctx->bitlength){
		case 224:
			ctx->internal_state = malloc(sizeof(state224));
			blake224_init((state224*) ctx->internal_state);
			break;
		case 256:
			ctx->internal_state = malloc(sizeof(state256));
			blake256_init((state256*) ctx->internal_state);
			break;
		case 384:
			ctx->internal_state = malloc(sizeof(state384));
			blake384_init((state384*) ctx->internal_state);
			break;
		case 512:
		default:
			ctx->bitlength = 512;//if it wasn't already set to this
			ctx->internal_state = malloc(sizeof(state512));
			blake512_init((state512*) ctx->internal_state);
			break;
	}
//	std::cout<<"init-easy "<< (ctx) << " " << (ctx->bitlength) << " " << (ctx->internal_state) <<std::endl;
	return ctx;
}
void blake_update_easy(blake_state_easy* ctx, const uint8_t *in, uint64_t inlen){
//	std::cout<<"update-easy "<< ctx <<" "<< (ctx->bitlength) << " " << in << " " << inlen <<std::endl;
	switch(ctx->bitlength){
		case 224:
			return blake224_update((state224*)ctx->internal_state,in,inlen);
		case 256:
			return blake256_update((state256*)ctx->internal_state,in,inlen);
		case 384:
			return blake384_update((state384*)ctx->internal_state,in,inlen);
		case 512:
			return blake512_update((state512*)ctx->internal_state,in,inlen);
	}
}
void blake_final_easy(blake_state_easy* ctx, uint8_t *out){
//	std::cout<<"final-easy "<< ctx <<" "<< (ctx->bitlength)<< " " << out <<std::endl;
	switch(ctx->bitlength){
		case 224:
			return blake224_final((state224*)ctx->internal_state,out);
		case 256:
			return blake256_final((state256*)ctx->internal_state,out);
		case 384:
			return blake384_final((state384*)ctx->internal_state,out);
		case 512:
			return blake512_final((state512*)ctx->internal_state,out);
	}
}

void blake_cleanup_easy(blake_state_easy* ctx){
//	std::cout<<"cleanup-easy "<< ctx <<" "<< (ctx->bitlength) <<std::endl;
	free(ctx->internal_state);
	free(ctx);
}

int version(){
    return 2021030604;
}
