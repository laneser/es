#include "../asterism.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(18);
        set_name( "dwarf elder", "矮人長老" );
        add ("id", ({ "dwarf", "elder" }) );
        set_short( "dwarf elder","矮人長老");
        set("unit","位");
        set("alignment",600);
        set("wealth/gold",100);
        set_long("",
            "矮人長老不但是個強壯的戰士也是個可怕的施法者。矮人本來並不擅於\n"
            "施法,但是與地精比鄰而居的結果使矮人也對魔法有蠻深的認識。\n"
        );
        set_perm_stat("str", 28);
        set_perm_stat("dex", 25);
        set_perm_stat("con",30);
        set_natural_weapon( 45, 20, 30 );
        set_natural_armor( 55, 20 );
        set ("gender", "male");
        set ("race", "dwarf");
        set("tactic_func","fire_tactic");
        set("special_defense",(["all":50,"none":10]));
        set("aim_difficulty",(["critical":100,"weakest":30,
                               "vascular":50,"ganglion":50 ])) ;
        set_skill( "blunt",100 );
        set_skill( "parry",20 );
        set_skill( "dodge",20 );
//      set_c_verbs(({"用%s使出鞭法向%s攻擊","用%s向%s敲擊"}));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        wield_weapon(WEAPONS"blunt01");
        equip_armor(ARMORS"boots01");
        equip_armor(ARMORS"leggings02");
        equip_armor(ARMORS"cloak_d01");
        equip_armor(ARMORS"gloves02");
}

int fire_tactic()
{
  object magics;
  int dam;
  
  if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
   tell_room(environment(),
       "矮人長老的手在空中畫了畫。你身上竟開始結冰將你包住。....\n"
       "......你好不容易才打破冰塊跑了出來。\n",
       this_object() );
  dam = 40 + random(20);
  magics->receive_special_damage("cold",dam);
  return 1;
}
       

