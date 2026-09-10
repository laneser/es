#include <mudlib.h>

inherit MONSTER;

void create()
{

	::create();
	set_level(11);
	set_name( "old miner", "老礦工" );
	add( "id", ({ "miner" }) );
	set_short( "老礦工" );
	set_long(@LONG
這個老人從年輕時就在段家工作了，老了之後段家顧用他來打理一些礦場上的瑣事
，所以你可以問他一些在礦坑裡的人和事．
LONG
);
	set_perm_stat( "str", 25 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "int", 15 );

	set( "natural_armor_class", 65 );
	set( "natural_defense_bonus", 20 );
	set_natural_weapon( 23, 18, 26);
	set( "time_to_heal", 2 );
	set( "max_hp", 400 );
	set( "hit_points", 400 );
	set( "gender", "male" );
	set( "alignment", 800 );
	set( "wealth/silver", 200 );
        set( "inquiry",([
             "detonation" : "我不清楚，不過你可以找那些命大的人問問．\n",
             "troll" : "我只知道他們是請來看守魔法磁鐵礦(magic magnetite)的．\n",
             "ghost":
"我就是不知道才在奇怪啊？算了看在你智商有點不太夠的\n"
"份上指點你一條明路吧．問看看老酒鬼知不知道．\n"
]));
	set( "chat_chance", 15 );
	set( "chat_output", ({
		"老礦工喃喃自語道: 大廳的南邊常有一些奇怪聲音發出來!不知道是不是有鬼(ghost)?\n",
		"老礦工說道: 自從有一天礦場發生大爆炸(detonation)後,一些人都變得怪怪的．\n",
	}));
	}