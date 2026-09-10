#include <mudlib.h>

inherit OBJECT;

void init()
{
	add_action( "hold_tail", "hold" );
}

void create()
{
        set_name( "fox's tail", "狐狸尾巴" );
        add( "id", ({ "tail" }) );
        set_short( "狐狸尾巴" );
        set_long(@C_LONG
這是一條蓬蓬鬆鬆的狐狸尾巴，據說握著(hold)千年狐狸精的尾巴可以使人
暫時隱身，不知道是真是假？
C_LONG
		);
   		set("unit","條");
   		set("weight", 10);
   		set("value",({10, "silver"}) );
        set("no_sale", 1 );
}

int hold_tail(string arg)
{
	if( !arg || arg != "tail" ) return 0;
    if ((string)environment(this_player())->query("short")=="藏經閣前" ) {
    	tell_object(this_player(), 
    		"你拿出狐狸尾巴舉在胸前，那些僧人們好像什麼都沒看見。\n" 
        );
        this_player()->set_temp("book_quest/step",1);
	} else
        tell_object(this_player(), 
         	"你把狐狸尾巴舉在胸前，旁邊路過的人都掩著嘴偷笑。\n"
        );
	return 1;

}
