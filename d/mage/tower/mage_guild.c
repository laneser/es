//#pragma save_binary

#include "../mage.h"
#define BOARD MAGE"mage_board"

inherit GUILD;
inherit DOORS;
void create()
{
    object master;
	::create();
	set_short( "The Mage Guild", "魔法師公會");
	set_long(
		"You enter the oldest mage guild in Moyada. The magical books,\n"
	"scrolls and magic items are messy put here. You notice a flying\n"
	"stele and some runes on it.\n",
@DESC
你現在來到摩亞達城最古老的魔法師公會。牆上畫滿了奇怪的符號和圖
案，似乎在訴說著銀色之塔輝煌的歷史。四周堆置著很多魔法書籍, 卷軸和
魔法道具，顯示出聚集在這裡的全是對於魔法有高深造詣的人。在微暗的燈
光下，你發現一塊飄浮在空中的石碑(stele) , 隱約的你可以看見上面的碑
文(runes)。
DESC
	);

	set("item_desc", ([
		"runes"	:
			"The runes reads:\n"
			"    Welcome to the Mage Guild, Young men! Who is interesting\n"
			"of the power of magic is welcome to join us. But only passing\n"
			"the ordeal of old archmage Rashudi can become a great mage.\n"
			"You can type 'help guild' to get more informations.\n",
		"stele"	:
			"The stele is flying.\n"
	]) );
	set("c_item_desc", ([
		"runes"	: @LONG
———————————————————————————————————
碑文寫著:
    歡迎來到魔法師公會，年輕人們！除了一些種族之外，任何對魔法有興趣的
人都歡迎加入我們。不過只有通過老魔導士拉修帝考驗的人才能成為偉大的魔法
師！用 help guild 可以得到進一步有關魔法師公會的訊息。
    有關本公會的限制與屬性上限，請用 help mages。
———————————————————————————————————
LONG
,
		"stele"	:
			"這石碑似乎具有某種不可思議的魔力而飄浮在空中。\n"
	]) );

    set("no_monster", 1);
	set("exits", ([
		"out" : MOYADA"rndplza",
                "east" : MAGE"time1",
		"up"  : MAGE"library",
	"down" : MAGE"hall_of_fame",
	]) );
	set("pre_exit_func", ([
	    "up" : "to_go_up",
	"down" : "to_go_down",
	]) );
// add a magic level list,
	set("objects", ([
		"list" : "/d/mage/tower/obj/list1",
	]) );
	set ("light", 1);
    BOARD->frog();
	set_guild( "mage" );
	master = new( MAGE"monsters/rashudi");
	master->move( this_object() );
}
int to_go_down()
{
	string class1;
	class1 = (string)this_player()->query("class");
	if(wizardp(this_player()) || class1=="mage" || class1=="necromancer" ||
	class1=="sage" || !present("rashudi") )
	return 0;
	tell_object(this_player(), 
	"拉修帝說: 你想學魔法啊? 先加入我們公會吧!\n");
	return 1;
}

int to_go_up()
{
    string class1;
    class1 = (string)this_player()->query("class");
    if( wizardp(this_player()) || class1=="mage" || class1=="necromancer" || 
        class1=="sage" || !present("rashudi") )
    return 0;
    tell_object( this_player(), 
      "拉修帝說: 慢著！你以為這裡是什麼地方？只有本公會的人才能進去！\n");
    return 1;
}

void init()
{
	guild::init();
}

void reset()
{
        int i;
        object *player;

        ::reset();
        player = users();
        for( i=0; i<sizeof(player); i++ )
                "/d/mage/tower/obj/topmages"->log_player(player[i]);
}

int clean_up() { return 0; }
