#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "fire gloves", "火焰手套" );
	add( "id", ({ "gloves" }) );
	set_short( "a fire gloves", "火焰手套" );
	set_long(
		"You see a pair of red gloves with strange magic.\n",
		"這是一雙紅色的手套，據說它是火神的最愛，戴上它，火神都會對你容情三分。\n"
	);
	set( "unit", "雙" );
	set( "type", "hands" );
	set( "weight", 40 );
	set( "no_sale",1);
        set("material","light_metal");
	set( "armor_class", -5 );
        set( "defense_bonus", 2 );
	set("special_defense",(["electric":30 ]));
	set("extra_stats",(["str":-1,"dex":-2,"con":-2 ])); 
	set("extra_skills",(["blunt":10]));

	set( "value", ({ 240, "silver" }) );
}
