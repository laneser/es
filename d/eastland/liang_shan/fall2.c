#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "半空中" );
	set_long(
	"你正在半空中，不停的向下墜落，往腳下看去，無邊的黑暗正如巨獸\n"
	"張開大嘴向你迎面而來，你意識到這對你來說，可能是一個悲慘的結束\n"
	);
        set( "no_monster",1);
        set( "pre_exit_func", ([
                "down" : "check_fall"
        ])) ;        
        set( "exits", ([
                "down" : TROOM"jail1"
        ]) );
}
int recover(object player)
{
write ("\n你終於回復神志，張開眼睛 ...\n\n");
player->set_temp("block_command",0);
player->move_player( TROOM"jail1","SNEAK");
tell_room(TROOM"jail1",
"你看到一個人從天而降，跌到了地牢裡，你覺得不那麼寂寞了.......\n",player);
return 1;
}
int check_fall()
{
write(
"\n你不停的向漆黑的空間落去，突然碰的一聲巨響，你終於落到了地面。巨大的\n"
"撞擊不但使你受了重傷，還使你癱瘓在地，無法動彈......\n\n");
this_player()->set_temp("block_command",1);
call_out("recover",40,this_player());
this_player()->add("hit_points",-(int)this_player()->query("hit_points")/3);
return 1;
}
int clean_up() { return 0; }