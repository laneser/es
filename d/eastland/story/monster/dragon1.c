#include <mudlib.h>

inherit MONSTER ;

void create ()
{
	::create();
	set_level(18);
	set_name( "thunder dragon", "應龍" );
	add ("id", ({ "dragon"}) );
	set_short( "雷獸 應龍");
	set_long(@CLONG
應龍生著一對晶瑩剔透的翅膀，原是住在「兇犁土邱山」的南端，善能畜水行
雨。應龍當年受黃帝大戰蚩尤所託，前來助陣。因為那時蚩尤會作大霧，但黃帝心
想，應龍能下大雨，難道大雨遠不及大霧？結果黃帝失算，因為蚩尤早已搬請了風
伯雨師來，風伯雨師祭起滔天雨水，使應龍猶如「小巫見大巫」般地而撤退。後來
蚩尤戰敗，黃帝勒命應龍看守這裡，以防北邊的解池有所變異。
CLONG
	);
	set_perm_stat("str", 25 );
        set_perm_stat("kar", 10 );
        set_perm_stat("int", 30 );
	set_skill( "dodge", 100 );
	set( "alignment", 800 );
	set( "hit_points", 800 );
	set( "max_hp", 800 );
        set( "max_fp",400);
	set_natural_weapon( 57, 23, 38 );
	set_natural_armor( 117, 20 );
        set( "tactic", "flank" );
        set("special_defense",(["all":30]));
        set("aim_difficulty",([ 
    	  "critical":80,"vascular":50,"weakest":50,"ganglion":50 ]) );
        set_skill("concentrate",100);
        set_skill("target",100);
        set_skill("black-magic",100);
        set("time_to_heal",5);
        set("spells/lightning",1);
        set("guild_levels/black-magic",50) ;
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
        set_c_verbs(({
                "%s用它的利爪向%s抓去",
                "%s伸出它那長滿利牙的嘴巴向%s咬去"
        }));
        set("tactic_func","my_tactic");
}
int my_tactic()
{
    int i;
    object victim;
    if ( !victim=query_attacker() ) return 0;
    if ( random(14)> 3 ) return 0;
    if ( query_temp("cast_busy") ) return 0;
    for ( i=0;i<2;i++ ) 
       command("cast lightning on "+victim->query("name"));
    set("stop_attack",0);
    return 1;
}
