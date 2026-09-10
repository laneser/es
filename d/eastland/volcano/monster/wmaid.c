#include "../oldcat.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "The young lady", "矮靈族美少女" );
	add( "id", ({ "lady" }) );
	set_short( "矮靈族美少女" );
	set_long(@LONG
    一個矮靈族的美少女，一襲垂肩的長髮，玉頰上泛著淡淡的紅暈，櫻桃小口，
眼珠靈動，一雙纖手皓膚如玉，滿臉都是溫柔，滿身盡是秀氣，似還有一股動人氣
韻，端莊中帶有稚氣。
LONG
	);
	set( "race", "dwarf" );
	set( "gender", "female" );
	set( "alignment", 0 );
	set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
	set( "wealth/gold", 1 );
        set( "hit_points", 100);
        set( "max_hp", 100);
        set( "inquiry",([
             "marry" : "@@ask_marry",
             "rose" : "@@ask_rose",
             ]) );
        set("natural_armor_class",35);
        set("natural_defense_bonus",10);
        set_natural_weapon(9,7,10);
        set("chat_chance",5);
        set("chat_output",({
            "美人說：你也是那些自以為長的很帥的男人嗎，要我嫁給你，少作夢了。\n"
             }) );
        set("att_chat_output", ({
          "\n美人說：你...你...像我這麼美麗的人你怎麼還出的了手。\n"
         }) );
        set("c_death_msg","%s 嬌喘了一聲...你這輩子別想討老婆了。\n");
        set_c_verbs( ({
        "%s 向你頻拋媚眼，趁你意亂情迷時，向%s打去",
        "%s 揮動她的繡花拳向 %s 打去",
        "%s 撩起裙子，趁你正色眯眯的看她的腿時，往%s打去",
        }) );
}

void ask_marry(object who)
{
  tell_object(who,
    "美人說：你這隻癩蛤蟆也想吃天鵝肉嗎 ?\n"
  );
}

void ask_rose(object who)
{
  tell_object(who,
    "美人說：假如你能找到藍玫瑰，我就嫁給你。\n"
  );
}

int accept_item(object me,object item)
{
  string name;
  object ob;

  name=(string)item->query("name");
  if (!name || name!="blue rose") {
    return 0;
  }

  if (this_player()->query_temp("blue_rose")) {
    write("美女說：非常謝謝你，讓我嫁給一位英俊的少年郎。\n");
    write("        謝謝你又送我一朵藍色玫瑰花，實在不好意思。\n");
    write("        這樣吧，我出價十個金幣買下你這朵玫瑰花，算是對你的補償。\n");
    this_object()->set("wealth",(["gold":11]) );
    command("give 10 gold to "+lower_case((string)this_player()->query("name")));
    item->remove();
    return 1;
  }

  if (item->query(me->query("name"))) {
    write("美女說：啊 ! 這真的是那藍玫瑰，非常謝謝你，不過．．．．．．。\n");
    write("        你實在不是我喜歡的類型，很抱歉，姻緣是不能勉強的．．。\n");
    write("        這樣吧，我出價十個金幣買下你這朵玫瑰花，算是對你的補償。\n");
    this_object()->set("wealth",(["gold":11]) );
    command("give 10 gold to "+lower_case((string)this_player()->query("name")));
    item->remove();
    return 1;
  }

  write("美女看了你給他的玫瑰一眼，唉、這是人造的吧。\n");
  write("我需要的是真正的玫瑰，謝謝。\n");
  item->move(me);
  return 1;

}
