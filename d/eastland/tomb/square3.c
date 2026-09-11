#include "almuhara.h"

inherit ROOM;
int gua;

void create()
{
	::create();
	set_short("地下廣場");
	set_long( 
@C_LONG_DESCRIPTION
這□是一個巨大的廣場，令你有豁然開朗的感覺。實在無法想像當年的工匠們是如何在
地底下建立如此大的廣場，你不禁對那些工匠起了分敬意。廣場邊有一根渾圓發亮的大石柱
，上面貼了一張咒符(charm)。從咒符上發出了亮紅色的光芒，映的滿室紅通通的。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"north" : TOMB"/square4", 
		"west" : TOMB"/square2",  ]) );
	add( "c_item_desc", ([
		"charm" :@AMULET_DESC
這是一張奇異的咒符，閃耀著亮紅色的光芒，你可以感受到它充滿了能量。也許你可
\以把它拿(get)下來。
AMULET_DESC
	]) );
	reset();	
}

void init()
{
	add_action( "get_amulet", "get" );
	add_action( "look_amulet", "look" );
}	

int get_amulet(string str)
{
	object player,ob;
	
	player = this_player();
	
	if ( !str || str != "charm" )
		return 0;
	if ( gua ) 
		return 0;
	else 
		tell_object( player, 
			"當你試著拿下咒符時，突然起了一陣旋風....咒符竟化成了人形 !!\n");
		tell_room( environment(player), 
			"當" + player->query("c_cap_name") + "試著拿下咒符時，突然起了一陣旋風....咒符竟化成了人形 !!\n",
			player );
		ob = new(MOB"/fire_guard");
		ob->move(environment(player));
		gua = 1;
		return 1;
}	

int look_amulet(string str)
{
	object player;
	
	if ( present("guard", this_object()) && str == "charm" )
		return 1;
	return 0;
}	