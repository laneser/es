#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name( "little boy", "小男孩" );
	add( "id", ({ "boy" }) );
	set_short( "小男孩" );
	set_long(
		"這個小男孩有黑色的眼珠和紅色的頭髮，他看起來餓了許多天，眼中流露出\n"
		"害怕的眼神。\n"
	);
	set_skill( "dodge", 10 );
   set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 1000 );
	set( "alt_corpse", "/d/noden/house/monster/devil" );
	set( "chat_chance", 10 );
	set( "chat_output", ({
		"小男孩說道: 陪我玩遊戲好嗎？\n",
		"小男孩好奇地打量著你。\n",
		"小男孩愉快地對著你微笑。\n"
	}) );
	set( "inquiry", ([
		"name" : "我....沒有名字，爸爸媽媽在我出生的時候就死了....\n" 
	]) );
}

void die()
{
	tell_room( environment(this_object()), 
		"小男孩咳出幾口鮮血，倒在地上 ....\n\n"
		"你聽到一陣沙啞的聲音從小男孩的屍體發出: 「你以為這樣就完了嗎？休想！」\n\n"
		"小男孩的屍體又站了起來！\n\n" ,
		this_object() );
	::die(1);
}
