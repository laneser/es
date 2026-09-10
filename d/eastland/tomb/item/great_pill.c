#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name( "great pill", "九轉金丹" );
	add( "id", ({ "pill" }) );
	set_short( "九轉金丹" );
	set_long(
		"這是一顆金色的丹藥，有一股芬芳的香味。\n"
	);
	set( "unit", "顆" );
	set( "weight", 1 );
	set( "value", ({ 1000, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
	add_action( "eat_pill","eat" );
}

int eat_pill(string str)
{
	object player,ob;
	int i,chinese_mode;
    
    	player = this_player();
    	chinese_mode = can_read_chinese(player);
    
	if ( !str || str=="") 
       		return 0;  
	if ( str == "pill" && present( "great pill", player ) )
	   {	   
		write( 
		"你吃了丹藥後，覺得全身三萬六千個毛孔，無一不舒暢。\n"
		);
		player->set("hit_points", (int)player->query("max_hp") );
		player->set("spell_points", (int)player->query("max_sp") );
		player->set("talk_points", (int)player->query("max_tp") );
		player->set("force_points", (int)player->query("max_fp") );
		player->set("medication_resistance", 0);
		remove();
		return 1; }
	else return 0;
}