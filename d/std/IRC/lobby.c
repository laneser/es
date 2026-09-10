#include <irc.h>
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
進入ES。左邊牆上有一個佈告欄(board), 上面貼了一張告示。右邊
牆角有張展示櫃(closet), □面放著1996 mud workshop 的紀念品。
C_LONG
    );
    set("c_item_desc", ([
     "closet": @C_CLOSET 
     這個展示櫃□放了個1996 mud workshop, ES 提供的虛擬紀念品 -- 精美可
     儲存胸章(amulet) 一個, 聽說只要參加 workshop 的ES玩家, 就可以獲贈
     一枚。
C_CLOSET,

	"amulet":@C_AMULET
	這是1996 M.U.D. workshop 上送的虛擬紀念品, 上面有個漂亮的
	勇者鬥惡龍Mark。上面共有三個小按鈕, 分別標示著(help), (login),
	以及 (check), 如果你不清楚它們的功用, 建議你先按(press) help
	按鍵看看。
C_AMULET,	  

    	"board" : @C_BOARD
    	
    	這張告示上面寫著:
	   1996 第一屆網路虛擬社區研討會紀念品獲贈名單:
	        bonbon, iop, jauyn, law, luna, lwz, moii, nausca, qer, 
	        shxteater, spice, trash, tutu, yoyo
    	        (按字典順序排列)
    	         
        PS   ES 快速進入秘技持續公開中: 默唸IRIS好帥1000次, 心誠則靈
        PS2  list 這個指令能讓你知道現在所處的順位.
        PS3  連續指令愛用者自己小心, 凡因此在這被Immortal zap 自行負責
C_BOARD,


]) );                                    
}
 
void init()
{
     add_action("do_list","list") ;
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

int sort_pio(object A,object B)
   { int aa,bb ;
     aa = A->query_temp("chat_user");
     bb = B->query_temp("chat_user");
   return  aa - bb ; }

int do_list()
{
    int piority ;
    object *usr,*tmp ;
    usr = all_inventory(this_object()) ;
    piority = member_array(this_player(),sort_array(usr,"sort_pio")) ;
    if(piority) write("你現在的順位是第"+chinese_number(piority)+"號。\n") ;
    else ("你不是屬於這個聊天室的人\n") ;
    return 1;
}

	