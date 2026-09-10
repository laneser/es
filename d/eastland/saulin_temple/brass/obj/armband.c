#include <mudlib.h>

inherit ARMOR;
 
void create()
{
        set_name("brass armband", "臂環");
        add( "id", ({"armband" }) );
        set_short("降龍伏虎臂環");
        set_long(
                "這是一個由十八個神態莊嚴的羅漢扣合而成的臂環，各個施展著\n"
                "一套不同的拳法。\n"
        );
        set( "unit", "個");
        set( "type", "arms" );
        set( "material", "monk" );
        set( "defense_bonus",1 );
        set( "armor_class",1 );
        set( "weight", 1 );
        set( "value", ({ 1, "gold" }) );
        set( "no_sale",1);
        set( "prevent_drop",1);
        set( "extra_skills", (["inner-force":5,"recitation":10]) );
        set( "equip_func", "to_equip");
        set( "unequip_func", "to_unequip");
}

int query_auto_load() { return 1; }

int to_equip() 
{
	this_object()->set("extra_look","@@looks");
	return 1;
}
int to_unequip()
{
	this_object()->delete("extra_look");
	return 1;
}
string looks()
{
	return set_color("$N戴著一個盤著十八羅漢的臂環, \n它除了是通過少林寺十八銅人陣的證明外, 更是強者的象徵 !!\n","HIW");
}
