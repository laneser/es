
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	seteuid(getuid());
	set_name( "homdlaser", "宏都拉瑟" );
	set_short( "a dwarf experienced miner homdlaser", "矮人專家礦工宏都拉瑟" );
	set_long(
	" Dwarf experienced miner,homdlaser is the manager for the factory,and he knows \n"
	"many knowledge.So cart can get the best effivelity.To talk with him,maybe you get\n"
	"some messages.\n",
	"矮人專家礦工宏都拉瑟,已經管理煉礦廠很多年了.而且對於矮人礦坑(mine)裡的地\n"
	"形地物非常瞭解.所以矮人運礦車(cart)在他的調度下發揮了最大的效率.和他談談\n"
	"\或許你會有意想不到的收穫.\n"
	);

    set("alignment",400 );
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "個" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 24 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 30);
	set_skill("unarmed",88);
	set_skill("dodge",88);
	set ("max_hp", 770);
	set ("hit_points", 770);
	set ("wealth", ([ "gold": 55 ]) );
	set_natural_weapon(35,22,33);
	set_natural_armor(70,35);
    set ("weight", 400);
    set( "inquiry", ([
         "cart" : "@@ask_cart",
         "carts": "@@ask_cart",
         "valor": "@@ask_valor",
         "mine" : "@@ask_mine",
           ]) );
    set("echo_valor",1);
    set ("chat_chance", 7);
	set ("chat_output", ({
	    "Homdlas says: Notice safety\n",
	    "宏都拉斯說:注意安全,這礦坑充滿著危險.\n",
	    "Homdlas says:if you want to help us,please prove you are a valor first.\n",
	    "宏都拉斯說:假如你是來幫助我們的,先證明你是一個勇者(valor).\n"
	    }) ); 
}

void ask_cart( object who )
{
     tell_object(who ,can_read_chinese(who) ?
     "一個從默爾斯來的流浪漢,希斯克利夫(Cisklyph),我想他可能是世界上最聰明的人,\n"
     "幫助我們建立了很完整的開礦與煉礦系統.像你問起的運礦車,就是一個很複雜的機器\n"
     ",構造連我也不是很瞭解,只知道它能很快速地在軌道上移動.但是運礦車的確幫助我\n"
     "們的採礦速度加快了.\n"
     :
     " \n"
     );
}
void ask_mine(object who)
{
    tell_object(who ,can_read_chinese(who) ?
    "礦坑,一個充滿黃金的地方,但是也充滿了危險與死亡\n"
    "我們矮人已經開發了大部份的地方,但是還有一些特別危險的地方,已經被我們封住.\n"
    "假使你對於探險有著很高的興趣,拿起你的鏟子去挖掘吧!通常在軌道的盡頭若是沒\n"
    "有一個緩衝器(讓運礦車停住的機器),那麼或許你將發現在那兒將有大量的財富在\n"
    "等著你.當然也有兇猛的怪物在等著你\n"
    :
    "\n"
    );
}
void ask_troll( object who )
{
        tell_object( who, can_read_chinese(who) ?
          "巨人,有很強的生命力,我們矮人族已經與它們作戰數百年了\n"
          "如果你想知道更詳盡的資料,或許巨人戰術研究室的卡爾(Karl)將軍\n"
          "能告訴你.\n"
          :
          "troll\n" );
      return ;        
}

void ask_valor(object who)
{
      
      tell_object(who,can_read_chinese(who) ?
      "去找皇室侍衛隊長卡爾服德,他將告訴你更詳盡的資料\n "
      :
      " \n"
     );
      return ;
}

int echo_valor(object ob1,object ob2)
{
     if (!ob2 || (int)(ob2->query("echo_quest_card"))!=1) return 0;
     if ((int)(ob2->query("echo_quest_card"))==1) {
        if( ob1->query("name")!=ob2->query("someone_id") )
          {
          tell_object(ob1,
          "我想這卡片是非法得來的.所以我不能幫助你這個賊.\n"
           );
          }
        else {
        tell_object(ob1,can_read_chinese(ob1) ?
        "勇者你好.宏都拉斯說\n"
        "宏都拉斯向你敬禮.\n"
        "我想你已經證明你的勇氣了.我們的聖地正遭受了很大的威脅,骸骨族黑武士\n"
        "的攻擊使得目前在聖地研究反黑魔法的艾爾與齊格的一番心血完全泡湯 .希\n"
        "望你的出現能幫助他們.\n"
        :
        " \n"
        );
       call_out("cart_open",2,this_object());
      // ob2->move(ob1);
      // tell_object(environment(),"宏都拉斯把卡片還給"+ob1->query("c_short")+"\n");
          }
     }     
     return 1;  
}

int cart_open(object ob1)
{
    object ob3,ob4;
    
    switch ((int)environment(ob1)->query("open_cart"))
      {
      case 1:   
         ob3=new(Mine"/obj_cart");
         ob4=new(Mine"/room_cart");
         ob3->set_roomcart(ob4);
         ob4->set_objcart(ob3);
         ob3->move(environment(ob1));
         tell_room(environment(ob1),"宏都拉斯把希斯克利夫運礦車開了出來.\n");
         environment(ob1)->set("open_cart",2);
         break;
      case 2:
         tell_room(environment(ob1),"運礦車已經在這裡了.\n");
         break ; 
     
      }     
    return 1;
}
