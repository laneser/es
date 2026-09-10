#include "../tsunami.h"
#include <daemons.h>

inherit HOME+"magic";
inherit ROOM;

void create()
{
    ::create();
    set_short("神武懸崖");
    set_long(@LONG
陣陣的強風迎著懸崖壁向你的身軀襲了過來，彷佛正無情的鞭打著你似
的；沒錯，這兒正是魔族國境的最高處，放眼看去，國境盡入眼中；前方几
步處是一片大斷崖，沒有人敢輕易靠近，深怕被強風捲落；也有人為證明自
己是勇者而跳了下去(jump)，但都沒回音；中間石頭上有幾個字(words)！
LONG
            );
     set("light",1);
     set_outside("island");
     set("item_desc",(["words":@WORDS

　　『唯有相信神的存在，方能證明自我的價值，才能成為真正智勇兼備的勇者！』
         
WORDS
                     ]) );
     set("exits",([
         "west":AREA"in3",
         "south":AREA"h3",
         "north":AREA"h1"
                  ]) );
}

void init()
{
     add_action("do_jump","jump");
}

int do_jump(string str)
{
     int hour;
     
     if( !(this_player()) ) return 0;
     if( !str || str!="down" )
     {
     write(@ALONG
    你要往哪兒跳呀？這兒只能往下跳耶！！
ALONG
          );
     return 1;
     }      

     if( !this_player()->query_explore("island#1") ) {
     write("\n你突然一個失足 ..... \n");
     this_player()->move_player(AREA"upriver","SNEAK");
     this_player()->set("hit_points",1);
     this_player()->set("spell_points",1);
     this_player()->set("talk_points",1);
     this_player()->set("force_points",1);
     this_player()->set("block_command",1);
     call_out("remove_block",10,this_player() );
     return 1;
     }
     else {
         write(@BLONG
               你奮力的，努力的向前一躍........
BLONG
         );                 
                                                       
     sscanf(WEATHER_D->query_game_time(),"%d",hour);
     if( hour >= 8 && hour < 16){
       tell_room(environment(this_player()),
         this_player()->query("c_name")+"很衝動地向懸崖躍了下去........\n"
         ,this_player() );
       this_player()->move_player(AREA"upriver","SNEAK");
       write("孩子，你的選擇是～～正確的！\n");
       tell_room(environment(this_player()),
         this_player()->query("c_name")+"以完美的姿勢自天空飄下.......\n"
         ,this_player() );
       return 1;
     }
     else{
       tell_room(environment(this_player()),
         "突然大風一吹，"+this_player()->query("c_name")+"一不小心掉下懸崖了！\n"
         ,this_player() );
       this_player()->move_player(AREA"river","SNEAK");
       tell_room(environment(this_player()),
         this_player()->query("c_name")+"以極難看的姿勢跳入水中，你心想：唉，兩分..\n"
         ,this_player() );
     this_player()->set("hit_points",(int)this_player()->query("hit_points") / 10);
     report(this_object(),this_player());
     return 1; 
         }
    }
}
