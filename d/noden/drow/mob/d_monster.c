#include "../iigima.h"
inherit MONSTER ;
void create ()
{
        ::create();
        set_level(13);
        set_name( "Dark monster","黑暗喚獸" );
        add ("id", ({ "monster" }) );
        set_short( "黑暗喚獸" );
        set("unit","只");
        set_long(
@C_LONG
這是一隻由佩蘿蒂絲的神劍『諸神的黃昏』所召喚的兇獸，正虎
伺眈眈的看著你！
C_LONG
        );
        set_perm_stat("str", 22);
        set_perm_stat("kar",20);
        set("alignment",180);
        set("killer",1);
        set_skill("dodge",60);
        set ("natural_weapon_class1", 20);
        set ("natural_min_damage1", 20);
        set ("natural_max_damage1", 35);
        set ("natural_armor_class", 50);
        set("natural_defense_bonus",16);
}

