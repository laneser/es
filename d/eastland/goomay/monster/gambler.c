
#include "mudlib.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(5);
        set_name( "gambler", "賭棍" );
        set_short( "賭棍");
        set("unit","位");
        set_long(
@C_LONG
你看到一個猥瑣的漢子，他約莫三四十來歲，可是看起來卻更老，營養不良
的臉上還留著睡眠不足的痕跡，此刻他正全神貫注地和一堆人大賭特賭，根
本沒有注意到你的存在。
C_LONG
);
        set("alignment",-450);
        set("wealth/silver",15);
        set_perm_stat("str",12);
        set_perm_stat("dex",10);
        set_perm_stat("kar",9); 
        set_natural_weapon(5,5,11);
        set ("natural_armor_class", 25);
        set_skill("parry",65);
        set("natural_defense_bonus",5);
        set ("gender", "male");
        set ("race", "halfling");
#include <replace_mob.h>
}
