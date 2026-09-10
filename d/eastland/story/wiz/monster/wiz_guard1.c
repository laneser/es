#include "../../story.h"

inherit SMOB"s_army";

void create()
{
	::create();
	set_level(13);
	set_name( "gate guard", "城門守衛" );
	add( "id", ({ "guard" }) );
	set_short( "城門守衛" );
	set_long(@C_LONG
城門守衛是負責「巫咸國」的安全工作的重要一員之一。雖然他一個人的力量不怎
樣，但是，他們卻重於團結，往往給來襲的敵人一個重重的痛擊。
C_LONG
        );
	set( "gender", "male" );
	set( "alignment", 600 );
        set( "weight",1000);
        set_perm_stat( "str", 20 );
        set_perm_stat( "dex", 17 );
        set_skill( "parry", 75 );
        set_skill( "block", 75 );
        set_skill( "polearm", 60 );
        set_natural_armor(50,11);
        set("wealth/gold",20);
        wield_weapon(SWWEA"polearm1");
        equip_armor(SWARM"wiz_shield1");
}
