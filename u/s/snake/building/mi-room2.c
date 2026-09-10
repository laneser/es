#include <mudlib.h>
#include <weather_d.h>
#include <daemons.h>

inherit ROOM;

void create()
{
        ::create();

        set_short("MI room", "一刻館");
        if ( correct_date()<19* 86400 / DAY_LENGTH/ 3600<19 ) {
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

int correct_date()      
{
        int current_time;

        current_time = time() - START_GAME_TIME;
        current_year = START_YEAR;
        while (current_time>YEAR_LENGTH) {
                current_time -= YEAR_LENGTH ;
                current_year ++;
        }
        current_month = START_MONTH ;
        while (current_time>months[current_month]["length"]*DAY_LENGTH) {
                current_time -= months[current_month]["length"]*DAY_LENGTH;
                current_month ++;
                if( current_month==num_months ) {
                        current_month=0;
                        current_year ++;
                }
        }
        current_day = START_DATE + current_time/DAY_LENGTH;
        current_time -= (current_time/DAY_LENGTH)*DAY_LENGTH - START_TIME;
        return current_time ;

}

