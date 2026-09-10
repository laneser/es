#include "../island.h"

inherit IWAR"i_warvalue";
void create()
{
	::create();
	set_level(19);
	set_name( "Lizardman Marshal Knight","戰事指揮官" );
	add( "id", ({ "lizardman","marshal","knight" }) );
	set_short( "蜥蜴人戰事指揮官" );
	set_long(@LONG
    你看到的是一位好戰的騎士，它等待這一刻已經不知道等多久，
興奮的它正大開殺戒以示慶祝，你最好別靠近它以免成為它的獵物。
LONG
		);
	set( "unit","名" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment",-1150 );
	set_natural_weapon( 37,11,22 );
	set_natural_armor( 68,30 );
	set( "max_hp",500 );
	set( "hit_points",750 );
	set( "special_defense",
	([ "fire":50,"cold":50,"energy":40,"electric":40,"none":50 ]) );
	set( "aim_difficulty",
	([ "critical":90,"vascular":45,"weakest":60,"ganglion":100 ]));
	set( "stun_difficulty",90 ); 
	set( "wealth/silver",890 );
	set( "tactic","melee" );
	set( "killer",1 );
	set( "justice",50 );
	set( "pursuing",1 );
	set_perm_stat( "str",27 );
	set_perm_stat( "dex",24 );
	set_skill( "polearm",100 );
	set_skill( "parry",100 );
	set_skill( "block",100 );
	set_skill( "tactic",100 );
	set( "chat_chance",10 );
	set( "att_chat_output",({
	"\n蜥蜴人指揮官冷冷地說：從來沒有人能從我的手中逃生的，乖乖地受死吧！\n\n",
	"\n蜥蜴人指揮官不屑地說：以你的能力想勝過我，再回家練十年吧！\n\n" }) );
	set( "tactic_func","my_tactic" );
	wield_weapon( IWARO"polearm" );
	equip_armor( IWARO"shield4" );
	equip_armor( IWARO"helmet3" );
	equip_armor( IWARO"arms4" );
	equip_armor( IWARO"amulet2" );
	equip_armor( IWARO"plate6" );
}

int my_tactic()
{
	string him;
	object victim;
	
	victim=query_attacker();
	him=victim->query( "c_name" );
	if( !victim || victim->query( "conditions/bleeding" ) ) return 0;
	if ( random(99) >14 ) return 0;
	tell_object( victim,
	"\n蜥蜴人指揮官突然飛快地向你胸膛刺出一槍，你發現你胸口\n"+
	"上多了一個碗大的窟窿，鮮血如噴泉般不斷地冒出來！\n\n" );
	tell_room( environment( victim ),
	"\n蜥蜴人指揮官突然飛快地向"+him+"的胸膛刺出一槍，你發現\n"
	+him+"的胸口多了一個碗大的窟窿，鮮血如噴泉般不斷冒出來！\n\n",victim );	
	victim->set( "conditions/bleeding",({ 2,15,4 }) );
	return 1;
}
