#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "小庭院" );
	set_long(
	"這是忠義堂後的小小庭院，面積似乎不大，但花木扶疏，舉目四望，\n"
	"竟種滿了無數梅花，婉約娟秀，別有一番滋味。清風徐來，梅花特有的\n"
	"清香瀰漫在風中，東方的樹叢間，隱約看到一間小房子....\n"
	);
        set_outside("eastland");
        set( "pre_exit_func", ([
                "east" : "check_east"
        ])) ;        
        set( "exits", ([
                "east" : TROOM"room1",
                "north" : TROOM"yard4"
        ]) );
        reset();
}
int check_east()
{
write(
"你撥開樹叢，進入一間小書房。\n");
return 0;
}
int clean_up() { return 0; }