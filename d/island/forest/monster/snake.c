#include "../tsunami.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(3);
    set_name("Big Snake","大蟒蛇");
    add("id",({"snake"}) );
    set_short("大蟒蛇");
    set_long(@LONG
一尾頗嚇人的大蟒蛇正盤踞在山洞旁的樹枝上，發現你的到來，正
不斷的對著你吐著蛇信，好像在偵查你似的!!
LONG
    );
    set("unit","尾");
    set("no_attack",1);
}