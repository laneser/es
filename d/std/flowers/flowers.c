#include <mudlib.h>
#include <stats.h>
#include <conditions.h>
inherit OBJECT;
int bee_out=0;
void create()
{
        set_name("amazing flower", "奇異之花");
        add ("id",({ "flower"}));
        set_short("奇異之花");
        set_long(
                 "這是一朵具有七彩花瓣的花。\n"
                 "它的花語是：沒有不可能的事。\n"
                 "這朵花上還系著一張小卡片。\n");
        set("unit", "朵");
        set( "weight", 1 );
        set ("value", ({ 10, "silver" }) );
        set("message","BLANK");
	set("no_sale",1);
	set("c_smell","一陣沁鼻的馨香直透入你的心房，令你感覺精神振奮全身舒坦。");

}
void init()
{
	add_action("write_msg","write");
	add_action("read_msg","read");
	add_action("look_card","look");
	add_action("smell_me","smell");
}
string get_c_sex(object who)
{
	string sex;
	sex=who->query("gender");
	if (sex=="male")
	  return "他的"; 
        if (sex=="female")
          return "她的";
	return "它的" ;
}
int look_card(string arg)
{
	if (arg !="card")
	return 0;

	write(
		"這是一張飄著清新花香的潔白小卡片，它可以為人們傳送更直接的心意。\n"
		"你可以試著讀它或寫些什麼。\n" );
	return 1;
}
int write_msg(string arg)
{
	string msg,item;
	object target;
	if ( !arg || arg=="" || sscanf(arg,"%s on %s",msg,item) != 2) 
	  return notify_fail(
			"要寫些什麼呢？ Syntax : write <message> on <flower>.\n" );
	target = present(item, this_player());
	if(!target)
		return notify_fail("你沒有這種花....。\n");
	
	if ((string)target->query("message") != "BLANK")
          return notify_fail(
			"這張卡片上已經寫上字了，嗯 !! 擦不掉 !! 換一張吧 !!\n" );
	target->set("message",msg);
	write("你在"+(string)target->query("c_cap_name")+"的卡片上寫道："+msg+"\n" );
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"背對著你，在"+get_c_sex(this_player())+"花卡上塗塗抹抹。\n",
		this_player() );
	
	return 1;
}

int read_msg(string arg)
{
	string msg;
	object target;
        if ( !arg || arg=="")
          return notify_fail(
			"要讀什麼呢？ Syntax : read <flower>\n" );
        target = present(arg, this_player());
        if(!target)
                return notify_fail("你沒有這種花....。\n");

	msg=target->query("message");
        if ( !msg || msg=="BLANK" )
          return notify_fail(
		(string)target->query("c_cap_name")+"上系著一張空白卡片，上面什麼都沒寫。\n" );

	write(target->query("c_cap_name")+"的卡片上寫著 ： "+msg+"\n" );
        tell_room( environment(this_player()), 
		this_player()->query("c_name")+"背對著你，專心的讀著"+get_c_sex(this_player())+"花卡。\n",
                this_player() );
	return 1;
}
int smell_me(string arg)
{
	string msg,c_msg;
        object target;
        if ( !arg || arg=="")
          return notify_fail(
		"要聞什麼呢？ Syntax : smell <flower>\n" );
        target = present(arg, this_player());
        if(!target)
                return notify_fail("你沒有這種花....。\n");

        c_msg=target->query("c_smell");
	msg  =target->query("smell");
	write("你把你的"+target->query("c_cap_name")+"湊近鼻端，"+c_msg+"\n" );
        tell_room( environment(this_player()), 
		this_player()->query("c_name")+"輕輕的聞著"+get_c_sex(this_player())+target->query("c_cap_name")+"。\n",
                this_player() );

	if (random(20)==10 && !bee_out)
	{
	write("突然一隻蜜蜂從花裡飛出來，在你的鼻子上螫了一下，哇 !! 好痛 !! 鼻子腫起來了 !!\n" );
	this_player()->receive_damage(5);
       (CONDITION_PREFIX + "simple_poison")->apply_effect( this_player(), 5, 3 );
        tell_room( environment(this_player()), 
		"突然，一隻蜜蜂從"+this_player()->query("c_name")+"的花裡飛出來，在"+get_c_sex(this_player())+"鼻子上螫了一下，"+get_c_sex(this_player())+"鼻子馬上腫了起來 !! \n",
                this_player() );
		bee_out=1;
	}
        return 1;
}
