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
		"down" : TROOM"underwater8", 
		"south" : TROOM"whirl3"]));
	set( "objects", ([
	        "fishman" : TMONSTER"two"
	        ]));
	set( "pre_exit_func",([
	        "south":"check_whirl"
	        ]));
	reset();
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
