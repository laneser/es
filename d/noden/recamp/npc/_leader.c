#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;

	ob->set_level( 5 );
	ob->set_name( "boarman leader", "野豬人領袖" );
	ob->add( "id", ({ "boarman", "leader" }) );
        ob->set_short( "野豬人領袖" );
	ob->set_long(
		"這個野豬人長得很「兇猛」，滿臉橫肉，綠豆般大的眼睛卻精神亦亦地\n"
		"打量著你這個不速之客。\n"
	);
	ob->set( "gender", "male" );
	ob->set_perm_stat( "str", 8 );
	ob->set_perm_stat( "con", 8 );
	ob->set( "max_hp", 100 );
	ob->set( "hit_points", 100 );
	ob->set_skill( "axe", 50 );
	ob->set_skill( "parry", 30 );
	ob->set( "natural_armor_class", 20 );
	ob->wield_weapon("/d/noden/recamp/obj/axe");
	ob->equip_armor("/d/noden/recamp/obj/chainmail");
}
