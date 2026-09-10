#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "martialist", "賣藝師傅" );
	add( "id", ({ "entertainer" }) );
	set_short("賣藝師傅" );
	set_long(
		"這位賣藝師傅原來是一家鏢局的鏢師，因為鏢局倒閉所以出來靠\n"
		"賣藝維生，他的拳腳功夫在這一帶是很有名的。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 300 );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 18 );
	set_skill( "dodge", 90 );
	set( "wealth/gold", 20 );
	set_natural_weapon( 40, 20, 35 );
	set_natural_armor( 55, 25 );
	set( "natural_weapon_class2", 30 );
	set( "natural_min_damage2", 13 );
	set( "natural_max_damage2", 25 );
	set( "chat_chance", 20 );
	set( "chat_output", ({
		"賣藝師傅說道: 小弟才疏學淺，請各位看倌多多指教。\n",
		"賣藝師傅縱身一跳，躍起大約四公尺高，然後飄然落地。\n",
		"賣藝師傅打了一套「黑虎拳」，拳出如風，身形矯健。\n",
		"賣藝師傅堆起六塊磚塊，然後用一根手指往磚塊按下，六塊石磚一齊碎裂。\n"
	}) );
#include <replace_mob.h>
}
