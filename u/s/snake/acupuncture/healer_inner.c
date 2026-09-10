#include <mudlib.h>

inherit "/d/healer/building/study" ;
inherit ROOM;

void create()
{
	::create();
    set_short("Healer's inner room", "行醫者書房");
	set_long( @LONG_DESCRIPTION
This is the inner section of healer's guild. Many valuable data is
stored here for fellow healers to study. In front of you is a book
shelf, you can find the books by searching the catalog. Also you
can see a human model with outlines on different nurves.. etc.
LONG_DESCRIPTION
		, @C_LONG_DESCRIPTION
這裡是行醫者們交換醫術心得的地方，不少行醫者都以能夠將自己的著述陳列
在這裡為榮，你在這裡可以研讀(study)其他行醫者所留下來的醫學著述，在你的
前方是一個巨大的烏檀木書架，你可以先從書架上的目錄(catalog)找起，另外，
你還可以看到一個木製的人體模型(model)，上面標示著一大堆經脈與術語。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
//	set( "c_item_desc", ([ 
//		"model" : @LONG_TEXT
//這個人體模型是行醫者用來練習針灸用的，對新手而言，用人體模型練習針灸
//可說是必修的課程。
//LONG_TEXT
//	]) );

        set( "objects", ([
                       "model" : "/d/healer/objs/model" ,
                       ]) ) ;	
        set( "item_func", ([
 		"catalog": "view_catalog" ]) );
	set( "exits", ([ 
		"west" : "/d/healer/building/healer_guild",
		"up" : "/d/healer/building/healer_upper",
		"south" : "/d/healer/building/healer_troom",
		"north" : "/d/healer/building/healer_reagent" 
		
		]) );

	set_spells( ([
		"heal"        : ({ "white-magic", 20, 4, 20, 100 }),
		"power-boost" : ({ "white-magic", 35, 3, 10, 150 }),
		"protect"     : ({ "white-magic", 60, 4, 10, 200 }),
		"paralyze"    : ({ "white-magic", 15, 4, 10, 100 }),
		"antidote"    : ({ "white-magic", 15, 6,  5, 100 })
	]) );
	
	reset();
}

