#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(12);
        set_name( "hawkman elder", "鳥人長老" );
        add ("id", ({ "hawkman", "elder" }) );
        set_short( "hawkman elder","鳥人長老");
        set("unit","位");
        set("alignment",500);
        set_long(@LONG
  身為鳥人族的長老，鳥人長老和鳥人族依武鬥會所推選出來的領袖不一樣的
是，他由多年的戰鬥經驗，學到了一些特殊的戰鬥技巧。所以雖然看起來並不像
是一個強壯的戰士，但決不是好欺負的。你又發現他腰間纏了條不起眼的鞭子，
不知是幹啥用的，反正應該不是ＳＭ，不用太緊張。
    最近鳥人族似乎風波不斷，鳥人長老不禁也是眉頭深鎖，你可以問問他在煩
惱些什麼，說不定你可以幫助(help)他喔。
LONG
        );
        set_perm_stat("str", 11);
        set_perm_stat("dex", 7);
        set_natural_weapon( 15, 10, 16 );
        set_natural_armor( 25, 10 );
        set ("gender", "male");
        set ("race", "hawkman");
        set("tactic_func","sp_tactic");
        set("max_hp",250);
        set("hit_points",250);
        set("special_defense",(["all":20,"none":10,"electric":40]));
        set("aim_difficulty",(["critical":10,"weakest":10,
                               "vascular":10,"ganglion":10 ])) ;
        set_skill( "parry",30 );
        set_skill( "dodge",50 );
        set_skill( "whip",80);
        set( "inquiry", ([
                "help" : "@@ask_help",
                        ]) );
}

void init()
{
        add_action("do_report","report");
}

int do_report()
{
        if (this_player()->query_temp("smore_box") == 5)
        {
                tell_object(this_player(),@LONG
長老說：你已經跟我說過了，我們大家都很感謝你。
LONG
                );
	return 1;
        }

        if (present("s_potion",this_object() ) &&
                this_player()->query_temp("smore_box") == 4)
        {
                tell_object(this_player(),@LONG
長老接過你的藥瓶，仔細的看了許久，然後嘆了一口氣，對你說道:

謝謝你告訴我這個天大的秘密!!當年我早就懷疑阿道夫的實力能贏的了維多，只是
比賽的結果就是如此，我也不能說什麼。這些年來我們受制於阿道夫的淫威之下，
都是敢怒不敢言，幸虧有你這麼一位俠肝義膽的俠士才算解了當年之謎! 太好了，
我馬上召開鳥人族大會，揭穿阿道夫的假面具，讓他以後無法在鳥人族中作人！

長老轉過頭去，向身後的護衛吩咐了幾句話，護衛點點頭，就向外離去了。

接著鳥人長老帶著你，穿過了重重地道，進入了鳥人族的禁地。

LONG
                );
                this_player()->set_temp("block_command",1);
                call_out("meeting_a",5,this_player() );
        }
        else if (!present("s_potion",this_object()) &&
                this_player()->query_temp("smore_box") == 4)
        {
                tell_object(this_player(),"長老說：『哦？那藥水在哪啊？』\n\n" );
                return 1;
        }
        else if (this_player()->query_temp("smore_box") != 4)
                return 0;

        return 1;
}

void meeting_a()
{
        tell_object(this_player(),@LONG
你發現自己走進了一間非常古老的大廳，四周的牆都是由茅草所建。鳥人一群
群的走了進來，間歇著帶有一陣陣談論的聲音。

鳥人長老清清喉嚨..." 安靜! 安靜 !"

LONG
);
    call_out("meeting_0",5,this_player() );
}

void meeting_0()
{
    tell_object(this_player(),@LONG

四周都安靜下來了.....

鳥人長老緩緩的將你所發現的藥瓶展示給大家看，說" 這就是當年阿道夫所偷
用的禁藥，就是用這個藥物才打敗了維多! 今天，我們就是要還維多一個公道
的! 阿道夫! 你還有什麼話好說!"

LONG
);
    call_out("meeting_1",10,this_player());
}

void meeting_1()
{
    tell_object(this_player(),@LONG
阿道夫臉上劃過一抹的驚訝，但隨即消逝，冷冷地笑笑，緩緩說道:
" 哼! 就拿一個小破爛瓶子，就要誣賴我是嗎? 別以為你是長老我就怕你了! "
阿道夫指著你 "這! 這是誰啊? 不是鳥人族的人也來我們的禁地多管閒事? 找死!"

阿道夫說完就拔劍往你身上砍來!

正當千均一發之際，鳥人長老雙手一伸，輕輕一撥就把阿道夫的劍擋下來!
鳥人長老目光炯炯的望著阿道夫說道:
" 阿道夫! 你這樣作莫非是作賊心虛，殺人滅口嗎? 有我在一切不可亂來 !"

LONG
);
    call_out("meeting_2",8,this_player());
}

