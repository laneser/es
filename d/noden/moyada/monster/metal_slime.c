#include "../moyada.h"
inherit MONSTER;

void create ()
{
    object amulet;
	::create();
	seteuid( getuid() );
	set_level(1);
	set_name( "metal slime", "金屬史萊姆" );
	add ("id", ({ "slime", }) );
	set_short( "金屬史萊姆" );
	set_long( @LONG
金屬的軟體怪? 好奇怪? 一雙圓圓的大眼睛好奇的看著你，看起來好可愛。
LONG
	);
   set( "race", "undead" );
	set( "alignment", 4000 );
    set( "unit", "只" );
	set_perm_stat( "dex", 30 );
	set_perm_stat( "str", 1 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 1 );
	set_perm_stat( "piety", 30 );
	set_perm_stat( "karma", 30 );
	set ("max_hp", 5);
	set ("hit_points", 5);
	set_natural_weapon( 15, 3, 6 );
   set_natural_armor( 250, 100 );
	setenv( "C_MIN", "一隻$N愉快的跳了過來。");
	setenv( "C_MOUT", "$N高興著往$D邊跳走了。");
   set("unbleeding",1);
   set( "block_aim", ({ "vascular", "ganglion" }) );
	set ("aim_difficulty", ([ "critical" : 100, "weakest" : 100, ]) );
	set ("special_defense",
        ([ "all" : 100, "none" : 35 ]) );
	set ("wimpy", 5);
	set_skill("dodge", 100);
	set ("moving", 1);
    set ("weight", 100);
    set ("time_to_heal", 40);
    set ("exp_reward", 15000);
    set ("tactic_func", "cast_mela");
    set ("chat_chance",5);
    set ("chat_output", ({
      "金屬史萊姆跳到你的腳旁，好奇的看著你，還對你微笑呢。\n"
    }) );
    set_c_verbs( ({ "%s撞到%s身上", "%s撲到%s臉上" }) );
    set_c_limbs( ({ "身體"  }) );
    set( "c_death_msg", "%s說: 為什麼要打我 .... 然後就死了。\n" );
    equip_armor( MOYADA"obj/slime_amulet" );
}

void cast_mela()
{
    object victim;
    if( !(victim=query_attacker()) || random(10)> 1 ) return 0;
    tell_object( victim,
      "金屬史萊姆跳到你面前，吐出一顆小火球。\n" );
    tell_room( environment(this_object()), 
      "金屬史萊姆跳到"+victim->query("c_name")+"面前，吐出一顆小火球。\n"
     , ({ victim, this_object() })
    );
    victim->receive_special_damage("fire", 5, 1 );
}

int catch_huntee( object who )
{
    tell_room( this_object(), 
      "金屬史萊姆看見 "+who->query("c_name")+" 之後，驚嚇地跳了開!\n"
   ,  ({ this_object(), who }) );
    tell_object( who, 
      "金屬史萊姆看見你之後，驚嚇地跳了開!\n" );
    return 1;
}
