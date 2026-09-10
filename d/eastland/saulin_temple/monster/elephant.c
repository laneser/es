#include "../saulin_temple.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(5);
	set_name( "A huge elephant", "大白象" );
	add( "id", ({ "elephant"}) );
	set_short( "大白象" );
	set_long(@ELEPHANT
你看到一頭超級大白象，頭上戴著黃金的垂飾，背上安著一張青玉座椅，它應該是
某位神的座騎。這隻大象看起來很安詳，正輕擺著兩隻大耳朵用長長的大鼻子拔著
樹葉吃，不過它的吃相實在有夠難看，東拉西扯的把美好的樹林破壞的一榻糊塗，
你最好趕快把這隻貪吃傢伙趕回它主人(master)身邊。  
ELEPHANT
	);
     set_perm_stat("dex", 5);
     set_perm_stat("str",10);
     set_perm_stat("kar",10);
     set_perm_stat("int", 5);
     set_perm_stat("pie",10);
     set_skill("dodge", 30);
     set("alignment",2000);
     set("max_hp",300);
     set("hit_points",300);
     set_natural_weapon(9, 4, 8);
     set_natural_armor(20, 18);
     set("special_defense", ([ "all" : 10, ]) );
     set("aim_difficulty", ([ "critical" : 10, ]) );
     set("exp_reward", 250);
     set("alt_corpse", SAULIN_MONSTER"fire_elephant");
     set_c_verbs(({ "%s用腿踩%s", "%s用頭撞%s", "%s用身體壓%s" }));
     set_c_limbs(({ "身體", "頭部", "腳部", "手臂" }));
     set ("c_death_msg",
  "%s大叫說: 可惡，竟敢欺負我？你不要命了! 讓我送你下地獄吧! 有種的不要走!\n"
     );
	 set( "inquiry", ([
		  "master" : 
	      "我的主人就是大名鼎鼎的西天如來佛 .......\n" 
	      "            座下的普賢菩薩，所以你可千萬不要欺負我喔!!\n"   ]) );
      set("tactic_func","crying");
}

int crying()
{
    if( random(20)<12 ) return 0;
    tell_room( environment(),
      "\n大白象叫道: 你做什麼？快停手! 否則我要生氣嘍!!\n" ,
      this_object()
    );
	return 1;
}

void die()
{
    tell_room( environment(this_object()),@C_DIE_MESSAGE
      
  大象慘叫一聲，搖身一變，化身成為一隻銀色巨象，它精光四射的眸子瞪著你
    ，紅紅的兩道烈焰隨著憤怒的呼吸飛揚在空中。
  它大叫道：可惡的白痴 !! 納命來 !! 
  
C_DIE_MESSAGE
      ,this_object()
    );
    ::die(1);
}
