#include "../almuhara.h"

inherit OBJECT;

void create()
{
	set_name("paper","發黃的羊皮紙");
	set_short("發黃的羊皮紙");
	set_long(
		"一張發黃的羊皮紙，上面寫著滿滿的字。\n"
	);
	set("no_sale",1);
	set( "unit", "張");
	set("weight", 5);
	set("value", ({ 5, "silver" }));
}

void init()
{
	add_action("read_paper","read");
}

int read_paper(string str)
{
    object ob;
    if ( !str || str != "paper" ) return 0;
    else {
      ob = environment(this_object());
      if ( ob != this_player() ) 
        return 0;
      else 
        {
          write("有緣人：\n"
		"我是負責建築此地的工匠首領  陳彬。當你見到此封信時，可能已是數百\n"
		"年後了，但我仍然要把一切寫下，告訴後人.......\n"
		"當年大國師  孝光發現了此鍾天地之靈氣的寶穴，即稟告皇上。而皇上亦\n"
		"下令在此建築陵墓，以求我國運昌隆、綿延不絕。大家知道這是與國運有\n"
		"關，莫不盡心盡力，以期將此處建設完美。誰知就在完工在即之時，竟有\n"
		"一近侍向皇上進讒，欲殺盡建築此地的工匠，幸好有人事先通知我，我方\n"
		"能闢此小室避禍，惜我身中數創，仍逃不過一死.........\n\n"
		"我死於此，天意乎？  但求有緣人能將我身軀安葬，使我死後無憾。\n\n\n"
		"					賽魯班  陳彬 絕筆\n" );
          return 1;      
        }
    }
}
