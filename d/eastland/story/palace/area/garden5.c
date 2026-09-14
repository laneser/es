#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("後花園");
	set_long( @LONG
這裡是後花園。後花園內漫天花海，瓊枝碧葉，上綴各色繁花。花開嬌豔，到
處香光盪漾，人從花下走過，沾了滿身香氣，那花香竟也與別處不同，不特清馨細
細，沁人心脾，氣味並不十分濃烈，□覺暗香微逗，自然幽□。旁邊一座涼亭，珠
光寶氣，吃周圍花林一襯，好似個萬姝中的嬌娘，明豔不可一視。

LONG
	);
        set("light",1);
        set("exits" , ([
               "west" : SPALACE"garden4",
               "east" : SPALACE"garden6"
        ]) );
        set("pre_exit_func",([
            "east":"can_pass"]));
        set("objects", ([
            "gardener1" : SPMOB"gardener1",
        ]) );
	reset();
}
int can_pass()
{
    object gardener;
    if ( !gardener=present("gardener",this_object()) ) return 0;
    if ( this_player()->query_attacker() ) {
      write(sprintf("\n%s把你攔了下來說道：你這小子，要滋事到別的地方去！！\n\n",
      gardener->query("c_name")));
      return 1;  
    }
    return 0;
}