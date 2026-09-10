#include "../layuter.h"

inherit ROOM;

void create()
{   
    object lord;

	::create();
	set_short("王屋");
	set_long( @LONG_DESCRIPTION
  這裡是一個樹洞房間，有一張巨大的石椅放在屋子的北邊，上面刻滿
  天馬圖樣，而地面鋪著漂亮的錦織地毯使整個房間看起來高貴異常，
  屋頂有一巨大的飾燈，由此發出的光線照亮整個房間。
LONG_DESCRIPTION
	);

	lord=new( "/d/noden/elf/monster/lord" );
	lord->move( this_object() );

	set( "light", 1 );
	set( "exits", ([
		"south" :LELF"elf32"
	]) );
	reset();	
}

int clean_up() { return 0; }
