#include "../echobomber.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
    set_level(16);
    set_name("the older Annow","安洛長老");
    add("id",({"older","annow"}) );
    set_short("the older Annow","安洛長老");
	set_long(
@C_LONG
一個睿智的長老,似乎無所不知的樣子.據說他曾經穿梭時空,而且到過地獄,但是假使
你問他的話, 他也只是笑一笑而不回答你
C_LONG
	);
    set("alignment",880);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "個" );
    set_perm_stat( "dex",19);
    set_perm_stat( "str",14);
    set_perm_stat( "int",26);
    set_perm_stat( "con",17);
    set_perm_stat( "piety",27);
    set_perm_stat( "karma",16);
	
    set ("max_hp",390);
    set ("hit_points",390);
    set ("wealth", ([ "gold":30]) );
    set_natural_weapon(33,15,30 );
	set_natural_armor( 65 ,30 );
    set ("weight", 350);
    
    set( "inquiry", ([
         "crystalball" : "@@ask_crystalball",
         "muse" : "@@ask_muse",
         "trouble":"@@ask_trouble",
         "chichikair":"@@ask_chichikair",
         "morr":"@@ask_morr",
         "ruin":"@@ask_ruin",
         "tower":"@@ask_tower",
         "queen":"@@ask_queen",
         "bell":"@@ask_bell",
         ]) );
    set("special_defense", (["all":33,"none":20]) ); 
    set ("aim_difficulty",(["vascular":20]) );
    set( "tactic_func", "cast_spell");
}

void ask_crystalball(object who)
{
     tell_object( who ,
       "安洛說:那顆魔法水晶球,是提供著房子飄浮的能源球.\n"
       "此外你也可以藉由著它離開這個地方.\n"
       );    
     return;  
}

void ask_cisklyph(object who)
{
     tell_object(who,
     "一個喜愛探險的流浪漢, 我們曾經一起探險邪惡的血湖, 九死一生的逃\n"
     "了出來, 而建立起我們之間良好的友誼. 喜愛冒險的他現在大概在古代\n"
     "遺蹟中尋找秘密吧.\n"
);
     return; 
}

void ask_muse(object who)
{
     
     tell_object(who,
                 "繆思泉,詩人夢想的地方,聽說能夠給與人無窮盡的靈感.\n"
                 "我也找尋它很久了.....\n"
                 "而我的一個好朋友希斯克利夫(Cisklyph), 為了這個秘\n"
                 "密也前往傳說中的古代廢墟(ruin)了.\n"
                 );
     return;
}
void ask_queen(object who)
{
     tell_object(who,"可憐的皇后, 全國的人民都為了她在擔心著\n");
}
void ask_trouble(object who)
{
     tell_object(who,
                 "安洛說: 有一個很大的麻煩正困擾著我們的村莊,但是知道這件事的人不多.\n"
                 "一個瘋狂的矮人魔法師奇奇凱爾(chichikair),不知道從那裡喚來一些幻影 \n"
                 "怪物,便自以為非常的了不起,竟然想要攻擊死亡大地紅色魔法高塔裡的大巫\n"
                 "妖懷爾,破壞矮人與高塔數百年的和平 ,一群巨人已經夠頭痛了,若再加上高\n"
                 "塔(tower)裡的那些邪惡魔法師,我不敢想像會有甚麼後果....."
                 ); 
     return;            
}

void ask_chichikair(object who)
{
     tell_object(who,
                 "安洛說: 瘋狂的矮人魔法師奇奇凱爾,原本也是一名善良的好人,但是自從他\n"
                 "的從小到大一起長大的好友法拉第死了以後,他的性情大變,瘋狂的研究起邪\n"
                 "惡的暗黑魔法,而他的同門摩兒知道了這情況,也千里迢迢地來到這裡勸阻他\n"
                 ",但是奇奇凱爾卻失蹤了.摩耳說他隱藏在一個神秘的地方,但確實的地點並無\n"
                 "法得知,只能大概知道在矮人迷宮的外面.你應該到去找找看\n"
                 );
     who->set_explore("deathland#29"); 
     return;            

}

void ask_morr(object who)
{
     tell_object(who,
                 "一個女妖精魔法師,魔法高強,喜好安靜的生活,所以她把自己的住所用魔法障壁\n"
                 "封了起來,以避免外人的打擾,想要見到她要一點勇氣才行.\n"
                 );
}

void ask_ruin(object who)
{
     tell_object(who,
                 "矮人迷宮中裡有一個很大的秘密. 聽說有個神秘的古代遺蹟隱藏於某個地方, \n"
                 "但是沒有幾個人能夠發現它的位置. \n"
                 "聽說很久以前一個矮人探險家曾經發現它的位置, 但是他卻在與巨人的戰爭中\n"
                 "犧牲了..\n"
                 );
}
void ask_bell(object who)
{
     object *items;
     int i;
      
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) {
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/explorer_bell"))
             {
             tell_object(who,
             "安洛看了一下你黑盒子的鈴當後說:\n"
             "沒錯: 這就是偉大探險家的鈴當, 記得他曾經告訴我說, 這個鈴當\n"
             "能夠指引你到達古代遺蹟去. 只要我加上適當的咒語就可以用了.\n"
             "安洛口中開始念念有辭.....\n...\n..\n.......\n..\n.....\n.\n...\n"
             "................\n.\n....\n"
             "過了數分鐘後,安洛把鈴當還給你並且說:\n"
             "去吧! 你的旅程才剛開始.\n"
             );
             items[i]->set("quest_action/invoke_bell",1);
             who->set_explore("deathland#23");
             if ( (int)who->query_quest_level("queen_smile") < 1 )
               who->finish_quest("queen_smile",1);
             return;
             }
       }
     tell_object(who,
     "你想問什麼鈴當??\n"
     );
     return;  
}

void ask_tower(object who)
{
     tell_object(who,
                 "紅色魔法高塔,他們似乎已經很久沒有甚麼動靜了,但是他們\n"
                 "的魔法實在是非常的可怕,由其是大巫妖懷爾,一個十分陰沉\n"
                 "的不死生物,據說他是邪神Yang的唯一傳人,他的魔力沒有人\n"
                 ",應該說是沒有活著人曾經見到過,像那個繁華一度的蘭斯城\n"
                 ",只因得罪了他,就這麼整個城沉入海底了.所以,誰願意去招\n"
                 "惹這個魔王呢?\n"
);
}

int cast_spell()
{
    object victim;
    string name,c_name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    c_name= victim->query("c_name");
    
    if( random(10) < 6 ) {
      tell_room( environment(this_object()), 
        "\n\n安洛大叫:地獄之火........\n" );
      victim->receive_special_damage("fire", 14+random(6));
      return 0;
    }
    if( (this_object()->query("hit_points")<180) && (random(100)<50) ) {
      tell_room( environment(this_object()), 
        "安洛使用天地之氣醫療他自己。\n" 
      );
      this_object()->receive_healing(35+random(30));
      return 1;
    }
    
    return 0;
}

