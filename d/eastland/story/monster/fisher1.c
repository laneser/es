#include "../story.h"
inherit MONSTER;

void create()
{
    ::create();
    set_level(16);
    set_name( "old fisher", "老釣者" );
    add ("id", ({ "fisher" }) );
    set_short( "老釣者");
    set_long(@LONG
你眼前所見的一位年逾半百的老人，頭戴著一頂草帽，背披著一件蓑衣，赤著雙足
，手持著一根四尺長的釣杆，除了身旁的漁簍以及些許釣餌之外，再無它物。不仔
細一看，你還不發現那老者的手臂似乎有著銀製的東西，在蓑衣的遮蓋下發出微微
的亮光。老釣者眼睛半睜半閉，態度從容有餘，好整以暇地凝視著釣杆前頭，看他
神情，容光煥發，兩隻半眼炯炯有神，想必是個非常人。
LONG
            );
    set("unit","位");
    set("race","human");      
    set("age",70);
    set("gender","male" );
    set("alignment",500);
    set("weight",1000);
    set_perm_stat("str",30);
    set_perm_stat("int",25);
    set("hit_points",550);
    set("max_hp",550);
    set("max_fp",200);
    set_natural_armor(70,25);
    set_natural_weapon(15,10,20);
    set("tactic","assault");
    set_skill("blunt",60);
    set_skill("dodge",70);
    set_skill("parry",70);
    set("special_defense", ([ "all": 30,"none":30]) );
    wield_weapon(SWEA"fisher_staff");
    equip_armor(SARM"fisher_armband");
    set( "tactic_func", "my_tactic" );
    set("chat_chance",1);
    set("chat_output",({
       "老釣者喃喃自語地道：該怎麼出去(how_to_out)咩?\n"
    }) );
    set("inquiry", ([
       "how_to_out":"@@ask_help",
      "ghost_spell":"@@ask_spell"
    ]) );
}
void ask_spell(object asker)
{
   int i,max;
   object spell,*eq;
   if ( !asker->query_temp("wizelder") ) {
      tell_room(environment(),"老釣者說道：我不知道。\n");
      return ;
   }
   spell=new(SWITEM"spell1");
   spell->move(environment());
   write(@LONG
   
老釣者說道：唉，我就是巫真的師父，多年前因為犯錯被天帝懲罰。多年來我
            一直想贖罪，好能返回天都，卻不幸死在「妖□ 谷辰」手裡，你
            現在跟我說話的是我臨死前用一塊石頭變成的替身。希望我英靈
            佑你，令你順利剷除谷辰.........


老釣者說完之後留下了一張「滅魔符」就變成一塊石頭滾到溪裡去了。

　　   
LONG
   );   
   asker->delete_temp("wizelder");
   this_object()->move("/u/d/dony/home/workroom");
   eq=all_inventory(this_object());
   max=sizeof(eq);
   for ( i=0;i<max;i++ )
     eq[i]->remove();  
   this_object()->remove();
}
void ask_help(object asker)
{
   write(@LONG
老釣者說道：不久前來了一位術師名叫「神算小瓜」，因感太多人喪生在
　　　　　　這個溪谷，特地在此施了咒語，就如你剛才被一陣突如其來
　　　　　　的風吹起，那就是咒語之一。而飛起的咒語好像是叫做：「
　　　　　　神恩如海天威如嶽繫系矩忙羅」，我也不太清楚，你最好去
            問他本人吧。

老釣者說完便繼續釣魚。

LONG
   );
}
int my_tactic()
{
     object victim;
     
     if (!(victim= query_attacker())) return 0;
     if ( random(30)>8) return 0;
     victim->receive_damage(15+random(10));
     tell_room(environment(this_object()),
           "\n\n老釣者把釣杆轉成一個大圓，釣線如長舌吐信一般向敵人掃去！\n\n");
     return 1;
}                  