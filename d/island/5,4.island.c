// File: 5,4.island.c

#include <mudlib.h>
#include "island.h"
inherit ROOM;
int no_branch;

void create()
{
	::create();
	set_short("桃花林");
	set_long( @LONG_DESCRIPTION
你身處在一片美麗的桃花林中，這裡正是所謂的『落英繽紛，芳草鮮
美』，要是仔細觀察此處的桃樹，你會發現它們以某種奇怪的次序排列著
，但你又看不出人力斧鑿的痕跡，或許是渾然天成的吧；在這裡站的越久
，你越覺得世間的名利鬥爭已經離你遠去，這種心曠神怡的感覺，使你對
兒流連忘返；南邊和西邊有條小河，但是有點深，小心唷！	
LONG_DESCRIPTION
	);

	set_outside( "island" );
	set( "exits", ([ 
		"west"  : ISLAND"4,4.island", 
		"north" : ISLAND"5,3.island", 
		"east"  : ISLAND"6,4.island",
		"south" : ISLAND"5,5.island",
		]) );
	set( "original", ISLAND"5,4" );
	set( "virtual_server", ISLAND"virtual/island_server" );
	set( "x_coordinate", 5 );
	set( "y_coordinate", 4 );
	no_branch=0;
	reset();
}

void init(){ add_action( "to_mill","mill" ); }

int to_mill( string arg )
{
	string target,tool;
	object obj;

	if( !arg || sscanf(arg,"%s with %s",target,tool)!=2 )
	return notify_fail( "Usage: mill <目標> with <工具> \n" );
	if( target!="tree" ) 
	return notify_fail( "這把斧頭只能砍樹木。\n" );
	if( tool!="saw" )
	return notify_fail( "用手鋸嗎？\n" );
	if( !present( "saw",this_player() ) )
	return notify_fail( "糟糕！你忘了帶鋸子來！\n" );
	if( no_branch < 4 ){
	tell_object(this_player(),
	"\n你費了九牛二虎之力，終於找到一棵合適的桃樹，鋸下一根樹枝！\n\n" );
	obj=new( "/d/island/hole/obj/branch" );
	obj->move( this_player() );
	this_player()->set_explore("island#8");
	no_branch=no_branch+1;
	return 1;
	}
	tell_object(this_player(),"\n不知道哪個奸商把這裡的桃木全砍了。\n\n" );
	return 1;
}
