#include <mudlib.h>

inherit ARMOR;

void create()
{
    set_name("red sandal beads","紫檀念珠");
    add("id",({"bead","beads","sandal"}) );
    set_short( "red sandal beads","紫檀念珠");
	set_long(
"This is a holy-ball necklace \n"
"這是一串由萬年紫色檀香木做成的念珠, 相傳是佛陀用過的念珠, 由於使用很久,\n"
"看起來很舊了, 但是它飄散出一股神秘的香味, 讓你覺得使用起來很安心。\n"
	);
	set( "no_sale",1);
	set( "unit", "串" );
	set( "weight", 17 );
	set( "type", "misc" );
    set( "material", "wood");
	set( "armor_class", 2 );
	set( "defense_bonus", 8 );
	set( "value", ({ 100, "gold" }) );
}
