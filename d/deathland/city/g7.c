
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
set_short("The graveyard of Hero","英雄墓場");
  set_long(@Long
這裡是矮人英雄的墓場,墓場裡埋藏著一位縱橫沙場的英雄.這一座墓碑的碑銘上
寫著: 一位令人敬仰的無敵英雄.
Long
);
set("exits",([
            "east":Deathland"/city/g6",
            "west":Deathland"/city/g8",
            "north":Deathland"/city/gb",
             ]));
set("pre_exit_func",([
    "north":"to_north",
    ]) );
    
set("objects",([
    "guard":Monster"/guard05",
    ]) );
    
reset();    
}

int to_north()
{
    if (!present("guard")) return 0;
    write("守衛把你擋了下來.\n");
    return 1;
}
