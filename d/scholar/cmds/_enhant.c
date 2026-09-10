//#pragma save_binary

#include <mudlib.h>

#define SCHOLAR_GONFU_DIR "/d/scholar/gonfus/"

inherit DAEMON;

int help();

string *gonfus = ({ "force-heal", "couples_sword", "mar_short", "booyi",
                    "tanlo", "unknow", "han", "song", "tang" , "poem"});

int cmd_enhant(string str)
{
/*
        string *gonfus = ({ "force-heal", "couples_sword", "mar_short",
                            "booyi", "tanlo", "unknow", "han", "song",
                            "tang" , "poem"});
*/
        int level;
        object me, code;

        if( !str ) return help();
        me = this_player();

        if( str == "stop" ) {
                write( 
                        "你停止運用任何武功\。\n");
                me->delete("attack_skill");
                me->delete("defense_skill");
                return 1;
        }

        if( member_array(str, gonfus) == -1 )
                return notify_fail("疑! 這是那一種功夫 ? \n");

        if( (int)me->query("stop_attack")>0 )
                return notify_fail (
                        "( 你上一個動作還沒有完成，無法施展招式。 )\n");

        if( me->query("gonfu_busy") || me->query_temp("gonfu_busy") )
        return notify_fail("你目前正運功所以無法另外運用其它武功\。\n");

        if( me->query_temp("stop_enhant") || me->query("stop_enhant") )
                return notify_fail("你正準備使用招式時，竟然發現你突然功力全失了。\n");
        
        if( undefinedp(level=(int)me->query("scholar_gonfu/"+str)) )
                return notify_fail("疑! 你會這種功夫 ? \n");

        code = find_object_or_load(SCHOLAR_GONFU_DIR+str);
        if( !code )
                return notify_fail("沒有這種功夫! 請通知巫師或用 bug 指令報告招式名稱。\n");

        code->enhant(me, level);
        return 1;
}

int help()
{
                write( @C_HELP
指令格式: enhant <招式名稱>

這個指令讓你用來施展招式。你可以用 gonfus 指令看你目前已經學會的招式列表。
C_HELP
                );
    return 1;
}
