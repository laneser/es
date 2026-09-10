#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("holy ring","愛染明王戒指");
    add("id",({"ring"}) );
    set_short( "愛染明王戒指");
	set_long(@C_LONG
這是五大明王之一 — 愛染明王使用過的戒指,如果你是善良
正義之士, 它將以明王之名加護你的。
C_LONG
       	        );
	set( "unit", "個" );
	set( "weight", 12 );
	set( "type", "finger" );
	set( "material","stone");
	set( "armor_class", 0 );
	set( "defense_bonus", 7 );
	set( "value", ({ 300, "gold" }) );
}
