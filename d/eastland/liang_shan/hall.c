#include "takeda.h"

inherit ROOM;

void create()
{
	object hu;
	::create();
	set_short( "忠義廳" );
	set_long(
	"這裡就是忠義廳，一個非常廣大的大廳，地上鋪著一大片織錦的鮮紅\n"
	"地毯，給人一種溫暖舒適的感覺，大廳四周羅列著一百零八張紫檀交椅。\n"
	"梁山泊一百零八條好漢，經常在此商討大計或飲酒作樂。\n"
	);
	set( "light",1 );
        set( "c_item_desc",(["chair":
        "這是紫檀木作成的大椅子，鋪上厚厚的坐墊，看來極其氣派。\n"
        ]));
        set( "exits", ([
                "south"  : TROOM"path9",    
                "north"  : TROOM"yard9",
                "up" : TROOM"up_hall",
                "down" : TROOM"down_hall"
        
        ]) );
        hu = new(TMONSTER"huyang");
        hu->move(this_object());
        
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
if ( !present("hu") ){
   write (
   "你舒服的躺在紫檀交椅上，感覺人世的喧鬧離你而去\n");
   tell_room(this_object(),
   this_player()->query("c_cap_name")+"舒服的躺在紫檀交椅上，安詳的閉上了眼睛\n"
      ,this_player());
}
else {
   write (
   "正當你想坐下時，呼延灼一把抓起你，說道: 這不是你能坐的\n");
   tell_room(this_object(),
   this_player()->query("c_cap_name")+"想要坐下休息，但卻被呼延灼制止了．\n"
   ,this_player());
}
return 1;
}
int clean_up() { return 0; }
