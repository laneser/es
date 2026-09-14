#include <mudlib.h>
#include <ansi.h>

#define NAIHER_BRIDGE "/d/abyss/hell/bridge"
#define REVIVE_ROOM "/d/noden/farwind/cemetery"
#define JUDGE_ROOM "/d/abyss/hell/hall"
inherit MONSTER;

void create()
{
	::create();
	set_level(13);
	set_name( "White Wuchang", "白無常" );
	add( "id", ({ "wuchang" }) );
	set_short( "White Wuchang", "白無常" );
	set_long(
		"You see the White Wuchang, agent of the Death.\n",
		"你看到一個臉色蒼白，面無表情的白衣怪人，這就是來自地獄的勾魂使者\n"
		"白無常，他和另一位黑無常負責將死去的亡魂帶到閻王面前受審。\n"
	);
	set( "gender", "male" );
}

void start_death(object ghost)
{
	object env;

	env = environment(ghost);
	if( !env ) return;
	if( environment() ) tell_room( environment(), ({
		"Black Wuchang says: Hmm... another one dies, what a day ....\n"
		"Black Wuchang's figure fades and disappears.\n"
		"With only one second, Black Wuchang returns with another ghost.\n",
		"黑無常說道: 又有人死掉了，今天是什麼日子 .....\n"
		"黑無常的身影消失在一片朦朦的霧氣中。\n"
		"只一眨眼的功夫，黑無常又用鐵鏈拖著另一個鬼魂從一片霧氣中出現。\n" }),
		this_object() );
	tell_object(ghost, can_read_chinese(ghost)?
		"\n你看到一個又高又瘦的黑色人影，無聲無息地走到你的身邊 ....\n"
		"\n黑無常說道: 你已經死了，隨我赴陰司受審吧。\n"
		"\n黑無常將一條又粗又重的鐵鏈往你頭上一套，很粗暴地拖著你向前走。\n"
		"\n你只見眼前許多雲霧像刀一樣刮過你的臉，然後出現了一座石橋 ....\n":
		"\nYou see a tall slim figure appears behind you silently ....\n"
		"\nBlack Wuchang says: YOU HAVE DIED, MORTAL ONE.\n"
		"\nBlack Wuchang put a heavy iron chain on your neck and draw you forth.\n"
		"\nYou see many white mist fly pass your face.\n" );
	ghost->move(NAIHER_BRIDGE);
	move(NAIHER_BRIDGE);
	call_out( "death1", 10, ghost );
}

void death1(object ghost)
{
	tell_object(ghost, can_read_chinese(ghost)?
		"\n黑無常說道: 鬼卒，我帶來了一個亡魂，你進去通報一聲！\n"
		"\n黑無常轉頭對你說道: 好好在這裡呆著，過了奈何橋就是陰間了。\n":
		"\nBlack Wuchang says: Guards, I have brought a new ghost, announce it!\n"
		"\nBlack Wuchang turns to you and says: WAIT HERE.\n" );
	call_out( "death2", 30, ghost );
}
void death2(object ghost)
{
     tell_object(ghost,can_read_chinese(ghost)?
     "\n跟著我來,黑無常說道,\n":
     "\n Follow me,Black wuchang says.\n"
     );                     
    
     ghost->move_player(JUDGE_ROOM,"SNEAK");
     call_other(JUDGE_ROOM,"death3",ghost); 
}
void death3(object ghost)
{
	tell_object(ghost, can_read_chinese(ghost)?
		"\n鬼卒說道: 算你運氣好，森羅殿還在整修當中，回陽間去吧！\n"
		"\n鬼卒抓起你往雲霧中一丟，一陣天旋地轉之後，你又見到一片熟悉的景象 ...\n":
		"\nHell Guard says: THE HELL IS NOT READY FOR GHOSTS, GO BACK!\n"
		"\nHell Guard throw you into the moar, you see something familiar ....\n" );
	ghost->move(REVIVE_ROOM);
	ghost->revive();
}
