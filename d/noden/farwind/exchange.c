//#pragma save_binary

// A basic coin exchange which inherits the standard coin exchange object.
// Needs to call ::create() like the shop does.

#include "farwind.h"
#include <money.h>

inherit "/std/exchange";
inherit ROOM;

void create()
{
	room::create() ;
	set("light",1) ;
    set_short( "錢幣兌換中心");
	set_long(@C_LONG
你現在位於遠風鎮遠近馳名的錢幣兌換中心。 在這裡你可以把身上的
各種錢幣換成金幣、銀幣、銅幣等。只要下 convert [數量] [甲錢幣] to
[乙錢幣] 命令就可以把指定數量的甲錢幣換成等值的乙錢幣。如果你不指
定 [數量]，就會把你身上所有的甲錢幣換成乙錢幣。
在左方的牆上有個錢幣兌換表(sign)。
C_LONG
                );
	set ("exits", ([ "down" : FARWIND"bank" ]) );
   set( "c_item_desc", ([
          "sign" : 
@LONG
    目前世面上流通的錢幣只有四種:
----------------------------------------------------------
  一. 白金幣(platinum): 一枚白金幣可兌換十枚金幣.
  二. 金幣(gold): 一枚金幣可兌換十枚銀幣.
  三. 銀幣(silver): 一枚銀幣可兌換十枚銅幣.
  四. 銅幣(copper).
----------------------------------------------------------
LONG
     ]) );
}
