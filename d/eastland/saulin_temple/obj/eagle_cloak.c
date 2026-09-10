#include <mudlib.h>

inherit ARMOR;

void create()
{
	set_name( "silver cloak", "銀鷹之翼" );
	add( "id", ({ "cloak" }) );
	set_short( "銀鷹之翼" );
	set_long(@C_LONG
銀鷹據說是居住在高山頂的極稀有生物，它的羽毛據說十分的珍貴。
銀鷹之翼是用銀鷹的羽毛做成的袍子，又保暖又有極佳的保護效果。
C_LONG
                );
	set( "unit", "件" );
	set( "type", "cloak" );
	set( "armor_class", 8 );
	set( "material", "leather" );
	set( "defense_bonus", 4 );
	set( "weight", 100 );
	set( "value", ({ 2530, "silver" }) );
}
