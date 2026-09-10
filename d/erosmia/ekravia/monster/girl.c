/*
	這個小女孩是 QUEST 的第一個動機
*/
#include "/d/erosmia/ekravia/ekravia.h"
#include <mudlib.h>

inherit MONSTER;
inherit MESSAGE;

int		looked;

void	create()
{
	::create();
	set_level(3);
	set_name( "little girl", "小女孩" );
	add( "id", ({ "girl" }) );
	set_short( "一個小女孩站在牆邊, 看著你" );
	set_long(@LONG
你看到一個約十歲左右的小女孩。她穿著白色洋裝、頭上帶著頂紅色的
大草帽, 一雙睜得大大的眼睛天真無邪地看著你。
LONG
	);
	set( "gender", "female" );
	set( "alignment", 100 );
	set( "no_attack", 1);
	looked = 0;
}

void	init()
{
	add_action( "do_look", "look" );
	::init();
}

int		do_look( string s )
{
	object	target;


	if (!s) return 0;
	target = present(s, environment(this_player()) );
	if ( (!target = present(s, environment(this_player())) ) ||
		(target != this_object()) )	return 0;
		
// 已確定 player 所看的正是這個小女孩, 開始幹活了!
	tell_room( environment(this_object()), emote_message_other(
		"$NS將$GS的視線投向小女孩身上。\n", this_player()),
		({ this_player(), this_object() }) );
	tell_object( this_player(), query("long") );
// 小女孩被看到後的動作。
	
	if (looked)	return 1;
	looked = 1;
	call_out( "do_disappear", 5, this_object(), this_player() );
	return 1;
}

void	do_disappear( object me, object player )
{
	if (environment(me) != environment(player)) return;
	
	emote( "$NS張開雙手, 帶著輕快的笑聲跑向$NO身邊。然而就在一瞬間,\n" +
		"她如同海市蜃樓般消失了, 只留下陣陣無邪的笑聲在空氣中迴響著...\n",
		me, environment(player), player );
	find_object_or_load( QUEST"girl" )->girl_disappear();
}