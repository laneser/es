#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("ChiYu_axe ","蚩尤七殺斧");
       add("id",({"axe","chiyu axe",}) );
       set_short("蚩尤七殺斧");
	   set_long(@C_LONG
這是用不明物質特製的巨斧，破壞力相當大，但沒有過人的力量
是拿不動的，相傳蚩尤曾以他大戰黃帝於屯鹿之野，但在蚩尤戰敗之
後，這把戰斧的力量遭到黃帝封印，現在聽說威力只剩當時的一半了
C_LONG	
	);
	set( "unit", "把" );
 	set( "weapon_class", 40 );
        set("type","axe");
	set( "min_damage", 25 );
	set( "max_damage", 53 );
	set( "weight", 250 );
	set( "nosecond", 1 );
	set("bleeding",8);
	set( "value", ({ 1050, "gold" }) );
	
}	
