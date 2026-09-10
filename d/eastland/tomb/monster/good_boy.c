#include "../almuhara.h"
 
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(17);
        set_name( "good boy", "小善童" );
        add ("id", ({ "good", "boy" }) );
        set_short( "小善童");
        set("unit","位");
        set("alignment",2000);
        set("wealth/gold",200);
        set_long(
"一位可愛的小童子，他是大國師的隨侍二童之一。據說他是大國師當年自魔族內戰中
，所撿到的孤兒。卻因為中了邪惡的魔法而不能繼續發育，於是便待在大國師的身
旁，大國師與他有著亦師亦父的關係。\n"
        );
        set_perm_stat("int", 23);
        set_perm_stat("dex", 23);
        set_perm_stat("kar", 20);
        set_perm_stat("str", 22);
        set( "max_hp",700 );
        set( "hit_points", 700);
        set_natural_weapon( 45, 10, 30 );
        set_natural_armor( 85, 20 );
        set("skills",(["dodge":85,"parry":85,"shortblade":85]) );
        set("gender", "male");
        set("race", "daemon");
        set("tactic_func","divine_tactic");
        set("special_defense",(["all":40,"none":40]));
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        wield_weapon(WEAPONS"/sunsword");
        equip_armor(ARMORS"/white_du_do");
        set( "inquiry", ([
"seal" : ({  "喔，我曾聽過大國師說過他們那三把劍是破除封印的關鍵。它們好像可以\n"
	     "插入(insert)那大石中。\n"
	     "\n"
	     "喔....國師還說了什麼「保中又、明夏佐、股尚佐」的....記不得了..:P\n"
	     "奇怪，你不會去問我家主人喔....笨 !! \n" })
		]) );     
}
 
int divine_tactic()
{
  object victim;
  int dam;
  
  if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_room(environment(),
       "\n"+"善童子口中唸唸有詞，突然他的雙手變得巨大無比，向你壓下!!\n",
       this_object() );
  dam = 30 + random(20);
  victim->receive_special_damage("divine",dam);
  return 1;
}
