#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(15);
    set_name("Shi Tsen","時遷");
    add("id",({"thief","shi","tsen"}) );
    set_short("時遷");
	set_long(@C_LONG
高唐州人士，外號鼓上蚤，手腳靈便，盜竊成性，行事機警，為梁山泊軍中報機密
步軍頭領．看到他你不禁抓緊你的錢包．
C_LONG
	);
    set("alignment",-400);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "個" );
    set_perm_stat( "dex",23);
    set_perm_stat( "str",20);
    set_perm_stat( "int",19);
    set_perm_stat( "karma",26);
    set_skill("dagger",60);
    set_skill("dodge",90);	
    set ("max_hp",360);
    set ("hit_points",360);
    set ("wealth", ([ "gold":10]) );
    set_natural_weapon(8,8,9);
	set_natural_armor(28,12);
	set ("aim_difficulty",([ "gangolion":33,"vascular":38]) );
	set("special_defense", (["all":17,"none":20]) );
    set ("weight", 40);
    set ("tactic_func","steal");
    equip_armor(TARMOR"thief_amulet");
    equip_armor(TARMOR"simple_boots");
    wield_weapon(TWEAPON"thief_dagger");
    equip_armor(TARMOR"small_cloth");
}
int steal()
{
  object victim;
  string name,c_name;
  if (!(victim=query_attacker())) return 0;
  name =victim->query("name");
  c_name =victim->query("c_name");
  if (random(10)<2) { 
  tell_room(environment(this_object()),
  "\n時遷一甩手，射出一把金錢鏢攻擊敵人....\n\n"
);
  victim->receive_special_damage("none",10);
  victim->add("wealth/gold",1);
return 1;
}
  if (random(10)<2 && victim->query("wealth/gold")>10) {
  tell_room(environment(this_object()),
  "\n時遷偷走了"+c_name+"一些錢，順便賞他一巴掌....\n\n"
);
  victim->receive_special_damage("evil",8);
  victim->set("wealth/gold",(int)(victim->query("wealth/gold"))-10);
  return 1;
}
return 0;
}

