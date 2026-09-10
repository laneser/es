#include <mudlib.h>

inherit "/d/healer/building/study" ;
inherit ROOM;

void create()
{
	::create();
    set_short("Healer's inner room", "行醫者書房");
	set_long( @C_LONG_DESCRIPTION
這裡是行醫者們交換醫術心得的地方，不少行醫者都以能夠將自己的著述陳列
在這裡為榮，你在這裡可以研讀(study)其他行醫者所留下來的醫學著述，在你的
前方是一個巨大的烏檀木書架，你可以先從書架上的目錄(catalog)找起，另外，
你還可以看到一個木製的人體模型(model)，上面標示著一大堆經脈與術語。
C_LONG_DESCRIPTION
	);

	    set( "light", 1 );
        set( "objects", ([
                       "model" : "/d/healer/objs/model" ,
                       ]) ) ;	
	set( "exits", ([ 
		"west" : "/d/healer/building/healer_guild",
		"up" : "/d/healer/building/healer_upper",
		"south" : "/d/healer/building/healer_troom",
		"north" : "/d/healer/building/healer_reagent" 
		
		]) );
	reset();
}

