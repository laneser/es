#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("溪谷沙岸");
	set_long( @LONG
你立足之處是一溪谷裡的沙岸，前面溪水從東南緩緩流向西北，漸漸地注入一
個黑色的大洞。這溪谷兩岸都是千仞高的山峰，除非脅生兩翼、步縱萬尺，否則斷
難攀越而過。
LONG
	);
        set("light",1);
	set( "exits", ([ 
         "southeast" : SAREA"bottom2",
        ]) );
	reset();
}
