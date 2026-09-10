#include "mudlib.h"

inherit WEAPON;

void create()
{
#include <compress_obj.h>
       set_name("wooden club","檜木棒");
       add("id",({"club",}) );
       set_short("檜木棒");
       set_long(
           "一條連樹皮都還沒撥乾淨的檜木棒\n"
     	);
	
	set( "unit", "把" );
 	set( "weapon_class", 25 );
	set("type","blunt");
	set( "min_damage", 5 );
	set( "max_damage", 25 );
	set( "weight", 200 );
	set( "value", ({ 1, "gold" }) );
}
