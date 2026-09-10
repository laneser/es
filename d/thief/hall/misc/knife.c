#include <mudlib.h>
#define MASK_OBJ "/d/thief/hall/misc/mask"
#define MAKE_SKILL "anatomlogy"
inherit OBJECT;

init()
{
	add_action("do_cut","cut");
}

void create()
{
	seteuid(getuid());
	set_name( "knife","割皮小刀" );
	set_short( "割皮小刀" );
	set_long( @LONG
    這是一把輕薄銳利的小刀, 是擅長製造面具的人常用的工具之一。
你可以用 cut skin from corpse 取一塊皮來做面具。
LONG
	);
	set( "weight",10 );
	set( "unit","把");
	set( "value",({ 230,"silver" }));
}
int check_skill(object me)
{
	int skill1,skill2,rate;
	if ( (string) me->query("class") != "thief" ) 
		return 0;
	if ( ( skill1 = (int) me->query_skill(MAKE_SKILL) ) == 0 )
		return 0;
	if (random(skill1 + (int) me->query_stat("piety") ) > 20 )
		return 1;
	else 
		return 0;
}

int query_sp_cost(object me)
{
	return ( 80 - (int)me->query_skill(MAKE_SKILL) ) ;
}

do_cut(string arg)
{
	string *args,tmp;
	int sz,i,skill;
	object *inv,env,mask,corpse,mob;

	if ( ! arg ) 
		return notify_fail("你想要割什麼?\n");
	if ( sscanf(arg,"skin from %s",tmp) != 1)
		return 0;
	if ( !this_player()->query_vision() )
		return notify_fail("這裡一片漆黑 ! 你什麼也看不到 !!\n");
	env = environment(this_player());
	if ( ! (corpse = present(tmp,env)) ) 
		return notify_fail("這裡沒有這種□體 。\n");
	if (sscanf((string)corpse->query("short"),"%s的屍體",tmp) < 1 || tmp == "腐爛") {
		return notify_fail("這□體已經發臭了, 做成面具可能會得皮膚病, 你敢嗎?? \n");
	}
	if ( (i = query_sp_cost(this_player())) > (int)this_player()->query("spell_points") ) {
		return notify_fail("你精神力太低了, 無法做這種精細的工作。\n");
	}

	this_player()->add("spell_points",-i);
	if ( ! (tmp = (string) corpse->query("npc")) ) 
		return notify_fail("割下皮後,你覺得這種材料並不適合做面具。\n");
	mob = new(tmp);
	if ( nullp(mob) ) {
		write("這邊有 bug, 請通知巫師!\n");
		return 1;
	}

	if ( check_skill(this_player()) ) {
		tell_room(env,sprintf("%s在□體上劃幾刀, 取下某樣東西。\n",this_player()->query("c_name") ), this_player() );
		write(sprintf("你小心翼翼的從□體上取下臉皮, 順利的完成了%s的面具。\n",(string)mob->query("c_name") ));
		mask = new(MASK_OBJ);	
		mask->set_short(mob->query("short")+"的面具");
		mask->set("mask_name", mob->query("name") );
		mask->set("c_mask_name",mob->query("short") );
		mask->add("extra_ids",mob->query("id"));
		mask->move(this_player());
		corpse->remove();
		mob->remove();
		return 1;
	} else {
	tell_room(env,sprintf("%s試著從□體上取下臉皮, 結果失敗了!\n",this_player()->query("c_name") ), this_player() );
		corpse->remove();
		mob->remove();
		return notify_fail("你一個不小心, 割壞了皮, 不能用了!!\n");
	}
}

