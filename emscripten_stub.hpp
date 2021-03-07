#ifdef __EMSCRIPTEN__
#include "emscripten.h"
#define LIBRARY_EXTERN extern "C" EMSCRIPTEN_KEEPALIVE
#else
#define LIBRARY_EXTERN extern
#endif
