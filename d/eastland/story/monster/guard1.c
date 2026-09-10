#include "../story.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "wing guard", "羽民族守衛" );
	add( "id", ({ "guard" }) );
	set_short( "羽民族守衛" );
	set_long(@C_LONG
羽民族守衛負責保護妖精村落的安全，在機要地方都有他的蹤跡，他是位強力戰士
，是羽民族最信賴的夥伴。摒除羽民族都是很瘦弱矮小的觀念，羽民族守衛給你第
一眼的印象是孔武有力，當然這對於做守衛工作而言是相當有利的。
C_LONG
        );
	set( "gender", "male" );
	set( "alignment", 100 );
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 20 );
        set_perm_stat( "int", 23 );
        set_perm_stat( "kar", 35 );
        set_skill( "parry", 50 );
        set_skill( "anatomlogy", 50 );
        set_skill( "dodge", 50 );
        set_skill( "dagger", 60 );
        set("max_hp", 500);
        set("hit_points",500);
        set("aiming_loc","weakest");
        set("special_defense", ([ "all":30, "none":20]) );
        set("aim_difficulty",
           ([ "vascular":50, "weakest":20 ]) );
        set_natural_armor(40,14);
        set_natural_weapon( 33,10,10);
        wield_weapon(SWEA"dagger1");
        equip_armor(SARM"imp_armband");
        equip_armor(SARM"imp_leggings");
        equip_armor(SARM"imp_plate");
}
