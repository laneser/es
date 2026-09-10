#include "forest.h"

inherit ROOM;

void create()
{
        ::create();
        set_short("森林的深處");
        set_long( @C_LONG_DESCRIPTION
這裡是猛獸森林的深處，樹木非常地茂盛，連陽光都無法進入，因此也
顯得格外的陰森。當你向四周圍望去，你發現黑暗中有無數雙碧□閃爍的眼
睛正邪惡地注視著你，要不是為了尋找傳說中的靈獸，誰也不會願意到這種
鬼地方來的。
C_LONG_DESCRIPTION
 );

        set( "exits", ([
                 "north"       : Forest"4,2.forest",
                 "east"        : Forest"5,1.forest",       
                 "west"        : Forest"3,1.forest",
            ]) );
                      
        set("objects", ([ 
                  "tiger#0" : FORMOB"tiger",
                  "tiger#1" : FORMOB"tiger",
            ]) );
            
        reset();    
}

void init()
{
        if (this_player()) this_player()->set_explore("eastland#8");
}
