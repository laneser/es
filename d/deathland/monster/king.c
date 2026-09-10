#include "/d/deathland/echobomber.h"

inherit MONSTER;

void create()
{
	::create();
	seteuid(getuid());
	set_level(19);
	set_name( "Dwarf King Molader V", "矮人國王莫拉德五世" );
	add ("id", ({ "king", "molader", "dwarf", }) );
	set_short( "矮人國王莫拉德五世" );
	set_long(@DESC
矮人國王莫拉德五世,他看起來雖然很老,但是他的力量和戰鬥技巧還是數一數二的.
在數次的矮人與巨人的戰爭之中,他領導著矮人族擊退巨人的攻擊,而且他將仍繼續
與邪惡的巨人族戰鬥下去.
DESC
	);
    set("weapon_master",1);
    set( "alignment",1600);
    set( "gender", "male" );
    set( "race", "dwarf" );
    set( "unit", "個" );
	set_perm_stat( "dex", 23 );
	set_perm_stat( "str", 27 );
	set_perm_stat( "int", 21 );
	set_perm_stat( "con", 30 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 30);
	set_skill("longblade",100);
	set_skill("parry",100);
        set("special_defense", (["all":35,"none":60,"monk":20,"scholar":20]) );
	set ("max_hp", 999);
	set ("hit_points", 999);
	set ("wealth", ([ "gold": 5 ]) );
	set_natural_weapon( 25, 5, 45 );
	set_natural_armor( 50, 60 );
    set ("weight", 400);
    set( "inquiry", ([
         "troll" : "@@ask_troll" ,
         "valor" : "@@ask_valor" ,
         "queen" : "@@ask_queen" ,  
           ]) );
    set ("unbleeding",1);
    set ("chat_chance", 8);
	set ("chat_output", ({    "矮人國王莫拉德五世希望一個偉大的勇者(valor)從巨人(troll)的侵略中拯救他的國家\n",
	    }) ); 
	set ("att_chat_output", ({	    "國王說:愚蠢的傢伙,你不可能擊敗我的\n",
	    }) );
	wield_weapon(Weapon"/blacksword");
    equip_armor(Armour"/leggings02");
    equip_armor(Armour"/helmet02");
    equip_armor(Armour"/boots02");
    equip_armor(Armour"/plate03");
}

void ask_troll( object who )
{
        tell_object( who,@MSG1
巨人,有很強的生命力,我們矮人族已經與它們作戰數百年了
如果你想知道更詳盡的資料,或許巨人戰術研究室的卡爾(Karl)將軍
能告訴你.
MSG1
);
      return ;        
}

void ask_valor(object who)
{
      
      tell_object(who,
      "我們須要一個勇者來幫助對抗巨人(troll),如果你願意幫助我們請先去找卡爾服德\n");
      return ;
}

void ask_queen(object who)
{
     object *items,special;
     int i;
     
     tell_object(who, @ASK_QUEEN_1
國王說:唉!!自從我的大兒子法拉第死掉了之後, 她就在也沒有露出笑容了. 
我也勸過她凡事要想得開一些, 但是她仍無法停止悲傷. 我也曾經請她最好
的朋友安琪拉來勸過她, 然而仍無法停止她的憂傷.
ASK_QUEEN_1
     );
     if ( (int) who->query_level() >= 10 ) {
       items=all_inventory(who);
       for(i=0;i<sizeof(items);i++) {
         if ( (string)items[i]->query("name")== "Black Box of Molader" )
           return;
         }
       tell_object(who,@ASK_QUEEN_2
這裡有一個黑盒子, 當你正為了解決我們的難題時, 它將是有幫助的,
拿著它, 希望你能夠早日幫助皇后恢復往日的笑容.
ASK_QUEEN_2
       );
       special=new(Object"/blackbox");
       
       switch ( (int)who->query_quest_level("queen_smile") ) {
         case 0: break;
         case 5: 
                 tell_object(who,"你已經完成了這任務,但這黑盒子的東西還是能夠幫助你的.\n");
         case 4:
         case 3:  
         case 2: 
                 special->set("quest_item/crystal_card",1);
         case 1: special->set("quest_item/explorer_bell",1);
                 special->set("quest_action/invoke_bell",1);
                 tell_object(who,"你曾試著幫助過我們,這黑盒子保存著一些有用的物品.\n");
         }
       special->move(who);  
       }
     return;
}

void die()
{
	object killer,scroll;
	killer = query("last_attacker");
        if (killer)
	killer->set_explore( "deathland#37" );
	 scroll = new( "/d/mage/tower/obj/star_scroll" );
   scroll->move(environment(this_object()));

   tell_room( environment(this_object()),
     "『咚』的一聲, 一件東西從矮人國王的懷中落在地上。\n",
     this_object() );
	::die(1);
}

void show_headband(object player)
{
     object key;
     tell_object(player,@MSG2
你是安琪拉介紹來的文學家嗎? 希望你能讓皇后重新拾起她往日的笑容.
拿著這鑰匙去找皇后吧!
MSG2
     );
     key=new(Object"/key01");
     key->move(player);
     return ;
}
