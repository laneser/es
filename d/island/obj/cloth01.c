#include "../island.h"

inherit ARMOR;

void create()
{
    set_name("Hai-nen pallium","六祖袈裟");
    add("id",({"cloth","pallium"}) );
    set_short("@@color");
	set_long(@C_LONG
由六祖傳下來的袈裟，雖然年代久遠，但是仍然不顯陳舊的樣子，由於經過
歷代繼承高僧的加持，使得這件袈裟具有神聖的防護力。 ( Odin,Inc )	
C_LONG
	);
	set( "unit", "件" );
	set( "weight", 80 );
	set( "type", "body" );
	set( "armor_class", 36 );
        set("material","cloth");
        set("special_defense",(["evil" : 10,
                                "fire" : 30,
                               "mental": 30,
                                "acid" : -10
                                           ]));
	set( "defense_bonus", 10 );
	set( "value", ({ 1200, "silver" }) );
	set( "no_sale", 1 );
	
}
string color()
  { return set_color("六祖袈裟","HIC"); } 