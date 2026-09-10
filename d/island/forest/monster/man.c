#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(6);
    set_name("Daemon man","魔族壯丁");
    add("id",({"man","daemon"}) );
    set_short("魔族壯丁");
    set_long(@LONG
這壯丁身材魁梧，熊腰虎背，豹頭燕頸；你心中不禁一凜：難道魔族的男性都
像他這樣嗎？
LONG
            );
    set("unit","個");
    set("gender","male");
    set("race","daemon");
    set("alignment",-300);
    set_perm_stat("str",8);
    set("wealth/silver",150);
    set_natural_weapon(6,7,12);
    set_natural_armor(30,0);
    set("weight",700);
}
