#include "../dony.h"

inherit DMONSTER"limit"; 

void create()
{
        ::create();
	set_level(6);
	set_name( "fat boar", "野豬" );
        add ("id", ({ "boar","fat" }) );
        set_short( "野豬" );
	set_long(@C_LONG
這頭野豬實在很胖,胖到你幾乎把它誤認為別人飼養的豬。\n"
C_LONG
	);
        set("lvlimit",10);
        set("alignment",-50);
	set_perm_stat( "str", 5 );
	set_perm_stat( "dex", 2 );
        set( "race", "beast" );
	set( "unit", "頭" );
        set_natural_armor(2,2);
	set_natural_weapon( 9,5,8 );
	set_c_verbs( ({ "%s低頭猛衝，撞向%s", "%s在地上一滾，用牙齒往%s頂去" }) );
	set_c_limbs( ({ "頭部", "身體", "腿部", "屁股" }) );
}
