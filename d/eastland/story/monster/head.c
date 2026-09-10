#include "../story.h"

inherit SMOB"pmob";
void create()
{
	::create();
	set_level(19);
	set_name( "Blue-Face scorpio's head", "人面藍蠍" );
	add( "id", ({ "head","scorpio" }) );
	set_short( "人面藍蠍的頭部" );
	set_long(@C_LONG
你眼前所見的是隻體型巨大無比，全身泛出紫藍色的蠍子。它的頭好像是一個人的
臉，但額前卻多凸出兩隻茶杯大小的怪眼，睜合之間兇芒四射，忽紅忽藍，奇光閃
爍不定。
C_LONG
        );
	set("pname","人面藍蠍");
	set( "alignment", -1000 );
        set_perm_stat( "str", 25 );
        set_perm_stat( "dex", 30 );
        set_perm_stat( "pie", 10 );
        set_perm_stat( "int", 25 );
        set_perm_stat( "kar", 30 ); 
        set_skill("dodge",100);
        set_skill("unarmed",100);
        set("hit_points",2000);
        set("max_hp",2000);
        set_natural_armor(90,15);
        set_natural_weapon( 61,44,56 );
        set("special_defense", (["all":30,"none":25]) );
        set_c_limbs( ({ "眼睛", "牙齒", "額頭", "頸部"}) );
        set_c_verbs( ({ 
            "%s用它的額頭猛撞%s",
            "%s用它的牙齒往%s一咬",
            "%s從後面伸出尖銳的毒刺往%s一螫"}) );
}
