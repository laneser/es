#include "../echobomber.h"
#include <money.h>

inherit SHOP;

void create()
{
	::create() ;
	set("light", 1) ;
	set_short( "陰暗的商店" );
	set_long( @C_LONG
當你走進這個帳蓬裡,你發覺這裡應該是一間商店,然而你卻看不到人,因為店主整
個人藏在櫃檯的後面.只有他看得到你而你完全看不到他.而牆上點燃著一把火炬,微弱
的火光更使這裡顯得恐怖.讓人感覺到你好像進入黑店一樣.
C_LONG
);
	set( "exits", ([ 
	  "out" : Deathland"/main/d11", 
	]) );
	::reset();
}
void init()
{
   ::init();
   add_action("to_sell","sell");
}

int to_sell(string str)
{
    write("老闆露出邪惡的笑容,說: 到這裡來賣東西,嗯......\n");
    if ( (int)this_player()->query("alignment") >= 0 ) {
      write("我想好人應該幫助我這個窮人吧!\n");
	  // rating 1,3 mean 1/3 By Kyoko.
      this_object()->set("rating", ({ 1, 3 }) );
    } else {
      write("邪惡的傢伙,我喜歡,但是在商言商,所以...\n");
      this_object()->set("rating", ({ 2, 5 }) );   
    }
    return ::sell(str);
}
