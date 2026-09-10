#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(18);
    set_name("Wu Song ","武松");
    add("id",({"wu","song","monk"}) );
    set_short("武松");
	set_long(@C_LONG
外號行者武松，江湖上亦稱他武二郎，山東清河縣人。生得高大威猛，練成
一身好武藝，曾在景陽岡喝醉而失手打死瀕臨絕種的老虎而遭通緝，目前為梁山
步軍大統領之一。
C_LONG
	);
    set("alignment",-400);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "個" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",25);
    set_perm_stat( "int",15);
    set_perm_stat( "karma",25);
    set_skill("longblade",90);	
    set_skill("parry",90);
    set ("max_hp",700);
    set ("hit_points",700);
    set ("time_to_heal",2);
    set ("wealth", ([ "gold":300]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(50,26);
	set ("aim_difficulty",([ "weakest":40,"vascular":50]) );
	set("special_defense", (["magic":40,"none":20]) );
    set ("weight", 400);
    wield_weapon(TWEAPON"snowblade");
    equip_armor(TARMOR"skeleton_bead");
    equip_armor(TARMOR"iron_headband");
    equip_armor(TARMOR"cowskin_boots");
    equip_armor(TARMOR"vest");
}

