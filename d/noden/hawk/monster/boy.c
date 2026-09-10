inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "hawkman boy", "鳥人族小男孩" );
	add("id",({"boy","hawkman"}) );
   	set_short( "鳥人族小男孩" );
	set_long(
		"活蹦亂跳的鳥人族小男孩，翅膀上的毛都還沒長齊呢.\n"
	);
	set( "gender", "male" );
	set( "race", "hawkman" );
	set( "alignment", 320 );
	set( "time_to_heal", 10 );
	set_natural_armor( 13, 2 );
	set_natural_weapon( 5 , 2 , 3 );
	set_perm_stat( "kar", 10 );
	set( "wealth/silver", 20 );
}

