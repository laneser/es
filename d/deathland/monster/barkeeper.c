
#include "../echobomber.h"

inherit MONSTER;

string *rumors = ({ 
       "謠傳瘋狂的魔法師奇奇凱爾將率領他的幻影軍團攻打死亡大地山頂的大巫妖懷爾 .\n",
       "謠傳一個漂亮的珍珠被藏在礦坑的深處,安琪拉已經尋找它好久了 .\n",
       "你知道矮人村前的迷宮嗎?似乎有個很大的秘密隱藏其中 .\n",
      // "你知道通向死亡大陸的的最深處的通道是在深淵的黑霧之中嗎 ?\n",
                }); 

void create()
{
    object ob1;
	::create();
	set_level(11);
	set_name( "barkeeper", "酒保" );
	add("id",({"barkeeper"}));
	set_short( "a barkeeper", "酒保" );
	set_long(
		"A smiling barkeeper.\n",
		"一個帶著笑臉的酒保 ,他已經在這裡服務多年了.\n"
	    );
	set("alignment",440);
	set_perm_stat( "dex", 13 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 8 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 12);
	set_perm_stat( "karma", 13);	
	set( "race", "dwarf" );
	set( "gender", "male" );
	set_natural_armor(56,20);
	set_natural_weapon(10,10,11);
	set_skill("dagger",50);
	set_skill("dodge" ,60);
	set( "inquiry", ([
		"legend" : "@@ask_rumor",
		"muse" : "@@ask_muse",
		"rumor" : "@@ask_rumor",
	]) );
	wield_weapon(Weapon"/dagger01");
	ob1=new(Object"/broom");
	ob1->move(this_object());
}


void ask_rumor(object who)
{
     int i;
     i=random(sizeof(rumors));
     tell_object(who,
          "這酒保說:"+ rumors[i]
          );
     return;   
}

void ask_muse(object who)
{
        tell_object(who,can_read_chinese()?
         "傳說中的繆思泉?嘿,嘿,...\n":
         "Need Translation.\n"
                   );
        return;
} 

