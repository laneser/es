// File: /d/eastland/goomay/mroad1.c
// create by : Ruby the little wizard from 5/6/1994

#include "goomay.h"
inherit ROOM;
string *c_msg = ({
"牆上塗滿了亂七八糟的字，你根本分不清楚到底在寫些什麼。\n",
"牆壁的左下角畫著一把小雨傘，傘下寫著段譽、王語嫣..\n",
"牆壁的最上面被人用指力刻著：飛天貓第三次大勝狐狸狗留念。\n",
});

void create()
{
	::create();
	set_short("青石板大道");
	set_long( @LONG_DESCRIPTION
你走在古梅鎮平坦的青石大道上，光潔的青石板顯示著這個城鎮的活力，
伴隨在你身邊的是小販的吆喝聲、馬車的轔轔聲還有偶而疾馳而過的駿馬，那
是一些想要成名的武林人物，古梅鎮的西風塵沙中，不知埋葬了多少年輕人的
夢想。街道向東西延伸而去，北方是聞名於世的武鬥大會場，但門口卻不在這
裡，在那堵高牆上被塗滿了亂七八糟的字。
LONG_DESCRIPTION
	);
        set("c_item_desc",(["wall":"@@look_wall"
                  ]));

        set_outside( "eastland" );
	set( "exits", ([ 
                "east" : Goomay"col24",
		"west" : Goomay"row25",
	]) );
        set( "objects", ([
                "woman1" : Mob"visitor",
                "woman2" : Mob"visitor",
        ]) );

	reset();
}

string look_wall()
{
	return c_msg[random(sizeof(c_msg))];
}
