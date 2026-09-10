#include "goomay.h"

inherit ROOM;

int ice;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "內殿" );
        set_long(
@LONG
你走進至陽觀的內殿，這裡是至陽道人清修的地方，一縷縷的清煙
嫋嫋從獸爐中噴出，顯得十分寧靜，正堂上供奉著三清祖師的畫像，牆
上掛著一把七星寶劍，此刻殿內闃無一人，沒事最好趕快離開，免得被
人誤認為樑上君子。
LONG
        );
        
        set( "exits", ([ 
		"south" : Goomay"doshu_temple",
        ]) );
	set("search_desc",([
	"here":"@@to_search_here",]) );
        ice=0;
        reset();
}
void reset()
{
   ::reset();
   ice=0;
}

string to_search_here()
{
   object ob1;
   this_player()->set_explore("eastland#9");
   switch(ice) {
   case 0 :
	ice=1;
        new(Mob"doshu" )->move(this_object() );
	return "";
   case 1:
	if (present("master daoist",this_object() ) || present("daoist",this_object() ))
	return "那道人大喝道：「你這無法無天的小偷，現在還想偷東西嗎？」\n";
	ice=2;
	ob1=new(Obj"crystal_ice");
	ob1->move(this_player());
	return "你仔細的翻箱倒櫃，最後發現了一塊萬年冰晶。\n";
   case 2:
	return "在一陣仔細的搜索下，再也找不到有趣的東西了。\n";
     }
}
