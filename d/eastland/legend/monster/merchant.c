#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(8);
	set_name( "fish merchant", "魚販" );
	add( "id", ({ "merchant" }) );
	set_short( "魚販" );
	set_long(@C_LONG
魚販的肩膀正挑著兩擔沈重的魚貨要去漁市場賣。看他兩肩下沈，走起路來歪歪斜
斜，滿身大汗，喘呼呼的樣子，你不禁想幫他一把。
C_LONG
        );
	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 100 );
        set_perm_stat( "str", 7 );
        set_perm_stat( "dex", 2 );
        set_natural_armor(40,2);
        set_natural_weapon( 11,5,8 );
}
