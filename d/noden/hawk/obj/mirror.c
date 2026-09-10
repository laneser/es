
#include <mudlib.h>
inherit OBJECT;
void create()
{
        set_name("Darkgreen Mirror", "墨綠色的寂思");
seteuid(getuid());
        add( "id", ({ "darkgreen mirror","mirror" }) );
        set_short( "墨綠色的寂思" );
        set("long","這是一面底部墨黑色的鏡子，你可以拿來看看(see)自己的尊容唷。\n");
        set( "weight", 3 );
        set( "unit", "面" );
}

void init()
{
        add_action("to_see","see");
}

int to_see(string str)
{
        string gen;
        gen = this_player()->query("gender");
        if (str != "mirror")
                return 0;
        if (gen == "male")
        {
                tell_object(this_player(),@LONG
哇！你在鏡子裡看到一個大帥哥。
你不禁得意的笑了起來～～～
.....................
LONG
                );
                call_out("m_next",5,this_player());
                return 1;
        }

        if (gen == "female")
        {
                tell_object(this_player(),@LONG
哇～你在鏡中看到一個絕世大美女。
你不禁顧影自憐，對著鏡子騷首弄姿～～～～
.....................
LONG
                );
                call_out("f_next",5,this_player() );
                return 1;
        }

        if (gen == "neuter")
        {
                tell_object(this_player(),@LONG
鏡子忽然碎掉了～～～～

可能是不喜歡你吧....
LONG
                );
                this_object()->remove();
                return 1;
         }
}

void m_next()
{
        tell_object(this_player(),@LONG
你突然發現鏡子裡的你沒有跟你一起笑，反而用血紅的雙眼瞪著你～～～
你受不了這個驚嚇，兩眼一翻腿一蹬就死了。
LONG
                );
        tell_room(environment(this_player()),
                "你看到"+(string)this_player()->query("c_name")+
                "對著鏡子傻笑一番，忽然臉色一變～～～～\n",
                this_player() );
        call_out("die",3,this_player() );
}

void f_next()
{
        tell_object(this_player(),@LONG
你突然發現鏡中的你沒有和你一起活動，反而用死魚般的眼死瞪著你～～～
你受不了這個驚嚇，暈死在地上。
LONG
                );
        tell_room(environment(this_player()),
                "你看到"+
                (string)this_player()->query("c_name")+
                "對著鏡子一陣騷首弄姿，突然滿臉驚懼的轉過頭來，然後就暈死在地上。\n",
                this_player() );
        call_out("die",3,this_player());
}

int die()
{
        object wuchang;
        tell_object(this_player(),@C_LONG

你死了。

你有種奇怪的感覺....輕飄飄的....

你看到你自己毫無力氣地躺在地上....。

你看到一個又高又瘦的黑色人影，無聲無息地走到你的身邊 ....
黑無常說道: 你已經死了，隨我赴陰司受審吧。
黑無常將一條又粗又重的鐵鏈往你頭上一套，很粗暴地拖著你向前走。
你只見眼前許多雲霧像刀一樣刮過你的臉，然後出現了一座石橋 ....
C_LONG
        );
        tell_room(environment(this_player()),
                (string)this_player()->query("c_name")+
                "發出一聲淒厲的慘叫，跌在地上 ... 死了。\n"+
                "你看到一縷白色的影子從"+
                (string)this_player()->query("c_name")+
                "的屍體中飄起。\n",this_player() );

        call_out("die1",10,this_player() );
	this_player()->move_player("/d/abyss/hell/bridge","SNEAK");
        wuchang=new("/d/abyss/hell/monster/black_wuchang");
        wuchang->move("/d/abyss/hell/bridge");
	this_player()->move_player("/d/abyss/hell/bridge","SNEAK");
        return 1;
}

int die1()
{
        tell_object(this_player(),@C_LONG
黑無常說道: 鬼卒，我帶來了一個亡魂，你進去通報一聲！
黑無常轉頭對你說道: 好好在這裡呆著，過了奈何橋就是陰間了。
C_LONG
        );
        call_out("die2",10,this_player() );
        return 1;
}

int die2()
{
        tell_object(this_player(),@C_LONG
鬼卒說道: 算你運氣好，森羅殿還在整修當中，回陽間去吧！
鬼卒抓起你往雲霧中一丟，一陣天旋地轉之後，你又見到一片熟悉的景象 ...
你覺得一陣暈眩，感覺自己又回到了熟悉的身體裡。
資料備份 ... 完畢。

C_LONG
                );


        this_player()->move_player("/d/noden/farwind/cemetery","SNEAK");
        this_player()->set("hit_points",10);
        this_player()->set("spell_points",1);
        if ( (string) this_player()->query("class") == "monk" )
        {
                this_player()->set("force_points",0 );
        }
        this_object()->remove();
        return 1;
}

