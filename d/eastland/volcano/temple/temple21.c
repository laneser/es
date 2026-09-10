#include "../oldcat.h"

inherit ROOM;

int be_eated;
void create()
{
	::create();
    set_short("神殿起居室");
	set_long( 
@LONG_DESCRIPTION
這是一間神殿起居室，除了長老之外，在這個神殿□工作的所有人都睡在這兒，
你看到排的整整齊齊的石床(bed)，床上的被褥比你在"成Ｘ嶺"的表現好上一千倍，
你正覺的臉紅時，突然發現最靠角落的一張床好像還有人(man)在睡覺。
LONG_DESCRIPTION
	);
set( "exits", ([
     "west": OTEMP"temple14",
     ]) );
set("item_desc",([
    "bed":"@@look_bed",
    "man":"一個睡的很熟的人，偶而還會放個屁。\n",
    ]) );
reset();
}

string look_bed()
{
write("\n躺在床上那個人翻了個身子，嘴裡還說著夢話：我才不相信有黑龍寶盒勒。\n");
write("\n你有問題想問他，想叫他但又不好意思...............\n");
return "你想了想，決定還是叫(call)他起床。\n\n";
}

void init()
{
  add_action("do_call","call");
}

int do_call(string arg)
{
  if (!arg || (arg!="man" && arg!="人")) return 1;

  write("\n那個人把頭轉過去，很不耐煩的說：吵什麼吵，沒看到老子在睡覺嗎?\n");
  write("\n你不死心，又叫了一次，那個人還是不回頭......\n");
  write("你終於不耐煩的大叫：起床啦，沒看過壞人啊，再睡就把你的ＸＸ剪掉。\n");
  write("\n那人一聽，反而把頭縮在被子裡，好啦，我跟你講：村子的那口井，\n");
  write("有一天晚上我看到有一道光芒從那口井發出，不知道是不是我眼花了。\n");
  write("\n這就是我所知道的....大人有大量..讓我繼續睡吧...............\n");
  write("\n只見他翻了個身又打起鼾來了...\n");
  return 1;
}
