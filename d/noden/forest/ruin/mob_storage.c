#include "ruin.h"
inherit ROOM;

#define MIN_GARGOYLES 6

void create()
{
	::create();
	set("light", 0);
    set_short("地洞");
    set_long(@CLong
你向上一望, 洞口很小, 似乎這個洞穴很深。你很驚訝你竟然沒有受
傷, 拍拍身上的灰塵, 開始觀察四周... 這裡的佈置: 兩排古老的石雕像
、散亂倒在地上的石塊、僅餘半截立在地上的石柱群。和遺蹟入口簡直一
模一樣, 但是你感到有一些不太對勁... 你仔細一看... 嚇然發現: 「那
不是雕像, 是活生生的... 」
CLong
    );
    set("mob_storage", MIN_GARGOYLES);
  	reset();
}

void init()
{
	add_action("climb_up", "climb");
}

int climb_up(string arg)
{
	int skill;
	object player;
	if( !arg || !(arg == "out" || arg == "up") )
		return notify_fail("Climb what?\n");
	player = this_player();
    skill = player->query_skill("climbing");
    skill += 5;
    if( random(65) < skill ) {
      tell_object( player, "你小心翼翼的爬了出去。\n" );
      tell_room( environment(player),
        player->query("c_name")+"爬了出去。\n" , player );
      player->move_player( RUIN"entry", "SNEAK" );
      tell_room( environment(player),
        player->query("c_name")+"突然從地下鑽了出來。\n", player
      );
      player->set_explore("noden#18");
    } else {
      tell_object( player,"你嘗試著爬出去，結果又滑了下來。\n" );
      tell_room( environment(player),
        player->query("c_name")+"嘗試著爬出去，結果又滑了下來。\n" , player
      );
    }
    return 1;
}

int is_a_gargoyle(object mob)
{
	if( (string)mob->query("name") == "Gargoyle" ) return 1;
	return 0;
}

void reset()
{
	int i;
	object *gargoyles;
	gargoyles = filter_array(
		all_inventory(this_object()), "is_a_gargoyle", this_object() );
	for( i=sizeof(gargoyles); i<query("mob_storage"); i++ )
		new(MOB"gargoyle")->move(this_object());
	::reset();
}
