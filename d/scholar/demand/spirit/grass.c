#include <mudlib.h>
#include <daemons.h>
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
string str1="你見到遠處一個綠色的精靈站在一根草上飛了過來，草精靈將一片藥草敷在你的傷口上，\n你覺的一陣刺痛，草精靈又隨著風飛走了。\n";
string str3="HIG";

void create()
{
	::create();
	set_level(4);
	set_name( "grass spirit", "草精靈" );
	add( "id", ({ "spirit" }) );
	set_short( "草精靈" );
	set_long(
		"一個有著修長的身軀，全身泛著淡綠色的精靈。\n"
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
        string str1="你見到遠處一個綠色的精靈站在一根草上飛了過來，草精靈將一片藥草敷在你的傷口上，\n你覺的一陣刺痛，草精靈又隨著風飛走了。\n";
        string str3="HIG";
        string str2="你見到"+me->query("c_name")+"神情專注的念著一些咒語，你見到遠處一個綠色的精靈站在一根草\n上飛了過來，草精靈將一片藥草敷在"+me->query("c_name")+"的傷口之後，又隨著風飛走了。\n";

 	seteuid(getuid());
	me->set_temp("summon_rest",1);
	this_object()->move(environment(me));
        tell_object(me,"草精靈對你說：沒問題...我馬上來幫你醫療!\n");
        me->receive_healing(6+random(2));
        END->bye_bye(me,this_object(),4,str1,str2,str3);
	return 1;
}
