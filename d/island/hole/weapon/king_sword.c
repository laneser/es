#include <../hole.h>

inherit WEAPON;
void create()
{
	set_name( "Bulansido Sword","布倫希多劍" );
	add( "id",({ "sword" }) );
	set_short( "布倫希多劍" );
	set_long(@LONG
	這把劍象徵著蜥蜴人族群中至高無上的權力，
	只要誰擁有它，便可以成為蜥蜴人的領袖。這
	是傳說中連接天界與地界的聖劍，據說會帶來
	勝利與榮耀。
LONG
	);
	set( "unit","把" );
	set( "type","longblade" );
	set( "weapon_class",35 );
	set( "min_damage",20 );
	set( "max_damage",40 );
	set( "weight",150 );
	set( "value",({ 5600,"silver" }) );
//	set( "no_sale",1 );
//	set( "nosecond",1 );
}