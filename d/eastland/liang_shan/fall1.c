#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "半空中" );
	set_long(
	"你正在半空中，不停的向下墜落，往腳下看去，無邊的黑暗正如巨獸\n"
	"張開大嘴向你迎面而來，你意識到這對你來說，可能是一個悲慘的結束\n"
	);
        set( "pre_exit_func", ([
                "down" : "check_fall"
        ])) ;        
        set( "exits", ([
                "down" : TROOM"fall2"
        ]) );
}
int check_fall()
{
write(
"\n你不停的向漆黑的空間落去。\n\n");
return 0;
}
int clean_up() { return 0; }