#include "ruin.h"
inherit ROOM;

void create()
{
	::create();
	set("light",0);
	set_short("通道");
	set_long(@CLong
這裡是條南北方向的通道, 上下左右的牆壁均是由石塊砌成的, 看來
相當地雄偉壯觀。通道的兩側排列著精美的石雕像, 而且各個都有不同的
神情姿勢, 令人為建造者的心思讚歎不已。
    由這裡往南往北都是一片黑暗。
CLong
	);
	set("exits",([
		"south"	: RUIN"tunnel_2",
		"north"	: RUIN"tunnel_4",
		]));

        add( "item_desc", ([
                "statues"       : @C_ITEM_DESC_1
    這些石雕像都被安置於壁上一個個凹入的半圓形小洞中, 被維護得相
當好。他們的均是以小鬼族的造型來塑造的, 活潑的神情與栩栩如生的姿
態看來非常有趣。尤其當中有一隻做伸手模樣的小鬼真的是可愛極了。
C_ITEM_DESC_1
                ,"statue"       : @C_ITEM_DESC_2
    這個雕像刻著一隻俏皮的小鬼, 伸著小手, 睜著大大的眼睛望著你,
讓你忍不住想伸出手來碰碰它。
C_ITEM_DESC_2
                ]) );

	reset();
}

void init()
{
	add_action("do_touch_statue", "touch");
}

int is_a_user(object player)
{
	if( userp(player) ) return 1;
	return 0;
}

int do_touch_statue(string s)
{
	int i;
	object *players, me;
	
	if(!s) return notify_fail( "你要碰什麼?\n" );
	if( (s != "hand") && (s != "statue") )
		return notify_fail( "這裡有這種東西嗎?\n" );
	me = this_player();
	tell_room( environment(me),
		me->query("c_name") + 
		"摸了摸雕像的手, 突然地上出現一個大洞, 你掉了下去!!\n"
		,me
	);
	write(@ALONG
你摸了摸雕像的手, 正覺得很有趣時, 突然看見小鬼的嘴角竟露出奸笑! 
你感到: 不妙!!正想放手時....
突然腳底一空, 地上出現一個大洞, 你掉了下去!!
ALONG
	);
   me->set_explore("noden#17");
	players = filter_array(
		all_inventory(this_object()),"is_a_user", this_object());
	for( i=0; i<sizeof(players); i++ ) {
		players[i]->move_player(RUIN"mob_storage","SNEAK");
		tell_room(environment(players[i]),
			players[i]->query("c_name")+"掉了下來。\n", players[i]
		);
	}	
	return 1;
}
