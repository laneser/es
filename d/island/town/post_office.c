// post_office.c
#include "../island.h"
#include <mailer.h>

inherit ROOM;

void create()
{
	::create();
	seteuid(getuid()) ;
	set_short("民營郵局");
	set_long(@C_LONG
你現在位於映世村的郵局，因為這村落是位在中立區，所以郵局是當
地民營的；在這裡你可以寄信(mail)給其它不在線上的人，若是有人寄信
給你，也可以在這裡領取。在櫃檯旁邊的牆上有一張佈告(sign)說明如何
寄信收信。
C_LONG
	);
	set("light",1) ;
	set("exits", ([ "west" : ITOWN"town02" ]) ) ;
	set("pre_exit_func", ([ "west" : "dest_mailer" ]) ) ;
	set("item_func", ([ "sign" : "read_sign" ]) ) ;
}

void init()
{
	add_action("mail", "mail") ;
	add_action("help", "help");
	add_action("read_sign", "read") ;
        if( this_player() ) this_player()->set_explore( "eastland#8" );
}

int mail(string arg)
{
   object ob;

   seteuid("TEMP");

   ob = new(MAILER);
   ob->move(this_player());
   ob->start_mail(arg);
   return 1;
}

int help(string str)
{
    if (str == "mail") {
	this_player()->more(MAILER_LONG);
	return 1;
    } else return 0;
}

int read_sign (string str)
{
	if (str && str!="sign") return 0 ;
	write (@LONG
        如何收信，寄信：
        
        □ 收信 ： 鍵入 mail ，你將進入讀信的狀態 。 用 ? 可在
                   讀信狀態下，得到help。
        □ 寄信 ： 格式是 mail [ppl's id] 。
LONG
     ) ;
	return 1 ;
}

int dest_mailer()
{
	object ob ;

	ob = present("mailer",this_player());
	if (ob) ob->remove() ;
	return 0 ;
}
