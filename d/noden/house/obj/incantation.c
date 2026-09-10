#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "incantation of exorcise", "驅魔咒" );
	add( "id", ({ "incantation" }) );
	set_short( "驅魔咒" );
	set_long(
		"這張驅魔咒是一張黃色的紙，上面畫滿彎彎曲曲的線條和符號，要使用\n"
		"驅魔咒，用 zap <someone>。\n"
	);
	set( "unit", "張" );
	set( "weight", 5 );
	set( "value", ({ 100, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "do_zap", "zap" );
}

int do_zap(string arg)
{
	object obj;

	if( !arg || arg=="" || !(obj= present(arg, environment(this_player()))) )
		return notify_fail( "要對誰使用驅魔咒？\n");
	if( base_name(obj) != "/d/noden/house/monster/devil" ) {
		write( 
			"你拿出驅魔咒在" + obj->query("short") + "面前揮舞，不過對方似乎不受影響。\n");

		tell_room( environment(this_player()), 
			this_player()->query("c_cap_name")+ "拿出一張黃色符咒在"+obj->query("short")+"面前揮舞。\n",
			this_player() );
		return 1;
	} else {
		write("你拿出驅魔咒在" + obj->query("short") + "面前揮舞 .... \n");
		tell_room( environment(this_player()), 
			this_player()->query("c_cap_name")+ "拿出一張黃色符咒在"+obj->query("short")+"面前揮舞。\n",
			this_player() );
		obj->zapped();
		write("你的驅魔咒突然自己飛了出去，緊緊貼在" + obj->query("short") + "身上！\n");
		remove();
		return 1;
	}
}
