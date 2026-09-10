#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "Emerald ring", "綠玉戒指" );
	add( "id", ({ "ring" }) );
	set_short( "a emerald ring", "綠玉戒指" );
	set_long(
		"You see a beautiful emerald ring.\n",
		"這是一個很漂亮的綠玉戒指，好像有一種奇特的魔力。\n"
	);
	set( "type", "finger" );
	set("material","element");
	set("defense_bonus",2);
	set( "weight", 5 );
	set( "value", ({ 210, "silver" }) );
        set("extra_skills",(["trading":15,]));
	
}
