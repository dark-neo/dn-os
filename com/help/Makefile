
# Makefile
# dark_neo
# 2014-08-24

ASCOM		= nasm
INCLDIR		= -I ../../incl
ASFLAGS		= -f bin 
BIN_NAME	= ./help.com
OUTDIR		= ../../out

all: $(BIN_NAME)

$(BIN_NAME):
	$(ASCOM) $(INCLDIR) $(ASFLAGS) -o $(BIN_NAME) *.asm
	mv 	-v	$(BIN_NAME)	$(OUTDIR)

