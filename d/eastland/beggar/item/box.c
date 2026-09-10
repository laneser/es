#include <mudlib.h>
#include <conditions.h>

#define COND_NAME "herb_apply"

inherit OBJECT;
inherit DAEMON;
void create()
{
	set_name("box", "小盒子");
	set_short("小盒子");
	set_long(@C_LONG
這是一隻晶瑩潤滑的白玉盒子,裡面裝著一些藥膏。你可以使用它( use )或檢查
( checkup )它。
C_LONG
	);
	set( "weight", 1);
        set( "times",  10);
        set( "charge_times", 3);
        set( "duration", 30 );
        set( "heal_apply", 7);
	set( "value", ({ 1500, "silver" }));
}       
void init()
{
   add_action("do_use","use");
   add_action("do_checkup","checkup");
} 
int do_use(string arg)
{
   object me,boxes;
   string class1,my_name;
   int heal,duration,frequency,times;
   
   if ( !arg ) return 
      notify_fail("你要 use 什麼東西。\n");
   if (!boxes=present(arg,this_player()))
      return notify_fail("你沒有那樣東西。\n");
   if (boxes->query("name")!="box")
      return notify_fail("Syntax <use box>\n");
   times=boxes->query("times");
   me=this_player();
   if (times<1)
      return notify_fail("～嗚,用完了啦～～\n");
   if ( me->query_attacker() )
      return notify_fail("戰鬥中不能敷藥!!\n");
   if ( (int)me->query("hit_points")>=(int)me->query("max_hp") )
      return notify_fail("沒受傷敷個什麼勁??\n");
   if( (int)me->query_temp("bandaged") ) 
      return notify_fail("你已經被包紮了,請先 remove bandage !!\n");
   my_name=me->query("c_name");
   class1=me->query("class");
   switch (class1) {
   case "healer":
   
   case "mage":
   case "scholar":
      times-=1;
      tell_object(me,
         "你熟練地從懷中取出一隻小盒,打開盒子,伸指沾些藥膏塗在傷口處!\n");
      tell_room(environment(me),my_name+
         "熟練地從懷中取出一隻小盒,打開盒子,伸指沾些藥膏塗在傷口處!\n",me);
      break;
   default:
      times-=2;                       
      tell_object(me,
         "你手快眼明地從懷中取出一隻小盒,打開它伸指沾些藥膏塗在傷口處!\n");
      tell_room(environment(me),my_name+
         "手快眼明地從懷中取出一隻小盒,打開它伸指沾些藥膏塗在傷口處!\n",me);
      break;
   }
   boxes->set("times",times);
   frequency = (int)boxes->query("heal_frequency");
   if( frequency < 1 ) frequency = 10;
   heal = (int)boxes->query("heal_apply");
   if( undefinedp(heal) ) heal = 1;
   duration = (int)query("duration");
   if( duration < 1 ) duration = 1;
   me->set("conditions/" + COND_NAME, ({ frequency,heal,duration}));
   return 1;
}
int do_checkup(string arg)
{
   int left_times;
   object boxes;
   if( !arg )
      return notify_fail("你要 checkup 什麼東西?\n");
   if( !(boxes=present( arg, this_player() )) )
      return notify_fail("你沒有這樣東西。\n");
   if (boxes->query("name")!="box")
      return notify_fail("Syntax <checkup box>\n");
   left_times=boxes->query("times");
   if (left_times<1)
      return notify_fail("唉,被塗完了啦!只有空空的一個盒子～\n");   
   if (left_times>8)
      return notify_fail("哈,小盒子還裝著滿滿的藥膏～～\n");
   else if (left_times>3)
      return notify_fail("嗯,小盒子還留下不少的藥膏～～\n");
   else return notify_fail("嗚,小盒子裡的藥膏已經快被用完了啦～～\n");   
}
