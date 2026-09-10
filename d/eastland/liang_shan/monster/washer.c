#include "mudlib.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(6);
	set_name("Da", "阿達");
	add ("id", ({ "da", "Da" }) );
	set_short( "阿達");
	set_long(
		"瘦弱的少年，為了不知名的原因來此打工．\n"
		);
	set_perm_stat("str", 10);
	set_skill( "dodge", 30 );
	set( "max_hp", 120 );
	set( "hit_points", 120 );
	set( "gender", "male" );
	set( "race", "beholder" );
	set( "alignment", 20 );
	set_natural_armor( 10, 2 );
	set_natural_weapon( 10, 4, 10 );
        set( "chat_chance",5);  
        set("chat_output",({"阿達喃喃自語: 奶奶的病還沒好，怎麼辦??\n",
                            "少年阿達正拼了命的工作....\n"}));
        set( "inquiry", ([
              "sick" : "@@ask_sick",
              "grandmother" : "@@ask_grama",
              "fish" : "@@ask_fish"
              ]));
}
string c_call(object who)
{
	if ((string)who->query("gender") == "female")
	return (!who->query("spouse")) ? "姐姐" : "大娘" ;
	else
	return (!who->query("spouse")) ? "哥哥" : "大叔" ;
}
void ask_grama()
{
write (
"少年阿達嘆了一口氣，說道: 你認識我的奶奶嗎? 那你應該知道她\n"
"生病的事情吧?\n");
this_player()->set_temp("da_quest/ask",1);
return ;
}

void ask_sick()
{
if ((int)this_player()->query_temp("da_quest/ask")<1) {
write (
"少年阿達說道: 喔，這位" + c_call(this_player()) +"生病了嗎? 也許你可以找我們寨\n"
"中的第一神醫，安道全先生......\n");
return ;
}
write (
"少年阿達說道: 這位好心的" + c_call(this_player()) +"，我家就在大湖東的石碣村，家中人丁單薄\n"
"只有奶奶和我相依為命，但是兩三年前，她突然得了一種奇怪的病，我也曾請\n"
"寨中的第一神醫，安道全先生去看過，但仍然是無效，所以我現在在努力打工\n"
"賺錢，看能不能把奶奶帶去默爾斯國醫治....\n");
return ;
}
void ask_fish()
{
if ((int)this_player()->query_temp("da_quest/ask")<1) {
write (
"少年阿達說道: 喔，這位" + c_call(this_player()) +"，對不起，我正在工作\n"
);
return ;
}
write (
"少年阿達說道: 這位好心的" + c_call(this_player()) +"，您是要問我奶奶喜歡的魚吧?\n"
"我奶奶常說，以前這湖裡有一種黃金色的鯉魚，是她最喜歡的食物，不過，這幾年來\n"
"已經很少見到了....\n");
return ;
}
