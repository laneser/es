#include <mudlib.h>

inherit ROOM;
inherit SELLER;

void create()
{       
        ::create();
        set_short("Healer's shop", "行醫公會藥材行");
	set_long( " no describe\n",
        "刑老爹平時行醫救人, 分文不取, 全靠刑大娘經營這家藥材器具行來維\n"
        "持家計。這裡有很多行醫者必備的器具, 你可以參考掛在牆上的目錄(menu)。\n"
	);
	
	set("objects", ([
	    "mother" : "/d/healer/building/monsters/mother"
	]) );
	set( "light", 1 );
	set( "exits", ([ 
		"south" : "/d/healer/building/healer_guild" ]) );
	set( "item_func", (["menu" : "show_menu"]) );
	set_inventory( ({
                ({"/d/healer/objs/bowl",10,10}),
                ({"/d/healer/objs/herb_hoe",10,10}),
                ({"/d/healer/building/weapons/scalpel",5,5}),
                ({"/d/healer/building/armors/cloth",5,5}),
		({ "/d/healer/reagent/chai_hu",20,20}),
		({ "/d/healer/reagent/chuan_chiung",20,20}),
		({ "/d/healer/reagent/dang_guei",20,20}),
		({ "/d/healer/reagent/ginseng",15,15}),
		({ "/d/healer/reagent/medlar",30,30}),
		({ "/d/healer/reagent/peony",30,30}),
		({ "/d/healer/reagent/swamp_berry",30,30}),
		({ "/d/healer/reagent/swamp_moss",30,30}),
		({ "/d/healer/reagent/sweet_herb",40,40}),
		({ "/d/healer/reagent/yellow_lotus",30,30}),
		({ "/d/healer/reagent/yellow_mushroom",30,30}),
	}) );
        reset();
}

void reset()
{
     room::reset();
     seller::reset();
     return;
}

int do_buy(string arg)
{
    if (this_player()->query("class") != "healer")
	return notify_fail("對不起，這裡只做醫生的生意，您請回吧!\n");
    return ::do_buy(arg);
}
