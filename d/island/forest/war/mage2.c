#include "../tsunami.h"

inherit "/d/eastland/island/war/i_warvalue";

void create()
{
	::create();
	set_level(10);
	set_name( "Light teeth", "光牙" );
	add("id", ({"teeth"}) );
        set_short( "魔獸「光牙」" );
	set_long(@C_LONG
一隻全身發光，四處亂撞的魔獸。
C_LONG
	);
	set_perm_stat("str", 10 );
	set_perm_stat("dex", 11 );
	set_skill("dodge", 40 );
	set_skill("tactic", 70 );
	set("tactic", "melee" );
	set("killer", 1);
	set("pursuing",1);
	set("max_hp", 200);
	set("hit_points", 200);
	set("justice",1);
	set_natural_armor(45,10);
	set_natural_weapon(20,12,20);

       set("c_killer_msg","突然地上射出一道光線，在衝向天空轉了個彎後，向你襲來！\n");
       set_c_verbs( ({"%s突然筆直的射向%s","%s轉了個彎兒向%s衝了過去",
              "%s在地上蜿蜒前進突然咬向%s"}) );
       set_c_limbs( ({"門面","牙齒","頭部","身軀"}) );
       set("c_death_msg","%s說：主人，請接受我的效忠！說著說著化成一把短刃....\n");
       set("alt_corpse",TWEP"shortblade1");   
}
