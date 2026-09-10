//#pragma save_binary
#include <mudlib.h>
#define BOARD "/d/thief/hall/thief_board"
#include <stats.h>

inherit GUILD;
 
void create()
{
	object guild_master;
	::create();
	
	set("light", 1);
	set_short( "小偷公會" );
	set_long( @LONG
你現在位於諾頓大陸所有的犯罪者的溫暖的家 -- 小偷公會，寬闊的大廳
只點著一盆忽明忽暗的火，整個大廳因此顯得有些灰暗，在大廳的每個牆角邊，
或臥或坐的不知道聚集的多少人，細細的談話聲時時可聞，但是卻沒有人敢大
聲說話。在東邊的牆上掛了一塊告示牌(plaque)，在暗淡的火光下，看不出寫
些什麼？告示牌旁邊有一根繩子(rope)。
LONG
	);

	set("exits", ([
		"north" : "/d/thief/hall/thief_shop",
		"east"  : "/d/noden/bluesand/temple",
		"south" : "/d/thief/hall/plan_room1",
		"west" : "/d/thief/hall/thief_trainroom",
	]) );
	
	set("pre_exit_func",([
		"north" : "check_thief" ,
		"west" : "check_thief" ,
	]));
	BOARD->frog();

        set("c_item_desc", ([
                "plaque"        : @LONG
你走過去仔細的看，告示牌上寫著:
——————————————————————————————
    歡迎加入小偷公會，勇敢的年輕人們 !! 本公會是諾頓大陸一切
罪惡的指導者，我們希望發揚搶劫、竊盜、暴力、詐欺等等生命本性
的優美藝術，加入我們你將學到一切罪惡的技術和美感，這是你追求
財富與快樂最快速的道路。你可以用 help guild 來獲得本公會更進
一步的資訊。
    加入本公會前，你可以用 help thieves 來了解本公會的特色。
——————————————————————————————
LONG
	,
	"rope" : "繩子上綁著一張紙條，上面寫著「拉(pull)我 !!」\n"]));
	guild_master=new("/d/thief/hall/monsters/pickering");
	guild_master->move(this_object());
	set( "no_monster", 1 );
	set_guild( "thief" ); 
	reset();
}
 
int clean_up()
{
		return 0;
}
void init()
{
	::init();
	add_action("do_pull","pull");
}
int do_pull(string arg)
{
	if ( arg != "rope")
		return notify_fail("你要拉什麼？\n");
	if ( !"/d/noden/bluesand/temple"->query("exits/west") )
		return notify_fail("出口的暗門早就關上了，不過小心一點是好的 !!\n");
	write("你拉拉繩子，把出口的暗門關起來。\n");
	"/d/noden/bluesand/temple"->delete("exits/west");
	return 1;
}
int check_thief()
{
	if ( wizardp(this_player()) ) return 0;
	if ( (string) this_player()->query("class") != "thief" ) {
		write("你不是小偷, 不能進去。\n");
		return 1;
	}
	return 0;
}	

void reset()
{
        int i,j;
        object *player;

        ::reset();
        player = users();
        j=sizeof(player);
        for( i=0; i<j; i++ )
                "/d/thief/data/topthieves"->log_player(player[i]);
}

