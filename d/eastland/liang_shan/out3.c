#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "小路" );
	set_long(@LONG
這是一條地圖上找不到的小路，兩旁長滿了長長的蘆葦，隨風搖曳。	  
傳說這兒常有翦徑強人出沒，他們會不會就躲在蘆叢內呢? 你不禁多看
了看蘆葦(weed)深處幾眼
LONG
   );
        set("c_item_desc",(["weed":
"你仔細的看著這一大叢蘆葦，一陣風來，你突然發現蘆葦叢後似乎別有\n"            
"洞天，也許你可以試著進去(pass)看看....\n"            
            ]));        
	set_outside("eastland",1);
        set( "exits", ([
                "north" : TROOM"out2",
                "south" : "/d/eastland/1,12.east"
        ]) );
        reset();
}
void init()
{
add_action("do_pass","pass");
}

int do_pass(string arg)
{
 if ( !arg || arg != "weed")
    return notify_fail("pass 什麼? 要 all pass 就快去唸書吧 !\n");
 if ( present("mountain thief"))  
 	return notify_fail("山賊把你攔住，曖昧的看著你 ...\n");
    write ("你兩手分開蘆葦叢，一頭鑽了進去...\n");
    tell_room(this_object(),
    "你看到"+this_player()->query("c_cap_name")+ "一頭鑽進了蘆葦叢.....\n" ,
    this_player());
    this_player()->move_player(TROOM"lake/beach10","SNEAK");
return 1;
}
int clean_up() { return 0; }    