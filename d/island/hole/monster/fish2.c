#include "../hole.h"        
        
inherit MONSTER;
void create ()
{
	::create();
	set_level(8);
	set_name( "Dragon Fish","紅龍" );
	set ( "id",({ "fish" }) );
	set_short( "紅龍" );
	set_long(@LONG
這是一條巨大的紅龍魚。
LONG
		);
	set( "likefish",1 ) ;
	set( "unit","條" );
	set( "alignment",1000 );
	set( "moving",1 );
	set( "speed",30 );
	set_natural_weapon( 35,5,16 );
	set_skill( "unarmed",80 );
	set_natural_armor( 25,8 );
	set_c_verbs( ({ "%s用巨大的尾鰭掃向%s","%s張開長滿利牙的大嘴咬向%s" }) );
	set_c_limbs( ({ "魚鰭","尾巴","頭部" }) );
	setenv( "C_MIN","一條很大尾的$N慵懶地遊了過來" );
	setenv( "C_MOUT","一條很大尾的$N慵懶地向$D遊了過去" );
}