
#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
     set_level(22);
     set_name("guard", "武神");
     set_short("the cool guard", "炎之武神");
        set_long(
                "擁有邪惡力量的武神,眼中發出可怕的邪氣.\n"
                "神聖武器護身的它最好別惹.\n",
        );
        set_perm_stat("str", 30 );
        set_perm_stat("con", 25 );
        set_skill( "thrusting", 100 );
        set( "alignment", 10000 );

        set( "race", "human" );
        set( "gender", "male" );
        set_natural_weapon( 50, 15, 30 );
        set_natural_armor( 90, 60 );

        wield_weapon( "/d/knight/fortress/weapons/dragonblood" );
}
