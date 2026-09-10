#include "../almuhara.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Sword Slave", "劍奴" );
	add( "id", ({ "slave", "guard" }) );
	set_short( "劍奴" );
	set_long(
		"你看到一位冷酷的年輕人坐在這兒。他的雙目微閉，對於你的到來絲\n"
		"毫沒有反應。\n"
	);
	set( "gender", "male" );
	set( "race", "orc" );
	set( "alignment", 1000 );
	set( "hit_points", 1200 );
	set( "max_hp", 1200 );
	set_natural_armor( 100, 35 );
	set_natural_weapon( 40, 20, 30 );
	set_perm_stat( "str", 22 );
	set_perm_stat( "dex", 28 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "pie", 20 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "kar", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "tactic", 100 );
	set("alt_corpse","NONE");
	set( "tactic", "berserk" );
	set( "force_effect", 8 );
	set( "force_type", "cold" );
	set( "wealth/gold", 200 );
	set( "special_defense", ([ "all": 50,"none":60 ]) );
        set( "aim_difficulty", ([ "vascular":20 ]) );
        set( "tactic_func", "my_tactic");
   
	wield_weapon( WEAPONS"/gemmy_sword" );
}

int my_tactic()
{
  object victim;
  int dam;
  
  if ( !(victim=query_attacker()) || (random(10)>2)) return 0;
  tell_object(victim,
       "\n劍奴手上之劍突然泛起滿天劍氣向你而來 !!\n");
	tell_room(environment(this_object()),
		sprintf("劍奴手中之劍突然泛起滿天劍氣向%s刺去 !\n\n",
			victim->query("c_cap_name")),({ this_object(),victim }) );
  dam = 23 + random(7);
  victim->receive_damage(dam);
  return 1;
}

int is_a_weapon(object item)
{
 	return ((int)item->query("wielded")) ;
}

void relay_message(string class1,string msg)
{
     string who,str,aa;
     object *weapons,obj;
     
     if( sscanf( msg, "%s(%s)走了過來。", aa , who )==2 )      
        {
         obj = find_player(lower_case(who));
         if(!obj) return ;
	weapons = filter_array( all_inventory( obj ), "is_a_weapon", this_object() );
	if( !weapons || !sizeof(weapons) ) return;
	tell_object( obj, 
		"劍奴手上之劍突然響起一聲輕吟，似乎要和你的武器一較長短。\n");
	this_object()->kill_ob(obj);
	return;
	}
}

void die()
{
	tell_room( environment(this_object()), 
		"\n劍奴詭異地一笑，突然化成飛灰隨風四散。\n\n" ,
		this_object() );
	::die(1);		
}	 	