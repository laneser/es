#include "../iigima.h"

inherit MONSTER ;

void create ()
{

        ::create();
        set_level(11);
        set_name( "Final guard","禁地守衛" );
        add ("id", ({ "drow", "guard" }) );
        set_short( "Final guard","禁地守衛" );
        set("unit","位");
        set_long(
@C_LONG
這位是監視禁斷之地的守衛，由於此處只有每年祭神時會由神官開啟
，平時則由大鐵門緊緊鎖上，而他就是負責看管此地的人。　　
C_LONG
        );
        set_perm_stat("str", 15);
        set_perm_stat("dex", 14);
        set ("natural_weapon_class1", 15);
        set("alignment",600);
        set ("natural_min_damage1", 3);
        set ("natural_max_damage1", 6);
        set ("natural_armor_class", 40);
   set( "special_defense", ([
      "all":15,"fire":-10,"cold":-10,"evil":30,"divine":-30,"none":5 ]) );
        set ("gender", "male");
        set("wealth/copper",2000);
   set ("weight" , 600 );
        set ("race", "drow");
        set_c_verbs(({"%用%s向%s砍去","用%s向%s刺去"}));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        wield_weapon(OBJ"copper_lb");
        equip_armor(ARM"shield");
        equip_armor(ARM"plate");
        equip_armor(ARM"ring1");
}

