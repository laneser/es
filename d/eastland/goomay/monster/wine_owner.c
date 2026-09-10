#include <mudlib.h>

inherit MONSTER;

void init()
{
	add_action( "have_menu", "menu");
	add_action( "have_menu", "list");
}
void create()
{
        ::create();
        set_level( 7 );
        set_name( "the wine shop owner", "趙燕居掌櫃" );
        add( "id", ({ "owner" }) );
        set_short("趙燕居掌櫃" );
        set_long(
@LONG
他是一個三十來歲的中年男人，留了兩撇稀稀疏疏的小鬍子，穿著一身嶄新
熟羅長袍的他笑咪咪的和進進出的客人聊天打招呼，店裡的生意越好他就越
忙。  
LONG
        );
        set( "gender", "male" );
	set("race","human");
	set( "alignment",200);
        set_natural_armor( 34, 14 );
        set_natural_weapon( 8, 8, 16 );
	set( "wealth/gold",10);
        set_perm_stat( "str", 12 );
        set_perm_stat( "int", 10 );
        set_perm_stat( "dex", 10 );
        set_skill( "unarmed", 50 );
        set_skill( "parry", 50 );
        set( "hit_points", 200 );
        set( "max_hp", 200 );
        set( "special_defense", ([ "all": 20 ]) );
	set( "defense_type","parry");
}

int have_menu()
{
		write(@MENU
掌櫃的笑咪咪的遞了一張手工制的菜單給你，你看了看...
**********************************************
*               趙燕居酒店                   *
**********************************************
         竹葉青(Ching)           20 silvers
         ＸＯ(XO)                30 silvers
         玫瑰紅酒(Rose wine)     20 silvers
**********************************************
MENU
	);
	return 1;
}
