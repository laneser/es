#include "../dony.h"

inherit ROOM;

void create()
{
	::create();
        set_short( "north8", "村路" );
	set_long(@C_LONG
你現在正走在一條頗為寬大的村路上,約可容納兩匹馬並行。村路向東、西方
向延伸。這條村路整理得蠻乾淨的,路旁的植物修緝的很整齊,花兒欣欣向榮,比起
廣場那片光禿禿的景像自是不可而語。畢竟這條是連接幾個較大鋪子,可說是村內
最繁華的道路。雖是如此, 卻看不出任何人工刻意留下來的痕跡,這一定是出自於
某位名匠之手。由北邊遠遠地望去,一排排矮矮的房子顯然是村內人們居住的地方
。西邊通往『賞善罰惡廳』。
C_LONG
	);
        set_outside("noden");
	set( "exits", ([
                      "east":DBEGGAR"north5.c",
                      "west":DBEGGAR"north10.c" 
	]) );
        set( "pre_exit_func", 
                      ([ 
                      "east": "can_pass",
                      "west": "can_pass"
        ]) );
        set( "objects", ([
                      "chau":DMONSTER"chau.c",
                      "burro":DMONSTER"donkey.c"
        ]) );                                    
     reset();
}

int can_pass()
{ 
   
   if( this_player()->query_temp("mounting") && !wizardp(this_player() ) 
       &&  present("chau") ){  
      tell_object(this_player(),
        "趙錢孫把你攔了下來恕道:怎麼你的馬跟我的驢子那麼像,是不是我的?\n" );
            return 1;
     } return 0;
}
