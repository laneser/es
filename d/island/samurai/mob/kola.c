#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Ninja Kola","忍者 葛拉" );
	add( "id", ({ "ninja","kola" }) );
	set_short( "忍者 葛拉" );
	set_long(@AAA
忍者葛拉，武士團黑暗力量的代表，藉由葛拉所率領的忍者部隊在暗地的行動，以
及武士團的正面作戰，這就是武士團的必勝方程式，而忍者首領葛拉的武藝號稱武
士城堡中最強的，你如果不信的話可以找他試一試！！！
AAA
        );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 18 );
        set_perm_stat( "dex", 25 );
        set_perm_stat( "kar", 25 );
        set_perm_stat( "pie", 15 );
        set( "time_to_heal",20 );    
        set( "max_hp",1000 );
        set( "hit_points",1000 );
 	set_natural_armor( 70,20 );
	set( "natural_weapon_class1", 20 );
	set( "natural_min_damage1", 20 );
	set( "natural_max_damage1", 40 ); 
        set( "special_defense",([ "all":25,"none":25 ])); 
        set( "aim_difficulty",([ "critical":90,"weakest":70,"ganglion":100,
                                 "vascular":35 ]));
        set( "stun_difficulty",10);  
	set( "alignment", -1000 );
	set_c_limbs( ({ "頭部", "身體", "手腕", "咽喉" }) );
        set_skill( "parry", 80 );
        set_skill( "longblade", 100 );
        set_skill( "unarmed", 100 );
        set_skill( "dodge", 80 );
        set_skill( "tactic", 100 );
        set( "tactic","melee");
        set( "wealth" , ([ "gold": 100 ]) );
        set("chat_chance",15);
        set("att_chat_output",({@AAA
        
葛拉狂笑道：你覺得你的經驗值夠多嗎？夠你死嗎？那我就成全你吧！！

AAA
,@BBB

葛拉說道：我是很慷慨的，可以免費送你去遠風鎮不收你半毛錢喔！！

BBB
}));    
        wield_weapon(MOBJ"evil_sword.c");
        equip_armor(MOBJ"dragon_chainmail.c");
        equip_armor(MOBJ"samurai_boots.c"); 
}
