#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(14);
    set_name("Zhan Shung","張順");
    add("id",({"zhan","shung"}) );
    set_short("張順");
	set_long(@C_LONG
外號浪裡白條，江州人，渾身雪練也似一般白肉，深通水性，水底下伏得七日
七夜，水□行起就如一根白條，又兼精通武藝，為梁山四寨水軍大統領。
C_LONG
	);
    set("alignment",100);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "個" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",20);
    set_perm_stat( "int",18);
    set_perm_stat( "karma",22);
    set_skill("dagger",60);	
    set_skill("dodge",70);
    set ("max_hp",400);
    set ("hit_points",400);
    set ("time_to_heal",5);
    set ("wealth", ([ "gold":180]) );
    set_natural_weapon(25,13,25);
	set_natural_armor(35,20);
	set ("aim_difficulty",([ "weakest":40,"vascular":30]) );
	set("special_defense", (["magic":30,"none":10]) );
    set ("weight", 400);
    set ("inquiry",([
         "fish" : "@@ask_fish",
         "whirl" : "@@ask_whirl"
         ]));
    equip_armor(TARMOR"fish_skin");
    wield_weapon(TWEAPON"waterdagger");
    equip_armor(TARMOR"hat");
}
void ask_fish()
{
if (!(this_player()->query_temp("fat_quest/fish")) || (int)this_player()->query_temp("fat_quest/fish")<1) {
write(
"張順說道: 要魚，湖裡多的是，自己不會去抓呀?\n");
return 0;
}
else write(
"張順說道: 是吳用先生叫你來的嗎? 剛才吳用先生派來一個使者，把事情都告訴了我。\n"
"以後每天我們都會送一籃新鮮的魚蝦過去，相信對肥東應該有些幫助。\n");
call_out("suggest_diet",5,this_player());
return 0;
}
int suggest_diet()
{
write(
"當你轉身欲行，張順突然叫住了你，並且說道: \n"
"關於這件事，我有別的建議，據我的手下所言: 他們不去吃的原因，除了沒有\n"
"肉之外，肥東的廚房非常的不衛生，這也是一個重要的原因。\n\n"
"聽了張順的話，你覺得，除了找到肉以外，設法維持廚房的清潔也是很重要的\n"
"但是肥東根本不能打掃，難不成要帶他去減肥(diet)嗎?\n");
this_player()->set_temp("fat_quest/fish",2);
return 0;
}
void ask_whirl()
{
write(
"張順說道: 湖邊的漁民們有一個傳說，在湖的最深處住著一隻千年的大河蚌\n"
"當它在用水管吸水時，就產生了湖中的漩渦，詳情是如何我也不清楚....\n");
return 0;
}
