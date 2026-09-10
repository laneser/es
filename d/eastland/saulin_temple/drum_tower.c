#include "saulin_temple.h"

#include <daemons.h>
#define NEED_FP   200
#define REDUCE_FP  20

inherit ROOM;
inherit STATS_D;

void create()
{
       ::create();
       set_short("鼓樓");
       set_long( @C_LONG_DESC
你沿著石階爬上一座古樓，樓上懸著一面巨鼓(drum)，硃紅的鼓身暗黃
的鼓面顯示這面鼓已有多年歷史了，在鼓旁有一支鼓錘，平時只有在傍晚才
有專人來敲(hit) 這面鼓，這就是所謂的 "暮鼓" 。據說這些敲鼓的人往往
身負上乘內功，因為巨鼓一響，所發出了音波強度，真的不是普通人能受得
了的。西方是一座偏殿。
C_LONG_DESC
       );
       set("light",1);
       set("item_desc",([ "drum" : @C_LONG
這是一面巨鼓，光是鼓身就有一個人高，如果不蒙上鼓面的話，塞上五、
六個人是沒問題的。現在它的鼓身鼓面都已經泛黃了，但是它的外表仍然
保持光潤，顯示有人常來保養它。
C_LONG
       ]));
       set("exits",([
           "west" : SAULIN"side_temple2",
       ]) );
       reset();
}

void init()
{
     add_action("hit_bell","hit");
}

int hit_bell(string str)
{
     if( !str || str != "drum" )
       return notify_fail("你要敲什麼?\n");

     if( (int)this_player()->query("force_points") < NEED_FP ) {    
       this_player()->receive_damage((int)this_player()->query("max_hp")/4);
       tell_object(this_player(), @C_LONG
  你拿起鼓槌，用力的往鼓面敲了下去，你感覺到一股音波如排山倒海般的
  從鼓面向你湧了過來，把你的五臟六腑震的四分五裂。
C_LONG
       );
       tell_object(this_player(),
         "( 你 "+status_string()+" )\n");
     } else {
       tell_object(this_player(), @C_LONG
  你拿起鼓槌，用力的往鼓面敲了下去，你感覺到一股音波如排山倒海般的
  從鼓面向你湧了過來，你趕緊運起內力抵抗。
C_LONG
       );
       this_player()->add("force_points", -REDUCE_FP);
     }
    return 1;
}       
