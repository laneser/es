
#include "hawk.h" 

inherit ROOM;

void create()
{
        ::create();
        set_short("鳥人祭壇");
        set_outside("noden");
        set_long( @LONG_DESCRIPTION
這裡是鳥人族最重要的聖地，高高的矗立在天空之城的最頂點。你側耳
傾聽，聽到一絲一絲詭異的聲音從懸崖的深處往上飄啊飄。再往下一望，只
看到無窮無盡，淡淡的紫色霧氣，虛無飄緲的感覺讓你不禁有點腳軟。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "southwest" : HAWK"room3-7",
                     ]) );
        set( "objects",([
                "prayer" : MOB"god" ]) );
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
