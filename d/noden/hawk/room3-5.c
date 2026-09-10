
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("鳥人祭壇");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
這裡是鳥人族最重要的聖地，高高的矗立在天空之城的最頂點。你往下
一望，只看到無窮無盡的黑霧，詭異的散發出來，陰氣森森，殺氣騰騰的感
覺讓你不禁有點腳軟。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "northeast" : HAWK"room3-3",
                     ]) );
        set( "objects",([
                "prayer" : MOB"god1" ]) );
        reset();
}//end of creat

void init()
{
        add_action("to_jump","jump");
}

int to_jump()
{
        this_player()->receive_damage(120);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        return 1;
}
