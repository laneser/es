//key issue of lizard_quest, modify it more easy, by Tsunami '96/09/15
#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "小水晶池" );
	set_long(@LONG
廣場的正中央有座設計精美的小水池，由精心雕刻的水晶構成，
一道潺潺的小流水自上頭的裂縫留下，為這個單調的洞穴增添不少的
色彩。	
LONG
		);
	set( "light",1 );
	set( "exits",([
			"east"  : HOLE"hole27",
			"west"  : HOLE"hole21",
			"south" : HOLE"hole25",
			"north" : HOLE"hole23"
			]) );
	set( "objects",([
			"girl#1" : HMONSTER"girl",
			"girl#2" : HMONSTER"girl",
			]) );
	set( "item_desc",([
	"pool" : "水池裡清楚的映出你的倒影，你想喝喝(drink)裡邊的水嗎？\n" ]) );
	set( "water_source",1 );
	seteuid( geteuid() );
	reset();
}

void init(){ add_action( "to_drink","drink" ); }

int to_drink(string str)
{
	string him;
	object player, ob;
	int max;

	player=this_player();
	him=player->query( "c_name" );
	max=player->query( "max_tp" );
	if( !str || str=="" )
		return notify_fail( "你想喝什麼？\n" );
	if( str=="water" ){
	  if( player->query_temp("lizard_quest/get_saw")){
	  tell_room( environment(),set_color(
	  him+"彎下腰想喝口水，但因腳滑了一下，一頭向池邊水晶牆撞去...！\n","HIR" ),
	  player);
	  write("你彎下腰想喝口水，卻因不慎滑倒，一頭撞向牆壁，把牆角咬下一塊...\n");
          ob = new(HOBJ"amethyst");
          ob->move(player); 
          player->set_explore("island#9");
          }else{
	  tell_room( environment(player),set_color(
	  him+"彎下腰，喝了一口池塘裡的水，你發現"+him+"的臉上洋溢著幸福的表情。\n","HIY" ),player );
	  tell_object(player,set_color(
	  "你喝了一口池塘裡的水後，頓時覺得喉頭一陣清爽，突然想大喊幾聲。\n","HIY" ) );
//	seteuid(geteuid(player));
//	player->force_me( "shout test....\n" );
	  }
	  return 1;
        }
        return notify_fail("你到底想要喝什麼？\n");
}
