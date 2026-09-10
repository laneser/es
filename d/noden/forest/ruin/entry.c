#include "ruin.h"
inherit ROOM;

#define GARGOYLE_NUM_ONCE 4
#define GARGOYLE_NUM 2
#define MAX_GARGOYLES 16

void create()
{
	::create();
	set_outside("noden");
	set_short("遺蹟");
	set_long(@CLong
兩排古老的石雕像 (statues)、 散亂倒在地上的石塊 (stones)、僅
餘半截立在地上的石柱群, 從前這裡大概是某個充滿著光輝、榮耀的神殿
吧! 但是時光逝去, 光華不再, 連在此被奉祀的神祈之名, 也因年代久遠
漸漸地被人遺忘, 不得而知了。在雜亂的石柱群中, 一個人工開鑿的洞穴
被半遮半掩地隱藏在北方的山壁上。南邊則是通往南方山丘地帶的小徑。
CLong
);
	set("exits",([
              "south"	: RUIN"hidden_path4",
              "north"	: RUIN"s_hall",
             ]));
    set("exit_suppress", ({ "north", }) );

	add("item_desc", ([
		"statues": @C_ITEM_DESC_1
    這些石像都是以石像鬼 (gargoyle) 的造型來塑造的, 但是各有各的
姿態, 栩栩如生。或許他們曾經真的「活過」, 不過經過了那麼久的時間
, 魔力大概早已消失無蹤了。
C_ITEM_DESC_1
,		"stones"	: @C_ITEM_DESC_2
    一堆散亂的石頭, 這些都是原來那個不知名的偉大建築中的一部份。
有些石頭上還可以隱約地看到優美的雕刻圖案。
C_ITEM_DESC_2
,		"tunnel": @C_ITEM_DESC_3
    與其稱它為一個洞穴, 還不如稱它為通道比較恰當, 洞穴的牆壁都是
石砌的, 四面相當的寬廣, 似乎通往相當深的地方。不過你隱隱約約感受
到洞口傳來一股斥力。
C_ITEM_DESC_3
		]));
		
	set( "pre_exit_func", ([
		"north" : "loop_exit" ]) );
//	set( "search_desc", ([
//    	"here" : "@@search_here" ]) );
	set("seal", GARGOYLE_NUM);
	reset();
}

int loop_exit()
{
	int i;
	object me, storage;
	
	me = this_player();
	if( !me->query("invisible") && present( "gargoyle", this_object() ) ) {
		write( 
		"石像鬼擋住了你的去路, 使你無法進入洞穴。\n");
		tell_room( environment(me), 
	sprintf("%s想進入洞穴, 但是被石像鬼擋住了。\n", me->query("c_name"))
		, me);
		return 1;
    } 
	if( me->query("invisible") || query("seal") < 1 ) return 0;
	write( 
	"你正想向洞穴走去, 突然間一陣奇異的光由石塊中發出, 擋住了你的去路。\n"
 	"緊接著四隻石像鬼眼睛一亮, 活了起來。\n" 
	);
	tell_room(this_object(),
		sprintf("%s正想往洞中走去, 突然間一陣奇異的光芒由石塊中發出。緊接著四\n"
			"只石像鬼眼睛一亮, 活了過來\n", me->query("c_name"))
		, me
	);
	tell_room(find_object(RUIN"mob_storage"),
		"突然間一陣奇異的光芒由石雕像的眼中發出。又有四隻石像鬼活了過來。\n"
	);
	storage = find_object_or_load(RUIN"mob_storage");
	for( i=0; i<GARGOYLE_NUM_ONCE; i++ ) {
		if( (int)storage->query("mob_storage") < MAX_GARGOYLES )
			storage->add("mob_storage", 1);
		new(MOB"gargoyle")->move(storage);
		new(MOB"gargoyle")->move(this_object());
	}
	add("seal", -1);
	return 1;
}

void reset()
{
	::reset();
	set("seal", GARGOYLE_NUM);
}
