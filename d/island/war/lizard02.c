#include "../island.h"

inherit IWAR"i_warvalue";
void create()
{
	::create();
	set_level(12);
	set_name( "Lizardman Sergeant","蜥蜴人班長" );
	add( "id",({ "lizardman","sergeant" }) );
	set_short( "蜥蜴人班長" );
	set_long(@LONG
    你看到的是一位戰場上的老兵，他正帶領著班兵四處殺敵，企圖
殲滅敵人。
LONG
	);
	set( "unit","名" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment",-300 );
	set_natural_armor( 50,15 );
	set_natural_weapon( 18,8,18 );
	set( "wealth/silver",90 );
	set( "justice",10 );
	set( "killer",1 );
	set( "pursuing",1 );
	set( "tactic","melee" );
	set_perm_stat( "str",15 );
	set_perm_stat( "dex",20 );
	set_skill( "longblade",60 );
	set_skill( "parry",60 );
	set_skill( "block",60 );
	set_skill( "tactic",60 );
	set( "chat_chance",20 );
	set( "att_chat_output",({
	"\n蜥蜴人班長大叫：『小子真大膽，敢向我挑戰！』\n\n" }) );
	wield_weapon( IWARO"longsword" );
	equip_armor( IWARO"cloth2" );
	equip_armor( IWARO"kepi" );
}