#include "saulin_temple.h" 

inherit "/d/monk/guild/train_gonfu.c";
inherit ROOM;

void create()
{
	room::create();
	set_short("A room", "基礎拳法練武房");
	set_long( @LONG_DESCRIPTION
NEED TRANSLATE HERE.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
你一進門便看到一些年輕的武僧正全心全意的在練拳，整間房子裡充滿了汗水的
味道，原來此地便是少林武僧學習基本拳法的練武房。少林拳法是最基本的少林武學  
，空手時便能使用。詳細的說明請看佈告(board)。
在你面前有幾面灰牆上(wall)畫滿了人形，你不妨根據你目前的拳法能力選擇適當的
拳法去練習(train)。 往北走是少林的羅漢堂。 
C_LONG_DESCRIPTION
	);

set("c_item_desc",([
            "board" : 
"少林基礎拳法\n"
"少林拳法是少林武僧慣用的武功，如果你的拳術技巧足夠，你可以在本房習得防身\n" 
"的少林拳法。這些拳法是不需運功便能使用的，一旦你學會了，在戰鬥中你本身自\n"
"動便能使出這些拳法，使得你在赤手空拳時也能有一定的戰鬥能力。\n"
"少林基礎拳法不需要太多的練習，其熟練度不變，是少林僧人常用的空手防身武藝\n"
"當學到一項拳法後，可用 \" fist [拳法名稱]\" 來使用它，你便可自動在和敵人對\n"
"戰時使出它來，並可見到其招式之戰鬥訊息，但如果配備武器，拳法便毫無作用。\n"
"一般而言，使用拳法作戰會在每一次出拳時耗用內力，如果內力不濟，拳法自然就\n"
"沒有效力，切記切記。有些低等級拳法無需內力，不妨多多使用。\n"
"使用指令 \" fist now \" 則可顯示出你目前正使用的拳法。\n"
]));
        set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
//		"north" : SAULIN"gonfu_room3",
		"north" : SAULIN"monk_guild" ]) );
                 
	set( "item_func", ([
		"wall": "view_catalog" ]) );

	set_gonfu_type("fist");
	set_gonfus( ([
		"sh_fist"    : ({ "fist-technic",  1,     0 }),
		"long_fist"  : ({ "fist-technic",  7,   100 }),
		"tb_fist"    : ({ "fist-technic", 17,   200 }),
		"ro_han"     : ({ "fist-technic", 30,   700 }),
		"ho_fist"    : ({ "fist-technic", 42,  1500 }),
		"fu_hu"      : ({ "fist-technic", 53,  4000 }),
        "wei_to"     : ({ "fist-technic", 65,  8000 }),
		"drunk_fist" : ({ "fist-technic", 75, 12000 }),
	]) );

	reset();
}
