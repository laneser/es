#include "../island.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "e shi", "一虛" );
	add ("id", ({ "e", "shi","monk" }) );
	set_short( "一虛" );
	set_long(@LONG
一虛是少林百年難得一見的天才，他精通五種七十二絕技，但他的年紀
卻很輕，大約近四十歲而已，雖然他武功很好，但是他最感興趣的是歷
史研究和古蹟發掘，現在他在這裡研究這個島上的傳說，最近他好像有
所發現，所以顯得很高興的樣子，你可問他有關研究(research)的事。
LONG
	);
	set( "alignment",1000);
	set( "gender", "male" );
	set( "race", "lizardman" );
	set( "unit", "位" );
	set_perm_stat( "dex", 29 );
	set_perm_stat( "str", 27 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "con", 24 );
	set_perm_stat( "piety", 29);
	set_perm_stat( "karma", 30);
	set_skill("unarmed",100);
	set_skill("dodge",100);
        set_skill("parry",80);
	set("special_defense", ([ "all":40, "none":30 ]) );
	set("aim_difficulty", ([ "critical":45, "vascular":40, ]) );
	set("max_hp", 1000);
	set("max_fp", 5000);
	set("hit_points", 1000);
	set("force_effect", 5);
	set("force_points", 5000);
	set("attack_skill",CLASS"dragon_claw");    
	set("defense_skill",CLASS"body_def");
	set("monk_gonfu/dragon-claw",100);
	set("monk_gonfu/body-def",100);
	set("monk_gonfu/power-finger",100);
	set("monk_gonfu/bolo-fist",100);
	set("monk_gonfu/keep-flower",100);
	set("wealth/gold", 10);
	set_natural_weapon( 100, 15, 36 );
	set_natural_armor( 40, 15 );
        set("weight", 500);
        set("chat_chance",20);
	set("att_chat_output", ({"\n", "\n一虛喝道 ：『這便是龍爪手!!!』\n\n " 
	}) );
	call_out("mygonfu1",25);
       equip_armor( IOBJ"cloth01.c" );
       equip_armor( IOBJ"boots01.c" );
       set("inquiry",([
            "research": "@@research",
            "war"     : "@@war",
            "peace"   : "@@peace"
               ]) );
}
void mygonfu1()
{ 
  delete("att_chat_output");
  set("att_chat_output",({"\n","\n一虛斷喝一聲：『看看大力金剛指吧！』\n\n"}));
  delete("attack_skill");
  set("attack_skill",CLASS"power_finger");
      call_out("mygonfu2",25);
 } 
 void mygonfu2()
 {
   delete("att_chat_output");
   set("att_chat_output",({"\n","\n一虛用宏偉的聲音說：『見識見識般若掌吧！』\n"}));
   delete("attack_skill");
   set("attack_skill",CLASS"bolo_fist");
   call_out("mygonfu3",25);
}
void mygonfu3()
{ 
    delete("att_chat_output");
    set("att_chat_output",({"\n","\n一虛微笑說道：『你想接接捻花指嗎？』\n\n"}));
    delete("attack_skill");
    set("attack_skill",CLASS"keep_flower");
    call_out("mygonfu4",25);
    
}
void mygonfu4()
{
    delete("att_chat_output");
    set("att_chat_output",({"\n","\n一虛狂喊道：『小子！讓龍爪手來收拾你吧！』\n\n"})); 
    delete("attack_skill"); 
    set("attack_skill",CLASS"dragon_claw");  
    call_out("mygonfu1",25);
}  

void research()
{
  write(@LONG
一虛埋頭整理著「一大堆」的資料，頭也不抬的說：
     『這位兄臺，您是要問戰爭(war)史呢？還是問和平(peace)史？』
LONG
       );
  return ;
}

void war()
{
  write( set_color(@LONG
  
一虛突然罵道：『啥！ 哇勒熱開水！我還在整理啦！ 打你唷！』
 
說完輕輕在你胸口按了一掌，你覺得好像受了內傷，最好去看醫生。

LONG
      ,"HIM") );
      this_player()->set("hit_points",(int)this_player()->query("hit_points")/10 );
      if( (int)this_player()->query("force_points") )
      { 
        this_player()->set("force_points",(int)this_player()->query("force_points")/10 );
      }
         this_player()->set("spell_points",(int)this_player()->query("spell_points")/10 );
       return ;   
}

void peace()
{
  write(@LONG
  一虛像是遇到知己般的擁抱著你，眼框中滲著淚水說：

    終於......有人關心和平了；根據我的研究，這金身原是『蜥蜴人聖騎士』
，當時是該族中最強的戰士，同時由於其德高望重，不插手無益的爭鬥，使他亦
受到其他二族的尊敬；正當三族正僵持不下時，他帶著人見人怕的『創世神戟』
出來進行調停工作，但魔族的人卻誤以為他有私心，因而偷襲施予石化魔法，將
其元神吸走並加以監禁，後來在神仙顯靈下雖獲得和平，但其嫌隙仍在，總之，
目前的和平是極不穩定的，據我推測，只要元神回到金身，使聖騎士復活，並向
他祈求(beg)，不然戰爭還是隨時會爆發的！  
LONG
      );
  return ;
}
