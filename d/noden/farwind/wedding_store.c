// File: /d/noden/farwind/wedding_store.c////#pragma save_binary

#include <mudlib.h>
#include <money.h>

inherit "/std/room/room";
inherit "/std/seller";

void create()
{
	::create();
	set_short("結婚禮服店");
	set_long( @LONG_DESCRIPTION
這裡是聞名世界, 別無分號的婚紗禮服店,
你看到四周的櫥窗佈滿一件件精美的禮服, 另外
它也提供捧花及結婚戒指. 你心裡想: 還是問問
老闆的意見吧!
LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "exits", ([ 
		"north" : "/d/noden/farwind/ebazz" ]) );
   set( "item_func", ([
		"menu" : "show_list",
        ]) );
   set_inventory( ({
         ({ "/d/noden/farwind/wedding_obj/boys_boots", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/boys_gloves", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/boys_pants", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/boys_scarf", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/swallowtail", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_boots", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_cape", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_gloves", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_lace", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_skirt", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_suit", 5, 5 }),
         ({ "/d/noden/farwind/wedding_obj/wedding_flower", 5, 5 }),
     }) );
   set( "objects", ([
        "boss" : "/d/noden/farwind/monster/meph"
     ]) );
	reset();
}

int show_list()
{
   show_menu();
   write("  結婚戒指 (wedding ring)          5000 銀幣        無限供應\n"
	 "  結婚護盾圓球 (wedding globe)     8000 銀幣        無限供應\n");
   return 1;
}

void reset()
{
     room::reset() ;
     seller::reset() ;
   return ;
}
