
#include "../echobomber.h"

inherit MONSTER;

void create()
{
	object ob1,ob2,ob3,ob4,ob5,ob6;
	
	::create();
	seteuid(getuid());
	set_level(18);
	set_name( "Dwarf general karl", "矮人將軍卡爾" );
	add ("id", ({ "general", "dwarf","karl" }) );
	set_short( "a dwarf general karl", "矮人將軍卡爾" );
	set_long(
	" an old general named called karl\n",@DESC
一個年老的將軍卡爾, 已經研究巨人的戰術有許多年了, 他的力量雖然已
經減退了,但是他的智慧卻隨著年齡的增長而越來越聰明瞭.只不過由於他
待在這裡實在太久了,因此他現在只懂得這裡的一切事物,而外界的事他一
不知.
DESC
    );

    set("inquiry",([
        "troll":"@@ask_troll",
        "notes":"@@ask_notes",
        "model":"@@ask_model",
        ]) );
        
    set( "alignment",700);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "個" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "con", 29);
	set("wealth", ([ "gold": 5]) );
	set_natural_weapon(12,13,17);
	set_natural_armor(35,40);
	set ("aim_difficulty", ([ "critical":30,"vascular":35]) );
	set ("special_defense",([ "all": 35,"none":35 ]) );
    set ("weight", 300);
    set ("alignment",700);
    set_skill("parry",97);
    set_skill("blunt",97);
    set_skill("block",88);
	wield_weapon(Weapon"/hammer02");
	equip_armor(Armour"/plate02");
	equip_armor(Armour"/leggings01");
	equip_armor(Armour"/boots02");
	equip_armor(Armour"/shield01");
	equip_armor(Armour"/helmet01");
	
}

void ask_troll(object who)
{
  tell_object(who,@MSG1
巨人,我們已經和他們作戰將近五百年了,他們的一舉一動
以及種種的攻擊模式和方法,早就被我們研究透徹了.他們
的主要特點是生命力以及恢復力非常強 ,如果在與巨人對
戰的時候,你不能一口氣解決他的生命的話,當你休息完再
度戰鬥的話,你面對的將是一個完好無缺的巨人
MSG1
  );
  return ;
}

void ask_model(object who)
{

   tell_object(who,@MSG2
這些模型是一個從東方來的刑大夫,在他駐留與此地時,和
艾爾王子一同研究的辛苦成果 ,上面記載著許許多多巨人
弱點和致命傷.
MSG2
                   );
   return;
}

void ask_notes(object who)
{ 
   tell_object(who,@MSG3
這些記錄看起來很亂,是不是?
假如你能證明你是個勇者的話.....
MSG3
               );
   return;
}

//int accept_item(object ob1,object ob2)
//{
//     if (!ob2 || (int)(ob2->query("echo_quest_card"))!=1) return 0;
//     if ((int)(ob2->query("echo_quest_card"))==1) {
//        if( ob1->query("name")!=ob2->query("someone_id") )
//          {
//          tell_object(ob1,
//          "我想這卡片是非法得來的.所以我不能幫助你這個賊.\n"
//           );
//          //command("drop card\n"); 
//          }
//        else {
//        tell_object(ob1,can_read_chinese(ob1) ?
//        " "
//        :
//        " \n"
//        );
//       ob2->move(ob1);
//       tell_object(environment(),"宏都拉斯把卡片還給"+ob1->query("c_short")+"\n");
//          }
//     }     
//     return 1;  
//}
