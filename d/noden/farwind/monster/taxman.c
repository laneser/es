#include <mudlib.h>
#include <body.h>

inherit COINVALUE;
inherit MONSTER;

void create()
{
	::create();
	set_level(1);
	set_name("Bikabal", "稅務官");
	add( "id", ({"taxman", "man"}) );
	set_short("稅務官畢卡博");
	set_long(@C_LONG
畢卡博是個好人——你必須承認這一點，他不像其他的稅務官會拿走你
身上全部的錢，畢卡博只有在你實在太有錢時才會向你收稅。
C_LONG
	);
	set( "race", "halfling" );
	set( "gender", "male" );
	set( "no_attack", 1 );
}

void init()
{
	object ob;

   npc::init();
	if( !( ob= this_player()) || !userp(ob) ) return;
	call_out( "check_wealth", 0, ob );
}

void check_wealth(object ob)
{
	string *types;
	mapping money, bank;
	int i, total;

	if( !ob || !this_object() ) return;
	if( member_group(geteuid(ob), "admin") ) {
		command("bow "+(string)ob->query("name"));
		command("say 親愛的大神, 歡迎光臨!!\n");
		command("bow "+(string)ob->query("name"));
		return;
	} else command( "say 嗨! "+ob->query("c_name") + ".\n" );
	money = (mapping)ob->query("wealth");
	if( !money ) money = ([]);
	bank = (mapping)ob->query("bank_balance");
	if( !bank ) bank = ([]);

	types = keys(money);
	for( i=0; i<sizeof(types); i++ ) 
		total += money[types[i]] * coinvalue( types[i] );
	types = keys(bank);
	for( i=0; i<sizeof(types); i++ )
		total += bank[types[i]] * coinvalue( types[i] );

	if( total > (int)ob->query_level() * MAX_MONEY_EACH_LEVEL ) {
		command( "say 哦～～!!閣下原來是金牛級的大人物呀!!!!\n" );
		command( "say 來, 捐獻一些來縮短貧富差距吧!!!!!\n" );
		
		types = keys(money);
		for( i=0; i<sizeof(types); i++ ) 
			money[types[i]] /= 2;
		ob->set( "wealth", money );
		types = keys(bank);
		for( i=0; i<sizeof(types); i++ )
			bank[types[i]] /= 2;
		ob->set( "bank_balance", bank );

		tell_object( ob, "稅務官從你身上和銀行帳戶各拿走一半的錢。\n");
	}
}

