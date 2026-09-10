#include "../tsunami.h"

inherit HOME+"magic";
inherit MONSTER;

void create()
{
    ::create();
    set_level(5);
    set_name("Shopkeeper","錢老闆");
    add("id",({"keeper"}) );
    set_short("錢老闆");
    set_long(@LONG
錢老闆是為約莫四十出頭的中年男子，嘴邊掛著一撮小鬍子，
外加兩顆咪咪眼，十足的精明幹練模樣。不過他的脾氣有點古怪，
外傳他曾是風聞一時的大盜，所以最好不要問他有關小偷(thief)
的事情哦，免得他動怒！另外呀，他觀察力可是一流的哦，能在短
時間內算清你身上所有的傷痕(scar)哦，那怕是衣服遮住的，一樣
無法逃出他的慧眼！
LONG
             );
    set("unit","個");
    set("gender","male");
    set("alignment",-500);
    set("race","daemon");
    set("no_attack",1);
    set("inquiry",([
          "thief":"@@ask_thief",
          "scar" :"@@ask_scar",
          ]) );
}
    
void ask_thief(object victim)
{
    write("錢老闆突然臉色一沉，一道煙霧後只見一團黑影向你衝了過來！！\n");
    tell_room( environment(victim),
    "\n突然一陣煙霧，只見一道黑影向"+victim->query("c_name")+"撲了過來！\n"
    , victim);
    kill_ob( victim);
    set_level(12);
    set_name("Great Thief","錢形次郎");
    add("id",({"thief"}) );
    set_short("大盜  錢形次郎");
    set_long(@LONG
    原來錢老闆果真是風聞一時的妙手大盜啊，只見他全身勁裝，一幅
氣急敗壞的模樣。
LONG
            );
    set("no_attack",0);
    set("c_killer_msg","\n突然一陣煙霧，只見一道黑影向你撲了過來！\n");
    set("killer",1);
    set("tactic_func","my_tactic");
    
    set("chat_chance",20);
    set("att_chat_out",({
        "臭小子，竟敢道破我最不想讓人知道的過去，我給你″死″！！\n"
        }) );
    set_natural_weapon(18,13,17);
    set_natural_armor(35,15);
} 

int my_tactic()
{
    object victim;
    
    if( !(victim=query_attacker()) ) return 0;
    if( random(20) < 2){
      tell_object(victim,
      "次郎順手一揮，數枚暗器向你射了過來，但都被你接住了.......\n"
      "哇～～！是五枚金幣耶，快收起來！\n"
                 );
       tell_room( environment(victim),
       "次郎偷偷地向 "+victim->query("c_name")+" 放暗器，但都被接住了！\n"
       ,victim );
       victim->add("wealth/gold",5);
       return 1;
        }
     else if( random(20) < 5){
       tell_object(victim,
       "突然「咻咻咻」數聲，次郎手中射出幾件暗器打在你身上，哇！好痛！！\n");
       tell_room( environment(victim),
       "次郎順手一揚，數件暗器激射而出，全打在 "
       +victim->query("c_name")+" 身上！\n"
       ,victim );
       victim->receive_special_damage("evil",15);
       report( this_object(),victim );
       return 1;
      }
     else return 0;
} 

void ask_scar()
{
    int jus;
    jus = (int)this_player()->query("justice");
    if(!jus) write("錢掌櫃指著你大笑道：你全身乾乾淨淨的, 一點傷痕也沒有, 你真是勇者嗎?????\n");
    else write("錢掌櫃拍手稱讚說：哇!!閣下全身上下佈滿大小傷痕"+jus+"道, 乃真神人是也!!\n");
    return 1;
}    
    
