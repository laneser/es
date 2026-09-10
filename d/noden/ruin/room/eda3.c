// eda3.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("依達波第亞宮．門廳");
    set_long(@C_LONG
走進依達波第亞宮的門廳裡，只見石塊與瓦礫散落了一地，目光所及盡是
一片破敗蕭條的景象。門廳的中央有個平臺，上面有塊小銅牌 (plate)，似乎
刻著有字。
C_LONG
    );
    set("item_desc", ([
	"plate" : "銅牌上刻著：「海王子．依達波第亞大人」\n"
	]) );
    set("exits", ([ "north" : AREA"eda4" ]) );
    reset();
}

