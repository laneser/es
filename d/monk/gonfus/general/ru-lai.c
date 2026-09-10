#include <mudlib.h>

#define MARTIAL_NAME    "monk/general/ru_lai"
#define D_MARTIAL_NAME    "monk/general/d_ru_lai"
#define GONFU_NAME      "ru-lai"

inherit DAEMON;

int eungon(object me, int level)
{
        
        if( (object)me->query("weapon1") ) {
                tell_object(me, 
                        "你裝備了不適合的武器。\n");
                return 0;
        }

        tell_object(me, 
                "\n你全身沐浴在佛光之中，準備使出「"+
                to_chinese(GONFU_NAME)+"」!!\n" );

        tell_room( environment(me), 
                me->query("c_name")+
                "全身散發出一股極平靜的氣息，但其中似乎又包含一股山雨欲來風滿樓的殺氣，難道他準備使出"+to_chinese(GONFU_NAME)+"? \n", me);

        me->set("attack_skill", MARTIAL_NAME); 
        me->set_temp("gonfu_busy",1);
        call_out("release_gonfu", 30+level, me);
        return 1;
}

void release_gonfu(object me)
{
        if( !me ) return;
        tell_object(me, 
                "\n\n你吸了一口氣, 停止使用"+to_chinese(GONFU_NAME)+"。\n" );
 
        tell_room( environment(me),
                me->query("c_name")+
                "輕輕的吐出一口氣，收式而立。\n", me);
 
        me->delete("attack_skill");
        me->delete_temp("gonfu_busy");
}
