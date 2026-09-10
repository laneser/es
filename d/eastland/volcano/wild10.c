#include "oldcat.h"

inherit ROOM;
int be_search;
void create()
{
	::create();
	set_short("草地");
	set_long( 
@LONG_DESCRIPTION
這裡沒有明顯的路給你走，你站在一大片草地中間，草地呈黃綠色，每當有風吹
過，所有的草就隨風左右搖曳，如同海浪一般，仔細觀察地面似乎有幾個小地洞，可
能是土撥鼠之類的動物，在這裡建造它們的房子；在這危險的地方，風聲鶴唳，稍微
有點風吹草動，都會使人驚心膽顫，你右前方的草地上，似乎有什麼東西在那兒。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "north": ONEW"wild11",
     "west" : ONEW"wild9",
     "southeast" : ONEW"wild13", ]) );
set( "search_desc", ([
     "here":"@@to_search_here"
     ]) );
set_outside("eastland");
reset();
}

string to_search_here()
{
  object ob;

  if (be_search) 
    return "你沒有發現任何東西。\n";
  ob=new(OMONSTER"cobra");
  ob->move(this_object()); 
  be_search=1;
  return "你搜索右前方的草地，嚇了一跳，一隻眼鏡蛇被你驚動起來，正懷著敵意的看著你。\n";
}

void reset()
{
  ::reset();
  be_search=0;
}
