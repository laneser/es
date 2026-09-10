#include "../dony.h"
inherit ROOM;

void create()
{
	::create();
        set_short( "church", "祠堂" );
	set_long(@C_LONG
這是一間老舊的祠堂,因為年老未修緝, 所以看起來好像要□塌的樣子。一眼
看過去桌上有很多架子,架上供奉的多是歷代幫主和一些精忠報國之士的神主牌 。
檀香嫋嫋,誦經之聲不斷,頓時讓你想詹仰先人的風範, 因而不禁嚴肅了起來,或許
是忠義心人人有之使得你有所感觸吧。
C_LONG
	);
	set("light",1);
	set( "exits", ([
                      "out":DBEGGAR"east7.c"
	]) );
        set( "objects", ([
                      "old":DMONSTER"old_garden.c",
                "enforcer1":DMONSTER"enforcer.c",
        ]) );
     reset();
}
