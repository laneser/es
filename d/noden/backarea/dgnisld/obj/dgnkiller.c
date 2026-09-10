#include "../dgnisld.h"

inherit WEAPON;

void create()
{
	set_name("Dragon Killer", "殺龍劍");
	add ("id",({ "sword","dragon killer","longblade", }) );
	set_short("a Dragon killer", "殺龍劍");
	set_long(
	    "A long sword named \"Dragon Killer\". It can cause much damage\n" 
	"to dragons, dinosaurs as same as its name. But it is a normal long\n"
	"blade to other animals.\n",
	    "一把名為龍之終結者之劍，正如其名，它對龍、恐龍都有很大的殺傷力\n"
	"。但對於其他種類，它只是一把普通的長劍。\n"
	);
	
	set( "weapon_class", 10 );
	set( "type", "longblade" );
	set( "min_damage", 15 );
	set( "max_damage", 35 );
	set( "weight", 50 );
	set( "value", ({ 10, "gold" }) );
	set( "unit", "把" );
}
