#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(12);
	set_name( "teacher", "私塾教師" );
	set_short( "私塾教師" );
	set_long(@C_LONG
一位正在課堂上認真教書的老師。他長得微胖，一副小眼鏡，戴個小帽子，口□橫
飛，表情相當嚴肅。
C_LONG
        );
	set( "gender", "male" );
        set( "unit","位");
        set_natural_armor(60,0); 
        set_natural_weapon( 17,9,20 );
        set( "inquiry", ([
             "special_things":"@@ask_things",
        ]) );
}
void ask_things(object asker)
{
tell_room(environment(),@LONG
                            
私塾老師說道：特別的東西？我生平見過最特別東西是顆水晶玻璃球(crystal_glass)
             ，不但大的出奇，又能在黑暗中綻放光芒。
                                      　　
LONG
     );
}
