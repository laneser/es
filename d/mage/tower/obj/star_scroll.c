//  Created by Yueh in Eastern Story 1995/11/10
#include <mudlib.h>
#include <daemons.h>
#define SLAB_FILE "/d/mage/data/slab.txt"
inherit OBJECT;

void create()
{
	set_name( "white magic scroll", "白色魔法卷軸" );
	add( "id", ({ "scroll" }) );
	set_short( "白色魔法卷軸" );
	set("long","@@desc");
	set( "unit", "張" );
	set( "weight", 5 );
	set( "no_sale", 1 );

}

void init()
{
        add_action( "study_scroll", "study" );
}

int study_scroll(string arg)
{
        object env,me;
	int points,total_points,percentage;
	me=this_player();
        if( !arg || arg!="scroll" )
                return notify_fail("想研究什麼？\n");
        if ((this_player()->query("spell_levels/misc")< 50))
                return notify_fail("這些星空圖好像記載了某種法術的秘密，但是你不知道正確的使用方式\n，大概是你對雜項魔法還不夠熟練吧！\n");
	points=(int)me->query_explore_points();
	total_points=EXPLORE_D->query_total_explore();
	percentage=points*100/total_points;
	if ( percentage < 60)
return  notify_fail("這些星空圖好像記載了某種法術的秘密，你研究了半天，還是不知道這些星空\n圖分別是從哪裡觀察的，大概你的探險度還不夠！\n");

if (!undefinedp(this_player()->query("spells/astral-gate")))
return notify_fail("你看看了星空圖，對這些星空的分佈記得更清楚了。\n");
	write("你開始仔細研究卷軸上的星空圖 .... \n\n");
	tell_room( environment(me), sprintf("%s看著卷軸開始發呆。\n", me->query("c_name")), me);
	printf("卷軸發出了白色的光芒，化作了幾百顆的白色星星的影像，圍繞著你快速的移動著.... \n ...\n ...\n");
	tell_room( environment(me),sprintf("\n%s手上的卷軸發出了白色的光芒，化作了幾百顆白色星星的影像，圍繞著%s快速的移動.... \n",me->query("c_name"),me->query("c_name")), me);

	call_out("effect",1,me);
        return 1;
}
void effect(object reciter)
{
string fame;
seteuid(getuid());
fame = "     "+(string)reciter->query("c_name")+"("+
                (string)reciter->query("name")+")"+" 於 "+
                "/adm/daemons/weather_d"->query_c_game_time()+" 習得星空之門 !!\n";
                write_file(SLAB_FILE, fame+"\n");
write("從觀察星星的分佈和移動，你領略出如何使用星空之門！！\n> ");
	tell_room( environment(reciter), sprintf("\n白色星星的影像愈來愈模糊，漸漸的消失不見了.... \n\n> " ));
	this_player()->set("spells/astral-gate",0);
	this_player()->set("spells/star-memory",0);
	remove();
}

string desc()
{
if (undefinedp(this_player()->query("spells/astral-gate")))
return("這張白色卷軸上面畫了很多的星空圖，想仔細研究(study)這個卷軸(scroll)嗎？\n");
else
return("這張白色卷軸上面畫著學習星空之門必知的各地星空圖。\n");
}

