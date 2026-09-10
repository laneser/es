#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("red gourd","大紅葫蘆");
        add("id",({"gourd"}));
        set_short( "@@query_short");
        set_long("@@query_long");
        set("unit","個");
        set("weight",10);
        set("no_sale",1);
        set("value", ({100, "silver"}) );
}
string query_short()
{
   return sprintf("大紅葫蘆%s", (query("heaven_water") ? " (裝著天堂之水)" : "") );
}
string query_long()
{
   return sprintf("一個紅色的大葫蘆，%s", (query("heaven_water") ? "可以把裡面的溶液倒出來(full)。\n":"可以用來當容器(fill)用。\n"));
}
void init()
{
   add_action("do_full","full");
   add_action("do_fill","fill");
}
int do_full(string arg)
{
   object player,flute;
   if ( !query("heaven_water") ) 
      return notify_fail("葫蘆裡沒有任何溶液。\n");
   if ( !arg ) return notify_fail("Syntax:<full items>。\n");
   player=this_player();
   if ( !(flute=present(arg,player)) )
      return notify_fail("你沒有那樣東西。\n");
   if ( flute->query("name") != "fly flute" )
      return notify_fail("你不能把葫蘆裡的「天堂之水」倒進那裡面去！\n");
   if ( flute->query("left_times") )
      return notify_fail("那東西裡面已經充滿著「天堂之水」了。\n");
   write("你緩緩地把葫蘆裡的「天堂之水」倒進「飛翔之笛」內。\n");
   flute->set("flute_left",1);
   remove();        
   return 1;
}
int do_fill(string arg)
{
   object env;
   if( !arg || arg!="gourd" )
      return notify_fail("Syntax:<fill gourd>。\n");
   if( query("heaven_water") )
      return notify_fail("葫蘆內已經裝滿溶液了。\n");
   env=environment(this_object());
   if( living(env) ) env = environment(env);
   if( !env->query("heaven_water") )
      return notify_fail("這個葫蘆不是用來裝這裡的任何溶液！\n");
   set("heaven_water",1);
   write("\n\n忽然從葫蘆口產生一股力量把這裡的氣體吸進去，瞬間，氣體變成了聖水－「天堂之水」。\n\n\n");
   return 1;    
}