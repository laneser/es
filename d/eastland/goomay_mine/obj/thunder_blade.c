#include "../zeus.h"

inherit WEAPON;

void create()
{
	set_name("thunder blade", "雷霆刀");
	add ("id",({ "blade"}) );
	set_short("雷霆刀");
	set_long(@C_LONG
這把刀就是傳說中，石家車隊威震邊疆時，石家好漢所配的制式武器。
在刀中因為摻了稀世的寒鐵精華，所以無堅不摧，是把難得的好刀．
C_LONG
	);
	
	set( "unit", "把" );
	set_c_verbs( ({ "的%s使出－－石破天驚－－劈向%s", 
	                "的%s使出－－破釜沈舟－－斬向%s",
	                "的%s使出－－雷動天下－－橫劈%s",
	                "的%s使出－－神龍九現－－直砍%s",}) );
 	set( "weapon_class", 33 );
	set( "type", "longblade" );
	set( "min_damage", 23 );
	set( "max_damage", 38 );
	set( "weight", 250 );
	set( "value", ({ 2100, "silver" }) );
}