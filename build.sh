rm -rf blake-wasm-dist
mkdir blake-wasm-dist

BIN="blake224.cpp blake256.cpp blake384.cpp blake512.cpp"

#W_FLAGS="-O3 -flto -DNDEBUG"
W_FLAGS="-O0 -g -v -s ASSERTIONS=1 -s DISABLE_EXCEPTION_CATCHING=0 --memoryprofiler"
echo $W_FLAGS
echo $BIN
emcc $W_FLAGS -s MODULARIZE=1 -s "EXPORTED_FUNCTIONS=['_malloc','_free']" -s 'EXPORT_NAME="createBlakeModule"' -s WASM=1 -s EXTRA_EXPORTED_RUNTIME_METHODS='["cwrap"]' $BIN blake_easy_stub.cpp -o dist/blake.js


cat dist/blake.js wrapper/wrapper.js > dist/blake-wrapped.js




