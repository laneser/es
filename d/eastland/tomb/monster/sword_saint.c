#include "../almuhara.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(18);
	set_name( "Sword Saint", "劍聖" );
	add( "id", ({ "saint", "guard" }) );
	set_short( "劍聖" );
	set_long(
		"你看到一位神情冷漠的年輕人坐在這兒。雖然他對於你的到來絲毫沒有反應，但\n"
		"是你想總比另外兩個人好溝通。你不妨問他有關這兒(here)的事。\n"
			);
	set( "gender", "male" );
	set( "race", "daemon" );
	set( "alignment", 1000 );
	set( "hit_points", 1200 );
	set( "max_hp", 1200 );
	set_natural_armor( 110, 45 );
	set_natural_weapon( 50, 30, 40 );
	set_perm_stat( "str", 23 );
	set_perm_stat( "dex", 29 );
	set_perm_stat( "int", 29 );
	set_perm_stat( "pie", 23 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "kar", 25 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "tactic", 100 );
	set("alt_corpse","NONE");
	set( "tactic", "melee" );
	set( "force_effect", 8 );
	set( "force_type", "cold" );
	set( "wealth/gold", 200 );
	set( "special_defense", ([ "all": 50,"none":60 ]) );
        set( "aim_difficulty", ([ "vascular":20 ]) );
        set( "tactic_func", "my_tactic");
        set( "inquiry", ([
"here" : 
	    "這兒是我的練劍室，我想你是要問劍冢(sword_tomb)吧....\n" ,
"sword_tomb" : 
	          "劍冢是皇帝下令興建的。因為皇帝喜愛收集各種劍，又想要這些劍永遠\n"
	          "陪伴他，於是下令興建劍冢。\n" ,
"stone" : 
	     "那石墩是一個由大國師  孝光所施的封印(seal)。由於冢內的一把邪劍在吸取\n"
	     "了此處的靈氣，竟幻化成一之異常邪惡的奇獸。國師當時無力將其除去，只有把它封在封\n"
	     "印中，等待後人能除此異獸。\n" ,
"seal" : 
	     "我也不是很清楚，你可以試著問問那兩個小童。\n" ,
	     ]) );     
	wield_weapon( WEAPONS"/antique_sword" );
}

int my_tactic()
{
  object victim;
  
  if ( !(victim=query_attacker()) || (random(10)>3)) return 0;
  tell_object(victim,
       "\n劍聖對你大喊 : 看「劍二十一」 !!\n");
	tell_room(environment(this_object()),
		sprintf("劍聖對%s大喊 : 看「劍二十一」 !!\n\n",
			victim->query("c_cap_name")),({ this_object(),victim }) );
  victim->receive_damage( 25 + random(15));
  return 1;
}

int is_a_weapon(object item)
{
 	return ((int)item->query("wielded")) ;
}

void relay_message(string class1,string msg)
{
     string who,str,tmp;
     object *weapons,obj;
     
     if( sscanf( msg, "%s(%s)走了過來。\n", tmp,who )==2 ) 
        {
         obj = find_player(lower_case(who));
         if(!obj) return ;
	weapons = filter_array( all_inventory( obj ), "is_a_weapon", this_object() );
	if( !weapons || !sizeof(weapons) ) return;
	tell_object( obj,"劍聖手上之劍突然響起一聲輕吟，似乎要和你的武器一較長短。\n" );
	this_object()->kill_ob(obj);
	return;
	}
}

void die()
{
	tell_room( environment(this_object()), 
		"劍聖仰天大笑 : 我終於敗了 !! 我終於敗了 !!\n長笑聲中，劍聖的身體化成飛灰，紛飛四散。\n\n" ,
		this_object() );
	::die(1);
}
