#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level( 10 );
	set_name( "shop owner", "商店老闆" );
	add( "id", ({ "owner" }) );
	set_short( "商店老闆" );
	set_long(@C_LONG
商店老闆是個中年人，頭頂微禿，臉上常常帶著一副憨厚的笑
容。你可以放心的把想要鑑定的物品給他，他一生中最大的興趣就
是鑑定各種稀奇古怪的物品。
C_LONG
    	       );
	set( "no_attack", 1 );
	set( "gender", "male" );
}

int accept_item(object who, object item)
{
   tell_room( environment(),
        "商店老闆奸笑道: 謝了! 白痴!\n"
        "( 商店老闆把"+item->query("c_name")+"收起來! )\n" );
   item->remove();
   return 1;
}
