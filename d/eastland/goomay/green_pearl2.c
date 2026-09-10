#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "綠珠樓花廳" );
        set_long(
@LONG
這裡是綠珠樓的花廳，廳堂四周都是一些美麗燦爛的奇花異草，
想必都是錢不多為了取悅他的如夫人而費盡心思蒐羅來的，原來綠珠
是個喜愛蒔花弄草的姑娘。
LONG
        );
        
        set( "exits", ([ 
		"down"   : Goomay"green_pearl",
        ]) );
        set( "objects", ([
                "lady" : Mob"green_lady",
		]));
        reset();
}

void init()
{
	if (this_player())
                this_player()->set_explore("eastland#10");
}
