#include <mudlib.h>;
#include <config.h>;

inherit OBJECT;
inherit DAEMON ;

int read_me = 0;

void create()
{
        seteuid(getuid());
        set("id",({"story"}));
        set_name("story","東方故事集");
        set_short("東方故事集");
        set_long(
                "這是一本記載東方大陸的古老傳說的故事集。\n");
        set( "weight", 30 );
        set("unit","本");
        set("value",({20,"silver"}) );
}

void init()
{
  add_action("read_me", "read");
}

int read_me (string str)
{
        object who,monster;
        who=this_player();
        
        if (!str)        
            return notify_fail("你要讀什麼東東呀?\n");
                 
        if (str!="story")     
            return 0;

        if (!read_me)
{
        say(who->query("c_name")
                +"正在讀一本書，書名是「東方故事集」。\n");
        tell_object(who,@LONG
書上記載著:
傳說在海的那一邊有個古老的國家，名叫東方大國。在那裡的人們都錦衣玉食，
遍地成金.......

咦? 後面的書頁都不見了, 好像是被蟲給蛀光了呢!
LONG
        );
        if ( (int)who->query_quest_level("bookbug") > 0 )
        return 1;

        tell_object(who,@LONG
當你翻閱故事集時, 忽然一隻肥嘟嘟的書蟲從書本中掉了出來!
LONG);
        monster = new( "/d/noden/farwind/monster/bookbug" );
        monster->move(environment(who));
        who->set_temp("findbug",1);
        read_me = 1;
        return 1;
}
        tell_object(who,@LONG
你仔細的閱讀書上所寫的字，企圖辨認上面所寫的字，不過實在
是被蟲蛀的太嚴重了....你越想越生氣，實在想把可惡的蛀書蟲
找出來一腳踩死洩忿。
LONG
        );
        return 1;
}

