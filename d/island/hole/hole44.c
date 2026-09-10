#include <hole.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "地下王宮" );
	set_long(@LONG
你現在所站的的位置是蜥蜴人王宮的第二層，不過怎麼看都不像
是個達官貴人的棲息場所，倒不如說是個洞穴更為恰當；或許這是因
為蜥蜴人天生就比較不講究居住環境所造成的。再往下就是蜥蜴人領
袖『古茲曼』的住所。
LONG
	);
	set( "exits",([
			"south" : HOLE"hole42",
			"down" : HOLE"hole45",
			]) );
	set( "objects",([
			"guard#1" : HMONSTER"life_guard",
			"guard#2" : HMONSTER"life_guard",
			]) );
	set( "pre_exit_func",([ "down" : "check_invis" ]) );
	reset();
}

int check_invis()
{
	object player;
	string him;
	
	player=this_player();
	him=player->query( "c_name" );
	if( (int)player->query( "player_invisible" )==1 )
	{
	if( present( "guard",environment(player) ) ){
	tell_room( environment(player),set_color(
	"守衛怒言道：『偷偷摸摸地想幹嘛？當我倆是死人啊？』\n","HIR") );
	return 1;
	}
	else{
	tell_room( environment(player),set_color(
	"突然一道宏亮的聲音說：『別以為隱形就可以逃過我的法眼，乖乖現形吧。』\n","HIR") );
	return 1;
	}
	}
	return 0;
}
