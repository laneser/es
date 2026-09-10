// File: /d/noden/asterism/tower2-3.c

#include "asterism.h"

inherit ROOM;

void create()
{
	::create();
	set_short("矮人高塔的第三層");
	set_long(
		@C_LONG_DESCRIPTION
這裡是艾斯特律恩城中矮人高塔的第三層,一陣肅殺的氣氛籠罩與此地.這裡的防護
十分強大,除了有著守衛看守著之外,這高塔的每一層都用上了厚厚的鎖 .這裡在往上一
層就是矮人王阿萊特斯四世的住處了.一本厚厚的黑皮書(blackbook)被放置於一個空空
的書櫥(closet)上面.除此之外這裡就沒有任何其它有趣的東西了.
C_LONG_DESCRIPTION
	);

  	set( "light", 1 );
	set( "exits", ([ 
		"up" : ASTR"tower2-4",
		"down":ASTR"tower2-2",
		]) );
	set("c_item_desc",([
	    "blackbook":"你可以試著去讀它.\n",
	    "closet":"除了一本黑皮書外,並沒有甚麼東西放在上頭.\n",
	    ]) );	
//	set("objects",([
//	    "guard#1":MOB"dwarf_guard01",
//	    "guard#2":MOB"dwarf_guard01",
//	    ]) );
	reset();
}

void init()
{
     add_action("to_read","read");
}

int to_read(string str)
{
   if (!str||str!="blackbook") return 0;
   
   write(can_read_chinese()?
         "             --------阿萊特斯王朝的歷史:--------\n\n"
         " 一群精英武士騎著獅鷲獸,從死亡大地的深處飛出來,為了找尋理想的家園,\n"
         " 不辭辛勞地日夜奔波,而領導這群武士的就是阿萊特斯王.               \n"
         " 當這群武士來到了貝基爾山脈的時候,他們瞭解到要再找到像這樣的地方是\n"
         " 很困難的事了,於是他們就從獅鷲獸上走了下來.但是卻遇到了固執的地精.\n"
         " 地精,一群強烈排外的種族,他們並不歡迎矮人的到來.但是世事就是這麼的\n"
         " 的湊巧,一群半身人正好被魔族所追殺著而逃到了這裡,而半身人的族長與地\n"
         " 精長老有著深厚的交情,而且地精與魔族的大戰爭已經發生過兩次了,因此地\n"
         " 精,半身人與魔族展開了第三次地精魔族戰爭.前兩次地精以強力的神聖魔法\n"
         " 勉強的抵擋住邪惡的魔族,但是這次魔族有備而來,可怕的魔族大魔導士比裡\n"
         " 來爾司德思終於發現了抵抗神聖力量的方法,準備這次一舉消滅地精們,但是\n"
         " 魔族們沒有想到強力的戰士會出現,阿萊特斯的精英武士與地精半身人的魔法\n"
         " 師聯手之下,終於擊潰了魔族大軍,並把比裡來爾司德斯的靈魂給禁錮了起來.\n"
         " 這一次戰役後,矮人,地精,半身人簽下了和平共處協議,並建造了艾斯特律恩.\n":
         "ENGLISH MODE NEED TRASLATE.\n" );
   return 1;
}
