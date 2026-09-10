#include "mercury.h"
inherit MMOB+"magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Samurai sika", "武士 星卡" );
	add( "id", ({ "samurai","sika" }) );
	set_short( "Samurai sika", "武士 星卡" );
	set_long(@AAA
你眼前是一位年輕的武士，雖然他年紀輕，但他以得到影流劍法奧義,目前是
武士團中的副隊長，但根據可靠消息來源指出，他的劍技已是武士之冠！！！
而在另一方面星卡也是著名的史學家，你如果有興趣可以問他歷史(history)
的事，又據說只要是他帶兵出去就不會輸，你也可以問他關於戰爭不敗之法
(win)！！
AAA
 );
	set( "unit", "位" );
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 18 );
        set_perm_stat( "dex", 18 );
        set_perm_stat( "kar", 20 );
        set_perm_stat( "pie", 20 );    
        set( "max_hp",650 );
        set( "hit_points",650 );
 	set_natural_armor( 45,25 );
	set( "natural_weapon_class1", 20 );
	set( "natural_min_damage1", 15 );
	set( "natural_max_damage1", 35 ); 
        set( "time_to_heal",30);
        set( "special_defense",([ "all":25,"none":25 ])); 
        set( "aim_difficulty",([ "critical":80,"weakest":20,"ganglion":50,
                                 "vascular":35 ]));
        set( "stun_difficulty/ma",15);  
	set( "alignment", 1000 );
	set_c_limbs( ({ "頭部", "身體", "手腕", "咽喉" }) );
	set_c_verbs( ({ "%s右手手刀往%s的咽喉猛力一劈", "%s左手直拳向%s的小腹擊來" }) );
        set_skill( "parry",85 );
        set_skill( "longblade",100 );
        set_skill( "dagger",100 );
        set( "wealth" , ([ "gold": 100 ]) );
        set( "tactic_func", "att_gonfus");
        set( "weight", 400 );    
        wield_weapon(MOBJ"black_ya_sha");
        equip_armor(MOBJ"samurai_gloves.c");
        equip_armor(MOBJ"samurai_cloth.c");
        equip_armor(MOBJ"samurai_boots.c"); 
        set("inquiry",([
            "win":"@@ask_win",
            "history":"@@ask_history",
            "continue"  :"@@ask_part",
            "war"       :"@@ask_war"
            ]));
}
int ask_win()
{
write(@AAA
星卡說道：其實不敗的秘訣很簡單，就是不打沒有把握的仗，當退則
　　　　　退，決不拖泥帶水，就如同打怪物時要設wimpy，wimpy跑
          時就跑那就不會死了，不過逃不掉時是例外啦！！
AAA
);
return 1;
}
int ask_history()
{
write(@AAA
星卡說道：其實我們的老祖先應該是諾頓王國的人吧，只是當初因為對於
　　　　　軍隊改革的立場不同，和當時諾頓騎士團的當權者有意見上的
　　　　　衝突，而後來因為有心人的煽風點火，進而演變成武力上的對
　　　　　決，而那時我們畢竟只是一個新起的流派，人數上不是正統騎
　　　　　士的對手，所以被迫遷徙到這個島來，剛到這裡時，環境還很
　　　　　好，我們也在此過的不錯，人口也大幅提升，那時和蜥蜴人也
　　　　　和平相處，只是後來發生一些災變，為求生存就必須和蜥蜴搶
　　　　　奪剩下來少數能居住的土地了，那時因為蜥蜴人沒有組織，即
　　　　　使我們只用接受騎士訓練的騎士就能打敗他們，所以早期並沒
　　　　　有像現在有如此大的武士團，．．hmm 我喝口水．你如果還想
　　　　　再聽下去就在問我 (continue)
AAA
);
return 1;
}
int ask_part()
{
write(@AAA
星卡說道：那為什麼現在有如此大的武士團組織，那是由於在我們擊敗
　　　　　蜥蜴人之後，蜥蜴人不知道從哪裡得到消息，知道我們的部隊是
　　　　　在諾頓大陸得到的訓練，於是他們就秘密派了一批較為聰明的蜥
　　　　　蜴人到諾頓去，而這批人回來後就組成相當有名的蜥蜴騎士團，
　　　　　由於蜥蜴人天生體格強健，我們人類組成的騎士團遇到他們根本
　　　　　就不是對手，在戰況不利的狀況下，當初我們所謂能實行的改革
　　　　　軍隊方案又搬上臺面了，那時我們開始秘密訓練武士團，而就在
　　　　　訓練完成的時候，我們一口氣突擊了蜥蜴人數個據點，終於板回
　　　　　我們軍事上的劣勢，所以目前我們和蜥蜴人是在個平衡狀態，而
　　　　　再三十年前突然發現東方山區內有個魔族的勢力，本來試想一口
　　　　　氣將其佔領併吞其力量，那我們就可以消滅蜥蜴人的勢力了，然
　　　　　後就．．．．．想再聽就問(war)吧！！！
AAA
);
return 1;
}
int ask_war()
{
write(@AAA
星卡說道：那一戰可說是武士團成軍以來最大的挫敗，那時我們集結了三個
　　　　　大隊的精銳武士，由當時的副團長牙神幻十郎帶領，另外還有當
　　　　　時年輕武士的佼佼者地場衛．鷹村守．以及我的師父日向左近等
　　　　　好手帶領，這些人出戰連蜥蜴人都要懼怕三分，但沒想到魔族本
　　　　　身的戰力雖不及蜥蜴人，但憑藉著其天險，在我們攻進他們城內
　　　　　時，以少了一半的兵力，剩下來的部隊在敵人佔多數的情形下也
　　　　　只好撤退，而當時帶隊的牙神也為了掩護撤退兒戰死，鷹村和地
　　　　　場則是在城內被圍殺而亡，只有我師父留下，而由此戰後我方戰
　　　　　力大傷，但魔族也好不到哪去，雖然攻入城內的人不多，但是仍
　　　　　給魔族造成不小傷害，而在我們失敗後蜥蜴人也採取了攻勢，雖
　　　　　然他們也派出了蜥蜴人最強的部隊，但是被魔族．．．．．．．
　　　　　　據說是他們守護神顯靈啦，才擊退蜥蜴人，總之從那戰之後呢
　　　　　三國勢力又成一個均衡形式，而也在個奇怪的情況下籤下和平條
　　　　　約，而怎麼簽下我是覺得太誇張了，所以我現在仍在研究中，你
　　　　　可別相信魔族那隻白痴鷲羽的說法，怎麼會有神呢？我可是不相
　　　　　信那種說法一點歷史概念都沒有．．．．．！！！
AAA
);
return 1;
}



int att_gonfus()
{
     object victim;
     int dam;
     
     if( !(victim = query_attacker()) || (random(20)>2) ) return 0;
     tell_room(environment(this_object()), 
	"\n星_卡大聲喝到:小子我要讓你知道你有多愚蠢來向我挑戰\n突然間，你發現星＿卡的刀消失了！！　\n\n"+
     "星_卡大喝一聲：接我的″不～動～冥～王～斬″\n\n"+
     "那把消失的刀突然在面前出現,並在"+victim->query("c_name")+"的胸前劃出一到極深的傷口\n"
      );
      dam = 20 + random(25);
      victim->receive_special_damage("energy", dam );
      report(this_object(),victim);
      return 1;
      
}
