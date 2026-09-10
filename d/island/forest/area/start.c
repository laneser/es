#include "../tsunami.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("有明海");
    set_long(@LONG
這是個十分清澈乾淨的湖(lake)，名字叫「有明海」是因為只要天上有
些許光線，這湖就會閃爍異樣的光芒。湖畔長滿了楊柳，垂掛在湖面上，映
著微波閃閃，身旁偶而吹過幾陣使人心曠神怡的清風，不禁使你覺得心情暢
快；如果你覺得時間充裕的話，在這兒泡泡澡，遊游泳倒也無妨！
LONG
            );
    set("light",1);
    set_outside("island");
    set("water_source",1);
    set("exits",([
        "west":"/d/island/11,7.island"]) );
    set("item_desc",([
         "lake":@LAKE
一個波光閃閃的小湖，你心想：在這兒游泳應當是一種享受！
LAKE
             ]) );
    set("objects",(["indi":TMOB"indi"]) );
    reset();
}
void init()
{
    add_action("do_swim","swim");
}
int do_swim(string str)
{
    write(@ALONG
    你迫不及待的一下子就往湖裡頭跳，突然暗潮將你吸到一個莫名其妙的怪地方...
ALONG
         );      
      tell_room( environment(this_player()),
      this_player()->query("c_name")+
      "連衣服都沒脫就跳進湖中爽快去了，叫都沒用，這個可惡的痞子..\n"
      , this_player() );
      this_player()->move_player(AREA"in","SNEAK");
     tell_room( environment(this_player()),
     "你看到"+this_player()->query("c_name")+"像死魚般一動也不動的飄了過來...\n"
     ,this_player() );   
   return 1;
}                      
                      
    
