#include "../layuter.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(2);
       set_name( "butterfly", "鳳仙蝶" );
        set_short( "鳳仙蝶" );
       set("unit","只");
        set_long(
       "這是一隻美麗的鳳仙蝶，此刻正在四處上輕快的飛舞著，有如風之舞者。\n"
                        );
       set("moving",1);
       set("speed",25);                  
       set_perm_stat("dex", 4);
       set ("natural_weapon_class1", 6);
       set ("natural_min_damage1",2);
       set ("natural_max_damage1", 4);
       set ("natural_armor_class", 5);
		setenv( "C_MIN", "一隻$N翩翩的飛了過來。");
        setenv( "C_MOUT", "$N翩翩地往$D邊飛去。");
       set_c_verbs(({"%s用它的翅膀向%s撲擊"}));
       set_c_limbs(({"身體","頭部"}));
}
