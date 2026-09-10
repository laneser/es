#include <takeda.h>
#include <move.h>
#include <stats.h>
#include <conditions.h>

inherit ROOM;

int crumb_present = 1;

void create()
{
	::create();
	set_short( "民居" );
	set_long(
	"你進入了一間陰暗的房子，從這間屋子的雜亂陳設看來，屋主大概是個\n"
	"不修邊幅的人，房子的中央放了一張大桌子(table)，上面放著一些鍋子和碗\n"
	  );
        set("c_item_desc",(["table":
"這是一張普通的桌子，實用價值遠遠大於裝飾價值，從放在桌子上的鍋子\n"
"和碗筷看來，這張桌子應該是張餐桌\，或許你可以在這找到些吃的東西。\n"
            ]));        
        set( "exits", ([
                "east" : TROOM"village2"
        ]) );
        reset();
}
void init()
{
     add_action("do_search","search");
}
int do_search(string arg)
{
 object crumb;
 if ( !arg || arg != "table")
    return notify_fail(
    "要找什麼?\n");
	if( !crumb_present )
		write(
		    "你翻爛了整張桌子，也沒找到什麼好吃的....\n"
		);
	else {
		write(@ALONG
你在桌子上找來找去，什麼吃的都沒找到，正當你想放棄時，你看到桌子的
縫隙中，有一些麵包屑(crumb)，於是你順手把麵包屑挖出來。
ALONG
		);
		crumb_present = 0;
		crumb = new( "/d/eastland/liang_shan/obj/crumb" );
		if( (int)crumb->move(this_player()) != MOVE_OK )
			crumb->move( this_object() );
	        return 1;
	}
}
