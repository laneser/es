#include <mudlib.h>

inherit MONSTER;

void create()
{
   object weapon;

        ::create();
        set_level(13);
        set_name( "beggar", "流浪的乞丐" );
        add( "id", ({ "beggar" }) );
        set_short( "流浪的乞丐" );
        set_long(
         "他是一位雙目失明, 衣衫襤褸的老人, 從他緊鎖的眉宇, \n"
         "你可以斷定, 他一定經受過巨大的磨難!\n"
        );
        seteuid(getuid());
        set( "alignment", 0 );
        set_perm_stat("str",30);
        set_perm_stat("dex",30);
        set_skill("parry", 100);
        set_skill( "dodge", 60 );

        set( "race", "human" );
        set( "gender", "male" );
        set_natural_armor( 50, 30 );
        set( "pursuing", 1 );
        set( "moving", 1 );
        set( "speed", 30 );
        set( "exp_reward",100);
        set( "patrol", ({ "east", "east", "west", "west", 
                          "west", "west", "east", "east" } ));
        set("chat_output",({"乞丐哀求道: 哪位大爺施捨點錢給我啊...\n"}));
        set( "chat_chance", 40 );
//        wield_weapon( "/d/moorth/obj/shortsword" );

        set( "inquiry", ([
            "story" : "@@ask_story",
//            "reward" : "@@ask_reward",
//            "inform" : "@@ask_inform",
//            "army" : "我們的大軍正準備進攻諾達尼亞城, 要命快閃吧!\n" 
          ]) );
}

void init()
{
       npc::init();
       add_action("do_give","give");
}

int do_give(string str)
{
     string s1,s2,s3,my_name;
     int num;
     object me;
     if(!str) return 0;
     if( sscanf(str,"%d %s %s %s",num,s2,s3,s1)<4 )
        return 0;
     if(query("name")!=s1 || s3!="to") 
        return 0;     
     if( s2!="gold" && s2!="silver" && s2!="copper") 
        return 0;

     me=this_player();
     my_name=lower_case(me->query("name"));
     
     if(num<=0 )
     {
         command("slap "+my_name);
         command("grin "+my_name);
         command("say 別以為我是瞎子就想蒙我, 沒門.....");
         command("spit "+my_name);
         return 1;
      }
     if(!me->debit(s2,num))
        return notify_fail("你沒那麼多錢  \n");     
     if(s2!="gold")
     {
         command("say 謝謝了， 不過還是金燦燦的好看..");
         return 1;
     }
     if(num<50)
     {
          command("say 謝謝了!");
          return 1;
     }
       command("say 你可真是個好心人啊...");
       command("sigh "+my_name);
       tell_object(me,"老乞丐繼續說道: 要不是經歷了那些事(story), \n"
                      +"我也不會淪落到這種地步! \n");
       command("say 命苦啊...");
       command("cry "+my_name);
       me->set_temp("paid",num);
       return 1;
}

int ask_story(object who)
{
   if( (int)who->query_level()<5 ) {
     command("sigh "+who->query("name"));
     write( "然後說: 你還小, 幫不了我忙的!\n" );
     return 1;
   } else {
   tell_object( who, @LONG
    既然你這麼好心, 我就告訴你吧...
    當年我是古梅鎮有名的大財主, 好結交江湖上各方義士,
    江湖上人稱柴大官人, 許多英雄豪傑都慕名投奔我
    xixixi 程序還沒編好, .. :D
LONG
     );
     return 1;
   }
   return 1;
}

int accept_item(object who,object item)
{  
/*  
       command("say 你可真是個好心人啊...");
       command("sigh "+who->query("name"));
       tell_object(who,"老乞丐繼續說道: 要不是經歷了那些事(story), \n"
                      +"我也不會淪落到這種地步! \n");
       command("say 命苦啊...");
       command("cry "+who->query("name"));
       return 0;
  */  
}

void die()
{  
   object ob1,killer;
   
   killer = query("last_attacker");
   if( !killer ) {
     ::die();
     return;
   }
   if(!present(killer->query("name")) )
   {
      ::die();
      return;
   }
   if(killer->query_temp("paid")>=50)
   {
     tell_object( killer,
      "\n你趁周圍人不注意偷偷從屍體裡拿出酒袋!\n");

     ob1=new("/obj/wineskin");
     ob1->move(killer);
     killer->set_temp("paid",0);
   }
   ::die();   
}
