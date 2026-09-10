#include "saulin_temple.h"

inherit ROOM;

void create()
{
       ::create();
       set_short( "雨花院" );
       set_long( @C_LONG_DESC
你走到個小院不禁有些詫異，空湯湯的院裡居然沒有任何佛像，只正中
擺了塊七色彩石(stone)， 相傳昔日佛祖說法，說的頑石點頭天女散花
，天花墜地化為彩石，莫非就是這塊石頭？東方是普賢殿。
C_LONG_DESC
       );
       set("item_desc",([ "stone" : @C_LONG
你看著這塊石頭，它好像只是一塊普通的彩石嘛! 真不知道為什麼少林寺要鄭重
其事的把它供奉起來？
C_LONG
       ]));
       set("light", 1);
       set("exits",([
		"east" : SAULIN"pusan_temple",
		"west" : SAULIN"forest7",
       ]) );
       reset();
}

void init()
{
       add_action( "touch_stone", "touch" );
}

int touch_stone(string arg)
{
	if( !arg || arg !="stone" )
		return notify_fail("喂喂! 你不要到處亂摸啊!\n" );
	if( this_player()->query("quest/elephant") ) {
        tell_object( this_player(), @SHADOW_OUT
你把這塊石頭拿起來，用袖子使勁的擦，擦了老半天什麼事也沒發生，正感到
一陣失望？咦？等等，它的七彩花紋好像會動呢! 天啊! 這塊石頭是活的？你
不禁雙手發顫，不小心把石頭摔落在地，石頭應聲破裂，發出一股輕煙，強烈
的暈眩向你撲來，你想要奪門而逃已經來不及了。你暈了過去 !

你突然感到有人在搖你，睜開眼睛一看，原來是美麗可愛善良溫柔又有氣質的
茹比，她笑咪咪的解釋：對不起! 還在幫石頭整理內部。等到開放了再通知你
，好嗎 ？她拿出一把大棒子往你頭上一敲，你又暈過去了。
SHADOW_OUT
		);
	}
    else
		tell_object( this_player(), @SHADOW_OUT
你把這塊石頭拿起來，用袖子使勁的擦，擦了老半天什麼事也沒發生。
SHADOW_OUT
		);
	return 1;
}
