#include "type.h"
#include "stdio.h"
#include "const.h"
#include "protect.h"
#include "string.h"
#include "fs.h"
#include "proc.h"
#include "tty.h"
#include "console.h"
#include "global.h"
#include "proto.h"

/*****************************************************************************
 *                                mkdir
 *****************************************************************************/
/**
 * create a dir.
 * 
 * 
 * 
 * 
 * 
 *****************************************************************************/
PUBLIC int mkdir(const char *pathname)
{
	MESSAGE msg;

	msg.type	= MKDIR;

	msg.PATHNAME	= (void*)pathname;
	msg.FLAGS	= 0;
	msg.NAME_LEN	= strlen(pathname);

	send_recv(BOTH, TASK_FS, &msg);
	assert(msg.type == SYSCALL_RET);

	return msg.FD;
}
