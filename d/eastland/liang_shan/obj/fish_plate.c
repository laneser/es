#include "takeda.h"

inherit ROOM;

void create()
{
	object me;
	me = this_player();
	::create();
	set_short( "釣魚平臺" );
	set_long(
	"　　這是一個小小的平臺，原來似乎是設計用來停泊船隻的，不過，因為\n"
	"石碣村的人們越來越不常出去打魚了，這裡反而變成釣魚的人大顯身手的\n"
	"好地方。你如果有帶釣竿來的話，或許可以在此試試手氣。\n");
	set( "light",1 );
        set_outside("eastland");
        set( "exits", ([
        "south" : TROOM"village2"]));
                        
        set( "objects" ,([
        "fisher" : TMONSTER"fisher"]));
        reset();
}
void init()
{
   add_action("do_fish","fish");
   add_action("do_pull","pull");
}
int do_fish()
{
   if ( !(int)this_player()->query_temp("can_fish")==1)  { 
   write(
   "\n你是姜太公嗎??\n");  
    return 1; 
    }
   if ( present("fish rod",this_player()) )
     {
      write(
      "\n你把釣具準備好，找了個舒服的位子坐下，開始快樂的釣魚...\n\n");
     
      tell_room(this_object(),
      "你看到"+this_player()->query( "c_name")+"準備好釣竿，開始快樂的釣魚。\n",this_player());
   if (present("fisher")) 
     {
      write(
      "\n旁邊的釣魚人把頭伸了過來，說道: 您也是來釣魚的吧，釣魚需要很大的\n"
      "耐心，不然是不可能釣的到魚的。\n\n");
     
     
      this_player()->set_temp("fish_quest/fish",1);
      call_out("recover",30,this_player());
     return 1;
     }
  else 
      this_player()->set_temp("fish_quest/fish",1);
      call_out("recover",50,this_player());
     return 1;
    }
  else  {
    write(
    "你想用什麼東西釣魚呢?\n");
    return 1;    
        }
}
int recover(object me)
  { 
   if (!present(me)) return 1;
   write(
   "\n正當你覺的有點無聊的時候，你的浮標突然一沉，你看到釣竿的竿先\n"
   "彎成美麗的弧型，接著一陣強烈的掙扎力順著你的釣竿傳來，你趕快\n"
   "起身，不知該不該將釣竿拉起來看看?\n\n");
   tell_room(me,
      "\n正當你覺得無聊的時候，你看到"+this_player()->query( "c_name")+"突然起身，\n"
      "\n好像是中魚了!\n\n"
      ,this_player());
               
   this_player()->set_temp("fish_quest/fish",2);
   return 1;
   }   
 int do_pull(string arg,object me)
 {
 int i,n;
 object ob;
 
 if (!arg || arg != "rod" )
 return notify_fail(
 "想拉什麼?\n" );
 if ((int)this_player()->query_temp("fish_quest/fish")==2 )  {
 if ( !(int)this_player()->query_temp("can_fish")==1) {
 write("先裝餌吧...\n");
 return 1;
 }
 if (random(6)>4) {
 write(
 "\n你大力一拉釣竿: 但是什麼都沒有拉起來\n\n");
 tell_room(me,
 "\n"+this_player()->query("c_name")+"大力一拉釣竿，但是什麼都沒釣到..\n\n"
 ,this_player());
 return 1;
 }
    switch (n=random(10) ){
    case 0: ob = new(TMONSTER"fish1"); break; 
    case 1: ob = new(TMONSTER"fish2"); break;
    case 2: ob = new(TMONSTER"fish3"); break;
    case 3: ob = new(TMONSTER"fish4"); break;
    case 4: ob = new(TMONSTER"fish5"); break;
    case 5: ob = new(TMONSTER"fish6"); break;
    case 6: ob = new(TMONSTER"fish7"); break;
    case 7: ob = new(TMONSTER"fish8"); break;
    case 8: ob = new(TMONSTER"fish9"); break;
    case 9: ob = new(TMONSTER"fish10"); break;            
                }
 ob->move( environment(this_player()) );
         
 write(
  "\n你大力一拉釣竿: 一條大魚順勢飛到岸上，你感到一陣中魚的滿足，但是\n"
  "魚仍然不停的掙扎....\n");
   tell_room(me,
   "\n"+this_player()->query("c_name")+"大力一拉釣竿，結果釣到一條大魚。\n\n"
   ,this_player());
   ob->kill_ob(this_player());
   this_player()->kill_ob(ob);
   this_player()->delete_temp("can_fish");
   return 1;
 }
 write(
 "\n耐心點，再等等吧。\n");
 return 1;
}