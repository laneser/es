#include <almuhara.h>

inherit ROOM;

void create()
{
	::create();
	set_short("陵墓");
	set_long( 
@C_LONG_DESCRIPTION
這兒就是傳說中的陵墓了，在你頭頂上竟是一片璀璨的星空，眾星們是用金鋼鑽做的，
而一輪明月則是一塊皎潔無瑕的碧玉，冷冷的銀光自星空灑下。在你南邊躺著的是縮小版的
東方大陸 !! 地形山川、樹木建築無不維妙維肖，河流中甚至還有水在緩緩流動著，真是太
驚人了，不知道前人是如何創造出這般景象，委實令人敬佩。北邊是一片巨大、鮮綠色的翡
翠(jade)，隱約透出陣陣的紅光，大概是有什麼寶物吧。
C_LONG_DESCRIPTION
	);

	set( "light",1);
	set( "exits", ([ 
		"east"  : TOMB"/inner4",
		"west"  : TOMB"/inner6"  ]) );
	set( "item_desc", ([
		"jade" : "這是一片巨大的翡翠，從它那完美無瑕的鮮綠色可以知道它的\n"
			 "品質有多好。你注意到旁邊有滑動過的痕跡，也許你可以試著\n"
			 "推推(push)看。\n" ]) );
	reset();	
}

void init()
{
	add_action( "do_push" , "push" );
}

int do_push(string str)
{
	object who;
	who = this_player();
	
	if ( !str || str == "" ) return notify_fail("推啥？\n");
	if ( str == "jade" || str == "door" ) {
		if ( (int)who->query_stat("str") < 15 ) 
			return notify_fail("你使盡吃奶的力氣，還是推不動它。\n");
		if ( (int)who->query_stat("pie") < 15 )
			return notify_fail("你聽到一股聲音說道：不夠誠心正意的人是無法進入的 !!\n");
		tell_object(who,
			"你輕輕地一推，翡翠便向外滑開。你進入了一個新的石室中。\n" );
		tell_room(this_object(),
			sprintf("%s將翡翠推開，走了進去。那翡翠隨即恢復原狀。\n",
				who->query("c_cap_name")) , who );
		tell_room(TOMB"/inner9",
			sprintf("%s將翡翠推開，走了過來。那翡翠隨即恢復原狀。\n",
				who->query("c_cap_name")) , who );
		who->move_player(TOMB"/inner9","SNEAK");
		return 1;
		}
	return notify_fail("推啥？\n");
}