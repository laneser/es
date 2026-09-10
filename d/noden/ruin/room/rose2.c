// rose2.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("廢墟");
    set_long(@C_LONG
你來到了一個破舊的廢墟，到處散落著頹圮的石柱和石塊。地上有條小徑
向南北方向延伸，北方的不遠處似乎有流水聲傳來。這地方陰暗潮溼，卻連一
點青苔也沒有，你不由得打了個寒噤。
C_LONG
    );
    set("exits", ([
	"north" : AREA"rose3",
	"south" : AREA"rose1"]) );

    reset();
}
