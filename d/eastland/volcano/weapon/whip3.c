#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "fire god whip", "火神鞭" );
	add( "id", ({ "whip" }) );
	set_short( "火神鞭" );
	set_long(
	  "這是一條火紅色火神鞭，平常是供在正殿，遇到敵人時可拿來對敵，\n"+
	  "充滿了一種奇特的魔力。\n"
	);
	set( "unit", "條" );
	set( "weight", 30 );
        set("nosecond",1);
	setup_weapon( "whip", 20, 10,20);
	set( "value", ({ 500, "silver" }) );
//        set( "hit_func", "special_hit" );
        set_verbs(({"%s甩向%s","%s卷向%s","%s揮向%s"}));

}

int special_hit(object victim)
{	
	object holder;
	holder=environment(this_object());
        if( random(holder->query_perm_stat("pie")+
		   holder->query_perm_stat("int"))<20) return 0;
        if( victim->query("stop_attack") ) return 0;

        tell_object( victim,
          "\n火神鞭啪的擊在地面，平地裡捲起一片烈火向你燒去 !!\n\n");
        tell_object( holder,
          "\n你將火神鞭往地上一擊，平地裡捲起一片烈火向敵人燒去 !!\n\n");
        tell_room( environment(holder),
          "\n"+holder->query("c_cap_name")+"將火神鞭往地上一擊，平地裡捲起一片烈火向" + victim->query("c_name") +"燒去 !!\n\n"
	, ({ victim, holder }));
        victim->receive_special_damage("fire",12+random(10));
        return 1;

}
