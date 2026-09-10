#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(6);
        set_name( "citizen","市民" );
        add ("id", ({ "citizen"}) );
        set_short( "citizen","市民");
        set("unit","位");
        set_long(@ANGEL
這是一個普通的市民，但由於生活在一個備戰體制下的城市中，也
是有一兩下子的人
ANGEL
        );
        
        set ("gender", "male");
        set("wealth/silver",70);
        set ("race", "human");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
}