//#pragma save_binary

#include "/d/mage/mage.h"

inherit ROOM;

void create()
{
	object master;
	::create();
	set_short("The Magic Library", "魔法圖書館");
	set_long( @C_LONG_DESCRIPTION
這裡是摩亞達城最古老的魔法圖書館，各式各樣的魔法經典語法術卷軸被整齊
地收藏在好幾排三、四個人高的書架(bookrack)上，這裡目前是歸魔法師公會管理
，所有的魔法知識也都被分門別類放在幾個收藏室內，在你的東邊是收藏元素魔法
的圖書室，西邊是集黑魔法之大成的卷軸室，往北的房間主要是收集一些冷僻的魔
法書籍，中央的一道螺旋梯通往三樓的高級魔法能源研究室。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
	set( "no_monster", 1);
	set( "c_item_desc", ([ 
		"bookrack" : "十分老舊的木書架，放了一些殘破的卷軸(scroll)，上面滿是灰塵。\n" ,
		"scroll" : "@@look_scroll"]) );
	set( "exits", ([ 
		"north" : MAGE"misc_lib", 
		"west"  : MAGE"black_lib", 
		"down"  : MAGE"mage_guild", 
		"east"  : MAGE"element_lib",
		"south" : MAGE"spell_lab",
		 "up"   : MAGE"energy_lab", 
    ]) );
	master = new( "/d/mage/tower/monsters/patolas");
	master->move( this_object() );
	reset();
}

string look_scroll()
{
	if (!present("patolas") ) return "一些殘破不全的卷軸，上面寫些什麼已經無法辨認了。\n";
return(@DESC
一些殘破不全的卷軸，上面寫些什麼已經無法辨認了。

帕多拉斯嘆了口氣，說：公會里本來存有很多記載高等法術的卷軸，但是
有一次公會被入侵，魔法卷軸被掠奪一空，只留下這些殘破不堪的卷軸。
經過動員全魔法公會的成員多年來四處明察暗訪，終於查出其中一些卷軸
的下落。

	火球術[7] : 地精大長老歐瑞安。需元素魔法等級50以上方能使用。
	幻雷術[4] : 大國師孝光。需黑魔法等級50以上方能使用。
	以太之箭[8] : 精靈王。需黑魔法等級50以上方能使用。

因著某個不知名的原因，以上這三種攻擊魔法只能擇一學之。
   
	星空之門 : 矮人國王莫拉德五世。需雜項魔法等級50及探險度60%
		以上方能使用。
DESC
);
}

int clean_up() { return 0; }
