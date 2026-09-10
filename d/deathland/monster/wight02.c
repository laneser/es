#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create()
{
	::create();
	set_level(17);
	set_name( "wight Leit", "怨靈萊特" );
	add("id",({"wight","leit"}));
	set_short( "a wight named Leit", "怨靈萊特" );
	set_long(
		"a terrible evil wight.\n",@DESC
一個怨靈, 他的名字叫作萊特. 他已經遊遊蕩蕩好幾年了, 似乎他的靈魂無
法安息的樣子.
DESC
	);
	set( "gender", "male" );
	set( "alignment", -480 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "kar", 15 );
	set_skill( "dodge", 100 );
	set( "tactic_func", "my_tactic" );
    set_natural_weapon( 35, 16, 27 );
	set_natural_armor( 70, 25 );
    set( "unbleeding",1);
    set("chat_chance",15);
    set("chat_output",({
        "Wight cries.\n",
        "這怨靈哭喊著, 我須要安息......\n"
        }) );
    set("can_be_duranced",1);
    set("inquiry",([
        "muse":"@@ask_muse",
        "brother":"@@ask_brother",    
        "kanni":"@@ask_brother",
        "island":"@@ask_island",
        ]));
}

void ask_muse(object who)
{
     tell_object(who,@MSG1
謬思泉, 花了我兄弟兩人半生的時間才發現的,你如果想要知道在那裡的話.
你必須幫助我與我的兄弟肯尼.
MSG1
     );
}

void ask_brother(object who)
{
     object *items;
     int i;
     
     tell_object(who,@MSG2
我的兄弟肯尼, 當大災難來臨的時候, 他逃了出去, 為了拯救這個城市, 他又
去到謬思泉, 但是我能感覺到他被困在灰暗小島上, 希望你能幫助他. 如果你
能幫助我的兄弟的話, 我將告訴你謬思的位置.
MSG2
     );
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) {
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/leit_amulet"))
               return;
           else {
             items[i]->set("quest_item/leit_amulet",1);
             who->set_explore("deathland#31");
             tell_object(who,
             "拿著我的護身符,當肯尼看到這護身符的時候,他就會知道你的來意了.\n"
              );
             }
         }
         
}

void ask_island(object who)
{
     tell_object(who,@MSG3
灰暗小島, 這個島位於死亡之河的中心, 雖然死亡之河數次的改道, 它仍然未被
河水淹沒. 或許它是謬思泉的入口吧! 希望你能找得到這個島..
MSG3
     );
}

int my_tactic()
{
	object victim;

	if( random(20)>4 || !(victim= query_attacker()) ) return 0;
    else {
      tell_object(victim,
          "邪惡怨靈發出可怕的笑聲,並且以它如風的速度向你飛來吸取你的生命力.\n"
          );
      tell_room(environment(this_object()),
        sprintf("邪惡怨靈發出可怕的笑聲,並且以它如風的速度向%s飛去.\n",victim->query("c_name"))
          ,({victim,this_object(),}) );
      victim->receive_special_damage("evil",10+random(17));
      report(this_object(),victim);
      return 1;
      }
}

void durance(object player,object box)
{
    tell_object(player,
    "你把萊特捉進了瓶子裡.\n");
    tell_room(environment(player),
        "萊特被"+player->query("c_name")+"給捉進了瓶子.\n",
      player );
    box->set("quest_action/bottle_lock","leit");   
    return ;
}
