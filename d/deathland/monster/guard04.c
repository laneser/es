#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(16);
	set_name( "holy guard", "神聖守衛" );
	add("id",({"guard"}));
	set_short( "a holy guard", "神聖守衛" );
	set_long(
		"一個身旁有著神聖力量保護著的守衛者,他已經守護這個地方很多個世紀了\n"
	);
	set( "gender", "male" );
	set( "alignment", 1200 );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "kar", 26 );
	set_skill( "dodge", 95 );
	set_skill( "parry", 95 );
	set_natural_armor(60,50);
 	set_natural_weapon(25,15,20);
    set( "special_defense", (  ["all":30, "none": 30]  ) );
    set ("aim_difficulty",([ "critical": 30 ,"vascular": 30, "weakest": 30 ]) );
    equip_armor(Armour"/plate07");
    set("for_check",0);
/*    switch( random(3)) {
      case 0:
                set_skill("dagger",100);
                wield_weapon(Weapon"/dagger07");
                equip_armor(Armour"/helmet03");
                break;
      case 1:
                set_skill("longblade",100);
                wield_weapon(Weapon"/sword04");
                equip_armor(Armour"/leggings03");
                break;
      case 2:
                set_skill("shortblade",100);
                wield_weapon(Weapon"/shortsword05");
                equip_armor(Armour"/boots03");
                break;
      default : break;
      }*/
}

void weapon_armor() 
{
     object env;
     env=environment(this_object());
     switch ((string)env->query("for_guard")) {
        case "dagger":
                set_skill("dagger",100);
                wield_weapon(Weapon"/dagger07");
                equip_armor(Armour"/helmet03");
                break;
        case "longblade":
                set_skill("longblade",100);
                wield_weapon(Weapon"/sword04");
                equip_armor(Armour"/leggings03");
                break;
        case "shortblade":
                set_skill("shortblade",100);
                wield_weapon(Weapon"/shortsword05");
                equip_armor(Armour"/boots03");
                break;
        default : break;
        } 
    set("for_check",1);   
}

void init()
{
    ::init();
    if ( !query("for_check") )
      weapon_armor();
}
