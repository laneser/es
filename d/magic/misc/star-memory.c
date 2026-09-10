// This is a spell object. type -> misc
// level    0
// cost    50
// time    --
// skill   80
// G_LVL   --	注: 魔法熟練度對本法術無任何影響
// G_EXP   30
#include <mudlib.h>
#define TYPE "misc"

inherit DAEMON;
inherit "/d/magic/magic";
inherit MESSAGE;

int query_gain_spell_exp(int level) { return 30; }

int query_need_spell_level(int level) { return 0; }

int query_sp_cost(object caster, int level) { return 50; }

int query_need_skill(int level) { return 80; }

int cast(int level, string dest)
{
    object me;
	
	me = this_player();

	if( (int)me->query_skill("misc") < query_need_skill(level) ) {
	  tell_object( me, 
		      "你的雜項魔法技能不足以使用這個魔法! \n" 
		      );
      return 0;
    }

	if (!dest) {
		tell_object( me, "你想把關於這個地方的記憶寄放在哪裡呢?\n" );
		return 0;
	}
	switch (dest)
	{
		case "aqua"		: break;
		case "pyro"		: break;
		case "aero"		: break;
		default	:	{
			tell_object(me, @FAIL
「星之憶」可以將所有關於此地的回憶寄放於天上的星辰, 但是僅有水之
星 (Aqua) 火之星 (Pyro) 與風之星 (Aero) 才擁有足夠的能力存下如此
多的思緒。
指令格式: cast star-memory [on|at] <星辰>
FAIL
			);
			return 0;
		};
	}

	if ( !environment(me)->query("outside") )
	{
		tell_object( me, "這裡看不到星星, 沒辦法使用星之憶。\n");
		return 0;
	}	
	if ( environment(me)->query("no_teleport") )
	{
		tell_object( me, "在這裡無法感受到天上的諸星, 無法留下記憶。\n");
		return 0;
	}
	
	emote( "$NS低頭默唸咒文, 將所有關於此地的記憶繫結於天上的諸星。\n"
		, me );

	me->set("teleport_points/" + dest, base_name(environment(me)) );
    gain_spell_experience(me, TYPE, query_gain_spell_exp(level));
	return 1;
}
