#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("stone of snake's eye","蛇眼之石");
    add("id",({"stone"}) );
    set_short("蛇眼之石");
    set_long(
@C_LONG
與其說這是一顆石頭，不如說這是像是一顆蛇的眼睛，它隨時都
閃爍著一股異樣的藍光，可能有什麼特殊的作用。　　
C_LONG
            );
    set("unit","顆");
    set("weight",25); 
    set("value", ({ 200, "silver" }));
    set( "no_sale",1); 
}    
