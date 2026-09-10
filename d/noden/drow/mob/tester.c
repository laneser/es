#include "../iigima.h"

inherit MONSTER ;

void create ()
{

        ::create();
	set_level(15);
        set_name( "Drow Valor Batur","黑暗精靈勇者　巴圖" );
        add ("id", ({ "drow", "valor","batur" }) );
        set_short( "Drow Valor Batur","黑暗精靈勇者　巴圖" );
        set("unit","位");
        set("alignment",900);
        set("weight",600);
        set("wealth/silver",1000);
        set_long(@C_LONG
這位英俊挺拔的武士是黑暗精靈族人中最英勇的戰士，他的武藝連隊長
修凱斯都要畏懼三分，據說能在他手下走過百招的人不過十餘人。如果你能
打敗他，那就是身為勇者的最佳證明。
C_LONG
        );
        set_perm_stat("int", 20);
	set_perm_stat("dex",20);
	set_perm_stat("str",18);
	set("max_hp",400);
	set("hit_points",400);
	set_natural_weapon(20,10,15);
	set_natural_armor(22,20);
        set ("special_defense",(["all":30, "cold":-10,
                        "fire":-10, "divine":-30,"evil":30, "none":15]));
        set ("race", "drow");
        set ("gender", "male");
        set_skill("longblade",80);
	set_skill("dodge",60);
	set_skill("parry",70);
	set_skill("block",60);
        set_c_limbs(({"身體","頭部","腳部","手臂"}));
	set ("tactic_func","my_tactic" );
        wield_weapon(OBJ"scale_lb");
        equip_armor(ARM"plate");
        equip_armor(ARM"shield");
        equip_armor("/d/noden/asterism/armor/leggings02.c");
}

void die()
{
	object killer;

	killer = query("last_attacker");

	tell_object( killer,
		"巴圖說道：嗯，小朋友武功不錯嘛。我去報告隊長羅。\n");
	killer->move_player("/d/noden/drow/r02","SNEAK");
	killer->set_temp("drow_certi",2);

       ::die();
}


int my_tactic()
{
	object *victim;
	int i;

	victim = (object *)this_object()->query_attackers();

	if( !victim ) return 0;
// 	if( random(20) > 1 ) return 0;

	for( i=0; i<sizeof(victim); i++ ) {
		if( (int)victim[i]->query("hit_points") < 50 ) {
		tell_object( victim[i], @LONG
忽然修凱斯隊長阻止了這場比武，並轉過頭來對你說：小朋友，回家練點功再來吧。
LONG
                );
		victim[i]->cease_all_attacks();
	victim[i]->move_player("/d/noden/drow/r02");
		return 1;
	}
    }
	return 0;
}
