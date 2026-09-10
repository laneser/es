#include <takeda.h>

inherit ROOM;

void create()
{
	object ling;
	::create();
	set_short( "點將臺" );
	set_long(
	"這裡是梁山泊的點將臺，站在這裡對前方的演武場，一覽無遺，許多\n"
	"人正在臺下操練陣法。輝煌的旗幟簇擁著一座四丈高臺，臺上煙雲裊繞，\n"
	"如在雲中。臺上一具千斤巨鼎，裊繞的煙雲，就是從鼎中飄出來的，鼎旁\n"
	"羅列著三十六張紫檀交椅。一個全身戎裝的中年人，神情威嚴，卓立在銅\n"
	"鼎前，正注視著臺下。\n"
	);
	set( "light",1 );
        set( "c_item_desc",(["chair":
        "正當你端詳這些交椅時，林沖冷冷的瞪了你一眼，你急忙將目光轉向臺下。\n"
        ]));
        set_outside("eastland");
        set( "exits", ([
                "south"  : TROOM"plaza5",    
                "north"  : TROOM"path5",
        ]) );
        ling = new(TMONSTER"lin");
        ling->move(this_object());
        set( "objects",([
                "bandit":TMONSTER"small_bandit",
        ]) );        
        reset();
}
void init()
{
add_action("do_sit","sit");
}
int do_sit(string arg)
{
if ( !arg || arg!="chair") return notify_fail(
"坐什麼?\n");
if ( ! present("lin") ){
   write (
   "你舒服的躺在紫檀交椅上，感覺人世的喧鬧離你而去\n");
   tell_room(this_object(),
   this_player()->query("c_cap_name")+"舒服的躺在紫檀交椅上，安詳的閉上了眼睛\n"
      ,this_player());
}
else {
   write (
   "正當你想坐下時，林沖伸出丈八蛇矛抵住你後心，說道: 這不是你能坐的\n");
   tell_room(this_object(),
   this_player()->query("c_cap_name")+"想要坐下休息，但卻被林沖制止了．\n"
   ,this_player());
}
return 1;
}
int clean_up() { return 0; }
