#include <almuhara.h>

inherit ROOM;
inherit DOORS;

void create()
{
	::create();
	set_short("屋內");
	set_long( 
@C_LONG_DESCRIPTION
這是一個整理得相當乾淨的大廳，四周有些用竹子作成的傢俱，整個屋子令人覺得相當
樸實典雅。室內有一股淡淡的清香，令你精神為之一振。正中央有一個小小的供桌，桌上祭
拜著一個道士，不知道是何方神聖。左邊牆上掛了一把劍，右邊則是一幅很大的壁畫，上面
畫著一些奇怪的文字及符號，還有一條條彎彎曲曲的線條。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/house4",
		"south" : TOMB"/house3", 
		"out"   : TOMB"/house1" ]) );
	create_door( "out","enter",
		(["keyword" : ({"door"}),
		  "name"    : "red door",
		  "c_name"  : "紅門",
		  "c_desc"  : "一扇紅色的門。",
		  "status"  : "closed",
		  ]) );
	set( "objects", ([
		"boy#1" : MOB"/good_boy",
		"boy#2" : MOB"/evil_boy" ]) );
	set( "pre_exit_func", ([
		"south" : "check_boy" ]) );
	reset();	
}

int check_boy()
{
	object player;
	
	player = this_player();
	if( present("broken jade",player) ) {
		write( "小童看了看你身上的碎玉佩，說道 : 「 你是來找我家女主人的喔，請進。」\n" );
		return 0; }
	if( present("old scroll",player) ) {
		write( "小童看了看你身上的畫軸，說道 : 「 你是來找我家女主人的喔，請進。」\n" );
		return 0; }
	if ( !wizardp(player) && present( "boy", this_object() ) ) {
		write( "小童說道 : 「 喂 !! 你這人懂不懂禮貌啊 ?? 隨隨便便就往人家的內室闖 !! 」\n" );
	return 1; 
	} else return 0;	
}
