#include "../hawk.h"
inherit MONSTER;
int thank;
void create()
{
        ::create();
        set_level(12);
        set_name( "smith","神秘老鐵匠" );
        add("id",({"smith"}) );
        set_short( "神秘老鐵匠" );
        set_long(@LONG
一個古怪的老頭，在這個打鐵鋪工作很久了，臉上被火燻的黑黝黝的，強壯的
肌肉大概也是長年的工作所鍛練出來的。
LONG
        );
        set( "inquiry", ([
                "god": "@@story",
                "armor" : "@@god_armor"]));
        set( "alignment", 100 );
        set( "gender","male" );
        set( "race","dwarf" );
        set_natural_armor( 30, 22 );
        set_natural_weapon( 25 , 13 , 17 );
        set( "wealth/silver", 20 );
}

void init()
{
        add_action("to_thank","bow");
}

int story()
{
        tell_object(this_player(),@LONG
    老鐵匠自言自語道：諸神都在天上享福，凡人受苦受難他們又哪有辦法知
道呢？不過如果有人能找齊他們的信物，那麼我也有辦法為他打造出一件前所
未見的完美裝備(armor)。
LONG
        );
        return 1;
}

int god_armor()
{
        if ((this_player()->query_temp("smore_armor/arcold") == 1)
         && (this_player()->query_temp("smore_armor/elder") == 1)
         && (this_player()->query_temp("smore_armor/las") == 1)
         && (this_player()->query_temp("smore_armor/knight") == 1)
         && (this_player()->query_temp("smore_armor/minister") == 1))
        {
           if (
                (!present("zeus amulet",this_object()))
              ||(!present("spark leggings",this_object()))
              ||(!present("diamond ring",this_object()))
              ||(!present("hades veil",this_object()))
              ||(!present("jupiter armband",this_object()) )
              )
                {
                        tell_object(this_player(),@LONG
老鐵匠懶洋洋的說：你不給我材料我哪有辦法給你好東西用....笨....
LONG
                        );
                        return 1;
                }
                else
                {
                        tell_object(this_player(),@LONG
老鐵匠抬起頭，看看你，喃喃的說：
罷了，或許也該是讓眾人瞭解諸神的意志的時候了....。
老鐵匠深吸一口氣，拿起材料，一陣叮叮噹噹，火焰越來越熾熱，只見你
臉上越脹越紅，豆珠般大的汗水如潮水般湧出....你受不了高熱而暈倒了。
LONG
                        );
                        this_player()->set_temp("block_command",1);
                        call_out("finish",10,this_player() );
                        return 1;
        }
                }
        else
                {
                        tell_object(this_player(),"老鐵匠理都不理你。\n");
                        return 1;
                }
        return 1;
}

int finish()
{
        tell_object(this_player(),@LONG

　　過了良久良久，你清醒了過來，看到老鐵匠手中拿著一襲精美絕倫的東西
，有著多年戰鬥經驗的你，竟也說不出那是盔甲、盾牌，還是什麼。你只知道
，這件泛著金黃色光揮的防具一定不是人間凡人所能擁有的，或許就是那拿著
神賜之寶保衛人間，傳說中的龍戰士？
LONG
        );
        this_player()->set_temp("block_command",0);
        call_out("finish2",5,this_player() );
        return 1;
}

int finish2()
{
        tell_object(this_player(),@LONG
　　扯了半天，老鐵匠如果不給你你也是沒戲唱，看來你得要好好"感謝"他一
下，讓他肯把東西交給你。
LONG
        );
        this_player()->set_temp("thank_smith",1);
        return 1;
}

int to_thank(string str)
{
        object obj;
        if (str != "smith" || this_player()->query_temp("thank_smith") != 1)
                return 0;
        tell_object(this_player(),@LONG
　　你必恭必敬的向老鐵匠打躬作揖，老鐵匠終於還是把這件『諸神的禮
贊』交給了你。
LONG
        );
        obj = new(ARMOR"gift");
        obj -> move(this_object() );
        command("give gift to " + this_player()->query("name") );
        return 1;
}

