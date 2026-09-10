#include "../legend.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("沼澤地底洞穴");
    set_long(@LONG
眼前忽然一亮，四下看去，原來是壁上長滿了一種會發光的蕈類，叫做『曙薇』
，長的有巴掌大，發出螢光似的黃色光暈。只見一朵朵大大小小發光的蕈傘，就好像
燈火通明的不夜城一般。嗯，正當你看的入神之際，好像有些什麼東西正緩緩地移動
著，仔細一瞧，才發現，原來你四周有著許許多多的生物正在咬食『曙薇』。有趣的
事，所有的生物都是透明的，只有皮膚及關節的部份可以勉強辨識的出來。
LONG
    );
    set("light",1);
    set("exits",([
            "eastdown":LAKE"swamp_d4",
            "westup":LAKE"swamp_d1",
    ]) );
    set("objects",([
           "mollusk#1":LMONSTER"mollusk",
           "mollusk#2":LMONSTER"mollusk",
           "mollusk#3":LMONSTER"mollusk",
    ]) );
    ::reset();
}

