
#include "../layuter.h"

inherit MONSTER ;

void create ()
{
        object weapon;

        ::create();
        set_level(3);
        set_name("Elven lady", "女精靈" );
        add ("id", ({"elf", "lady" }) );
        set_short( "女精靈" );
        set("unit","位");
        set_long(
           " 女精靈是辛勤的工作者，由於她們的努力使的精靈村\n"
           " 看起來井井有條。\n" 
        );
        set_perm_stat("str", 2);
        set_perm_stat("int", 4);
        set_perm_stat("kar", 4);
        set ("natural_weapon_class1", 1);
        set ("natural_min_damage1", 1);
        set("natural_max_damage1",2);
        set ("natural_armor_class", 15);
        set ("gender", "female");
        set("wealth/silver",30);
        set ("race", "elf");
        set_c_verbs(({"%用%s向%s砍去","用%s向%s刺去"}));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        
        weapon= new(LWEAPON"carver");
        weapon->move(this_object());
        wield_weapon(weapon);
}
