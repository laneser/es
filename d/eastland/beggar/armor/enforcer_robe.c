#include "../dony.h"

inherit ARMOR;

void create()
{
        set_name("enforcer robe","執事者之袍");
        add("id",({"robe"}) );
        set_short("執事者之袍");
	set_long(@C_LONG
這只不過是一件普普通通的袍子,上面繡有佛家梵語,你即使不是僧侶,穿上它還真
像那麼一回事。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 3 );
	set( "value", ({ 500, "silver" }) );
}
