#include <mudlib.h>
#include <body.h>
#include <races.h>

inherit COINVALUE;
inherit RACE_ELF;

void create()
{
	::create();
	set_level(18);
	add( "id", ({ "elf","taxman", "shilufu"}) );
	set_name( "elf taxman shilufu" , "精靈稅官 希露芙");
	set_short("精靈稅官 希露芙");
	set_long(@LONG
她是島上少數的精靈，因為她十分靈巧，所以村裡委託她來做這個
吃力不討好的工作，她的特技是隱形來查稅，村裡的投機份子大多
吃過她的苦頭。
LONG
	);
	set( "gender", "female" );
	set_perm_stat( "str", 30 );
	set_perm_stat( "dex", 30 );
	set( "time_to_heal", 5 );
	set( "unarmed",100 );
	set( "wimpy" , 200 );
	set( "max_hp" , 600 );
	set( "hit_points" , 600 );
	set_skill( "dodge", 100 );
	set_natural_armor( 100, 40 );
	set_natural_weapon( 70, 20, 65 );
	set( "alignmnet", 500 );
	set( "wealth/gold", 150 );
//	set( "forgetful" , 1 );
	set( "player_invisible" ,1 );
}

void init()
{
	object ob;
	::init();
	
	add_action("do_kill","kill");
	if( !(ob= this_player()) || !userp(ob) ) return;
	call_out( "check_wealth", 0, ob );
}

do_kill(string arg)
{   
	if(arg=="elf"||arg=="taxman"||arg=="shilufu") {
		call_out("do_inv",5);
		return 0;
	}
	return 0;    
}
  
string c_call(object who)
{
	if ((string)who->query("gender") == "female")
		return (!who->query("spouse")) ? "小姐" : "太太" ;
	else
		return (!who->query("spouse")) ? "帥哥" : "先生" ;
}

void check_wealth(object ob)
{
	string *types,type,name,c_name;
	mapping money,bank;
	object env;
	int i,total;
	
	name = (string)( this_player()->query("name") );
	c_name = ob->query("c_name");
	env = environment();
	
	if( !env || !present(ob, env) ) return;
	if( name=="ishige" || name=="odin" || name=="tsunami" || name=="mercury") {
		tell_room( env,"\n希露芙道了個萬福: 辛苦您了, 巫師 "+c_name+"。\n\n" ,this_object() );
		return;
	}
	if( wizardp(ob) ) {
		tell_room( env,"\n希露芙瞪了你一眼後說道: 原來是巫師 "+c_name+" ,害我以為是那個倒楣的闊佬來交稅金了。\n\n" );
		return;
	}
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
		command( "visible" );
		tell_room(env,"希露芙微笑說道：『"+c_call(ob)+"被我抓到了唷！捐點建設經費吧！』\n\n",
		this_object() );
		
		types = keys(money);
		for( i=0; i<sizeof(types); i++ ) 
		{	money[types[i]] /= 3;
			type = types[i];
			credit( type,money[types[i]] );
		        money[types[i]] *= 2;
		}        	
		ob->set( "wealth", money );
		types = keys(bank);
		for( i=0; i<sizeof(types); i++ )
		{
			bank[types[i]] /= 3;
			type = types[i];
			credit( type,bank[types[i]] );
			bank[types[i]] *= 2;
		}
		ob->set( "bank_balance", bank );

		tell_object( ob,"暗藏了那麼多錢，你自己都覺得不好意思，自動自發的捐出了三分之一的錢\n");
		call_out( "do_inv" , 10 );
	} 
	
	else {
	tell_room( env,"希露芙笑著說: " +c_name+c_call(ob)+"，您是來觀光的嗎？\n",this_object() );
	}
	return;
}

void do_inv()
{
	command( "invisible" );
	return;
}
