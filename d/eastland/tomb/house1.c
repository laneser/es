#include "almuhara.h"

inherit ROOM;
inherit DOORS;
void create()
{
	::create();
	set_short("精緻小屋");
	set_long( 
@C_LONG_DESCRIPTION
你來到了一幢精緻的小屋門前。小屋四周種滿了各式各樣的奇花異卉，間或有幾隻蝴蝶
在其中穿插飛舞。小屋旁有一口井(well)，井旁有一片空地，上面稀稀散散地插了十數支普
通的竹竿，卻隱隱約約有股霧氣籠罩在空地上，你想還是不要過去的好。在門的兩旁有兩隻
栩栩如生的石獅子。門上有個匾額寫著 ---- 『 逍遙居 』。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"west"  : TOMB"/lin5",
		"enter"  : TOMB"/house2"  ]) );
	create_door( "enter","out",
		(["keyword" : ({"door"}),
		  "name"    : "red door",
		  "c_name"  : "紅門",
		  "c_desc"  : "一扇紅色的門。",
		  "status"  : "closed",
		  ]) );
	add( "c_item_desc", ([
		"well" :@WELL_DESC
一口深不見底的井，似乎有什麼聲音傳上來。
WELL_DESC
	]) );
	reset();	
}

