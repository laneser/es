
#include "hawk.h"

inherit ROOM;
int ring;
void create()
{
        ::create();
        set_short("墓穴");
	set("light",1);
        set_long( @LONG_DESCRIPTION
這顯然是一個匆匆完成的墓穴，不過依稀看得出來這個墓穴的主人應該是
一個精擅武藝的人，因為四周的牆壁旁放滿了各式各樣的武器，有劍(sword)
，有長槍(lance)，有巨斧(axe)，還有一面體積相當龐大的盾牌。想到一代英
雄就如此草草埋在這種荒郊野地，你不禁感到人事無常。
LONG_DESCRIPTION
        );

set("c_item_desc",([
        "lance":" 這是一把青色的長槍，槍柄上還有不少圖樣。\n",
        "axe":" 這是一把黑色的巨斧，大概只有巨人才有辦法拿的動。\n",
        "shield":"這面盾牌體積更是驚人，躲下兩個人大概是不成問題。\n",
        "sword":" 這是一把生了一堆鐵鏽的巨劍。\n",
                ]) );
	set( "exits", ([
		"out":"/d/noden/2,5.noden" ]) );
        reset();
}//end of creat

void init()
{
        add_action("to_search","search");
        add_action("to_pray","pray");
}

int to_search(string str)
{
        object obj;
        if ((str != "shield" && str != "盾牌") || ring == 0)
                return notify_fail( "你很努力的找來找去，不過沒有啥收穫。\n");
        tell_object(this_player(),
                "哇... 你找到了一枚淡綠色的戒子。\n");
	obj = new(OBJ"ring");
        obj->move(this_object());
        this_player()->set_temp("find_ring",1);
        ring = 0;
        return 1;
}

int to_pray()
{
        if (this_player()->query_temp("smore_box") == 5)
        {
                tell_room(environment(this_player()),
                        this_player()->query("c_name") +
                        "虔誠的跪在墓前，希望亡魂能夠安息。\n"
                ,this_player() );
                tell_object(this_player(),@LONG
你彷佛看到墓裡飄起一股淡淡的白霧，幻化成一位英武的勇士的身影，
他對著你微笑，然後就飄向天空消失不見了。
你聽到天空傳來一陣雄壯而溫和的聲音：謝謝你，勇士，請你告訴柏妮
絲我對她永恆的眷戀。
LONG
                );
                this_player()->set_temp("smore_box",6);
       }

        return 1;
}

void reset()
{
        ::reset();
        ring = 1;
}
