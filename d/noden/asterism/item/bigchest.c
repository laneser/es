#include "../asterism.h"

inherit OBJECT ;

void create()
{     

        set_name( "bigchest" , "大箱子" ) ;
        add( "id" , ({ "bigchest","chest" })) ;
        set( "unit","個" ) ;
        set_short("一個大箱子") ;
        set_long(
         @C_TEXT
一個兩立方公尺左右的大箱子,看來有點詭異。該打開它嗎 ? 
還是該先做安全檢查動作 ??
C_TEXT
         );
         
        set("weight", 300 );
        set("prevent_get",1 ) ;
        seteuid(getuid())     ;        
}

void init()
{
     add_action("exam_chest","exam");
     add_action("exam_chest","check");
     add_action("do_hurt","open");
     add_action("do_hurt","search");
     }
     
int exam_chest(string str)
{     
     object mob ;
          
     if (!str || str !="chest") 
         {         
               return notify_fail( "檢查什麼 ?\n" );
         }
     else
      {   
          tell_room(environment(),
           "這個箱子在你靠近時,突然張開血盆大口,嚇了你一大跳。\n"
            ,this_player() )  ;
          mob = new(MOB"mimic") ;         
          mob->move(environment(this_object())) ;         
          remove() ;
          return 1 ;     
        }            
}              
     
int do_hurt(string str)     
{ 
       object mob ;
       int hp  ;      

       if (!str || str !="chest") 
          {         
           return notify_fail(
                           "你想做什麼 ?\n" );
          }
  
       hp = this_player()->query("hit_points") ;
       
       if (hp <101 )
          {
            this_player()->set("hit_points",1) ;
           }
        else
          { 
            this_player()->set("hit_points",hp-99) ;
           } 
       write(
             "這個箱子突然張開血盆大口往你身上一口咬下。哇～～好痛。\n"  );
       tell_room(environment(),"這口箱子突然張口向"+this_player()->query("c_cap_name")+
                 "一口咬下。\n",this_player() ) ;
          
          mob = new (MOB"mimic") ;
          mob->move(environment(this_object())) ;         
          this_player()->set_explore("noden#34");
          remove() ;
          return 1 ; 
 }
   
