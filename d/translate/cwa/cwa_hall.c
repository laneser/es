#include <mudlib.h> 

inherit ROOM;

void create()
{
	::create();
	set_short("Color Wolf Association", "色狼協會" );
	set_long(
"You are in the great hall of Color Wolf Association.\n",
      "這□是色狼協會大廳, 你看到豬八戒親切地對你微笑. 但是千萬\n"
"不要想殺豬八戒來賺經驗點, 否則總有一天你會受到狼群圍攻, 死無葬\n"
"身之地!\n"
      "你可在這□加入色狼協會, 不過你最好先看看東邊牆上的說明公\n"
"告(sign)再說. 西邊的牆上則是一個英雄榜(list), 上面有所有色狼協\n"
"會成員的名單.\n"
	);
	set( "light",1 );
	set( "exits", ([
		"up" : "/u/s/supertramp/cwa/cwa_club"
	]) );
	set("pre_exit_func", ([
		"up" : "check_color"
	]) );
	set("item_desc", ([
		"sign" : @SIGN
===============================================================
===============================================================
SIGN
	])  );

	set("c_item_desc", ([
		"sign" : @C_SIGN
==============================================================
  色狼協會是諾頓大地歷史最悠久, 成員最多的組織. 它的會員們各
  各都具有超人的能力, 姣好的面孔, 天才的智商以及最重要的 - 
  超凡入聖的品德. 若你(你)亦具備了上述優良的特質, 現在就加入
  神聖的色狼協會吧!
==============================================================
C_SIGN
	])  );

	set("item_func",([
		"list" : "look_list"
	]));

	set("objects", ([
		"pig8" : "/u/s/supertramp/cwa/pig"  ]));
}

int look_list() {
	cat("/u/s/supertramp/cwa/memberlist.txt");
	return(1);
}

void init()
{
        add_action("join","join");
}

int join()
{
	if((int)this_player()->query("CWA")==1)
		return notify_fail(can_read_chinese()?
"你早已加入色狼協會了!\n" :
"You are already a member of CWA!\n");

	write(can_read_chinese()?
"你以為神聖的色狼協會是那麼好加入嗎? 別傻了!\n" +
"色狼協會會員們都是東方故事中的精英! 你認為你\n" +
"夠資格嗎? 如果你真的認為你自己行, 送封信給協\n" +
"會中的任何一位長老, 他們將盡快審定你的入會資\n" +
"格! 祝好運!" :     
"Do you think it's THAT EASY to join CWA? Don't be silly!\n" +
"Send a mail to the elders in CWA first, they will decide if\n" +
"you can join or not. Send them a mail NOW!\n");
	return(1);
} 


int check_color()  {
	if((int)this_player()->query("CWA")!=1)  {
		write(can_read_chinese()?
"\n\n\n豬八戒大聲喝道：慢著, 小子! 你以為你是誰? 你給我站住!\n\n\n\n"+
"你從驚嚇中回過神來, 但再也不敢冒犯豬八戒及任何色狼協會會員了\n" :
"\n\n\nThe evil pig shouts: Stop! Kid! Who do you think you are? FREEZE!\n\n\n\n"+
"You awake, but you are now afraid of the evil pig and CWA members very much!\n"); 
		return(1);
	}
	return(0);
}


