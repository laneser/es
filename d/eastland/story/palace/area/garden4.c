#include "../../story.h"

inherit SPALACE"RR";

void create()
{
        ::create();
	set_short("玉石小徑");
	set_long( @LONG
不知不覺你已經走到了玉石小徑的盡頭。小徑通體紅玉鋪成，質若明晶，兩旁
均是參天花樹，因為樹大枝繁，上面花枝糾結連成一片，一眼望去，直似兩條花龍
錦城，蜿蜓飛舞。小徑東邊就是後花園了。

LONG
	);
        set("light",1);
        set("exits" , ([
           "northwest" : SPALACE"garden3",
                "east" : SPALACE"garden5",
        ]) );
        set("pre_exit_func",([
           "east":"can_pass"]));
        reset();
}
int can_pass()
{
    if ( this_player()->query("palace_war") ) return 1;
    return 0;
}