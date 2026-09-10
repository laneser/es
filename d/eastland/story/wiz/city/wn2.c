#include "../../story.h"
#include "../../magic.c"
#include <conditions.h>
inherit ROOM;

void create()
{
        ::create();
	set_short("北大街");
	set_long( @LONG
你走正走在「巫咸城」內北大街上，大街往東邊方向延伸，南邊則是西大街。
西大街由這裡一轉已變成為地處偏僻的北大街，往來無塵囂，街旁樹木稀稀落落於
房子間，空氣清新，顯的格外幽雅脫俗，街道內相當安靜，是為居住之地。路旁另
有一口枯井和一棵大榕樹約七、八抱寬，其分枝繁葉已延伸達二十四尺直徑方圓，
老幼皆喜來此乘涼嬉戲，為北大街另添一殊。
LONG
	);
        set("light",1);
	set( "exits", ([ 
           "south" : SCITY"wn1",
            "east" : SCITY"nw2",
        ]) );
        set("objects", ([
            "boy#1" : SWMOB"boy2",
            "boy#2" : SWMOB"boy2",
            "girl1" : SWMOB"girl2",
            "girl2" : SWMOB"girl2",
            "older" : SWMOB"older1",
        ]) );
	reset();
}
void init()
{
   add_action("do_search","search");
   add_action("do_jump","jump");
}
int do_search(string arg)
{
    write(@LONG
你發現了一口枯井(well)，深不見底，你最好不要□試跳下去(jump)，以免
發生危險。  
LONG
   );    
   return 1;
}
int do_jump(string arg)
{
   object player;
   if ( !arg || arg!="well" ) {
      write("Snytax:<jump well>。\n");
      return 1;
   }
   player=this_player();
   tell_object(player,"你衝動地往井裡跳下去！\n\n\n\n\n\n\n");
   player->move_player(SCITY"well1",({
            "%s不顧一切地往井裡一跳！\n",
            "%s從上面跳下來。\n"}),"");
   tell_object(player,"唉呀，你不小心地被井邊牆壁突出的石塊給割傷，流血不止！\n");                     
   (CONDITION_PREFIX + "bleeding")->apply_effect(player,20,2 );
   return 1;           
}