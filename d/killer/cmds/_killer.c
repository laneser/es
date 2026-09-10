#include "../killer.h"

inherit DAEMON;

int cmd_killer(string arg)
{
        seteuid(getuid());
        ORG_OBJ->guild_line(arg);
        return 1;
}

int help()
{
        write( @HELP
用法 : killer message
這個指令用來同目前線上的殺手通信。

參考: killer
HELP
              );
        return 1;
}