void meeting_2()
{
    tell_object(this_player(),@LONG
柏尼絲也嬌聲說:
" 阿道夫，我很希望你是清白的，只是這些年來我始終無法瞭解你是怎麼打敗維多
的，也許今天在這裡，你可以當大家的面把事情澄清，現在出現了這瓶禁藥，而且
剛剛族人也相繼的發現裘拉根和雷多都不見了? 這些疑點未免太過蹊蹺了吧? "

柏尼絲轉過身來望著你 "對了，朋友，你還知道些什麼有力的證據嗎? "

LONG
);
    call_out("meeting_3",5,this_player());

}

void meeting_3()
{
    tell_object(this_player(),@LONG
你站了出來，當著全鳥人族的面前朗聲說道 :
" 各位親愛的鳥人族朋友們! 阿道夫的走狗--雷多，跟裘拉根他們三人當年聯合串
通好，讓阿道夫服用了增強肌力及抗力的藥物，打敗了維多，然而這藥卻是你們鳥
人族的禁藥，因為，他會讓鳥人的翅膀硬化，飛不起來，也就是說....

    阿～道～夫～他～～他～現～在～根本就～～不～會～飛!!!  "

你話一說完，鳥人們開始蠱噪起來，紛紛的用不屑的眼神看著阿道夫!

LONG
);
    call_out("meeting_4",10,this_player());
}

void meeting_4()
{
    tell_object(this_player(),@LONG

阿道夫眼睛充滿鮮紅殺氣，大叫" 說謊! 說謊! 不要相信他!!"

鳥人長老拿起火炬往地上一扔，火勢沿著稻草順勢就燒了起來!
鳥人長老看了看阿道夫說:
" 現在，就是給你證明的機會了! "

鳥人長老把你一把抱起來，拍拍翅膀，你覺得身體有種奇怪的感覺，雙腳竟離
開了地面..... 慢慢的，其他的鳥人也跟著飛到了空中，真是奇妙的感受!
只見阿道夫在那間審判室中慘叫，原來他真的飛不動了，看他被火焚燒的可憐
樣子，在場卻沒有任何一位鳥人願意下去解救他，可見他真的是作惡多端啊!

你聽到火焰中傳來一陣陣淒厲的慘叫聲：『對不起～～～我錯了～～～』，不
由得於心不忍，說到：『算了，放過他吧，你們還需要他的力量來抵禦外族人
的侵掠呢。』
LONG
        );
    call_out("meeting_5",5,this_player() );
}

void meeting_5()
{
        tell_object(this_player(),@LONG

鳥人長老略一遲疑，點點頭，說到：『在下次比武大會之前，還是讓阿道夫先
暫代領袖職務吧，首惡裘拉根已經受到了應有的處罰，那就夠了。』

長老手一揮，一陣大雨將熊熊大火澆熄，留下被烈火燒的奄奄一息的阿道夫，
兩個守衛飛過去把阿道夫抱了起來帶回城內。

鳥人長老帶著你回到了村落。... ....

LONG
        );

        this_player()->move_player("/u/s/smore/hawk/room3-2","SNEAK");
        this_player()->set_temp("block_command",0);
        this_player()->set_temp("smore_box",5);
	call_out("ending",5,this_player() );
}

void ending()
{
	tell_object(this_player(),@LONG
長老對你說：感謝你為我們做了那麼多，聽你說你找到了維多的墳墓，那麻
煩你再到維多的墓前，告訴他他的冤辱已經被你洗刷了。
LONG
        );
}

int ask_help()
{
        tell_object(this_player(),@LONG

鳥人長老嘆了口氣，說：
    最近真是流年不利啊，戰爭打的損傷慘重，看來阿道夫真不是個好的領
袖，可是偏偏他又贏了武鬥大會。真希望維多能夠回來重新領導鳥人族，不然看
來鳥人族就要敗亡在我們這一代了。前一陣子聽說維多的手下有回來過，卻不幸
死在森林裡，如果能找到他帶回來的東西，說不定就能探聽出維多的下落。
LONG
        );
        return 1;
}

int sp_tactic()
{
        object magics;
        int dam;
        if ( !(magics=query_attacker()) || (random(12)>3)) return 0;
        magics->set_temp("kill_elder",1);
        tell_room(environment(),
        "\n\n鳥人長老忽然用手中的長鞭緊緊的絞在對手的脖子上。\n",
        this_object() );
        dam = 10 + random(5);
        magics->receive_damage(dam);
        magics->block_attack(2);
        magics->set_temp("msg_stop_attack",
                "( 你被長鞭緊緊的勒住，失去一次行動的機會 )\n");
        return 1;
}

void die()
{
        object *attackers, elder;
        int i;
        tell_room( environment(this_object()),
        "鳥人長老大聲狂笑： 唷呵呵....你還不錯嘛 .... \n\n"
        "一陣狂風吹來，鳥人長老竟又站了起來\n"
        "鳥人長老大叫：見識一下我真正的實力吧\n\n"
        "只見鳥人長老似乎越長越高，全身的肌肉也都鼓了起來，再從身後拿出
幾件防具穿上....\n\n"
        ,this_object() );
        elder = new("/u/s/smore/mob/elder.c");
        elder->move( environment(this_object()) );
        attackers = this_object()->query_attackers();
        for( i=0; i<sizeof(attackers); i++ )
                elder->kill_ob( attackers[i] );
        this_object()->remove();
        ::die(1);
}
