#include "../farwind.h"

inherit MONSTER;

void create()
{
	::create();
	set_level( 3 );
	set_name( "smith", "鐵匠" );
	add( "id", ({ "old smith" }) );
	set_short( "老鐵匠" );
	set_long("@@query_long");
	set( "gender", "male" );
	set( "race", "dwarf" );
	set( "alignment", 800 );

	set( "chat_chance", 20 );
	set( "chat_output", ({
		"老鐵匠將燒紅的鐵塊浸入水中，發出一陣滋滋的聲音。\n",
		"老鐵匠說道: 拜託，倒杯水給我喝好嗎？\n",
		"老鐵匠用掛在脖子上的毛巾擦汗。\n"
	}) );
	set("max_hp", 200);
	set("hit_points", 200);
	set( "wealth/silver", 40 );
	set( "tactic_func", "my_tactic" );
	set_natural_weapon( 4, 2, 2 );
	set_natural_armor( 30, 10 );
	wield_weapon( FARWIND"items/hammer" );
}

string query_long()
{
	if( query("chat_chance") )
		return "這個老鐵匠正在努力工作，瞧他滿身大汗的樣子，如果你能替他倒一杯水\n"
		"喝，他一定會感謝你。\n";
	else return "老鐵匠正在辛勤地工作著，不過看起來他似乎樂在其中。\n";
}

int accept_item(object who,object item)
{
    if ( !item->query("quest_smith") ) return 1;
    if ( !item->query_filled() ) {
         tell_room( environment(), 
			"老鐵匠嘆了口氣: 我很忙，別拿空杯子和我開玩笑。\n");
			command("give cup to "+who->query("name"));
			return 1; 
	     }
	 item->remove();  
	 set( "chat_chance", 0 );

     tell_room( environment(), 
	    sprintf("老鐵匠向%s(%s)點頭微笑，說道: 謝謝！\n",
		who->query("c_name"),who->query("name") )
		,who );
	tell_object( who,"老鐵匠向你點頭微笑，說道: 謝謝！\n");
	if( (int)who->query_quest_level("smith") < 1 ) {
		who->finish_quest("smith", 1);
		tell_object( who, 
			"[你完成了 Smith 任務，得到 1000 點經驗]\n"
			);
		who->gain_experience(1000);
		}
	return 1;
}

void reset()
{
	set( "chat_chance", 15 );
}

int my_tactic()
{
	object victim, weapon;
	int wc;

	if( random(20)>4 ) return 0;
	if( !(victim= query_attacker()) ) return 0;
	if( !(weapon = victim->query("weapon1")) )
		weapon = victim->query("weapon2");
	if( !weapon ) return 0;
	tell_room( environment(), 
		"老鐵匠高舉鐵錘，往" + victim->query("c_cap_name") + "的" + 
		weapon->query("c_name") + "「匡啷」一聲敲了下去。\n",
		({ this_object(), victim }) );
	tell_object( victim,
		"老鐵匠高舉鐵錘，往你的" + 
		weapon->query("c_name") + "「匡啷」一聲敲了下去。\n");
	wc = weapon->query("weapon_class");
	wc -= weapon->query("wc_damaged");
	if( !weapon->query("wc_damaged") ) {
		weapon->add( "short", " (受損)" );
	}
	weapon->add( "wc_damaged", wc/2 );
	victim->calc_weapon_class();
	return 1;
}
