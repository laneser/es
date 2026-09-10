#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "昭慶寺" );
        set_long("EMPTY\n",
@LONG
你走進一座寺廟，廟堂上掛著一方匾額「昭慶寺」，雖然這座寺廟位居古梅鎮
的鬧市，但它卻出奇的破舊，連殿上大佛的金身也剝落的差不多了，不過，隱約從
殿中傳來得幾聲清磬、幾句梵唱卻使得你俗念盡消。
LONG
        );
        
        set( "exits", ([ 
		"north" : Goomay"col11",
        ]) );
        
        set( "objects", ([
                "little monk" : Mob"little_monk",
        ]) );
        reset();
#include <replace_room.h>
}

