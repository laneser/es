#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set_outside( "eastland" );
        set_short( "樹叢" );
        set_long(
@LONG
這是一片濃密的樹叢，微弱的天光從濃密的枝葉間透進來，四周
寂寂無聲，你似乎能聞到一陣陣清雅的花香隨風飄來，隨著輕風掠過
，帶起一陣枝葉搖曳聲，外面好像有許多樹木。這裡的地面上有一個
大洞，洞旁立了一塊告示牌(sign)。
LONG
        );
        
//	set( "exits", ([ 
//		"east" : Goomay"col33",
//	]) );
        set("c_item_desc",(["sign":@C_LONG
    哈哈哈 !! 你上當了 !! 這裡只是窮極無聊的茹比留下的連接區，
什麼東西都還沒有，不過只要你到了這裡，多多少少都有那麼一點好處
啦 .... 現在你最好還是鑽洞回去嘍 !
C_LONG
                            ]));
                                       
        reset();
}
void init()
{
	add_action("to_enter_hole", "enter");
        if (this_player()) this_player()->set_explore("eastland#12");
}

int to_enter_hole( string arg )
{
    if( !arg || arg != "hole" )
      return notify_fail("要進去哪裡 ?\n");

      this_player()->move_player(Goomay"tunnel2","SNEAK");
    return 1;
}

