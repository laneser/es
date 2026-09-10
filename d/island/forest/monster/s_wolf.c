#include "../tsunami.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Little wolf","小野狼");
    add("id",({"wolf"}) );
    set_short("小野狼");
    set_long(@LONG
這是一隻小野狼，仔細一看，還真是討人喜歡呢！它看到你進來，似乎對你蠻感興趣
的，不斷的搖著尾巴，好像要你和它玩耍呢！
LONG
            );
    set("unit","只");
    set("alignment",-100);
    set("weight",100);            
    set_natural_weapon(5,5,10);
    set_natural_armor(10,5);
    set_c_verbs( ({"%s奮力撲向%s","%s努力咬向%s"}) );
    set_c_limbs( ({"頭部","身體","屁股","尾巴"}) );
}