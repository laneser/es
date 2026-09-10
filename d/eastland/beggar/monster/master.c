#include "/d/eastland/beggar/dony.h" 

object ob1;

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "Master of beggar","丐幫幫主 震八方" );
	add ("id", ({"master"}) );
	set_short( "丐幫幫主 震八方" );
	set_long(@C_LONG
震八方看起來約莫五、六十歲年紀,長得熊腰虎背、豹頭燕頜,太陽穴高高鼓起,雙
眼中隱隱泛出紫氣, 一看就知道功力高深而且修為不凡。他為人豪爽又樂意助人,
在幫中頗得人緣,同時他被許為丐幫百年來武功最為出類拔萃, 一手『降龍十八掌
』更是打遍天下無敵手,即使是這樣仍然有解決不了的問題 ( trouble ) 。
C_LONG
	);
	set( "unit", "名" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "kar", 30 );
        set("weight",800);
	set_skill( "dodge", 100 );
	set_skill( "unarmed", 100 );
        set_skill( "unarmed-parry",90);    
	set( "special_defense", ([ "all": 52,"none":50,
	     "monk":50,"scholar":50]) );
	set("aim_difficulty", 
	   ([ "critical":60, "vascular":80, "ganglion":80, "weakest":80 ]) );
	set("stun_difficulty",50);
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 5000 );
	set("max_hp", 1200);
	set("hit_points",1200);
	set("max_fp",1000);
	set("force_points",1000);
	set_natural_armor( 30,70 );
	set_natural_weapon( 100,50,65);
	set( "wealth/gold", 300 );
        equip_armor(DARMOR"wind_cloth.c");
        equip_armor(DARMOR"wind_belt.c");
        equip_armor(DARMOR"wind_helmet.c");
        equip_armor(DARMOR"wind_ring.c");
	set_c_verbs( ({ "%s身體挺進，一招 『見龍在田』向%s遞了過去", 
	                "%s身子下沈，臨空飛起使出 『潛龍勿用』 打向%s",
		        "%s往前一縱，使出 『飛龍在天』 往%s飛撲而去",
		        "%s橫飛而來，滿天手影打出 『終日乾乾』 攻向%s", 
		        "%s以退為進，運起 『突如其來』 猛砍%s",
		        "%s忽然狂笑一聲，突然使出 『戰龍在野』用雙手拍向%s" }) );
        set( "inquiry", ([
                  "trouble":"@@ask_trouble",
                 "password":"@@ask_password",
                      "war":"@@ask_war"
              ]) );
	set( "tactic_func", "my_tactic" );
}

void ask_trouble( object asker )
{
    tell_object( asker ,
            "幫主 震八方說道:唉,前幾天不小心我把打狗棒給遺失了。在幫中打狗\n"
            "                棒象徵著幫主地位,不幸的是再過幾天就要舉行『祭\n"
            "                祖大典』了,沒有打狗棒那麼我的地位就會受到懷疑\n"
            "                ,你能幫我找回來嗎? 我記得是和全副幫主 ( chan \n"
            "                ) 喝完酒後就遺失的。\n"
            );
}
void ask_war()
{
write(@C_LONG
幫主 震八方慘然道:唉,在距今三十多年前,我的同門師兄全冠清因不服師父將幫主之位
                  傳授給我,時時刻刻都有不忿之色,我念在他是我師兄份上也就不大
                  去理會。沒想到在二十年後,他竟然發難,糾結外面的人對我展開一
                  連串的攻擊,一一剪除我身邊的人,那時我的處境甚是兇險。好在, 
                  他們之間起了內鬨, 這一場叛變才得以終止。我為了要安撫參與這
                  件叛變的弟子,提拔師兄的兒子為副幫主之位,他的兒子也不負我所
                  託近年來幫我把幫內的事務整頓的好興旺。 當時他年紀還小,我並
                  沒有向他說明他父親的事, 我心想不跟他說更或許他不會重蹈他父
                  親的路子,希望以後再也不會有那樣的叛變事情發生了。
C_LONG
    );
}
int accept_item(object me, object item)
{
      string name,my_name;
      
      name=(string)item->query("name");
      my_name=(string)me->query("name");
                  
      if (name!="dog blunt")
         return 0;
                                 
//      if( (int)me->query_quest_level("dony1") ) {
      if ( me->query("finish_dony") ) {
         tell_object( me,
            "幫主 震八方說道:謝謝你仗義相助。\n");
         return 0;
      }                                          
      
      if ( ( item->query("master") ) != my_name ) {
         tell_object( me,
            "幫主 震八方說道:你這是打那兒來的棒子啊?\n");
         command("give dog blunt to "+my_name);
      }
      else {
//         me->finish_quest("dony1", 1);
         me->set("finish_dony",1);
         me->gain_experience(3000);
         item->remove();
         tell_object( me,
            "幫主 震八方接過你的棒子說道:你什麼都不用說了,副幫主已經全都告訴我了。\n"
            "                            唉,或許我該跟他說明一切才不致於有這樣的事\n"
            "                            發生。謝謝你仗義相助!!\n");
         tell_object( me,
            "\n\n[你完成了 震八方 的任務，得到 3000 點經驗]\n\n");
         if ( ( me->query("class") ) =="scholar" ) {
            tell_object( me,
              "幫主 震八方說道:對了,我還有一件東西放在陸阿巧那兒,你幫我去問問看。\n");
            command("grin "+my_name);}
      }
         return 1;
}
void ask_password( object asker )
{
       if ( present("password",asker) ){
       command("look "+asker->query("name"));
       tell_object( asker,
         "幫主 震八方說道:你身上不是有手諭了嗎?\n");
       return ;  
    }
    if ( query("be_asked") ){
       command("sigh "+asker->query("name"));
       tell_object( asker,
         "幫主 震八方說道:你來晚了,我才把手諭給別人\n");
       return ;
    }
    if ( asker->query_temp("wu_asked")){
       tell_object( asker ,
            "幫主 震八方說道:哦,你要手諭?給你,不要弄丟喔。\n");
       ob1=new(DITEM"password");
       ob1->move(this_object());
       command("give password to "+asker->query("name"));    
       set("be_asked",1);
       call_out("recover",1800,this_object());
       return ;
    } 
    tell_object( asker ,
      "幫主 震八方說道:小孩子沒事問什麼手諭?去去去.\n");
}
void recover( object obj)
{
    obj->delete("be_asked");
}

int my_tactic()
{
     object victim,*t_item,*wea1,*wea2;
     int i;

	if (!(victim= query_attacker())) return 0;
	
	if ( query("force_points") < 100 ) set("force_points",1000);
	
	if( random(10)>8 ){
	   tell_room(environment(this_object()),
              "震八方大吼一聲，二式『亢龍有悔』後招疊前招向"
              +(string)victim->query("c_name")+"排山倒樹而來\n\n",victim);
           tell_object(victim,
              "震八方大吼一聲，二式『亢龍有悔』後招疊前招向你攻來,頓時你感到胸口鬱悶無比!!\n\n");
           victim->receive_special_damage("fire",50);
       	   report(this_object(),victim);
              wea1=victim->query("weapon1");
              wea2=victim->query("weapon2");
              if (wea1) wea1->unwield(1);
              if (wea2) wea2->unwield(1);
          return 1;
        }
       else { return 0;}       
}
