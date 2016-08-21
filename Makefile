
# Makefile
# dark_neo
# 2014-08-22

ASCOM 		= nasm
ASFLAGS		= -f bin
GZIPCOM		= gzip
OUTDIR		= ./out

#########################################################################
#			ABOUT KERNEL IMAGE NAME				#
# The filesystem where the kernel is stored is a FAT filesystem, so the #
# name MUST FOLLOW the FAT 11 bytes structure for filenames:		#
#              8 bytes for filename + 3 bytes for file extension 	#
# 						separed by dot (.) 	#
#########################################################################
KERNEL_NAME	= dnoskrnl
KERNEL_VERSION	= 0.0.2pre-alpha
SCRIPT_NAME	= ./requis.bsh

all: help

do-all: build build-kernel
#do-all: build

build:  $(KERNEL_NAME)

do-iso:	| $(OUTDIR)			# $(OUTDIR) target must exists.
	$(SCRIPT_NAME) $(OUTDIR) $(KERNEL_NAME).gz $(KERNEL_VERSION) \
				$(OUTDIR)/$(KERNEL_NAME).gz

$(OUTDIR):
	mkdir -p $(OUTDIR)

build-kernel: | $(OUTDIR)
	$(info )
	$(MAKE) -C com
	$(info )
	$(info Compressing image file...)
	$(GZIPCOM)	$(OUTDIR)/$(KERNEL_NAME)
	#mv $(OUTDIR)/$(KERNEL_NAME).gz $(OUTDIR)/schos-kernel.gz
	$(info Done!)

$(KERNEL_NAME): | $(OUTDIR)
	$(info )
	$(info Creating object files...)
	$(ASCOM) 	$(ASFLAGS)	-o $(OUTDIR)/$(KERNEL_NAME) *.asm
	$(info Done!)

clean:
	$(info )
	$(info Cleaning source tree...)
	rm -fr $(OUTDIR)

help:
	$(info )
	$(info * COMPILE OPTIONS *)
	$(info -------------------)
	$(info )
	$(info help(default): Show this text and finish)
	$(info do-all:        Build sources and create a compressed kernel)
	$(info image file)
	$(info )
	$(info do-iso:        Create ISO. do-all action required previously)
	$(info )
	$(info build:         Build sources but do not create kernel image)
	$(info build-kernel:  Create and compress kernel image file)
	$(info clean:         Delete 'out' directory)
	$(info )
	$(info )

