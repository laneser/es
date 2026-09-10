#include "../oldcat.h"

inherit "/d/eastland/volcano/temple/in_well";

void create()
{
	::create();
	set_short( "井中" );
	set_long(
@LONG
你正處在這口井的井水中。除了水面上傳來微弱的光線以外，你的四周全都
被黑暗和寂靜籠罩，但往下看去，你仍可以隱約查覺到有一點光線從那裡傳來。
LONG
	);
	set( "exits", ([
             "up":OTEMP"well1",
	     "down" : OTEMP"well3",
	]) );
        set("pre_exit_func",([
            "up":"to_up",
            ]) );
        reset();
}

int to_up()
{
  this_player()->delete_temp("likefish");
  return 0;
}
