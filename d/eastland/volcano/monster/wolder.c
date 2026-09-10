#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(10);
	set_name( "The older", "矮靈族老人" );
	add( "id", ({ "older" }) );
	set_short( "矮靈族老人" );
	set_long(
          "一個矮靈族的老人，滿臉皺紋，駝著背，他是50年前火山爆發的倖存者之一。\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", -10 );
	set_perm_stat( "str", 15 );
	set( "wealth/gold", 5 );
        set( "hit_points", 150);
        set( "max_hp", 150);
        set("natural_armor_class",40);
        set("natural_defense_bonus",15);
        set_natural_weapon(15,5,5);

        ob1=new(OWEAPON"wstick");
        ob1->move( this_object() ); 
	wield_weapon( ob1 );

        equip_armor(OARMOR"boots1");
        set("inquiry", ([
            "square":"@@ask_square",
            "rose": "@@ask_rose",
            "volcano":"@@ask_volcano",
            "fire" : "@@ask_fire",
            ]) );
}

void ask_square(object who)
{
  tell_object(who,
   "\n老人說：不知道是不是我老眼昏花，我曾看過廣場中間的巨大營火(fire)曾經熄\n"
   "滅，待我帶人去看時，它又恢復原狀了．．．．部落裡沒有人願意相信我的話。\n\n"
   );
   return;
}

void ask_fire(object who)
{
  tell_object(who,
   "\n老人說：那營火實在很奇怪，我曾看它消失過。\n"
  );
  return;
}

void ask_rose (object who)
{
  tell_object(who,
    "老人說：我那個兒子在發春了，我活那麼久，還沒聽說過有藍玫瑰的存在。\n"
  );
  return;
}

void ask_volcano(object who)
{
  tell_object(who,
     "老人說：這座火山實在是我們矮靈族的惡夢，50年前的爆發把我們矮靈族幾乎全毀了，只有少數人還活下來，所以找一個好方法來解決火山爆發的問題，實在是刻不容緩。\n"
  );
  return;
}
