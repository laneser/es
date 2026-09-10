#include "../oldcat.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(17);
	set_name( "Left Guard", "左護衛" );
	add ("id", ({ "guard" }) );
	set_short( "左護衛－左青城" );
	set_long(
             @LONG
左護衛－左青城、是當年曾力戰兩湖水怪的英雄，在一次除妖的時後，身受重傷，恰
好被龍王遇到，因而獲救，從此就跟著龍王一起修煉，並且擔任龍王的護衛。
LONG
	);
    set( "alignment", 1000 );
    set( "gender", "male" );
    set( "race", "human" );
//    set( "pursuing" ,1);
    set( "unit", "個" );
    set( "likefish",1);
    set_perm_stat( "dex", 23 );
    set_perm_stat( "str", 25 );
    set_perm_stat( "int", 20 );
    set_perm_stat( "con", 27 );
    set_perm_stat( "piety", 10 );
    set_perm_stat( "karma", 21 );
    set("max_hp", 800);
    set("hit_points", 800);
    set("wealth", ([ "gold": 50 ]) );
    set_natural_weapon( 10, 10, 15 );
    set_natural_armor( 35, 20 );
    set("weight", 800);
    set("exp_reward",32590 );
    set_experience(950000);
    set_skill("parry",80);
    set_skill("block",80);
    set_skill("dodge",85);
    set("unbleeding", 1);
    set("special_defense", ([ "all" : 50, "none" : 40 ]) );
    set("aim_difficulty", ([ "critical" : 50 ]) );
    set("chat_chance",5);
    set("att_chat_output", ({
      "\n左青城說：你們比那些爛妖怪還差，再去修煉個五百年再來吧。\n\n"
    }) );
    wield_weapon( OWEAPON"axe1" );
    equip_armor( OARMOR"mail7" );
    equip_armor( OARMOR"shield2" );
    set("tactic_func", "special_attack"); 
}

int special_attack()
{
    object *victim;
    int i;
    
    if( !(victim = query_attackers()) || (random(10)<5) ) return 0;
    tell_room( environment( this_object() ),
      "\n左青城大喊: 看我的絕招 天雷破! \n"+
      "只見左青城舉起斧一劈，只聽得一陣雷聲，一道閃電直擊向所有的敵人。\n\n",
      this_object()
    );
    i = sizeof(victim);
    while(i--) {
      victim[i]->receive_damage(random(10)+25);
    }
    return 1;
}
