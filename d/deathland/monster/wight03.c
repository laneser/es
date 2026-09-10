#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "wight Kanni", "怨靈肯尼" );
	add("id",({"wight","kanni"}));
	set_short( "a wight named Kanni", "怨靈肯尼" );
	set_long(
		"a terrible evil wight.\n",@DESC
一個怨靈, 他的名字叫作肯尼. 他已經遊遊蕩蕩好幾年了, 似乎他的靈魂無
法安息的樣子.
DESC
	);
	set( "gender", "male" );
	set( "alignment", -480 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 22 );
	set_perm_stat( "kar", 15 );
	set_skill( "dodge", 100 );
	set( "tactic_func", "my_tactic" );
    set_natural_weapon( 55, 26, 37 );
	set_natural_armor( 70, 25 );
    set( "unbleeding",1);
    set("inquiry",([
        "muse":"@@ask_muse",
        "brother":"@@ask_brother",    
        "leit":"@@ask_brother",
        "island":"@@ask_island",
        "crystal":"@@ask_crystal",
        "secret":"@@ask_secret",
        ]));
}

void ask_brother(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/leit_amulet")) {
              tell_object(who,@MSG1
肯尼說:我的兄弟萊特叫你來找我的嗎? 
唉....
其實一切都已經太遲了,我們的城市經早就毀了, 只是我不甘心. 我一定
要到達謬思泉, 找到起死回生的泉水.
肯尼嘆了一口氣又繼續地說道:
謬思泉其實有著很大的秘密的, 這是我與我兄弟萊特用了無數的時間所發
現的. 它的泉水有著好幾種顏色, 而每一種的效用都有很大的不同, 每一
種都有它特殊的效果. 如果一不謹慎的話, 甚至於有死亡的危險, 當年我
們也嚐盡了苦頭. 如果你要喝的話, 你必須很小心的去嘗試.
不過這些對我已經不重要了, 我現在只希望我能夠在看到謬思泉的泉水,
為了它, 我花了半生的光陰. 現在的我就是為了它而不肯安息的..
希望你能夠幫助我..
MSG1
              ); 
              call_out("quest_info_1",5,who);
               return;
              }
     tell_object(who,
       "肯尼完全不理會你的問題.\n"
       );
     return;
}

void ask_muse(object who)
{
     tell_object(who,@MSG2
謬思泉, 花了我兄弟兩人半生的時間才發現的,你如果想要知道在那裡的話.
你必須幫助我與我的兄弟萊特.
MSG2
     );
}

void ask_island(object who)
{
     tell_object(who,@MSG3
灰暗小島, 這個島位於死亡之河的中心, 雖然死亡之河數次的改道, 它仍然未被
河水淹沒. 假使你已經搜索過這個島, 你應該知道有一個力場阻擋著你的去路. 
那就是謬思泉的入口....
MSG3
     );
}

int my_tactic()
{
	object victim;

	if( random(20)>5 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim,
          "邪惡怨靈發出可怕的笑聲,並且以它如風的速度向你飛來吸取你的生命力.\n"
          );
      tell_room(environment(this_object()),
          "evil shadow laughs and drains the lifeforce of "+ victim->query("name")+".\n",
          "邪惡怨靈發出可怕的笑聲,並且以它如風的速度向"+victim->query("c_name")+"飛去.\n"
          ,({victim,this_object(),}) );
      victim->receive_special_damage("evil",30+random(27));
      report(this_object(),victim);
      return 1;
      }
}

void quest_info_1(object who)
{
     tell_object(who,@MSG4
仔細聽好, 首先我要告訴你進入謬思泉的方法
你必須找到三個不同顏色的魔水晶, 而其中一顆紫水晶已經被我收藏在我的城
市的市議會之中. 而黑水晶與綠水晶分別由沼澤與森林的守護獸所持有, 你必
須設法拿到它, 當你拿到三顆水晶 ( crystal )後, 再來找我吧, 我將告訴你
下一個步驟.
MSG4
     );
     return;
}

