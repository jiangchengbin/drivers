#include <linux/module.h>
#include <linux/types.h>
#include <linux/fs.h>
#include <linux/errno.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/cdev.h>
#include <asm/io.h>
#include <asm/system.h>
#include <asm/uaccess.h>

#define GLOBALMEM_SIZE 0x1000
#define MEM_CLEAR 0x1
#define GLOBALMEM_MAJOR 254

static globalmem_major=GLOBALMEM_MAJOR;

struct globalmem_dev
{

	struct cdev cdev;
	unsigned char mem[GLOBALMEM_SIZE);
}

strcut globalmem_dev dev;

int globalmem_init(void)
{
	int result;
	dev_t devno=MKDEV(globalmem_major,0);
	
	if ( globalmem_major)
	{
		result=register_chrdev_region(devno,1,"globalmem");
	}
	else
	{
		result=alloc_chrdev_region(&devno,0,1,"globalmem");
		globalmem_major=MAJOR(devno);
	}
	
	if (result < 0)
		return result;
	
	globalmem_setup_cdev();
	return 0;
}

void globalmem
