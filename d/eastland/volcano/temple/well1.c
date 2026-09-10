#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
        set_short( "井中");
	set_long( 
@LONG_DESCRIPTION
你正坐在大桶子裡，井壁上長了一些青苔，從這裡往上看去，天空只剩下一點點，
看來想出去只有叫人幫忙了；往水中看去，似乎有淡淡的亮光在水底下，不知道可不
可以潛下去瞧瞧。
LONG_DESCRIPTION
	);
set("search_desc", ([
    "here":"@@to_search_here" ]) );
reset();
}

string to_search_here()
{
  string str;

  str="\n你在這兒仔細的搜索了一遍，沒有發現任何通路，正不知道如何出去時，\n"
       +"突然想起了很久以前上課學過的摩斯求救密碼\n\n";
  return str;
}

void init()
{
  add_action("do_sos","sos");
  add_action("do_dive","dive");
}

int do_sos()
{
  object ob;

  ob=new(OOBJ"g_chocolate"); /* stupid method to init the room above well*/
  write("你在井壁上敲著摩斯密碼．．．－－－．．．\n");
  ob->move(OGROUP"warea10");
  ob->remove();
  if(present("well guard",find_object(OGROUP"warea10"))) {
     write("守衛探頭看著你：叫你不要自殺你就偏不聽。\n");
     write("守衛說：接住繩子，我拉你上來。\n\n");
     tell_room(this_object(),"你見到"+this_player()->query("c_name")+"被一根繩子慢慢的拉了上去。\n",this_player());
     this_player()->move_player(OGROUP"warea10","SNEAK");
     return 1;
  }

  write("\n天空傳來老貓的聲音：對不起，能幫助你的人已經被Ｋ死了。\n");
  return 1;
}

int do_dive()
{
  if (this_player()->query_skill("swimming")<50) {
    write("你的泳技似乎還不足以讓你潛入水中。\n");
    return 1;
  }
  if (random ( (int)this_player()->query_skill("swimming")) < 50) {
    write("你想以自己的泳技，潛水是不會有啥問題的，於是就跳了下去。\n");
    write("才遊了幾下，就發現好像氣不夠了，只好又回到水面。\n\n");
    tell_room(this_object(),"你見到"+this_player()->query("c_name")+ "跳下水去，不一會兒，氣喘如牛的慢慢爬進木桶子裡。\n",this_player());
    return 1;
  }
  write("你仗著你的泳技精湛，吸了一大口氣之後，就不顧一切的跳入水中。\n");
  tell_room(this_object(),this_player()->query("c_name")+"跳下水去，濺起一大片水花，你的身上到處都是小水珠。\n",this_player());
  this_player()->move_player(OTEMP"well2","SNEAK");
  return 1;
}
