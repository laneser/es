// translation done. -Elon 03-10-94
#include "../moyada.h"
inherit ROOM;

void create()
{
	::create() ;
	set_short( "洞穴" );
	set_long( @C_LONG
十分陰暗的洞穴, 向北延伸, 不知通往何處。四處顯得潮溼, 有種陰森森
的感覺, 你恨不得趕緊離開這裡。
C_LONG
	);
	
	set( "exits", ([ 
	   "south" : MOYADA"shop/cellar",
	   "north" : MOYADA"shop/strange_room",
	]) );
	set( "pre_exit_func", ([
	  "south" : "to_cellar",
	]) );
	set( "objects", ([
	  "small_bat#1" : MOYADA"monster/bat",
	  "small_bat#2" : MOYADA"monster/bat",
	  "small_bat#3" : MOYADA"monster/bat",
	  "small_bat#4" : MOYADA"monster/bat",
	  "small_bat#5" : MOYADA"monster/bat",
	  "small_bat#6" : MOYADA"monster/bat",
	  "small_bat#7" : MOYADA"monster/bat",
	  "small_bat#8" : MOYADA"monster/bat",
	  "bats_king#1" : MOYADA"monster/large_bat",
	  "bats_king#2" : MOYADA"monster/large_bat",
	]) );
	reset();
}

int to_cellar()
{
    if( MOYADA"shop/cellar"->query("move") ) 
      return 0;
    write( "出口好像被甚麼東西擋住了, 出不去. \n" );
    return 1;
}
