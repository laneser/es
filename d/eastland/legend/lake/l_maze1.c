#include "../legend.h"

inherit LAKE+"in_lake1";

void create()
{
        ::create();
    set_short("大海");
        set_long( 
@LONG
你劃著船槳來到了海面上，極目四眺，是一片風平浪靜的無垠大海，遠處幾艘
漁船正隨著波浪載浮載沈，撒網成群，辛勤地捕著漁。波面上不時穿梭著飛魚，陽
光反射其身上，好似一顆顆亮晶晶的銀寶石。
LONG
    );
    ::reset();     
}

