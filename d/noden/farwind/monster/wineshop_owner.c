#include <mudlib.h>

inherit MONSTER;

void init()
{
	::init();
	add_action( "have_menu", "menu");
	add_action( "have_menu", "list");
}

void create()
{
        ::create();
        set_level( 10 );
        set_name( "wine shop owner", "酒店老闆娘" );
        add( "id", ({ "owner" }) );
        set_short( "酒店老闆娘" );
        set_long(
            "遠風鎮的酒店老闆娘。"
        );
        set( "no_attack", 1 );
        set( "gender", "female" );
		set( "inquiry", ([
			"menu" :@ALONG


		這是遠風酒店的價目表，您參考看看...
		**********************************************
		*                 遠風酒店                   *
		**********************************************
		         竹葉青(Ching)           20 silvers
		         ＸＯ(XO)                30 silvers
		         玫瑰紅酒(Rose wine)     20 silvers
		         伏特加(Vodka)           30 silvers
		       * 烤雞(Chicken) *        200 silvers
		       * 特調大補酒(Special) *  100 silvers
		**********************************************
ALONG
		]) );
}

int have_menu()
{
   write(@BLONG
   		老闆娘遞了一張手工制的菜單給你，你看了看...
		**********************************************
		*                 遠風酒店                   *
		**********************************************
		*         竹葉青(Ching)           20 silvers *
		*         ＸＯ(XO)                30 silvers *
		*         玫瑰紅酒(Rose wine)     20 silvers *
		*         伏特加(Vodka)           30 silvers *
		*         烤雞(Chicken)          200 silvers * 
		*       * 特調大補酒(Special) *  100 silvers *
		**********************************************
BLONG
        );	
	return 1;
}
