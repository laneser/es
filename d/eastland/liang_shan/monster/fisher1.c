#include "mudlib.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(8);
	set_name("fisher", "魚夫");
	add ("id", ({ "fisher", "fish" }) );
	set_short( "魚夫");
	set_long(
		"這是一位石碣村土生土長的魚夫，有什麼事問他就對啦..\n"
		);
	set_perm_stat("str", 14);
	set_skill( "dodge", 60 );
	set( "max_hp", 180 );
	set( "hit_points", 180 );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 50 );
	set_natural_armor( 30, 5 );
	set_natural_weapon( 25, 10, 20 );
        set( "inquiry", ([
              "fish" : "@@ask_fish",
              "da" : "@@ask_da"
              ]));
}
string c_call(object who)
{
	if ((string)who->query("gender") == "female")
	return (!who->query("spouse")) ? "小姐" : "大娘" ;
	else
	return (!who->query("spouse")) ? "小哥" : "大哥" ;
}
void ask_fish()
{
        if (!(int)this_player()->query_temp("feed_fish")==1) {
write (
"這位魚夫說道: " + c_call(this_player()) +"，對不起，我要餵我的魚...\n");
return ;
}
write (
"這位魚夫說道: " + c_call(this_player()) +"，我養的這些魚，全都是從平臺上釣起\n"
"來的，您要有意思，也可以去試試看。對了，這裡的魚，非常\n"
"喜歡吃味道很重的爛魚爛蝦，否則很難釣的到。\n");
return ;
}
void ask_da()
{
        if ((int)this_player()->query_temp("da_quest/ask")<1) {
        write (
        "這位魚夫說道: " + c_call(this_player()) +"，對不起，達婆婆住對面..\n");
        return ;
        }
        write (
        "這位魚夫說道: " + c_call(this_player()) +"，你也知道達婆婆生病了吧.......\n"
        "我們也曾請來有名的神醫安道全來看病，他說: 達婆婆沒病，只是她一\n"
        "直以為身瘓絕症而吃不下飯，因而營養不良。如果能找到她最喜歡吃的\n"
        "給她補一補，很快就能恢復健康，問題是，誰知道她最喜歡吃什麼?\n");
        return ;
 }       
