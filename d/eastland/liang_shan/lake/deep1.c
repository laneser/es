#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short("湖中");
	set_long( @C_LONG_DESCRIPTION
這裡是湖中的深水區域，除了打魚的魚夫偶而會來到此處外，一般的冒險者由
於游泳技術不佳，很少來到此處。形形色色的魚兒，因為沒有人為的干擾，正在水
中快樂的游來游去。
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"down" : TROOM"underwater1", 
		"south" : TROOM"shallow21",
		"east" : TROOM"deep2" ]) );
	set( "pre_exit_func",([
	        "east":"check_deep",
	        "south":"check_shallow"
	        ]));
	set( "objects",([
	        "fish": TMONSTER"fish1"]));
	reset();
}
int check_deep()
{    
    if ((int)this_player()->query_skill("swimming")-random(15)<40){
    write (
    "你努力地想要游到別處，但是身子卻不聽使喚的向下沉去.......\n");
    this_player()->move_player(TROOM"underwater1","SNEAK");
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
