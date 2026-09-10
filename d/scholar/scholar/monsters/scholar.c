#include <mudlib.h>
#include <conditions.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Ro Yubin", "駱語冰" );
	add( "id", ({ "ro", "yubin", "scholar" }) );
	set_short( "玉劍書生 駱語冰" );
	set_long("@@query_long");
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 1000 );
	set( "hit_points", 1000 );
	set( "max_hp", 1000 );
	set( "max_fp", 3000 );
	set( "force_points", 3000 );
	set_natural_armor( 120, 50 );
	set_natural_weapon( 28, 10, 15 );
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "pie", 20 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "kar", 30 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "inner-force", 100 );
	set_skill( "tactic", 100 );
	set( "tactic", "melee" );
        set( "tactic_func", "my_tactic");
        set( "flute",0);
	set( "force_effect", 8 );
	set( "force_type", "cold" );
	set( "wealth/gold", 300 );
	set( "attack_skill", "scholar/poem" );
	set( "scholar_gonfu/poem", 50 );
        set( "class", "scholar");
	set( "special_defense", ([ "all": 50,"none":60 ]) );
	set( "aim_difficulty", ([ "vascular":80 ]) );
   
//	wield_weapon( "/d/scholar/scholar/weapons/ebonysword" );
}

string query_long()
{
  if (!(this_object()->query("flute")))
    return  "你看到一位相貌俊雅的少年書生，坐在一張黑檀木長桌旁邊，桌上擺著一隻古玉蕭，\n"+
  "手中一本殘破不堪的舊書，正聚精會神地讀著。\n";
  else
    return "你看到一位相貌俊雅的少年書生，坐在一張黑檀木長桌旁邊，一隻手拿著一隻古玉蕭，\n"+
  "另一隻手中拿著一本殘破不堪的舊書，正聚精會神地讀著。\n";
}

int my_tactic(string arg)
{
  object ob;
  int rrr;

  ob=this_object()->query_attacker();
  if (this_object()->query("flute")) {
    rrr=random(15);
    if (rrr<4) {
      tell_room(environment(this_object()), set_color(
         "\n駱語冰突然把古玉簫拿到嘴邊吹出一陣奇異的聲音.....\n\n"
      ,"HIR",ob));
    }
    if (rrr<5) {
      switch (rrr) {
       case 0:
         tell_object(ob,set_color( "你見到地面突然裂開，大地精靈從中衝了出來向你施展它的必殺技：十字鎖喉反扣。\n","HIM",ob));
         tell_room(environment(this_object()),set_color("你見到地面突然裂開，大地精靈從中衝了出來向"+ob->query("c_name")+"施展它的必殺技：十字鎖喉反扣。\n","HIM",ob),ob);
         ob->block_attack(2);
         ob->set_temp("msg_stop_attack", "（ 你現在被大地精靈扣住，動彈不得，無法攻擊 ）\n");
         command("scholar 可惡的"+(string)ob->query("c_name")+"竟敢跑到書生公會來撒野 !!\n");
         break;      
       case 1:
         tell_object(ob,set_color("突然晴天一聲霹靂，火精靈挾著雷霆之勢從天而降，火精靈把口一張，從嘴裡向你射出一團火□。\n","HIR",ob));
         tell_room(environment(this_object()),set_color("突然晴天一聲霹靂，火精靈挾著雷霆之勢從天而降，火精靈把口一張，從嘴裡向"+ob->query("c_name")+"射出一團火□。\n","HIR",ob),ob);
         ob->receive_special_damage("fire",20);
         command("scholar 書生們 ! 等我把"+(string)ob->query("c_name")+"給宰了，你們就可以來分裝備了 !!\n");
         break;
       case 2:
         tell_object(ob,set_color( "你感覺到一道劍氣直射而至，劍魂化成一把寶劍在空中飛舞著，突然，寶劍一氣化三元，三把寶劍劍鋒向你吐出紅藍綠三色劍芒。\n","HIW",ob));
         tell_room(environment(this_object()),set_color( "你感覺到一道劍氣直射而至，劍魂化成一把寶劍在
空中飛舞著，突然，寶劍一氣化三元，三把寶劍劍鋒向"+ob->query("c_name")+"吐出紅藍綠三色劍芒。\n","HIW",ob),ob);
         BLEEDING->apply_effect(ob,4,5);
         if ((string)ob->query("class")=="scholar")
           command("scholar 想不到 ... "+(string)ob->query("c_name")+"竟是我們公會里的叛徒，那我就不客氣了 !!\n");
         else
           command("scholar 嘿嘿 ! 不要命的"+(string)ob->query("c_name")+"，不給你一點顏色瞧瞧，你是不會乖乖聽話的 !!\n");
         break;
       case 3:
         tell_room(environment(this_object()),set_color("你見到天空一朵烏雲飄來，水精靈從中飄了出來，水精靈用手觸摸駱語冰的傷口之後，水精靈又隨著烏雲飄走了。\n","HIB",ob));
         this_object()->receive_healing(20);
         command("scholar 書生們 ! 大家來ＰＫ"+(string)ob->query("c_name")+"吧 !!\n");
         break;
      default: 
         command("scholar "+(string)ob->query("c_name")+" !! 明年的今天就是你的忌日 !!\n");
         break;
      };
    }
    return 0;
  }
  tell_room(environment(this_object()),"玉劍書生 駱語冰從長桌上拿起古玉蕭\n");
  ob=new("/d/scholar/scholar/weapons/flute");
  ob->move(this_object());
  command("wield flute");
  ob=new("/d/scholar/jade_mark");
  ob->move(this_object());
  this_object()->set("flute",1);
  return 1; 

}

void die()
{
	object killer,weapon,ob;

	killer = query("last_attacker");
	if ( !killer) {
		::die();
		return ; 
	}
        command("scholar "+(string)killer->query("c_name")+" !! 雖然我不小心被你打敗，但我的冤魂會永遠的纏著你的 !!!\n");
        ob=query("guild");
        ob->remove();
        weapon=query("weapon1");
        weapon->set("killer",killer);
	::die();
	return;
}
