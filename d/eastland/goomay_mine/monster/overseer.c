#include "../zeus.h"
inherit MONSTER;

void create()
{       int i;
        ::create();
        set_level(19);
        set_name( "overseer", "蕭別離" );
        add ("id", ({ "overseer" }) );
        set_short( "礦工工頭 蕭別離");
        set("unit","位");
        set_long(@C_LONG
他是一位兇悍的而且強壯的工頭，所有的礦工在他的嚴苛管理下，沒有
人敢打混摸魚，聽說過去是專門做跑單幫生意的，在一次因緣際會中被
段老大所救，被段老大邀請回來幫忙，代替上次爆炸中受傷的工頭
C_LONG
        );
        
        set("alignment",100);
        set("wealth/gold",50);
        set("gender", "male");
        set("race", "dwarf");
        set("max_hp", 800);
        set("max_fp", 600);
        set("hit_points", 800);
        set("force_points", 600);
        set_perm_stat("str", 27);
        set_perm_stat("dex", 26);
        set_natural_weapon( 30,20, 40 );
	set_natural_armor( 80, 30 );
        set("special_defense", ([ "all":40, "none":30 ]) );
        set("aim_difficulty", ([ "critical":40, "vascular":50, ]) );
        set_skill("longblade",90);
        set_skill("parry", 90);
	set("tactic_func","my_tactic");
	set("inquiry",([
	"key":
"我不清楚，不過以前的工頭曾告訴我他在那次爆炸中遺失了\n"
"一個像鋼片的東西，希望我如果有發現類似的東西能還給他．\n"
])); 
	 wield_weapon(ZOBJ"/dragon_sword");
	 equip_armor(ZOBJ"/dragon_gloves");
	 equip_armor(ZOBJ"/love_ring.c");
	 equip_armor(ZOBJ"/six_shoe.c");
}
int my_tactic()
{       object *victim;
        int dam,bonus; 
        string *attack_msg=({
"\n蕭別離舉劍在頭上劃個圓後使出＜銀龍抬頭＞攻向你的頭部！．．．．．．．\n\n",
	              
"\n蕭別離將劍挽花，向後甩刺再向前上方推出使出＜仙人指路＞攻向你的弱點！．\n\n",
	              
"\n蕭別離右腿向後提膝，雙手推劍向前猛刺使出＜青龍過海＞攻向你的心臟！．．\n\n",
	              
"\n蕭別離左腳踏實，右手持劍挽逆花使出＜臥龍吐舌＞攻向你手臂！．．．．\n\n",
	              
"\n蕭別離右手持劍由上下撩，在挽花使出＜龍展風眉＞攻向你身體的弱點！．．．\n\n",
	              
"\n蕭別離右手持劍，向胸前下方橫劈使出＜矯龍吞妖＞攻向你的致命弱點！．．．\n\n"
	              });
	bonus=(int)this_player()->query_perm_stat("dex");
	if(!(victim=query_attackers())|| ( random(20)>5 ) ) return 0;
	tell_object(victim,attack_msg[random(6)]);
	dam = 60+random(30)-bonus*2;
	victim->receive_special_damage("divine",dam);
	return 1;
	}