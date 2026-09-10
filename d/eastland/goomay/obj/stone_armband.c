#include <mudlib.h> 
inherit ARMOR;

void create()
{
        set_name("stone armbands", "勇者護臂");
        add( "id", ({"armband","armbands" }) );
        set_short("a stone armbands", "勇者護臂");
        set_long(
        "An armband used by wrestler.\n",
	"這是用塞外西夏的黑剛石作成的護臂，通常是西夏高級的摔角勇士才有\n"
        "資格配帶的。摔角高手最怕手臂受傷，所以配此以防敵人的刀劍攻擊。\n"
                );
        set( "unit", "對");
        set( "type", "arms" );
        set( "armor_class", 4 );
        set( "defense_bonus", 0 );
        set("material","stone");
        set( "weight", 50 );
        set( "value", ({ 450, "silver" }) );
}
