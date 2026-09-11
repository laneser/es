#include "mumar.h"
inherit ROOM;
 
void create()
{
        ::create();
  set_short("御風樓");
  set_long( @CLong
你走進了一間極為華麗的房間，四周的牆上掛滿了鑲滿寶石的刀劍，地上則鋪著
一件帶著虎頭的虎皮。一張純金的座椅放置在北邊的窗前，椅把上則放著一隻象牙雕
的望遠鏡。高高的天花板上掛著一盞琉璃燈，照亮整個房間。角落有個梯子，可以通
往樓下。
CLong
);
set("light",1);
set( "pre_exit_func", ([ "east" : "check_button" ]) );
set("exits",([
               "east":MUMAR"stage07",
               "down":MUMAR"stage02"
             ]));
set("objects",([
               "general":MOB"lee"]) );
reset();
}
int check_button()
{
  if( wizardp(this_player()) || this_player()->query_temp("give_button") ) return 0;
  else {
        tell_object(this_player(),
                    "不知道這是什麼保全的設計，不過你就是走不過去。\n" );
        return 1;
       }
}
