
#include "../echobomber.h"

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
    set_short("The protect room","矮人村落的避難所");
    set_long(@Long
Long
,@CLong
一間為了保護矮人的安全而做的避難所.但是似乎並沒有使用過,但是這個地方依舊保
持著一塵不染.
CLong
    );
    set("exits",([
                "west":Deathland"/village/v54",
             ]));
    create_door("west","east",([
               "keyword":({"archdoor","door"}),
               "status":"locked",
               "c_desc":"一個圓形的拱門",
               "c_name":"拱門",
               "name":"archdoor",
               "desc":"a archdoor",
               "lock":"ECHO_VILLAGE_ARCHDOOR",
               ]) );
    ::reset();
}

void init()
{
  this_player()->set_explore( "deathland#11" );
}
