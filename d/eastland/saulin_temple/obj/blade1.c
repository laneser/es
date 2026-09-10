#include <mudlib.h>

inherit WEAPON ;

void create()
{
	set_name("holy blade", "少林戒刀");
	add ("id", ({ "holy","blade" }) );
	set_short( "少林戒刀" );
	set_long(
		"這是少林的戒律院執事僧所慣用的兵器 一般人稱之為戒刀\n"
	);
	set("type", "longblade");
	set("weapon_class", 25);
	set("min_damage", 12);
	set("max_damage", 25);
	set("weight", 150);
	set("value", ({ 500, "silver" }) );
	set_c_verbs( ({
		"%s從一個奇怪的角度砍了出來，砍在%s",
		"%s從上向下直劈 劈向%s",
		"將%s揮成一片刀幕，傷到%s",
		"手中的%s捲起一陣呼呼的風聲，刺在%s",
	}) );
}
