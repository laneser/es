#include "../island.h"        
#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level( 10 );
       set_skill( "unarmed" , 20 );
       set( "likefish" , 1 ) ;
       set_name( "salmon","櫻花鉤吻鮭" );
       set ( "id", ({ "salmon","fish" }) );
       set_short( "櫻花鉤吻鮭" );
       set( "unit" , "條" );
       set( "alignment" , 500 );
       set_natural_weapon( 22,11,19 );
       set_natural_weapon2( 15,8,18 );
       set_long(@LONG
這是國寶魚『櫻花鉤吻鮭』，它只能在極清潔和良好的水中活存
，好國民要好好保護它。
LONG
                        );
       set_c_verbs(({"%s用它的身體向%s撞去","%s用它的尾巴向%s掃去"}));
       set_c_limbs(({"魚鰭","尾巴","頭部"}));
}
