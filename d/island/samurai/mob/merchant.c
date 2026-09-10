
#include <mudlib.h>

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(6);
        set_name( "merchant","雜貨商人" );
        add ("id", ({ "merchant"}) );
        set_short( "merchant","雜貨商人");
        set("unit","位");
        set_long(@ANGEL
這是一個雜貨的商人
ANGEL
        );
        
        set ("gender", "male");
        set("wealth/gold",7);
        set ("race", "human");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
}