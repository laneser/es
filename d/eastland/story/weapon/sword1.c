#include <mudlib.h>

inherit WEAPON;
void create()
{
	set_name("heavy iron sword","玄鐵重劍");
	add ("id",({ "sword"}) );
        set_short("玄鐵重劍");
	set_long(@C_LONG
這是一把通體拗黑的重型兵器。玄鐵重劍的劍身並不怎麼鋒利，雕工也不怎麼精細
，黑沈沈的不怎麼順手，看起來宛如是塊黑色大石。當年，劍客「八神吹雪」憑著
這一把玄鐵重劍打遍江湖無敵手，他手底下工夫直是叫人匪疑所思。
C_LONG
	);
	set( "unit", "把" );
        setup_weapon("longblade", 35,20,30);
	set( "weight", 100 );
	set( "value", ({ 5000, "silver" }) );
}

