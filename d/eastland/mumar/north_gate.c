#include <mumar.h>
inherit ROOM;
 
void create()
{
 
        ::create();
        set_short("牧馬關");
        set_long( @C_LONG_DESCRIPTION
這裡是牧馬關的北門，雄偉的建築結構再次出現在你的眼前。向北出了關外就是
一片除了沙還是沙的黃色世界。歷代的探險家和商人花費了幾百年的時間才在這片茫
茫的翰海之中建立了絲綢之路，然而卻有更多冒失的冒險家在那兒丟了性命。從這兒
往北就可以出關，往南不遠則是教場。
C_LONG_DESCRIPTION
        );
        set( "light" ,1 );
        set( "exits", ([
                "south" : MUMAR "square05",
                "north" : MUMAR "north_gate"]) );
        set( "objects", ([
                "guard#1" : MOB "gate_guard",
                "guard#2" : MOB "gate_guard",
                 ]) );
 
        set("pre_exit_func",(["north":"go_north"]));
        reset();
}
 
int go_north()
{
        write("你試圖向北走出城門，但一陣沙漠風暴把你吹了回來\n。");
        return 0;
}
