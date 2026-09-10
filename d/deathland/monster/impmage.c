#include "../echobomber.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
    set_level(15);
    set_name("Imp mage Morr","妖精魔法師摩兒");
    add("id",({"imp","mage","morr"}) );
    set_short("Imp mage Morr","妖精魔法師摩兒");
	set_long(@LONG
??
LONG
    ,@C_LONG
一個身上長著一對翅膀的妖精魔法師.似乎有著強大的法力.
C_LONG
	);
    set("alignment",-400);
    set( "gender", "female" );
    set( "race", "imp");
    set( "unit", "個" );
    set_perm_stat( "dex",21);
    set_perm_stat( "str",11);
    set_perm_stat( "int",25);
    set_perm_stat( "con",13);
    set_perm_stat( "piety",17);
    set_perm_stat( "karma",22);
	
    set ("max_hp",340);
    set ("max_sp",1300);
    set ("hit_points",340);
    set("spell_points",1300);
    set ("wealth", ([ "gold":21]) );
    set_natural_weapon(22,12,17);
	set_natural_armor(65,24);
    set ("weight", 160);
    set_skill("target",100);
    set_skill("elemental",100);
    set_skill("concentrate",100);
    set_skill("dodge",98);
    set_skill("wand",100);
    set("magic_delay",2);
    set("spells/sleet",4);
    set("spells/fireball",4);
      set( "inquiry", ([
         "rune" : "@@ask_rune",
         "bottle" : "@@ask_bottle",
         "painting" : "@@ask_painting",
         "chichikair":"@@ask_chichikair",
         "book":"@@ask_book",
         "charge":"@@ask_charge",
         ]) );
    set("special_defense", (["all":35,"none":10]) ); 
    set ("aim_difficulty",(["vascular":20]) );
    set( "tactic_func", "cast_spell");
    wield_weapon(Weapon"/wand");
}

void ask_rune(object who)
{
     tell_object( who ,@MSG1
這些魔法書籍上記載著種種召喚邪惡生物的方法,但是由於這些文字實在是太難了.
所以目前我也只會召喚出幻影來幫助我,只不過我並沒有把握能控制住它.
MSG1
       );    
}

void ask_bottle(object who)
{
     object *items;
     int i;
     
     tell_object( who,@MSG2
這個瓶子是我的老師給我的,這個魔法瓶....
嘿嘿,這是一個秘密.
MSG2
                 );
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_action/find_book")) {
              tell_object( who,@MSG3
但是既然你幫我拿回了這本研究心得, 那麼告訴你也無妨 : 
這是一個鎖魂瓶, 它能夠把他人的靈魂鎖於其中, 但是由於 
在使用鎖魂瓶的時候, 使用者必須把自己的生命力注入於內 
, 因此通常是事先注入於內, 像這個鎖魂瓶已經有我的生命 
力在其中了, 所以你不能使用 ,如果你找到了鎖魂瓶, 你可 
以拿來, 我能夠注入(charge)你的力量而讓你能使用它 .
MSG3
                 );
           } 
      return;           
}

void ask_painting(object who)
{
     tell_object( who,"摩兒回答你:喜歡我的自畫像嗎?\n");

}

void ask_chichikair(object who)
{
     tell_object(who,@MSG4
摩兒說: 奇奇凱爾, 原本在我們暗黑魔法研究小組中最有心得的一位高級魔法師 ,
想不到他會變得如此瘋狂. 他偷走了我們辛苦多年的研究心得, 如果你能夠幫我找
回那本研究心得(book), 我想我會很感激你的 .
MSG4
                 );
}

void ask_charge(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
          if ( items[i]->query("quest_action/find_book") ) { 
          if ( items[i]->query("quest_item/ancient_bottle") ) {
          tell_object(who,@MSG5
我將盡我所有的力量來幫助你.....
摩兒開始口中念念有辭..
世
間
的
魔
神
魔
瓶
須
要
你
們
的
力
量
一道耀眼的光芒進入你的眼中.
此時摩兒說:
你已經可以使用這索魂瓶了.
MSG5
          );
          items[i]->set("quest_action/charge_bottle",1);
          if ( (int)who->query_quest_level("queen_smile") < 3 ) 
             who->finish_quest( "queen_smile" , 3 );
          }
          else 
          tell_object(who,"先找出索魂瓶吧.\n");
          return;          
          }
     tell_object(who,"摩兒以奇怪的眼神看著你.\n");
     return;     
}
void ask_book(object who)
{
     object *items;
     int i;
     
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" ) 
          if ( items[i]->query("quest_item/study_book") ) { 
          tell_object(who,@MSG6
你找到我的書了.謝謝你.
摩兒拿回她的書並說:謝謝,如果有須要幫助的
話, 儘管開口.
MSG6
          );
          items[i]->set("quest_item/study_book",0);
          items[i]->set("quest_action/find_book",1);
          return;
          }
     tell_object(who,"我們多年的研究心得,已經消失了, 希望你能幫我找回來.\n");
     return;
}

int cast_spell()
{
    object victim;
    string name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    
    if( random(10) < 3 ) {
      command("cast sleet on "+name);
      return 1;
     }
    else if (random(10)< 2) {
      command("cast fireball on "+name);
      return 1;
      }
    else return 0;   
}

