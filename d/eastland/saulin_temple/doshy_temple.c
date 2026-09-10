//File: doshy_temple.c 兜率大士院

#include "saulin_temple.h"

inherit ROOM;

void create()
{

       ::create();
	   set("kissed",0);
       set_short("Doshy temple","兜率大士院" );
       set_long( @LONG_DESC
empty
LONG_DESC
                 ,@C_LONG_DESC
這裡是供奉普渡眾生的觀音大士的地方，不同於少林寺其他地方的是： 
不知道為什麼除了每日服事僧會來灑掃之外，這裡幾乎是人跡罕至。院內供
奉的一尊白玉觀音(statue)，執瓶揮柳似欲遍撒甘霖，寶像十分莊嚴中卻帶
了七分俏麗。門外是一片寂寂的樹林。
C_LONG_DESC
               );
       set( "light", 1 );
       set("exits",([
		"north" : SAULIN"forest1",
       ]) );
       reset();
       set("c_item_desc",([ "statue" : @C_LONG
你走上前去仔細端詳尊白玉觀音，突然眼睛一花，眼前竟然出現了一位
美貌少婦(woman),她對你妖媚的笑著，不停的用她那對勾魂懾魄的鳳眼
看著你，你感到一陣前所未有的心跳，忍不住想上前親親(kiss)她。
C_LONG
       ]));
}

void init()
{
	add_action( "kiss_woman", "kiss" );
}

int kiss_woman(string arg)
{
	if( !arg || arg !="woman" )
      return notify_fail(can_read_chinese() ?
    	"你變態啊 ! 親牆壁嗎？\n" :
		"kiss what ? You stupid nut ?\n" );
    if( this_object()->query("kissed") )
      tell_object(this_player(), can_read_chinese()?
        "那少婦大叫一聲轉身就逃：色狼啊! 色狼啊! 來人啊! 有人非禮啊 ～～\n"+
        "你頓時慌了手腳，轉身就跑，沒想到一頭撞在牆上，原來只是幻想。\n" :
        "The woman run away and scream : Help !! Colorwolf !\n"
      );
	else {
      tell_object(this_player(), can_read_chinese()? @SHADOW_OUT
你露出了色狼的嘴臉，衝上前去抱著那位少婦猛親。咦？怎麼毛毛的？難道這女
人長鬍子嗎？哇 ! 你定睛一看，懷裡抱的怎麼是一隻眯眯眼的狐狸？

狐狸嘻嘻一笑：哈哈 ! 我等你好久了 ! 狼先生 !! 讓我吸吸你的陽氣吧 !

SHADOW_OUT
   : "The fox shout to you : Oh ! come on baby ! I need your blood !!\n"
      );
      new( SAULIN_MONSTER"fox" )->move( this_object() );
      this_object()->set("kissed",1);
    }
    return 1;
}

void reset()
{
    ::reset();
    set("kissed",0);
}
