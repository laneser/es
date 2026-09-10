#include "ekravia.h"
inherit BASE_ROOM;

void	create()
{
	::create();
	set_light(1);
	set_short("迪諾旅店");
	set_long(
@CLong
你走進一家旅店, 迎面映入眼簾的是一張古舊的樟木櫃臺 (counter)
。一本厚厚的登記簿 (register) 被放在櫃檯上, 一張張的書頁由外面進
來的陣陣大風翻閱著。一張簡單的說明 (note) 被貼在櫃檯旁的一角, 上
面寫著一些關於住宿的說明。
    櫃檯的右側後方有一道木門, 周圍的石牆上面掛著幾個野獸的頭, 彷
佛訴說著旅館主人當年勇敢的事蹟。左右兩側各有一個迴廊, 左邊的迴廊
不時有些喧鬧聲傳來, 右邊的迴廊則充滿著一股寧靜的氣息。
CLong
);

	set("c_item_desc", ([
		"counter"	: @ITEM_COUNTER
這個櫃檯由厚實的樟木所組成, 上面沒有任何的雕飾, 給人一種穩重的感
覺。細看木頭表面的顏色, 你發覺這個不起眼的櫃檯可能已經有上百年之
久的歷史。
ITEM_COUNTER
		, "register"	: @ITEM_REGISTER
一本封皮已經相當古舊的冊子, 不過內頁是可換的, 整本冊子實在是厚重
得可以。上面應該寫著一些住宿的資料, 不過字跡潦草, 難以確認。
ITEM_REGISTER
		, "note"	: @ITEM_NOTE
我想你應該走近一點, 然後仔細讀讀 (read) 它。
ITEM_NOTE
		]) );

	set("exits", ([
		"east"		: HERE"maple_street3",
		"south"		: HERE"corridor1",
		"north"		: HERE"corridor2",
		]));
		
	set( "objects", ([
		"keeper"	: MOB"innkeeper"
	]) );
	reset();
}

void	init()
{
	::init();
	add_action( "read_note", "read");
	add_action( "do_sign", "sign");
	add_action( "do_buy", "buy");
}

int	read_note(string s)
{
	if (!s)	return 0;
	if (s=lower_case(s) != "note")	return 0;
	write( @NOTE_MSG
□住宿須知□
    如果你想住宿的話, 你必須在登記簿上籤下你的名字 (sign name on 
register)。 我會收走你的錢並給你一把鑰匙, 往北走上樓就可以走到你
的房間。在房間裡你可以休息 (rest) 或是睡覺(sleep) 以恢復體力, 覺
得休息夠了, 就離開房間, 否則別怪我動手把你攆出去。
    我們一晚的價格是 200 個銀幣, 另外還有優惠的銀卡出售, 3200 個
銀幣一張。如果你需要的話, 直接跟我買。 (buy silver card)
                                                        §迪諾§
NOTE_MSG
	);
	return 1;
}

int	do_buy(string s)
{
	if (!s)	return 0;
	switch (lower_case(s)) {
		case "silver card"	:
			if (!this_player()->debit( "silver", 3200))	
				return notify_fail( "你掏掏口袋, 發現錢不夠\n");
			clone_object(OBJ"silver_card")->move(this_player());
			printf("%s", "老闆收下錢, 給你一張銀色的卡片。\n");
			return 1;
		default	:
			return 0;
	}
}

int	do_sign(string s)
{
	if (!s)	return 0;
	switch (lower_case(s)) {
		case "name on register"	:
			if (!this_player()->debit( "silver", 200))	
				return notify_fail( "你掏掏口袋, 發現錢不夠\n");
			clone_object(OBJ"tavern_key")->move(this_player());
			printf("%s", "老闆收下錢, 給你一把小鑰匙。\n");
			return 1;
		default	:
			return 0;
	}
}
