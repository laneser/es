// entrance 0

#include "../lilia.h"

inherit ROOM;

void create()
{
    ::create();
    set_short("米達爾墓穴");
    set_long(@C_LONG
你現在在一個黑暗潮溼的洞穴裡，不過奇怪的是雖然這裡瀰漫著很重的溼
氣，牆壁上卻是一點青苔也沒有。處於這個陰森森的洞穴裡，你不由得打了個
機伶伶的冷戰 .... 你覺得還是趕快離開這個鬼地方比較好。
C_LONG
    );
    set("item_desc", ([
	"face" : "這石像的臉雕刻的很是精美，你不禁想摸摸它 ....\n",
	"statue" : "這石像雕刻的很是精緻，看起來倒有點兒像魔族。\n",
	"wall" : "西邊的牆上似乎嵌著一尊石像，不過你看不清楚它的臉。\n",
	"board" : @BB
告示牌上面寫著：

	這是一個全新的區域，包含了一個非常高難度的任務。由於這個區域
    曾經困住過不少的巫師，所以如果你找不到這個房間的出路的話，請鍵入
     pray 這個命令，萬能的天神會把你送到安全的地方去。

	這個任務會在你完成一個階段之後予以儲存，在第三階段之後由於和
    黑無常簽下贊助合約，所以如果不小心的話，可能會直接回遠風鎮露天英
    雄館去，希望你能留意。加油吧！努力去完成任務！ 

				調教師  女王 (Lilia) 
BB
	]) );
    reset();
}

void init()
{
    add_action("to_touch", "touch");
    add_action("to_search", "search");
    add_action("to_pray", "pray");
}

int to_touch(string str)
{
    object p;
    p = this_player();

    if (str == "face")
    {
	tell_object(p, "石像的眼睛突然發出了一陣異樣的光芒籠罩著你，你發現自己被傳送到別的地方!\n");
	if (p->query(QUESTNAME) >= 1)
	    p->move_player(AREA"rose0", ({"%s被一陣詭異的光芒傳送走了!\n", "%s伴隨著一陣光芒出現在這裡。\n"}), "" );
	else
	{
	    p->set_temp("lilia_0", 1);
	    p->move_player(AREA"en1", ({"%s被一陣詭異的光芒傳送走了!\n", "%s伴隨著一陣光芒出現在這裡。\n"}), "" );
	}
	return 1;
    }
    else
	return notify_fail("你想摸什麼? 隨便亂摸是不好的行為哦 ....\n");
}

int to_search()
{
    write("牆角似乎掛著一塊告示牌 (board)。\n");
    return 1;
}

int to_pray()
{
    write("你跪下來祈禱 .... 祈禱些什麼好呢? ....\n");
    this_player()->move("/d/noden/nodania/sealroom");
    return 1;
}
