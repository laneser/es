#include "/d/mage/mage.h"
 
#define TMP_FILE "/tmp/wall."+getoid(this_player())
#define WALL_FILE "/d/mage/data/wall.txt"
 
inherit ROOM;
 
 
 
int process();
 
void create()
{
	
	::create();
	
	set_short("魔法師公會名人堂");
	
	set_long(@TEXT
這裡是銀塔的地下室. 西面是一片塗鴉牆 (wall). 正前方立了幾個石碑. (slab)
北邊牆掛了個牌子 (sign). 地面上寫了幾個大字:
 
拉老大到此一遊!
 
 
TEXT
	);
	
	set("item_desc", ([
	"sign" : @SIGN

┌————————————————————————————————┐
│ 魔法師公會名人堂:                                              │
│ 0. 這裡現任的負責人是boss                                      │
│ 1. 要立碑的請找我,並請說明理由(如你某項魔法第一個練到頂)       │
│ 2. 要在塗鴉牆寫字的: write wall                                │
└————————————————————————————————┘
 
底下有一行小字: Jdw 不要在這裡 med 啦..
SIGN
	,
	"slab" : @SLAB

                �   ┌————————┐
                �   │      boss      │
                �   │  (波波士士)    │
                �   │     �          │
                �   │      魔�       │
                �   │      法�       │
                �   │      公�       │
                �   │      會        │
                    │      第        │
                �   │      二        │
                �   │      人        │
                    │不準告我濫用職權│
                �   └————————┘
 
SLAB
,
    "wall" : "@@read_wall",
	]) );
	set("exits", ([
 
	"up" : MAGE"mage_guild",
	"down" : MAGE"storage",
 
	]) );
 
	set("pre_exit_func", ([
	"down" : "to_go_down",
	]) );
 
//	set("objects", ([
//	"worker" : MAGE"npc/worker",
//	]);
}
 
void init()
{
	add_action("write_wall","write");
//	if ((string)this_player()->query("name") == "karrimor") {
//		add_action("settitle","title");
//	}
}
/*
int settitle(string str)
{
	if (!str) return notify_fail("Syntax: title <title to set>\n");
this_player()->set("title",str+" "+(string)this_player()->query("c_name"));
	return 1;
}
*/ 
int write_wall(string str)
{
	if (!str) return notify_fail("你要寫那裡啊?\n");
	if (str != "wall") return notify_fail("不要亂畫喔... \n");
    write("開始輸入文字....\n");
	this_player()->edit(TMP_FILE, "process", this_object());
	return 1;
}
 
int process()
{
	string text, title;
    seteuid(getuid());
    text = read_file(TMP_FILE);
    rm(TMP_FILE);
    title = (string)this_player()->query("c_name")+" 於 "+
        "/adm/daemons/weather_d"->query_c_game_time()+" 寫下:\n";
    write_file(WALL_FILE, title+text+"\n");
    write("Ok.\n");
	return 1;
}
 
string read_wall()
{
	this_player()->more(WALL_FILE);
	return "\n";
}
 
int to_go_down()
{
	if (wizardp(this_player()) || (this_player()->query_level() >= 
10) ) 
		return 0;
	tell_object( this_player(), "一道魔法力場擋住了你的去路\n");
	return 1;
}

