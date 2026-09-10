#include <mudlib.h>
void create(object ob)
{
        if (!ob) return ;
        seteuid(getuid()) ;

	ob->set_level( 4 );
	ob->set_name( "boarman shaman", "野豬人巫醫" );
	ob->add( "id", ({ "boarman", "shaman" }) );
        ob->set_short( "野豬人巫醫" );
	ob->set_long(
		"唔....嗯....如果你的審美觀沒有錯的話，這位野豬人算是個美女了，她\n"
		"的皮膚比她的同類白，而且毛比較少，至少脖子上的鬃毛比較短....。\n"
	);
	ob->set( "gender", "female" );
	ob->set_perm_stat( "str", 5 );
	ob->set_perm_stat( "dex", 7 );
	ob->set( "max_hp", 80 );
	ob->set( "hit_points", 80 );
	ob->set_skill( "blunt", 40 );
	ob->set_skill( "parry", 30 );
	ob->set( "natural_armor_class", 15 );

	ob->wield_weapon("/d/noden/recamp/obj/staff");
	ob->equip_armor("/d/noden/recamp/obj/cloak");
}
