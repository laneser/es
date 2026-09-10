#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name("green sword","太乙青霜劍");
	add ("id",({ "sword"}) );
        set_short("太乙青霜劍");
	set_long(@C_LONG
傳說青霜劍是幾千年前黃帝大戰蚩尤時在昆吾山中所得到的銅石打造而成的。銅石
本身原是像火一樣的東西，不但赤紅，又帶著極高的溫度。可是，當寶劍鑄成之後
，卻變成青色，寒光四射，有如水晶般的透明，劍身更是削鐵如泥，威力極大！後
來，黃帝的軍隊因它而打敗了蚩尤，功不可沒。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("shortblade", 28,16,32);
	set( "weight", 100 );
	set( "value", ({ 8000, "silver" }) );
}

