#include "../tsunami.h"

//inherit DOORS;
inherit ROOM;

void create()
{
    ::create();
    set_short("偏殿");
    set_long(@LONG
這兒是偏殿，也是砂紗美公主的寢宮。來到此處，只聞滿室清香，四處
整理的一塵不染；由於公主年紀不大，所以這兒只有一些普通的陳設；倒是
因為公主頗喜愛看書，因此牆邊書架上堆滿滿都是書。
LONG
             );
    set("exits",([
        "north":CITY"inhouse2"]) );
    set("light",1);
    set("objects",([
        "sasami":TMOB"sasami"]) );
/*    create_door("north","south",([
        "keyword":({"oak door","door"}),
        "status":"closed",
        "name":"Oak door",
        "c_name":"橡木門",
        "c_desc":"一扇厚重結實，刻工精美的橡木門"
        ]) );*/
     reset();
}

