#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set_short( "地洞" );
        set_long(
@LONG
你跌進一個奇怪的地洞，彎彎曲曲的地道剛好將你送到洞底，你只
感到有些頭昏，卻沒有受傷，在這個空無一物的大土洞裡，即使是點著
火把也是模糊一片，等等 ...洞的那一側有兩點微微的亮光，就好像是
野獸的眼睛一樣，你最好小心一點。
LONG
        );
        
        set( "exits", ([ 
		"out" : Goomay"yi_hong",
        ]) );
        
        set( "objects", ([
                "roger" : Mob"roger",
        ]) );
        reset();
}
void init()
{
        if(this_player()) this_player()->set_explore("eastland#14");
}
