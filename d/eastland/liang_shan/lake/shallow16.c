#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short("湖邊");
	set_long( @C_LONG_DESCRIPTION
這裡是湖中的淺水區域，水並不算深，大約只到腰際，就算不游泳也不必擔心
會有危險，也因此你才能好好欣賞到這大湖的景色。湖水一望無際，煙波浩瀚，幾 
只白鷺閒閒飛越水畔，在目力難及之處，似乎有群山相繞，但由於湖上的煙霞，看
得不是很清楚。
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"east" : TROOM"shallow17",
		"north" : TROOM"deep7",
		"west" : TROOM"shallow15" ]) );
	set( "pre_exit_func",([
	        "east":"check_shallow",
	        "north":"check_deep",
	        "west":"check_shallow"
	        ]));
	reset();
}
int check_deep()
{    
    if ((int)this_player()->query_skill("swimming")-random(15)<40){
    write (
    "你努力地想要游到別處，但是身子卻不聽使喚的向下沉去.......\n");
    this_player()->move_player(TROOM"underwater7","SNEAK");
  return 1;
  }
    else return 0;
}
int check_shallow()
{
    if ((int)this_player()->query_skill("swimming")-random(5)<13){
    write (
    "你努力的想游到別處，但你發現身體一動也不動.....\n");
  return 1;
    }
    else return 0;
}
