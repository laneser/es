#include "../nodania.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name("poorman child", "窮人孩子");
	add( "id", ({ "child" }) );
	set_short("窮人孩子");
	set_long(
		"這個小孩子滿身髒汙，一雙大眼睛正貪婪地望著你的口袋。\n"
	);
	set_skill( "dodge", 10 );
	set( "alignment", 150 );
	set( "wealth/silver", 1 );

	set( "gender", "male" );
	set( "race", "halfling" );
}
