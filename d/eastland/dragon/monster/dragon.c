#include "../../layuter.h"
inherit MONSTER ;

void create ()
{
        ::create();
        set("exp_reward",60000);
        set_level(19);
        set_name( "evil dragon", "孽龍恨天" );
        add ("id", ({ "dragon" }) );
        set_short(" 孽龍恨天");
        set("unit", "位");
        set("alignment",-2000);
        set("weight",2000);
        set("wealth/gold",1000);
        set_long(@C_LONG
它是一隻十分邪惡的惡龍，它曾經殘殺無數的生靈因而被玉帝將其封於此處
，它並不好惹曾有無數的勇者死於其手。
C_LONG
        );
        set_perm_stat("int", 30);
        set_perm_stat("str", 30);
        set_perm_stat("dex", 30);
        set_perm_stat("kar", 30);
        set_perm_stat("pie", 30);
        set_perm_stat("con", 30);
        set("max_hp",2500);
        set("hit_points",2500);
        set_natural_weapon( 95, 50, 80 );
        set_natural_armor( 100, 70 );
//	set("unbleeding",1);
        set("special_defense",
        	([ "cold" : 90, "fire" : 70, "all" : 70 , "none" : 80 ]));
        set_skill("dodge",70);
        equip_armor(Lditem"dragon_amulet");
        set("tactic_func","special_attack");
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        set_c_verbs(({"%s用它的利爪向%s抓去","%s伸出它那長滿利牙的嘴巴向%s咬去" }));                
}

void announce( string c_msg )
{
	object *usr;
	int i;

	usr = users();
	for( i=0; i<sizeof(usr); i++ ) {
		if( !environment(usr[i]) ) continue;
		tell_object( usr[i], c_msg);
	}
}
       
       
int special_attack()
{// 20% use it! damage 40-70.
    object env,*inv,*victim;
    int i;
    env=environment(this_object());
    inv=all_inventory(env);
    if(random(10)<8) return 0;
    tell_room( environment( this_object() ), 
      "孽龍以它的尾巴，掀起滔天巨浪，滾滾湖水淹沒湖的四周並強烈地衝擊岸上每一個人。\n",
      this_object()
    );
    i = sizeof(inv);
    while(i--) {
      if (inv[i]!=this_object()) 
        {
           inv[i]->receive_damage(random(30)+40);
           "/d/magic/magic"->report( this_object(), inv[i] );
        }
    }
    return 1;
}

void die()
{
    
    object ob1;
    
    ob1=query("last_attacker");
    announce(
"\n東方大陸的上空出現朵朵祥雲，而陣陣仙樂從空中傳下，在天兵天將的護持\n"
"中龍神九州出現在東方大陸的上空，並對著這世界所有的人宣稱：\n"
"偉大的英雄 "+ob1->query("c_name")+" 解救我那不成才的弟弟孽龍恨天\n"
"我以他為榮，再為東方的英雄史寫下燦爛的一頁。\n\n");
    if ((int)ob1->query_quest_level("evil_dragon")< 1 ){
       ob1->finish_quest("evil_dragon",1);
       tell_object(ob1,"你已經完成這個任務，你得到 50000點經驗值\n" );
       ob1->gain_experience(50000);    
   };
  ::die(); 
}
