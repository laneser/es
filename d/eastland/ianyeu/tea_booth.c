// /u/m/mad/room/tea_booth.c
#include "/d/eastland/ianyeu/mad.h"

inherit ROOM;

void create()
{
        ::create();
   set_short( "茶棚" );
   set_long( @LONG
你正站在一間小茶棚之中, 空氣中瀰漫著清淡芬芳的茶香,
而店小二正不斷地忙於穿梭來往川流不息的客人之中, 看來此處
生意不錯。
LONG
        );
   set( "light", 1 );
   set( "objects", ([
           "waiter" : IANMOB"waiter",
           "father" : IANMOB"liang_father" ]) );
   set( "exits", ([
        "out" : "/d/eastland/10,13.east" ]) );
   reset();
}

void init()
{
   add_action( "sit_down", "sit" );
   add_action( "buy_item", "buy" );
}

int sit_down(string str)
{
   object waiter;

   if( !str || str != "down" )
   return notify_fail( "你『乓』的一聲跌坐在地!\n" );

   waiter = present( "waiter", this_object() );

   if( !waiter )
   return notify_fail( "你找了個空位子坐下, 但沒有人來招呼你!\n" );

   write( "當你找到一個空位子坐下時, 店小二急忙跑來並且說道:\n"
          "客倌, 您要點些什麼? 來壺『碧螺春(tea)』(100大銀)?\n"
          "或『燻羊腿(lamb)』(300大銀)?\n"
          "還是客倌想要試試本店特產『陳年高粱(wine)』(600大銀)?\n");
   return 1;
}

int buy_item(string str)
{
        object waiter;
        waiter = present( "waiter", this_object() );

        if( !waiter )
        return notify_fail(
        "你大叫: 店小二 ... 店小二 ... 但是店小二似乎不在!\n" );
        if (str == "wine")
        {
                if (this_player()->query_temp("get_wine") != 1)
                        return notify_fail(
                        "店小二說：客倌，我們這種酒是不隨便賣的喔。\n" );
                tell_object(this_player(),@LONG
店小二說：哇！客倌果然是識貨的。
接著轉身回酒窖拿了瓶陳年高粱，交給了你。
你聞到了一股神秘的香味，於是一口把高粱喝的乾乾淨淨～～～果然好喝。
想來雷多要的大概就是這玩意兒吧....。
LONG
                );
                this_player()->set_temp("get_wine",2);
                return 1;
        }
        return 1;
}

