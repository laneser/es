#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;
#include "../magic.c"

void create()
{
  ::create();
  set_level(17);
  set_name("poisonous moth", "鬼面蛾");
  add( "id", ({ "moth" }) );
  set_short("鬼面蛾");
  set_long(@LONG
嚇！好一張恐怖的鬼臉，仔細一瞧，更是不得了，居然是兇惡的鬼面蛾。據說
這種蛾類最喜歡吸食大行動物的腦汁，人類也是它的最愛之一．渾身上下的磷
粉都是劇毒，而且攻擊性極強，即使不是要進食，也會任意的毒殺其它動物．
LONG
    );
  set( "race", "insect" );
  set( "unit", "只" );
  set( "alignment", -1000 );
  set_natural_armor( 10, 10 );
  set( "max_hp", 500 );
  set( "hit_points", 500 );
  set_skill("dodge",100);
  set_perm_stat( "str", 22 );
  set_perm_stat( "int", 22 );
  set_perm_stat( "dex", 25 );
  set_perm_stat( "kar", 30 );
  set_natural_weapon(50,20,25);
  set("aim_difficulty",(["critical":80,"vascular":70,"ganglion":100]));
  set("special_defense",(["all":60,"none":40]));
  set( "killer", 1 );
  set( "time_to_heal", 20 );
  set( "tactic_func", "emit_poison" );
  set_c_limbs( ({ "頭部", "身體", "翅膀", "腹部" }) );
  set_c_verbs( ({ "%s對%s散下無數的磷粉" ,
                  "%s用翅膀揮向%s"
                  }) );
}

int emit_poison()
{
  object victim;
  int i;

  if( random(20)>8 || !(victim= query_attacker()) ) return 0;
  if ((i=random(16))>10) {
    tell_object( environment(this_object()),
      "你不小心吸進鬼面蛾散下的毒磷，神智逐漸模糊......\n"
      );
    (CONDITION_PREFIX + "confused")->apply_effect( victim, 7, 25 );
    victim->receive_special_damage("poison",40); 
    report(this_object(),victim);
    return 1;
  }
  else if (i>5) {
    tell_object( environment(this_object()),
      "鬼面蛾揮出一團磷粉，你一個失神，四肢觸碰到磷粉，手腳一陣□麻.....\n"
      ); 
    (CONDITION_PREFIX + "slow")->apply_effect(victim,20,10 );
    victim->receive_special_damage("poison",40); 
    report(this_object(),victim); 
    return 1;  
  }
  else {
    tell_object( environment(this_object()),
      "鬼面蛾叮了你一口.....\n"
      );
    (CONDITION_PREFIX + "simple_poison")->apply_effect(victim,7,25 );
    victim->receive_special_damage("poison",25);
    report(this_object(),victim);
    return 1;
  }
}
void die()
{
     object killer;
     if ( killer=query("last_attacker") ) killer->add_temp("mobs",4);
     ::die();
}