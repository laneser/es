#include <takeda.h>

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
		"west" : TROOM"whirl2",
		"north" : TROOM"shallow6",
		"south" : TROOM"shallow14" ]) );
	set( "pre_exit_func",([
	        "west":"check_whirl",
	        "north":"check_shallow",
	        "south":"check_shallow"
	        ]));
	reset();
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
 int check_whirl()
 {
   int n;
   string place;
   write (
   "突然間，你發現你正遊向一個大漩渦，強勁的水流不斷的把你扯向漩渦中心。\n"
   "你不斷的掙扎...................................\n\n\n\n"
   "你終於精疲力盡，隨著漩渦捲入水底，死亡的陰影頓時佔據了你的心靈.....\n");
   switch (n=random(3) ){
   case 0: place = "whirl1"; break;
   case 1: place = "whirl2"; break;
   case 2: place = "whirl3"; break;
   }
   this_player()->move_player( TROOM+place,"SNEAK");
   return 1;
 }
