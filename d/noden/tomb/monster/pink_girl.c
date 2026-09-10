#include <mudlib.h>

inherit MONSTER;

void create()
{

	::create();
	set_level(10);
	set_name( "pink girl", "粉紅色小女孩" );
	add( "id",({ "girl" }) );
   set_short( "粉紅色小女孩" );
	set_long(
		"你看到一個粉紅色、發著微光的小女孩的身影，她的輪廓並不是很清\n"
           "楚，使你不禁懷疑她是不是鬼魂。或許你可以問她一些關於墓室的事\n"
           "情。\n"
	);
	set_perm_stat( "str", 6);
	set_perm_stat( "int", 16);
	set_skill( "dodge", 70);
	set_skill( "tactic", 70 );

	set( "alignment", 1000 );
	set( "tactic", "flank" );
	set( "race", "shapeshifter" );
	set( "gender", "female" );
	set_natural_armor( 30, 10 );
	set_natural_weapon( 20, 6, 8 );
	set( "wealth/gold", 5 );
   set( "inquiry", ([
            "mummy" : "那個整天咿咿啊啊的傢伙啊?\n"
                      "如果你運氣夠好, 他會教你繃帶包紮。\n",
            "torch" : "你問外面那隻火把啊? 用力拉下(pull)就好了...\n"
                       "不過...嘻嘻...我不告訴你其它秘密...\n",
            "skeleton" :
@LONG
唉...那是我的屍骨............
當我第一次來到這墓穴時, 不小心闖入一間有恐怖怪物
的房間; 在一眨眼間, 我身中劇毒, 痛苦不堪........
最後想想, 與其痛苦身亡, 不如一刀自我了斷........
LONG
   ]) );

   equip_armor( "/d/noden/tomb/obj/bkernel" );
}
