#include "../hole.h"

inherit MONSTER;
void create()
{
        ::create();
        set_level(5);
        set_name( "Lizardman child", "蜥蜴人小孩" );
        add("id",({"lizardman","child" }) );
        set_short( "蜥蜴人小孩" );
        set_long(@LONG
你看見一位天真活潑的小孩，他正在廣場上和
夥伴們玩遊戲
LONG
        );
        set( "gender","male" );
        set( "race","lizardman" );
        set( "alignment",600 );
        set( "wealth/silver",10 );
        set_perm_stat( "str",10 );
        set_perm_stat( "dex",13 );
        set_natural_armor( 20,5 );
        set_natural_weapon( 2,0,2 );
        set_skill( "parry",40 );
        wield_weapon( HWEAPON"bat" );
}

