#include "../hole.h"

inherit WEAPON;
void create()
{
	set_name( "Magic Chabok","魔法長鞭" );
	add( "id",({ "chabok","whip" }) );
	set_short( "魔法長鞭" );
	set_long(@LONG
	一把用藤蔓編成的長鞭，經過蜥蜴人祭司--拉
	索達--長年用魔法浸漬的結果，使得它擁有特
	殊的魔力。
LONG
	);
	set( "unit","把" );
	set( "type","whip" );
	set( "weapon_class",33 );
	set( "min_damage",15 );
	set( "max_damage",30 );
	set( "weight",120 );
	set( "value",({ 1280,"silver" }) );
	set_c_verbs( ({ "%s向%s猛抽一鞭" }) );
}