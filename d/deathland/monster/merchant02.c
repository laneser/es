#include "../echobomber.h"

inherit SELLER;
inherit MONSTER;

void create()
{
	::create();
	set_level(10);
	set_name( "eastern merchant", "東方商人" );
	add("id",({"merchant",}));
	set_short( "a eastern merchant", "東方商人" );
	set_long(
		"一個來自東方的商人,你可以向他購買物品,只要問他物品(item)"
		",他就會讓你看他的貨物.或許你能買到一些意想不到的驚喜\n"
	);
	set("alignment",-200);
	set_perm_stat( "dex", 8 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 15 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 10);
	set_perm_stat( "karma", 10);	
	set ("natural_weapon_class1",18);
	set ("natural_min_damage1",18);
	set ("natural_max_damage1",25);
	set ("natural_defense_bonus",15);
	set ("natural_armor_class",55);
	set ("max_hp", 280);
	set ("max_sp", 0);
	set ("hit_points", 280);
	set ("spell_points", 0);
	set( "race", "human" );
	set( "gender", "male" );
	// set( "no_attack", 1 );
	set_inventory( ({
		({ Object"/hawtor", 30, 30 }),
	}) );
	set( "inquiry", ([
		"item" : "@@show_menu"
	]) );
    set("chat_chance",7);
    set("chat_output", ({
        "東方商人說:跳樓大拍賣,跳樓大拍賣.\n",
        })
         );
}

void init()
{
	npc::init();
	seller::init();
}
