#include "../echobomber.h"

inherit ARMOR;

void create()
{
        set_name("Luck ringmail","幸運環甲");
        add("id",({"ringmail"}) );
         set_short( "a luck ringmail","幸運環甲");
	set_long(
"This is a suit of ringmail made of mithril meterial,which can  \n"
"protect your body against opponent's attacks.\n",
"這是一副環甲,可以保護你抵抗敵人的攻擊,據說穿上這環甲的人在戰鬥中能夠幸運\n"
"的避開敵人的重擊.\n"
	);
	set( "unit", "件" );
	set( "weight", 250 );
	set( "type", "body" );
	set( "material", "light_metal");
	set( "armor_class", 22 );
	set( "defense_bonus", "@@luck_bonus" );
	set( "value", ({ 188, "gold" }) );

}

int luck_bonus()
{ 
    int bonus;
    
    bonus= 2 +random(5);
    return bonus;
}     
