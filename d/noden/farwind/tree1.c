//#pragma save_binary

// Unos translacion de Platino, Mar 4 2:33:23 1994

#include <mudlib.h>

inherit ROOM;

int beehive = 0;

void create()
{
	::create();
    set_short( "榕樹上");
	set_long( @C_LONG_DESCRIPTION
你輕而易舉地便爬上了這棵榕樹，從樹上往下看可以看到遠風鎮的西門
和旁邊的一間白色小屋，咦....啊....就在離你一公尺不到的地方有一個西
瓜大的蜂窩(beehive) ，蜜蜂嗡嗡的聲音似乎就在你的耳邊，還是趕緊離開
這個地方以免驚動它們。
C_LONG_DESCRIPTION
	);

	set( "exits", ([
		"down" : "/d/noden/farwind/w_gate"
	]) );
	set( "objects", ([
		"witch" : "/d/noden/farwind/monster/witch" ]) );
	set( "item_desc", ([
        "beehive" :
			"一個和西瓜差不多大的蜂窩，你最好不要靠太近，以免蜜蜂受到驚擾。\n",
	]) );
    reset();
}

void init()
{
	add_action( "do_hit", "hit" );
	if( this_player() ) this_player()->set_explore("noden#0");
}

int do_hit(string arg)
{
	object obj;
	int i;

	if( !arg || arg!="beehive" ) return 0;
	write( "你躡手躡腳地靠近蜂窩，往蜂窩用力一敲！\n");
	tell_room( this_object(), 
		this_player()->query("c_name") + "躡手躡腳地靠近蜂窩，然後在上面用力一敲！\n",
		this_player() );
	if( beehive ) return 1;
	beehive = 1;
	for( i=0; i<6; i++ ) {
		obj = new( "/d/noden/monster/hornet" );
		obj->move(this_object());
	}
	for( i=0; i<3; i++ ) {
		obj = new( "/d/noden/monster/hornet_soldier" );
		obj->move(this_object());
	}
	
	this_player()->set_explore( "noden#3" );
	
	this_player()->gain_experience(100);
	write( "你得到 100 點經驗。\n" );
	return 1;
}
