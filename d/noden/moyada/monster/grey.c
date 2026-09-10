
#include "../moyada.h"

inherit TEACHER;
inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(18);
	set_name( "Grey", "葛雷" );
	add ("id", ({ "grey", "adventurer", }) );
	set_short( "旅遊冒險家 葛雷" );
	set_long( @LONG
    到世界各地尋找財寶的旅行冒險家, 有著灰色的頭髮和碧籃色的眼睛。
因為到過世界各地旅行, 而鍛練出傲人的肌肉和體魄, 看起來頗為自負。
LONG
	);
	set( "alignment", 1000 );
    set( "gender", "male" );
    set( "race", "human" );
    set( "pursuing" ,1);
    set( "unit", "個" );
	set_perm_stat( "dex", 23 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 12 );
	set_perm_stat( "con", 27 );
	set_perm_stat( "piety", 9 );
	set_perm_stat( "karma", 21 );
	set("max_hp", 950);
	set("hit_points", 950);
	set("wealth", ([ "gold": 50 ]) );
	set_natural_weapon( 35, 15, 35 );
	set_natural_armor( 35, 30 );
    set("weight", 800);
    set("exp_reward",19000 );
    set_experience(450000);
    set_skill("parry",80);
    set_skill("block",60);
    set_skill("dodge",85);
    set("unbleeding", 1);
    set("special_defense", ([ "all" : 50, "none" : 40 ]) );
    set("aim_difficulty", ([ "critical" : 50 ]) );
    wield_weapon( MOYADA"obj/grey_sword" );
    equip_armor( MOYADA"obj/snake_plate" );
    equip_armor( MOYADA"obj/dragon_shield" );
   set( "chat_chance", 12 );
   set( "chat_output", ({
         "葛雷嘆道: 都沒有學生可以教, 真無聊!\n" }) );
    set( "inquiry", ([
            "help" : "@@ask_help",
            "train" : "你想學如何用盾牌抵擋敵人的攻擊嗎?\n" ]) );
    set("tactic_func", "special_attack"); 
    set_lessons( ([
                "block" : ({ 200, 50 })
    ]) );
}

void init()
{
   npc::init();
   teacher::init();
}

void ask_help( object who )
{
    tell_object( who, 
      "葛雷說: 你來的正好, 這家店的老闆好像正想用人, \n"
      "        你可以問他看看還有沒有(job)。\n" 
    );
}

// 10% use it! damage 40-50.
int special_attack()
{
    object *victim;
	        int i;
    
    if( !(victim = query_attackers()) || (random(10)>1) ) return 0;
    tell_room( environment( this_object() ), 
      "\n葛雷大喊: 看我的絕招 真空斬! \n"+
      "  只見葛雷舉劍一劈，無數條彎月型的光波向所有敵人射去。\n" ,
      this_object()
    );
    i = sizeof(victim);
    while(i--) {
      victim[i]->receive_damage(random(10)+40);
      "/d/magic/magic"->report( this_object(), victim[i] );
    }
    return 1;
}

int check_trainee(object who)
{
    if( (string)who->query("class")=="adventurer" &&
        (int)who->query_level()>4 )
    return 1;
    else return notify_fail(
      "葛雷說: 我只教夠資格的冒險者。\n" );
}

