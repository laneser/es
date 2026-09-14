#include "../oldcat.h" 

inherit OBJECT;

object place;
void create()
{
	set_name( "manlike fruit", "人參果" );
	set_short( "人參果" );
	set_long(
	  "這是個可以延年益壽、千年一結的人參果。\n"
	);
        add("id",({"fruit"}) );
        set( "unit", "個");
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
  add_action("do_eat","eat");
}

int do_eat(string arg)
{
   int align;

   if(!arg || arg!="fruit")
   { write("你要吃什麼？\n");
     return 1;
   };
   this_object()->set("prevent_drop",1); 
   write("你吃了這顆人參果之後，突然你覺得身體好像有什麼變化．．．．．\n");
   this_player()->set_temp("block_command",1);
   write("\n\n\n\n\n\n\n");
   call_out("idle_time1",2,this_player());
   call_out("idle_time2",5,this_player());
   call_out("end",25,this_object(),this_player());

   return 1;
}

int idle_time1(object who)
{
    tell_object(who, "你覺得你的身子一輕，慢慢的飄了起來，你不禁暗暗偷笑，好不容易在ＥＳ中混那麼久，終於成仙了。\n");
    tell_room(environment(this_player()),"\n你見到 "+this_player()->query("c_name")+" 慢慢的飄了起來，往天空中飛上去。\n\n",this_player());
    tell_object(who,"\n\n\n\n\n\n\n");
    return 1;
}

int idle_time2(object who)
{
    tell_object(who, "你發覺自己仍不斷的升高，離地面越來越遠，終於看不見了，你整個身體懸在半空中，不知到會飄到何處。\n");
    tell_room(place=environment(who),"\n"+who->query("c_name")+"越飛越高、越飛越快，終於縮成一點，消失在空中了。\n\n",who);
    who->set_temp("block_command",0);
    who->move_player(OTEMP"void","SNEAK");
    return 1;
}

void end(object ob1,object who)
{
  tell_object(who,"\n空中傳來巫師老貓的聲音：對不起、你修煉還不夠，等你功德圓滿時，\n自然有人會來帶你成仙。\n\n");
  tell_room(place,"\n你見到"+who->query("c_name")+"從空中慢慢的飄了下來。\n\n",who);
  who->move_player(place,"SNEAK");
  ob1->remove();
  return;
}
