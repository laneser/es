//#pragma save_binary

// bank.c
// A basic bank object. Players can open an account, receiving a bank card.
// The bank card is an autoloading object that keeps track of how much
// money they have deposited. At the bank, players can withdraw or deposit
// funds.
// The bank has a create function which sets the euid of the object. Any
// file than inherits this file needs to ::create() in its create function.
// Note that the bank does not store the account data internally. Instead,
// each player's account data is stored in his bank card. This makes lookup
// faster but it does mean the player has to keep his card safe.
// Created by Mobydick@TMI-2, 8-28-92

#include <move.h>
#include <mudlib.h>
#include <money.h>

inherit COINVALUE;

void init()
{
	add_action ("open_account", "open");
	add_action ("deposit", "deposit");
	add_action ("withdraw", "withdraw");
}

// Open_account lets the player open his bank account. It gives him a bank
// card which is where his account data is stored. The fee is set at 25
// gold pieces but you can change that very easily if you desire.

int open_account(string str)
{
	int i;
	object ob ;

	if (!str || str != "account")
		return notify_fail(
			"你要開戶的話，請用 open account。\n");

	if( present("bank card", this_player())||
		present("credit card", this_player()) ) {
		write(
			"你已經有帳戶了。\n" );
		return 1 ;
	}

	if(this_player()->query("bank_balance")) {
		write (
			"咦？你把提款卡搞丟了 .... 沒關係，我們馬上發給你一張新的提款卡。\n");
		if( member_group(geteuid(this_player()), "admin") )
			ob = clone_object(ADM_CREDIT_CARD_FILE);
		else
			ob = clone_object(BANK_CARD_FILE);
		ob->move(this_player()) ;
		return 1 ;
	}
	if( !this_player()->debit("gold", 25) ) {
		write( 
			"你需要 25 塊金幣才能開戶！\n");
		return 1 ;
	}
//	if( member_group((string)this_player()->query("name"), "admin") )
//		ob = clone_object(ADM_CREDIT_CARD_FILE);
//	else
		ob = clone_object(BANK_CARD_FILE);
//	ob->assign(this_player());
	ob->move(this_player());
	write ( 
		"你現在有了屬於你自己的帳戶了！這是你的提款卡，好好保管吧！\n");
	tell_room( this_object(), 
		this_player()->query("c_name")+"向銀行申請了一個帳號。\n",
		this_player() );
	this_player()->set("bank_balance", ([ ]) ) ;
	return 1 ;
}

// Withdraw allows a player to withdraw money from his bank account. The
// player must have his card to permit this. The function checks his card
// to make sure he has enough money to make the withdrawal.
// The bank knows about conversion: if the player wants to withdraw 5 gold
// and has 0 gold and 50 silver in the bank, the bank withdraws his 50 silver
// and gives him the 5 gold. More comments on this below.

int withdraw (string str)
{
	int number, i;
	int oldval, newval, newnum ;
	string type, word, newtype ;
	object card, coins ;
	string *types ;

	if (!str || sscanf(str,"%d %s",number,type)!=2 )
		return notify_fail( 
			"指令格式: withdraw <數量> <錢幣種類>\n");

	if (number<1)
		return notify_fail(
			"你想提出「負數」的錢來增加存款？別傻了！\n");

	card = present("bank card", this_player());
	if( !card ) card = present("credit card", this_player());
	if( !card )
		return notify_fail( 
			"你身上沒有提款卡 .... 請用 open account 開戶或申請補發。\n");
			
//	if( (int)card->query_val(type)>=number ) {
	if( (int)this_player()->query("bank_balance/"+type) >= number ) {
		if (this_player()->credit(type, number)) {
			if (number==1) word = "coin" ; else word="coins" ;
			write( 
				"你從帳戶提出 "+ number+ " 塊" + to_chinese(type + " coin") + "。\n");
			tell_room( this_object(), 
				this_player()->query("c_name")+"從銀行領出一些"+to_chinese(type+" coin")+"。\n",
				this_player() );
			this_player()->add("bank_balance/"+type,-number);
//			card -> add_val (type,-number) ;
			return 1 ;
		} else
			return notify_fail(
				"你身上無法攜帶這些錢幣，請通知巫師處理。\n");
	}
	
	return notify_fail(
		"你的帳戶裡沒有這麼多" + to_chinese( type + " coin") + "。\n");
}

// Deposit allows a player to put his money in the bank.

int deposit(string str)
{
	int i, number;
	string type, word ;
	object card ;

	if (!str || sscanf(str,"%d %s",number,type)!=2 )
		return notify_fail(
			"指令格式: deposit <數量> <指令種類>\n");

	if (number<1)
		return notify_fail(
			"你不能存入「負數」的錢，明白嗎？\n");

	i = this_player()->query("wealth/"+type) ;
	if (i<number)
		return notify_fail( 
			"你身上沒有那麼多" + to_chinese( type + " coin" ) + "。\n");

	card = present( "bank card", this_player() );
	if( !card ) card = present( "credit card",this_player() );
	if( !card )
		return notify_fail(
			"你必須先開戶(open account)才能在銀行存錢。\n");

	if( !this_player()->debit( type, number ) ) {
		write(
			"你目前身上的錢可能有點問題，請通知巫師處理。\n");
		return 1;
	}
	this_player()->add("bank_balance/"+type,number);
//	card->add_val(type,number) ;
	if (number==1) word="coin" ; else word="coins" ;
	write( 
		"你在自己的帳戶存入 "+number+" 塊"+to_chinese(type+" coin")+"。\n");
	tell_room( this_object(), 
		this_player()->query("c_name")+"將一些"+to_chinese(type+" coin") +"存入自己的帳戶。\n",
		this_player() );
	return 1 ;
}
