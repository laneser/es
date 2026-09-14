
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	object ob1;

	::create();
	set_level(16);
	set_name( "Doctor Angelina", "女醫生安琪拉" );
	add( "id", ({ "doctor", "angelina", }) );
	set_short( "a female doctor Angelina", "女醫生安琪拉" );
	set_long(
		"NEED TRANSLATION.\n",@DESC
一個醫術高明的女醫生,在她的細心和耐心之下,許多受傷的戰士們都能很
快的康復.
DESC
	);
	set( "race", "dwarf" );
	set( "gender", "female" );
	set_perm_stat( "int", 26 );
	set_perm_stat( "kar", 28 );
	set_perm_stat( "dex", 14 );
	set_skill( "dodge", 99 );
	set_skill( "dagger", 87 );
	set_skill( "anatomlogy", 100 );
	set( "aiming_loc", "vascular" );
	set( "max_hp", 330 );
	set( "hit_points", 330 );
	set_natural_armor(88,22);
	set_natural_weapon(10,16,22);
	set( "special_defense", ([ "all": 28 ,"none":10]) );
	set( "aim_difficulty",([ "critical": 20, "weakest":30 , "vascular":30]) );
	set( "alignment", 1200 );
    equip_armor(Armour"/necklace01");
	wield_weapon(Weapon"/dagger05");
    set( "tactic_func", "aim_point");
    set ( "inquiry",([
	      "queen":"@@ask_queen",
	      "litterateur":"@@ask_litterateur",
	      ]) );
}

int aim_point()
{
    if (random(10)<5)
      set( "aiming_loc", "vascular" );
    else
      set( "aiming_loc", "weakest" );
      
      return 0;
}

int accept_item(object ob1,object ob2)
{
    if ( !ob2 ) return 0;
    if (ob2->query("echo_pearl")) {
       tell_object(ob1,@MSG1
安琪拉笑著對你說:謝謝你的禮物,
我已經尋找這東西很久了,當時巨人入侵的時候,我不小心把這個家傳的寶
物遺失了,想不到經過這麼多年它又回到我的手上.
安琪拉小心謹慎地把珠寶收了起來.
MSG1
);
       ob2->remove();
       ob1->set_explore("deathland#30");
       call_out("tell_secret",10,ob1);
       return 1;
       }
    else return 0;   
}

void tell_secret(object ob1)
{
     tell_object(ob1,@MSG2
安琪拉告訴你說:或許我不應把這個秘密洩露出去,但是也許熱心助人
的你或許能夠幫忙安洛長老的麻煩.試著在安洛長老的門口說出下列的密語
(intelligence)你就可以見到最聰明的矮人長老了.
MSG2
);
     return ;
}

void ask_queen(object who)
{
     tell_object(who,@MSG3
可憐的皇后, 自從她的大兒子死了之後, 我就在也沒有見到
她的笑容了, 雖然我不斷勸她, 但是始終沒有甚麼用. 我與
她是多年的好朋友, 為了幫助她, 我也費了不少力氣. 我想
到一個或許有用的方法, 皇后是一個喜歡文學的人, 於是我
就請了矮人作家是否能夠跟皇后討論文學, 讓皇后的注意力
能夠轉移到她喜愛的文學上, 藉此讓她忘記喪子之痛, 但是
最近詩人卻陷入了創作低潮, 無法幫助皇后......
如果你是個優秀的文學家(litterateur)也許就能夠幫助皇后吧.
MSG3
                );
     return;
}

void ask_litterateur(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_action/good_poet")) {
           tell_object(who,@MSG4
原來你是個文學作家啊! 這麼一來也許你能幫助皇后恢復她往日的
笑容也說不定.
安琪拉拿出一個小發飾給你.
安琪拉說道:拿著這個髮飾, 把它拿給國王看看(show),他將讓你與
皇后談談.
MSG4
           );
           items[i]->set("quest_item/doctor_headband",1);
           who->set_explore("deathland#26");
           return;
           }
     tell_object(who,"對的, 我覺得只有優秀的文學家可以幫助我們的皇后.\n");
     return;      
}
