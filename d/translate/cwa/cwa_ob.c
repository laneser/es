
// Color Wolves Association object - wolf tail

#include <mudlib.h>
inherit OBJECT;
 
mapping levels = ([]); 

void create()
{
    seteuid(getuid());
    set_name( "wolf tail", "狼尾巴" );
    add( "id", ({ "tail", "cwa" }) );
    set_short( "wolf tail", "狼尾巴" );
	set_long(
"This is the symbol of membership to the C.W.A. - If you don't know what\n"+
"it means, you probably shouldn't have it.\n"+
"For information about the group, type <wolfinfo>.\n\n",
"這是色狼協會的信物. 如果你想知道相關資料, 請用 <wolfinfo>. \n\n",
    );
    set( "weight", 2 );
    set( "no_sell", 1 );
    set( "prevent_drop",1);
    set( "extra_look", "$N is a member of C.W.A.\n");
    set( "c_extra_look", "$N是色狼協會的一員\n");
    set( "unit", "條" );
}
 
void init()
{
	add_action("wolf_cmd","wolfinfo");
	add_action("wolves","wolves");
	add_action("rmall","rmall");
	add_action("bark", "bark");
	add_action("wtalk", "wtalk");
	add_action("enemies", "enemies");
}


int bark(string str)  {
	object dest;

	if(!str || str=="") {
		write(can_read_chinese()?
"你發出一陣狼嚎!  Woof! Woof!\n" :
"You bark like a wolf! Woof! Woof!\n");
		tell_room(environment(this_player()), ({
this_player()->query("cap_name")+" barks like a wolf! Woof! Woof!\n",
this_player()->query("c_cap_name")+"發出一陣令你膽顫心驚的狼嚎!\n" }),
		this_player());
		return 1;
	}
	if(!dest=present(str,environment(this_player())))
		return notify_fail(can_read_chinese()?
"你要對什麼東西叫?\n" : 
"What do you want to bark at?");
		
	write(can_read_chinese()?
"你對著"+dest->query("c_cap_name")+"嚎叫\n" :
"You bark at "+dest->query("cap_name"));

	tell_object(dest, can_read_chinese(dest)?
this_player()->query("c_cap_name")+
"對你發出一陣煽情的狼嚎, 你不自覺地被他吸引而忘記自己是誰\n" :
this_player()->query("cap_name")+" barks at you! You DO like him does this to you!\n");
	return(1);
}


int wtalk(string str)  {
	object *wolves_online;
	int i;

	if (!str || str=="") return notify_fail(can_read_chinese()?
"你想對其他狼們說啥?\n" : "What do you wanna tell other wolves?\n");

	wolves_online=filter_array(users(),"filter_wolf",this_object());
	wolves_online=sort_array(wolves_online,"sort_usrs",this_object());
	i = sizeof(wolves_online);

	if(i==1) return notify_fail(can_read_chinese()?
"現在只有你一匹狼在線上, 還是省省你的口水吧!\n" :
"You are the ONLY wolf on line now!\n");

	while(i--)  {
		message("wolf_line",sprintf(can_read_chinese(wolves_online[i])?
"[狼語] %s: %s\n":"[WOLF] %s: %s\n",this_player()->query(can_read_chinese(
wolves_online[i])? "c_cap_name":"cap_name"), str), wolves_online[i]);
	}
	return 1;
}


int wolves(string str) {
	object *wolves_online;
	string tail_cut;
	int i;

	if(str=="all") { cat("/u/s/supertramp/cwa/memberlist.txt");return(1); }

	wolves_online=filter_array(users(),"filter_wolf",this_object());
	wolves_online=sort_array(wolves_online,"sort_usrs",this_object());
	i=sizeof(wolves_online);
	if(i) {
		write(can_read_chinese()?
"目前共有 "+i+" 只色狼在色:\n" : 
"There are "+i+" color wolves on line:\n");
		write("========================\n");
		while(i--)  {
			tail_cut = wolves_online[i]->query_temp("tail_cut")? "*" : " ";
			printf("[%2d]%s%s\n",wolves_online[i]->query_level(),
tail_cut, wolves_online[i]->query(can_read_chinese()?"c_short":"short"));
		}
		write("========================\n");
	} else write(can_read_chinese()?
"現在現上一隻色狼也沒有!\n" :
"There is no color wolf on line now\n");
	return 1;
}


