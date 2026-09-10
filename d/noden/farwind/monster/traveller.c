#include <mudlib.h>

inherit MONSTER;

string *rumors = ({
	"聽說默爾斯帝國軍最近又要來了，不知道這次他們會打哪一個城鎮？",
	"如果你想到東方，可以到藍沙港去等伊莉雅皇后號渡船。",
	"藍沙港南邊有一棟鬧鬼的屋子，聽說那裡一夜之間死了七、八個人....",
	"你去過精靈村嗎？我到現在還搞不清楚精靈村的正確位置。",
	"滿月的時候塔姆姆族會出來獵人頭，不想死的人最好別靠近河流的上游....",
});

void create()
{
	object ob1, ob2, ob3;

	::create();
	set_level( 7 );
	set_name( "traveller", "過路旅客" );
	set_short( "過路旅客" );
	set_long(@C_LONG
這個人看起來雖然疲憊不堪，但是你從他結實的肩膀和手臂可以看得出
他是一個很有經驗的旅行家，如果你有時間，可以向他打聽一些在這附
流傳的一些流言(rumors)。
C_LONG
	);
	set_perm_stat( "str", 10 );
	set_perm_stat( "kar", 10 );
	set_skill( "longblade", 70 );
	set_skill( "parry", 40 );

	set( "gender", "male" );
	set( "race", "human" );
	set( "wealth", ([ "gold" : 10 ]) );
	set( "inquiry", ([
		"rumors" : "@@ask_rumors" ]) );

	ob1 = new( "/d/noden/farwind/items/rapier" );
	ob1->move( this_object() );
	wield_weapon( ob1 );

	ob2 = new( "/d/noden/farwind/items/gloves" );
	ob2->move( this_object() );
	equip_armor( ob2 );

	ob3 = new( "/d/noden/farwind/items/buskin" );
	ob3->move( this_object() );
	equip_armor( ob3 );
}

string ask_rumors()
{
	int i;

	i = random(sizeof(rumors)/2) * 2;
	if( environment() )
		tell_room( environment(),
			"過路旅客說道: " + rumors[i+1] + "\n",
			this_object() );
}
