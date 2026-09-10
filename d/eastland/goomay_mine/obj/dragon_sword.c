
#include "../zeus.h"
inherit WEAPON;

void create()
{
        set_name( "dragon longsword ", "龍形劍" );
        add( "id",({ "sword", "dragon","longsword" }) );
        set_short( "a dragon longsword", "龍形劍" );
        set_long(@CLONG
龍形劍法自少林傳出，乃武僧絕藝之一，故有龍形劍之稱出現，此劍
乃度難大師所有，劍上刻有詩曰：
        　　　少林寶劍出鞘閃，龍頭鳳尾捲上天
        　　　刺劈窮迫越疾風，霎時閃電擊河山
      　　　　單劍能刺巨石爛，玄德雙劍闖漢關
CLONG
);
        set( "unit", "把");
        set( "weapon_class", 38 );
        set( "type", "longblade" );
        set( "min_damage", 24 );
        set( "max_damage", 44 );
        set( "weight", 190 );
        set( "value",({ 300, "gold" }) );
        }