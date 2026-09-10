#include <mudlib.h>
        
inherit MONSTER;

void create ()
{               
       ::create();
       set_level(13);
       set_name("wild insect","熱帶昆蟲" );
       add("id",({"insect"}) );
       set_short( "熱帶昆蟲" );
       set("unit","只");
       set_long(@LONG
一隻奇形怪狀的昆蟲；它前面和後面各長著一個墨綠色的小頭，頭上的小眼骨嚕嚕
地正盯著你瞧，好像有什麼企圖；反觀它的身子卻出乎意料的大，足足有二十公分
長；在它身子旁，另長著五對長長的足肢，足肢滿是毛絨絨的綠毛，可怖極了！看
別看它一副雍腫的模樣，行動起來卻迅速已極！不曉得它是什麼動物？唉呀，它正
向你攻擊！
LONG
       );
       set("killer",1);
       set("hit_points",80);
       set_perm_stat("str",20);
       set_natural_armor(65,0);
       set_natural_weapon(18,12,21);
       set_c_verbs(({"%s用它的前足肢向%s攻擊",
                     "%s用它的後肢狠狠向%s一踹",
                     "%s用它的頭部撞向%s"
       }));
       set_c_limbs(({"身體","頭部","足肢"}));
}
void kill_reward(object killer)
{
   switch( random(3) ) {
   case 0: killer->add("hit_points",-100);
           break;
   case 1: killer->add("force_points",-150);
           break;
   default: killer->add("spell_points",-150);
           break;    
   }
   ::kill_reward(killer);
}
void die()
{
   tell_room(environment(this_object()),
      "唉呀！熱帶昆蟲的身體脹成一個大球，忽然，大球破掉並且流出一堆綠色液體！！\n\n");
   set("alt_corpse","NONE");
   ::die(1);
}
