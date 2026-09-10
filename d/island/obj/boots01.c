#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("cloud boots", "流雲靴");
        add( "id", ({ "boots","boot" }) );
        set_short("@@color");
        set_long(@C_LONG
流雲靴是少林寺中代表地位的象徵，只有同時會三種以上七十二絕技的僧人
才會被頒發此靴，上面如流雲搬的圖騰，是用金絲繡上去的，整雙鞋看來閃
閃發亮。 ( Odin,Inc )       
C_LONG
        );
        set("material","cloth");
        set( "unit", "雙");
        set( "type", "feet" );
        set( "armor_class", 10 );
        set( "defense_bonus", 4 );
        set( "weight", 35 );
        set( "value", ({ 1001, "silver" }) );
        set( "no_sale", 1 );
}
string color()
{ return set_color("流雲靴","HIY"); }