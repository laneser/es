
#include "hole.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "鐘乳石洞穴" );
	set_long(@LONG
你忽然來到一處潮溼的洞穴，叮叮咚咚的水聲由洞穴深處傳來。
猛抬頭一看，幾根將近三尺的鐘乳石上，忽然落下幾滴清涼的水珠打
在你身上。剎時間你覺得彷佛置身仙境。在你的面前，幾根較粗大的
鐘乳石中間形成一灘小水池，裡邊的水看起來相當清澈，想必是由上
面的鐘乳石上凝結而成的。
LONG
		);
	set( "exits",([ 
			"north" : HOLE"water19",
			"out" : HOLE"hole30",
		]) );
	set( "item_desc",([ 
	"pool" : "水池裡清楚的映出你的倒影，你想喝喝(drink)裡邊的水嗎？\n" ]) );
	set( "water_source",2 );
	reset();
	
}

void init(){ add_action( "to_drink","drink" ); }

int to_drink(string str)
{
	string him;
	object player;
	int max;

	player=this_player();
	him=player->query( "c_name" );
	max=player->query( "max_tp" );
	if( !str || str!="water" )
		return notify_fail( "喝什麼？\n" );
	tell_room( environment(player),set_color(
	him+"彎下腰，喝了一口池塘裡的水，你發現"+him+"的臉上洋溢著幸福的表情。\n","HIY" ),player );
	tell_object(player,set_color(
	"你喝了一口池塘裡的水後，頓時覺得喉頭一陣清爽，突然想大喊幾聲。\n","HIY" ) );
	player->set( "talk_points",max );
	player->force_me( "shout 餘誓予至誠，致死效忠 ES ，若有二心，願請眾巫師和大神PK我... " );
	return 1;
}