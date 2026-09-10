
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "Swallow Sword", "飛燕之劍" );
        add( "id",({ "swallow","sword" }) );
        set_short( "Swallow Sword", "飛燕之劍" );
        set_long(@AAA
這一神崎夢想流事劍士 橘右京 的配劍，據說右京曾用此劍
斬落空中的飛燕，故此劍有此名！
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 38 );
        set( "type", "longblade" );
        set( "min_damage", 15 );
        set( "max_damage", 37 );
        set( "weight", 130 );
        set( "value", ({ 1720, "silver" }) );
}
