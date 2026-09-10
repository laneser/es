#include <takeda.h>

inherit ROOM;

void create()
{
	::create();
	set_short( "柵上小路" );
	set_long(
	"這裡是梁山泊大寨上的小路，是為了防禦攻擊而建造的．但近幾年\n"
	"來，已沒有人敢來侵犯了．站在這裡，遠方的風景一覽無遺．小路繼續\n"
	"向東方延伸．\n"
	  
	);
	set_outside("eastland");
	set( "light",1 );        
        set( "exits", ([
                "east" : TROOM"wall2",
                "westdown" :TROOM"gate1"      
        ]) );
        reset();
}
int clean_up() { return 0; }