#include <mudlib.h>
#include <conditions.h>

inherit MEDICINE;

void create()
{
	medicine::create();
	set_name("speed pill", "逍遙遊" );
	add( "id", ({"pill"}) );
	set_short("逍遙遊");
	set_long(
		"這是由刑大娘研發出的解藥,專門解除各種麻痺的症狀。\n"
		"如果你覺得肌肉僵硬,吃(eat)下它應有不錯的效果!\n"
	);
	set( "can_eat", 1 );
	set( "unit", "粒" );
	set( "weight", 15 );
	set( "value", ({ 50, "silver" }) );
	set( "medication", 50 );
}

void eat(object player)
{
    int stat;
    
	if( !player->query("conditions/slow") ) return;
	tell_object( player, can_read_chinese(player)?
		"你覺得肌肉不再僵硬了！\n": "You recover from poison!\n" );
	stat = (int) player->query("slow");
	player->modify_stat("dex",stat);	
	"/std/conditions/slow"->remove_effect(player);
}
