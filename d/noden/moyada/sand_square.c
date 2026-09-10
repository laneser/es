//#pragma save_binary

// adding room desc, yeah.. run on sentences.. big deal.. -Elon 03-10-94
#include "moyada.h"
#define ant_number 4

inherit ROOM;

int ant = 0;

void create()
{
	::create();
	set( "dig", 1);
   set_short( "一片沙地" );
	set_long( @LONG_DESCRIPTION
你來到一片廣大的沙地，眼前矗立著一座巨大的沙丘，你看到幾隻螞蟻爬進
爬出的，莫非是一座蟻窩(anthill)?
LONG_DESCRIPTION
	);
	set( "exits", ([
		"east" : MOYADA"mainrd7"
	]) );
	set( "c_item_desc", ([
		"anthill" : "一座像小山的蟻冢，你最好不要靠太近，以免受到兵蟻圍攻。\n"+
		            "更別想亂挖它，小心螞蟻群擁而上。\n",
	]) );
	set( "objects", ([
	   "ant worker#1" : MOYADA"monster/ant_worker",
	   "ant worker#2" : MOYADA"monster/ant_worker",
	   "ant fighter" : MOYADA"monster/ant_fighter",
	   "ant solider" : MOYADA"monster/ant_solider",
	   "ant knight" : MOYADA"monster/ant_knight",
	]) );
	reset();
}

void reset()
{
    ::reset();
    set( "ant_left", 10);
    ant = 0;
}

void init()
{
	add_action( "do_enter", "enter" );
}

void to_find_dig(string arg)
{
	object obj;
	int i;

	if( arg != "anthill" ) {
	write( "這裡沒有那種東西可挖！\n" );
	  return;
	}

	if( ant ) {
		write( "這個蟻穴已經被挖過了！\n" );
		return;
	}

   write(
          "你用鏟子去挖蟻冢，轟的一聲蟻冢垮了，露出一個大洞(hole)！\n" );
    tell_room( this_object(),
	this_player()->query("c_name")+"用鏟子去挖蟻穴，轟的一聲蟻冢垮了！\n",
		this_player() );
	add( "c_item_desc", ([
		"hole" : "蟻冢的入口，你最好不要進入，以免受到兵蟻圍攻。\n",
	]) );
	ant = 1;
	for( i=0; i<ant_number; i++ ) {
		obj = new( MOYADA"monster/ant_killer" );
		obj->move(this_object());
	}
   this_player()->set_explore("noden#7");
	return ;
}

int do_enter( string str )
{
    object obj, player;
    int left, i;
    if( !str || str == "" )
    return notify_fail( "進去哪裡?\n" );
    if( !ant )
       return notify_fail( "這裡沒有洞！\n" );
    player = this_player();
    if( obj=present("ant") ) {
       tell_object( player,
          "洞口的螞蟻阻止你進入並開始攻擊你。\n" );
       obj->kill_ob( player );
       return 1;
     }
    if( (left=(int)this_object()->query("ant_left")) && (left>1) ) {
        tell_object( player, 
           "二隻工蟻從蟻冢內爬了出來不讓你進去並開始攻擊你。\n" );
       for( i==0; i<2; i++ ) {
         obj = new(MOYADA"monster/ant_worker");
         obj->move(this_object());
         obj->kill_ob(player);
         left--;
       }
       this_object()->set("ant_left",left);
       return 1;
    }
     tell_room( MOYADA"anthill/cellar1", 
        sprintf("%s爬了進來。\n", player->query("c_name") ), player );
     tell_room( this_object(),
       sprintf("%s爬進蟻冢。\n", player->query("c_name") ), player );
    player->move_player(MOYADA"anthill/entrance","SNEAK");
    return 1;
}
