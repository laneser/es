#include "../iigima.h"

inherit MONSTER ;

void create ()
{

        ::create();
        set_level(6);
        set_name("Drow slave","黑暗精靈奴役" );
        add ("id", ({"drow", "slave" }) );
        set_short( "黑暗精靈奴役" );
        set("unit","位");
        set_long(
@C_LONG
這是個可憐的下等奴役，瘦巴巴的樣子好像被餓了很久了。
C_LONG
        );
        set_perm_stat("str", 5);
        set_perm_stat("int", 7);
        set_perm_stat("kar", 7);
        set ("natural_weapon_class1", 10);
        set ("natural_min_damage1", 8);
        set("natural_max_damage1",12);
        set ("natural_armor_class", 12);
          set( "special_defense", ([
       "all":6,"fire":-10,"cold":-10,"evil":15,"divine":-30 ]) );
        set ("gender", "male");
        set("wealth/copper",80);
        set ("race", "drow");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
       set("weight" , 300);
        wield_weapon(OBJ"blunt");
        equip_armor(ARM"bracers");
}
// Ending QC.
