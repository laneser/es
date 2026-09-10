#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short("湖濱");
	set_long( @C_LONG_DESCRIPTION
你來到一片平坦的沙地，柔細的黃沙使得你的身後，留下一行深深的足印，偶爾
清風吹起，湖面泛起陣陣漣漪，不禁令人有出世之想，沙地旁的草叢長滿了不知名的
野花。
C_LONG_DESCRIPTION
	);

	set_outside("eastland");
	set( "exits", ([ 
		"west" : TROOM"beach1",
		"south" : TROOM"shallow2" ]) );
	set( "pre_exit_func",([
	        "south":"check_enter"
	        ]));
	reset();
}
int check_enter()
{
    if ((int)this_player()->query_skill("swimming")-random(5)<13){
    write (
    "你走入水中，突然想起你不太會游泳，連忙跑回岸上\n");
    return 1;
    }
    else return 0;
 }   