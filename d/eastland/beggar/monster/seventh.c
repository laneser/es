#include <mudlib.h>

inherit MONSTER;

void create()
{
	::create();
	set_level(14);
	set_name( "seven-bag beggar", "七袋弟子" );
	add( "id",({"beggar","seven"}) );
	set_short( "丐幫 七袋弟子" );
	set_long(@C_LONG
丐幫七袋弟子在幫中地位算是蠻高, 他現在正在教導五袋弟子的武功。 
C_LONG	
        );
        set( "unit", "名" );
	set_perm_stat( "str", 22 );
	set_perm_stat( "dex", 16 );
	set_perm_stat( "kar", 20 );
        set("weight",650);
	set_skill( "dodge", 80 );
	set( "special_defense", ([ "all": 20 ]) );
	set( "race","human");
	set( "gender", "male" );
	set( "alignment", 200 );
	set_natural_armor( 25, 10 );
	set_natural_weapon( 40, 18, 20 );
        set( "natural_weapon_class2", 40 );
        set( "natural_min_damage2", 15 );
        set( "natural_max_damage2", 25 );
	set( "wealth/gold", 60 );
        set("chat_chance",15);
        set("chat_output",({
          "七袋弟子說道：不對不對,怎麼教幾次還不懂啊?\n",
          "七袋弟子說道：你又攪錯了,不是這樣啊!!\n"                        
                                  }) );
	set_c_verbs( ({ "%s踏步向前，一記直拳打向%s",
		"%s一記 『太祖長拳』，雙拳直取%s",
		"%s一招  『聲東擊西』，右足點向%s", 
		"%s一招 『猛虎出閘』，左拳如風，直取%s",
                   }) );

}
