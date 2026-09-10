#include <../hole.h>        
        
inherit MONSTER;
void create ()
{
	::create();
	set_level(15);
	set_name( "Flesheater Fish","食人魚" );
	set ( "id",({ "fish" }) );
	set_short( "食人魚" );
	set_long(@LONG
這是一條兇悍的食人魚，正在這兒覓食。
LONG
		);
	set( "likefish",1 ) ;
	set( "unit","條" );
	set( "alignment",-1000 );
	set( "killer",1 );
	set( "moving",1 );
	set( "speed",30 );
	set_natural_weapon( 60,15,40 );
	set_skill( "unarmed",80 );
	set_natural_armor( 40,10 );
	set( "c_killer_msg",
	"食人魚看到你那『白晰晰、幼咪咪』的肌膚，色眯眯地在你身旁徘徊\n\n" );
	set_c_verbs( ({ "%s用利刃般的背鰭刺向%s","%s張開長滿利牙的大嘴咬向%s" }) );
	set_c_limbs( ({ "魚鰭","尾巴","頭部" }) );
	setenv( "C_MIN","$N迅速地遊了過來" );
	setenv( "C_MOUT","$N緩緩地向$D遊了過去" );
}