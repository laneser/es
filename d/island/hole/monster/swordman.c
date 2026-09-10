#include <../hole.h>

inherit MONSTER;
void create()
{
	::create();
	set_level(19);
	set_name( "Lizardman swordman Abon","亞邦" );
	add( "id",({ "lizardman","swordman","abon" }) );
	set_short( "蜥蜴人劍術師 亞邦" );
	set_long(@LONG
    你看到的是一位氣宇非凡的劍客，他現在主要以訓練年青人為主
。聽說它年青時曾經單身闖入龍穴，與人間兇獸『火麒麟』大戰三天
三夜。由於火麒麟身上的鱗片非常堅硬，加上火麒麟身上奇熱無比，
無法接近，所以始終不分上下。後來它發現火麒麟身上有一個地方的
鱗片脫落，於是朝這缺口奮力一擊，終於將火麒麟殺死。它覺得這麒
麟的鱗片非常怪異，於是順手將火麒麟的皮剝下。後來它將這張獸皮
拿給當時最有名的工匠『愛吉斯』研究，『愛吉斯』就用上面的鱗片
替它打造了『火麟戰甲』、『火麟護臂』、『火麟盾』和『火麟劍』。
LONG
		);
	set( "gender","male" );
	set( "race","lizardman" );
	set( "alignment",-800 );
	set( "time_to_heal",6 );
	set_natural_armor( 55,35 );
	set_natural_weapon( 35,10,15 );
	set( "max_hp",950 );
	set( "hit_points",950 );
	set_perm_stat( "str",30 );
	set_perm_stat( "dex",25 );
	set_perm_stat( "kar",25 );
	set_perm_stat( "int",20 );
	set_skill( "parry",100 );
	set_skill( "block",100 );
	set_skill( "tactic",100 );
	set_skill( "shortblade",100 );
	set_skill( "dodge",80 );
	set( "tactic","assault" );
	set( "wealth/gold",150 );
	set( "special_defense",([ "none":20,"fire":80 ]) );
	set( "aim_difficulty",
	([ "weakest":70,"critical":70,"vascular":45,"ganglion":80 ]) );
	set( "stun_difficulty",80 );
	wield_weapon( HWEAPON"scale_sword" );
	equip_armor( HARMOR"arms5" );
	equip_armor( HARMOR"plate3" );
	equip_armor( HARMOR"shield7" );
}