int enemies() {
	object *wka;
	int i;

	if(!wizardp(this_player())) return notify_fail(can_read_chinese()?
"只有色狼巫師才允許用這個指令.\n" : "Only colorwiz can use this command.\n");
	wka=filter_array(users(),"filter_wka",this_object());
	wka=sort_array(wka,"sort_usrs",this_object());
	i=sizeof(wka);
	if(i) {
		write(can_read_chinese()?
"現在有"+i+"個 WKA 烏合之眾上線\n" :
"There are "+i+" WKA member(s) on line.\n");
		write("========================\n");
		while(i--)  {
			printf("[%2d] %s\n", wka[i]->query_level(), 
wka[i]->query(can_read_chinese()? "c_short" : "short"));
		}
		write("========================\n");
	} else write(can_read_chinese()?
"狼威太大! WKA 不敢上線了!\n" :
"There is NO WKA member on line now!\n");
	return 1;
}


int sort_usrs(object u1, object u2)
{
	return (int)levels[u1]-(int)levels[u2];
}

int filter_wolf(object ausr)
{
	if ((int)ausr->query("CWA")==1 && visible(ausr,this_player()))
	{
		levels[ausr]=(int)ausr->query_level();
		if(!levels[ausr] || levels[ausr]==0) return 0;
		return 1;
	}
	return 0;
}


int filter_wka(object ausr)  {

	if((int)ausr->query("WKA")==1 && visible(ausr,this_player()))
	{
		levels[ausr]=(int)ausr->query_level();
		if(!levels[ausr] || levels[ausr]==0) return 0;
		return 1;
	}
	return 0;
}

 
int wolf_cmd(string str)
{
	switch(str) {
		case "organize" :
			this_player()->more("/u/s/supertramp/cwa/organize.txt",0,1);
			break;
		case "brief" :
			this_player()->more("/u/s/supertramp/cwa/brief.txt",0,1);
			break;
		case "commands" :
			this_player()->more("/u/s/supertramp/cwa/commands.txt",0,1);
			break;
		case "rules" :
			this_player()->more("/u/s/supertramp/cwa/rules.txt",0,1);
			break;
		default :
			this_player()->more("/u/s/supertramp/cwa/info.txt",0,1);
	}
        return 1;
}


int rmall(string str)  {
	string cap_name, c_cap_name;
	object dest;

	cap_name=(string)this_player()->query("cap_name");
	c_cap_name=(string)this_player()->query("c_cap_name");

	if (!str || str =="")
	{
		write(can_read_chinese()?
"你在大庭廣眾之下脫光衣服! 好一隻色狼!\n" :
"You take off your all clothes.\n");

		tell_room(environment(this_player()), ({
this_player()->query("cap_name")+" takes off all clothes in front of you!\n",
c_cap_name+"在你面前脫光所有衣服, 你受到驚嚇似地把臉別向一邊,\n"+
"但是你的兩顆眼珠仍貪婪地停留在"+c_cap_name+"的身體上. 你一方\n"+
"面懊惱自己為何如此不爭氣, 另一方面卻不禁讚歎著：他果然有脫的本錢！\n"
		}), this_player());
		return 1;
	}
	if(!dest=present(str,environment(this_player())))
		return notify_fail(can_read_chinese()?
"對誰脫衣服?\n" :
"To whom you wanna take off the clothes?\n");
	
	if(!living(dest) || (int)dest->query("npc"))
		return notify_fail(can_read_chinese()?
"你在對牛彈琴嗎?\n" :
"Oops! You must have a SPECIAL taste!\n");

	write(can_read_chinese()?
"你對"+dest->query("c_cap_name")+"脫光衣服!\n" :
"You take off all clothes before "+dest->query("cap_name"));
	tell_object(dest, can_read_chinese(dest)?
c_cap_name+"對著你把所有衣服脫光, 你看了以後不禁深深地愛上了"+c_cap_name+".\n":
cap_name+" remove all clothes in front of you. You fall in love with him after you saw his body!\n");
	return(1);
}


int cut() {
	object ob, owner;

	owner = environment(this_object());
	ob = new("/u/s/supertramp/cwa/half_tail");
	ob->move(owner);
	owner->set_temp("tail_cut",1);
	owner->set_temp("cutter",this_player()->query("cap_name"));
	owner->set_temp("c_cutter",this_player()->query("c_cap_name"));
	this_object()->remove();
}


int query_auto_load() { return(1); }


