
#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name( "ninja cape", "忍者披風" );
        add( "id", ({ "cape" }) );
        set_short( "忍者披風" );
        set_long(@C_LONG
這是一件黑色的披風，上面有各式各樣奇怪的迷彩花紋。這就是
傳說中的忍術 － 隱身術的必備法寶。
C_LONG
        );
        set( "unit", "件" );
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 4 );
        set( "defense_bonus", 4);
        set( "weight", 70 );
	set( "special_defense", ([ "evil":5,"divine":-7 ]) );
        set( "value", ({ 1200, "silver" }) );
}
