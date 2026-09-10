#include <mudlib.h>

inherit "/d/thief/hall/study" ;
inherit ROOM;

void create()
{
	::create();
    set_short("詭計研究中心");
	set_long( @LONG_DESCRIPTION
這裡是小偷們互相交換詭計和騙術的地方，不少小偷都以能夠將自己的點子
留在這裡為榮，你在這裡可以學習(study)其他小偷所留下來的聰明點子，在你
的前方桌上有一本巨大的書，你可以先從書上的目錄(catalog)找起。
PS. 目前尚未開放學習。
LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_func", ([
 		"catalog": "view_catalog" ]) );
	set( "exits", ([ 
		"north" : "/d/thief/hall/thief_guild" ]) );
	set_tricks( ([
		"set-fire"   	 : ({ "trick", 20, 4, 20, 100 }),
		"shut-up"		 : ({ "trick", 35, 3, 10, 150 }),
		"bag-bag"    	 : ({ "trick", 60, 4, 10, 200 }),
		"not-me" 	     : ({ "trick", 15, 4, 10, 100 }),
		"throw-dagger"   : ({ "trick", 15, 6,  5, 100 })
	]) );
	
	reset();
}

