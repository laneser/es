#include <mudlib.h>
inherit WEAPON;

void create()
{
	if ( clonep(this_object()) ) {
        set_default_ob(__FILE__);
        return;
	}
  set_name("orc blunt", "獸人權杖");
  add("id", ({"blunt","orc blunt"}) );
  set_short("a orc blunt","獸人權杖");
  set_long(
   "一把黑鋼鑄成的權杖，上面雕了一隻半獸人的雕像。\n"
  );
  set( "unit", "把" );
  set( "weapon_class", 40 );
  set( "type","blunt");
  set( "min_damage", 15 );
  set( "max_damage", 40 );
  set( "weight", 100 );
  set( "value", ({ 8000, "silver" }) );
  set( "hit_func", "weapon_hit" );
  set_c_verbs ( ({
   "%s霎間「一刀兩斷、奪命三劍客」兩式，打在%s",
   "%s霎間「流星斬、趕月鍘」兩式，攻向%s",
   "%s霎間「十字東征、千軍萬馬」兩式，斬向%s",
   "%s霎間「撒旦血盟、惡魔有約」兩式，刺向%s",
             }) ) ;
}

int weapon_hit( object victim, int damage )
{
   object owner ;
   int inte ;

   owner = environment();
   inte = owner->query_stat("str");
   if (!victim) return 0;
   if ( random(100) > 80 ) {
     tell_object( owner,
       "\n權杖突然光芒萬丈，嗡嗡作響，一道閃光向"
           +victim->query("c_name")+"射去\n\n" );
     tell_object( victim,
       "\n"+owner->query("c_name") 
           + "權杖突然嗡嗡作響併發出一道閃光，向你襲來!\n\n" );
     tell_room( environment(owner),
       "\n" +owner->query("c_name") 
           + "的權杖突然嗡嗡作響併發出一道閃光向" + victim->query("c_name") 
           + "射去!\n\n", ({ victim, owner }) );
     victim->receive_special_damage( "energy", inte );
     return inte;
   }
}
