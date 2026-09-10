#include <mudlib.h>

inherit WEAPON;

void create()
{
   set_name( "crimson mace", "血紅釘頭槌" );
   add("id",({"mace",}));
   set_short("血紅釘頭槌");
   set_long(
        "一把普通的血紅釘頭槌。\n"
               );
	set( "unit", "把" );
   set( "weapon_class", 17 );
   set( "type", "blunt" );
   set( "min_damage", 9 );
   set( "max_damage", 20 );
   set( "weight", 150 );
   set( "value", ({ 50, "gold" }) );
   set("extra_skills",(["anatomlogy": 5]));
}
