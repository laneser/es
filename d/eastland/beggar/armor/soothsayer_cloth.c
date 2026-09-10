#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("Wind-Fire-Thunder robe","風火雷電七星袍");
        add("id",({"robe"}) );
        set_short("風火雷電七星袍");
	set_long(@C_LONG
這是一件神算小瓜慣穿的深黑色袍子,上面繡有七顆依照北斗七星排列的寶石。在這
件衣服上縱橫交錯的五色線條是根據易經推演而來的,神算小瓜並且在上面輔施以咒
語,讓你感覺到這件袍子充滿了各式各樣的神秘色彩。 你就算不懂上面代表的意義,
也不難想像它有很好的魔法防禦力。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",100 );
	set( "type", "body" );
        set("material","cloth");
	set( "armor_class", 10 );
	set( "defense_bonus", 5 );
	set("special_defense",
	  (["fire":10,"cold":8,"energy":6,"electric":4,"magic":20]) );
	set( "value", ({ 3465, "silver" }) );
}
