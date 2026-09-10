#include "oldcat.h"

inherit ROOM;

void create()
{
	::create();
	set_short("山腰");
	set_long( 
@LONG_DESCRIPTION
那聳立雲霄的火山山口似忽還會有陣陣濃煙冒出，不知何時還會再爆發，你覺的
這裡非常的熱，不可能有生物能在這裡生存下去，這裡到處都是火山岩和浮石，這座
由火山岩所構成的火山，由於到處是巨大的裂縫，因此想到達山頂是相當困難的，你
站在山腰處，在你的左方有一棵被烤乾的樹木，抬頭往上望去，心裡想著要到達火山
頂還一大段距離，在樹下休息一下吧。
LONG_DESCRIPTION
	);

/* set("search_desc",([
    "here":"@@search_here",
    ]) ); */

set( "exits", ([
     "southwest" : ONEW"varea2",
     "northwest" : ONEW"varea3" 
     ]) );
set_outside("eastland");
reset();
}

string search_here()
{
      return "\n"; 
      write( 
           "你繞著這棵樹搜尋了一圈，發現有一枝幹(branch)怪怪的。\n"+
           "這個枝幹很有彈性，你可以試著去拉拉看。\n");
}

void init()
{
/*    add_action("do_pull","pull"); */
}

int do_pull(string arg)
{   
    if (!arg || arg!="branch")
    { write(
        "你的手做出一些奇怪的動作.....天上傳來一陣笑聲....你在拉什麼拉？\n");
      tell_room(this_object(),this_player()->query("c_name")+"的手做一些奇怪的動作。\n",this_player());
      return 1;
    };
    write( 
          "樹幹上出現一個大洞，你信步往洞中走去....\n"+
          "你剛跨入樹洞之中，啊的一聲，往下摔了下去...\n"+
          ".....\n\n......\n\n...\n\n..........\n\n...\n\n.....\n"+
          ".........\n\n......\n"+
          "你發現你已在火山的山腹中。\n");
    this_player()->move_player( ONEW"mcave1.c","SNEAK" );
    tell_room(this_object(),"你見到"+this_player()->query("c_name")+"消失在你的面前。\n",this_player());
    return 1;
}
