#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 1) ;
        set_short("綠珠樓" );
        set_long(
@LONG
這裡是大財主錢不多特地為他的寵妾－綠珠所建造的一座小樓，
裝飾卻一點都不豪華，淨素的牆面上掛著幾幅水墨山水，兩扇琉璃
窗使得整個前廳顯得十分潔淨優雅。你可以想見這裡的主人一定是
個很懂得生活的人。
LONG
        );
        
        set( "exits", ([ 
		"east" : Goomay"rich_house",
		"up"   : Goomay"green_pearl2",
        ]) );
        set( "objects", ([
                "maid1" : Mob"maid",
		]));
        set( "pre_exit_func", ([
                "up" : "can_pass" ]) );
        reset();
}

int can_pass()
{
	if(!this_player()->query_temp("give_pearl") && !wizardp(this_player()))
        {
                tell_object(this_player(),
                "婢女叉著腰擋在你面前說道：「你這個人怎麼一點禮貌都不懂嗎？亂闖人家家裡 !!」\n");
		return 1;
	}
	else
	return 0;
}
