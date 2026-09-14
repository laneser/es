#include "../legend.h"

inherit MONSTER;

void create()
{
        ::create();
        set_name( "old captain", "老船東" );
        add("id",({"captain"}));      
        set_short( "老船東");
        set("unit","位");
        set_long(
@LONG
一位漁村裡頭的老船東，他在海上捕魚己經有五十年的歷史了，現在因為年紀老邁
了，於是乎做起租小船給人們的工作。他開的價錢向來公道，雖然手底下的船比較
老舊，但是由於維修得宜，一直沒出過事。當然，你可以直接跟他租船(rent boat
) 。
LONG
);
        set ("gender", "male");
        set ("race", "human");
        set("no_attack",1);
}

void init()
{
  add_action("rent_boat","rent");
}

int rent_boat(string arg)
{
  if (!arg||!(arg=="boat")) return notify_fail("老船東說道：大爺您想租啥？\n");

  if (this_player()->query_temp("mounting"))  
    return notify_fail(@C_LONG
老船東驚道：哎喲，客人您難道想邊騎馬邊划船啊。請不要做弄我一個老人家嘛。
老船東說完就調頭過去不再理你。
C_LONG
      );
  tell_object(this_player(),@C_LONG
老船東喜孜孜地說道：客人您運氣真不錯，從今天開始租船一律免費，呵呵呵。
並指著堤岸邊一艘小船說，吶，您說這艘好嗎？
你在老船東的幫助之下笨拙地爬進小船，接過遞來的船槳，開始嘗試把船劃出船
塢，雖然你大力的撥弄船槳，但是船只是不停的在原地打轉，一時手忙腳亂不知
該如何是好.........
  
C_LONG    
    );
  this_player()->set_temp("block_command",1);
  call_out("continue_rent",5);
  return 1;
}

int continue_rent()
{ 
  object ob1;   
  tell_object(this_player(),@C_LONG      
老船東看了一會兒，笑道：還是我來幫你好了。只見老船東運起一股大力，喝的一
聲，把你從堤岸推到海面上來了。
老船東在你背後大叫著：如果你迷路了，一直往北劃就回的來了呦，不要忘了。
老船東在你背後大叫著：如果你迷路了，一直往北劃就回的來了呦，不要忘了。
老船東在你背後大叫著：如果你迷路了，一直往北劃就回的來了呦，不要忘了。
老船東在你背後大叫著：如果你迷路了，一直往北劃就回的來了呦，不要忘了。
老船東在你背後大叫著：如果你迷路了，一直往北劃就回的來了呦，不要忘了。
老船東在你背後大叫著：如果你迷路了，一直往北劃就回的來了呦，不要忘了。
老船東在你背後大叫著：如果你迷路了，一直往北劃就回的來了呦，不要忘了。
老船東在你背後大叫著：如果你迷路了，一直往北劃就回的來了呦，不要忘了。

C_LONG
    );
  tell_room(environment(this_object()),sprintf(
    "你看到前方%s正好從堤岸劃了一艘船到海面上。\n",this_player()->query("c_name"))
    ,this_player());
  this_player()->move_player(LAKE"l_maze0","SNEAK");
  tell_room(environment(this_player()),sprintf(
    "%s搖著槳，姿勢笨拙地劃了過來。\n",this_player()->query("c_name"))
    ,this_player());
  if (interactive(this_player())) {
    ob1 = new( LITEM"oar" );
    ob1->move(this_player());
  }
  this_player()->delete_temp("block_command");
  return 1;
}
