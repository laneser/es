#include "../tsunami.h"
#include "/include/move.h"
#include <daemons.h>

inherit MONSTER;
inherit DAEMON;

int times;

void create()
{
        ::create();
        seteuid(getuid()); 
        set_level(17);
        set_name("Archwizard Washu","大魔導士");
        add( "id", ({"daemon","arch","archwizard","washu"}) );
        set_short("大魔導士鷲羽");
        set_long(@LONG
鷲羽是魔族中魔法知識最豐富的大魔導士，同時也是魔族中知識最豐富的長老
，她年輕時曾四處闖蕩，因此閱歷非常豐富，應該就是別人所謂的活字典了；她
最喜歡對別人說有關三位守護靈和三把主鑰的故事(story) 了，你有興趣聽嗎？
如果你能討他歡心的話，說不定她還會送你獎品哦！
LONG
                );
        set( "unit", "位" );
        set( "race", "daemon" );
        set( "gender", "female" );
        set( "alignment",-5000 );
        set( "hit_points", 550 );
        set( "max_hp", 550 );
        set( "spell_points",2000);
        set( "max_sp",2000);
        
        set_perm_stat("int",25);
        set_perm_stat("str",15);
        set_perm_stat("dex",25);
        set_perm_stat("kar",25);
        set_perm_stat("pie",25);
        
        set_natural_armor(35,30);
        set_natural_weapon(30,10,30);
        
        set( "special_defense", ([ "all":25,"none":10 ]) );
        set("aim_difficulty",
        ([ "critical":100,"vascular":20,"weakest":60,"ganglion":20 ]) );
        
        set( "wealth/silver",1000 );
        set( "tactic_func", "cast_spell" );
        set( "weight",350 );
        set( "times",0 );  
        set_skill("dagger",80 );
        set_skill("dodge",80);
        set_skill("parry",60);
        set_skill("anatomlogy",100);
        set_skill("elemental",80);
        set_skill("target",100);
        set_skill("concentrate",100);
        
        set("aiming_loc","vascular"); 
        set("magic_delay",2);
        set("spells/fireball",4);
        set("spells/sleet",4);
        set("inquiry",([
             "story":"@@ask_story",
             "canteen":"@@ask_canteen"]) );
        
        wield_weapon(TWEP"dagger1");
        equip_armor(TOBJ"hat");
        equip_armor(TOBJ"robe");
}

int cast_spell()
{
        object victim;
        string name;
        if( !(victim=query_attacker()) ) return 0;
        name = victim->query("name");
        
        if( random(15)<2 ) {
        command("cast sleet on "+name);
               return 1;
        }
        else if( random(15)<3 ) {        
        command("cast fireball on "+name);
               return 1;
       }
        else return 0;
}   

