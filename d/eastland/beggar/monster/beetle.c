#include "../dony.h"      
        
inherit DMONSTER"limit";

void create ()
{               
       ::create();
       set("lvlimit",10);
       set_level(5);
       set_name( "beetle", "甲蟲" );
       add( "id",({"beelte",""}) );
       set_short( "甲蟲" );
       set("unit","只");
       set_long(
       "這是一隻小小的昆蟲,它正棲息在樹上。\n"
                        );
       set_perm_stat("dex", 4);
       set_perm_stat("str", 4);
       set_natural_weapon(7,4,8);
       set_natural_armor(25,1); 
       set_c_verbs(({"%s用它的巨角往%s一頂"}));
       set_c_limbs(({"腹部","頭部","角"}));
}
