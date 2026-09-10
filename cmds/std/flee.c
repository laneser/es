// _flee.c
// Elon@ES 4-22-95

#include <mudlib.h>

inherit DAEMON;

int cmd_flee()
{
	write("直接跑就好了!!!!!!!\n");
	return 1;
}

int help()
{
	write(@TEXT
flee - 沒用的指令.
TEXT
	);
}
