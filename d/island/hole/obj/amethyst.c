//#include <mudlib.h>
#include <daemons.h>
#include "../hole.h"

inherit OBJECT;

void create()
{
	set_name( "Amethyst","紫水晶" );
	add( "id",({ "amethyst" }) );
	set_short( "紫水晶" );
	set_long(@LONG
	一根閃閃發亮的紫水晶，據說它能吸收月亮的
	光芒，產生破魔的力量。你可以試著使用在物
	品上。
LONG
		);
	set( "weight",5 );
	set( "no_sale",1 );
	set( "value",({ 320,"silver" }) );
	set( "prevent_drop",1 );
	set( "unit","根");
	set( "light",1 );
}           

void init()
{
	add_action( "to_show","show" );
}

int to_show( string arg )
{
    string who,month,msg;
    object ob;
    int year,day,j,k;
    
    if( !arg ) return notify_fail( "啥？\n" );
    if( sscanf( arg, "amethyst to %s", who )!=1 )
      return notify_fail( "Usage : show what to whom\n" );
    ob = present( who, environment(this_player()) );
    if( !ob ) {
      tell_object( this_player(),"這裡沒這個人。\n");
      return 1;
    }
    sscanf(WEATHER_D->query_c_game_time(),"王國曆 %d 年，%s %d 日，%s %d 時 %d 分",
    year,month,day,msg,j,k );
    if( msg=="凌晨" || msg=="深夜" || msg=="夜晚" ){
    if( undefinedp(ob->change(ob, this_player())) )
    tell_object( this_player(),
	ob->query("c_name")+"說：你幹什麼?\n" );
    return 1;
    }
    else {
    return notify_fail( "時間不對喔！只有藉著月光才能發揮它的功用。\n" );
    }
}
