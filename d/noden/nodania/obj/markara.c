#include <mudlib.h>

inherit WEAPON;

void create()
{
	seteuid( getuid() );
	set_name( "Sword of Markara", "瑪卡拉之劍" );
	add( "id", ({ "markara","sword" }) );
	set_short( "瑪卡拉之劍" );
	set_long(
        "這把瑪卡拉之劍是國王送給精銳騎士長戴利佛的武器，上面刻著許多\n"
		"美麗的花紋，這把美麗的劍是戴利佛最重視的武器。\n"
	);
	set( "unit", "把" );
	set( "weapon_class", 35 );
	set( "type", "longblade" );
	set( "min_damage", 19 );
	set( "max_damage", 36 );
	set( "weight", 120 );
	set( "value", ({ 230, "gold" }) );
}
