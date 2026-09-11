#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地下廣場");
	set_long( 
@C_LONG_DESCRIPTION
這兒是一個非常大的廣場，想到在地底下竟有如此大的廣場，你不禁佩服起當年那些建
築此處的工匠。當你的目光移到廣場中央時，簡直無法相信眼睛所看到的景象----這真是絕
世奇景!!你看到一個自然形成的池子，水在裡面緩緩地旋轉流動，而池子中央竟是一團熊熊
的火焰!!如此兩種性質截然不同的東西，竟能在此共存地如此融洽，無怪乎大國師會稟告皇
上，設陵墓於此，這兒真是一個鐘天地之靈氣的寶穴。
C_LONG_DESCRIPTION
	);
	set( "light", 1);
	set( "exits", ([ 
		"north" : TOMB"/square19",
		"south" : TOMB"/square17", 
		"east" : TOMB"/square18",
		"west" : TOMB"/square20" ]) );
	reset();	
}

void init()
{
	add_action("search_pool","search");
}

int search_pool(string str)
{
	object ob,player;
	
	player = this_player();
	
	if ( !str || str == "" ) 
		return 0;
	if ( str == "pool" ) {
		if ( present("golden dragon orb", player) && !player->query_temp("ORB_POOL") ) {
			tell_object( player,
				"你靠近著池子準備搜索，忽然你身上的金龍珠及池中火焰皆光芒大盛 !! \n"
				"\n"
				"你聽到遠處傳來隆隆的聲音。\n"
				);
			player->set_temp("ORB_POOL",1);	
			return 1; }
		else tell_object( player,
			"你環繞著池子搜索著，卻沒有什麼特別的地方。\n" );
			return 1; }
	else return 0;
}						