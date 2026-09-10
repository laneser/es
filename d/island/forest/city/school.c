#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("私塾");
    set_long(@LONG
這兒是魔族的一般人開的私塾，目的在以教授學問來換取個人的生活補
助。雖然一般人把小孩送到私塾來求學問的風氣並不盛，但有錢人家仍希望
自己的子弟能懂得比別人多，好讓自己能在別人面前抬得起頭，因此便把孩
子往私塾送；「授課」這門職業也因此得以存活下去。
LONG
            );
    set("light",1);
    set("exits",(["west":CITY"sway1"]) );
    set("objects",([
        "teacher":TMOB"teacher",
        "student#4":TMOB"student",
        "student#3":TMOB"student",
        "student#2":TMOB"student1",
        "student#1":TMOB"student1"]) );
    reset();
#include <replace_room.h>
}
