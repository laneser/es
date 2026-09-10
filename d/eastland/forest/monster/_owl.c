#include "../forest.h"

void create(object ob)
{
	if ( ! ob ) return ;
        ob->set_level(3);
        ob->set_name( "owl", "貓頭鷹" );
        ob->set_short( "貓頭鷹" );
        ob->set_long(
                "這是一種晝伏夜出的鳥，叫聲非常難聽，常被視為不吉祥的象徵。\n"
        );
        ob->set("unit","只");
        ob->set( "alignment", -100 );
        ob->set_perm_stat( "dex", 5 );
        ob->set_natural_weapon(4,3,6);
        ob->set_natural_armor(9,0);
        ob->set_c_verbs( ({ "%s往下俯衝，用嘴巴啄%s", "%s用爪子往%s抓下" }) );
        ob->set_c_limbs( ({ "頭部", "身體", "翅膀" }) );
}
