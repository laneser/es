#include "../asterism.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "a gnome magic student", "魔法學徒" );
	add("id",({"mage","gnome","student"}) );
   set_short( "魔法學徒" );
	set_long(
	"這個地精正在練習魔法。聽他有時結巴的咒文,有時要歪頭回想手印的神情.\n"
        "你斷定他才剛接觸魔法沒多久。\n"
	);
	set( "gender", "female" );
	set( "race", "gnome" );
	set( "alignment", 260 );
	set( "time_to_heal", 10 );
	set_natural_armor( 20, 9 );
	set_natural_weapon( 15 , 10 , 13 );
	set_perm_stat( "kar", 20 );
	set_perm_stat( "int", 20 );
	set("max_sp",600);
	set("spell_points",600);
	set_skill("concentrate",30);
	set_skill("target",30);
	set_skill("black-magic",40);
	set_skill("dodge",30);
	set_skill("dagger",80);
	set("spells",(["ether-bolt":2]));
	set( "wealth/gold", 10 );
//	wield_weapon(WEAPONS"sad_dagger");
//	equip_armor(ARMORS"cloak01");
	equip_armor(ARMORS"ring01");
        set( "tactic_func", "cast_help" ); 
}

int cast_help()
{ 
    object victim ;
    string name;
    int i;
    victim = query_attacker();
    
    if( !victim ) return 0; 

    if ( (int)this_object()->query("spell_points")< 300 )
       this_object()->set("spell_points",600);
    if ( random(10)<7 ) {
       name=victim->query("name");
       command("cast ether-bolt on "+name); 
       return 1;
       }
    else return 0;
}

