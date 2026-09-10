//#pragma save_binary

// _auction.c
// Command to auction an item .
// Created by Ruby@Eastern_Story, 6-11-94

#include <mudlib.h>

inherit DAEMON;
inherit COINVALUE ;
#define STOREROOM "/d/noden/farwind/auc_room.c"

int help()
{
        write(@HELP_TEXT
Syntax	: auction on/off
	打開/關掉拍賣廣播網
	: auction <something> for <price>
	拍賣身上的某一件物品。起價 price 枚銀幣。如果你定的起價太低，
	拍賣公司會替你定個好價格。
	: auction <price>
	出 <price> 枚銀幣搶標正在拍賣的拍賣品。

HELP_TEXT
);
        return 1;
}

object custom,buyer,auc_item;
int last_price,val;
int first = 1 ;
int auction_now = 0 ;

int check_auction()
{
	if (auction_now) {
//	if ( find_call_out("count_down") != -1 ) {
		write("對不起，正在拍賣物品中，請稍候 !!\n");
		return 0;
	}
	return 1;
}

int boardcast(string msg)
{
        object *usr;
        int i;

	usr = users();
        if( sizeof(usr) )
                for( i=sizeof(usr)-1; i >= 0; i-- ) {
			if (!usr[i]->query("seller_channel")) continue;
			usr[i]->quick_message(
				sprintf(set_color("[拍賣兔女郎] :","HIY",usr[i])+" %s \n",msg),usr[i]);
		}
        return 1;
}
int channel_on()
{
        this_player()->set("seller_channel",1);
        write(set_color("你的耳邊傳來一陣奇怪的聲音：歡迎收聽拍賣廣播網 ..\n","HIY",this_player()));
        return 1;
}
int channel_off()
{
        this_player()->delete("seller_channel");
	write(set_color("你扭扭你的耳朵，關掉拍賣廣播網的噪音 ..\n","HIY",this_player()));
        return 1;
}

void count_down(int timer, int price)
{
	if ( last_price > price ) { 
		price = last_price ;
		call_out("count_down",9,1,price);
		return ;
 	}

	if ( nullp(custom) ) {
		boardcast("哇 .. 賣方 Quit 了 .. 拍賣取消 ..");
		if ( !nullp(auc_item) )
			auc_item->delete("prevent_get");
		auction_now = 0;
		buyer = 0;
		return ;
	}

	if ( nullp(auc_item) ) {
                boardcast("哇 .. 拍賣品消失了 .. 拍賣取消 ..");
                auction_now = 0;
                buyer = 0;
                return ;
	}
	if ( timer<3 ) {
		boardcast(
//			  sprintf("%s標售的%s一件，第 %d 次喊價 %d 枚銀幣 !! 請出價 !!",
			  sprintf("%s一件，第 %d 次喊價 %d 枚銀幣 !! 請出價 !!",
//				  custom->query("c_name"),
				  auc_item->query("short"),
				  timer,price));

                call_out("count_down",8,timer+1,price);
		return ;
	}
	if ( buyer ) {
		if ((int)buyer->query("wealth/silver") > price ) {

			buyer->add("wealth/silver",-price);
//              boardcast(sprintf("%s一件 !! 以 %d 枚銀幣賣給%s，謝謝惠顧 !!",
                boardcast(sprintf("%s一件 !! 以 %d 枚銀幣賣出，謝謝惠顧 !!",
				  auc_item->query("short"),price,
//				  buyer->query("c_name")
				  ));
		if (custom) {				  
                	tell_object(custom,
			sprintf("你賣掉了你的%s，扣掉 50 %% 的拍賣差額，你得到了 %d 枚銀幣 !! \n",
				auc_item->query("c_name"),val + (price-val)/2));
                        custom->add("wealth/silver",val + ( price-val)/2);
		}
		tell_object(buyer,
			"一隻戴著茹比快遞公司帽子的陸行鳥飛奔過來，把一件東西丟在你面前，\n又「咻～～」的一聲跑掉了。\n");
		tell_room(environment(buyer),
			sprintf("一隻戴著某某快遞公司帽子的陸行鳥飛奔過來，把一件東西丟給%s，\n然後又飛也似的跑了。\n",buyer->query("c_name")),buyer);
		
		environment(auc_item)->add("money",(price-val)/2);
		auc_item->move(environment(buyer));

		} else {
		tell_object(buyer,"一個轟雷似的聲音在你的耳邊響起：你想欺騙偉大的拍賣公司嗎？給你一點教訓 !!\n");
                environment(auc_item)->add("money",(int)buyer->query("wealth/silver")-1);
		buyer->set("wealth/silver",0);
                if (custom ) {
                	tell_object(custom,
			"一隻戴著茹比快遞公司帽子的陸行鳥飛奔過來，把一件東西丟在你面前，\n又「咻～～」的一聲跑掉了。\n"
			"真倒黴，遇到一個沒錢的笨騙子，東西還在但是拍賣失敗了 !!\n");

                	tell_room(environment(custom),
			sprintf("一隻戴著某某快遞公司帽子的陸行鳥飛奔過來，把一件東西丟給%s，\n然後又飛也似的跑了。\n",custom->query("c_name")),custom);
                	auc_item->move(environment(custom));
		}
		
		}
		
	}
	else {
		boardcast(sprintf("%s才不過賣 %d 枚銀幣，居然沒人買，真是太可憐了 !!",auc_item->query("short"),price));
                tell_object(custom,"哈哈 !! 你太貪心了吧，不值錢的東西也 ...\n"
                        "一隻戴著茹比快遞公司帽子的陸行鳥飛奔過來，把一件東西丟在你面前，\n又「咻～～」的一聲跑掉了。\n");
                tell_room(environment(custom),
			sprintf("一隻戴著某某快遞公司帽子的陸行鳥飛奔過來，把一件東西丟給%s，\n然後又飛也似的跑了。\n",custom->query("c_name")),custom);
                auc_item->move(environment(custom));

	}
	auc_item->delete("prevent_get");
	auction_now = 0;
        first=1;
	buyer = 0;
	return ;
}

