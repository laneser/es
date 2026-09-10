// g10.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("廢棄的花園");
    set_long(@C_LONG
你來到了一個廢棄的花園，到處長滿了雜草和青苔。這裡的空氣充滿著肅
殺的氣氛，似乎連你身上的血液也快要為之凝結起來。雜草上沾滿了斑斑血跡
，看來這兒曾死過不少人。
C_LONG
	    );
    set("exits", ([
	"north" : AREA"g10",
	"east" : AREA"g9",
	"west" : AREA"g3",
	]) );
    set("objects", (["deathknight" : MOB"deathknight"]));
    reset();
}


	    
