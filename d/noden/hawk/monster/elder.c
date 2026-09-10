#include <mudlib.h>
#include <conditions.h>
#include "/u/s/smore/hawk.h"
inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "hawkman elder", "鳥人長老" );
        add ("id", ({ "hawkman", "elder" }) );
        set_short( "hawkman elder","鳥人長老");
        set("unit","位");
        set("alignment",1500);
        set("class","adventurer");
        set_long(@LONG
身為鳥人族的長老，鳥人長老自也是一名驍勇善戰的戰士，不過和鳥人族依
武鬥會所推選出來的領袖不一樣的是，鳥人長老同時也精通某些法術，更由
多年的戰鬥經驗，學到了一些特殊的戰鬥技巧，和他作戰，大概可以說是你
這一生最大的錯誤之一。由於他的豐富戰鬥經驗和人生閱歷，使得他在鳥人
族中講話極有份量。
LONG
        );
        set_perm_stat("str", 24);
        set_perm_stat("int", 30);
        set_perm_stat("dex", 21);
        set_natural_weapon( 45, 20, 30 );
        set_natural_armor( 45, 30 );
        set ("gender", "male");
        set ("race", "hawkman");
        set("tactic_func","sp_tactic");
        set("aiming_loc","weakest");
        set("max_hp",1400);
        set("hit_points",1400);
        set("special_defense",
                (["all":60,"monk":20,"scholar":20,"none":40,"electric":90]));
        set("aim_difficulty",
                (["critical":100,"weakest":30,"vascular":10,"ganglion":50 ])) ;
        set_skill( "whip",100 );
        set_skill( "parry",100 );
        set_skill( "dodge",70 );
        set_skill( "block",40 );
        set_skill( "anatomlogy",80);
        wield_weapon("/u/s/smore/weapon/whip1.c");
        equip_armor(ARMOR"shield2.c");
        equip_armor(ARMOR"god_1.c");
//	equip_armor(ARMOR"platemail.c");
        equip_armor(ARMOR"glove1.c");
//	equip_armor(ARMOR"helmet1.c");
//	equip_armor(ARMOR"armbands1.c");
        equip_armor(ARMOR"boots1.c");

}

void report(object holder, object victim )
{
   seteuid(getuid());
   tell_object( victim,
   sprintf("( 你%s )\n","/adm/daemons/statsd"->status_string(victim)));
}

void init()
{
        add_action("do_report","report");
}

int sp_tactic()
{
        object magics,caster;
        int dam,choice,kar,con,pie,dex,str,aa;
        choice = random(5);
        switch(choice)
        {
        case 0: return 0;

                break;
        case 1:
                if ( !(magics=query_attacker())
                        || (random(20)>random(5)) ) return 0;
                tell_room(environment(),
                        "鳥人長老從口中吐出一團黑霧，把你團團罩住。\n"
                        "....等黑霧散去，你發現身上多了不少黑色斑點....\n",
                this_object() );
                con = magics->query_perm_stat("con") ;
                pie = magics->query_perm_stat("pie") ;
                dam = con * 3 - pie * 2  + random(20);
                magics->receive_special_damage("poison",dam);
                (CONDITION_PREFIX + "simple_poison")->apply_effect( magics,
15, 3 );
                return 1;
                break;
        case 2:
                if ( !(magics=query_attacker()) || (random(10)>2)) return 0;
                dex = magics->query_perm_stat("dex") ;
                if ( random(dex) > 17)
                {
                        tell_object(magics,
                                 "鳥人長老眼中射出兩道高熱的光芒，不過你身手敏"
                                +"捷的往旁邊一跳....\n一個漂亮的後空翻，你躲開"
                                +"了這次的攻擊。\n\n" );
                        tell_room(environment(),
                                 (string)magics->query("c_name")
                                +"一個漂亮的轉體兩週後空翻，躲開了鳥人長老"
                                +"眼中放出的兩道紅色光芒。\n\n",this_object() );
                        return 1;
                }
                tell_room(environment(),
                        "鳥人長老的雙眼射出兩道紅光，照的你全身發熱。\n",
                               this_object() );
                tell_object(this_player(),
"鳥人長老眼中射出兩道炙熱的紅光，你覺得全身血液似乎快要沸騰了。\n"
                );
                dam = 30 + random(10);
                magics->receive_special_damage("energy",dam);
                report(magics,magics);
                return 1;
                break;
        case 3:
                if ( !(magics=query_attacker()) || (random(10)>2))
                        return 0;
                aa = (int)this_player()->query_temp("be_hang");
                if (aa) return 0;
                str = magics->query_perm_stat("str") ;
                if (random(str) > 17) return 0;
                tell_room(environment(),set_color(
"鳥人長老忽然用手中的長鞭緊緊的絞在敵人的脖子上。\n","HIR"),
                this_object() );
                dam = 15 + random(10);
                magics->receive_damage(dam);
                magics->block_attack(6);
                magics->set_temp("msg_stop_attack",
                        "( 你被長鞭緊緊的勒住，失去一次行動的機會 )\n");
                magics->set_temp("be_hang",1);
                call_out("over_hang",10,magics);
                return 1;
                break;
        case 4:
                caster = present("elder");
                aa = (int)caster->query_temp("no_way_out");
                if (random(10) > 4) return 0;
                if (aa) return 0;
                tell_room(environment(),set_color(
"鳥人長老狂嘯一聲，雙翅鼓動，四周捲起千堆雪，讓你分不清東南西北。\n","HIB")
                ,this_object() );
                caster->set_temp("no_way_out",1);
                call_out("let_go",10,magics);
                return 1;
                break;
                }
        return 1;
}

int over_hang()
{
        object magics;
        magics = query_attacker();
        magics -> set_temp("be_hang",0);
        return 0;
}

int let_go()
{
        object caster;
        tell_room(environment(),@LONG

大雪終於停止，你又看得到四周的環境了。

LONG
                ,this_object() );

        caster = present("elder");
        caster -> set_temp("no_way_out",0);
        return 1;
}

void die()
{
        object killer;
        killer = query("last_attacker");
        killer->set_temp("smore_armor/elder",1);
die(1);
}

int do_report()
{
        if (this_player()->query_temp("smore_box") == 5)
        {
                tell_object(this_player(),@LONG
長老說：你已經跟我說過了，我們大家都很感謝你。
LONG
                );
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

鳥人長老清清喉嚨..." 安靜! 安靜 "!

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

柏尼絲轉過身來望著你 "對了，朋友，你還知道什麼有利的證據嗎? "

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

