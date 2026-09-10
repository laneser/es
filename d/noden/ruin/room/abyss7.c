// abyss7.c

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();

    set_short("冥王行宮");
    set_long(@C_LONG
這裡是冥王的行宮，極盡陰森恐怖之能事於一地。你不禁替你自己的前途
擔憂起來，因為光看這裡的佈置，就知道這裡的主人是個喜歡送人下地獄的家
夥，看來得賭上你一生的好運，才有離開這裡的機會。
C_LONG
    );
    set("light", 1);
    set("objects", (["archfiend" : MOB"archfiend"]) );

    reset();
}
 
