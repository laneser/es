#include "../takeda.h"
#include <conditions.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "水池中" );
	set_long(@C_LONG
這裡是一個小池子的底部，池底是堅硬的石壁，上面長滿了厚厚的水生植物
在不遠的前方，好像有一大塊類似階梯(ladder)的岩石，似乎可以通到上面
的一個大巖隙，一些微風從那個巖隙中透出，那裡也許可以通到外面去喔。
C_LONG	
	);
        set( "exits", ([
                "out" : TROOM"lair/lair2"
        ]) );
        
        set( "objects", ([
                "sco1" : TMONSTER"scopio",
        ]) );
                set("c_item_desc",(["ladder":
                "一塊像梯子的大石頭，從它光滑平整的表面來看，似乎不是 \n"
                "天然的物品，也許你可以爬(climb)到上面去看看....\n"
                                                   ]));
        
        set("underwater",1);
        reset();
}
void init()
{
  UNDERWATER->apply_effect(this_player(),4,1);
  add_action("do_climb","climb");
}
int do_climb()
{
    if ( present("scorpion",this_object()) ) {
    write("別忙，先殺掉蠍子再過去吧....\n");
    return 1;
    }
    write("你游到那塊岩石前，並且往上爬去..........\n");
    this_player()->move_player(TROOM"lair/lair5","你看到"+this_player()->query("c_name")+"從石縫爬了出去...\n");
    return 1;
}
int clean_up() { return 0; }
