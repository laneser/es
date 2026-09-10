#include <mudlib.h>

inherit TEACHER;
inherit MONSTER;

void create()
{
	::create();
	set_level(19);
	set_name( "captain", "警備隊長" );
	add( "id", ({ "guard" }) );
   set_short( "警備隊長" );
   set_long( @LONG
這位警備隊長正坐在桌子前讀一些公文，他年輕時曾是一位偉大的冒險
者，現在從海上退休，擔任藍沙港的警備工作。最近他正為了處理海盜
(pirate)入侵的事而焦頭爛額。
LONG
	);
	set( "race", "human" );
	set( "gender", "male" );
	set_perm_stat( "str", 27 );
   set_perm_stat( "dex", 22 );
   set_perm_stat( "kar", 24 );
   set( "max_hp", 1200 );
   set( "hit_points", 1200 );
	set_skill( "longblade", 100 );
	set_skill( "shortblade", 100 );
	set_skill( "two-weapon", 100 );
	set_skill( "parry", 100 );
	set_skill( "dodge", 100 );
	set_skill( "tactic", 100 );
	set( "tactic", "berserk" );
   set( "tactic_func", "call_help" );
	set( "wealth/gold", 180 );
   set( "weight", 850 );
   set( "special_defense", ([ "fire":50, "cold":50, "none":-5 ]) );
	set( "alignment", 1400 );
   set_natural_armor( 50, 10 );
   set( "aim_difficulty", ([
   "critical":30, "ganglion":30, "weakest":30,"vascular":30 ]) );
   set_natural_weapon( 17, 15, 25 );
   set_natural_weapon2( 15, 10, 20 );
   wield_weapon2( "/d/noden/bluesand/item/etheral_cutlass" );
   wield_weapon( "/d/noden/bluesand/item/murasame" );
   set_lessons( ([
                  "parry" : ({ 200, 50 })
   ]) );
   set( "inquiry", ([
     "parry" : "就是武器招架啦! 要學就快。\n",
     "pirate" : "最近海盜猖獗, 如果你把海盜頭子的腦袋給我, 我會給你一些獎勵。\n"
   ]) );
}

void init()
{
   teacher::init();
   npc::init();
}

int accept_item(object who, object item)
{
   if( (string)item->query("c_name")=="奧斯塔的人頭" )
   tell_object( who,
        "很好! 海盜頭子終於死了!\n"
        "這是給你的獎金。又你想學武器招架(parry)嗎?\n" );
   who->set_temp("train_parry", 1);
   who->credit("gold", 50);
   item->remove();
   return 1;
}

int check_trainee(object who)
{
   if( !who->query_temp("train_parry") )
   return notify_fail(
        "守備隊長說道: 請先交出奧斯塔的人頭！\n" );
   if( (string)who->query("class")=="adventurer"
     && (int)who->query_level()> 4 )
   return 1;
   else return notify_fail(
        "守備隊長說道: 我只教夠資格的冒險者，你的條件不合！\n" );
}

int call_help()
{
   object cop1, cop2, cop3, victim;
   int hp;

   victim = query_attacker();
   hp = this_object()->query("hit_points");

   if( hp>250 ) return 0;
   if( random(10)> 3 ) return 0;
   if( present("cop", environment(this_object())) ) return 0;
   tell_room( environment(this_object()),
      "警備隊員們大叫道: 誰敢動隊長!?讓他下地獄!!\n\n" );
   cop1 = new("/d/noden/bluesand/monster/cop");
   cop2 = new("/d/noden/bluesand/monster/cop");
   cop3 = new("/d/noden/bluesand/monster/cop");
   cop1->move(environment(this_object()));
   cop2->move(environment(this_object()));
   cop3->move(environment(this_object()));
   cop1->kill_ob(victim);
   cop2->kill_ob(victim);
   cop3->kill_ob(victim);
   return 1;
}

void die()
{
   object *blade, murasame;

   blade = children( "/d/noden/bluesand/item/murasame" );
   murasame = present( "murasame", this_object() );
   if( sizeof(blade) > 1 ) {
        tell_room( environment(this_object()),
		"警備隊長怒嚎: 不! 我怎麼可能被毛賊殺死？即使我死你們也別想拿到寶刀!\n"
		"警備隊長用盡最後的力量把村正擲進藍沙港中!\n",
		this_object() );
        murasame->remove();
   }
   ::die();
}
