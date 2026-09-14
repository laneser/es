#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
        set_short("火山口");
	set_long( 
@LONG_DESCRIPTION
在這火山的最頂端，在火山岩的地表之上，到處都是火山岩和浮石的石塊，你站在
火山口，往下看去，火山口仍有陣陣濃煙冒出，不知何時還會再爆發，在你的右側有一
座巨大的雕像(statue)，雕像前面有個小祭壇(altar)，祭壇上似乎還留有一點血跡，你
想這一定就是那矮靈族將祭品獻給火山之神的祭臺。
LONG_DESCRIPTION
	);

set("item_desc",([
    "statue" : "這是一座巨大的火神雕像，住在火山附近的矮靈族相信只有奉獻鮮血才能平息火神之怒。\n",
    "altar" : "這祭壇上到處都是血跡，在檯面上有一個火龍的圖案(symbol)，在祭壇的下方有一個告示板(board)。\n",
    "symbol" : "一條張牙舞爪的火龍，嘴裡吐著火焰。\n",
    "board" : "對我奉獻，你就會得到你所想要的。\n",
    ]));
set( "exits", ([
     "down" : ONEW"varea3"
     ]) );
set( "objects", ([
     "wwizard":OMONSTER"wwizard"
     ]) );
set_outside("eastland");
reset();
}

void init()
{
    add_action("do_touch","touch");
/*    add_action("do_jump","jump"); */
}

int do_touch(string arg)
{  
    if(!arg || arg!="symbol") return 0;

    write("你看到一陣濃煙將你包圍，待濃煙散去，你發現自己已到了另一個地方了。\n");
    this_player()->move_player(ONEW"wcave1","SNEAK");
    tell_room(this_object(),"你看到一陣濃煙將"+this_player()->query("c_name")+"包圍起來，等濃煙散去，你已看不見"+this_player()->query("c_name")+"的人影\n",this_player());
    return 1;
}

int do_jump()
{
    write(
          "你的身體不斷往下掉，你的耳邊只聽到咻咻聲，本以為一定會死，\n"+
          "說巧不巧，剛好撞到在一凸出的樹枝上，啪的一聲，樹枝斷了但\n"+
          "也將你的墜勢阻了一阻，你跌在厚厚的火山灰上。\n");
    this_player()->move_player( ONEW"icave1.c","SNEAK" );
    tell_room(this_object(),"你看到"+this_player()->query("c_name")+ "把自己當成祭品往下跳去.\n",this_player());
    return 1;
}
