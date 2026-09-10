#include "../island.h"

inherit IWAR"i_warvalue";
void create()
{
	::create();
	set_level(17);
	set_name( "Lizardman Knight","蜥蜴人騎士" );
	add( "id", ({ "lizardman","knight" }) );
	set_short( "蜥蜴人騎士" );
	set_long(@LONG
    你看到的是蜥蜴人正規軍，也就是蜥蜴人軍隊中戰鬥力最強的一
支。雖然蜥蜴人是很友善的一個種族，但是它們絕不輕言與敵人妥協，
所以你最好不要成為它的敵人。
LONG
		);
	set( "unit","名" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment",-300 );
	set_natural_armor( 59,20 );
	set_natural_weapon( 38,13,25 );
	set( "special_defense",
	([ "fire":20,"cold":15,"none":30 ]) );
	set( "aim_difficulty",
	([ "critical":75,"vascular":70,"weakest":50,"ganglion":100 ]));
	set( "stun_difficulty",60 );
	set( "wealth/silver",710 );
	set( "killer",1 );
        set( "justice",12 );
	set( "tactic","assault" );
	set_perm_stat( "str",25 );
	set_perm_stat( "dex",20 );
	set_skill( "jousting",90 );
	set_skill( "parry",90 );
	set_skill( "tactic",90 );
	set_skill( "block",90 );
	set_skill( "dodge",70 );
	set( "chat_chance",20 );
	set( "att_chat_output",({
	"\n蜥蜴人騎士大叫：你真是太天真了，蜥蜴人軍團是無人能擋的！\n\n",
	"\n蜥蜴人騎士：我們的騎士軍團就快到了，快快棄械投降吧！\n\n" }) );
	wield_weapon( IWARO"lance1" );
	equip_armor( IWARO"shield1" );
	equip_armor( IWARO"boots1" );
	equip_armor( IWARO"bracer1" );
	equip_armor( IWARO"plate1" );
}