#include <mudlib.h>

#define PETDIR "/d/noden/farwind/pet/pet_"

inherit ROOM;

#define PRICE ({ 0, 1500, 2000, 1400, 1400, 1800, 3500 })
#define PETS ({ "none", "cat", "dog", "bird", "rat", "pig", "dino" })
#define AMOUNT ({ 0, 4, 4, 5, 5, 3, 2, })
void create()
{
        ::create() ;
        set("light", 1) ;
        set_short( "茹比寵物專賣店" );
        set_long(@LONG
這裡是一家寵物店，一進門就聽到滿屋子的寵物叫聲，你可以隨意看看或跟
一些比較乖的寵物玩，如果真的很喜歡，你可以參考牆上的價目表(menu)再決定
要不要帶它回家，你可以在這裡買賣寵物，同時他們也會幫你找回(looking)失蹤
的寵物。
LONG
        );

        set("item_func",(["menu": "msg_menu", ]));
        set("exits", ([
            "south" : "/d/noden/farwind/bazz3",
        ]) );
        set( "amount", AMOUNT );
        reset();
}

void init()
{
		add_action( "call_pet", "looking");
        add_action( "buy_pet", "buy");
        add_action( "sell_pet", "sell");
}

int msg_menu()
{
	int *amount;
	amount = this_object()->query("amount");

write(
"牆上掛著一張可愛的寵物月曆，上面註明著每種寵物的特性和價錢 ：\n\n"
"                      茹比寵物專賣店\n"
"    ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n"
"    ＝  喵喵貓  (pet cat)     "+PRICE[1]+" 銀幣    還有 "+amount[1]+" 只  ＝\n"
"    ＝  大笨狗  (pet dog)     "+PRICE[2]+" 銀幣    還有 "+amount[2]+" 只  ＝\n"
"    ＝  精靈鳥  (pet bird)    "+PRICE[3]+" 銀幣    還有 "+amount[3]+" 只  ＝\n"
"    ＝  天竺鼠  (pet rat)     "+PRICE[4]+" 銀幣    還有 "+amount[4]+" 只  ＝\n"
"    ＝  迷你豬  (mini pig)    "+PRICE[5]+" 銀幣    還有 "+amount[5]+" 只  ＝\n"
"    ＝  小火龍  (mini dino)   "+PRICE[6]+" 銀幣    還有 "+amount[6]+" 只  ＝\n"
"    ＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝＝\n\n"+
"ＰＳ：本店以市價的一半收購您不要的寵物，請不要讓你的寵物走失。\n"
	);
	return 1;
}
int call_pet()
{
 	object ob;
 		
 	ob = this_player()->query_temp("now_pet");
	if( !ob )
		return notify_fail("店員搖搖頭說：你又沒有寵物.\n");
	if( present(ob, this_object())	) {
		tell_object( this_player(),
            "店員說道: 你的寵物已經在這裡, 不用去找了!\n" );
        return 1;
	}
	tell_object(this_player(),
		"店員拿出一把哨子，用力一吹，嗶～～的一大聲，差點沒把你的耳朵震聾 .\n"
		"突然你的寵物不知道從哪裡鑽了出來，在你的四周高興地跑來跑去。\n"
		);
	ob->move_player(this_object(),"SNEAK");	
	return 1;
}

int sell_pet(string arg)
{
 	object ob;
 	int i=0, *amount;
 	if( !arg || arg != "pet" )
 		return notify_fail("指令格式 : sell pet (如果你有).\n");
 		
 	ob = this_player()->query_temp("now_pet");
	if( !ob )
		return notify_fail("你沒有寵物.\n");
	if( !present(ob, this_object())	) {
		tell_object( this_player(),
            "店員說道: 對不起，你的寵物不在這裡, 快去把它找回來吧!\n" );
        return 1;
	}

	switch( (string)ob->query("pet_type") ) {
        case "cat"  : i=1;  break;
        case "dog"  : i=2;  break;
        case "bird" : i=3;  break;
        case "rat"  : i=4;  break;
        case "pig"  : i=5;  break;
        case "dino" : i=6;  break;
        default :
          tell_object( this_player(), 
            "店員說道: 對不起，本店不收購這種寵物。\n" );
          return 1;
    }

	if( i<1 || i>6 ) return 0;
	
    this_player()->credit("silver", PRICE[i]/2);
    this_player()->set_temp("now_pet", 0);
    ob->remove();
    amount = this_object()->query("amount");
    amount[i]++;
    this_object()->set("amount", amount);
    tell_object(this_player(), 
        "你賣掉你的寵物，得到 "+(PRICE[i]/2)+" 塊銀幣。\n"
		);
    return 1;
}

int buy_pet(string arg)
{
	object ob;
	int i=0, *amount;

	if( !arg || arg == "" )
		return notify_fail("指令格式 : buy <寵物名稱>.\n");
	
	if( this_player()->query_temp("now_pet") )
    	return notify_fail("對不起, 一個人只能有一隻寵物。\n");
          
	amount = this_object()->query("amount");
	if( !amount )
		return notify_fail("對不起, 本店所有的寵物都已賣完了。\n");
          
	switch (arg) {
        case "cat"  : i=1;  break;
        case "dog"  : i=2;  break;
        case "bird" : i=3;  break;
        case "rat"  : i=4;  break;
        case "pig"  : i=5;  break;
        case "dino" : i=6;  break;
        default :
          tell_object( this_player(), 
            "店員說道: 對不起，本店沒有賣 "+arg+" 這種寵物。\n" );
          return 1;
          break;
    }
    if( i<1 || 1>6 ) return 0;
    if( amount[i] < 1 ) {
    	tell_object( this_player(), 
          "店員說道: 對不起，本店 "+arg+" 這種寵物已經賣完了。\n" );
        return 1;
    }
    
    if( !this_player()->debit("silver",PRICE[i] ) )
        return notify_fail("你沒有那麼多銀幣。\n");

	amount[i]--;
	this_object()->set("amount", amount);
    ob = new( PETDIR+PETS[i] );
    ob->move( this_object() );
    
    this_player()->set_temp("now_pet", ob);
    ob->set_master( this_player() );

    tell_object(this_player(), 
        "店員把你的寵物交給你，笑道：「你要好好照顧它喔 !!」\n");
    return 1;
}

void add_amount(string type)
{
	int i=0, *amount;
	
	if( !type || type == "" ) return;
	switch (type) {
        case "cat"  : i=1;  break;
        case "dog"  : i=2;  break;
        case "bird" : i=3;  break;
        case "rat"  : i=4;  break;
        case "pig"  : i=5;  break;
        case "dino" : i=6;  break;
        default : return;
    }
    if( i<1 || i>6 ) return;
    amount = this_object()->query("amount");
    amount[i]++;
    this_object()->set("amount", amount);
}

void reset()
{
	set("amount", AMOUNT );
	::reset();
}
