#include "takeda.h"

#define HORSEDIR TMONSTER"horse_"

inherit ROOM;

#define PRICE ({ 0, 1500, 2000, 3000 })
#define HORSES ({ "none", "spot_horse", "red_horse", "whitefoot_horse" })
#define AMOUNT ({ 0, 4, 2, 2 })

void create()
{
	::create();
	set_short( "馬市" );
	set_long(
	"這裡是一塊小小的空地，人們的吆喝聲此起彼落，間或夾雜著馬匹\n"
	"的長嘯聲，這裡就是梁山泊內最大的馬市，由皇甫端所出資開設。\n"
	"馬匹的腥□氣和人們汗水的氣味混雜在一起，卻成了另一種充滿生。\n"
	"命力的氣息。在空地中央，貼了一張告示(note)。\n"
	);
	set( "light",1 );
        set_outside("eastland");
        set( "exits", ([
                "west"  : TROOM"path1",    
        ]) );
        set( "objects",([
             "boss" : TMONSTER"huanpo"
             ]));
        set("item_func",(["note": "note_msg", ]));
        set( "amount", AMOUNT );
        reset();
}

void init()
{
        add_action( "buy_horse", "buy");
        add_action( "sell_horse", "sell");
}

int note_msg()
{
	int *amount;
	amount = this_object()->query("amount");

write(
"這張告示上寫著：\n\n"
"    本店提供各類馬匹，價錢公道，童叟無欺，以下為現有的馬種\n\n"
"     馬種:                    價格:\n\n"
"   小花馬  (spot_horse)     "+PRICE[1]+" 銀幣    只剩 "+amount[1]+" 只  \n"
"  紅鬃烈馬  (red_horse)     "+PRICE[2]+" 銀幣    只剩 "+amount[2]+" 只  \n"
"  踏雪烏騅(whitefoot_horse) "+PRICE[3]+" 銀幣    只剩 "+amount[3]+" 只  \n\n"
"         　　　　　ps 凡本店賣出的馬匹，若不滿意，本店可以半價購回\n"                                      
	);
	return 1;
}


int sell_horse(string arg)
{
 	object horse;
 	int i=0, *amount;
 	if( !arg || arg != "horse" ) {
 		return notify_fail("指令格式 : sell horse (如果你有).\n");
 		                     }
 	horse = this_player()->query_temp("now_mount");
	if( !horse )                 
		return notify_fail("老闆說道:你有在這買馬嗎?\n");
	if( !present(horse, this_object())	) {
		tell_object( this_player(),
            "老闆說道: 沒錯，先讓我看看馬吧!\n" );
        return 1;
	}

	switch( (string)horse->query("name") ) {
        case "spot_horse"  : i=1;  break;
        case "red_horse"  : i=2;  break;
        case "whitefoot_horse" : i=3;  break;
        default :
          tell_object( this_player(), 
            "老闆說道: 對不起，本店不收這種東西。\n" );
          return 1;
    }

	if( i<1 || i>3 ) return 0;
	
    this_player()->credit("silver", PRICE[i]/2);
    this_player()->set_temp("now_mount", 0);
    horse->remove();
    amount = this_object()->query("amount");
    amount[i]++;
    this_object()->set("amount", amount);
    tell_object(this_player(), 
        "你賣掉你的馬，得到 "+(PRICE[i]/2)+" 塊銀幣。\n"
		);
    return 1;
}

int buy_horse(string arg)
{
	object horse;
	int i=0, *amount;

	if( !arg || arg == "" )
		return notify_fail("指令格式 : buy + <馬的名稱>.\n");
	
	if( this_player()->query_temp("now_mount") )
    	return notify_fail("老闆搖頭說道: 對不起, 一個人只能買一匹馬。\n");
          
	amount = this_object()->query("amount");
	if( !amount )
		return notify_fail("老闆笑道: 對不起, 本店所有的馬都已賣完了。\n");
          
	switch (arg) {
        case "spot_horse"  : i=1;  break;
        case "red_horse"  : i=2;  break;
        case "whitefoot_horse" : i=3;  break;
        default :
          tell_object( this_player(), 
            "老闆說道: 對不起，本店沒有賣 "+arg+" 這種馬。\n" );
          return 1;
          break;
    }
    if( i<1 || 1>3 ) return 0;
    if( amount[i] < 1 ) {
    	tell_object( this_player(), 
          "老闆說道: 對不起，本店 "+arg+" 這種馬已經賣完了。\n" );
        return 1;
    }
    
    if( !this_player()->debit("silver",PRICE[i] ) )
        return notify_fail("你沒有那麼多銀幣。\n");

	amount[i]--;
	this_object()->set("amount", amount);
    horse = new( HORSEDIR+HORSES[i] );
    horse->move( this_object() );
    
      this_player()->set_temp("now_mount", horse);
      horse->set_master( this_player() );

    tell_object(this_player(), 
        "老闆牽來一匹馬，邪惡地笑道：「下次記得再來喔 !!」邊說邊把□繩交給你\n");
    return 1;
}

void add_amount(string type)
{
	int i=0, *amount;
	
	if( !type || type == "" ) return;
	switch (type) {
        case "spot_horse"  : i=1;  break;
        case "red_horse"  : i=2;  break;
        case "whitefoot_horse" : i=3;  break;
        default : return;
    }
    if( i<1 || i>3 ) return;
    amount = this_object()->query("amount");
    amount[i]++;
    this_object()->set("amount", amount);
}

void reset()
{
	set("amount", AMOUNT );
	::reset();
}
int clean_up() { return 0; }
