
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("forest of GreyIsland","灰暗之島的森林");
  set_long(@Long
Long
,@CLong
一個黑漆漆的森林, 這森林似乎充滿著荊棘與矮灌木, 地上都是腐爛的樹葉, 是
個令人很想逃離的地方. 你發覺你已在森林的深處了. 
CLong
);

set("search_desc",([
    "here":"當你仔細地尋找這裡的時候, 發現一條小小的通道往東北沿伸.\n",
    ]));
set("exits",([
     "west" :Deathland"/island/forest07",
     "south":Deathland"/island/forest11",
     "north" :Deathland"/island/forest09",
     "northeast":Deathland"/island/forest12",
     ]) );

set("objects",([
    "plant":Monster"/plant01",
    ]) );

set("exit_suppress",({"northeast"}) );
 ::reset();
#include <../replace_room.h>
}

