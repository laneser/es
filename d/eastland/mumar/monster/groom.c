#include <../mumar.h>
inherit MONSTER;
 
void create()
{
        ::create();
        seteuid( getuid() );
        set_level(5);
        set_name( "groom", "馬伕" );
        set_short( "馬伕" );
        add( "id", ({ "groom" }) );
        set_long( "一個馬伕，負責看管照顧馬房裡的馬兒們。\n" );
        set( "gender", "male" );
        set( "alignment", 150 );
        set( "wealth/silver", 30 );
        set( "natural_armor_class", 26 );
        set( "natural_defense_bonus", 12 );
        set( "no_attack",1 );
        set_natural_weapon(11,4,14);
        set_perm_stat( "str", 5 );
        set_perm_stat( "dex", 7 );
        set_skill( "dodge", 50 );
}
