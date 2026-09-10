//#pragma save_binary

// An example bank which inherits the standard bank object. Like the shop,
// the bank should have ::create as the first call in its own create.
// This bank has a janitor. Bringing him a shrubbery solves the example
// quest in the default mudlib.

#include "farwind.h"
#include <money.h>
#include <move.h>

inherit "/std/bank";
inherit ROOM;

void create()
{
	room::create();
	reset();
	set_short( "銀行");
	set_long(@C_LONG
歡迎來到遠風鎮引以為傲的銀行。在這裡你只要花費 25 塊金幣就可以
開(open)一個戶頭，接受銀行提供的服務。銀行行員會給你一張儲金卡，你
可以用這張卡在這裡或各地的分行存款(deposit)及提款(withdraw)。 銀行
角落裡有一座樓梯通往二樓的錢幣兌換中心。
C_LONG
	);
	set("light", 1);
	set("exits", ([ 
		"west" : FARWIND"nmain",
		"up" : FARWIND"exchange"
	]) );
	set("objects", ([ 
		"janitor" : FARWIND"monster/taxman" ]) );
	reset();
}
