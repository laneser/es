
#include <mudlib.h>
inherit WEAPON;

void create()
{
        set_name( "sound_blade", "鍔鳴刀" );
        add( "id",({ "bladed","sword","sound_sword" }) );
        set_short( "sound_blade", "鍔鳴刀" );
        set_long(@AAA
這是一把劍身薄且長的日本刀,在劍鍔處刻有一個修字,表示這是武士
隊長約修的配刀
AAA
        );
        set( "unit", "把");
        set( "weapon_class", 35 );
        set( "type", "longblade" );
        set( "min_damage", 20 );
        set( "max_damage", 38 );
        set( "nosecond",0);
        set( "weight", 150 );
        set( "value", ({ 100, "gold" }) );
}



