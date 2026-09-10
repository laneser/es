#include <mudlib.h>
#include <daemons.h>
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
void create()
{
	::create();
	set_level(15);
	set_name( "moon spirit", "月光精靈" );
	add( "id", ({ "spirit" }) );
	set_short( "月光精靈" );
	set_long(
		"一個全身發出柔和的黃色光芒的精靈。\n"
	);
	set( "unit", "個" );
	set( "race", "elf" );
	set( "alignment",  800 );
	set( "max_hp", 5000 );
	set( "hit_points", 5000 );
	set_skill( "dodge", 50 );
}

int my_action(object me)
{
       string str1="你見到一道黃光從天空直射而至，月光精靈從中走了出來，突然月光精靈全身放出一片\n金色光芒籠罩著你，你感覺一陣溫暖，月光精靈又消失在黃光之中。\n";
       string str2="你見到"+me->query("c_name")+"神情專注的念著一些咒語，突然一道黃光從天空中直射而至，一隻\n月光精靈從中走了出來，你見到月光精靈突然全身放出一片金色光芒籠罩"+me->query("c_name")+"之後，\n又消失在黃光之中。\n";
       string str3="HIY";

        seteuid(getuid());
	me->set_temp("summon_rest",1);
	this_object()->move(environment(me));
        tell_object(me,"月光精靈對你說：沒問題...我馬上來幫你醫療!\n");
        me->receive_healing(15+random(15));
        END->bye_bye(me,this_object(),15,str1,str2,str3);
	return 1;
}
