#include "almuhara.h"

inherit ROOM;

void create()
{
	::create();
	set_short("地下廣場");
	set_long( 
@C_LONG_DESCRIPTION
這裡是一個巨大的廣場，在經過那麼長久的路程後，這兒令你有豁然開朗的感覺。實在
無法想像當年的工匠們是如何在地底下建立如此大的廣場，你不禁對那些工匠起了分敬意。
廣場上空空蕩蕩的，似乎沒有任何生物存在，也許早就死光了。在西邊好像有什麼東西，紅
紅的光吸引你過去探個究竟。
C_LONG_DESCRIPTION
	);

	set( "exits", ([ 
		"east" : TOMB"/square5", 
		"west" : TOMB"/square21"  ]) );
	set( "objects", ([
		"guard" : MOB"/holy_guard2" ]) );
	set( "pre_exit_func", ([
		"west" : "check_guard" ]) );
	reset();	
}

int check_guard()
{
	if (present( "guard", this_object() ) ){
		tell_object(this_player(),
		"守衛阻止你前進!!\n");
		return 1;}
	else return 0;
}