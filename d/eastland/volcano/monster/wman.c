#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(10);
	set_name( "The young man", "矮靈族青年" );
	add( "id", ({ "man" }) );
	set_short( "矮靈族青年" );
	set_long(
         "一個矮靈族的青年，有著略帶蒼白的臉孔，憂鬱的眼神，微卷的頭髮。\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 0 );
	set_perm_stat( "str", 16 );
        set_perm_stat( "dex", 16 );
	set( "wealth/gold", 2 );
        set( "hit_points", 150);
        set( "max_hp", 150);
        set("natural_armor_class",45);
        set("natural_defense_bonus",15);
        set_natural_weapon(18,9,15);
        set("chat_chance",15);
        set("chat_output",({
            "青年正喃喃自語：唉、除非老天爺幫助我，不然我是沒有指望了。\n"
            }) );
        set( "inquiry", ([
             "trouble" : "@@ask_trouble",
             "help" : "@@ask_trouble",
             "rose" : "@@ask_rose",
             ]) );
}

void ask_trouble(object who)
{
  tell_object(who,
     "\n青年說：我愛上了部落裡最美的那位女孩子，但是．．．．．．\n"+
     "唉 ! 那位冰山美人竟然說：假如我帶著藍色的玫瑰花向她求婚，她就答應。\n"+
       "但誰都知到這世界上藍色的玫瑰花根本就不存在。\n\n");
}

void ask_rose(object who)
{
  tell_object(who,
     "\n青年說：我需要一朵真正的藍色玫瑰花，拜託你找一朵給我好嗎。\n\n"
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
    write("青年說：非常謝謝你，讓我終於可以娶到一位美嬌娘。\n");
    write("        我已經不再須要這朵玫瑰了。\n");
    item->move(me);
    return 1;
  }
  
  if (item->query(me->query("name"))) {
    write("青年說：啊 ! 這真的是那藍玫瑰，非常謝謝你，我求婚有望了。\n");
    write("另外再告訴你一個秘密：我曾聽過我父親說過我們村落好像有個關於\n");
    write("廣場的秘密，但我不太記得了．．．你可以去問我父親關於廣場(square)的事。\n");
    me->set_temp("blue_rose",1);
    item->remove();
    return 1;
  }
  
  write("他看了你給他的玫瑰一眼，唉、這是人造的吧。\n");
  write("我需要的是真正的玫瑰，謝謝。\n");
  item->move(me);
  return 1;

}
