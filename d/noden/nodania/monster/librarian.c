#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(7);
	set_name( "librarian", "圖書館員" );
	set_short( "圖書館員" );
	set_long(@CLONG
這位看起來很斯文秀氣的小姐就是諾達尼亞大圖書館的圖書館員，你如
果想找什麼書，只要問(ask)她所要找尋的主題，她就會幫你找書。
CLONG
	);
	set( "no_attack", 1 );
	set( "gender", "female" );
	set( "race", "elf" );
	set( "inquiry", ([
		"ALL_TOPIC" : "@@seek_book"
	]) );
}

void seek_book( object player )
{
	tell_object( player,
		"圖書館員對你說道: 很抱歉，最近圖書館正在整修，暫停借書....。\n"
	);
}
