
#include "mudlib.h"
inherit ARMOR;

void create()
{
        set_name("ice demon's cloak", "玄陰鬥蓬");
        add( "id", ({ "cloak" }) );
        set_short("玄陰鬥蓬");
        set_long(@C_LONG
這是傳說中的邪惡陰神所穿的披風，傳說附有陰神的邪惡魔力，
陰玄冰曾經想利用極其邪惡的九子鬼母大法來釋放它的威力，而
殘害了十餘名孕婦和她們的小生命，但是最後在天下正道人士的
合力追緝下功虧一簣。
C_LONG
        );
        set("unit","件");
        set( "type", "cloak" );
        set( "material", "cloth" );
        set( "armor_class", 5 );
        set( "defense_bonus", 4 );
        set( "special_denfese", ([ "ice":6, "fire":-10 ]) );
        set( "weight", 50 );
        set( "value", ({ 1600, "silver" }) );
}
