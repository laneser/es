inherit MONSTER;
#include "../hawk.h"
int help1 = 0;
void create()
{
        ::create();
        set_level(8);
        set_name( "tailor","裁縫師" );
        add("id",({"tailor"}) );
        set_short( "裁縫師" );
        set_long(@LONG
你看到一個年紀不輕的裁縫師，多年的工作經歷使得她對於縫紉工作架輕就熟，
不過你看她神色似乎不善，可能是順手的工具不見了，你如果能幫忙(help)她找回
她的東西，可能會對你滿有幫助的。
LONG
        );
        set( "inquiry", ([
                "help" : "@@help_me",
                "dry" : "@@dry_paper"]));
        set( "alignment", 100 );
        set( "gender","female" );
        set( "race","gnome" );
        set( "time_to_heal", 10 );
        set_natural_armor( 20, 12 );
        set_natural_weapon( 25 , 13 , 17 );
        set( "wealth/silver", 10 );
}

int dry_paper(object who)
{
        object paper1;
        if (this_player()->query_temp("help_tailor") == 0)
        {
                tell_object(this_player(),
                "你想把東西烘乾啊？要用熱的東西去烘啊。如果不會的話，我"+
                "可以幫你烘，但\n是你要先幫我(help)做點事。\n");
                return 0;
        }

        if (this_player()->query_temp("help_tailor") == 2)
        {
                tell_object(this_player(),
                "你要烘啥東西啊，小心不要燒掉了，還是我來幫你好了。\n");

                if (!present("paper",this_object()))
                {
                        tell_room(environment(),
                        "裁縫師說：你紙不給我的話，我可沒辦法幫你唷。\n",
                        this_object()
                                 );
                        return 1;
                }

                tell_room(environment(),
                        "裁縫師幫"+(string)this_player()->query("c_name")+
                        "把他手上的小紙片烘乾了。\n",this_object()
                         );
                paper1 = new(OBJ"paper1.c");
                paper1->move(this_object());
                command("give paper to "
                        +(string)this_player()->query("name"));
		this_player()->set_explore("noden#41");
                return 1;
        }
}

int help_me()
{
        if (this_player()->query_temp("help_tailor") == 2)
        {
                tell_object(this_player(),
                        "裁縫師說：為了感謝你幫我找到了我的熨斗，有什麼需要"+
                        "我幫忙的你就儘管說吧。\n" );
                return 1;
        }

        if (this_player()->query_temp("help_tailor") == 1)
        {
                if (!present("iron") )
                {
                        tell_object(this_player(),
                        "裁縫師說：非常謝謝你幫助我，請你把熨斗還給我吧。\n" );
                }
                else if (present("iron") )
                {
                        tell_object(this_player(),
                        "裁縫師拿起熨斗高興的叫: 『 啊~~~~我又可以回"+
                        "去做我的工作羅。』\n");
                        command ("kiss " +
                           (string)this_player()->query("name"));
                        this_player()->set_temp("help_poet",2);
                }
        return 1;
        }
	if (help1 == 1)
	{
		tell_object(this_player(),@LONG
裁縫師說：嗯，有個大有為的年輕人說要幫我找了，那就謝謝你的好意了。
LONG
		);
		return 1;
	}
		
        tell_object(this_player(),@LONG

裁縫師看了你一眼，說：
    很久以前啊，我曾經遺失了一個熨斗，不知道掉在哪裡，不過我猜有可能是
在一陣被山賊追趕的混亂中掉的。希望你能幫我找回來，如果找回來的話，有什
麼我能幫的上忙的，儘管開口吧。
LONG
        );
	help1 = 1;
        return 1;
}

