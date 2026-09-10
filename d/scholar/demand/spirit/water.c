#include <mudlib.h>
#include <daemons.h>
#define END "/d/scholar/demand/spirit/end"
inherit MONSTER;
void create()
{
	::create();
	set_level(10);
	set_name( "water spirit", "水精靈" );
	add( "id", ({ "spirit" }) );
	set_short( "水精靈" );
	set_long(
		"一個全身藍色的精靈，頭上還有著一小朵烏雲。\n"
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
        string str1="你見到天空一朵烏雲飄來，水精靈從中飄了出來，水精靈用手觸摸你的傷口，你覺的一陣\n冰涼，水精靈又隨著烏雲飄走了。\n";
        string str2="你見到"+me->query("c_cap_name")+"神情專注的念著一些咒語，突然天空中飄來一朵烏雲，一隻水精靈\n飄了出來，你見到水精靈伸出手去觸摸"+me->query("c_cap_name")+"的傷口之後，又隨著烏雲飄走了。\n";
        string str3="HIB";

 	seteuid(getuid());
	me->set_temp("summon_rest",1);
	this_object()->move(environment(me));
        tell_object(me,"水精靈對你說：沒問題...我馬上來幫你醫療!\n");
        me->receive_healing(15+random(5));
        END->bye_bye(me,this_object(),10,str1,str2,str3);
	return 1;
}
