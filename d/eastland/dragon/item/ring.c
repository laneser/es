#include "../../layuter.h"
inherit ARMOR;

void create()
{
        set_name("occult ring", "神秘戒指");
        add( "id", ({ "ring" }) );
        set_short("神秘戒指");
        set_long(
                "這是以龍人族特有的咒術施以神秘的金屬上製成的戒指。\n"
        );
	set("unit","只");
        set( "type", "finger" );
        set( "material" ,"light_metal" );
        set( "armor_class", 0 );
        set( "defense_bonus", 7 );
	set("special_defense",(["fire" :3,"cold":3,"divine":-4]));
        set( "weight", 20 );
        set( "value", ({ 500, "gold" }) );
}