#include "../takeda.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "Zhuan Shiao Chi", "阮小七" );
	add("id",({"zhuan","shiao","chi"}));
	set_short( "阮小七" );
	set_long(
		"阮小七外號活閻羅，小二，小五是他哥哥，本以打魚維生，兄\n"
		"弟三人隨吳用落草，現俱為水軍頭領．他現在正在找他哥哥小二，似\n"
		"乎有什麼事情。\n"
	);
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", -80 );
	set_perm_stat( "str", 18 );
	set_perm_stat( "dex", 18 );
	set_perm_stat( "kar", 11 );
	set_skill( "shortblade", 50 );
	set_skill( "parry", 25 );
	set_skill( "dodge", 40 );

	set( "wealth/gold", 30 );
	set( "special_defense", (["all": 16 ]) );
	set_natural_weapon( 8, 8, 8 );
	set_natural_armor( 25, 8 );
        set( "inquiry",([
        "whirl" : "@@ask_whirl",
        "brother" : "@@ask_brother"
        ]));
	wield_weapon( TWEAPON"fishman_dagger" );
        equip_armor( TARMOR"hat");
        equip_armor( TARMOR"fish_skin");
}
void ask_whirl()
{
write(
"阮小七說道: 湖邊的漁民們有一個傳說，在湖的最深處住著一隻千年的大河蚌\n"
"當它在用水管吸水時，就產生了湖中的漩渦，詳情是如何我也不清楚....\n");
return 0;
}
void ask_brother()
{
write(
"我哥哥阮小二前天說他在湖中發現了一個大秘密，昨天他一個人到湖裡\n"
"結果到現在都不見人影，真是令人擔心....\n");
return 0;
}
