#include "../legend.h"

inherit ROOM;

void create()
{
object kun;    
        ::create();
    set_short("月到風來亭");
        set_long( 
@LONG
一座古色古香的六角亭。斜□飛簷，結構巧妙，名為『月到風來』亭，不論是
取名，或是建築構造，在海內堪稱獨步。涼亭邊一塊大石旁種有一本『眼兒媚』，
掩掩映映，更添姿色。
LONG
    );
    set( "light",1);
    set("exits",([
          "out":LAKE"village4",
    ]) );
    kun = new(LMONSTER"pao_kun");
    kun->move(this_object());
                
    reset();
}
int clean_up()
{
    return 0;
}