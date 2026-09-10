#include "../echobomber.h"

inherit MONSTER;

void create()
{
	
	::create();
	set_level(16);
	set_name( "Dwarf Queen Lilies", "矮人皇后莉莉絲" );
	add ("id", ({ "queen", "lilies", "dwarf", }) );
	set_short( "Dwarf Queen Lilies", "矮人皇后莉莉絲" );
	set_long(
    "a sad queen.\n",@DESC
一個悲傷的皇后,自從她的大兒子死掉之後,她就再也沒有笑容了.
她似乎需要他人的安慰(comfort).
DESC
	);

    set( "gender", "female" );
    set( "race", "dwarf" );
    set( "unit", "個" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 21 );
	set_perm_stat( "con", 20 );
	set_perm_stat( "piety", 15);
	set_perm_stat( "karma", 20);
	set ("max_hp", 999);
	set ("hit_points", 999);
	set ("wealth", ([ "gold": 50 ]) );
	set_natural_weapon(35,20,45);
	set_natural_armor(80,22);
	set ("special_defense",(["all":33]));
    set ("weight", 300);
    set_skill("dodge",100);
    equip_armor(Armour"/cloth05");
    equip_armor(Armour"/cloak03");
    wield_weapon(Weapon"/mace03");
    set( "inquiry", ([
         "son" : "@@ask_son" ,
         "falady" : "@@ask_falady" ,
           ]) );
}

void init()
{
     ::init();
     add_action("to_comfort","comfort");
}

void ask_son(object who)
{
     object *items;
     int i;
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/doctor_headband") &&
               items[i]->query("quest_action/good_poet") ) {
           tell_object(who,
           "我的兩個兒子, 法拉第與艾爾, 你見過他們嗎? 他們都是英勇的勇士.\n"
           );
           return ;
           }
     tell_object(who,
     "皇后看了看你覺得你是個陌生人而不回答你.\n"
     );
     return;
}

void ask_falady(object who)
{
     object *items;
     int i;
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/doctor_headband") &&
               items[i]->query("quest_action/good_poet") ) {
           tell_object(who,@MSG1
我的大兒子法拉第, 你見過他嗎? 他是英勇的勇士. 但是卻不幸地
戰死了.
皇后說道這裡時, 不自覺的掉下眼淚來.
MSG1
           );
           return ;
           }
     tell_object(who,
     "皇后看了看你覺得你是個陌生人而不回答你.\n"
     );
     return;
}

void ask_air(object who)
{
     object *items;
     int i;
     items=all_inventory(who);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/doctor_headband") &&
               items[i]->query("quest_action/good_poet") ) {
           tell_object(who,@MSG2
我的二兒子艾爾, 你見過他嗎? 他是一個神奇的□金術士. 我已經很
久沒有見到他了.
MSG2
           );
           return ;
           }
     tell_object(who,
     "皇后看了看你覺得你是個陌生人而不回答你.\n"
     );
     return;
}

int to_comfort(string str)
{
    object *items,who;
    int i;
    
    if (!id(str)) return 0;
    
    who=this_player();
    items=all_inventory(who);
    for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           if (items[i]->query("quest_item/doctor_headband") &&
               items[i]->query("quest_action/good_poet") ) {
               write(@MSG3
你試著去安慰皇后, 由於你的文學修養與風趣的言論, 皇后的心情.
覺得好多了.
然而皇后仍然並未展開笑容.她依舊思念著她的兒子.
這時皇后對你說:
我很思念我的大兒子法拉第, 我有一個很無理的要求, 希望你能幫我
辦到, 那就是我很期望能再見他一面, 即使是他的靈魂.
皇后拿出一個護身符,
希望你見到我大兒子的時候能夠告訴他母親很想念他.
MSG3
               );
               items[i]->set("quest_item/queen_amulet",1);
               return 1;
               }
    tell_object(who,
     "皇后看了看你覺得你是個陌生人而不理會你.\n"
     );           
    return 1;
}
