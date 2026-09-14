#include "../saulin_temple.h"

inherit "/d/eastland/saulin_temple/monster/mob_special";

int be_released;

void create()
{
        ::create();
        set_level(18);
        set_name( "jay yeng", "覺遠大師" );
        add ("id", ({ "monk","jay","yeng" }) );
        set_short("覺遠大師");
        set("unit","位");
        set_long(@C_LONG
你眼前的這位中年僧人長的斯斯文文的，但他肩上挑著兩個大鐵桶不說
腳上還拖著兩條粗大的鐵鏈，最奇怪的是他竟然從山下把水挑到山上的
井裡。雖然他挑著裝滿水的大鐵桶，在山路上走起來卻如履平地，想必
內功必是十分的驚人。他的嘴裡一直喃喃著什麼經書什麼的，或許你可
以跟他問個清楚。
C_LONG
        );
        set( "inquiry", ([
             "book" : ({ @BOOK
阿彌陀佛 ! 貧僧真是倒黴 ! 那日輪到貧僧值守藏經閣，正好有一
		位昔日老友天竺僧釋法藍前來，我倆相談甚歡。當晚達摩院首座
		來查經，有一本楞枷經竟然遍尋不著，楞枷經雖然很普遍，但是
		那本經書乃是達摩老祖自天竺攜來的，意義實在不同凡響。現在
		糟了，老納受罰不打緊，拖累了老友也被監禁在寺，真是太過意
		不去了。唉! 老納若能回藏經閣(library) 一趟，一定能查出什
		麼蛛絲馬跡。
BOOK
			}), "library" : ({@LIBRARY
對了，你可以幫貧僧回去查查嗎？藏經閣內有兩扇長窗，只要把
              兩扇窗同時一拉(pull)就會出現一道樓梯了，你可以幫我到密閣
              查查... 但是... 要怎麼進入藏經閣呢？閣外守衛那麼嚴密，要
              進去除非是隱形(invisible) 了，那怎麼可能呢？可是偏偏有人
              能偷的了書去 ... 唉 ～～

覺遠大師又開始自言自語，搖搖頭好像忘了你的存在，隨著一陣陣喃喃聲，
他又挑著鐵桶走了。
LIBRARY
			}),
		]));

        set("alignment",1400);
        set("wealth/gold", 10);
        set("gender", "male");
        set("race", "human");
        set("chat_chance",10);
//	set("moving",1);
//	set("speed",25);
//	set("patrol",({"north","north","north","north","south",
//		"south","south","south",}));
        set_perm_stat("str", 25);
        set_perm_stat("dex", 28);
        set_perm_stat("int", 20);
        set("max_hp", 700);
        set("hit_points", 700);
        set("max_fp", 2000);
        set("force_points", 2000);
        set("special_defense", ([ "all" : 40, "none" : 50, "monk":20 ]) );
        set("aim_difficulty", ([ "critical" : 60, "vascular" : 60 ]) );
        set_natural_weapon( 25, 20, 40 );
        set_natural_armor( 70, 30 );
        set_skill("chain",100);
        set ("chat_output",({@C_LONG
覺遠說道：不知道是誰偷走了那本愣枷經，方丈要我在這裡挑水反省。
C_LONG
        }));
        setenv("C_MIN", "$N挑著兩個大水桶走了過來" );
        setenv("C_MOUT", "$N挑著兩個大水桶向$D離開" );
	wield_weapon( SAULIN_OBJ"coul" );
        equip_armor( SAULIN_OBJ"cloth4" );
        equip_armor( SAULIN_OBJ"necklace" );
//	equip_armor( SAULIN_OBJ"armband1" );
 set("special_attack",(["damage_type" : "energy","main_damage" : 30,
                                "random_dam" : 20 , "hit_rate" : 25]));
        set( "tactic_func", "my_tactic" );
set("c_enemy_msg",
"\n覺遠將兩個大桶互相撞擊，發出「當」的一聲巨響，把你震的暈頭轉向 ...\n\n");
set("c_room_msg","覺遠用他的大桶互相撞擊，把");
set("c_room_msg2", "震的暈頭轉向 ...\n");
}

void init()
{
    add_action( "do_release","release");
}

int do_release(string arg)
{
    if ( !arg || ((arg != "Jay yeng") && (arg!= "yeng") && (arg!= "jay yeng")))
    {
        tell_object(this_player(),"你想要釋放誰?\n");
        return 1;
    } 
    if ( this_player()->query_temp("book_quest/step") != 5 )
    {
        tell_object(this_player(),@MSG1
覺遠說：施主您的好意, 老衲心領了!
不過, 沒有方丈法旨, 老衲不敢擅離。
MSG1
);
        return 1;
    }
    if ( be_released == 1 )
    {
        tell_object(this_player(),
        "咦! 奇怪了! 剛剛已經有人傳過方丈的法旨了。莫非你是在騙我嗎?");
        return 1;
    }

    tell_object(this_player(),@MSG2
覺遠感激地說道：多謝施主, 為老衲洗清這樁冤枉。
                老衲終於又可以再次加入早課、晚課和誦經的行程了
                對了! 說到誦經.....

你看到覺遠不管三七二十一地開始喃喃自語了起來, 聽起來好像是在誦經。
MSG2
                );
    if (this_player()->query("force_effect") < 4) {
       tell_object(this_player(),
       "\n你聽了覺遠的話, 心中若有所悟, 似乎發現到了武學中新的天地.....\n\n");
       this_player()->set_temp("block_command",1);
       call_out("check_gonfus", 20, this_player());
                                                  }
     this_player()->add("alignment",1000);
     this_player()->set("book_quest_finish",1);
     be_released = 1;
     set("chat_chance",0);
     return 1;
}

void check_gonfus()
{
	object* eqs;
	int i;

       if (this_player()->query("monk_score") > 1800) {
       if (this_player()->query("force_effect") == 3) {
          tell_object(this_player(),@MSG3
過去所學的種種, 都在你的腦海中如走馬燈般重現, 你”啊！”的一聲！
你頓悟了九陽神功的至理, 你的全身真氣迅速地在你的體內流通, 循環了
一十八個大周天後, 你已練成了九陽神功！
MSG3
);
          this_player()->set("force_effect",4);
          this_player()->set("force_points",this_player()->query("max_fp"));
                                                       }}
       else {
          tell_object(this_player(),@MSG4
”唉！”你長嘆一聲, 覺遠所念的每一句話, 對你來說都太深奧了,
你實在是無法體會, 心想要回去好好地再練練功夫。
MSG4
);
            }
      tell_room(environment(this_player()),
          "\n你看著覺遠自顧自地在唸唸有詞，漸漸走遠了! \n");
       this_player()->set_temp("block_command",0);
       eqs=all_inventory(this_object());
        this_object()->delete("weapon1");
        for ( i=sizeof(eqs)-1 ; i >-1 ; i--) {
                if (eqs[i]->query("equipped")) eqs[i]->delete("equipped");
                eqs[i]->remove();
        }
       remove();
}

