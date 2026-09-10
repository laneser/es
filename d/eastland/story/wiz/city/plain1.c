#include "../../story.h"

inherit ROOM;

void create()
{
        ::create();
	set_short("東郊");
	set_long( @LONG
這是「巫咸城」外的東郊，大約七、八十尺見方，除了西邊可以進入「巫咸城
」，四周不遠處皆是蓊蓊鬱鬱的樹林。此間雲淡風輕，空氣清新，伴隨著鳥啼蛙嗚
，不時有鹿類隱藏林中奔相逕走，是個狩獵的好地方。
LONG
	);
        set("light",1);
	set( "exits", ([ 
       	    "west" : SCITY"eastgate",
            "north" : SCITY"plain2",
        ]) );
        set( "pre_exit_func", ([
            "north":"do_north",
            "west":"do_west"
        ]) );
	reset();
}
int do_north()
{
    if ( ( (this_player()->query_temp("north")) > 5 ) &&
         present("crystal glass",this_player()) ) { 
       this_player()->delete_temp("north");
       return 0;
    }       
    this_player()->move_player(SCITY"plain1","SNEAK");
    this_player()->add_temp("north",1);
    return 1;
} 
int do_west()
{
    this_player()->delete_temp("north");
    return 0;
}
