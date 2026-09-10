#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "Hades Veil","黑帝斯面紗" );
        add( "id", ({ "veil","hades veil" }) );
        set_short( "黑帝斯面紗" );
        set_long(
                "這隻黑色的面紗上面畫滿了許多邪惡的圖樣, 看來像是冥界黑"+
                "帝斯所用的。\n"
        );
        set( "unit", "只" );
	set("material","cloth");
	set( "type", "head" );
        set( "armor_class", 1 );
        set( "defense_bonus", 1 );
        set( "weight", 50 );
        set( "value", ({ 7000, "silver" }) );
}
