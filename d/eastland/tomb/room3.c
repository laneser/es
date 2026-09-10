#include "almuhara.h"

inherit ROOM;
int bury,paper,pick;
void create()
{
	::create();
	set_short( "地下石室" );
	set_long( 
@C_LONG_DESCRIPTION
你進入了一個小小的石室，與前面的石室比起來，這兒真是小的微不足道。環顧四周空
無一物。喀.....你似乎踩到什麼東西，定睛一看，嚇.....是具骷髏。它身上的服飾樣式古
樸，身旁還散落了一些工具，不知道為什麼死在這兒。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"east" : TOMB"/room1",  ]) );
	set( "item_desc" , ([
		"skeleton" : "一具駭人的骷髏\，也許你可以搜索一下。\n" ]) );
	reset();	
}

void reset()
{
	bury = bury;
	::reset();
}

void init()
{
	add_action("search_skeleton", "search");
	add_action("bury_skeleton", "bury");
}

int search_skeleton(string str)
{
	object player;
	
	player = this_player();
	
	if ( !str || str == "")
		return 0;
	if ( bury ) return 0;
	if ( str == "skeleton" ) {
		if ( paper ) return 0;
		tell_object( player, 
			"在你仔細搜尋後，發現了一張羊皮紙。\n");
		new(ITEM"/paper1")->move(player);
		paper = 1;
		return 1;
		}
	else if ( str == "tools" || str == "tool" ) {
		if ( pick ) return 0;	
		tell_object( player,
			"你翻了翻那些工具，只剩下一把十字鎬是堪用的。\n");
		new("/d/noden/moyada/obj/pick")->move( environment(player) );
		pick = 1;
		return 1;
		}
	else return 0;
}

int bury_skeleton(string str)
{
	object player,ob;
	
	player = this_player();
	
	if ( !str || str == "")
		return notify_fail("埋啥??\n");
	if ( bury ) return 1;
	if ( str == "skeleton" ) {
		if ( !present( "pick" , player ) ) {
			tell_object( player, 
				"你沒有適當的工具，想空手入硬石嗎？？\n"
				);
			return 1;
			}	
		else tell_object( player, 
			"在你好好地安葬了骸骨後，竟然發現骸骨下藏了封短函及一顆奇異的珠子。\n"
			);
			new(ITEM"/orbkey")->move( player );
			new(ITEM"/paper2")->move( player );
			bury = 1;
                        this_player()->set_explore("eastland#34");
			return 1;
		}
	else return notify_fail("埋啥??\n");
}
