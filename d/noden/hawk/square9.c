
#include "hawk.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("競技場");
        set_long( @LONG_DESCRIPTION
這裡是鳥人族每年比武大會舉行的地點，你可以看到四周空蕩蕩的啥都
沒有，正是比武的好地方。不過，你卻發現現在有點不一樣，觀察一下，你
似乎覺得四周隱隱約約傳來野獸的咆嘯及低聲嘶吼的聲音，看來，你得要自
求多福羅。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "west" : HAWK"square8",
        "north" : HAWK"square6",
                     ]) );
    reset();
}//end of creat

