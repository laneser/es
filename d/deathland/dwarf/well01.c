
#include "../echobomber.h"

inherit ROOM;

int squ;
void create()
{
	::create();
set_short("well","井底");
  set_long(@Long
Long
,@CLong
一個很深的井,而井裡的水已經乾枯了.\井的四周長滿了青苔,似乎爬上去並不
是一件容易的事.在井底有一道裂痕(crack),似乎水都是從這裡流出去的.
CLong
);

set("c_item_desc",([
    "crack":"@@to_crack",
     ]) );

set("search_desc",([
    "crack":"@@to_search_crack"
     ]) );   

  reset();

}

void init()
{
    add_action("to_climb","climb");
    add_action("to_squeeze","squeeze");
}

int to_squeeze()
{
   if (squ==1) {
     write("你無法鑽進如此小的裂縫\n");
     }
   else
     {
     write("你勉強地鑽進去這裂縫\n");
     write("你的人整個掉了下去.\n.\n.\n.\n.\n");
     this_player()->set_explore("deathland#5");
     this_player()->move_player(Deathland"/dwarf/well02",({
      this_player()->query("short")+"從裂縫掉了下去\n",
      this_player()->query("short")+"從上面掉下來\n",
      }),"");
     }
   return 1;     
} 

int to_climb()
{
    if ( (int)(this_player()->query_skill("climbing")) >= 60 ) 
      {
       say(this_player()->query("c_name")+"從井底慢慢地爬了上去\n");
       write("你廢了很大的力氣才爬出井底\n");
       this_player()->move_player(Deathland"/dwarf/village_09","SNEAK","");
      } 
    else
      { 
       say(this_player()->query("c_name")+"爬呀爬但還是和你在同一個地方\n");
       write("你廢了很大的力氣但就是爬不出井底\n");
      }
    return 1;
}

string to_search_crack()
{
    if (squ==1) {
      squ=2;
      return "當你仔細搜查這裂縫時,發現旁邊的石頭有點鬆動.你把石頭撥開\n"
             "讓這裂縫變大了許多.\n";
      }
    else
      {
      return "一個周圍石頭曾被移動過的裂縫.\n" ;
      }   
}

string to_crack()
{
  if (squ==1)
    return "一道小小的裂縫.\n";
  else 
    return  "一道大的裂痕,\或許你可以試著鑽(squeeze)進去\n";
}

void reset()
{
  ::reset();
  squ=1;
}
