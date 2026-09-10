// Deathland/holyplace/h08.c 
// Created by Echobomber @Eastern.Stories 
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short(" A strange place","陰暗的虛無飄渺處");
  set_long(@Long
Long
,@CLong
一處陰暗的地下世界,四處的黑影無聲無息地向你侵襲而來.這裡的寂靜令人感到害怕,
讓你不自主的想要發出一些聲音.沒有風聲,沒有水聲,甚至你無法聽到自己的腳步聲,你不
禁懷疑自己處在一個虛無的地方.你的視野越來越小,似乎你的眼睛被一些黑色的\"霧\"擋住
了視線.在這個危險的地方,你最好提高警覺,因為隨時都有可能從黑暗中走出邪惡的生物.
CLong
);

set("c_item_desc",([
    "fog":"@@to_look_fog",
    ]) );
set("exits",([
             "east":Deathland"/holyplace/h07",
             "west":Deathland"/holyplace/h11",
             ]));
reset();
}

string to_look_fog()
{
     return can_read_chinese() ?
            "是霧嗎?你懷疑著,你能很清楚地看到一些懸浮粒子飄散在你的周圍.\n"
            "\或許是一種邪惡的物質,你能感覺到有著邪惡的成份參雜其中.\n" :
            "need work.\n"; 
}
