#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name( "mar_short book", "楚辭劍法" );
	set_short( "楚辭劍法" );
	set("long",@LONG
楚辭劍法的劍譜。你能讀懂它(read mar_short book)嗎?
LONG);
	set( "unit", "本" );
	set( "weight", 1 );
	set( "no_sale", 1 );
        set( "prevent_drop",1);
        set( "prevent_insert",1);  
}

void init()
{
        add_action( "do_read","read");
        add_action( "do_learn", "learn" );
}

int do_read(string arg)
{
  if( !arg || arg!="mar_short book" )
    return 0;
  tell_object(this_player(),@LONG
你翻開劍譜的第一張，上面寫道
『楚辭劍法是一種短刃型劍法，強調近身搏鬥時的技巧，所以當你的對手所使用的武
器攻擊距離越短的，你所能發揮劍法的威力也越大。............................
................................................................』
再繼續翻下去就是一些舞劍的圖形了，你想，或許你能嘗試去學習(learn mar_short
 book)這套劍法。  
LONG);
  return 1;
}

void learn_book(object me,object obj)
{
  tell_object(me,     
 "經過一番苦練，你終於學會楚辭劍法。\n你可以用<enhant mar_short>來施展劍法。\n");
  this_player()->set("scholar_gonfu/mar_short",1);
  obj->remove();
  return;
}

int do_learn(string arg)
{
   object me;
   me=this_player();
   if( !arg || arg!="mar_short book" )
     return 0;
   if (!(me->query("class")=="scholar"))
     return notify_fail("你拿起秘笈仔細端詳一番，心想還是放棄好了。\n");
   if ((me->query_skill("palaeography")< 75))
     return notify_fail("你看了半天，連一個字都看不懂。\n");
   if ((me->query_perm_stat("int")< 24))
     return notify_fail("你看了半天，好像有點懂了，但卻沒有辦法理解劍法的精髓。\n");
   if (me->query("scholar_gonfu/mar_short"))
     return notify_fail("你早就瞭解楚辭劍法的精義了。\n");
   tell_object(me,
     "你仔細研讀了一番，突然心領神會，對空比劃了起來......\n..............\n\n");
   call_out("learn_book",5,me,this_object());  
   return 1;
}
