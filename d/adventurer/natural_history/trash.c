#include <mudlib.h>

#define c_name ({"破雨傘","爛木頭","舊衣服","破鞋","狗大便","死人骨頭","蒲葉"})
#define ID ({"umbrella","trunk","cloth","shoes","shit","bone","leave"})
#define name ({"broken umbrella","rotten trunk","old clothes","poor shoes","dog's shit","bone of human","huge leave"})
#define UNITS ({ "把","根","件","雙","沱","根","片" })
#define TYPES ({ "head","shield","body","feet","feet","misc","cloak" })
#define ARMORS ({ 1,1,4,1,1,0,1 })
#define DEFENSE ({ 1,2,2,1,2,2,1 })

inherit ARMOR;

void create()
{
	int i;
	i = random(7);
	set_name(name[i],c_name[i]);
	add( "id" , ({ ID[i] }) );
	set_short(c_name[i]);
	set_long(
	"這是一"+UNITS[i]+c_name[i]+"，不知道能拿來幹嘛??\n"
	);
   	set( "material","adventurer");
   	set("type",TYPES[i]);
   	set( "armor_class", ARMORS[i] );
   	set( "defense_bonus", DEFENSE[i] );
   	set("unit",UNITS[i]);
   	set("weight", 10);
}
