#include "../legend.h"
#include <mudlib.h>

inherit OBJECT;

void create()
{
     seteuid(getuid());
     set_name("Sea Ball", "定海珠");
     add("id", ({ "sea ball","ball" }) );
     set_short("定海珠");
     set_long(@C_LONG
一顆靛藍色的珠子,隱隱約約傳來海的訊息。
C_LONG
     );                             
     set( "unit", "顆" );
     set( "no_sale",1);
}
void init()
{
   add_action("do_roll","roll");
}
int do_roll(string arg)
{
    object holder,env;
    if ( !arg || arg!="sea-ball" ) 
       return 0;
    holder=environment(this_object());
    if ( !living(holder) ) 
       return 0;    
    env=environment(holder);
    if ( !env->query("can_use_sea_ball") )
       return 0;
    if ( env->query("exits/tunnel") ) {
       tell_object(holder,"這裡己經有一條通道 ( tunnel ) 了!\n");       
       return 1;
    }
    if ( present("water beast",env) ) 
      return 0;
    holder->set_temp("block_command",1);
    tell_object(holder,set_color(
        "\n\n       你口中喃喃自語地用手摩擦著定海珠..\n\n\n",
        "HIC"));
    tell_room(env,set_color(sprintf(
        "\n\n       %s口中喃喃自語地用手摩擦著定海珠..\n\n\n",holder->query("c_name")),
        "HIC"),holder);   
    call_out("recover1",2,holder,env);       
    return 1;
}
void recover1(object holder,object env)
{
    tell_room(env,set_color(
       "\n\n       忽然間！！湖面波浪□天、雷電交加，甚是險惡....\n\n"
       "       你心裡閃過不好的預感！！\n\n"
       ,"HIC"));
    call_out("recover2",6,holder,env);
}    
void recover2(object holder,object env)
{
    object beast; 
    holder->delete_temp("block_command");
    tell_room(env,set_color( 
       "\n\n       轟！一道閃電垂直轟向湖面！！\n\n" 
       "       在閃電過後，湖面隱隱約約地出現一條甬道 ( water-tunnel ) ！！\n\n\n"
       ,"HIC"));
    if ( !beast=present("water beast",env) ) {
       beast=new(LMONSTER"water_mob");
       beast->move(env);  
    }
    env->add("exits/tunnel",LAKE"lake1");
    env->add("c_item_desc/water-tunnel","一條水道 ( tunnel ),兩旁都是丈高的水牆。\n");
    env->set( "exit_suppress", ({
                   "tunnel"}) );
    this_object()->remove();
}
