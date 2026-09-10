#include "hawk.h"

inherit ROOM;
int be_move;
void create()
{
        ::create();
        set_short("絕壁");
        set_long(@LONG
你延著小路踩著碎石來到了這塊光禿禿的石地上。東邊有塊顏色深褐的
怪石(rock)，兀立在旁跟其他的巖塊看起來很不搭調，北邊及南邊的雜
草叢生，環繞著陡峭的絕壁而生(precipice) ，遠風吹來陣陣的山嵐，
可是你感覺到的不是清爽，而是一股不寒而慄。不知哪兒傳來細微的人
聲獸語，可是你仔細的環顧四周都沒有發現生物的蹤跡。在這種可怕的
地方，如果你亂走的話，可能會失足落崖。
LONG
);

        set_outside("noden");
        set("c_item_desc",([
                "rock":"@@to_rock",
                "lever":"@@to_lever",
                "precipice":" 深不見底的峭壁, 要是一個不小心摔下去, 大概小命就沒了。\n"
                                ]) );

        set("search_desc",([
                "rock":"@@to_search_rock",
                        ]) );
        set("exits",([
                "southwest" : HAWK"room1-1"
                        ]) );
        reset();
}

void init()
{
        add_action("to_move","move");
        add_action("to_pull","pull");
        add_action("to_bottom","go");
}

int to_bottom(string str)
{
        if (!str || str=="southwest" )
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

int to_pull(string str)
{
        if ((!str) ||(str!="lever") || (be_move<2) )
        return notify_fail("要拉麵回家去拉啦!\n");
        tell_object(this_player(),
                "你用力的拉下扳杆..."+
                "忽然你腳下的石板震動起來......\n\n\n ”匡啷！！”\n"+
                "你整個人被石板彈到一個新的地方.....\n" );
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name") +
                "被石板彈到空中去了!\n",this_player());
        this_player()->move_player(HAWK"room1-3","SNEAK");
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "像只鳥兒似的從天而降!\n",this_player());
        return 1;
}

int to_move(string str)
{
        if ((!str) || (str !="rock" )) return notify_fail("你要移動什麼呀?\n");
        if (be_move==0)
        {
                tell_object(this_player(),
                        "你使盡吃奶的力氣就是推不動石塊。\n");
                tell_room(environment(this_player()),
                        "你看到"+(string)this_player()->query("c_name")+
                        "使盡吃奶的力氣在移動石頭，"+
                        "但是石塊紋風不動。\n",this_player());
        }
        else
        {
                be_move=2;
                tell_object(this_player(),
                        "你非常用力的推擠石頭....\n\n\n"+
                        "終於把石頭搬開了幾公分之寬....石頭後面似乎還有什麼秘密...\n"+
                        "你伸手到石頭後面挖呀挖的, 竟發現有個拉桿(lever)! \n");
                tell_room(environment(this_player()),
                        "你看到"+(string)this_player()->query("c_name")+
                        "奮力的把石塊推開了一點距離。\n",this_player() );}
        return 1;
}

string to_search_rock()
{
        if ((be_move==0) || (be_move==1))
        {
                be_move=1;
                return "當你仔細的檢察這塊石頭時, 細心的你發現石塊有點鬆動。\n"
                "也許可以嘗試去移動(move)看看。\n";
        }
        else
        {
        return "一個被移動過的石頭, 後面有個拉桿(lever)\n" ;
        }
}

string to_rock()
{
        if ( (be_move==0)||(be_move==1) )
                return "一塊顏色詭異的巨石,不知為何會出現在這裡。\n";
                return  "一塊被移動過的巨石,石頭後面有支拉桿(lever)。\n";
}

string to_lever()
{
        if ((be_move<2) ) return "這裡沒有這樣東西。\n";
        return "這個拉桿看來可以拉動(pull), 不知道會有什麼結果。\n";
}
void reset()
{
        ::reset();
        be_move=0;
}
