
#include <org.h>////#pragma save_binary

// _levels.c
// This command lists experience required for each level.
// By Annihilator 11-04-93

#include <stats.h>
#include <daemons.h>

int cmd_orglv(string arg)
{
        int i;
        object guild;
        string *c_titles;
     seteuid(getuid());
	if(this_player()->query("level")<1)
		return notify_fail("你沒有加入任何組織!\n");
     guild = (object)GUILD_MASTER ( (string)this_player()->query("organization") );
        c_titles = (string *)guild->query_c_titles();

        for( i=1; i<=MAX_ORG_LEVEL; i++ ) {
                write( 
                        sprintf( "等級 %2d : %30-s %8d 點經驗\n", i, c_titles[i-1], NEW_GUILD->query_org_exp(i-1) ) 
                );
        }
        return 1;
}

int help()
{
                write( @C_HELP
指令格式: levels

這個指令會列出一份你加入的組織等級及各需多少經驗值的列表。
C_HELP
                );
        return 1;
}
