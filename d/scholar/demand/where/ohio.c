#include "../oldcat.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(8);
	set_name( "Ohio", "俄亥俄" );
	set_short( "俄亥俄" );
	set_long( 
             @LONG
你看他走來走去，不時的跺腳，滿頭大汗的樣子, 不禁想要幫助他。
LONG
	);
	set( "alignment", 200 );
        set( "gender", "male" );
        set( "race", "human" );
	set_perm_stat( "dex", 15 );
	set_perm_stat( "str", 16 );
	set_perm_stat( "int", 5 );
	set_perm_stat( "con", 17 );
	set_perm_stat( "piety", 7 );
	set_perm_stat( "karma", 10 );
	set ("max_hp", 220);
	set ("hit_points", 220);
	set ("wealth", ([ "gold": 5 ]) );
	set("natural_armor_class",30);
	set("natural_defense_bonus",8);
        set_natural_weapon(3,5,5);
    set ("exp_reward",690 );
    set ("chat_chance", 10);
    set ("chat_output", ({
      "俄亥俄說：有那位好心人可以幫助我嗎？\n",
    }) );
}

void init()
{
 add_action( "to_help", "help" );
}

int to_help(string str)
{
   int i;
   object player,ob1,*items;
   if(!str || str != "ohio") {
     write(
           "幫助誰?\n");
     return 1;
   }
   items=all_inventory(this_player());
   for(i=0;i<sizeof(items);i++)
     if ((string)items[i]->query("name")=="ohio ring")
     {  tell_object(this_player(),
        "俄亥俄說：你找到我的兄弟了嗎？\n");
        return 1;
     }
   write( 
     "\n俄亥俄說: 可以幫助我找我的兄弟嗎？我們兩兄弟進入火山地區探險，\n" 
     "在途中某個晚上，我在睡夢中突然聽到一聲慘叫，起來一看，我兄弟已\n"
     "已經失蹤了。第二天早上，我也趕緊收拾東西在這附近找尋我弟弟的下\n"
     "落，找著找著，竟然遇到了一個兇惡的土人，好在我跑得快，不然一定\n"
     "沒命了，我猜我弟弟大概被他們抓走了，能不能請你幫我找他，謝謝。\n"
     "請將這個戒指交給他，他就會知道我還活著。\n"
   );
   ob1 = new( OOBJ"ohio_ring" );
   ob1->move(this_object());
   command("give "+(string)ob1->query("name")+" to "+lower_case((string)this_player()->query("name")));
   return 1;
}

int accept_item(object me, object item)
{
	string name;
        
        name=(string)item->query("name");
        if ( !name || !(name=="oregon ring")) {
        return 0;
        }

    if (!item->query(me->query("name"))) {
      tell_object(me,
        "俄亥俄說：你這個戒指是從別人那裡摸來的吧!\n");
      return 1;
    }

    tell_object( me, 
      "俄亥俄說：啊! 這是我兄弟的戒指。\n"
      "俄亥俄向"+me->query("c_cap_name")+"拜倒，說道: 謝謝你救我的兄弟出來！\n"
      "我也要繼續我的旅程了，再見。\n"
    );
    command("wave "+lower_case((string)this_player()->query("name")));
    if( !me->query_quest_level("Ohio's_brother") ) {
      me->finish_quest("Ohio's_brother",1);
      if ((string)me->query("class")=="scholar") {
        tell_object(me,set_color("俄亥俄又匆匆忙忙的跑回來：這個東西是我在旅行的時後得到的，就送給你吧，說著就往\n你的手裡一塞，就離開了。你攤開手一看，是一個桃花木盒，一打開，一隻木精靈跳了出\n來，說道：我的主人，我能運用一些大自然的力量來幫助你，有需要請召喚我。\n","HIG"));
        me->set("demand/wood",1);
      }
      tell_object( me,
         set_color("[你完成了 Ohio 任務，得到 5000 點經驗]\n","HIY"));
      me->gain_experience(5000);
    }
    item->remove();
    this_object()->remove();
    return 1;
}
