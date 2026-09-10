#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(14);
        set_name( "Ninja", "忍者" );
        add ("id", ({"ninja"}) );
        set_short( "Ninja","忍者");
        set("unit","位");
        set_long(@AAA
這是武士團的秘密部隊，忍者軍團的一員，他們和武士不同之處在於他們是負責
敵後破壞工作，而非正面刺殺，但你可別因此小看他們的戰力喔．
AAA
        );
        set_skill("longblade",70);
        set_skill("parry",60);
        set_skill("dodge",60);
        set("hit_points",300);
        set("max_hp",300);
        set ("natural_weapon_class1", 30);
        set ("natural_min_damage1",10);
        set ("natural_max_damage1",25);
        set ("natural_armor_class", 64);
        set("natural_defense_bonus",10);
        set ("gender", "male");
        set("wealth/silver",320);
        set ("race", "human");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        
        wield_weapon(MOBJ"ninja_sword.c");
        equip_armor(MOBJ"ninja_cloth.c");
}
