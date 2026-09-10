#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level( 3 );
	set_name( "Oregon", "俄勒岡" );
	add( "id", ({ "oregon" }) );
	set_short("俄勒岡" );
	set_long(
		"他是在火山附近探險時被抓的。"
	);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 800 );

	set("max_hp", 200);
	set("hit_points", 200);
	set( "wealth/silver", 40 );
        set_natural_armor( 10, 3 );
}

void give_mark(object me,object ore)
{
  tell_object(me,@LONG
正當你要轉身離開時，俄勒岡突然叫住你並說道：『咦，看你應該是書生吧。我被關在
這裡的時候，有一晚聽到守衛跟科拉克，羅索兄弟喝醉酒時說的話，內容大概是巫師科
拉克的祖先曾經救過一名在若嵐皇城偷盜被皇城禁軍殺成重傷的大盜，那位大盜送了他
們一本從皇宮內寶庫盜出的『劍法秘笈』，可惜他們家族向來只在魔法上有鑽研，對劍
術實在是不行，矮靈族也沒有什麼人能夠鍛□，所以一直鎖在神殿裡沒用。或許你可以
去偷出那本秘笈，如果你能學會的話，一定對你很有用處。』   
LONG);
  me->set_temp("known_book_of_sword",1); 
  ore->remove();
  return;
}

int accept_item(object me, object item)
{
    string name;
    object ob1;
        
        name=(string)item->query("name");
        if ( !name || (name!="ohio ring") ) {
          return 0;
        }

	tell_room( environment(),
          "俄勒岡向"+me->query("c_name")+"拜倒，說道: 謝謝你來救我！\n"
	, me );
    tell_object( me, 
        "俄勒岡說：啊! 這是我兄弟的戒指。\n"
        "俄勒岡向你拜倒，說道: 謝謝你來救我，不過我已經挖地道脫險了。\n");
        ob1 = new( OOBJ"oregon_ring" );
        ob1->move(this_object());
        ob1->set(me->query("name"),1);
        command("give "+(string)ob1->query("name")+" to "+lower_case((string)this_player()->query("name")));
        item->remove();
        tell_object(me,"俄勒岡說：：請將這個戒指拿去給俄亥俄，讓他知道我已經脫險了。\n        我也該走了，再見 !\n\n");
        command("wave "+lower_case((string)this_player()->query("name")));
        if (me->query("class")=="scholar")
          call_out("give_mark",2,me,this_object());     
        else 
          this_object()->remove();
        return 1;
}
