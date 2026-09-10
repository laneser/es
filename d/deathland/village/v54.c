
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("The road of the dwarf village","矮人村落的小路");
    set_long(@Long
Long
,@CLong
你目前位於矮人的村莊的環莊道路上,這裡有著非常和平安詳的氣氛,恍佛是一個世
外桃源.這裡已經多年沒有戰爭了,矮人們的童年幾乎在此渡過.東邊有個拱門,通向一個
避難所.
CLong
    );
    set("exits",([
                "east":Deathland"/village/vr4",
                "north":Deathland"/village/v55",
                "south":Deathland"/village/v53",
             ]));
    create_door("east","west",([
               "keyword":({"archdoor","door"}),
               "status":"locked",
               "c_desc":"一個圓形的拱門",
               "c_name":"拱門",
               "name":"archdoor",
               "desc":"a archdoor",
               "lock":"ECHO_VILLAGE_ARCHDOOR",
               ]) );
    set("objects",([
        "guard":Monster"/guard03"
        ]) );
    ::reset();
}
