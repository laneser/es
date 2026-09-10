#include <mudlib.h>

#define NEW_AMULET "/obj/amulet2.c"

inherit ARMOR;

int do_fast_in();
int do_check();
int do_help();

void create()
{
	seteuid( getuid() );
	set_name( "workshop amulet","泥巴研討會紀念胸章" );
	add("id",({"amulet"}));
	set_short( "泥巴研討會紀念胸章" );
	set_long(@Long
	這是1996 M.U.D. workshop 上送的虛擬紀念品, 上面有個漂亮的
勇者鬥惡龍Mark。上面共有三個小按鈕, 分別標示著(help), (login),
 以及 (check), 如果你不清楚它們的功用, 建議你先按(press) help 
 按鍵看看。
Long
	);
	set( "type", "misc" );
	set( "material", "cloth" );
	set( "weight", 7 );
	set( "armor_class", 0 );
	set( "defense_bonus", 4 );
	set( "prevent_drop",1);
	set( "prevent_get",1);
	set( "prevent_insert",1);
}

int query_auto_load()
{
	return 1;
}

void init()
{
	add_action("do_press","press");
}

int do_press(string arg)
{
	if (!arg) return notify_fail("你要按什麼?\n");
	if (arg == "login") do_fast_in();
	else if (arg == "check") do_check();
	else if (arg == "help") do_help();
	else return notify_fail("你要按什麼?\n");
	return 1;
}
int do_fast_in()
{
	object player;
	int fast_login;
	object new_amulet;
	
	player = this_player();
	
	if ( ! player->query_temp("chat_user") ) { 
		write("你又沒在大廳中, 耍寶啊??\n");
		return 1;
	}
	if (! ( fast_login=player->query("fast_login") ) ) fast_login=5;
	
	// move user to adv guild
	tell_room ( environment(player), player->query("c_name")+
			"伸手按下泥巴紀念胸章上的一個小按鈕, 你發現他的身影漸漸模糊, 終於消失了。\n",
			player);
	write ("你伸手按下泥巴紀念胸章上的一個小按鈕, 你的身影漸漸模糊...。\n");
	player->move_player("/d/adventurer/hall/adv_guild");
	write ("你的身影隨著一陣煙霧, 出現在冒險者公會中。\n");
	
	// delete temp attributes in lobby
     player->delete_temp("chat_user");
     player->delete_temp("be_sucked");
     player->delete_temp("be_clawed");
     player->delete_temp("be_hoofed");
     
     fast_login --;
     
     //still can use fast login....
     if (fast_login > 0) { 
     	player->set("fast_login",fast_login);
     }
     // can not use fast login anymore....
     else {
     	write ("你的泥巴紀念胸章能源已經耗盡, 再也不能幫你快速進入ES了:~\n");
     	player->delete("fast_login");
     	new_amulet = new(NEW_AMULET);
     	new_amulet->move(player);
     	this_object()->remove();
     }               				
     return 1;	
}		

int do_check()
{	
	object player;
	int fast_login;
	
	player = this_player();
	if (! (fast_login= this_player()->query("fast_login") ) ) {
		fast_login = 5;
		this_player()->set("fast_login",5);
	}	
	write ("你的泥巴紀念胸章還能幫助你快速進入ES " + fast_login +" 次。\n");
	return 1;
}

int do_help()
{
	write(@Help
這個泥巴研討會紀念胸章除了可以當做一般的防具使用外, 還可以幫助你
快速進入開放區域, 使用方法如下:
press check: 檢查紀念胸章中的能量還能幫助你login幾次。
press login: 立即進入 ES 開放區域。
當紀念胸章中的能量用完後, 胸章仍可當作一般的防具使用, 而且在quit
後不會消失。
Help
	);
}	