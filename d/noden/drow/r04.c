#include "iigima.h"
inherit ROOM;
inherit DOORS;

void create()
{
        ::create();
        set_short( "tunnel","通道");
        set_long(
@C_LONG
這裡是黑暗精靈村的通道，由於整個村落都是在地底下的深處，這
裡陰涼而空氣清新，廣大的通道寬廣平坦，靠近石壁的地方，都雕刻有
蜘蛛，和蛇的圖案。
C_LONG
        );
        set( "light",0 );
        set( "exits", ([

                     "east" : DROW"r05",
                     "west" : DROW"r03",
                     "north": DROW"r01",
        ]) );
        set("objects", ([
                "guard#1": DRO"final_guard",
                "guard#2": DRO"final_guard",
        ]) );
        set( "pre_exit_func", ([
                "north" : "check_guard" ]) );
        reset();

        create_door( "north", "south", ([
                "keyword" : ({ "iron door", "door" }),
                "name" : "iron door",
                "c_name" : "大鐵門",
                "status" : "locked",
                "c_desc" : "一扇冰冷的大鐵門，。\n",
                "lock" : "IRON_DOOR"
        ]) );
        reset();
}
int check_guard()
{
        if ( present("guard", this_object() ) ) {
                write("守衛說道: 裡面是祭祀的神壇，你不能過去啦！\n");
                return 1; }
        return 0;
}
