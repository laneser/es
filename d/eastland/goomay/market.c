#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "市場" );
        set_long(
@LONG
這是一座市場，叫賣的聲音此起彼落，吵鬧的人潮川流不息，形成
一片熱鬧非凡的景象。同時這裡也是古梅鎮婦女的重要消息來源，只要
你在路旁待上一時三刻，保證可以聽到各種奇奇怪怪的大小雜事，而且
有耳朵長繭的危險，南方是一條青石板道。在你的北方一眼望去都是雜
亂骯髒的貧民窟，雜草野花在頹圮的廢墟中孳生，那應該是本鎮的舊鎮
址。
LONG
        );
        
        set( "exits", ([ 
                "south" : Goomay"row21",
		"north" : Goomay"ruin1",
        ]) );
        
        set( "objects", ([
                "woman1" : Mob"woman",
                "woman2" : Mob"woman",
                "merchant" : Mob"merchant",
        ]) );
        set("exit_suppress", ({ "north" }) );
set("pre_exit_func",([
    "north":"to_north",
    ]) );
        reset();
}
int to_north()
{
    write("你穿過擁擠的人群，進入了荒煙蔓草的廢墟.\n");
    return 0;
}

