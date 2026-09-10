#include "../moyada.h"

inherit MONSTER;

#define MAX 10

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(8);
	set_name( "Anteater", "食蟻獸" );
	add ("id", ({ "anteater" }) );
	set_short( "食蟻獸" );
	set_long( @LONG
一隻飢餓的食蟻獸，不知多久沒進食了，看起來瘦瘦巴巴的，好可憐。
LONG
	);

    set( "alignment", 400);
    set( "unit", "只" );
	set_perm_stat( "dex", 12 );
	set_perm_stat( "str", 10 );
	set_perm_stat( "int", 7 );
	set_perm_stat( "con", 14 );
	set_perm_stat( "piety", 5);
	set_perm_stat( "karma", 17);
	set ("max_hp", 240);
	set ("hit_points", 240);
	set_natural_weapon( 20, 10, 20 );
	set_natural_armor( 45, 10 );
	set( "persuing", 1);
	set( "death_msg", "食蟻獸哭著說: 我好命苦 .... 然後就死了!\n" );
	set( "weight", 400);
	set( "exp_reward", 700 );
    
	set ("chat_chance", 15);
	set ("chat_output", ({
	    "食蟻獸說: 好餓喔!\n",
	    "食蟻獸說: 好久沒見過螞蟻了，是不是都死光了?\n",
	    "食蟻獸說: 好心的大爺，賞只螞蟻給我好嗎!\n",
            "食蟻獸說: 沒有活的螞蟻，喂(feed)個螞蟻的屍體也行！\n",
	    }) ); 
	set ("att_chat_output", ({
	    "食蟻獸說: 不要就算了，幹嘛還打我！\n",
	    "食蟻獸說: 救命啊! 欺負弱小啊 ～～\n",
	    }) );
	set_c_verbs( ({ "%s咬%s", "%s踢%s", "%s用力撞%s" }) );
	set_c_limbs( ({ "身體", "爪子", "腳", "頭", "尾巴", "舌頭", }) );
}
/*

void relay_message(string class, string msg)
{
      string who,tmp;
      object obj;

      if ( sscanf( msg, "%s(%s)走了過來。", tmp,who )==2 ) {
        obj = present(lower_case(who), environment(this_object()) );
        if( !obj ) return;
        if( (string)obj->query("race") == "ant" ) {
          tell_room( environment(this_object()) , 
            "食蟻獸說: 螞蟻!!! 有救了，乖乖的別跑，好好讓我吃吧!\n"+
            "食蟻獸一口就把"+obj->query("c_name")+"吞下肚了。\n"
            , this_object()
          );
          obj->remove();
          call_out( "to_emote", 1, this_object() );
        }
      }
}
*/

void init()
{
    add_action("to_feed", "feed");
}

int is_a_corpse( object obj )
{
    if( (string)obj->query("name")=="corpse of ant" ) return 1;
    return 0;
}

int to_feed( string str )
{
    object player, *corpse;
    int left, i;
    
    if( !str || str == "" )
      return notify_fail("喂誰 ?\n");
    if( str != "anteater" )
      return notify_fail("沒看到有這個東東啊 ？\n");
    player = this_player();
    left = MAX - (int)player->query_temp("anteater");
    corpse = filter_array( all_inventory(player),
                           "is_a_corpse", this_object() );
    i = sizeof( corpse );
    if( !i )
      tell_object( player,
        "食蟻獸很不高興的瞪著你說: 你拿什麼餵我?\n" );
    else {
      while( i-- ) {
        if( (string)corpse[i]->query("type")=="ant" ) {
          tell_object( player,
            "食蟻獸高興的把"+corpse[i]->query("c_name")+
            "吞下肚並露出滿足的表情。\n" );
          left--;
          corpse[i]->remove();
        } else {
          tell_object( player, 
          "食蟻獸高興的把"+corpse[i]->query("c_name")+
            "吞下肚但卻露出難看的表情。\n" );
          corpse[i]->remove();
        }
      }
      if( left <= 0 && (int)player->query_quest_level("anteater") < 1 ) {
        tell_object( player,
          "食蟻獸滿意的說: 謝謝你! 我吃飽了!\n"
          "   [ 你救了食蟻獸，獲得 4000 點經驗值。]\n" );
        player->finish_quest("anteater",1);
        player->gain_experience(4000);
      } else if( (MAX - left) > (int)player->query_temp("anteater") ) {
        tell_object( player, 
          "食蟻獸高興的說: 謝謝你! 好好吃，我還要。\n" );
        player->set_temp("anteater", MAX-left);
      } else
        tell_object( player,
          "食蟻獸失望的說: 都不好吃，有沒有別種的?\n" );
    }
    return 1;
}

void to_emote( object obj )
{
      tell_room( environment(obj), 
            "食蟻獸說: 好吃!!還有沒有?\n" , obj
      );
}

