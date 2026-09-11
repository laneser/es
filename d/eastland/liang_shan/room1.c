#include "takeda.h"

inherit ROOM;

void create()
{
       object song;
	::create();
	set_short( "小書房" );
	set_long(
	"這是一間小小的書房，窗明幾靜，樸素典雅，一張古意盎然的紅木書桌，\n"
	"吸引了你的目光，上面擺著一座小小的香爐，幾本善本書整齊的堆放在桌上\n"
	"，可見主人相當的愛惜書本。一個男子正坐在桌前，神情肅穆，若有所思。\n"
	);
        set( "light",1);
        set( "exits", ([
                "west" : TROOM"yard3"
        ]) );
        song = new(TMONSTER"song");
        song->move(this_object());
        set( "objects",([
                "cap1":TMONSTER"captain",
                "cap2":TMONSTER"captain",
                "cap3":TMONSTER"captain"
                ]));

        
        reset();
}
void init()
{
  if(this_player()) this_player()->set_explore("eastland#21");
}
int clean_up() { return 0; }
