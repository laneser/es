#include "irc.h"
#define BOARD "/d/std/IRC/irc_board"
 
inherit ROOM;
 
void create()
{
	::create();
	set("light", 1);
    set_short( "Lobby","大廳" );
    set_long(
@C_LONG
這是一間陳設簡單的方形大廳. 許多人正席地而坐, 靜靜排隊等待
進入ES。左邊牆上有一個佈告欄(board), 上面貼了一張告示。
C_LONG
    );
    set("c_item_desc", ([
    	"board" : @C_BOARD
    	
    	這張告示上面寫著:
	
    	本實驗室將於今年七月十三日星期六於交大工程三館舉辦關於網路虛擬社會
    	的研討會, 歡迎踴躍參加。同時並公開徵求論文, 只要有關網路虛擬社會的
    	文章均歡迎投稿。稿件請寄新竹市交通大學資科所智慧型遠距教學實驗室或
    	email 至 workshop@cindy.cis.nctu.edu.tw。詳情請見各大 BBS Mud 版。
    	         
	P.S. ES 快速進入秘技持續公開中: 默唸IRIS好帥1000次, 心誠則靈

C_BOARD
]) );                                    
}
 
void init()
{
	add_action("do_kill","kill");
	add_action("do_auction","auction");
	add_action("do_drop","drop");
//      banish mage commands
	add_action("do_cast", "cast");
        add_action("do_meditate", "meditate");
//      banish thief commands
	add_action("do_backstab", "backstab");
	add_action("do_steal", "steal");
//      banish monk commands	
        add_action("do_exercise", "exercise");
        add_action("do_songin", "songin");
        add_action("do_eungon", "eungon");
//      banish scholar commands
	add_action("do_brood","brood");
        add_action("do_chutan","chutan"); 
        add_action("do_embattle","embattle");
        add_action("do_demand","demand");       
//      banish healer commands
	add_action("do_clot","clot");
	add_action("do_aid","aid");
	add_action("do_acupunct","acupunct");
//      banish adventurer commands
	add_action("do_hang","hang");
}

int do_drop()
{
	write("這□不準亂丟垃圾。\n");
	return 1;
}



int do_acupunct()
{
	write("這□不準針灸。\n");
	return 1;
}

int do_hang()
{
	write("這□不準絞殺。\n");
	return 1;
}



int do_aid()
{
	write("這□不準急救。\n");
	return 1;
}

int do_clot()
{
	write("這□不準止血。\n");
	return 1;
}

int do_demand()
{
	write("這□不準召喚。\n");
	return 1;
}


int do_embattle()
{
	write("這□不準結陣。\n");
	return 1;
}


int do_chutan()
{
	write("這□不準聚丹。\n");
	return 1;
}


int do_brood()
{
	write("這□不準打坐。\n");
	return 1;
}


int do_eungon()
{
	write("這□不準運功。\n");
	return 1;
}


int do_songin()
{
	write("這□不準誦經。\n");
	return 1;
}


int do_exercise()
{
	write("這□不準打坐。\n");
	return 1;
}

int do_meditate()
{
	write("這□不準冥思。\n");
	return 1;
}

int do_steal()
{
	write("這□不準偷竊。\n");
	return 1;
}


int do_backstab()
{
	write("這□不準背刺。\n");
	return 1;
}

int do_cast()
{
	write("這□不準施法。\n");
	return 1;
}

int do_auction()
{
	write("這□不準交易。\n");
	return 1;
}

int do_kill()
{
	write("這□不準械鬥。\n");
	return 1;
}	
	