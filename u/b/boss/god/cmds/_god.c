#include "../god.h"

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
用法 : god message
這個指令用來同目前線上的魔神通信。

參考: god
HELP
              );
        return 1;
}
