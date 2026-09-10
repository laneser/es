#include "../iigima.h"

inherit MONSTER ;
void create ()
{
        ::create();
        set_level(8);
        set_name("Drow woman","黑暗精靈婦女" );
        add ("id", ({"drow", "woman" }) );
        set_short( "黑暗精靈婦女" );
        set("unit","位");
        set_long(
@C_LONG
這是一位黑暗精靈村的貴族婦女，她頸上的銅環閃閃發光，吸引你的
注意。
C_LONG
        );
        set_perm_stat("str", 5);
        set_perm_stat("int", 8);
        set_perm_stat("kar", 8);
        set ("natural_weapon_class1", 10);
        set ("natural_min_damage1", 10);
        set("natural_max_damage1",14);
        set ("natural_armor_class", 15);
        set ("gender", "female");
      set( "weight", 400);
        set("wealth/silver",40);
        set ("race", "drow");
     set( "special_defense", ([
       "all":10,"fire":-10,"cold":-5,"evil":25,"divine":-30,"none":5 ]) );
        equip_armor(ARM"feet");
        equip_armor(ARM"amulet");
}
// Ending QC.
