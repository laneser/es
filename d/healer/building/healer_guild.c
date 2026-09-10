////#pragma save_binary

// translation done 2-24-94. -Elon (having hard time translating)

#include <mudlib.h>
#include <stats.h>
#include <guilds.h>

#define BOARD "/d/healer/building/healer_board"

inherit GUILD;
inherit DOORS;
void create()
{
    object guild_master;
    
	::create();
	
    set_short("行醫者公會");
	set_long( 
		 @C_LONG_DESCRIPTION
你現在來到了一棟美侖美奐的東方式建築，大廳的大梁掛著一塊烏檀木
的匾額，上面寫著「仁心仁術」。這裡是藍沙港的行醫者公會，雖然這裡布
置得相當華麗，但是所有的經費都是由附近受過公會主人刑老爹照顧的居民
捐的，你看到中間一張屏風上掛著一塊牌子(sign)，公會的出口在你的西邊
, 而東邊則是行醫者傳承知識的聖地。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "c_item_desc", ([ 
		"sign" : @LONG_TEXT
———————————————————————————————————
牌子上寫著:
    本公會只收立志行醫救人的年輕人，入會之後切忌作奸犯科、濫殺無辜，若
有違者將逐出門牆,永遠不得踏入此地一步。詳細入會情形請用 help guild 閱
讀說明。
    有關本公會的限制與情形請用 help healers。
———————————————————————————————————
LONG_TEXT
 ]) );
    set( "exits", ([ 
                "north": "/d/healer/building/healer_shop",
		        "east" : "/d/healer/building/healer_inner",
		        "west" : "/d/noden/bluesand/alley2",
		        "south": "/d/healer/building/healer_operate",
	]) );

	set( "pre_exit_func", ([
		"east" : "check_healer" ]) );
    guild_master=new("/d/healer/building/monsters/healer");
    guild_master->move(this_object());
	create_door( "west", "east", ([
		"keyword" : ({ "arch door", "door" }),
		"name" : "arch door",
		"c_name" : "拱門",
		"desc" : "A red arch door which decorated with bronze rings",
		"c_desc" : "一扇紅色的拱門，上面裝飾著許多銅環。\n",
		"status" : "closed"
	]) );
	set_guild( "healer" );
	BOARD->frog();
	reset();
}

int clean_up() {  return 0; }

int check_healer()
{
	if( wizardp(this_player()) ) return 0;
	if( !call_other(GUILD_MASTER("healer"), "is_guild_member", this_player() ) ) {
		write( "你不是行醫者，不能進入東邊的書房！\n" );
		return 1;
	}
	if( (int)this_player()->query("alignment") < -200 ) {
		write( "你做了太多壞事，在你改過向善之前不能進入東邊的書房！\n"
 );
		return 1;
	}
	return 0;
}
