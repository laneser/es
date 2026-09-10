#include <../goomay.h>

inherit OBJECT;

void create()
{
	set_name( "crystal of ice", "萬年冰晶" );
	add( "id", ({ "crystal","ice" }) );
	set_short( "萬年冰晶" );
	set_long(
		"這是一顆罕見的萬年冰晶，是火焰精靈的剋星，要使用它\n"
		"，用 ice <someone>。\n"
	);
	set( "unit", "顆" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "do_ice", "ice" );
}

int do_ice(string arg)
{
	object obj;

	if( !arg || arg=="" || !(obj= present(arg, environment(this_player()))) )
		return notify_fail( "要對誰使用冰晶？\n" );
	if( base_name(obj) != Mob"fire_beast" ) {
		write(
			"你拿出冰晶打在" + obj->query("short") + "的身上，不過對方似乎不受影響。\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+ "拿出一顆小石頭打在"+obj->query("short")+"身上。\n",
			this_player() );
		return 1;
	} else {
		write( 
			"你拿出冰晶打在" + obj->query("short") + "身上 .... \n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+ "拿出一顆冰晶打在"+obj->query("short")+"身上。\n",
			this_player() );
		obj->iced();
		write( 
			"你的冰晶飛了出去，緊緊貼在" + obj->query("short") + "身上！\n");
		remove();
		return 1;
	}
}
