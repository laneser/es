#include "../echobomber.h"

inherit MONSTER;

void create ()
{

	::create();
	//seteuid( getuid() );
 set_level(14);
 set_name("dwarf teacher","矮人戰鬥教師");
 add ("id", ({ "teacher","dwarf"}) );
 set_short( "a dwarf teacher",
           "矮人戰鬥教師");
 set_long(@LONG
A dwarf teacher,his fighting skill is very good.
LONG
    ,@C_LONG
矮人戰鬥教師",他的戰鬥技巧非常地好,所以負責教導新兵的基本戰鬥教練.    
C_LONG
	);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "個" );
    set_perm_stat( "dex",13);
    set_perm_stat( "str",22);
    set_perm_stat( "int",21);
    set_perm_stat( "con",20);
    set_perm_stat( "piety",8);
    set_perm_stat( "karma", 21);
    set ("max_hp",450);
    set ("max_sp",0);
    set ("hit_points",450);
    set ("spell_points",0);
    set ("wealth", ([ "gold":30]) );
    set_natural_weapon(21,3,10);
	set_natural_armor(45,15);
    set ("weight", 350);
    equip_armor(Armour"/chainmail02");
    wield_weapon(Weapon"/spear01");
}


