#include <mudlib.h>

inherit WEAPON;

void create()
{
	set_name( "chilin whip", "麒麟鞭" );
	add( "id", ({ "whip" }) );
	set_short( "麒麟鞭" );
	set_long(
	  "這是一條火紅色麒麟鞭，平常是供在左殿，遇到敵人時可拿來對敵，\n"+
	  "充滿了一種奇特的魔力。\n"
	);
	set( "unit", "條" );
	set( "weight", 30 );
        set("nosecond",1);
	setup_weapon( "whip", 20, 9,18);
	set( "value", ({ 320, "silver" }) );
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
          "\n麒麟鞭快速的舞著，鞭影似化成一隻火麒麟向你撲來!!\n\n");
        tell_object( holder, 
          "\n你急速的舞著麒麟鞭，鞭影化成一隻火麒麟向敵人撲去 !!\n\n");
        tell_room( environment(holder),
          "\n麒麟鞭快速的舞著，鞭影似化成一隻火麒麟向" + victim->query("c_name") +"撲去 !!\n\n"
	, ({ victim, holder }));
        victim->receive_special_damage("fire",5+random(10));
        return 1;

}
