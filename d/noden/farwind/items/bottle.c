#include <mudlib.h>

inherit WEAPON;

int breaked;

void create()
{
	set_name( "wine bottle", "酒瓶" );
	add( "id", ({ "bottle" }) );
	set_short( "酒瓶" );
	set_long(@CLONG
這是一個....呃....酒瓶子，裡面早已喝得一滴也不剩，瓶裡
還有一堆噁心的唾沫，趁早把這垃圾給丟了吧。
CLONG
	);
	set( "weight", 30 );
	set( "value", ({ 3, "silver" }) );
	set( "useless", 1 );
	breaked = 0;
}

void init()
{
	add_action( "break_bottle", "break" );
}

int break_bottle(string arg)
{
	if( breaked ) return 0;

	if( !arg || !id(arg) )
		return notify_fail("打破什麼？\n");
	breaked = 1;
	write( 
		"你將酒瓶摔在地上，嗯....看起來這半截酒瓶似乎可以當成武器？\n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name") + "把一個酒瓶摔在地上，破成兩截。\n",
		this_player() );
	set( "type", "dagger" );
	set( "weapon_class", 7 );
	set( "min_damage", 3 );
	set( "max_damage", 7 );
	set_name( "broken wine bottle", "破酒瓶" );
	add( "id", ({ "broken bottle" }) );
	set_short( "破酒瓶" );
	return 1;
}

