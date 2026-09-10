#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("wedding suit","白色新娘禮服");
        add("id",({"suit"}) );
   set_short( "白色新娘禮服");
	set_long(
"這是一件白色的新娘禮服，純白的顏色代表純潔無暇的愛情。\n"
	);
	set( "unit", "件" );
	set("material","cloth");
	set( "weight", 150 );
	set( "type", "body" );
	set( "armor_class", 28 );
	set( "defense_bonus", 5 );
   set( "wedding_obj", 1 );
	set("no_sale",1);
   set( "value", ({ 3500, "silver" }) );
   set( "extra_stats", ([ "dex": -2 ]) );
}

stop_equip(object owner)
{
        if ( (string)this_player()->query("gender") != "female") {
        printf(
                  "別開玩笑了, 你想當人妖嗎?\n" );
        return 1;
        }
}
