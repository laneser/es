
#include "../goomay.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(11);
        set_name( "Bodyguard", "護院武師" );
        add ("id",({ "bodyguard","guard"}));
        set_short( "護院武師");
        set("unit","位");
        set_long(
@C_LONG
他是一個長的極為可怕的蜥蜴人，佈滿細細鱗片的身上泛著詭異的油光，
他可是打架高手，而且十分負責盡職，沒事最好不要惹他。
C_LONG
);
        set ("gender", "male");
        set ("race", "lizardman");
        set_perm_stat( "str", 20 );
        set_perm_stat( "kar", 20 );
        set_perm_stat( "dex", 18 );
        set_skill( "dodge", 100 );
        set_skill( "unarmed", 75 );
        set( "max_hp", 400 );
        set( "hit_points", 400 );
        set( "wealth/gold",20);
        set( "natural_armor_class", 45 );
        set( "natural_defense_bonus", 20 );
        set( "natural_weapon_class1", 19 );
        set( "natural_min_damage1", 5 );
        set( "natural_max_damage1", 10 );
        set( "special_defense", ([ "all": 30,"none":20]) );
        set( "alignment", 500 );
#include <replace_mob.h>
}
