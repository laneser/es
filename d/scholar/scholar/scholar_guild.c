//#pragma save_binary

#include <mudlib.h>
#define BOARD "/d/scholar/scholar/scholar_board.c"

inherit GUILD;

void create()
{
    object guild_master;
	::create();
	set_short("舞墨軒");
	set_long( @LONG_DESCRIPTION
你現在來到一間古色古香的書院，一塊紅木匾上寫著幾個龍飛鳳舞的大字，不知
道是什麼人的大作，不過你確定那一定是「舞墨軒」三個字，這裡的主人卞大夫非常
喜歡結交各地的文人墨客，正廳掛著一張工整的小楷(paper)，上面寫著有關入舞墨
軒的規定與注意事項。
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "item_desc", ([ 
		"paper" : @LONG_TEXT
————————————————————————————————
舞墨軒，也就是俗稱的書生公會，是有名的「賽孟嘗」卞大夫和門下食客
談古論今，切磋學藝的地方，如果你想加入舞墨軒成為一名書生，你必須
有至少  5 點的智慧(intelligence)，另外，皇上對舞墨軒的書生常常召
見，為了避免驚動聖駕，來自西方相貌特異的種族如半獸人、蜥蜴人、半
人馬、眼魔與鳥人，我們謝絕加入。
————————————————————————————————
LONG_TEXT
 ]) );
	set( "exits", ([ 
		"east" : "/d/eastland/easta/north_malley",
		"up"   : "/d/scholar/scholar/hall" ]) );
	set( "no_monster", 1 );
	guild_master=new("/d/scholar/scholar/monsters/scholar" );
	guild_master->move(this_object());
	BOARD->frog();
	set_guild( "scholar" );
        set( "pre_exit_func", ([
		"up" : "check_scholar" ]) );
        reset();
}

int check_scholar()
{
	if( wizardp(this_player()) ) return 0;
	if( (string)this_player()->query("class")!="scholar" ) {
                write( "對不起, 只有書生能進去。\n" );
		return 1;
	}
	return 0;
}

int clean_up()
{
		return 0;
}
