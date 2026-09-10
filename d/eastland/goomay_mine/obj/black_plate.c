#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "black platemail", "黑色盔甲" );
	add( "id", ({ "plate", "platemail" }) );
	set_short( "黑色盔甲" );
	set_long(@AA
這是一套和黑色護膝不同質料的盔甲，不過它雖然不起眼，卻能提供相當不錯的防禦力。
AA
	);
	set( "unit", "套" );
	set( "type", "body" );
	set( "material", "heavy_metal" );
	set( "armor_class", 33 );
	set( "equip_func","bonus_up");
	set( "unequip_func","stop_bonus_up");
	set( "weight", 270 );
	set( "value", ({ 2000, "silver" }) );
}
void bonus_up()
{
    object ob;
    if((ob=present("wooden armband",environment(this_object()) ))&&
        (ob->query("equipped"))){
        set( "defense_bonus",6);
        set( "armor_class",35);
        tell_object(environment(this_object()),
"當你穿上黑色盔甲時，發現他和黑木臂環緊緊密合形成一套極棒的戰鬥服\n"
);
return 0;
}
}
void stop_bonus_up()
{
set( "defense_bonus",0);
set( "armor_class",33 );
}
