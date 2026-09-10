#include "../healer.h"

inherit MONSTER;

void create()
{
    ::create();
    set_level(1);
    set_name( "dog", "物之郎" );
    set_short( "物之郎");
    set("no_attack",1);
    set_long(@C_LONG
一隻長毛的大白狗。長耳朵搭拉著，一看到好吃的就會撲上去。
響子為了紀念她的先生所以起了這個名字。
C_LONG
            );
    set("unit","位");
    set("age",18);
    set("gender","man" );
    set("no_attack",1);
    set("weight",3100);
    set( "moving", 1 );
    set( "speed", 30 );
    set( "patrol", ({ "east","west",
                      "east","west" } ));
    set("chat_chance",5);
    set("chat_output",({
         "物之郎對你『汪汪汪』地吠著。\n",
         "物之郎鑽進自己的狗屋裡『呼呼』地睡著了。\n",
         "物之郎衝著你手上好吃的『汪汪汪』地吠著。\n"
    }) );
}        
int accept_item(object me, object item)
{
      string name;
      
      name=item->query("name");
      if (this_object()->query_temp("feed")){
          item->remove();
          tell_object(me,this_object()->query("c_name")+
                "把你給它的東西給埋在地下～～\n");
          return 0;
      }
      if (name!="white bone") {
          item->remove();
          tell_object(me,this_object()->query("c_name")+
                "把你給它的東西吃下去～～\n");
          return 0;
      }
      item->remove();
      this_object()->set_temp("feed",1);
      tell_room(environment(this_object()),this_object()->query("c_name")+
          "一溜煙地叼著你給它的東西跑回自己的狗屋裡了～～\n");  
      set_long(@C_LONG
物之郎。它正在吃著東西。
C_LONG
            );
      return 1;
}
