#include "saulin_monkb.c"

void create()
{
        ::create();
        set_level(15);
        set_name( "commandment enforcer", "戒律院執事僧" );
        add("id",({ "monk","enforcer" }));
        set_short("戒律院執事僧");
        set("unit","位");
        set_long(@C_LONG
他是一位看起來很嚴肅的和尚，手持戒棍，一副絕不可侵犯的樣子... 
戒律院負責少林子弟的懲罰處置，犯了任何戒律都由他們來制裁和處罰。
所以，勸你沒事的話還是離他們遠一點為妙。 
C_LONG
        );
        set("alignment",600);
        set("wealth/gold", 18);
        set_perm_stat("str",20);
        set_perm_stat("dex",25);
        set_perm_stat("kar",23);
	set_natural_weapon(-4,2,10);
        set_natural_armor(53, 19);
        set("max_fp",1800);
        set("force_points",1800);
        set("max_hp", 500);
        set("hit_points", 500);
	set("attack_skill",CLASS"fu_mo");
	set("gonfus/fu-mo",100);
        set("special_defense",([ "none" : 40, "all" : 20 ]));
        set("aim_difficulty", ([ "critical" : 35, "vascular" : 40, ]) );
        set_skill("parry",100);
	set_skill("bo",80);
        set("gender", "male");
        set("race", "human");
        wield_weapon( SAULIN_OBJ"rule_staff" );
        equip_armor( SAULIN_OBJ"necklace01" );
        equip_armor( SAULIN_OBJ"yellow_pallium" );
}
