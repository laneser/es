// justice.c
// The justice of the peace of Farwind. 
// Nominally performs marriages, although the marriage code is in the
// courthouse and not in the monster.

#include <mudlib.h>

inherit MONSTER ;

int time=0;
void create ()
{
	::create() ;
	set_level(19);
	set_name("allynia", "艾裡妮雅");
	add ("id", ({ "justice", "judge" }) ) ;
	set_short("法官艾裡妮雅");
	set_long(
		"艾裡妮雅一生最大的嗜號就是為人主持婚禮。\n"
	);
	set ("no_attack", 1);
	set ("gender", "female");
	set ("race", "imp");
}

void init()
{
        ::init();
        add_action("wedding_word","wedding");
}

int wedding_word(string str)
{
	object ppl,ppl2;
	string who1,who2;
	int crazy;
	if ( !wizardp(this_player()) ) return 0;
        if( !str || sscanf( str, "%s to %s", who1, who2 ) != 2 )
                return notify_fail( "Syntax : wedding <boy> to <girl>" );

	if (!present(who1,environment()) || !present(who2,environment()) )
	return notify_fail( 
	      "法官搖搖頭：「 新郎或新娘不在這裡 !!」\n" );

	if ( time==0 )
	{
	tell_room( environment(), 
	"法官莊嚴地對著 "+capitalize(who1)+" 說道：「 "+capitalize(who1)+" !! 你願意一輩子照顧 "+capitalize(who2)+" ，\n"+
	"不論颳風下雨，reboot 或 crash ，天天拼命賺錢供 "+capitalize(who2)+" 揮霍，\n"+
	"並且儘自己所有的能力來愛護她，以使她快樂嗎？」\n" ,
        this_object() );
		time=1;
		crazy=0;
	return 1;
	}

        if ( time==1 )
        {
        tell_room( environment(), 
	"法官轉頭對著 "+capitalize(who2)+" 說道：「 "+capitalize(who2)+" !! 你真的願意成為 "+capitalize(who1)+" 的新娘，\n"+
	"承諾一生一世愛他、敬他、幫他花錢，不論 reboot 或 crash ，\n"+
	"天天伴在 "+capitalize(who1)+" 的身旁，直到昏倒在電腦前嗎？」\n" ,
        this_object() );
                time=2;
        return 1;
	}

        if ( time==2 )
        {
        tell_room( environment(), 
	"法官微笑地說道：「恭喜你們 !! "+capitalize(who1)+" 和 "+capitalize(who2)+" !!! \n"+
	"我宣佈你們成為正式的夫妻，請交換戒指，同時別忘了登記喔 !!」\n",
        this_object() );
                time=3;
        return 1;
	}

        if ( time==3 )
        {
        tell_room( environment(),
	"艾裡妮雅法官突然跳起來，拍手叫道：「 我要親新郎 !! 其他人排我後面 !!」\n"+
	"說著，不由分說的抱著 "+capitalize(who1)+" 猛親 ... 親 ...親 ...\n\n"+
	"你終於理解 ...... 這傢伙 ... 是個... 花痴 !!!! \n\n" ,
        this_object() );
                time=0;
	command("hold "+who1);
	command("kiss "+who1);
        command("lkiss "+who1);
        command("lkiss "+who1);
	command("lkiss "+who1);
        return 1;
	}

	return 0;
}
