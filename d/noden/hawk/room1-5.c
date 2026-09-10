//room1-5.c
#include "hawk.h"
inherit ROOM;
int moves;
void create()
{
        ::create();
        set_short("石板小徑");
        set_light(1);
        set_long( @LONG_DESCRIPTION
走到這邊，突然你發現到地上已經鋪上了石板，走起來舒適多了，而且
慢慢的視野也越來越好。不過你還是搞不清剛剛所聽到的那些奇怪的聲音是
從哪裡傳來，可能要再往前走段路才能弄明白吧。
    小徑兩旁茂密的森林(forest)裡，傳來一陣陣森林特有的芳香，讓你感
到心曠神怡。
LONG_DESCRIPTION
        );
        set( "exits", ([
                "south" : HAWK"room1-6",
                "northwest" : HAWK"room1-4",
                     ]) );
        set("c_item_desc",([
                "forest":"@@to_forest",
                "skull":"@@to_skull",
                "ball":"@@to_ball"
                ]) );
        set("search_desc",([
                "forest":"@@to_search_forest",
                "skull":"@@to_search_skull"
                        ]) );
        reset();
}//end of creat

void init()
{
        add_action("to_move","move");
        add_action("to_touch","touch");
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="south" || str=="northwest" )
                return 0;
        write("啊! 不好....\n\n");
        tell_room(environment(this_player()),
                "你看到有人失足了!\n",this_player());
        this_player()->receive_damage(70);
        this_player()->move_player(HAWK"room1-18","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "從高聳的絕壁上摔下來!\n"+
                "竟然沒死! 真是命大啊!\n",this_player());
        return 1;
}

string to_skull()
{
        if (moves == 0) return "這裡沒有這樣東西。\n";
        return "一棵深褐色的骷髏頭, 看來年代已經相當久遠了。\n";
}

string to_ball()
{
        if (moves < 2) return "這裡沒有這樣東西。\n";
        return "一棵泛著神秘光芒的水晶球, 不斷的吸引你去觸摸(touch)它。\n";
}

string to_search_skull()
{
        if (moves == 0)
        {
        return "啥..? 啥..? 你要找啥...?\n";
        }
        else if (moves == 1)
        {
        moves = 2;
        return "這骷髏頭下面好像有點東西,不過你可能要先移開(move)"+
               "它, 才能看得更仔細。\n";
        }
        else if (moves > 1)
        {
        return "再多找也是沒有用的, 省點力氣吧。\n";
        }
}

string to_search_forest()
{
        if ((moves == 0) || (moves == 1))
        {
        moves = 1;
        return "哇！你在森林的深處找到一顆骷髏頭(skull)\n" ;
        }
        else
        {
        return "你再找了找, 不過沒啥新發現\n";
        }
}

int to_touch(string s)
{
        if ((!s) || (s!="ball") || (moves != 3 ))
                return notify_fail("亂摸亂摸，小心下次被路上小姐告性騷擾喔\n");
        tell_object(this_player(),
                "你摸呀摸，摸呀摸，摸了半天，也沒發生啥事，覺得有"+
                "一股受騙了的感覺。\n");
        this_player()->set_temp("touch_ball",1);
        return 1;
}

string to_forest()
{
        return "一片茂密的森林, 但不知怎的, 你總是覺得有一股詭異的氣氛籠罩
在這片森林。你靠近森林, 隱隱約約感受到一股血腥的味道, 很多樹
幹上也有不少兵器殺伐所留下的痕跡, 你猜在這邊一定曾有過一場大
戰。\n";

}

int to_move(string str)
{
        if ((!str) || (str!="skull") || (moves == 0))
        {
                tell_object(this_player(),
                        "....亂動亂動會掉到山下去喔。\n");
                return 1;
        }

        if (moves == 1)
        {
                tell_object(this_player(),
                        "呃....你想了想，還是決定不要亂動這個骷髏頭比較妥當。\n");
                return 1;
        }

        if (moves == 2)
        {
                moves = 3;
                tell_object(this_player(),
                        "你輕輕的把骷髏頭移開..哇..你看到一個閃"+
                        "爍著神秘光芒的水晶球(ball)\n");
                tell_room(environment(this_player()),
                        "你看到"+(string)this_player()->query("c_name")+
                        "找到了一個水晶球!\n",this_player());

                return 1;
        }

        if (moves == 3)
        {
        tell_object(this_player(),"你可以不用再移了。\n");
        }
        return 1;
}

void reset()
{
        ::reset();
        moves = 0;
}
