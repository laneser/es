//這個物件是參考/d/thief/hall/misc/knife.c 還原來的
//在此感謝原作者aqaurius                     
//                                               Takeda 於95年11 月

#include <mudlib.h>
#define SKIN_OBJ "/d/adventurer/hall/obj/skin"
#define MAKE_SKILL "anatomlogy"
inherit OBJECT;

init()
{
	add_action("do_cut","cut");
}

void create()
{
	seteuid(getuid());
	set_name( "knife","剝皮小刀" );
	set_short( "剝皮小刀" );
	set_long( @LONG
    這是一把輕薄銳利的小刀, 是獵取毛皮的人常用的工具之一。
你可以用 cut skin from corpse 取下野獸的皮。
LONG
	);
	set( "weight",10 );
	set( "unit","把");
	set( "value",({ 230,"silver" }));
}
int check_skill(object me)
{
	int skill1,skill2,rate;
	if ( (string) me->query("class") != "adventurer" ) 
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
	object *inv,env,skin,corpse,mob;

	if ( ! arg ) 
		return notify_fail("你想要割什麼?\n");
	if ( sscanf(arg,"skin from %s",tmp) != 1)
		return 0;
	if ( !this_player()->query_vision() )
		return notify_fail("這裡一片漆黑 ! 你什麼也看不到 !!\n");
	env = environment(this_player());
	if ( ! (corpse = present(tmp,env)) ) 
		return notify_fail("這裡沒有這種□體 。\n");
        if (sscanf((string)corpse->query("short"),"%s的屍體",tmp) < 1 || tmp =="腐爛") {
		return notify_fail("這屍體已經發臭了, 你敢碰它嗎?? \n");
	}
	if ( (i = query_sp_cost(this_player())) > (int)this_player()->query("spell_points") ) {
		return notify_fail("你精神力太低了, 無法做這種精細的工作。\n");
	}

	this_player()->add("spell_points",-i);
	if ( ! (tmp = (string) corpse->query("npc")) ) 
		return notify_fail("割下皮後,你覺得這種皮好像品質不是很好。\n");
	mob = new(tmp);
	if ( nullp(mob) ) {
		write("這邊有 bug, 請通知巫師!\n");
		return 1;
	}

	if ( check_skill(this_player()) ) {
		tell_room(env,sprintf("%s在屍體上劃幾刀, 取下一張皮。\n",this_player()->query("c_name") ), this_player() );
		write(sprintf("你小心翼翼的從屍體上剝下一張皮。\n",(string)mob->query("c_name") ));
		skin = new(SKIN_OBJ);	
		skin->set_short(mob->query("short")+"的皮");
		skin->set("skin_level", mob->query_level() );
		skin->set("c_skin_name",mob->query("short") );
		skin->set("make_skill",(int)this_player()->query_skill("anatomlogy"));
		skin->add("extra_ids",mob->query("id"));
		skin->move(this_player());
		corpse->remove();
		mob->remove();
		return 1;
	} else {
	tell_room(env,sprintf("%s試著從屍體上取下皮, 結果失敗了!\n",this_player()->query("c_name") ), this_player() );
		corpse->remove();
		mob->remove();
		return notify_fail("你一個不小心, 割壞了皮, 不能用了!!\n");
	}
	return 0;
}

