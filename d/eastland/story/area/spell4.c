#include "../story.h"

inherit ROOM;
int have_head=1;
void create()
{
        ::create();
	set_short("解池");
	set_long(@LONG
異於前面所走過的洞穴，你發現這裡的空氣非常乾燥，並且溫暖極了！相傳當
年黃帝大戰蚩尤，蚩尤打了個敗仗因此被砍下頭顱，身首異處，一分為二，其中一
部份被丟在這裡。解池又叫鹽池，池裡的鹽水呈紅色，人們都說那是蚩尤的血流積
而成的。在解池旁有一個墳墓，當年黃帝怕蚩尤死後作怪，因此在這裡修了個墳墓
加了某種禁咒，並在來這裡的途中設下幾隻鎮守這裡的怪物，以防被盜。
LONG
	);
        set( "exit_suppress", ({
          "su"}) );
	set("exits", ([
          "southup" : SAREA"spell3",
               "su" : SAREA"spell3"
        ]) );
	reset();
}
void init()
{
   add_action("do_auction","auction");
   add_action("do_search","search");
}
int do_search(string arg)
{
   object head; 
   if ( !have_head ) return 0;
   have_head=0;
   write("你找了找，發現旁邊墳墓裡埋了一具□體！");
   if ( ( this_player()->query_perm_stat("str") ) < 10 ) {
     write("可惜你力量不夠，無法把它挖起來。\n");
     return 1;
   }
   write("於是你把它挖起來。\n");
   head=new(SITEM"head1");
   head->move(this_object());
   call_out("recover",900);
   return 1;
}
void recover()
{
   have_head=1;
}
int do_auction(string arg)
{
   write("\n這裡忽然起了陣咒語，令你無法專注於拍賣動作！\n\n");
   return 1;
}
