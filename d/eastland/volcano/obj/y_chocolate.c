#include "../oldcat.h" 

inherit OBJECT;

void create()
{
	set_name( "yellow_chocolate", "黃色巧克力" );
	add( "id", ({ "chocolate" }) );
	set_short( "黃色巧克力" );
	set_long(
		"這是一個慾望巧克力，你可以□□看(taste)。\n"
	);
	set( "type", "misc" );
	set( "weight", 10 );
	set( "value", ({ 1, "silver" }) );
	set( "no_sale", 1 );
}

void init()
{
  add_action("do_eat","taste");
}

int do_eat(string arg)
{
   int align;

   if(!arg || arg!="chocolate")
   { write("你要吃什麼？\n");
     return 1;
   };

   write("你吃了這塊巧克力，你的心裡浮出一個影像：\n");
   this_player()->set_temp("block_command",1);
   write("\n\n\n\n\n\n\n");
   call_out("idle_time1",2,this_player());
   call_out("idle_time2",9,this_player());
   call_out("end",11,this_object());

   align=this_player()->query("alignment");
   this_player()->set("alignment",align+10);
   return 1;
}

int idle_time1(object who)
{
    tell_object(who,"你耳邊聽到朝拜的聲音，定神一看，只見所有的ES玩家正跪在地上向你膜拜  \n");
    tell_object(who,"你不禁哈哈大笑．．．．．．．．我是ES之王啦．．．．．．．．．．．．  \n");
    tell_object(who,"\n\n\n\n\n\n\n");
    return 1;
}

int idle_time2(object who)
{
    tell_object(who,"突然你的眼前一片黑暗，你震了一下，你發覺你的周圍都是人，而且不知道用\n");
    tell_object(who,"手對著你指指點點的做什麼，臉上還帶著鄙視的笑容，\n");
    tell_object(who,"你正覺得奇怪時，突然發現自己正流著口水，地上還□□的，糗死了\n");
    tell_object(who,"你恨不得地上有個洞可以馬上鑽進去。\n");
    who->set_temp("block_command",0);
    return 1;
}

void end(object ob1)
{
  ob1->remove();
  return;
}
