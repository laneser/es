#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Daemon girl student","魔族女學生");
    add("id",({"daemon","girl","student"}) );
    set_short("魔族女學生");
    set_long(@LONG
一個魔族的小女孩，似乎無視於你的存在，專心的聽著先生講課。
LONG
            );
    set("unit","個");
    set("alignment",-50);
    set("gender","female");
    set("race","daemon");
    set("weight",150);
    set_perm_stat("dex",6);
    set_natural_weapon(3,3,5);
    set_natural_armor(20,0);
    set("wealth/silver",20);
}    
