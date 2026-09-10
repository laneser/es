#include "ekravia.h"
inherit BASE_ROOM;

int		room_working;

void	create()
{
	::create();
	set_light(1);
	set_short("旅館房間");
	set_long(
@CLong
這裡是旅館的客房。首先映入眼簾的是一張木製的大床, 上面整齊地
鋪著潔白的床單、棉被與一個大枕頭。看來雖是平淡無奇, 但據稱只要在
這張床上面睡一個晚上, 所有的外傷都可以不藥而癒。
    床旁邊是一張小桌子, 上面擺了一面鏡子與一盞油燈。在床的另一側
則是一個大衣櫥。其他還有一些傢俱, 但睡眼惺忪的你無暇看那麼多了。
CLong
);
	set("exits", ([
		"out"		: HERE"corridor2",
		]));
}

void	init()
{
	int		sleep_time;

	::init();
	if (!room_working)
	{
		room_working = 1;
		call_out( "do_sleep", 2, this_player() );
		sleep_time = random(60) +60;
		call_out( "wake_up", sleep_time, sleep_time, this_player(), 
			this_object() );
	}
}

void	do_sleep(object ob)
{
	if (ob) {
		tell_object( ob, "你往床上一躺, 不久便沈沈地睡著了\n" );
		ob->set_temp("block_command", 1);
	}
}

void	wake_up(int time, object ob, object this_room)
{
	object	key;

	if (ob) {
		ob->add( "hit_points", time*3/2 );
		if ( ob->query("hit_points") > ob->query("max_hp") )
			ob->set("hit_points", ob->query("max_hp") );
		ob->add( "spell_points", time*2 );
		if ( ob->query("spell_points") > ob->query("max_sp") )
			ob->set( "spell_points", ob->query("max_sp") );
		ob->add( "talk_points", time*4 );
		if ( ob->query("talk_points") > ob->query("max_tp") )
			ob->set( "talk_points", ob->query("max_tp") );
		ob->add( "medication_resistance", -time*5 );
		if ( ob->query("medication_resistance") < 0 )
			ob->set( "medication_resistance", 0 );
		ob->set_temp("block_command", 0);
		tell_object( ob, "你一覺醒來, 感覺體力完全恢復了。\n" );
		tell_object( ob, "你打開房門走下樓\n\n" );
		ob->move_player(HERE"corridor2", "", "out");
		key = present( "copper key", ob);
		if ((key) && (base_name(key) == OBJ"tavern_key")) 
			key->remove();
		key = present( "silver card", ob);
		if ((key) && (base_name(key) == OBJ"silver_card")) 
			key->use_card();
		this_room->remove();
	}
}