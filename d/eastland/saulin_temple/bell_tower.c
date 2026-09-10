#include "saulin_temple.h"

#include <daemons.h>
#define NEED_FP   200
#define REDUCE_FP  20

inherit ROOM;
inherit STATS_D;

void create()
{
       ::create();
       set_short( "鐘樓" );
       set_long( @C_LONG_DESC
你沿著石階爬上一座高樓，樓上懸著一口巨鍾(bell)，黝黑的鐘身和綠色的銅鏽
，使得這口鐘顯得厚重異常。在鍾旁懸有一根巨木，平時只在凌晨才有專人來撞(hit)
這口鐘，就是所謂的 "晨鐘" ，但是這口鐘也可以用特定的信號召集僧眾或傳遞緊急
消息。據說撞鐘的僧人都由寺中一流高手擔任，因為巨鍾一響，所發出的音波強度，
將會使一個普通人嘔血身亡。東側是一座偏殿。
C_LONG_DESC
               );
       set("light",1);
       set("item_desc",([
         "bell" : @C_LONG
    這是一口大銅鐘，它的表面鑄出了許多美麗繁複的花紋，不曉得當初鑄它的
高手匠人是怎麼完成的？現在它的表面都已經發黑了，顯然它的年歲也不少了，
可是它仍然保養的很好。顯然有人常常來看顧它。
C_LONG
]));

       set("exits",([
         "east" : SAULIN"side_temple1",
       ]) );
       reset();
}

void init()
{
     add_action("hit_bell","hit");
}

int hit_bell(string str)
{
     if(!str || str != "bell")
       return notify_fail("你要敲什麼?\n" );
     if( (int)this_player()->query("force_points") < NEED_FP ) {
       this_player()->receive_damage((int)this_player()->query("max_hp")/8);
       tell_object( this_player(), @C_LONG
  你拿起巨木，用力的往鍾撞了下去，你感覺到一股音波如排山倒海般的
  從鐘口向你湧了過來，把你的五臟六腑震的四分五裂。
C_LONG
);
       tell_object(this_player(),
         "( 你" + status_string() + " )\n");
     } else {
       tell_object( this_player(), @C_LONG
  你拿起巨木，用力的往鍾撞x2了下去，你感覺到一股音波如排山倒海般的
  從鐘口向你湧了過來，你趕緊運起內力抵抗。
C_LONG
       );
       this_player()->add("force_points", -REDUCE_FP);
     }
        this_player()->set_explore("eastland#28");
     return 1;
}       
