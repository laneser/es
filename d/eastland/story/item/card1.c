// By Player@Eastern.Stories 1996

#include <mudlib.h>
#include <body.h>

inherit COINVALUE;
inherit OBJECT;

string book_color();

void create()
{       
	set_name("balance_amulet","進財符" );
        add("id",({"amulet"}));
	set_short("進財符");
	set_long(@LONG
一張大紅色的符咒，上面印著泥金四個大字『招財進寶』。你可以嘗試去使用這張
符咒，不知道會有什麼事情發生。(use balance_amulet)。
LONG);
	set("unit","張");
}

void init()
{
        add_action("do_balance","use");
}

int fil_ppl(object obj)
{ 
  object me;
  if (wizardp(obj)) return 0;
  if (userp(obj)&& obj->query_level()>8) return 1;
  return 0;
}

void second_msg(object me,object ob)
{
  int i,j,total=0;
  string *types;
  object *here;
  mapping money;
  if ( !interactive(me)) {
    ob->remove();
  }
  tell_room(environment(me),sprintf("%s%s%s%s%s%s",
    set_color("\n一陣狂風把所有人身上的錢幣都捲到天上....\n","HIB"),
    set_color("白金幣    ","HIW"),set_color("金幣    ","HIY"),
    set_color("銀幣    ","CYAN"),set_color("銅幣    ","YEL"),
    set_color("滿天飛舞，然後就全部消失不見了...........\n\n","HIB"))
    );
  here = filter_array(all_inventory(environment(me)),"fil_ppl",this_object());
  for(i=0;i<sizeof(here);i++) {
    money = here[i]->query("wealth");
    if( !money ) money = ([]);
    types = keys(money);
    for( j=0; j<sizeof(types); j++ )
      total += money[types[j]] * coinvalue( types[j] );
  }
  total = (total / (sizeof(here)))/10;
  for(i=0;i<sizeof(here);i++) {
    here[i]->delete("wealth");
    here[i]->set("wealth/silver",total);
  }  
  me->delete_temp("block_command");
  ob->remove();
}

int do_balance(string arg)
{
  object ob;
  
  if (!arg||arg!="balance_amulet")
    return 0;
  if (!(ob=present(arg,this_player())))
    return 0;
  if (this_player()->query_level() < 9 ) {
    tell_object(this_player(),"你因為能力不足而無法使用這樣物品。\n");
    return 1;
  }
    
  tell_object(this_player(),set_color(
    "\n你輕輕地把符咒撕了開來，只見五彩祥雲簇擁，天放異光罩住這裡的每一個人..\n\n","HIY")
    );
      
  tell_room(environment(this_player()),set_color(sprintf(
    "\n%s你輕輕地把符咒撕了開來，只見五彩祥雲簇擁，天放異光罩住這裡的每一個人..\n\n",
    this_player()->query("c_name")),"HIY"),this_player());
  this_player()->set_temp("block_command",1);     
  call_out("second_msg",3,this_player(),ob);
  return 1;
}

