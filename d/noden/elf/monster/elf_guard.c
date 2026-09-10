#include "../layuter.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(14);
        set_name( "Elf guard", "精靈守衛" );
        add ("id", ({ "elf", "guard" }) );
        set_short( "精靈守衛" );
        set("unit","位");
        set_long(
          "這個精靈守衛負責保護大草原的和平，他是位超強力戰士，請勿等閒視之。\n"
        );
        set("max_hp", 1000);
        set("hit_points", 1000);
        set_perm_stat("str", 28);
        set_perm_stat("dex", 28);
        set_perm_stat("int", 19);
        set_perm_stat("pie", 19);
        set_perm_stat("kar", 25);
        set_natural_weapon( 42, 20, 40 );
        set_natural_armor( 80, 40 );
        set("gender", "male");
        set("wealth/gold",35);
        set("race", "elf");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        
        wield_weapon(LWEAPON"guard_sword");
        equip_armor(LARMOR"mail");
}
