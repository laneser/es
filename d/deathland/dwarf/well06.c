
#include "../echobomber.h"

inherit ROOM;

int squ;
void create()
{
	::create();
  set_short("well","地下河道");
  set_long(@Long
Long
,@CLong
四周到處都是青苔和一些奇怪的小蟲,而且這裡的泥土十分潮溼,似乎這裡是地下
河川的河道,但是目前這河道已經乾枯了.南邊的巖壁上有著一個細細的狹縫,勉強你
可以擠過去.
CLong
);

set("exits",([
     "northwest":Deathland"/dwarf/well04",
     "southeast":Deathland"/dwarf/well07",
     "south":Deathland"/dwarf/pass01.c",
     ]) );
set("pre_exit_func",([
    "south":"to_south",
    ]) );     
 ::reset();
}

int to_south()
{
    write("你用力地擠過去這個細縫後,你的人似乎有著騰空的感覺.看一看地面\n"
          "啊!離地竟然有五六尺.\n\n\n\n\n咻...............\n砰的一聲,你整個人跌了下來\n"
         );
    return 0;  
}
