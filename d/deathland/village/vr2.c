
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set("light",1);
  set_short("The church of dwarf village","矮人村落的教堂");
  set_long(@Long
一股祥和的氣氛籠罩著整個地方,教堂裡到處都是虔誠的信徒,矮人的信仰十分
虔誠,期望他們的大神能夠解救他們脫離苦海,因此在這裡又建造了這座雄偉的大教
堂.教堂內的擺設除了一座非常巨大的神像(statue)外,神像前有一個祭壇(altar),
此外數張長椅被整齊排列著,好讓信徒們能專心的祈禱(pray).
Long
);
set("exits",([
    "north":Deathland"/village/v41",
             ]));
set("c_item_desc",([
    "altar":@Altar
一個奇怪的祭壇,上面空無一物.
Altar
    ,"statue":@Statue
巨大的神像聳立在你的面前,似乎你曾經見過他,仔細想一想在小時候的惡夢之
中常常出現的大魔神就是這般模樣,他就是傳說中的惡神 Evil Yang.他的右手
拿著一把三叉戟 ( trident ) ,指向遙遠的西方.善神 Echo 所住的地方.
Statue
    ]) );
set("objects",([
    "believer#1":Monster"/believer",
    "believer#2":Monster"/believer",
    "priest":Monster"/archbishop",
             ]) );
::reset();
}

void init()
{
	add_action("do_pray","pray");
}
int do_pray()
{
	tell_object(this_player(),"你專心的向惡神 Yang 祈禱 ...\n");
	this_player()->save_me();
	"/adm/daemons/backup"->user_backup(this_player());
	return 1;
}
