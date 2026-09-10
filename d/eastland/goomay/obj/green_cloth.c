#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("green cloth","翠煙羅");
        add("id",({"cloth","green"}) );
        set_short("green cloth","翠煙羅");
	set_long(
"This is a suit of cloth made of silk meterial.\n",
"『孤燈寒照雨，深竹暗浮煙，故人江海別，幾度隔山川。』 \n"  
"這是用江南的翠蠶絲和寒煙山莊的寒煙綢編織而成的衣裳。 \n"   
"是『江南一劍』江羽送給靈兒的定情之物，然流水有情，落花無意... \n"
	);
	set( "unit", "件" );
	set( "weight", 135 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 20 );
	set( "defense_bonus", 10 );
	set( "value", ({ 250, "gold" }) );
	set("no_sale",1);
}
