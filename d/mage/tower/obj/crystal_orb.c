#include <mudlib.h>

inherit OBJECT;
#include "/d/mage/tower/detect-magic.h"
#define USE_SP 20
int do_use(string str);

void create()
{
		//seteuid( getuid() );
	    set_name( "crystal orb", "水晶球" );
        add( "id", ({ "orb"}) );
        set_short( "水晶球" );
//        set_long(@LONG
//			這是一顆水晶球，光線照射進球內，發散出五彩的光芒。使你不禁想使用(use) 看看。
//			LONG );
	set_long(@LONG
這是一顆水晶球，光線照射進球內，發散出五彩的光芒。使你不禁想使用(use) 看看。
LONG);
        set("unit","顆");
        set("weight", 20);
        set( "value", ({ 20, "silver" }) );
        set("no_sale",1);

}

void init()
{
        add_action( "do_use", "use" );
}

int help ()
{
return notify_fail( "指令格式: use orb to identify 〈防具〉 \n");
}

int do_use(string str)
{
	int num;
	string this1,class1;
	object dest;
	if (!str) return help();
	class1 = (string)this_player()->query("class");
	if(!( wizardp(this_player()) || class1=="mage" || class1=="necromancer" ||
		class1=="sage")) {
		write("你不是魔法師，不知道如何使用這個水晶球。\n");
    		return 1;
	}	
	if (this_player()->query("spell_points") < USE_SP){
		write ("你的法力不夠！\n");
		return 1;
	}
	if (!this_player()->query("vision")) {
		write("你什麼也看不見。\n");
		return 1;
	}
	if (sscanf(str, "orb to identify %s", this1) == 1){
		if ( !dest= present( this1, this_player() ) )
			return notify_fail( "你沒有這樣東西。\n");
		num=this_player()->query_skill("identify");
		this_player()->add("spell_points", -USE_SP );
	write("你運用法力使用水晶球，水晶球發出了一陣異樣的光芒。\n");
	tell_room(environment(this_player()),this_player()->query("c_name")+"身上的水晶球發出了一陣異樣的光芒。\n",this_player());
		write(identify_armor(dest,num));
		return 1;
	}
	return help();
}

