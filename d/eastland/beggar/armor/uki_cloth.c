#include "mudlib.h"

inherit ARMOR;

void create()
{
        set_name("doctor cloth","醫者之袍");
        add("id",({"cloth"}) );
        set_short("醫者之袍");
	set_long(@C_LONG
這是『一代神醫 小雪子』最愛穿的衣服。雖然上面破了幾個洞, 而且縫縫補補幾
個補丁,好像一用力就會被撕個稀巴爛, 但由於是小雪子死去的師父所贈, 對她而
言異常珍貴。
C_LONG	         );
	set( "unit", "件" );
	set( "weight",110 );
	set( "type", "body" );
        set("material","healer");
	set( "armor_class", 35 );
	set( "defense_bonus", 8 );
	set("special_defense",
	     (["fire":-10,"poison":15,"acid":10]) );
	set( "value", ({ 4000, "silver" }) );
}
