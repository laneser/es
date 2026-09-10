#include "../island.h"

inherit IOBJ+"drink.c";

void create()
{
    ::create();
    set_name("Loquat paste","老桐閣川貝枇杷膏");
    set("id", ({ "paste","herb" }) ) ;
    set_short("老桐閣川貝枇杷膏");
    set_long(@C_LONG
這是老桐閣密煉的極品枇杷膏，專治喉嚨沙啞哦！！
C_LONG
             );    
    set("container",0) ;
    set("tp",100);
    set("value",({ 10,"gold" }) ) ;
    set("amount",0) ;
    set("c_succ","你日夜殺戮，瘋狂喊叫，喝下這川貝枇杷膏之後，使你覺得喉嚨好多了。\n") ;
    set("c_osucc","$CN灌下一瓶川貝枇杷膏之後，又把瓶子給吞了下去，你看得都傻眼了。\n") ;
}
