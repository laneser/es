#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "The Scholar", "文臣" );
	add( "id", ({ "scholar" }) );
	set_short( "文臣" );
	set_long(
		"你看到一位長滿白鬍子的魚頭人身的怪物，他是龍王的諮詢對象。\n"
	);
	set( "unit", "名" );
	set( "race", "monster" );
	set( "gender", "male" );
	set( "alignment",  800 );
        set( "likefish",1);
	set( "max_hp", 500 );
	set( "hit_points", 500 );
	set( "special_defense", ([ "all": 40, "none" : 20, ]) );
	set( "aim_difficulty", ([ "critical" : 35, "vascular" : 25, ]) );
	set_natural_armor( 53, 23 );
	set_natural_weapon( 5, 0, 10 );
	set( "wealth/gold", 10 );
	set( "tactic_func", "my_tactic" );
	set_perm_stat( "str", 15 );
	set_perm_stat( "dex", 24 );
	set_perm_stat( "int", 28 );
	set_perm_stat( "pie", 25 );
	set_perm_stat( "kar", 23 );
	set_skill( "dodge", 90 );
        set("chat_chance",10);
        set("chat_output",({
         "文臣：龍王最近愁眉深鎖，不知道發生了什麼事。\n"
        }) );

	wield_weapon(OWEAPON"dagger03" );
	equip_armor( OARMOR"ring2" ); 
	equip_armor( OARMOR"cloth2" );
}

int my_tactic()
{
	object *victim;
	int i;

	if( !(victim = query_attackers()) ) return 0;
	if( random(20)>2 ) return 0;
	tell_room( environment(this_object()),
	  "文臣口中念道:『陰陽順逆妙難窮，二至還鄉一九宮。』\n"
          "文臣口中念道:『若能了達陰陽理，天地都來一掌中。』\n"
	  "\n突然，四周的水開始急速的旋轉，如一大旋渦般的把你捲入其中 !\n"
	, this_object()
	);
	for ( i=0; i < sizeof(victim) ; i++) {
	  victim[i]->receive_special_damage("divine", random(10));
          victim[i]->block_attack(5);
          victim[i]->set_temp("msg_stop_attack",
            "( 你被轉得七暈八素的，身體完全不能控制 ! )\n");
        }
	return 1;
}
