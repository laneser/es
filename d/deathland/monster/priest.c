
#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	
	::create();
	set_level(17);
	set_name( "Dwarf priest", "矮人牧師" );
	add ("id", ({ "priest", "dwarf", }) );
	set_short( "矮人牧師" );
	set_long(
    "一個安靜的牧師,似乎他正在與惡神Yang溝通\n");

    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "個" );
	set_perm_stat( "str", 20 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "kar", 25 );
	set ("wealth", ([ "silver": 200 ]) );
	set_natural_weapon(12,13,22);
	set_natural_armor(30,40);
	set("special_defense",(["all":40,"none":30]) );
	set("aim_difficulty",(["critical":15,"weakest":15,"vascular":15]) );
    set ("weight", 400);
    set_skill("blunt",98);
    set_skill("parry",70);
	wield_weapon(Weapon"/mace02");
    equip_armor(Armour"/cloth01");
    equip_armor(Armour"/cloak02");
	equip_armor(Armour"/amulet01");
    set( "tactic_func", "cast_spell");	
}
int cast_spell()
{
    object victim;
    string name,c_name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    c_name= victim->query("c_name");
    
    if( random(10) < 4 ) {
      tell_room( environment(this_object()), 
        "矮人牧師召喚出一團火球攻擊"+c_name+"\n\n" );
      victim->receive_special_damage("fire", 43+random(12));
      report(this_object(),victim);
      return 1;
    }
    return 0;
}
