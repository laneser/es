#include "../forest.h"

inherit MONSTER;

void create()
{
        ::create();
        set_level(5);
        set_name("goblin", "小惡鬼");
        add( "id", ({ "goblin" }) );
        set_short("小惡鬼");
        set_long(@LONG
它是一種矮小, 紅眼尖耳, 有點類似猴子的類人生物。當然, 它們比猴子聰明
多了。光是從它們可以使用武器這點來看, 對初出茅廬的冒險者而言算是相當危險
的敵人。
LONG
        );
        set( "unit", "只" );
        set( "gender", "male" );
        set_natural_armor( 25, 10 );
        set_natural_weapon( 8, 3, 5 );
        set( "alignment", -100 );
        wield_weapon(OBJ"small_dagger");
}

void die()
{
		if( random(10) == 1 ) set("wealth/gold", 2);
		else set("wealth/silver", random(10));
		::die();
}
