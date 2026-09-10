#include "../echobomber.h"

inherit MONSTER;

void create ()
{
	//object staff, amulet;

	::create();
	//seteuid( getuid() );
	set_level(20);
	set_name( "Retal", "雷多" );
	add ("id", ({ "retal", "mage","archmage" }) );
	set_short( "Retal the archmage of the Echo city", 
	           "Echo city 的大魔導士雷多" );
	set_long(@LONG
Retal is an old experienced mage.When evil lich,firer,whelmed the 
    echo city ,he was the only man escaped. 
LONG
    ,@C_LONG
        魔導士雷多是Echo city 的大魔法師. 當邪惡的 Lich 懷爾把 Echo city
    沉入大海之中,他是唯一逃出來的人.
C_LONG
	);
    set( "gender", "male" );
    set( "race", "human" );
    set( "unit", "個" );
	set_perm_stat( "dex", 20 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 25 );
	set_perm_stat( "con", 10 );
	set_perm_stat( "piety", 25);
	set_perm_stat( "karma", 20);
	
	set ("max_hp", 500);
	set ("max_sp", 600);
	set ("hit_points", 500);
	set ("spell_points", 600);
	set ("wealth", ([ "gold": 10 ]) );
	set ("natural_weapon_class1", 20);
	set ("natural_armor_class", 15);
	set ("natural_min_damage1", 15);
	set ("natural_max_damage1", 25);
    set ("weight", 350);
    set ("exp_reward", 30000 );
    //set ("inquiry", ([
    //     "mage" : "@@ask_mage",
    //   "spells" : "@@ask_spells",
    //    ]) );
    
	//staff = new(MOYADA"obj/thunderwand.c");
	//staff->move(this_object());
	//wield_weapon(staff);
    //amulet = new( MOYADA"obj/amulet" );
    //amulet->move(this_object());
    //equip_armor(amulet);
}

//void ask_mage( object who )
//{
//    tell_object( who, can_read_chinese(who) ?
//      "拉修帝說: 歡迎加入魔法師公會，除了蜥蜴人之外，不論什麼種族，\n"
//      "          只要對魔法有興趣，都能夠成為我們的一員。\n":
//      "Rashudi says: Welcome to join mage guild. Who is interesting\n"
//      "              in the power of magic is welcome to be a mage\n"
//      "              unless a lizardman.\n"  
//    );
//}

//void relay_message(string class, string msg)
//{
//     string who;
//     object obj;
     
//     if( sscanf( msg, "%s arrives.\n", who )==1 ) {
//       obj = find_player(lower_case(who));
//       if( (string)obj->query("class")=="mage" ) {
//         if( (int)obj->query("alignment")<(-3000) )
//           command("kill "+lower_case(who));
//         else if( (int)obj->query("alignment")<(-2000) )
//           tell_object( obj, can_read_chinese(obj) ?
//             "拉修帝說: 再次警告你，別做太多壞事了。\n":
//             "Rashudi says: Warning! you are too bad!\n" );
//         else if( (int)obj->query("alignment")<(-1000) )
//           tell_object( obj, can_read_chinese(obj) ?
//             "拉修帝說: 小心點！別做太多壞事了。\n":
//             "Rashudi says: Be careful, don't be too bad!.\n" );
//       }
//     }
//}
