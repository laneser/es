#include "mercury.h"

inherit MONSTER;

void create()
{
	::create();
	set_level(16);
	set_name( "Ninjadog Poppy", "忍犬 巴比" );
	add( "id", ({ "ninjadog","dog","poppy" }) );
	set_short( "Ninjadog Poppy", "忍犬 巴比" );
	set_long(@AAA
這是一隻兇猛的大狗，由於受過忍法的訓練，有比一般警衛犬有更強的
戰力，是加爾福特的愛犬！
AAA
 );
	set( "unit", "只" );
	set( "race", "monster" );
	set( "gender", "male" );
	set_perm_stat( "str", 25 );
        set_perm_stat( "dex", 25 );    
        set( "max_hp",350 );
        set( "hit_points",350 );
 	set_natural_armor( 60,25 );
	set( "natural_weapon_class1", 60 );
	set( "natural_min_damage1", 15 );
	set( "natural_max_damage1", 35 ); 
        set( "special_defense",([ "all":15,"none":15 ])); 
        set( "aim_difficulty",([ "critical":90,"weakest":15,"ganglion":50,
                                 "vascular":35 ]));
        set( "stun_difficulty/ma",15);  
	set( "alignment", 1000 );
	set_c_limbs( ({ "頭部", "身體", "前腳", "咽喉","後腿","尾巴" }) );
        set_skill( "tactic",100 );
        set("tactic","berserk");
        set( "wealth" , ([ "silver": 70 ]) );
        set_c_verbs( ({"%s衝到你面前，用後腳對%s一陣亂踢","%s突然消失，從空中落下來撞%s",
                       "%s飛撲過來，用利爪抓向%s"}));    
}
