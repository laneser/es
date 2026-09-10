#include "../tsunami.h"

inherit DOORS;
inherit ROOM;

void create()
{
    ::create();
    set_short("庭院");
    set_long(@LONG
這兒果然有人住著，東方有一間頗為華麗的房子，而這兒看來似乎是庭
院的樣子，兩旁的花圃整理的十分整齊，中間假山的小瀑布更是讓人覺得這
兒的主人品味非常非常出眾。不知道房子中住的是什麼樣的人呢？
LONG
             );
    set("exits",([
            "east":AREA"house2",
            "west":AREA"way4"]) );
    set_outside("island");
    create_door("east","west",([
         "keyword"   :  ({"Oak door","door"}),
         "status"    :"closed",
         "name"      :"oak door",
         "c_name"    :"橡木門",
         "c_desc"    :"一道有著精緻雕刻的橡木門"
                ]) );
    reset();
}
