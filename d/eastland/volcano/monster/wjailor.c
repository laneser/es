#include "../oldcat.h" 

inherit MONSTER;

void create()
{
	object ob1,ob2;

	::create();
	set_level(14);
	set_name( "guard", "矮靈族守衛" );
	add( "id", ({ "guard" }) );
	set_short( "矮靈族守衛" );
	set_long(
	  "一個負則看守祭品的守衛，有他在這兒，想劫獄，再等一百年吧。\n"
	);
	set( "max_hp", 500 );
	set( "hit_points", 500 );
	set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "kar", 20 );
	set_skill( "chain", 80 );
	set_skill( "parry", 80 );
	set_skill( "dodge", 60 );
        set_skill( "tactic", 80 );
	
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", -800 );
        set( "tactic", "melee" );
	set( "natural_armor_class", 40 );
	set( "natural_defense_bonus", 29 );
        set_natural_weapon(2,5,8);
	set( "wealth/gold", 20 );

	ob1=new(OWEAPON"wstar");
	ob1->move( this_object() );
	wield_weapon(ob1);

        ob2=new(OOBJ"wguard_key");
        ob2->move(this_object());

        equip_armor(OARMOR"mail4");
}

void die()
{
  object ob1,killer;

  killer=query("last_attacker");
  if (!killer) {
    ::die();
    return;
  }
  tell_object(killer,
    "守衛說：你終於還是技高一籌，不過你給我記住，我要和你再比一場，場地在陰間。\n");

  ::die();
}
