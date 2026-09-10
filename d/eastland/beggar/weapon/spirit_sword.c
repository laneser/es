#include "../dony.h"

inherit WEAPON;

void create()
{
	set_name( "spirit sword", "靈氣劍" );
	add( "id", ({ "sword","spirit" }) );
	set_short( "靈氣劍" );
	set_long(@C_LONG
這是由精神和內力化成的一口寶劍，雖然不是一把舉世無雙的神兵利器,不過你要
是能掌握它的奧秘,相信能帶給你莫大的好處。
C_LONG	
	);
	set( "unit", "柄" );
	set( "weight", 0 );
	setup_weapon("longblade",25,20,27);
        set("prevent_drop",1);
        set( "prevent_drop", 1 );
        set( "prevent_get", 1 );
        call_out( "vanish_out",3600,this_object());
}
void vanish_out(object ob)
{
        ob->unwield(1);
        ob->remove(1);
        return ;
}
