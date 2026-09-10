#include "../legend.h"

inherit ROOM;

void create()
{
        ::create();
    set_short("沼澤");
        set_long( 
@LONG
你發現沿途上的如畫美景似乎只到這裡為止，往西看去，只見遍地枯木，沼氣
氤氳。面前有一張告示貼在一具木架上，告示寫道：

                危險！往西通往沼澤地帶，沼澤內有『劇毒』瘴氣，
           更有『極』兇猛吞人野獸，請愛惜性命，『千萬絕對不要進入』。

LONG
    );
    set("exits",([
            "northeast":LAKE"village1",
            "west":LAKE"swamp1",
       ]) );
    set("objects",([
             "crab#1":LMONSTER"crab",
             "crab#2":LMONSTER"crab",
             "crab#3":LMONSTER"crab",
             "crab#4":LMONSTER"crab",
             "crab#5":LMONSTER"crab"
    ]) );
    reset();
}

