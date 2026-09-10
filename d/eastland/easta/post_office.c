// post_office.c
#include <mudlib.h>
#include <mailer.h>

inherit ROOM;

void create()
{
	::create();
	seteuid(getuid()) ;
	set_short("驛站");
	set_long(@C_LONG
你現在位於若嵐城的驛站。在這裡你可以寄信(mail)給其它不在線上的
人，若是有人寄信給你，也可以在這裡領取。在櫃檯旁邊的牆上有一張佈告
(sign)說明如何寄信收信。
C_LONG
	);
	set("light",1) ;
	set("exits", ([ "east" : "/d/eastland/easta/north_ealley" ]) ) ;
	set("pre_exit_func", ([ "east" : "dest_mailer" ]) ) ;
	set("item_func", ([ "sign" : "read_sign" ]) ) ;
}

void init()
{
	add_action("mail", "mail") ;
	add_action("help", "help");
	add_action("read_sign", "read") ;
        if( this_player() ) this_player()->set_explore( "eastland#7" );
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
"The sign on the wall reminds you that you can still send in a postcard\n"+
"saying whether you prefer the \"Old Buddha\" stamp or the \"Young Buddha\"\n"+
"stamp. It also says that you can type \"mail\" to read your mail, and you\n"+
"can type \"mail <name>\" to send mail to another player.\n") ;
	return 1 ;
}

int dest_mailer()
{
	object ob ;

	ob = present("mailer",this_player());
	if (ob) ob->remove() ;
	return 0 ;
}
