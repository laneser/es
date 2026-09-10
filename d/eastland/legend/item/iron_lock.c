#include <mudlib.h>

inherit OBJECT;

void create()
{
     set_name("iron lock", "大鐵索");
     add("id", ({ "lock"}) );
     set_short("大鐵索");
     set_long(@C_LONG
一件沈重的鐵鎖。
C_LONG
     );                             
     set( "unit", "件" );
     set( "no_sale",1);
}
void init()
{
   add_action("do_lock","iron_lock");
}
int do_lock(string arg)
{
    object holder,env,victim;
   
    holder=environment(this_object());
    if ( !living(holder) ) 
       return 0;    
    env=environment(holder);
    if ( !victim=present("beast",env) ) {
       tell_object(holder,"對不起,請不要亂來。\n");
       return 1;
    }
    if ( !victim->query("npc") ) {
       tell_object(holder,"咩,他跟你有仇嗎?\n");
       return 1;
    }
    if ( !victim->query("faint") ) {
       tell_object(holder,"嗚,它清醒著～～\n");
       return 1;
    }
    if ( victim->query("locked") ) {
       tell_object(holder,"可憐的它已經被鎖上了!\n");
    }
    tell_object(holder, sprintf("你用大鐵索鎖在%s的頸脖上,鼻孔裡又給穿上了金鈴!\n",
       victim->query("c_name")) );
    tell_room(env,sprintf(
       "%s用大鐵索鎖在%s的頸脖上,鼻孔裡又給穿上了金鈴!\n",holder->query("c_name"),victim->query("c_name")),holder);
    victim->set("locked",1);
    this_object()->remove();               
    return 1;
}