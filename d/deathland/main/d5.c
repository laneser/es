
#include "../echobomber.h"

inherit "/std/room/waterroom";

void create()
{
	::create();
	set_short("海底廢墟");
	set_long( @LONG_DESCRIPTION
當你潛入海底的最深處時,你發現一處非常破舊的廢墟(ruin),塌陷的石
柱及荒廢的房屋已經被海水侵蝕的不成樣子.一塊板子(board)放置在廢墟的
入口,而且仍然相當的清晰,並未受到海水的侵蝕.
LONG_DESCRIPTION
	);
set("item_desc",([
    "board":@BOARD
----------------------------------------------------------------
愚蠢的人們,不要試著跟我的主人 Firer 作對,看看這群躺在海底的人
假如你激怒了我偉大的主人,他們將是你的榜樣.
                  ------Archmage Romus-----
----------------------------------------------------------------
BOARD
   ,"ruin":@RUINS
一處非常破舊的廢墟.
RUINS
    ]) );
	set( "light", 0 );
set("exits",(["up":Deathland"/main/d4"]));
}
void init()
{
   add_action("to_enter_ruin","enter");
}

int to_enter_ruin(string str)
{

   if (!str||str!="ruin") {
    write("Enter what?\n"); return 1;
     }
  write("Not open yet,please wait a monent\n");    
  // this_player()->move_player(Ruins"/r1",
  // "SNEAK","");
   return 1;
}
