// town_guard.c
// A pursuing monster. That is, if you are in combat with him, and
// you leave, he'll go after you. You can lose him if you run fast
// enough but otherwise he's pretty lethal.
// Also, if A attacks B, then the guard will attack A.
// Comments on monster properties are found in /obj/foobird.c
// Written by Mobydick, 6-20-93.

#include "/d/noden/farwind/farwind.h"

inherit MONSTER;

void create ()
{
	::create();
	set_level(15);
	set_name( "ebbruce", "艾柏魯斯" );
	add( "id", ({ "sheriff" }) );
	set_short( "遠風鎮保安官艾柏魯斯");
	set_long(@C_LONG
艾柏魯斯是這個鎮上的保安官，他的任務就是維護遠風鎮的和平寧靜，
這個人十分嚴肅，最好別在遠風鎮打架或幹壞事 (至少別在他面前讓他
看到) 。
C_LONG
                );
	set( "race", "dwarf" );
	set( "gender", "male" );
	set( "natural_armor_class", 50 );
	set( "natural_weapon_class1", 10 );
	set( "natural_min_damage1", 5 );
	set( "natural_max_damage1", 10 );
	set( "max_hp", 450 );
	set( "hit_points", 450 );
	set( "moving", 1 );
	set( "speed", 30 );
	set( "patrol", ({ "north", "south", "west", "west", "east", "east",
		"south", "north" }) );
	set_perm_stat( "str", 20 );
	set_perm_stat( "dex", 18 );
	set_skill( "longblade", 100 );
	set_skill( "parry", 100 );
	set( "special_defense", ([ "all": 20 ]) );

	wield_weapon( FARWIND"items/b_sword");
	equip_armor( FARWIND"items/leather_boots");
	equip_armor( FARWIND"items/breast_plate");

	set ("pursuing", 1) ;
	set ("inquiry", ([
"lucksis": "@@ask_lucksis"
	]) ) ;
}

void init()
{
   npc::init();
   add_action( "kill_killer", "kill" );
}

int kill_killer(string arg)
{
   object killer;

   killer = this_player();
   if( arg && present(arg,environment(this_object()))
        && arg != "ebbruce" && arg != "torch" )
   {
     if(killer) {
            kill_ob(killer);
            killer->kill_ob(this_object());
            tell_object(killer,
         "艾柏魯斯瞪你一眼，說道: 你竟敢公然在遠風鎮撒野？\n");
            tell_room(  environment(killer),
         "艾柏魯斯橫眉一豎,鬍子一翹,立刻出手海Ｋ"+killer->query("c_name")+
        "......!\n", killer );
     }
   }
}

void ask_lucksis(object who)
{
     if (!(who->query_temp("lucksis_quest")) || (int)(who->query_temp("lucksis_quest/ask"))==0 ) 
       tell_object(who,"艾柏魯斯依舊不微言笑的站著.\n"
                       );
     else
       {
         tell_object(who,"艾柏魯斯說:你是拉克希絲派來的?\n"
                         "那個小女子現在還有沒有動不動就哭泣?\n"
                         "艾柏魯斯露出難得一見的笑容.然後對你說:\n"
                         "對不起,我必須維護這地方的安全了,請別打攪我.\n"
                         "\n\n你感覺出艾柏魯斯對於拉克希絲似乎並無任何的\n"
                         "感情.或許艾柏魯斯根本並不會對任何人產生感情.\n"
                    );
         who->set_temp("lucksis_quest/ebbruce",1);             
       }
     return;
}

