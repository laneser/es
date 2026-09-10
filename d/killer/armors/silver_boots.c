#include  <mudlib.h>

inherit ARMOR;

string C_NAME="天蠶絲鞋";

void create()
{
        set_name("silver boots", C_NAME);
        add( "id", ({ "boots" }) );
	set_short( C_NAME );
        set_long(
                "一雙閃亮的銀色靴子，這雙靴子是諾達尼亞王室的特約工匠麥爾\n"
                "迪藍的精心傑作，他曾經很自豪地向人們說過，這雙靴子的防禦\n"
                "力除了附上魔法以外，已經無法再更強了。\n"
        );
        set( "unit", "雙" );
        set( "type", "feet" );
        set( "material", "knight");
        set( "extra_skills", ([ "defend":10 ]) ); 
        set( "armor_class", 10 );
        set( "weight", 50 );
        set( "value", ({ 100, "gold" }) );
        set( "no_sale", 1); 
}
