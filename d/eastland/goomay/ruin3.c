#include "goomay.h"

inherit ROOM;

void create()
{
        ::create() ;
        set("light", 0) ;
        set_short( "井邊" );
        set_long(
@LONG
這裡有一口井，清澈的井水在井中盪漾著，有許的貧民區的女人在井邊
洗衣服聊天，所以這裡一片吵雜聲。
LONG
        );
        
        set( "exits", ([
		"west"  : Goomay"ruin2",
        ]) );
        set( "objects", ([
                "woman" : Mob"poor_woman",
                "woman2" : Mob"poor_woman",
                "woman3" : Mob"poor_woman",
                "cat"   : "/d/noden/nodania/monster/cat",
		]));
        set("c_item_desc",(["well":@C_LONG
    你探頭望井裡一瞧，只見粼粼的微光隨著水面的波動搖曳著，
等你仔細一看，突然發覺左邊的井圈好像有些磨損，就好像有人常常
出入一般，或許你也可以爬進去。
C_LONG
        ]));

        reset();
}
void init()
{
        add_action( "climb_well", "climb" );
}

int climb_well(string arg)
{

        if( !arg || arg!="well" )
        return notify_fail("你在地上到處亂爬。\n");

	if ((int)this_player()->query_skill("climbing")<20)
	{
        tell_object(this_player(),
        "你小心的想要沿著井緣爬下井底，突然，腳下一個踩空，摔了個四腳朝天 !!\n");

        tell_room( this_object(), 
        this_player()->query("c_name") + "試著爬入井底...哎呀 ! 他摔了個四腳朝天，技術實在是 ...\n",
                this_player() );
	return 1;
	}

        tell_object(this_player(),
	"你小心的沿著井緣爬下井底，突然，腳下一個踩空....\n");

        tell_room( this_object(), 
	this_player()->query("c_name") + "試著爬入井底...哎呀 ! 他頭下腳上的栽進去了，技術實在是 ...\n",
                this_player() );
        this_player()->move_player( Goomay"under_well", "SNEAK" );
        tell_room( Goomay"under_well", 
		this_player()->query("c_name") + "從井口直直的栽了下來。\n"
		,this_player() );
        return 1;
}
