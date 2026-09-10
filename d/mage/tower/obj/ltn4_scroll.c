//  Created by Yueh in Eastern Story 1995/11/10
#include <mudlib.h>
#define SLAB_FILE "/d/mage/data/slab.txt"
inherit OBJECT;
void create()
{
	set_name( "blue magic scroll", "藍色魔法卷軸" );
	add( "id", ({ "scroll" }) );
	set_short( "藍色魔法卷軸" );
	set("long","@@desc");
	set( "unit", "張" );
	set( "weight", 5 );
	set( "no_sale", 1 );
}


void init()
{
        add_action( "recite_runes", "recite" );
}

int recite_runes(string arg)
{
        object env,me;
	me=this_player();
        if( !arg || arg!="runes" )
                return notify_fail("想吟誦什麼？\n");
        if ((this_player()->query_skill("runes")< 90))
                return notify_fail("你根本看不懂，想吟誦什麼？\n");
        if ((this_player()->query("spell_levels/black-magic")< 50))
                return notify_fail("你吟誦了半天，還是不知道正確的使用方式，大概是你對黑魔法還不夠熟練吧！\n");
if ((undefinedp (this_player()->query("spells/lightning"))) || (this_player()->query("spells/lightning")< 3))
return  notify_fail("你吟誦著咒文，但是以目前你的幻雷術等級不知道該如何使用！\n");

if ((this_player()->query("spells/ether-bolt")== 8)||(this_player()->query("spells/fireball")== 7))
return notify_fail("你已經學了其它高等攻擊魔法，無法在學了！\n");

if (this_player()->query("spells/lightning")== 4)
return notify_fail("你吟誦了咒文，對這個咒文記得更清楚了。\n");
	write("你開始吟誦卷軸上的咒文：拉·依古瑪·得拉哈坦....。\n\n");
	tell_room( environment(me), sprintf("%s對著卷軸開始喃喃自語。\n", me->query("c_name")), me);
	printf(set_color("卷軸發出了藍色的光芒，化作了幾百團的遊離的電氣，圍繞在你四周快速移動著，不時閃出電光.... \n ...\n ...\n", "HIB") );
	tell_room( environment(me), set_color(sprintf("\n%s手上的卷軸發出了藍色的光芒，化作了幾百團的電氣，圍繞在%s四周快速移動著，不時閃出電光.... \n",me->query("c_name"),me->query("c_name")),"HIB" ), me);

	call_out("effect",1,me);
        return 1;
}
void effect(object reciter)
{
string fame;
seteuid(getuid());
fame = "     "+(string)reciter->query("c_name")+"("+
                (string)reciter->query("name")+")"+" 於 "+
                "/adm/daemons/weather_d"->query_c_game_time()+" 習得幻雷術[4] !!\n";
                write_file(SLAB_FILE, fame+"\n");
	write("從觀察遊離電氣的移動，你領略出如何使用幻雷術[4]！！\n> ");
	tell_room( environment(reciter), sprintf(set_color("\n遊離的電氣愈來愈弱，漸漸的消失不見了.... \n\n> ", "HIB") ));
	this_player()->set("spells/lightning",4);
	remove();
}

string desc()
{
if ((this_player()->query_skill("runes")< 50))
return ("這張藍色卷軸上寫了一些你看不懂的奇怪文字。\n");
else
if ((this_player()->query_skill("runes")< 90))
return ("這張藍色卷軸上寫了一些魔法文字，但是你只看懂了一半，大概是你對魔法文字的認識還不夠吧。\n");
else
if ((undefinedp (this_player()->query("spells/lightning"))) || (this_player()->query("spells/lightning")< 3))
return ("這張藍色卷軸上面似乎記載著幻雷術的咒文，但是以目前你的幻雷術等級不知道該如何使用。\n");
else
if (this_player()->query("spells/lightning")== 4)
return("這張藍色卷軸上面記載著幻雷術第四級的咒文。\n");
else
return("依你對幻雷術的瞭解，上面記載著似乎是幻雷術的一種咒文，可是你以前從沒看過這些咒文，\n想試著吟誦(recite)這些咒文(runes)看看嗎？\n");
}

