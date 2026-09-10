#include "takeda.h"
inherit ARMOR;

void create()
{
        set_name("green hood", "渾青抓角頭巾");
        add( "id", ({ "hood" }) );
        set_short("渾青抓角頭巾");
        set_long(
                "這是一頂綠油油的頭巾，如果你不介意的話，這倒是非凡的防具． \n"
        );
        set("unit","頂");
        set( "type", "head" );
        set( "material", "cloth");
        set( "armor_class", 7 );
        set( "defense_bonus", 5 );
        set( "special_defense",
               ([ "fire":4, "cold":-5, "mental":2 ]) );
        set( "weight", 50 );
		set( "equip_func","equip_hood");
        set( "value", ({ 466, "gold" }) );
        set( "extra_look", "$N戴著一頂綠油油的頭巾，看來十分可愛。\n" );

}
void equip_hood()
{
object holder;
    holder=this_player();
    tell_room(environment(holder),
    holder->query("c_name")+"小心翼翼的套上一頂綠油油的頭巾.......\n"
    ,({holder}));
    tell_object(holder,
    "你小心翼翼的套上這頂綠油油的頭巾.........\n");
	return ;
}


