#include "../../story.h"
inherit MONSTER ;
void create ()
{
	::create();
	set_level(13);
	set_name( "The palace's lady", "天都仙女" );
	add ("id", ({"lady"}) );
	set_short( "天都仙女");
	set_long(@CLONG
天都仙女生得雪膚花貌，秀麗入骨，一色淺黃色宮裝，雲鬢風鬟，仙姿綽約，亭亭
玉立，手執蒲扇，侍立一旁。
CLONG
	);
	set("race","god");
	set("gender","female");
	set_natural_armor( 70, 0 );
        set_natural_weapon(6,0,5);
        set("wealth/silver",100);
        set_skill("blunt",40);
        set("queen_f",1);
        wield_weapon(SPWEA"fan1");
        equip_armor(SPARM"f_cloth1");
}

