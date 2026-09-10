// /u/m/mad/bravar.c

#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
   set_level(12);
   set_name("Bravar","布瑞伐爾");
   add("id", ({ "man" }));
   set_short("布瑞伐爾");
	set_long(
          "布瑞伐爾先生本來是諾達尼亞的軍醫, 聽說這屋子死了\n"
          "不少人, 而來此地調查。為何他竟會被困於這個地窖?\n"
	);
   set("race","human");
   set("gender","male");
   set("alignment",700);
   set("unit","位");
   set_perm_stat("dex",16);
   set_perm_stat("int",16);
   set_perm_stat("pie",16);
   set_natural_armor(25,10);
   set_natural_weapon(10,6,11);
   set_skill( "blunt", 50 );
   set_skill( "dodge", 60 );
   set_skill( "anatomlogy", 70 );
   set_temp( "aiming_loc", "ganglion" );
   set("chat_chance",10);
   set("chat_output", ({
           "布瑞伐爾無力地呻吟著: 食.....食......\n"
           "   (他的聲音太小以致於你聽不清楚...)\n"
     }) );
   wield_weapon("/d/noden/house/obj/mace");
}

int accept_item(object me,object item)
{
  string name;
  object ob;

  name=(string)item->query("name");
   if( !name || name != "cookie" ) {
    return 0;
  }

   item->remove();
   ob = new( "/d/noden/house/obj/incantation" );
   ob->move(me);
   this_player()->set_explore("noden#26");
   tell_object( me,
     "布瑞伐爾說: 謝謝...我很久沒吃東西了! 這張驅邪符算是回報吧!\n" );
   return 1;
}
