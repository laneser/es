#include "../hole.h"

inherit MONSTER;
void create()
{
        ::create();
        set_level(7);
        set_name( "Lizardman Girl", "蜥蜴人小女孩" );
        add("id",({"lizardman","girl" }) );
        set_short( "蜥蜴人小女孩" );
        set_long(@LONG
你看見一位美麗天真的小女孩，她正在廣場上
和夥伴們玩過家家。
LONG
        );
        set( "gender","female" );
        set( "race","lizardman" );
        set( "alignment",600 );
        set( "wealth/silver",10 );
        set_perm_stat( "str",12 );
        set_perm_stat( "dex",15 );
        set_natural_armor( 20,5 );
        set_natural_weapon( 2,3,8 );
        set_skill( "parry",40 );
        wield_weapon( HWEAPON"comb" );
}

