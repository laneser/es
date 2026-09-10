#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "cave worm", "洞穴蟲" );
	add( "id", ({ "worm" }) );
	set_short( "洞穴蟲" );
	set_long(@CLONG
這是一種叫做洞穴蛾的幼蟲，它的身上長著許多堅硬的剛毛，皮膚上覆蓋著
一層岩石般的角質，據說它的叫聲會使人喪失法力。
CLONG
	);
	set( "unit", "只" );
	set( "alignment", 100 );
	set( "natural_weapon_class1", 8 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 5 );
	set_perm_stat( "dex", 2 );
	set_perm_stat( "str", 4 );
	set( "hit_points", 300 );
	set( "max_hp", 300 );
	set( "natural_armor_class", 80 );
	set( "tactic_func", "my_tactic" );
	set_c_limbs( ({ "身體" }) );
	set_c_verbs( ({ "%s張開長滿利齒著口器刺向%s", "用身體的剛毛往%s刺去" }) );
}

int my_tactic()
{
	object *victim;

	if( random(20)<3 ) {
		tell_room( environment(this_object()), 
			"洞穴蟲發出一陣「嗶咕，嗶咕」的叫聲，你覺得一陣頭暈....。\n",
			this_object() );
		victim = query_attackers();
		if ( victim->query("spell_points"))
			victim->set( "spell_points", 0 );
		return 1;
	}
	return 0;
}

