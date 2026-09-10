#include <mudlib.h>
#include "/d/noden/nodania/nodania.h"
inherit "/d/noden/nodania/monster/guard" ;

void init()
{
	::init();
	add_action("order_me","order_guard");
	add_action("help_order", "help_guard");
}

void create()
{
        ::create();
        set_level(14);
        set_name("body guard","貼身侍衛");
        add( "id", ({ "guard" }) );
        set_short( "找不到主人的貼身侍衛");
        set_long(
@C_LONG
這位貼身侍衛尚在測試中, 看起來還不成熟, 身上有一堆bug爬來爬去
噁心死了 *puke*
如果你是他的主人，你可以用 order_guard <commands> 命令他做事。
另外還有一些指令, 你可以打help_guard看看。
C_LONG
        );
        set("post_name","'s body guard");
        set("c_post_name","的貼身侍衛");
        set("prevent_give_money", 1);
        setenv("C_MMIN","$N跟著他的主人走了過來");
        setenv("C_MMOUT","$N跟著他的主人走開");
	set_perm_stat("str", 20 );
	set_perm_stat("dex", 20 );
	set_perm_stat("con", 20 );
	set_skill("axe", 75);
	set_skill("parry", 75);
	set_skill("block", 75);
	set_skill("defend",75);
	set_natural_armor( 30, 6 );
	set_natural_weapon( 10, 4, 8 );

	set( "race", "human" );
	set( "gender", "male" );
	set( "alignment", 600 );
	set( "wealth/silver", 300 );
	set( "special_defense", ([ "all": 25 ]) );
	set( "war_score", 5000 );
	wield_weapon("/d/knight/fortress/weapons/battleaxe");
	equip_armor(NODANIA"obj/shield");
	equip_armor(NODANIA"obj/breast_plate");
}
