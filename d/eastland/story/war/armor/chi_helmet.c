#include <mudlib.h>

inherit ARMOR;

void create()
{
        set_name("Chi-eu's helmet","蚩尤戰盔");
        add("id",({"helmet"}) );
        set_short("蚩尤戰盔");
	set_long(@C_LONG
一件用布料縫製而成的護頭，上面插了幾根羽毛，有點像印地安那頭上穿的東西。
C_LONG	         );
	set( "unit", "頂" );
	set( "weight",60 );
	set( "type", "head" );
        set("material","cloth");
	set( "defense_bonus", 2 );
	set( "value", ({ 1000, "silver" }) );
}
