#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(6);
	set_name( "older", "老頭子" );
	set_short( "老頭子" );
	set_long(@C_LONG
一位白髮蒼蒼皺紋橫布的人，他正在樹下拿著扇子一邊納涼一邊看著小孩子嘻戲。
C_LONG
        );
	set( "gender", "male" );
        set_natural_armor(30,0); 
        set_natural_weapon( 9,3,8 );
        set("chat_chance",10);
        set("chat_output",({
           "老頭子喃喃自語道：好想去天都(fly_building)逛逛喲。\n"
        }) );
}
