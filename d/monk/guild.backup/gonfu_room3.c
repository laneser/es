#include "saulin_temple.h" 

inherit "/d/monk/guild/train_gonfu.c";
inherit ROOM;

void create()
{
	room::create();
	set_short("A protect gonfu room", "少林武學精武房");
	set_long( @LONG_DESCRIPTION
NEED TRANSLATE HERE.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
這裡是少林寺學習各種不同刀棍護身武學的練功房，大部份常見的的少林武功\
秘笈都放在這裡。一些特殊的武功秘笈則被放在樓上的少林七十二絕技房及藏經閣
在你面前是一堆泛黃的卷軸(scroll)，你可以根據自己的刀棍武學造詣選擇你能夠
學習的武功，然後在此處訓練 (train)，角落有一個注意須知(note)你不妨先看看 
往南可以回到羅漢堂，向上則通內功心法房。
C_LONG_DESCRIPTION
	);

    set("c_item_desc",([
         "note":@BOOK
少林武學是用來在戰鬥中攻擊敵人或防護自己的功夫。使用方法是 

                  eungon [功夫名稱] 
       然後再     k      [怪物名字]

少林武學強弱和熟練度有很大的關係，所以要多多使用以增加熟練度。功夫在精不  
在多，所以你不一定要每一樣都學。熟練度為零的效果和一百時有所差異，不要忘 
記當熟練經驗值夠了時要去訓練提升武學境界。
(攻擊，醫療和護體的功夫一次只能三選一用。)   
BOOK
	]));         

    set( "no_monster", 1);
	set( "light", 1 );
	set( "exits", ([ 
		"up"    : SAULIN"inner_room",
 		"south" : SAULIN"monk_guild" ]) );
                 
	set( "item_func", ([
		"scroll": "view_catalog" ]) );

	set_gonfu_type("general");
	set_gonfus( ([
        "tai-zuo"  : ({ "martial-art", 15,   800 }),
        "wu-sur"   : ({ "martial-art", 30,  2200 }),
	"da-mo"    : ({ "martial-art", 30,  2000 }),
	"fu-mo"    : ({ "martial-art", 60, 10000 }),
        "bolo-mi"  : ({ "martial-art", 25,  1000 }),
	"chu-han"  : ({ "martial-art", 85, 21000 }),
        "gi-mei"   : ({ "martial-art", 65,  8000 }), 
	]) );

	reset();
}
