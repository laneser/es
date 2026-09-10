//#pragma save_binary

#include <mudlib.h>
inherit GUILD;

void create()
{
	object guild_master;

	::create();
	set_short( "The Knight Guild", "騎士公會");
	set_long(
		"You have come around the Knight's Guild in Nodania. The Royal\n"
	"Knights are planning to recurit more young fighters to help fight\n"
	"against the invaders from Moorth. You can see a plaque on the wall\n"
	"and a large book on a oak table in the middle of the room. West of\n"
	"here is the pathway leading back to the palace.\n",
		"你現在來到了諾達尼亞的騎士公會。皇家騎士團正在招募強壯的年輕人\n"
	"加入騎士團，以對抗來自默爾思的入侵者。你注意到牆上掛著一張告示牌(\n"
	"plaque )和房間中央一個橡木桌上擺著一本書(book)。往西走可以回到通往\n"
	"王宮的小徑。\n"
	);

	set("item_desc", ([
		"plaque"	:
			"The plaque reads:\n"
			"    Welcome to the Knight Guild, Young men! For your loyalty to\n"
			"the Noden Kingdom and King Yaramon XI, join the Knight guild and\n"
			"learn the fighting skills. Type \"help guild\" for more about\n"
			"the Royal Knights.\n",
		"book"	:
			"The book is labeled \"Quests\". Maybe you should \"read\" it.\n"
	]) );
	set("c_item_desc", ([
		"plaque"	: @LONG
——————————————————————————————
告示牌上寫著:
    歡迎加入皇家騎士團，勇敢的年輕人們！為了表示你對諾頓王國
與國王耶拉曼十一世的忠誠，加入皇家騎士團將是你學得高超戰技，
展現抱負的最佳選擇！用 help guild 可以得到進一步有關皇家騎士
團的訊息。
    加入騎士公會之前，請先 help knights 以瞭解本公會的特色。
——————————————————————————————
LONG
,
		"book"	:
			"這本書的書名是「任務之書」，也許你可以 read 它。\n"
	]) );

	set("exits", ([
		"west" : "/d/noden/nodania/e_path2",
		"east" : "/d/knight/fortress/knight_inner"
	]) );

	set ("light", 1);
	guild_master = new("/d/knight/fortress/monsters/laice");
	guild_master->move( this_object() );

	set( "pre_exit_func", ([
		"east" : "check_knight" ]) );
	set( "no_monster", 1 );

	call_other("/d/knight/fortress/knight_board", "???");

	set_guild( "knight" );
	reset();
}

int clean_up() { return 0; }

void init()
{
	::init();
	add_action( "do_read", "read" );
}

int check_knight()
{
	if( wizardp(this_player()) ) return 0;
	if( (string)this_player()->query("class")!="knight" ) {
		write( "對不起，只有騎士才能進去。\n");
		return 1;
	}
	return 0;
}

int do_read(string arg)
{
	if( !arg || arg!="book" ) return 0;
	write("上面一片空白....。\n");
	return 1;
}
void reset()
{
        int i,j;
        object *player;

        ::reset();
        player = users();
        j=sizeof(player);
        for( i=0; i<j; i++ )
                "/d/knight/data/topknights"->log_player(player[i]);
}
