#include "../asterism.h"

inherit ARMOR;

void create()
{
        set_name("obsidian gloves", "黑曜石手套");
        add( "id", ({ "gloves" }) );
        set_short( "黑曜石手套");
        set_long(
                "這是一雙由珍貴的黑曜石製成的手套。\n"
        );
        set("unit","雙");
        set( "type", "hands" );
        set("material","element") ;
	set( "armor_class", 5 );
        set( "defense_bonus", 3 );
        set( "weight", 65 );
        set( "value", ({ 150, "gold" }) );
}






