//#pragma save_binary

#include <mudlib.h>

#define MONK_GONFU_DIR "/d/monk/gonfus/"

inherit DAEMON;

int help();

int cmd_eungon(string str)
{
        string *fist = ({ "sh_fist", "tb_fist", "long_fist", "ro_han",
                "drunk_fist", "fu_hu", "wei_to", "ho_fist" });
        string *heals = ({ "bi-du", "gun-in", "lun-chi", "pu-ty", });
        string *cures = ({ "bi-du",  "lun-chi",  });
        string *gonfus = ({ "bolo-mi", "chu-han", "fu-mo", "gi-mei", "tai-zuo",
                "wu-sur", "body-def", "bolo-fist", "dragon-claw", "keep-flower",
                "da-mo","power-finger","ru-lai","king-kong", "burn-blade","fon-mo"});
        int level, heal;
        object code, me;

        if( !str ) return help();

        me = this_player();
        if( (int)me->query("stop_attack")>0 )
                return notify_fail ("( 你上一個動作還沒有完成，無法施展招式。 )\n");
        if( me->query_temp("stop_eungon") || me->query("stop_eungon") )
                        return notify_fail("你正準備使用招式時，竟然發現你突然功力全失了。\n");

        if( member_array(str, fist) != -1 )
                return notify_fail("基礎拳法可用 fist 指令使用, 不須運功。\n");

        if( member_array(str, heals) != -1 ) heal = 1;
        else if( member_array(str, gonfus) != -1 ) heal = 0;
        else return notify_fail("疑! 這是那一種功夫?\n");

        if( (heal && member_array(str, me->query("monk_gonfu/heal"))==-1) ||
                (!heal && undefinedp(level=(int)me->query("monk_gonfu/"+str))) )
                return notify_fail("疑! 你會這種功夫?\n");

        if ( (!heal) && 
             ( me->query("gonfu_busy") || me->query_temp("gonfu_busy") )  
           )
        if ( !me->query_temp("gonfu_top") )
        return notify_fail("你目前正運功所以無法另外運用其它武功。\n");
        code = find_object_or_load(MONK_GONFU_DIR+(heal?"heal/":"general/")+str);
        if( !code )
                return notify_fail("沒有這種功夫! 請通知巫師或用 bug 指令報告招式名稱。\n");
        if( me->query_temp("gonfu_top") ) {
           me->delete("attack_skill");
           me->delete("defense_skill");
           }
        code->eungon(me, level);
        return 1;
}

int help()
{
                write( @C_HELP
指令格式: eungon <招式名稱>

這個指令讓你用來施展招式。你可以用 gonfus 指令看你目前已經學會的招式列表。
C_HELP
                );
    return 1;
}
