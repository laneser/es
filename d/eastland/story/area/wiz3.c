#include "../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("山腳");
	set_long( @LONG
你走在山腳下，地上長著靈花異卉，其花朵之大，馥郁芬香撲鼻，微風吹來，
不禁令你神清氣爽為之一□，無身毫不舒暢，野蜂蝴蝶翩翩飛舞恣意其間引伴採蜜
，好不快活。雲淡高空，溫度適中，沾著些許溼氣，多一分太多，少一分則深深不
足，格是個化外之境。路旁有座涼亭和一塊石碑(stone)。 
LONG
	);
        set("light",1);
        set( "exit_suppress", ({
	    "seu" }) );
	set( "exits", ([ 
       	  "southeastup" : SAREA"wiz2",
                  "seu" : SAREA"wiz2",
                "north" : SCITY"southgate",
                 "west" : SAREA"rest1"
        ]) );
        set("c_item_desc",([
          "stone":@LONG
石碑上：
        北達「巫咸國」。「巫咸國」又名「巫咸城」，此地乃國境。
LONG
        ]) );                     
	reset();
}
