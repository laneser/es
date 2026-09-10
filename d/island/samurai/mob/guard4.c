#include "mercury.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(16);
        set_name( "guard samurai", "守衛武士" );
        add ("id", ({ "samurai","guard"}) );
        set_short( "guard samurai","守衛武士");
        set("unit","位");
        set_long(@ANGEL
這是個專門負責千川樓安全的武士，也是武士團中最強的武士，你如果想
在千川樓做壞事的話，最好別被他看見！
ANGEL
        );
        
        set_skill("longblade",85);
        set_skill("parry",85);
        set_skill("tactic",70);
        set("tactic","assault");
        set ("natural_weapon_class1", 30);
        set ("natural_min_damage1",10);
        set ("natural_max_damage1",25);
        set ("natural_armor_class", 45);
        set("natural_defense_bonus",8);
        set ("gender", "male");
        set("wealth/silver",400);
        set ("race", "human");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        
        wield_weapon(MOBJ"lakonia_sword.c");
        equip_armor(MOBJ"samurai_vest.c");
        equip_armor(MOBJ"samurai_gloves.c");
        equip_armor(MOBJ"samurai_helm.c");
}