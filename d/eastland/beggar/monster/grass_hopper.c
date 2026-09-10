#include "../dony.h"        
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(4);
       set_name( "grass hopper", "蚱蜢" );
       add( "id",({"grass","hopper"}) );
       set_short( "蚱蜢" );
       set("unit","只");
       set_long(
       "這是一隻小小的昆蟲,它正跳來跳去的。\n"
                        );
       set_perm_stat("dex", 3);
       set_natural_weapon(5,2,4);
       set_natural_armor(5,1); 
//       set( "moving", 1 );
//       set( "speed", 30 );
//       set ("pursuing", 1) ;
//       setenv( "C_MIN", "一隻$N跳了過來。");
//       setenv( "C_MOUT", "$N往$D邊跳了過去。");
       set_c_verbs(({"%s用它的腿向%s踢去"}));
       set_c_limbs(({"腹部","頭部","腿"}));
}
