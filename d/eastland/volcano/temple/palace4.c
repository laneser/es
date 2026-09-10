#include <daemons.h>
#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

int min,hour,day,year;
string month;

void create()
{
	::create();
	set_short( "走廊" );
	set_long(
@LONG
你正漫步在井龍宮的走廊，一盞盞琉璃燈火懸在走廊的兩旁，在這裡你做什麼事
都得特別小心，否則會發生什麼事只有天知道。
你注意到在你的西邊有一扇紅寶石大門(door)。
LONG
	);
	set( "exits", ([
             "north" : OTEMP"palace6",
             "west" : OTEMP"palace4",
	     "east" : OTEMP"palace3",
	]) );
        set("item_desc",([
            "door":
"一扇紅寶石大門，門上面有塊圓形水晶(crystal)，想打開這扇門必需看準時間。\n",
            "crystal":"@@look_crystal",
            ]) );
         set("pre_exit_func",([
             "west":"to_west"
             ]) );
         set("light",1);
         reset(); 
}

int to_west()
{
  printf("\n門上的水晶發出一道紅光射中你的身體，把你從門邊推開。\n");
  return 0;
}

string look_crystal()
{
  string str;

  sscanf(WEATHER_D->query_game_time(),"%d:%d, %s %d, Year %d",hour,min,month,day,year);
//  printf("%d %d\n",hour,min);
  if ((((min-30)>hour) && (hour<12)) || (((min-15)>hour) && (hour>12)) )
    this_player()->set_temp("ruby_door",1);
  else
    this_player()->delete_temp("ruby_door");
  str="\n你向水晶望去，清楚的從裡面看到一排字 ： \n"+ WEATHER_D->query_c_game_time()+"\n\n";
  return str;
}

void init()
{
  add_action("do_touch","touch");
}

int do_touch(string arg)
{
  if (!arg || arg!="crystal" )
    return 1;
  if (this_player()->query_temp("ruby_door")) {
    printf("\n水晶發出一道柔和的白光將你朧罩，\n");
    printf("\n你定下神來，發現自己被四周刺眼的亮光所包圍。\n");
    this_player()->move_player(OTEMP"palace9","SNEAK");
    this_player()->delete_temp("ruby_door");
    return 1; }
  printf("\n水晶嗡嗡作響：你來得不是時候。\n");
  return 1;
}
