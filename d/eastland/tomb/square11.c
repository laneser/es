#include "almuhara.h"

inherit ROOM;
int gua;
void create()
{
	::create();
	set_short("地下廣場");
	set_long( 
@C_LONG_DESCRIPTION
這裡是一個巨大的廣場，令你有豁然開朗的感覺。實在無法想像當年的工匠們是如何在
地底下建立如此大的廣場，你不禁對那些工匠起了分敬意。廣場邊有一根渾圓發亮的大石柱
，上面貼了一張咒符(charm)。從符咒上發出了淡藍色的光芒，映的四周一片藍色。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"south" : TOMB"/square12", 
		"east" : TOMB"/square10",  ]) );
	add( "c_item_desc", ([
		"charm" :@AMULET_DESC
這是一張奇異的咒符，閃耀著淡藍色的光芒，你可以感受到它充滿了能量。也許你可
\以把它拿(get)下來。
AMULET_DESC
	]) );
	reset();	
}

void init()
{
	add_action( "get_amulet", "get" );
	add_action( "look_amulet","look" );
}	

int get_amulet(string str)
{
	object player;
	
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
		new(MOB"/water_guard")->move(environment(player));
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