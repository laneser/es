#include "irc.h"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Midair","半空中" );
    set_long( @LONG
LONG
	,@C_LONG
C_LONG
    );
}
 
void init()
{
    write(can_read_chinese()?
		"\nWeeeeeeeeeeeeee..............\n"+
		"你看到底下小小的樹, 河流漸漸接近你...\n"+
		"wowowowowowow.....\n越來越近了!!!\n"+
		"WHAM!!!!!\n突然你被一股力量拉住而停了下來。\n":
		"\nWeeeeeeeeee......\n"+
		"You see little trees and rivers below you...\n"+
		"wowowowowowow...\nIt's getting closer!!!\n"+
		"WHAM!\nThe sudden stop almost tear you into half.\n");
    call_out("hanging", 10, this_player());
    add_action("look_here","look");
}
 
int look_here(string str)
{
    if( str ) return 0;
    write(can_read_chinese()?
        "\n你往下看, 深藍色的河水急速的流過谷底。往上看, 懸崖離你還有\n"+
        "一段距離。你... 現在「掛」在半空中。\n":
        "\nYou are hanging in mid-air. Above you is the cliff and below\n"+
        "you, the dark blue river runs through the valley.\n"
    );
    return 1;
}
 
void hanging(object player)
{
	if( !player ) return;
    tell_object(player, can_read_chinese(player)?
    	"你覺得你「掛」在這裡太久, 該上去了.... \n":
    	"You think you are here long enough, time to climb back!\n"
   	);
    tell_object( player, can_read_chinese(player)?
    	"你抓緊繩子順著崖壁爬了上去。\n":
    	"You climb up along the cliff wall.\n"
   	);
    player->move_player(IRC"deck_3.c","SNEAK");
    tell_room(environment(this_player()),({
    	player->query("cap_name")+" climbs up.\n",
    	player->query("c_cap_name")+"從崖下爬了上來。\n" }),player
    );
    find_object(IRC"deck_3")->set("busy",0);
}

