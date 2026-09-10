// rose1.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("廢墟");
    set_long(@C_LONG
你來到了一個破舊的廢墟，到處散落著頹圮的石柱和石塊。地上有條小徑
向南北方向延伸。你注意到在不遠處的瓦礫堆旁有個小營帳 (camp) ，裡面透
出來些微的光亮，似乎是有人居住的樣子。到底是誰會住在這個鬼地方呢？
C_LONG
    );
    set("exits", ([
	"north" : AREA"rose2",
	"south" : AREA"rose0",
	"camp" : AREA"camp"
	]) );

    reset();
}
	
