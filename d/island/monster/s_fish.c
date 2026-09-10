#include "../island.h"        
#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level( 5 );
       set( "likefish" , 1 ) ;
       set_name( "small fish","小魚" );
       set ( "id", ({ "fish" }) );
       set_short( "小魚" );
       set( "unit" , "條" );
       set( "alignment" , 30 );
       set_natural_weapon( 12,5,9 );
       set_skill( "unarmed" , 15 );
       set_natural_armor( 25,8 );
       set_long(@LONG
這是一條極普通的小魚，請不要欺負它，謝謝！
LONG
                        );
       set_c_verbs(({"%s用它的身體向%s撞去"}));
       set_c_limbs(({"魚鰭","尾巴","頭部"}));
}
