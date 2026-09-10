#include "saulin_temple.h" 
  
inherit "/d/monk/guild/train_gonfu.c";
inherit ROOM;

void create()
{
	room::create();
	set_short("A heal gonfu room", "療傷神功練功房");
	set_long( @LONG_DESCRIPTION
NEED TRANSLATE HERE.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
這裡是少林寺專門教導各種不同運功療傷武學的練功房，大部份基礎的療傷
武功秘笈都放在這裡，一些使用注意說明請看佈告欄(board)。
在你面前是一排泛黃的羊皮紙 (paper)，你可以根據自己的武學造詣選擇你能夠
學習的武功\，然後在此處訓練(train)，往西可以回到羅漢堂。 
C_LONG_DESCRIPTION
	);
   
    set("c_item_desc",([
         "board":@BOOK
療傷神功是用來恢復你在戰鬥中所受傷害的功夫。使用方法是 eungon [功夫名稱]

1. 輪指封穴: 點穴止血
2. 運功逼毒: 以你的穴道學知識及內力大小，運功將體內毒素逼出
3. 其它: 大都為療傷用，也許有其它效果  

BOOK
	]));         
	set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"west" : SAULIN"monk_guild" ]) );
	set( "item_func", ([
		"paper": "view_catalog" ]) );

	// setup type of gonfus & name of gonfus.
	set_gonfu_type("heal");
	set_gonfus( ([
//		"gi-chi"  : ({ "heal-cycle",  5,   200 }),
		"bi-du"   : ({ "heal-cycle", 65,  7500 }),
		"lun-chi" : ({ "heal-cycle", 25,  2000 }),
		"pu-ty"   : ({ "heal-cycle", 50,  5000 }),
		"gun-in"  : ({ "heal-cycle", 85, 20000 }),
	]) );
	reset();
}
