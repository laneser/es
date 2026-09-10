
#include "../../layuter.h"
inherit WEAPON;

void create()
{
        seteuid(getuid());
        set_name( "dragon god drumstick", "龍神鼓槌" );
        add( "id",({ "drumstick"}) );
        set_short( "龍神鼓槌" );
        set_long(
            "這把鼓槌可以擊(beat)鼓(drum)。\n"
        );
        set( "unit", "把");
        set("no_sale",1);
        set( "weapon_class", 23 );
        set( "type", "blunt" );
        set( "min_damage", 10);
        set( "max_damage", 15 );
        set( "weight", 180 );
        set( "value", ({ 50, "gold" }) );
}

void init()
{
  add_action("to_beat","beat");
 }
  
int to_beat(string str)
{  
   object owner,env,mob;
   
   if(!str||str=="") return notify_fail("你要敲什麼??\n");
   if(str!="drum") return 0 ;
    
   owner=environment(this_object());
   if(owner!=this_player()) return 0 ; 
   
   env=environment(this_player());
   if(!(env->query("beat_control")))
         { return notify_fail("這兒沒有合適的鼓可以敲。\n") ; }
   if(this_object()->query("once_beat"))
        { return notify_fail("這根鼓槌已經被敲爛了。\n") ; }

   this_object()->set("once_beat",1) ;
   mob=find_object_or_load(Ldmonster"dragon");   
   
   if(present(mob,env))
        {return notify_fail("鼓聲大作但沒有任何事發生\n"); }
   mob->move(env);
   write("從湖的中央，一隻巨龍緩緩地從湖中升起，它的猙擰型態，令人望而生懼\n");
   this_player()->set_explore("eastland#5");
   return 1; 
}
