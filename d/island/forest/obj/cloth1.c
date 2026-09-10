#include "../tsunami.h"

inherit ARMOR;

void create()
{
    set_name("Police Uniform","警用緊身裝");
    add("id",({"cloth","uniform"}) );
    set_short("警用緊身裝");
    set_long(@LONG
這是魔族保安衙門中的勤務專用制服．當一位服勤中的保安官穿上它時，將會
忘了束縛的存在，同時也能給予使用者相當程度的防護，以提高偵辦案件的效率．
LONG
            );
     set("unit","件");
     set("type","body");
     set("material","cloth");
     set("armor_class",30);
     set("defense_bonus",2);
     set("special_defense",(["divine":20,"mental":15,"fire":-15]) );
     set("weight",150);
     set("value",({600,"silver"}) );
}              