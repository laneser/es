#include "../tsunami.h"
#include "/include/move.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(10);
    set_name( "luoky", "魎皇鬼" );
    add( "id",({"luoky"}) );
    set_short( "魎皇鬼" );
    set_long(@LONG
這是一隻長相像兔子，叫聲卻像貓的小動物，很可愛吧！它可是砂紗美公主的
寵物呢！你千萬不要欺負它哦！否則你會遭天譴的哦！如果你餵它蘿蔔(radish)
的話，它就會和你親近哦！
LONG
            );
    set("aligment",1000);
    set_c_verbs( ({"%s用它鋒利的牙齒咬向%s","%s強而有力的後腿踢向%s",
                   "%s用它大大的耳朵甩向%s"}) );
    set_perm_stat( "str", 10);
    set_perm_stat( "dex", 10);
    set_perm_stat( "int", 15);
    set( "chat_chance",5);
    set( "chat_output", ({
  "魎皇鬼用鼻子邊聞邊叫著: 喵～～喵，我要蘿蔔，喵～～喵～～喵～～\n"
       }));
    set("hit_points",200);
    set("max_hp",200);
    set_natural_weapon( 30, 15, 30 );
    set_natural_armor(35,10);
    set("c_death_msg","由於你最後一下補得太猛了，%s的鮮血噴得你滿臉都是！\n");
}

int accept_item(object player,object obj)
{ 
   object *item, ob1, ob2;
   int i;
   ob1 = ( present("luoky")); 
   ob2 = new(TOBJ"crystal");
   
   if(!obj || !(obj->query("give_me_radish")) ) {
   tell_room(environment(),
   "魎皇鬼掛著兩行湯匙般大的淚珠哭道：喵～～喵～～喵，蘿蔔蘿蔔啦！\n");
   return 1;
   }
   
   if( (string)obj->query("owner") != (string)player->query("name") ){
   tell_object(player,"魎皇鬼哭道：嗚喵，你沒有誠意喵，居然給我一隻不新鮮的蘿蔔，喵～喵！\n");
   obj->remove();
   return 1;
   }
   
   tell_room(environment(),
     "魎皇鬼很愉快的咬著蘿蔔，變成一棵水晶，圍繞著"+player->query("c_name")+
     "飛舞........\n");
   tell_object(player,"魎皇鬼對你說：請你帶我回我的主人那兒去!!\n");
   ob2->set("winner",(string)player->query("name"));
   ob2->move(player);
   item = all_inventory(ob1);
   for( i=0; i<sizeof(item); i++ ) item[i]->remove();
   ob1->remove();
   return 1;
} 

void die()
{
   object killer;
   killer = query( "last_attacker" );
   
   if( !killer ){
   ::die();
   return;
   }
   killer->set_temp("luoky_killer",1);
   ::die();
}   
            
