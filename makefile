CC=clang++
CFLAGS= -Wall
BIN  =  blake_easy_stub.o blake224 blake256 blake384 blake512

all:			$(BIN)
			@echo "Checking test vectors"	
			./blake224
			./blake256
			./blake384
			./blake512

clean:
			rm -f $(BIN) 

dist:			clean
			cd ..; \
			tar zcf BLAKE-`date +%Y%m%d%H%M`.tgz BLAKE/*


