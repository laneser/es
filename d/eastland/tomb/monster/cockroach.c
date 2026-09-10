#include <mudlib.h>
inherit MONSTER;
 
void create()
{
        ::create();
        set_level(1);
        set_name( "cockroach", "蟑螂" );
        set_short( "蟑螂" );
        set_long(
                "一隻蟑螂，讓你覺得噁心。\n"
        );
        set_perm_stat("dex", 5 );
        set_perm_stat("str", 1 );
        set( "alignment" , -100 );
        set_c_verbs( ({ "%s張嘴往%s咬下" }) );
        set_c_limbs( ({ "頭部", "身體","觸角" }) );
 
        set( "unit", "只" );
        set( "natural_armor_class", 8 );
        set( "max_hp", 20 );
        set( "hit_points", 1 );
}
