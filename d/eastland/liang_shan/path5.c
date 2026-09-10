#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "石板路" );
	set_long(
	"這是點將臺後的一條石板路，比起天王大道來不算大，說小卻又能供五馬\n"
	"並行，路的盡頭，赫然是座輝宏華麗的大院，千椽萬瓦，燈火輝煌。門口(gate)\n"
	"蹲踞著兩隻猙獰的石獅子，你不知道是不是該進去(enter)。\n"
	);
	set( "light",1 );
        set_outside( "eastland" );
        set( "no_monster",1);
        set( "exits", ([
                "south"  : TROOM"plate",    
        ]) );
        reset();
}
void init()
{
add_action("do_pass","enter");
}
int do_pass(string arg)
{
 if ( !arg || arg != "gate")
    return notify_fail(
    "你想要進去那兒?\n");
    write (
    "你雙手推開門板，大步走了進去...\n");
    tell_room(this_object(),
    "你看到"+this_player()->query("c_cap_name")+ "大步走進了門內。\n" ,
    this_player());
    this_player()->move_player(TROOM"chuyi_hall","SNEAK");
return 1;
}
int clean_up() { return 0; }    