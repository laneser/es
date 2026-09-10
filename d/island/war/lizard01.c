#include "../island.h"

inherit IWAR"i_warvalue";
void create()
{
	::create();
	set_level(10);
	set_name( "Lizardman Soldier", "蜥蜴人士兵" );
	add( "id", ({ "lizardman","soldier" }) );
	set_short( "Lizardman Soldier", "蜥蜴人士兵" );
	set_long(@LONG
你看到一位初次上戰場的士兵，看他傻里傻氣的樣子，手還不停地發
抖，很難想像他是一位軍人。
LONG
		);
	set( "unit","名" );
	set( "race","lizardman" );
	set( "gender","male" );
	set( "alignment", -300 );
	set_natural_weapon( 10,6,14 );
	set( "wealth/silver",20 );
	set( "justice",5 );
	set( "killer",1 );
	set( "pursuing",1 );
	set( "speed",30 );
	set_perm_stat( "str",12 );
	set_perm_stat( "dex",14 );
	set_skill( "shortblade",50 );
	set_skill( "parry",50 );
	set( "chat_chance",20 );
	set( "att_chat_output",({
	"\n蜥蜴人士兵大叫：『別逼我，我不想殺害你！』\n\n",
	"\n蜥蜴人士兵說道：『丟下你的武器投降吧，我不會傷害你的！』\n\n" }) );
	wield_weapon( IWARO"shortsword" );
	equip_armor( IWARO"cloth2" );
	equip_armor( IWARO"kepi" );
}


