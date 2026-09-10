#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(3);
	set_name( "student", "學子" );
	set_short( "學子" );
	set_long(@C_LONG
一個綁著兩個辮子，捧著課本專心於課堂上的小學子。
C_LONG
        );
	set( "gender", "male" );
        set_natural_armor(25,0); 
        set_natural_weapon( 3,1,3 );
}
