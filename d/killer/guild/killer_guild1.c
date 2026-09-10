//sage 修改於： 98-4-18 11:10

////#pragma save_binary

#include <mudlib.h>

inherit ROOM;

int cup;
int open=0;


void create()
{
        ::create();
        set_short("停屍房");
        set_long( @C_LONG_DESCRIPTION
    這裡是公會擺放亡靈的地方，寒風陣陣，佈滿了大大小小的棺材(coffin)，
只要是為公會而陣亡的，你就有資格把你的身軀放在這神聖的地方，聽說身軀
放在這個房間，永遠也不會腐爛。
C_LONG_DESCRIPTION
        );

        set( "light", 1 );
        set( "item_desc", ([
                "coffin" : "這些棺材十分老舊，上面積滿了灰塵，但你仔細查看一遍，\n"
                          "發現似乎每個棺材都可以打開(open)，但你有這個膽量去 \n"
                          "打開它嗎？\n"
        ]) );

        set( "exits", ([
         "east" : "/d/killer/guild/killer_guild.c" 
        ]) );
}
void init()
{
        add_action( "do_open", "open" );
        add_action("enter_hole", "enter");
}

int do_open(string str)
{
    if( !str || str != "coffin" )
      return notify_fail("你要打開什麼?\n");
    if( (int)this_player()->query_stat("str") < 15 )
      return notify_fail(@ALONG
你用盡了全身的力氣，可是因為力量太小而抬不動。
你已經四肢發軟坐在地上喘氣。
ALONG
      );

    tell_object( this_player(),@C_LONG
你用力地打開棺材的頂蓋。突然你聽到奇怪的聲音從棺材的底部傳來，好像
是觸動了什麼機關。當你低頭一看，棺材底部出現了一個小洞(hole)
C_LONG
    );
    open = 1;
    return 1;
}
int enter_hole(string str)
{
      if( !str || str != "hole" )
        return notify_fail( "你要進去哪裡?\n");
      this_player()->move_player("/u/s/sage/workroom");
      return 1;
}
void reset()
{
        ::reset();
        open = 0;

}
