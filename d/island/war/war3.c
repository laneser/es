#include "../island.h"

inherit IWAR"i_warvalue";

void create ()
{
        ::create();
        set_level(13);
        set_name( " soldier ", "武士團士兵" );
        add ("id", ({ "soldier"}) );
        set_short( "武士團士兵");
        set("unit","位");
        set_long(@ANGEL
這是一個經過良好訓練的士兵，負責看守武士團的邊境地區
ANGEL
        );
        set("killer",1);
        set("pursuing",1);
        set("justice",8);
        set_skill("longblade",60);
        set_skill("parry",20);
        set ("natural_weapon_class1", 15);
        set ("natural_min_damage1",5);
        set ("natural_max_damage1",20);
        set ("natural_armor_class", 50);
        set("natural_defense_bonus",10);
        set ("gender", "male");
        set("wealth/silver",350);
        set ("race", "human");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        
        wield_weapon(IWARO"wind_blade_sword.c");
}