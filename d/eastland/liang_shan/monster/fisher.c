#include "mudlib.h"
inherit MONSTER;

void create()
{
	::create() ;
	seteuid(getuid()) ;
	set_level(8);
	set_name("fisher", "釣客");
	add ("id", ({ "fisher", "fish" }) );
	set_short( "釣客");
	set_long(
		"這是一位專程來此釣魚的釣客，不過似乎成績並不理想...\n"
		);
	set_perm_stat("str", 12);
	set_skill( "dodge", 40 );
	set( "max_hp", 150 );
	set( "hit_points", 150 );
	set( "gender", "male" );
	set( "race", "human" );
	set( "alignment", 50 );
	set_natural_armor( 25, 5 );
	set_natural_weapon( 20, 6, 15 );
        set( "chat_chance",16);  
        set("chat_output",({"釣客把釣竿用力一扯，但是什麼都沒有...\n",
                            "釣客把釣竿拉起低頭重綁魚餌...\n",
                            "釣客說道: 今天真倒黴....\n",
                            "釣客不停的玩弄他的腳趾....\n"}));
        equip_armor("/d/eastland/liang_shan/obj/rod");
        equip_armor("/d/eastland/liang_shan/armor/hat");
        set( "inquiry", ([
              "fish" : "@@ask_fish"
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
write (
"這位釣客說道: " + c_call(this_player()) +"，這□有很多魚呦...\n");
return ;
}

