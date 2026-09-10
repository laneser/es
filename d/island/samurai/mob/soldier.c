#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(7);
        set_name("soldier","青年士兵" );
        add ("id", ({ "soldier","young"}) );
        set_short( "young soidier","青年士兵");
        set("unit","位");
        set_long(@ANGEL
這是一個武士團中地位最低的士兵，是個剛剛被徵招入伍的新兵
ANGEL
        );
        
        set ("gender", "male");
        set("wealth/silver",50);
        set ("race", "human");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        wield_weapon(MOBJ"iron_blade.c");
}