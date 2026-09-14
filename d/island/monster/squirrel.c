#include "../island.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(2);
        set_name( "squirrel", "松鼠" );
        add( "id", ({ "squirrel" }) );
        set_short( "松鼠" );
        set_long(@LONG
你看到一隻有著長長尾巴，靈活大眼睛的小動物在枝頭間跑來跑去。
LONG
);
        set( "unit", "只" );
        set_perm_stat("kar", 3 );
        set_perm_stat("dex", 5 );
        set_natural_weapon(4,2,3);
        set_natural_armor(7,0);
        set_c_verbs( ({ "%s用爪子往%s抓去" }) );
        set_c_limbs( ({ "頭部", "身體", "腿部", "尾巴" }) );
}
