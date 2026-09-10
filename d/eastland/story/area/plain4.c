#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("草原");
	set_long(@LONG
你來到了一處空曠的草原，西和南邊是草原的延伸，北邊是大樹群。在草原上
長滿了些小小的矮花，矮花的顏色很鮮□，靠近一聞，鼻子中滿是濃郁的香味。除
此之外，一群野蜂正悠哉悠哉地穿梭在花叢間，恣意地採著蜂蜜。你東邊是一面千
仞高的山壁，上面突出來大大小小的巖塊如疊格子般一層層的井然有序，與其說這
山壁是經由石頭堆積起來的！巖塊間有許多裂縫，你試了試發現其大小正足可以容
納一隻腳的體積，如果你攀爬技術純熟，或許可以籍此登上( climb )。
LONG
	);
	set("light",1);
	set("exits", ([ 
            "west" : SAREA"plain3",
           "south" : SAREA"plain2",
        ]) );
	reset();
}
void init()
{
   add_action("do_climb", "climb" );
}
int do_climb()
{    
   int climb_skill;
   object player;
   string name;
   player=this_player();
   name=player->query("c_name");
   climb_skill = (int)player->query_skill("climbing");
   if( random(climb_skill) < 20 ) {
      write("\n\n雖然你使勁了全身的力量卻一個不小心踩錯地方跌了下去！\n\n");
      tell_room(this_object(),sprintf(
         "%s踩著石縫想往上爬，結果失敗跌了下來。\n",name),player);
      player->receive_damage(20);
      return 1;
   }
   write("\n你頭也不回氣也不喘地專心往上爬去．．\n\n\n\n\n\n");
   player->move_player(SAREA"mountain1",({
        "%s費力地往上爬去。\n",
        "%s從下面爬了上來。\n"}),"");
   return 1;                   
}