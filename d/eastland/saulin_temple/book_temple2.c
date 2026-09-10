//File: book_temple2.c 少林寺藏經樓

#include "saulin_temple.h"

inherit ROOM;

int pull=0;

void create()
{
       ::create();
       set_short("少林寺藏經樓");
       set_long( @C_LONG_DESC
你走進嚮往已久的藏經閣，閣內寂寂無聲，四面牆壁都是直抵屋頂的書架，
每一格架上都貼了一張小條，上面寫的是彎彎曲曲的怪字，想必是梵文，看來
想從這個浩瀚書海中找到少林寺的武功密笈真是難上加難。右方書架正中有兩
扇長窗(windows)，可是卻沒有光線射進來，想必是被書籍給堵死了。
C_LONG_DESC
       );
	   set("light",1);
	set("objects",([ "monk" : SAULIN_MONSTER"shu_ju" ,]));
       set("exits",([
         "out" : SAULIN"book_temple1",
       ]) );
       reset();
       set("item_desc",([ "windows":
@C_LONG
    這是兩扇長木窗，雖然被擦拭的很乾淨，但是卻沒有光線透進來。
C_LONG
       ]));
}

void init()
{
     add_action("pull_window","pull");
     add_action("climb_ladder","climb");
}

int pull_window(string str)
{
    if( !str || str != "windows" )
       return notify_fail(can_read_chinese()?
         "你要拉什麼?\n" :
         "What do you want to pull ?\n" );
if (present("shu ju",this_object()))
{
    tell_object(this_player(), can_read_chinese() ? @C_OPEN
你正想用力把窗子拉開，虛竹走了過來阻止你，他合十道：為了本閣藏書
的保存，這個窗子是開不得的，請不要把它打開。
C_OPEN
: "You want to pull the window but shu ju stop you.\n"
    );
	return 1;
}

    tell_object(this_player(),@C_LONG
你用力把窗子一拉，整面窗子突然向你移動過來，現出書架後的一架木梯
，木梯很乾淨，好像常有人出入，或許你可以爬(climb)上去看看。
C_LONG
    );
    pull = 1;
    return 1;
}
                   
int climb_ladder(string str)
{
      if( !str || str != "ladder" || !pull )
        return notify_fail("你要爬什麼?\n");
       this_player()->move_player(SAULIN"book_temple3");
       return 1;
}
