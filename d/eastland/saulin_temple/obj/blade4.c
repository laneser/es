#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "long blade", "長刀" );
	add( "id", ({ "blade", }) );
	set_short( "長刀" );
	set_long(
		"這是般若堂武僧使用的長刀, 刀身寬而長, 是少林中常見的兵器。\n" 
	);
	set( "unit", "柄" );
	set( "type", "longblade" );
	set( "weight", 130 );
	set( "weapon_class", 22 );
	set( "min_damage", 10 );
	set( "max_damage", 20 );
	set( "value", ({ 490, "silver" }) );
}
