#include <mudlib.h>

inherit CONTAINER;

void create()
{
        
        seteuid(getuid());
        set_name( "rope", "繩子" );
        set_short( "繩子" );
   set_long( "一根長繩子。\n" );
        set( "weight", 18 );
        set( "value", ({ 1, "silver" }) );
}

void init()
{
  add_action("to_throw","throw");
 }
  
int to_throw(string str)
{
  object ob1,ob2;
  int test;
   if (str!="rope")  return 0;      
   else if (str=="rope"){
     ob1=environment(this_object());
     if (ob1==this_player()){ 
       ob2=environment(ob1);
       test=ob2->query("layuter_hole");
       if (test==1){
       tell_room(this_object(),this_player()->query("c_name")+"丟出一條繩子，跟著進入了洞中。\n",this_player());
       write("你把繩子丟出勾住洞外大石，然後沿著繩子爬入洞內，你順手將繩子收起來。\n");
       this_player()->move_player("/d/eastland/haiwei/hole1","SNEAK");
       return 1;
        } 
      else write("你將繩子拋上拋下的玩著。\n");            
      }
    return notify_fail("你身上並沒有繩子！\n");
  } 
 }
