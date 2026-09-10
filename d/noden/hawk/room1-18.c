#include "hawk.h"

inherit ROOM;

int hole;

void create()
{
        ::create();
        set_short("山谷");
        set_light(1);
        set_long( @LONG_DESCRIPTION
你身處在一個伸手不見五指的陰暗山谷底，周圍一片暗茫茫的，頭上
的樹不停的在滴水，腳下的腐泥也不斷的散發出噁心的沼氣，四周的蜘蛛
網堅軔的有如尼龍繩，完全封住了你的去路，你看了半天，還是不知道該
怎樣離開這個恐怖的地方，或許"Quit"會是你唯一的選擇，不想Quit的話
還是趕快在『四周』找找，看看有什麼方法可以離開這個鬼地方。
LONG_DESCRIPTION
);
        set("c_item_desc",([
                "tunnel":"@@to_tunnel"
                        ]) );
        set("objects", ([
                "bug" : MOB"spider"
                        ]) );

    reset();
}//end of creat

void init()
{
	call_out("report",1,this_object() );
        add_action("to_go","go");
        add_action("to_find","search");
        add_action("to_enter","enter");
}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

int to_go()
{
        if ( present("spider",this_object()) )
        {
           tell_object(this_player(),"蜘蛛張牙舞爪著，不讓你過去。\n");
           return 1;
        }
        tell_object(this_player(),"這裡沒有任何出路。\n");
        return 1;
}

string to_tunnel()
{
        if ((this_player()->query_temp("find_hole") == 1) && (hole == 1))
        {
                return "一個陰森潮溼的地洞，你要進去(enter)嗎？\n";
        }
        else
        {
                return "你想看什麼？\n";
        }
}

int to_find(string s)
{
        if (present("spider"))
        {
                tell_object(this_player(),
                        "蜘蛛張牙舞爪，你嚇得不敢亂動。\n");
                return 1;
        }

        else if (s != "everywhere")
        {
                tell_object(this_player(),
                        "你找了又找，並沒有發現任何東西。\n");
                return 1;
        }
        else
        {
                tell_object(this_player(),
                        "你到處找來找去，最後在東北角的大樹旁，找到"+
                        "一個小地道(tunnel)。\n");
                this_player()->set_temp("find_hole",1);
                hole = 1;
		this_player()->set_explore("noden#40");
                return 1;
        }
}

int to_enter(string s)
{
	if ((this_player()->query_temp("find_hole") == 1) && (hole == 1) && s == "tunnel")
        {
                tell_room(environment(this_player()),
                "你看到"+this_player()->query("c_name")+
                "像狗一樣鑽到洞裡去了。\n",
                this_player() );
                tell_object(this_player(),
                        "你一頭栽進洞裡，跑到另一個地方羅。\n");
                this_player()->move_player(HAWK"room1-1","SNEAK");
                return 1;
        }
        tell_object(this_player(),"你想進去那裡？詩摩爾的閨房嗎？\n");
        return 1;
}

void reset()
{
        ::reset();
        hole = 0;
}