int ask_story()
{
    string str;
    
    str = @ALONG
    好吧！孩子，我就告訴你吧！
當年魔族為了王位繼承的問題，分成不同意見的兩派；一派主張王位繼承者以長子為優先
，另一派則主張以魔族純正血統為優先考慮；當時皇后為魔族血統，皇妃為人類血統，但
是皇妃卻比皇后早生下王子。皇后雖然後來也生下王子，但終究是次子；當時宮中便有大
臣向當時的皇帝斐恩貝拉五世建議及早訂定王位繼承人人選，以免日後發生手足相殘的悲
劇；但是皇帝認為來日方長，不須如此急迫的進行此事，因此這份建議就被如此擱下。歲
月匆匆，轉瞬間兩位王子已達行成人禮的年齡，斐恩貝拉五世原本要在行禮的當日宣佈王
位繼承的人選，但是，不幸卻由此發生，皇帝在大禮前夕以３９歲英年突然暴斃，又沒有
留下任何詔書指示繼承人選，繼承問題立刻浮現檯面，成為大臣們爭權奪利的政爭工具；
擁有人類血統皇妃『船穗』不忍心看到自己的孩子淪為政爭下的犧牲品，遂使用陪嫁的三
把主鑰『津名魅』、『龍皇』還有『船穗』，懇求守護靈召喚出三艘飛船，帶著王子、貼
身侍衛及一些家丁，當然還有我，趁著黑夜離開帝國國都。後來只聽說帝國發生內戰，所
為為何，自不在話下。

    當時我們只能漫無目的的四處漂流，雖然我不斷的使用探知魔法，希望能找到一個非
常隱密的居所，過著與世無爭的日子，但卻一直無法如願。過了好長一段日子，王妃病倒
了，依我們的魔法水準仍無法使她恢復健康，王妃知道是天年已盡，大限將至，臨終前交
代：創立一個依東方體制為基礎的王朝，只要保衛自己的居所就行了，不用在意以往那輝
煌的歷史，之後就過世了。一切就像是王妃在指引似的，不久後，我們在這個小島中發現
了非常隱密的森林，於是便決定在此生根了；但是，一切並不如我們想像的完美，就在準
備降落的同時，突然吹起了罕見的龍捲風，彷佛在捍衛這個小島似的。經過一番搏鬥，我
們終於突破暴風圈，降落在這森林中，可是『龍皇』在降落時卻撞到山壁........。當時
王子決定遵從母親遺訓，在此落地生根，因此便在降落後把由主鑰控制的三把主鎖移植在
陸地上，這三把主鎖也就變成了三株神木，但是龍皇由於損毀過重，移植不久後就枯萎了
。

    過了三十年，當我們一切發展都近乎完備的時候，島上原住民蜥蜴人的新興勢力，及
外來的武士團，為了擴張彼此的勢力，逐漸往這個山谷發展，我們為了維護當年王妃的遺
訓，遂起而與之抗爭，數十個年頭下來，三方都付出相當大的代價，直到有一天，蜥蜴人
派出了號稱『最終兵器』的戰士，企圖一舉殲滅我們魔族，在不得以的情況下，我們集合
了三位守護靈的靈力，好不容易終於鎮壓住這隻怪物，但是它的魔力太強，三位守護靈逼
不得以均使用自己主鑰的能力，終於將此怪物封印在『破邪鎮』之中。戰爭發展至此，一
直保持沈默的武士團準備大舉屠殺，讓我們及蜥蜴人都從這個島上消失，就在他們發動攻
勢的前夕，島上發生變動，島中央的山丘突然流出四道水流將島分成四個部份，接著天上
傳出洪亮的神諭：『停止吧 .....！我們是創造這島的神仙，如果不聽勸告，我們將決議
收回這個島嶼.....』 翌日，三族便在中央的山丘上籤訂合約，並立下碑文，在上面宣示
：『和平與此碑共存』。

    孩子，這就是我們發展的經過，你睡著了嗎？？？
ALONG
       ;
      this_player()->more(explode(str,"\n"), 0,1);   
  return 1;
}

int ask_canteen()
{
    object obj;
    obj = new(TOBJ"canteen");
        
    if( (int)this_player()->query("alignment") > 5000 ){
       tell_object(this_player(),
       "鷲羽說：要東西？可以啊，不過你太乖了，我不喜歡乖小孩！\n");   
       tell_room( environment(this_player()),
       "由於"+this_player()->query("c_name")+"看起來太乖了，所以鷲羽不甩他.....:P\n"
       ,this_player() );
       return 1;
    }
    
    if( this_object()->query("times") >= 3 ){
       tell_object(this_player(),
       "鷲羽說：哎呀，真不巧，水壺剛剛都被拿完了...\n"); 
       return 1;
    }
    
    if ( !this_player()->query_temp("get_canteen") ){
    write(@LONG
鷲羽帶著噁心的笑容，拍拍你的頭說：
    你要水壺是吧，我只能給你一個，要是弄破的話，準備拿命來賠吧！
說著順手遞了個乖乖壺給你。
LONG
         );
    obj->move( this_player() );
    this_object()->add("times",1);
    this_player()->set_temp("get_canteen",1);
    return 1;
    }
    else{
    write("鷲羽很不高興的說：你不聽話？完全忽視我是吧？死吧！\n");
    this_object()->kill_ob( this_player() );
    return 1;
    }
}
