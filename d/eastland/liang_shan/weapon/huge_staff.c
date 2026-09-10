#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("iron staff","水磨禪杖");
       add("id",({"staff"}) );
       set_short("水磨禪杖");
	   set_long(@C_LONG
這是一種特殊的金屬做成的禪杖，由於普通的方法無法鍛造，只
有以水沙慢慢打磨，故名水磨禪杖．是魯智深最趁手的武器．
C_LONG	);
	
	set( "unit", "把" );
 	set( "weapon_class", 42 );
        set("type","blunt");
	set( "min_damage", 25 );
	set( "max_damage", 47 );
	set( "weight", 230 );
	set( "nosecond", 1 );
	set( "value", ({ 933, "gold" }) );
	
}	
