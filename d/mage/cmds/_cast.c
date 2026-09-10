//#pragma save_binary
// cast.c
// Command hook for spellcasting.
// A player casts a spell by typing "cast <name> [at|on] <name>"
// The input is parsed for spell name and target, and control is passed
// to /cmds/std/<name>_spell.c, which takes the target as an argument
// and does the Right Thing.
// Many of the spells require hooks in the user object. These hooks are
// found in /std/living/spells.c.
// You can make monsters cast spells also. See /obj/foobird.c or any other
// spellcasting monster's code for the details.

// Created 10-5-92 by Mobydick@TMI-2
// Update by Kyoko.

#include <mudlib.h>
#include <magic.h>
#define TP_COST 2

inherit DAEMON;

int spell_exists(string spell);

int help();

int cmd_cast (string str)
{
	string type, targname, spell, code;
	int found, sp_cost, skill, spell_power;
	object target;
	string *known;
	mixed spell_level;

	if( !str ) return help();

	if( (int)this_player()->query("stop_attack")>0 )
		return notify_fail (
			"( 你上一個動作還沒有完成，無法施法。 )\n");

    if( this_player()->query_temp("cast_busy") )
        return notify_fail( 
            "你上一個魔法還沒有完成，無法施法。 \n");

    if( this_player()->query_temp("silence") ||
        this_player()->query("slience") )
      return notify_fail( 
        "你正準備唸咒文時，竟然發現你突然發不出聲音。\n" );

    if( environment(this_player())->query_temp("no_cast") ||
        environment(this_player())->query("no_cast") )
      return notify_fail( 
        "一陣奇怪的力場使你念不出咒文。\n" );
    
     if ( sscanf( str, "%s %s at %s",type, spell, targname)==3  ||
          sscanf( str, "%s %s on %s",type, spell, targname)==3 ) {
		if ( MAGIC_D->alias_spell(spell) )  
			spell = MAGIC_D->alias_spell(spell);
		if ( undefinedp(spell_level= this_player()->query("spells/"+spell)) )
			return notify_fail ( 
				"你不記得有這種法術。\n");

	} else if ( sscanf( str, "%s at %s", spell, targname)==2 || 
		        sscanf( str, "%s on %s", spell, targname)==2 ) {
		type = "";
		if ( MAGIC_D->alias_spell(spell) )  
			spell = MAGIC_D->alias_spell(spell);
		if( undefinedp(spell_level= this_player()->query("spells/"+spell) ) )
			return notify_fail (
				"你不會這種法術。\n");
	}
	else
	if ( sscanf( str, "%s %s",type, spell)==2 ) 	{
		if ( MAGIC_D->alias_spell(spell) )  
			spell = MAGIC_D->alias_spell(spell);
		if ( undefinedp(spell_level= this_player()->query("spells/"+spell)) )
			return notify_fail ( 
				"你不記得有這種法術。\n");
		targname = "NONE";

	} else {
		spell = str;
		if ( MAGIC_D->alias_spell(spell) )  
			spell = MAGIC_D->alias_spell(spell);
		if ( undefinedp( spell_level= this_player()->query("spells/"+spell) ) )
			return notify_fail( 
				"你不記得有這種法術。\n");
		targname = "NONE";
	}
	
	code = MAGIC_D->find_spell( spell );
	if( !code )
		return notify_fail(
			"沒有這種法術 .... 請通知巫師或用 bug 指令報告法術名稱。\n");

    if( !this_player()->query("vision") && targname != "NONE" )
      return notify_fail(
	    "你看不見目標，怎麼施法!\n" );

if ((targname != "NONE") && ( spell != "star-memory") && ( spell != "astral-gate"))
{
	target = present(targname, environment(this_player()));
	if (!target) return notify_fail("你想對誰施法？\n");
	if( (int)target->query("ghost")==1 )
            	    return notify_fail("這個可憐蟲已經死了，你還想怎樣？\n");
}
	if( this_player()->query("weapon1") && ( this_player()->query("weapon2") ||
	     this_player()->query("armor/shield") ) )
	  return notify_fail( 
	    "你沒空出任何手施法術!\n");

	if( !type || type == "" ) {
//    spell_level -= (int)this_player()->query("spell_power");
	  spell_power = this_player()->query("spell_power");
	  if (spell_power <0)	spell_level += spell_power;
	  if (spell_power >0) 
	    spell_level = (spell_power > spell_level) ? spell_level : spell_power;
	}
    else
      switch( type ) {
        case "max"     : break;
        case "regular" : spell_level -= 1; break;
        case "normal"  : spell_level -= 2; break;
        case "minor"   : spell_level -= 3; break;
        case "mini"    : spell_level -= 4; break;
        default : return notify_fail( 
          "沒有這種法術出力，請用 max, regular, normal, minor, mini。\n" );
      }
    if( spell_level < 0 ) spell_level = 0;
	sp_cost = (int)code->query_sp_cost( this_player(), spell_level, targname );
	if (!(this_player()->query("npc")))
	{
	if( sp_cost && (int)this_player()->query("spell_points") < sp_cost )
		return notify_fail("你的法力不夠！\n");

	if( (int)this_player()->query("talk_points") < TP_COST )
		return notify_fail("你沒有力量念出咒文！\n");
	
	if( this_player()->query_attacker() ) {
		skill = this_player()->query_skill("concentrate");
		if( random((sp_cost>100)? 100 : sp_cost) > skill ) {
			write("你無法有效集中精神！\n");

			tell_room( environment(this_player()), 
                            sprintf("%s喃喃地念了一段咒文，可是似乎無法專心念完。\n",this_player()->query("c_name")),
				this_player() );
			this_player()->add("spell_points", -sp_cost/2);
			this_player()->add("talk_points", -TP_COST);
			return 1;
		}
	}
	}
	
	if( code->cast(spell_level, targname) ) {
	  this_player()->add("spell_points", -sp_cost );
	  this_player()->add("talk_points", -TP_COST);
	}
	return 1;
}

int help()
{
		write( @C_HELP
指令格式: cast [出力] <法術名稱> [on|at] <目標>

這個指令讓你用來施展法術，並不一定所有的法術都要指定目標，有些法術則會
自行選定目標。你可以用 spells 指令看你目前已經學會的法術列表。出力可有
可無，沒指定則以目前你設定的標準出力為準。你可用spellpower指令看你目前
法術的標準出力。出力可為 max, regular, normal, minor, mini 。

法術名稱可用簡寫代替, 請用 info slist 指令去查閱各法術的簡寫。
C_HELP
		);

    return 1;
}
