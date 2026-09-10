//#pragma save_binary

/*
// This file is part of the TMI Distribution Mudlib.
// Please include this header if you use this code.
// Slick Ace, 01/02/91
// Help added by Brian (1/28/92)
// Rewritten by Buddha to show equipped items properly (2/3/92)
// Changed by Mobydick@TMI-2 (9/16/92) to capitalize short descriptions
// and to handle the new equipping system.
// Replaced the hardcoded weight limit with included #defines. Moby, 4-26-93
*/

// Modified by Annihilator to fit mounted animals.

#include <move.h>
#include <player.h>
#include <mudlib.h>

#define SHORT_DESCRIPTION "short"

inherit DAEMON ;

int filter_invis(object ob, object carrier)
{
	return visible(ob,carrier);
}
int cmd_inventory(string arg)
{
	object *items, me, ob;
	int coin, i, x, count;
	string result, tmp, *names, unit;
	mapping inv;

	count = 0;
	if( arg && wizardp(this_player()) ) {
		me = find_living(arg);
		if( !me ) return notify_fail("沒有這個人....。\n");
	} else me = this_player();

	coin = me->coins_carried();
	items = filter_array(all_inventory(me), "filter_invis", this_object(), me);
	for (i = 0; i < sizeof(items); i++)
		if(items[i]->query(SHORT_DESCRIPTION))
			count++;
	result = count? ("你現在總共帶著 "+count+" 樣物品" + (coin?("，與 "+coin+" 枚錢幣: \n"):": \n"))
			 : ("你現在身上沒有任何東西"+(coin?"，但是有 "+coin+" 枚錢幣。\n":"。\n"));

	result += sprintf("(總重量 %d.%d 公斤, 上限 %d.%d 公斤)\n",
		(int)me->query("load")/10,
		(int)me->query("load")%10,
		(int)me->query("max_load")/10,
		(int)me->query("max_load")%10);

	ob = me->query_temp("mounting");
	if( ob ) result += 
		"你現在正騎在一" + ob->query("unit") + ob->query("c_name") + "上，有 * 記號的物品\n"
		"表示正馱在它身上。\n";

// Always use compact mode. Compact mode is more convenient for players.
// It also costs fewer eval cost when the user carry many objs of the same.
//                            Modified by Iris 2/24/96
//	if( this_player()->getenv("compact") ) {
		inv = unique_mapping(items, "query", "short");
		names = keys(inv);
		for (x=sizeof(names)-1; x > -1; x--) {
			if(tmp=(string)inv[names[x]][0]->query(SHORT_DESCRIPTION)) {
		tmp += " ("+inv[names[x]][0]->query("name")+")";
		if( inv[names[x]][0]->query("wielded")) tmp += " (武器)";
		if( inv[names[x]][0]->query("equipped")) tmp += " (護甲)";
		if( inv[names[x]][0]->query("invisible")) tmp += " (隱形)";
		if( inv[names[x]][0]->query("mounted")) tmp += " (座騎)";
		if( inv[names[x]][0]->query("secure")) tmp+= " [標記設定]";
				if( sizeof(inv[names[x]]) > 1 ) {
					if( !unit= inv[names[x]][0]->query("unit") ) unit = "個";
					tmp = chinese_number(sizeof(inv[names[x]])) + unit + tmp;
				}
				if( inv[names[x]][0]->query("on_mounted")) result += "* " + tmp + ".\n";
				else result += "  " + tmp + ".\n";
			}
		}
//	}
/*	else for (x=0; x < sizeof(items); x++) {
		if(tmp=(string)items[x]->query(SHORT_DESCRIPTION)) {
		tmp += " ("+items[x]->query("name")+")";
		if(items[x]->query("wielded")) tmp += " (武器)";
		if(items[x]->query("equipped")) tmp += " (護甲)";
		if(items[x]->query("invisible")) tmp += " (隱形)";
		if(items[x]->query("mounted")) tmp += " (座騎)";
		if(items[x]->query("secure")) tmp += " [標記設定]";
		if(items[x]->query("on_mounted")) result += "* " + tmp + ".\n";
			else result += "  " + tmp + ".\n" ;
		}
	}
*/
	write(result);
	return 1;
}

int help()
{
	write( @HELP
指令格式: inventory

	這個指令可以列出你現在身上所攜帶的物品。
HELP
	);
	return 1;
}
/* EOF */
