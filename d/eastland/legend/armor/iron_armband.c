#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("iron armband", "玄鐵通臂");
        add( "id", ({"armband", }) );
        set_short("玄鐵通臂");
        set_long(@C_LONG
諸保昆委託東方大陸名鑄造師段鐵幫忙冶煉他在苗疆所得到的一塊玄鐵礦，段鐵用
這塊玄鐵礦煉製了數樣防禦力非凡的護具，這是其中的玄鐵通臂。        
C_LONG
        );
        set( "unit", "個");
        set( "type", "arms" );
        set( "armor_class", 4 );
        set( "material","heavy_metal" );
        set( "weight", 38 );
        set( "value", ({ 950, "silver" }) );
}
