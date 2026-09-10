#include <mudlib.h>
#include <ansi.h>

#define NAIHER_BRIDGE "/d/abyss/hell/bridge"
#define REVIVE_ROOM "/d/noden/farwind/cemetery"

inherit MONSTER;

void op_revive1(object ghost);
void op_revive2(object ghost);

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

	if( ! ghost ) return;
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
	if (ghost->query_temp("operate")) call_out( "op_revive1", 10, ghost);
	else call_out( "death1", 10, ghost );
}

void death1(object ghost)
{
	if ( ! ghost ) return;
	tell_object(ghost, @DEATH1
黑無常說道: 鬼卒，我帶來了一個亡魂，你進去通報一聲！
黑無常轉頭對你說道: 好好在這裡呆著，過了奈何橋就是陰間了。
DEATH1
		    );
    if (ghost->query_temp("operate")) call_out( "op_revive1", 5, ghost);
	else call_out( "death2", 30, ghost );
}

void death2(object ghost)
{

	if ( !ghost) return;
	if (ghost->query_temp("operate")) {
	   op_revive1(ghost);
	   return;
	}   
	tell_object(ghost, @DEATH2
鬼卒說道: 算你運氣好，森羅殿還在整修當中，回陽間去吧！
鬼卒抓起你往雲霧中一丟，一陣天旋地轉之後，你又見到一片熟悉的景象 ...
DEATH2
		);
	ghost->move(REVIVE_ROOM);
	ghost->revive(0);
}

void op_revive1(object ghost)
{
     if (!ghost) return;
     if (! (ghost->query_temp("operate") ) ) {
        call_out("death2",20,ghost);
        return;
     }
     tell_object(ghost, @OP_REV1
你看著四周哭泣的鬼魂, 不禁想起你在陽間的親友, 你的家庭, 你
的事業....不行, 你還有太多事情放不下, 你決心要逃離這個鬼地
方。
OP_REV1
     );
     call_out("op_revive2",20,ghost);
}

void op_revive2(object ghost)
{
     string healer;
     object healer_obj;
     if (!ghost) return;
     if (! (healer=ghost->query_temp("operate") ) ) {
        tell_object(ghost,"唉, 看守太嚴密了, 你找不到機會逃跑!\n");
        death2(ghost);
        return;
     }
     if (! (healer_obj=find_player(healer) ) ) {
         death2(ghost);
         return;
     }
     tell_object(ghost, @OP_REV2
你發現看守你的鬼卒正在打瞌睡, 立刻把握機會回頭就跑....
鬼卒, 牛頭馬面, 黑白無常在你身後喊叫, 追趕著, 但你不理會他們, 一心
只想逃離這裡....
你忽然一腳踏空, 從一片雲霧中摔了下來, 四周又回到你熟悉的影像。
OP_REV2
      );
      
      ghost->move(environment(healer_obj));
	  ghost->revive(1);
}                 
