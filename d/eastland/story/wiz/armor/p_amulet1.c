#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "gem necklace","琉璃珠項鍊" );
        add( "id", ({ "necklace" }) );
        set_short( "琉璃珠項鍊");
        set_long(@long
由一顆顆反覆燒製而成的琉璃珠所串成的項鍊，非常名貴。在這串項鍊上閃爍著一
閃閃的光芒，把全室照著通亮。
long    );
        set( "unit", "串" );
        set( "weight", 30 );
        set( "type", "misc" );
        set( "material", "element");
        set( "defense_bonus", 5);
        set( "value", ({ 2000, "silver" }) );
        set( "equip_func","equip_cloth");
        set( "unequip_func","unequip_cloth" );
        set("extra_stats",(["str":-1]));
                 
}
int equip_cloth()
{
    set("light",1);
    return 1;
}
int unequip_cloth()
{
    set("light",0);
    return 1;
}
