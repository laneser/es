
#include "mudlib.h"

#define AC ({ 7,4,4,7,7,7 })
#define DB ({ 1,0,0,1,2,1 })
#define TYPES ({"head","arms","hands","legs","cloak","feet" })
#define UNITS ({"頂","個","雙","雙","片","雙" })
#define ADD_CNAME ({"山賊戰鬥頭盔","山賊戰鬥護肘","山賊戰鬥護手","山賊戰鬥脛甲","山賊戰鬥背甲","山賊戰鬥靴" })
#define EXTRA_ID ({"helmet","sleeves","bracers","leggings","backarmor","shoes" })
inherit ARMOR;

void create()
{
        int i;
        i = random(6);
        set_name("bandit "+EXTRA_ID[i], ADD_CNAME[i]);
        add( "id", ({ EXTRA_ID[i] }) );
        set_short(ADD_CNAME[i]);
        set_long(
                "這是梁山泊的山賊們所使用的"+ADD_CNAME[i]+"\n"
                "雖然看來不是很美觀，但是卻相當實用..\n"
        );
        set("unit",UNITS[i]);
        set( "type", TYPES[i] );
        set( "material", "heavy_metal");
        set( "armor_class", AC[i] );
        set( "defense_bonus", DB[i] );
        set( "weight", 250 );
        set( "value", ({ 230, "silver" }) );
}



