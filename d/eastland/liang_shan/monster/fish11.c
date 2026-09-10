
#include "mudlib.h"

inherit MONSTER ;

void create ()
{
        ::create();
        set_level(1);
        set_name( "little fish", "漂亮小魚" );
        set_short("漂亮小魚");
        set("unit","條");
        set_long(
@C_LONG
    這是一條非常可愛的小魚，它正好奇的看著你。
C_LONG
);
        set ("gender", "female");
        set( "likefish",1);
        set( "alignment", 300 );
        set_natural_weapon( 2, 1, 3 );

}
void init()
{
        add_action( "kill_me", "kill");
}
int accept_item(object me,object item)
{
	string name;
	name=(string)item->query("name");
     if ( !name || ( name != "crumb") ) return 1;
{
     tell_object(me,
@CRUMB
小魚開始快樂的吃著麵包屑.......
CRUMB
	);
		item->remove();
		this_player()->set_temp("feed_fish",1);
        return 1;
}
}