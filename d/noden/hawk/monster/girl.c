inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "hawkman girl", "鳥人族小女孩" );
	add("id",({"girl","hawkman"}) );
   	set_short( "鳥人族小女孩" );
	set_long(
		"活蹦亂跳的鳥人族小女孩，正和旁邊的小男孩嘻鬧呢.\n"
	);
	set( "gender", "female" );
	set( "race", "hawkman" );
	set( "alignment", 370 );
	set( "time_to_heal", 10 );
	set_natural_armor( 13, 2 );
	set_natural_weapon( 5 , 2 , 3 );
	set_perm_stat( "kar", 15 );
	set( "wealth/silver", 60 );
}

