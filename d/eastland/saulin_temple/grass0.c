#include "saulin_temple.h"

inherit ROOM;

void create()
{
	::create();
	set_short("林中草地");
	set_long( @C_LONG_DESCRIPTION
你走到了一片草地上，四周都是松林，除了山風吹掠、蟲鳴鳥啼外，沒
有一點塵俗雜音，陰涼幽靜的森林氣息深深的迷醉每一顆來自俗世塵囂的心
，你頓時放下世俗的一切種種牽絆，放開心胸來體會這份難得的自然之美。
當你仔細一看，發現有一塊草皮(grass) 顏色似乎和其他草地不同，呈現一
種淡青色，顯得十分醒目。
C_LONG_DESCRIPTION
	);
    set("item_desc", ([ "grass" : @C_LONG
你走上前去仔細觀察那塊草皮，發現它是由許多十分可愛的青綠色小草綴
成的，咦! 這草一莖七葉、通體細刺，看起來頗像是有用的藥草，或許你
可以挖幾株回去向高人請教請教 !
C_LONG
	]));
    set("objects", ([
        "snakea" : "/d/noden/monster/snake",
        "snakeb" : "/d/noden/monster/snake",
    ]) );
    set("herb_left", 2);
        set_outside("eastland");
	set( "exits", ([
         "east" : SAULIN"entrance",
	]) );
	reset();
}

void init()
{
    add_action( "dig_herb", "dig" );
}

int dig_herb(string arg)
{
    if( !arg || arg !="herb" )
		return notify_fail( can_read_chinese() ?
		  "你東挖西挖的累得滿身大汗才想起來：你不知道要挖什麼？\n" :
		  "Dig what ?\n" );
	else if( query("herb_left") < 1 ) {
		tell_object(this_player(), can_read_chinese() ?
			"不知是那個缺德鬼把這塊草皮上的植物都給挖掉了。\n":
			"There are no herbs here.\n"
		);
		return 1;
	} else {
	if (present("snake",environment(this_player())))
	{
        tell_object(this_player(), 
	"慢著慢著 !! 那些藥草正盤著一條蛇，至少要先把它請走吧 !!\n" 
	);
	return 1;
	}
        tell_object(this_player(), @GOT_HERB
你跪下來細心的連土把藥草挖出來，在你的手心上，藥草更顯得青翠，不過
，如果你不把它包好(pack)再趕快種回土裡並且澆上一大瓢的水，恐怕它的
綠意會消失的很快。
GOT_HERB
		);
		add("herb_left", -1);
		new( SAULIN_OBJ"herb" )->move(this_player());
		return 1;
	}
}

void reset()
{
	set("herb_left", 2);
	::reset();
}
