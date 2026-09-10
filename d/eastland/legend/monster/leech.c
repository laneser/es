#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
#include "../magic.c"

inherit MONSTER;

void create()
{
  ::create();
  set_level(18);
  set_name("crystal leech", "天水螞蝗");
  add( "id", ({ "leech" }) );
  set_short("天水螞蝗");
  set_long(@LONG
一種吸血水蛭，因為通體透明，就如同天池之水一般，所以人稱天水螞蝗。每
當它吸食其他動物血液的時候，自身透明的體液和鮮血混在一起，會變成如玫
瑰石般□麗的色澤，十分好看。
LONG
    );
  set( "race", "amphibia" );
  set( "unit", "只" ); 
  set( "alignment", -800 );
  set_natural_armor( 10, 20 );
  set( "max_hp", 600 );
  set( "hit_points", 600 );
  set_skill("dodge",100);
  set_perm_stat( "int", 20 );
  set_perm_stat( "dex", 25 );
  set_perm_stat( "kar", 30 );
  set_natural_weapon(60,30,50);
  set("aim_difficulty",(["critical":90,"ganglion":50]));
  set("special_defense",(["all":40,"none":20]));
  set( "killer", 1 );
  set( "time_to_heal", 40 );
  set( "tactic_func", "emit_poison" );
  set_c_limbs( ({ "頭部", "身體", "腹部", "尾部" }) );
  set_c_verbs( ({ "%s狠狠的咬住%s的皮膚，開始吸血" ,
                  "%s用腹部尖銳的牙齒劃破了%s的皮膚"
                  }) );
}

int emit_poison()
{
  object victim;

  if( random(20)>8 || !(victim= query_attacker()) ) return 0;   
  if (random(5)>2) { 
    tell_object( victim,
      "\n螞蝗緊緊的咬住你的手臂，只見螞蝗的顏色由透明轉為粉紅，鮮豔異常....\n\n"
      );
    victim->receive_damage(30);
    this_object()->receive_healing(30);  
    report(this_object(),victim);
    return 1;
  }
tell_object(victim,
  "你的大腿因為被螞蝗咬了一口而麻痺了......\n");
  victim->block_attack(2);
  return 1;
}
void die()
{
     object killer;
     if ( killer=query("last_attacker") ) killer->add_temp("mobs",4);
     ::die();
}