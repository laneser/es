#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(3);
    set_name("Daemon student","魔族學生");
    add("id",({"daemon","student"}) );
    set_short("魔族學生");
    set_long(@LONG
一個魔族的小男孩，發現你在看他，趁先生不注意的時候把墨汁甩向你臉上！
LONG
            );
    set("unit","個");
    set("alignment",-50);
    set("gender","male");
    set("race","daemon");
    set("weight",200);
    set_perm_stat("str",5);
    set_natural_weapon(2,2,5);
    set_natural_armor(15,0);
    set("wealth/silver",10);
}    
