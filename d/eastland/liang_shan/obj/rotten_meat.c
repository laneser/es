#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit OBJECT;

void init()
{
	add_action( "smell_food", "smell" );
        add_action( "hook_hook", "tie");
}

void create()
{
	set_name("meat","臭魚爛蝦的肉");
	add( "id" , ({ "meat","fish" }) );
   set_short("臭魚爛蝦的肉");
   set_long( "　　這些肉原來是些什麼已經沒人知道了，但從它們的來源來看大概\n"
             "是一些魚蝦之類，雖然它們不時發出刺鼻的臭味，你還是忍不住地把\n"
             "它放在鼻子前聞一聞(smell)。\n" );
   	set("unit","塊");
   	set("weight", 5);
}

int smell_food(string arg)
{
object holder;	

       if( !(holder = environment(this_object())) || !living(holder) ) return 0;
       
       if( !arg || arg != "meat" ) return 0;
       write("\n啊，真是臭啊.....\n");
       (CONDITION_PREFIX + "weak")->apply_effect(holder,4,4);
	return 1;
}

 int hook_hook(string arg,object me)
 {
 int i,n;
 object ob;
 
 if (!arg || arg != "hook" )
 return notify_fail(
 "想穿這些爛肉在什麼上?\n" );
 if (!(int)this_player()->query_temp("can_fish")==1 )  {
 write(
 "\n你把臭魚爛蝦的肉穿在釣鉤上...\n");
 this_player()->set_temp("can_fish",1);
 remove();
 return 1;
}
 else 
 write(
 "\n釣鉤上已經穿好了釣餌.....\n");
 return 1;
}