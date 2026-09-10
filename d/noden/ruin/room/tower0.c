// tower0.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("魔術師塔．入口");
    set_long(@C_LONG
這裡是魔術師塔的入口，四周堆滿著各種生物的骷髏，肅殺詭秘的氣氛令
人毛骨悚然。魔術師塔的大門旁立著塊石碑，上面寫著：「路痴和菜鳥不準進
入」。
C_LONG
	    );

    set("exits", (["north" : AREA"tower1"]));
    reset();
}

void init()
{
    add_action("to_search", "search");
}

int to_search(string arg)
{
    object p;
   
    p = this_player(); 
    write("你找呀找地，忽然地面上裂開了一個大洞 .... 哇～～～\n");
    p->move(AREA"tower2");
    p->receive_damage(5);
    return 1;
}

