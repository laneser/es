#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("red coat","紅雲衫");
        add("id",({"cloth","red"}) );
        set_short("紅雲衫");
	set_long(@AA
一件火紅的衣裳，沒有什麼特別的地方，上面的鈕釦早已壞的壞掉的掉了，
還染上了不少的酒漬，不過每當老酒鬼喝醉的時候，就會對著這件衣服默默
地掉下幾滴淚水，想必它又是一個故事的見證．
AA
	);
	set( "unit", "件" );
	set( "weight", 150 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 20 );
	set( "defense_bonus", 5 );
	set( "value", ({ 250, "gold" }) );
}
