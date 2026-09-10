#include <mudlib.h>

inherit OBJECT;

void create()
{
    set_name("captain's seal","侍衛隊長徽章");
    add("id",({"seal"}));
    set_short("侍衛隊長徽章");
    set_long(
@C_LONG
這是一枚侍衛隊長的徽章，用銅片及碎寶石鑲成，代表的是勇氣與
無比的信心。
C_LONG
            );
    set("unit","枚");
    set("weight",20);
    set("value", ({ 100, "silver" }));
    set( "no_sale",1);
}                                 
