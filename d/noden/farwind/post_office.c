//#pragma save_binary

// post_office.c
// A room which allows access to Huthar's mailer.
// Written by Mobydick@TMI-2, 9-30-92
// Most of the code was taken from the _mail.c command, written by
// Huthar and Buddha.
// The room uses add_action() to define a mail command. If the player types
// that command, a clone of the portable mailer is give to him, and he
// enters the mailer. When he quits the mailer, it destructs itself: it
// also is destructed if he leaves the post office by going north, via
// the pre_exit_func property.

#include <mailer.h>
#include "farwind.h"

inherit ROOM;

void create()
{
	::create();
	seteuid(getuid()) ;
	set_short("郵局");
	set_long(@C_LONG
你現在位於遠風鎮的郵局。在這裡你可以寄信(mail)給其它不在線上的
人，若是有人寄信給你，也可以在這裡領取。在櫃檯旁邊的牆上有一張佈告
(sign)說明如何寄信收信。
C_LONG
	);
	set("light",1) ;
	set("exits", ([ "east" : FARWIND"smain2" ]) ) ;
	set("pre_exit_func", ([ "east" : "dest_mailer" ]) ) ;
	set("item_func", ([ "sign" : "read_sign" ]) ) ;
}

void init()
{
	add_action("mail", "mail") ;
	add_action("help", "help");
	add_action("read_sign", "read") ;
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
	write (
" “mail <name>” mail給你指定的人。\n"+
"  或鍵入“mail”後再按“？”看HELP \n") ;
	return 1 ;
}

int dest_mailer()
{
	object ob ;

	ob = present("mailer",this_player());
	if (ob) ob->remove() ;
	return 0 ;
}
