/*************************************************************************//**
 *****************************************************************************
 * @file   ls.c
 * @brief  ls
 * @author Sweet
 * @date   2015
 *****************************************************************************
 *****************************************************************************/

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
 *                                ls
 *****************************************************************************/
/**
 * Write to a file descriptor.
 *
 *****************************************************************************/
PUBLIC int ls(char *pathname)
{
    MESSAGE msg;
    msg.type = LS;


	msg.PATHNAME	= (void*)pathname;
	msg.FLAGS	= 0;
	msg.NAME_LEN	= strlen(pathname);

    send_recv(BOTH, TASK_FS, &msg);

    return msg.RETVAL;
}
