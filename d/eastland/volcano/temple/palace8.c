#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

int be_get;
void create()
{
	::create();
	set_short( "龍宮花園" );
	set_long(
@LONG
這裡是龍宮花園，放眼望去，可謂天下奇花異草集於此地，一年四季皆滿園
花簇，玫瑰、紫羅蘭、風信子、鳶尾、水仙、鬱金香．．．．．．．．．．
一片萬紫千紅，平時龍王父女兩人最喜愛相偕來此談天。
LONG
	);
	set( "exits", ([
	     "west" : OTEMP"palace5",
	]) );
        set("search_desc", ([
            "here":"@@to_search_here",
            ]) );
         set("item_desc",([
             "rose":"@@look_rose",
             ]) );
         set("light",1);
         reset(); 
}

string to_search_here()
{
   string str;

   str="你在茫茫花海之中，發現一朵藍玫瑰(rose)。\n";
   this_player()->set_temp("rose/check",1);
   return str;
}

string look_rose()
{
  if (this_player()->query_temp("rose/check"))
    return "一朵閃著藍色光芒的玫瑰花。\n";
  return 0;
}

void init()
{
  add_action("do_get","get");
}

int do_get(string arg)
{
  object ob;

  if (!arg || arg!="rose" || !this_player()->query_temp("rose/check") )  {
//    write("你要拿啥?\n");
//    return 1;
      return 0;
  }
  
  if (!this_player()->query_quest_level("Dragon_box")) {
    write("你伸手去摘這朵玫瑰花，卻撈個空，原來你看到的只是幻影。\n");
    return 1;
  }

  if (present("rose",this_player())) {
    write("你為什麼不讓其他人也能觀賞這朵難得一見的藍玫瑰呢?\n");
    return 1;
  }

  if (be_get) {
    write("這朵玫瑰已經被人摘走了。\n");
    return 1;
  }

  write ("你輕輕的把這朵藍色玫瑰花摘了下來。\n");
  ob=new(OOBJ"rose");
  ob->set(this_player()->query("name"),1);
  ob->move(this_player());
  be_get=1;
  return 1;
}

void reset()
{
  ::reset();
  be_get=0;
}
