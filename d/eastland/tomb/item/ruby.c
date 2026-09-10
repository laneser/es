#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name( "shining ruby", "紅寶石" );
	add( "id", ({ "ruby","stone","gem" }) );
	set_short( "閃閃發光的紅寶石" );
	set_long(
		"這是一顆閃閃發光的紅寶石。\n"
	);
	set( "unit", "顆" );
	set( "weight", 5 );
	set( "value", ({ 10, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "put_ruby","put" );
}

int put_ruby(string str)
{
	object player,ob;
	string orb;
	int i,chinese_mode;
    
    	player = this_player();
    	chinese_mode = can_read_chinese(player);
    
	if ( !str || str=="") 
       		return 0;  
	if ( str == "ruby in hole" && present( "guilt", player ) )
	   {	   
		write( 
		"當你把紅寶石放入小洞時，邪像眼中的光芒忽然一暗，接著大盛 !! \n"
		);
		player->set_temp("NO_DRAIN", 1);
		remove();
		return 1; }
	else return 0;
}