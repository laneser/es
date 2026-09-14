#include <mudlib.h>
#include "../legend.h"
inherit LAKE"in_lake";

void create()
{
    ::create();
    set_short( "lake7", "湖中" );
    set_long(@C_LONG
你走在湖中,腳底下是三丈來許的『水板』而兩旁都是千丈高的水牆。兩旁水
聲轟隆隆地快要把你的耳膜震破, 挾帶著漫天的水氣,不禁把你的全身都給濡溼了
。 水牆裡一些七彩斑斕的魚兒正悠閒地追逐玩耍,有時遊近你身旁,一點也不怕你
的樣子,你不禁伸手想要穿過水牆去觸摸它們,卻似乎有股力量阻擋著你。
C_LONG
    );
    set( "exit_suppress", ({
      "south","north" }) );
    set( "exits", ([
      "north":LAKE"lake3",
      "east":LAKE"village1",
      "west":LAKE"lake2",
      "south":LAKE"lake1" 
    ]) );
    reset();
}
