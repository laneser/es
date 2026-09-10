#include "../oldcat.h" 

inherit MONSTER;

void create()
{
        object ob1;

	::create();
	set_level(14);
	set_name( "The soldier", "矮靈族衛兵" );
	add( "id", ({ "soldier" }) );
	set_short( "矮靈族衛兵" );
	set_long(
		"他守護著矮靈族部落，負責部落的安全。\n"
	);
	set( "max_hp", 600 );
	set( "hit_points", 600 );
	set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 16 );
	set_skill( "longblade",100);
	set_skill( "parry", 80 );
	set_skill( "dodge", 60 );
	
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", -200 );
	set( "natural_armor_class", 50 );
	set( "natural_defense_bonus", 15 );
	set( "wealth/gold", 15 );
        set("inquiry", ([
            "head" : "@@ask_head",
            "cut" : "@@ask_head",
            "volcano" : "@@ask_volcano",
            ]) );
     
        ob1=new(OWEAPON"wsword");
        ob1->move( this_object() );
	wield_weapon(ob1);
        equip_armor(OARMOR"mail2");
}

void ask_volcano(object who)
{
  tell_object(who,"守衛對你說：火山隨時都有爆發的可能，我們在這裡做了望的工作。\n");
  return;
}

void ask_head(object who)
{
  int i;
  object ob,*item;

  item=all_inventory(this_player());
  for(i=0;i<sizeof(item);i++) {
    if ((string)item[i]->query("name")=="sharp knife") {
      write("守衛說：你已經有一把割人頭的利器了。\n");
      return;
    }
  }
  if (this_player()->query_temp("head_knife")) {
     write("守衛說：我記得已經給過你那銳利的刀子了。\n");
     return;
  }
  tell_object(who,
    "守衛說：嗯、要想順利的把人頭割下來，須要一把銳利的刀子。\n");
  ob=new(OOBJ"head_knife");
  ob->move(this_object());
  command("give "+(string)ob->query("name")+" to "+lower_case((string)this_player()->query("name")));
  this_player()->set_temp("head_knife",1);
  return;
}
