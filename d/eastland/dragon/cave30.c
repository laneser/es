#include "../layuter.h"

inherit ROOM;

void create()
{
	::create();
	set_short("花園");
	set_long( @C_LONG_DESCRIPTION
這裡是一個花團錦簇的花園，這裡有非常多的奇花異草，是鄭大戶從世界各地移植過
來的，其中有一株數人高的食人樹，每天要□其一隻大象，也有數株純黑玫瑰聽說是園藝
大師章魚正心的傑作，這裡也有一個噴泉(fountain)。
C_LONG_DESCRIPTION
	);
set("item_desc",([
    "fountain":"這是一個乾枯的噴泉。\n"]));
	
	set("objects",([
	    "woman1":"/d/noden/nodania/monster/gardener"
	    ]));
	set( "light", 1 );
	set( "exits", ([
	    "west" : Lcave"cave29"
	]) );
	reset();
}

void init()
{
    add_action("do_enter","enter");
 }
 
int do_enter(string arg)
{ 
 if (!arg || arg!="fountain") return 0;
 tell_room(environment(this_player()),
         this_player()->query("c_name")+"進入噴泉中\n",this_player() );
 this_player()->move_player(Lcave"cave31","SNEAK");
 return 1;
 }
