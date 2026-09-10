
inherit ROOM;

void create()
{
        ::create();
        set_short("教練場");
        set_long( @LONG_DESCRIPTION
這裡是黑暗精靈士兵平時訓練的場地，你可以看到十餘個士兵正辛苦的
接受著操課。
LONG_DESCRIPTION
        );
        set( "exits", ([
        "south" : "/d/noden/drow/square2",
                     ]) );
    reset();
}//end of creat
