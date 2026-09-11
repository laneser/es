#include "takeda.h"

inherit ROOM;

void create()
{
	::create();
	set_short( "小庭院" );
	set_long(
	"這是忠義堂後的小小庭院，面積似乎不大，但花木扶疏，舉目四望，\n"
	"竟種滿了無數梅花，婉約娟秀，別有一番滋味。清風徐來，梅花特有的\n"
	"清香瀰漫在風中....\n"
	);
        set_outside("eastland");
        set( "pre_exit_func", ([
                "east" : "check_leave",
                "south" : "check_leave",
                "west"  : "check_fall",
                "north" : "check_shut"
        ])) ;        
        set( "exits", ([
                "east" : TROOM"yard5",
                "south" : TROOM"yard3",
                "west" : TROOM"yard3",
                "north": TROOM"yard4"
        ]) );
        reset();
}
int check_leave()
{
write(
"你撥開樹叢，鑽了進去，但這片梅林似乎無窮無盡。\n");
return 0;
}
int check_fall()
{
write(
"你撥開樹叢，鑽了進去，忽然腳下一空，跌進一個大陷坑。\n");
this_player()->move_player( TROOM"fall1","SNEAK");
return 1;
}
int check_shut()
{
write(
"你撥開樹叢，鑽了進去，不知觸到什麼機關，如雨射下一堆箭矢。\n");
this_player()->set("hit_points",(int)this_player()->query("hit_points")-15);
return 0;
}
int clean_up() { return 0; } 