#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("snake herb","蛇窩草");
    add("id",({"herb"}) );
    set_short("蛇窩草");
    set_long(
@C_LONG
    這是生長在蛇窩旁邊的一種奇特小草，看起來有一點像韓國草，
據說在黑暗精靈族中，有人能將這種小草和某些藥材混合，製成一種
藥粉，灑在村落四周，能防止毒蛇的侵入。
C_LONG
            );
    set("unit","束");
    set("weight",18); 
    set("value", ({ 20, "silver" }));
    set( "no_sale",1); 
}    
