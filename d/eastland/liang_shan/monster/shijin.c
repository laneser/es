#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(18);
    set_name("Shi Jin","史進");
    add("id",({"shi","jin"}) );
    set_short("史進");
	set_long(@C_LONG
外號九紋龍，華陰縣人，肩膊胸膛上共刺有九條繡紋青龍。重義氣，輕錢財，
精擅棍法，目前為梁山馬軍大驃騎兼先鋒使。他最近得到了一根新棍子，正拿
在手上把玩。
C_LONG
	);
    set("alignment",400);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "個" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",25);
    set_perm_stat( "int",20);
    set_perm_stat( "pie",25);
    set_perm_stat( "karma",23);
    set_skill("blunt",90);	
    set_skill("parry",90);
    set ("max_hp",520);
    set ("hit_points",520);
    set ("max_fp",1000);
    set ("force_points",1000);
    set ("time_to_heal",5);
    set ("wealth", ([ "gold":280]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(45,25);
	set ("aim_difficulty",([ "weakest":40,"vascular":40]) );
	set("special_defense", (["magic":40,"none":20]) );
    set ("weight", 400);
    equip_armor(TARMOR"iron_plate");
    wield_weapon(TWEAPON"elemental_staff");
    equip_armor(TARMOR"mirror");
    equip_armor(TARMOR"white_robe");
    equip_armor(TARMOR"silk_hood");
}

