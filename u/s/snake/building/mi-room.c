#include <mudlib.h>
#include <weather_d.h>
#include <daemons.h>

inherit ROOM;

void create()
{
        ::create();

        set_short("MI room", "一刻館");
        if ( (int)this_player()->query("alignment") < -200 ) {
                set_long( 
                 @C_LONG_DESCRIPTION
一刻館。你現在來到了一刻館的門口，這是一棟有點破舊的大木屋。
C_LONG_DESCRIPTION
        );
	} else {
                set_long( 
                 @C_LONG_DESCRIPTION
黑濛濛的！透過街燈微弱的燈光只看見一棟房子的摸樣，房間裡沒有燈光。
C_LONG_DESCRIPTION
        );
                }
        set( "light", 1 );
        set( "exits",([
                       "up"  : "/d/healer/building/healer_guild.c",  
                      ]) );
}

int clean_up() {  return 0; }