int cmd_auction(string str)
{
	string item,file;
	object ob1,room,*obs;
	int price1,bid_price,i;
	mixed *value ;

	if ( !room = find_object(STOREROOM) ) 
		room = new(STOREROOM);
	if (!str || !stringp (str)) return help();
	if (str == "on" ) return channel_on();

        if (str == "off" ) return channel_off();

        if (!this_player()->query("seller_channel"))
		return notify_fail("請先打開拍賣廣播網。\n");

	if ((sscanf(str,"%s for %d",item,price1) != 2) && 
	    (sscanf(str,"%d",bid_price) != 1)) return help();

	if ( item ) {
	if ( !(ob1=present (item,this_player()))) 
		return notify_fail("想買空賣空嗎？你根本沒有這件東西 !!\n");

    if ( find_call_out("count_down") != -1 ) 
    	return notify_fail("對不起，正在拍賣物品中，請稍候 !!\n");

	if ( (ob1->query("prevent_drop")) || (ob1->query("no_sale")) ||
		(ob1->query("prevent_insert")) )
		return notify_fail("對不起 !! 這種東西不能拍賣 !!\n");
/*
	if ( obs = deep_inventory(ob1) ) {
		for ( i = sizeof(obs)-1 ; i >=0; i-- )
			if ( obs[i]->query("no_sale") )
				return notify_fail("這裡面裝了不能拍賣的東西 !!\n");
	}
*/		
        if ( price1 < 1 ) return notify_fail("錢太多嗎？別鬧了 ^oo^ \n");
        custom = this_player();
        value = ob1->query("value");
    	if ( !value || !intp(value[0]) ) {
			return notify_fail("對不起 !! 這種東西不能拍賣 !!\n");
	}
	val = value[0] * coinvalue( value[1] ) / coinvalue("silver");
	price1 = ( val > price1 ? val : price1 ) ;
	last_price = price1 ;
	
	auc_item = ob1;
	ob1->move(room);
	ob1->set("prevent_get",1);
	auction_now = 1;
                tell_object(custom,
			"一隻戴著茹比快遞公司帽子的陸行鳥飛奔過來，把你的拍賣品搶走，\n又「咻～～」的一聲跑掉了。\n");
                tell_room(environment(custom),
			sprintf("一隻戴著某某快遞公司帽子的陸行鳥飛奔過來，搶走了%s的一件東西，\n然後又飛也似的跑了。\n",custom->query("c_name")),custom);

		boardcast(
//			sprintf("跳樓大拍賣 !! %s標售%s(%s)一件 !!\n起價 %d 枚銀幣 !! 有沒有人要出價的啊？",
			sprintf("跳樓大拍賣 !! %s(%s)一件 !!\n起價 %d 枚銀幣 !! 有沒有人要出價的啊？",
//			  custom->query("c_name"),
			  auc_item->query("short"),
			  auc_item->query("name"),
			  price1));

		call_out("count_down",9,1,price1);

	    return 1;
	}
	else if ( bid_price > 0 ) {

	if ( !auction_now )
		return notify_fail("你出價要買什麼？現在又沒有拍賣。\n");
	if (this_player() == custom ) 
		return notify_fail("喂 ! 是你在拍賣耶，想哄抬價格嗎？\n");
	if (this_player() == buyer )
		return notify_fail("你的價碼已經是最高價了 !!\n");
	if ( (int)this_player()->query("wealth/silver") < bid_price )
		return notify_fail("你身上的銀幣不夠 !!\n");
        if (first) {
	if ( bid_price <= last_price )
		return notify_fail("你出的價要高於底價喔 !!\n");
             first=0;
                   } else
	if ( bid_price < last_price+50 )
		return notify_fail("你出的價要高於現在的價格再加 50 枚銀幣喔 !!\n");
	buyer = this_player();
	if ( nullp(buyer) ) return 1;
	last_price = bid_price;
//	boardcast( sprintf("%s出價 %d 枚銀幣搶標%s !! 有沒有人要加價的？",
	boardcast( sprintf("有人出價 %d 枚銀幣搶標%s !! 有沒有人要加價的？",
//			   buyer->query("c_name"),
				bid_price,
			   	auc_item->query("short")));
	return 1;
	}
	else return help();
}


