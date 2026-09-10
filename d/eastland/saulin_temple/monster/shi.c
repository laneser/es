#include "../saulin_temple.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(17);
	set_name("master shi hun","般若堂首座 虛行");
	add("id",({"shi","hun","monk","master"}) );
	set_short("般若堂首座 虛行");
	set_long(@C_LONG
般若堂專門研究各門各派的武學絕技，使得少林子弟將來遇到對手時得以
知己知彼百戰百勝... 所以般若堂首座必然精通江湖各門各派武藝... 虛
行是個九十歲的老僧，他八歲入少林，自幼嗜武成痴，尤擅內勁及指力，
人稱「白髮佛」。他對江湖各門各派武學莫不瞭如指掌，加上七十年的易
經筋火侯，武藝可說是爐火純青。
C_LONG
	);
	set( "alignment", 1300 );
	set( "gender", "male" );
	set( "race", "human");
	set( "unit", "位" );
	set_perm_stat( "dex",27);
	set_perm_stat( "str",28);
	set_perm_stat( "int",23);
	set("max_hp", 800);
	set("hit_points", 800);
	set("max_fp", 4150);
	set("force_points", 4150);
	set("wealth/gold", 70 );
	set_natural_weapon( 10, 9, 9 );
	set_natural_armor( 50, 12 );
	set("special_defense", ([ "all" : 60, "none" : 48 ]) );
	set("aim_difficulty",([ "critical" : 56, "vascular" : 60 ]) );
	set("weight", 840);
	wield_weapon( SAULIN_OBJ"thu" );
	equip_armor( SAULIN_OBJ"cloth2" );
	equip_armor( SAULIN_OBJ"glove1" ); 
	equip_armor( SAULIN_OBJ"necklace2" );
	equip_armor( SAULIN_OBJ"armband2" ); 
 set("special_attack",(["damage_type" : "mental","main_damage" : 40,
                                "random_dam" : 20 , "hit_rate" : 25]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
"\n虛行無奈的說：施主如此行為，莫怪老僧無禮了!!!\n\n"+
"但見虛行雙手合十，雙腳深陷入青石地板中，突然一聲斷喝，使出少林七十二\n"+
"絕技『一指禪』... 他身形一變，手中打出一股強烈的真氣，你只感到一股巨\n"+
"力如洪水□堤般衝來... 。\n\n" );
set("c_room_msg","\n虛行無奈的說：施主如此行為，莫怪老僧無禮了!!!\n\n"+
"但見虛行雙手合十，雙腳深陷入青石地板中，突然大喝一聲，使出少林七十二\n"+
"絕技『一指禪』... 他身形一變，手中打出一股強烈的真氣，射向");
set("c_room_msg2", "的身體 ...\n");
}

