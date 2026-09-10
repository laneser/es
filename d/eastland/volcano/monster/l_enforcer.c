#include "../oldcat.h"

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(11);
	set_name( "The left_temple enforcer", "左殿執事" );
	add( "id", ({ "enforcer" }) );
	set_short( "左殿執事" );
	set_long(
                "一位神殿左殿執事，他付責神殿中左殿的祭祀事情。\n"
	);
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "alignment", 500 );
	set_perm_stat( "str", 15 );
        set_perm_stat( "dex", 15 );
        set_perm_stat( "pie", 25 );
        set_perm_stat( "int", 23 );
	set( "wealth/gold", 15 );
        set( "hit_points", 200);
        set( "max_hp", 200);
        set("natural_armor_class",35);
        set("natural_defense_bonus",15);
        set_natural_weapon(10,3,7);
        wield_weapon(OWEAPON"whip1");
        equip_armor(OARMOR"cloth3");
        set( "inquiry", ([
             "box" : "@@ask_box",
             "tree": "@@ask_tree",
             "fruit": "@@ask_tree",
             "chilin":"@@ask_chilin",
             ]) );
}

void ask_box(object who)
{
  tell_object(who,
     "\n執事說：我覺的黑龍寶盒的傳說應該是真的，但要找到它是非常困難。\n"
       "我曾聽長老說過，黑龍的寶盒有難以想像的強大力量，連巫師的神力也難\n"
       "以抗衡，聽說只要黑龍拿到它的寶盒，它就能再恢復昔日強大的力量。\n\n"
     ); 
}

void ask_tree(object who)
{
  tell_object(who,
    "\n執事說：人□果入土即化，需要有塊布攤開(spread)在下面接著。\n\n");
}

void ask_chilin(object who)
{
  tell_object(who,
    "\n執事說：相傳火麒麟是火神的坐騎之一，全身冒著火□，口中也能吐出烈火。\n\n");
}
