#include <mudlib.h>
#include <ansi.h>

#define NAIHER_BRIDGE "/d/abyss/hell/bridge"
#define REVIVE_ROOM "/d/noden/farwind/cemetery"

inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "Black Wuchang", "黑無常" );
	add( "id", ({ "wuchang" }) );
	set_short( "黑無常" );
	set_long( @LONG
你看到一個臉色蒼白，面無表情的黑衣怪人，這就是來自地獄的勾魂使者
黑無常，他和另一位白無常負責將死去的亡魂帶到閻王面前受審。
LONG
	);
	set( "gender", "male" );
}

void start_death(object ghost)
{
	object env;

	env = environment(ghost);
	if( !env ) return;
	if( environment() ) tell_room( environment(), @DIE1
黑無常說道: 又有人死掉了，今天是什麼日子 .....
黑無常的身影消失在一片朦朦的霧氣中。
只一眨眼的功夫，黑無常又用鐵鏈拖著另一個鬼魂從一片霧氣中出現。
DIE1
		,this_object() );
	tell_object(ghost, @DIE
你看到一個又高又瘦的黑色人影，無聲無息地走到你的身邊 ....
黑無常說道: 你已經死了，隨我赴陰司受審吧。
黑無常將一條又粗又重的鐵鏈往你頭上一套，很粗暴地拖著你向前走。
你只見眼前許多雲霧像刀一樣刮過你的臉，然後出現了一座石橋 ....
DIE
	);
	ghost->move(NAIHER_BRIDGE);
	move(NAIHER_BRIDGE);
	call_out( "death1", 10, ghost );
}

void death1(object ghost)
{
	tell_object(ghost, @DEATH1
黑無常說道: 鬼卒，我帶來了一個亡魂，你進去通報一聲！
黑無常轉頭對你說道: 好好在這裡呆著，過了奈何橋就是陰間了。
DEATH1
		    );
	call_out( "death2", 30, ghost );
}

void death2(object ghost)
{

	tell_object(ghost, @DEATH2
鬼卒說道: 算你運氣好，森羅殿還在整修當中，回陽間去吧！
鬼卒抓起你往雲霧中一丟，一陣天旋地轉之後，你又見到一片熟悉的景象 ...
DEATH2
		);
	ghost->move(REVIVE_ROOM);
	ghost->revive();
}
