#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(11);
	set_name( "The right_temple enforcer", "右殿執事" );
	add( "id", ({ "enforcer" }) );
	set_short( "右殿執事" );
	set_long(
                "一位神殿右殿執事，他付責神殿中右殿的祭祀事情。\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 400 );
	set_perm_stat( "str", 16 );
        set_perm_stat( "dex", 16 );
        set_perm_stat( "int", 21 );
        set_perm_stat( "pie", 25 );
	set( "wealth/gold", 14 );
        set( "hit_points", 180);
        set( "max_hp", 180);
        set("natural_armor_class",35);
        set("natural_defense_bonus",20);
        set_natural_weapon(10,2,5);
        wield_weapon(OWEAPON"whip2");
        equip_armor(OARMOR"cloth3");
        set( "inquiry", ([
             "box" : "@@ask_box",
             "fruit":"@@ask_tree",
             "tree": "@@ask_tree",
             "dragon":"@@ask_dragon",
             ]) );
}

void ask_box(object who)
{
  tell_object(who,
     "\n我覺的黑龍寶盒的傳說是假的，不要去相信那條龍的話，\n"
         "它只是要你去送死罷了。\n\n"
     ); 
}

void ask_tree(object who)
{
  tell_object(who,
    "\n欲得人參果，需要小棒槌敲(hit)果子。\n\n" );
}

void ask_dragon(object who)
{
  tell_object(who,
    "\n執事說：相傳火龍是火神的坐騎之一，全身冒著火□，口中也能吐出烈火。\n\n"  );
}
