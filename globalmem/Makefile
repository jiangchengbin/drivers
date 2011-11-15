#   Makefile for modules
#   #

mod_SRCS=globalmem.c
mod_OBJS=$(mod_SRCS:.c=.o)


ifneq ($(KERNELRELEASE),)
    obj-m:=$(mod_OBJS)
else
    KERNELDIR:=/lib/modules/$(shell uname -r)/build
    PWD:=$(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
endif

clean:
	@rm -f *.mod.c *.mod.o *.o *.order *.symvers
