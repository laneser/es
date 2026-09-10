#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_name("statue","娜考璐璐雕像");
	add( "id" , ({ "statue" }) );
	set_short("statue" , "娜考璐璐雕像");
	set_long(@AAA
一個雕刻相當精美的雕像，仔細一看原來是個娜考璐璐的人像，真不愧是
一代雕刻大師橘右京刻的，人物栩栩如生，要不是因為這個雕像比真人來
得小，還真以為這是真人呢！！	
AAA
	);
   	set("unit","個");
   	set("weight", 20);
   	set("nakoruru_statue",1);
   	set("value",({ 1, "silver" }) );
}

