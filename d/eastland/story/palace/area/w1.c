#include "../../story.h"

inherit SPALACE"RR";
inherit DOORS;
void create()
{
        ::create();
	set_short("天都大殿西側");
	set_long( @LONG
你立足之地是天都大殿的西側，大殿地面原是用整片翠精碧玉建成的，不但玉
質特佳，光明若鏡，毛髮可鑑。環顧殿內，琉璃天瓦，上下兩相對照，發出七彩旋
轉虹光；殿偏玉柱彩壁，左側一金門矗立，除此之外別無它物，雖然空間廣闊，卻
益發顯得莊嚴隆重，氣象萬千。
LONG
	);
        set("light",1);
        set("exits" , ([
           "east" : SPALACE"center",
           "west" : SPALACE"palace1",
          "north" : SPALACE"n1w1",
          "south" : SPALACE"s1w1",
        ]) );
        create_door( "west","east" ,([
          "keyword" : ({ "jade door", "door" }),
          "name" : "jade door",
          "c_name" : "玉門",
          "c_desc" : "一個白玉做的大門，上面各有兩個碗大的雀環。\n",
          "status" : "closed"
        ]) );
        set("pre_exit_func",([
          "west":"can_pass"]));
        reset();
}
int can_pass()
{
   if ( this_player()->query("palace_war") ) return 1; 
   return 0;
}   
