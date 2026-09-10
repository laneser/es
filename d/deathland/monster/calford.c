#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	seteuid(getuid());
	set_name( "calford", "卡爾服德" );
	add ("id", ({ "calford", "dwarf", }) );
	set_short( "矮人皇室侍衛長卡爾服德" );
	set_long(
	"矮人皇室侍衛長卡爾服德,被譽為莫拉德皇族史中最強大的戰士.若是沒有他,巨人族\n"
    "早就擊潰莫拉德矮人王國了.\n"	
	);
    set("weapon_master",1);
    set("alignment",100);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "個" );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 20 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 30);
	set_skill("axe",100);
	set_skill("parry",100);
	set_skill("dodge",90);
        set("special_defense", (["all":30,"none":40,"monk":10,"scholar":10]) );
	set ("aim_difficulty",([ "vascular":35 , "weakest":20 ]) );
	set ("max_hp", 850);
	set ("hit_points", 850);
	set ("wealth", ([ "gold": 55 ]) );
	set_natural_weapon( 35, 15, 20 );
	set_natural_armor( 60, 55 );
    set ("weight", 400);
    set( "inquiry", ([
         "troll" : "@@ask_troll",
         "valor"  :"@@ask_valor",
           ]) );
    
    set ("chat_chance", 25);
	set ("chat_output", ({
    "卡爾服德說:要不是我必須保護皇宮的安全,我早就殺進巨人的巢穴了\n",
	    "卡爾服德說:假如你是來幫助我們的,先證明你是一個勇者(valor).\n"
	    }) ); 
	set ("att_chat_output", ({
	    "卡爾服德說:矮人的敵人,受死吧\n",
	    }) );
	
	wield_weapon(Weapon"/axe03");
	equip_armor(Armour"/plate04");
	set ("cutknife", 5);
}

void ask_troll( object who )
{
        tell_object( who, 
          "巨人,有很強的生命力,我們矮人族已經與它們作戰數百年了\n"
          "如果你想知道更詳盡的資料,或許巨人戰術研究室的卡爾(Karl)將軍\n"
          "能告訴你.\n");
      return ;        
}

void ask_valor(object who)
{
      object ob8;
      
      tell_object(who,
      "證明你是一個勇者的方法很容易,砍死一隻巨人(troll),然後把它的耳朵割來給我.\n"
     );
     if( (int)(who->query_level())<15 ) {
         tell_object(who,"\n\n卡爾服德看著你說:提升你的等級後再來找我吧!\n");
         return ;
      }
      if( !query("cutknife") )
      	write("卡爾服德說: 已經沒有割耳小刀了，下次看看吧。\n");
      else {
      	ob8=new(Weapon"/cutknife");
      	ob8->move(who);
      	add("cutknife",-1);
      	write("卡爾服德給你一把割耳小刀。\n");
      }
     return ;
}

int accept_item(object ob1,object ob2)
{
     object ob3;
     
     if (!ob2 || (int)(ob2->query("receive_trollear"))!=1) return 0;
     if ((int)(ob2->query("receive_trollear"))==1) {
        tell_object(ob1,
        "卡爾服德說:\n"
        "我想你已經證明你的勇氣了.\或許你覺得有些困惑,為什麼我會要你去冒險\n"
        "與巨人戰鬥?因為一個更艱難的任務正等著你.\n"
        "在礦坑的深處,有兩個傳說中的骸骨族黑武士( skeleton blackknight ),\n"
        "他們的出現曾經使得矮人國度陷入恐慌,甚至當時的國王莫拉德二世下令他\n"
        "的兒子阿萊特斯(Alaits),率領著一群精英戰士帶著老弱婦孺騎著獅鷲飛離\n"
        "死亡大地.而他則獨自前去對抗黑武士.最後雖然莫拉德二世英勇的戰死,但\n"
        "是兩名黑武士再也沒有出現了.\n"
        "經過了數百年,當時的黑武士似乎復活了. 但是幸好某次地震所造成的大深\n"
        "淵阻隔了他們.只不過我們矮人族的聖地卻遭受了很大的威脅, 二皇子艾爾\n"
        "與宮廷魔法師齊格為了對抗巨人祭司哈特瑞德屈裡的黑暗魔法而所\n"
        "做的研究可能因此泡湯.希望你能夠幫助我們.\n"
        );
       if( (int)(ob1->query_level())<15 ) {
         tell_object(ob1,"\n\n卡爾服德看著你說:提升你的等級後再來找我吧!\n");
         return 1;
       }
       ob3=new(Object"/blackcard");
       ob3->set("someone_id",ob1->query("name"));
       ob3->move(ob1);
       tell_object(environment(),sprintf("卡爾服德給%s一張證明文件.\n",ob1->query("c_name")));
       tell_object(ob1,"拿著這個證明,把它給宏都拉瑟看(show),他將幫你越過深淵.\n"); 
       ob2->remove();
       ob1->set_explore("deathland#33"); 
       return 1;
     }
}
