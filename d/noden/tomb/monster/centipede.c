
#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(15);
   set_name("purple centipede", "紫蜈蚣");
   add( "id", ({ "centipede" }) );
   set_short("紫蜈蚣");
	set_long(
     "你看到一隻巨大的紫蜈蚣, 渾身紫黑, 一雙深紅的眼睛正盯著你,\n"
     "令你不禁倒抽一口涼氣!\n"
	);
   set("race","insect");
   set( "unit", "條" );
   set( "alignment", -1000 );
   set( "exp_reward", 15562 );
   set_natural_armor( 55, 34 );
   set_natural_weapon( 25, 8, 17 );
   set( "max_hp", 800 );
   set( "hit_points", 800 );
   set_perm_stat( "int", 10 );
   set( "block_aim", ({ "weakest" }) );
   set( "killer", 1 );
	set( "tactic_func", "emit_poison" );
   set_c_limbs( ({ "頭部", "身體", "足部" }) );
   set_c_verbs( ({ "%s的尾巴掃向%s", "%s的頭部撞向%s" }) );
   equip_armor( "/d/noden/tomb/obj/ankh" );
}

int emit_poison(object victim)
{

   if( random(20)>5 || !(victim= query_attacker()) ) return 0;
if( 2<random(20)<6 ) {
    tell_room( environment(this_object()),
       "\n紫蜈蚣突然附在你的身上, 狠狠地咬了你一口...\n",
		this_object() );
   (CONDITION_PREFIX + "simple_poison")->apply_effect( victim,20,20 );
   }
   if( random(20)<3 ) {
   tell_object(victim,
       "\n紫蜈蚣突然噴出一團黑色的氣體在你臉上...\n\n" );
   (CONDITION_PREFIX + "slow")->apply_effect( victim,15, 5 );
   }
	return 1;
}

void die()
{
        object killer;

        killer = query("last_attacker");
        if( killer ) killer->set_explore("noden#19");
        ::die();
}
