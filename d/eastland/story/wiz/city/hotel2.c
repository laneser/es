#include "../../story.h"

inherit ROOM;

void create()
{
	::create();
        set_short("旅館二樓");
	set("long",@LONG
這裡是旅館二樓，打掃得很乾淨，並且相當安靜。除了擺了一排排的床以外，
每個床旁邊的桌子上還有些茶水。大多數的人都躺在床上閉目養神，少數業已休息
完畢精神飽滿準備好行李等著要下樓，誰也不去打擾誰。
LONG
	);
	set("light", 1);
        set("exits",([
           "down" : SCITY"hotel1"
        ]) );
	reset();
}
