#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "ugly toad", "癩蛤蟆" );
	add( "id", ({ "toad" }) );
	set_short( "癩蛤蟆" );
	set_long(
		"又大又醜癩蛤蟆，有著綠色、黏稠的皮膚。\n"
	);
	set_c_limbs( ({ "後腿", "頭部", "身體" }) );
	set_c_verbs( ({ "%s張嘴往%s一咬", "%s用它的舌頭往%s一舔" }) );
}