void ask_crystal(object who)
{
     object *items,*crystal;
     int i,j,k,num;
     
     crystal=allocate(3);
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) {
           if (items[i]->query("quest_item/leit_amulet")) {
             for(j=0;j<sizeof(items);j++) 
               if ( (num=(int)items[j]->query("echo_crystal")) ) 
                 crystal[num-1]=items[j];  
             for(j=0;j<3;j++)
               if (!crystal[j]) { k=1;break; } 
             if (!k) {
                for(j=0;j<3;j++)
                  crystal[j]->remove();
                tell_object(who,
                "很好,你找到了這三顆水晶, 現在我將為你製造一個水晶磁卡.\n稍等.....\n"
                );  
                call_out("quest_info_2",10,who,items[i]);
               }
             else
             tell_object(who,
             "當你找齊三個水晶再來吧! 進入謬思泉須要這三顆魔水晶.\n"
             );  
             return;
           }
        else break;
        }
     tell_object(who,
       "肯尼完全不理會你的問題.\n"
       );
     return;           
}

void quest_info_2(object you,object box)
{
     
     tell_object(you,@MSG5
我把水晶磁卡交給你了, 這個水晶將幫助你通過在灰暗之島北方山嶽的力場.
而謬思泉的入口就在那裡了.......
然而你還須要一個特殊的容器去承裝謬思的泉水來給我喝, 那個瓶子隱藏在沼
澤之中, 經過了沼澤經年累月的侵蝕, 它已經可以抵擋住謬思泉的威力了, 你
必須找到那瓶子, 而這水晶磁卡將會與瓶子起共鳴. 當你找到了瓶子的時候, 
記得再回來找我, 我將告訴你我所需要的以及謬思泉的大秘密(secret).
MSG5
     );
     you->set_explore("deathland#32");
     box->set("quest_item/crystal_card",1);
     if ((int)you->query_quest_level("queen_smile") < 2 ) 
       you->finish_quest( "queen_smile" , 2 );
     return;
     
}

void ask_secret(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/black_bottle")) {
              tell_object(who,@MSG6
你發現那瓶子了, 很好, 當你到了謬思泉之後,請用這瓶子裝滿(fill)
白色的泉水, 再來給我, 我的心願也就完成了.
MSG6
              ); 
              call_out("quest_info_3",5,who);
               return;
              }
     tell_object(who,
       "肯尼不回答你的問題.\n"
       );
     return;
}

void to_check_something()
{
     object *items,who;
     int i;
     
     who=this_player();
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) {
           if ( (string) items[i]->query("quest_action/bottle_lock")== "leit" ) { 
             tell_object(who,
             "你把我的兄弟帶來了嗎??,請釋放他好嗎?\n"
             );
             }
           else if ((int)items[i]->query("quest_action/muse_filled")==8) {
             tell_object(who,@MSG7
當你走進這裡時, 肯尼發現你已經裝滿了白色的謬思泉水....
肯尼說: 
謝謝你的幫忙, 我的心願終於能夠完成了........
這時肯尼喝下了這泉水.
肯尼再說道:
我的心情已經漸漸的平靜了, 我想這世間已經沒有甚麼值得留戀的了,
不過我希望你能幫我最後一件事, 我的兄弟萊特仍然痛苦地活在這個世
界上, 我必須開導他, 希望你能把他帶來.
這時肯尼把一個小小的瓶子拿給你.並說
這個是一個古代的魔法瓶, 可以把死去的靈魂給禁錮住, 我想用這個你
能把我兄弟萊特的靈魂給帶來. 但是你必須知道它的力量與使用方法.
再度麻煩你了.
MSG7
             );
             items[i]->set("quest_action/muse_filled",0);
             items[i]->set("quest_item/ancient_bottle",1);
             who->set_explore("deathland#34");
             }
           return;
           }
     return;
}

void init()
{
   ::init();
   to_check_something();
}
