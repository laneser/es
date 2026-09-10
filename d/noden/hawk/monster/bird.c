inherit MONSTER;

void create()
{
	::create();
	set_level(2);
	set_name( "Bird", "野鳥" );
	add("id",({"Bird"}) );
   	set_short( "野鳥" );
	set_long(
		"一隻顏色完全不漂亮的野鳥，似乎正忙著覓食呢.\n"
	);
	set( "alignment", 0 );
	set( "time_to_heal", 10 );
	set_natural_armor( 7, 2 );
	set_natural_weapon( 5 , 3 , 5 );
	set( "wealth/silver", 40 );
}

