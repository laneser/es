#include "../hawk.h"
inherit MONSTER;
void create()
{
        ::create();
        set_level(3);
	set("drink",0);
        set_name( "Traito","雷多" );
        add("id",({"traito"}) );
        set_short( "雷多" );
        set_long(@LONG
你看到一名身材瘦小又小頭銳面的男子，不過他可是天空之城當今第一大
紅人唷。自從阿道夫當上了鳥人族的領袖，雷多的地位就如火箭升空一般的向
上竄，如今就像個螃蟹一樣在鳥人城中橫行霸道。
LONG
        );
        set( "inquiry", ([
                "wine" : "@@ask_wine",
                "vito" : "@@ask_vito",
                "plan" : "@@ask_plan",
                ]) );
        set( "alignment", -400 );
        set( "gender","male" );
	set( "max_hp",100 );
	set( "hit_points",99 );
        set( "race","hawkman" );
        set( "no_attack", 1 );
}

void init()
{
        add_action("to_inform","inform");
}

int to_inform()
{
        if (this_player()->query_temp("get_wine") != 2)
        {
                tell_object(this_player(),"雷多說：疑，你真的有找到嗎？\n");
                return 1;
        }

        else
        {
                tell_object(this_player(),@LONG
雷多一聽到你告訴他酒在哪兒，馬上興沖沖的出門了。
LONG
                );
                this_object()->move("/d/std/rooms/void");
		call_out("come_back",40,this_object() );
                return 1;
        }
        return 1;
}

int come_back()
{
	object obj;
	message("tell_room","你看到雷多搖搖晃晃的從外面走了進來。\n",
		HAWK"traroom",this_object() );
	obj = new(MOB"traitoa.c");
	obj->move(HAWK"traroom");
	this_object()->remove();
	return 1;

}

int ask_wine()
{
	if (!this_object()->query("drink") )
	{
        	tell_object(this_player(),@LONG
雷多說：酒啊，我最喜歡酒了。威士忌啊，白蘭地啊，我都滿喜歡的。不過
聽說東方有一種陳年高粱，味道很好，可惜到現在我都還沒喝過，如果人能幫助
我拿到那種酒來喝，我一定會很高興的。這樣吧，你就去幫我找吧，找到以後來
告訴(inform)我酒在哪兒買，我自己去喝，這樣好不好啊？
LONG
        );
        	this_player()->set_temp("get_wine",1);
        	return 1;
	}
	else
	{
		tell_object(this_player(),
			"雷多說：酒？....我已經歷遍世上所有美酒羅....\n");
		return 1;
	}
}

int ask_vito()
{

        if ((int)this_player()->query_temp("traito") == 1)
        {
                tell_object(this_player(),@LONG
雷多說：嘿嘿，柏妮絲還不死心嗎？你去告訴她他的維多早就已經死了
啦！死了這條心吧。成者為王敗者為寇，這不是我們每年舉辦武鬥大會推舉
領袖的精神嗎？不要妄想什麼有人陷害他啦，技不如人就要服輸。如果不相
信，可以再去和阿道夫較量較量啊。哈哈哈....
LONG
                );
                this_player()->set_temp("traito",2);
                call_out("look_look",20,this_player());
                return 1;
        }
        else
        {
                tell_object(this_player(),@LONG
雷多說：維多？是誰叫你來問的....？他是我們以前的領袖，不過去年被自己的
弟弟打敗，從此就不見人影了，可能是覺得沒臉見人吧。
LONG
                );
                return 1;
        }
        return 1;
}

int ask_plan()
{
        if( this_player()->query_temp("smore_box") < 3) return 0;
        tell_object(this_player(),@LONG
雷多面如土色....顫抖的說：
　　天啊～～你都知道了是嗎？....沒想到....沒想到我們多年來的辛苦努力，
全毀在我貪杯誤事! 既然事到如今，我就告訴你背後的秘密吧！不過你可要答應
我幫我在長老及眾人面前求情啊！

　　事情是這樣的....當初阿道夫為了想要奪取比武大賽的冠軍，裘拉根就花了三個
月的時間收集各種神奇藥草，用肉食獸的唾液作引，所熬出來一瓶通筋活血的秘藥，
喝了之後不但如有神助般的力大無窮，而且皮堅如石，也難怪當初神勇如維多也會敗
在阿道夫的手下啊! 不過....這個藥有個致命弱點，就是阿道夫喝了以後，發現翅膀
肌肉硬化，羽毛也全部骨質化，換句話說，身為鳥人族領袖的阿道夫竟然不會飛呀!!

哈哈哈哈..........哈哈哈哈...............哈哈哈哈...........

雷多仰天狂笑不止，倒地不起，竟然笑死了!!
慢慢地，雷多的屍體冒出一股清煙，一會兒之後，他的屍體竟然氣化了!
你覺得應該把雷多的話報告(report)給長老聽, 也許可以還維多一個清白!

LONG
        );
        this_player()->set_temp("smore_box",4);
	this_object()->remove();
}

int look_look()
{
        tell_object(this_player(),@LONG
過了一會兒，你突然想到剛剛雷多的眼睛一直在瞄著牆邊的一個大鐵
箱(box)，不知道在幹嘛。
LONG
        );
        this_player()->set_temp("smore_box",1);
        return 1;
}

