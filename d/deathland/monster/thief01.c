#include "../echobomber.h"

inherit MONSTER;

void create ()
{

	object ob;
	::create();
    set_level(3);
    set_name("lost thief","迷路的小賊");
    add ("id", ({ "thief"}) );
    set_short("迷路的小賊");
	set_long(@LONG
一個迷路的小賊,他並不能發現出路而迷失在這裡
LONG
	);
    set("alignment",-300);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "個" );
    set_perm_stat( "dex",  6);
	set_skill("dagger",30);
    set ("max_hp",75);
    set ("max_sp",0);
    set ("hit_points",75);
    set ("spell_points",0);
    set ("wealth", ([ "gold":8]) );
    set_natural_weapon(12,4,9);
	set_natural_armor(35,0);
    set ("weight", 350);
    set("chat_chance",15);
    set("chat_output",({
        "小賊說:誰能告訴我如何離開這裡呢 ?\n"
       }) );
    wield_weapon(Weapon"/dagger06");
    ob = new(Object"/opiate");
    ob->move(this_object());
}


