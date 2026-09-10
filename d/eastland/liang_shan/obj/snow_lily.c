#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name( "snow_lily", "天山雪蓮" );
	add( "id", ({ "lily" }) );
	set_short( "天山雪蓮" );
	set_long(@C_LONG
這是一朵練武之人夢寐以求的寶物天山雪蓮，服用(eat)它可以使人神完氣足
，功力恢復。
C_LONG
	);
	set( "no_sale", 1 );
	set( "unit","朵");
	set( "weight", 1 );
	set( "value", ({ 450, "gold" }) );
}

int eat_food(string arg)
{
	if( !arg || ( arg !="lily" && arg !="snow_lily")  ) 
	return notify_fail("吃什麼??"); 
	write( 
	"你吃下一朵天山雪蓮，從丹田升起一股真氣，遊走全身...\n" );
	tell_room( environment(this_player()), 
	this_player()->query("c_cap_name")+
	"吃下一朵天山雪蓮，又回復了生龍活虎的樣子\n" , this_player()
		);
		this_player()->receive_healing( 3+random(2) );
	        this_player()->set("force_points",(int)this_player()->query("max_fp"));
	remove();
	return 1;
}

