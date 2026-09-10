#include "takeda.h"

inherit WEAPON;

int damage_count=0;
void create()
{
       set_name("gold bow","泥金鵲畫細弓");
       add("id",({"gold","bow",}) );
       set_short("泥金鵲畫細弓");
	   set_long(@C_LONG
你看到一把金色的弓，上面畫滿美麗的花鳥蟲魚，栩栩如生．
雖然你射箭並不好，也許拿堅硬的弓身也能直接攻擊敵人
C_LONG	);
	
	set( "unit", "把" );
 	set( "weapon_class", 35 );
        set("type","blunt");
	set( "min_damage", 18 );
	set( "max_damage", 35 );
	set( "weight", 50 );
	set( "value", ({ 310, "gold" }) );
        set_c_verbs( ({
          "%s射出一根箭，射向%s",
          "%s虛拉弓弦，發出颼的一聲，一股氣流襲向到%s",
          "%s一記力劈華山，拿弓用力敲向%s．",
          "%s發出一聲清嘯，連珠般射出五隻箭，射向%s",
         }) );
        set( "extra_skills",(["dodge":10])); 
}

