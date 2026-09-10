#include <mudlib.h>
inherit MONSTER;
void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(19);
	set_name("pickering", "畢克林老爹");
	set_short( "畢克林老爹");
	set_long( @LONG
    畢克林老爹是小偷界最受人尊重的人，他不僅德高望重，而且技藝高超，
據說他年輕的時候曾經偷走了國王的配劍，結果和追蹤而來的雷思騎士團團長
( 當時是第一騎兵隊小隊長 )數度交手，最後結成好友，後來他屢次為國王出
秘密任務，成為國王最信任的密探。他退休後，致力於小偷界的安定和和平，
於是小偷界的兩大集團公推他為大長老，主持小偷公會。
LONG
	);
	set_perm_stat("str", 25);
	set_perm_stat("int",27);
	set_perm_stat("dex", 32);
	set_perm_stat("kar", 30);
	set_skill( "dagger", 100 );
	set_skill( "dodge", 100 );
	set_skill( "anatomlogy",100);
	set( "max_hp", 560 );
	set( "hit_points", 560 );
	set( "gender", "male" );
	set( "race", "human" );
    	set( "aiming_loc", "weakest" );
	set( "alignment", 1200 );
	set_natural_armor( 120, 35 );
	set_natural_weapon( 25, 13, 30 );
	set("special_defense", ([
		   "electric" : 20,
		   "evil" : 30,
		   "energy" : 20,
		   "fire" : 40,
		   "cold" : 30,
		   "none":30 ]) );
	set("aim_difficulty",
			([ "vascular":35, "ganglion":50 ]) );
    	wield_weapon("/d/thief/hall/weapons/pick_dagger");
    	equip_armor("/d/thief/hall/armors/lucky_amulet");
	set( "tactic_func","my_tactic" );
}

object query_equip(object who)
{
	object *inv,ob;
	int flag = 1;

	ob = 0;
	inv = all_inventory(who);
	while ( flag && flag < 6 ) {
		ob = inv[random(sizeof(inv))];
		if ( ob->query("prevent_drop") || ob->query("wielded") ) {
			flag++;
			continue;
		} else
			return ob;
	}
	return 0;
}


#define TMP_ROOM "/u/r/ruby/rooms/workroom" 
#define ORG_ROOM "/d/thief/hall/thief_guild"

int my_tactic()
{
	object me,victim,env,ob;
	int i;

	me = this_object();
	victim = query_attacker();
	env = environment(me);

	if ( (string) victim->query_class() == "thief" ) {
		if ( (int)victim->query_temp("backstabed") == 1 ) 
			victim->set_temp("hidding",0);
	}

	if ( (int) victim->query_temp("pickering_bs") == 1) {
		string msg;
		victim->receive_damage( 80 + random(50) );
        	msg = "/adm/daemons/statsd"->status_string(victim) ;

		tell_room(env,set_color(sprintf(
		"%s的身影突然從%s背後浮現出來，眼中殺機重重....\n",
		me->query("c_name"),victim->query("c_name")),"HIY",victim),victim);
		tell_object(victim,set_color(sprintf(
		"\n%s的身影突然從你背後浮現出來，眼中殺機重重, 你覺得不妙!! \n",
		me->query("c_name")),"HIR",victim) );
		tell_object(victim,sprintf("(你%s)\n",msg));
		victim->set_temp("pickering_bs",0);
		victim->kill_ob(me);
		return 0;
	}

	switch( random(25) ) {
	    case 1..3 : // 偷裝備
		ob = query_equip(victim);
		if ( ob ) {
		    ob->move(me);
		    tell_object(victim,
			set_color("你覺的有點怪怪的,好像有點不對勁...\n","HIR",victim));
		}
		return 0;
	    case 16..19 :
		i = (int) victim->query("wealth/silver");
		if ( i > 500 )
			victim->debit("silver",random(500));
		else
			victim->debit("silver",random(i));
		return 0;
	    case 20..24 :
		me->move(find_object_or_load(TMP_ROOM));
		victim->set_temp("pickering_bs",1);
		tell_room(env,"突然間畢克林老爹消失了.......\n");
		call_out("IamHere",2,me);
		return 1;
	    default :
		return 0;
	}
}

int IamHere(object me)
{
	object env;
	me->move(ORG_ROOM);
}

