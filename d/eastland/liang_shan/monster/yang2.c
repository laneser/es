#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(18);
    set_name("Yang Zhi","楊志");
    add("id",({"yang","zhi"}) );
    set_short("楊志");
	set_long(@C_LONG
外號青面獸，關西人，五侯楊老令公之孫。忠實老練，行事不□。十八般
武藝，樣樣俱精，目前為梁山馬軍大驃騎兼先鋒使。他現在正奉公孫先生的
命令(order)把守通往後山的要道。
C_LONG
	);
    set("alignment",100);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "個" );
    set_perm_stat( "dex",25);
    set_perm_stat( "str",23);
    set_perm_stat( "int",18);
    set_perm_stat( "karma",24);
    set_skill("thrusting",90);	
    set_skill("parry",90);
    set_skill("tactic",95);
    set ("max_hp",550);
    set ("hit_points",550);
    set ("time_to_heal",3);
    set ("wealth", ([ "gold":280]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(45,25);
	set ("aim_difficulty",([ "weakest":40,"vascular":40]) );
	set("special_defense", (["magic":35,"none":20]) );
    set ("weight", 400);
    set( "inquiry", ([
                    "order" :"這是公孫先生的命令，我只負責執行\n"
                    "不要問我為什麼....\n" ,
                    "why" : "叫你別問你還問，小心我K 你喔...\n",
                    "prism" : "這道鐵柵是用來防止閒人進入的，以前鐵柵後面的森林\n"
                    "曾經是非常好的獵場.....\n",
                    "hunt" : "打獵的事情，你最好去找老花，他最喜歡打獵了...\n",
                    "獵場" : "打獵的事情，你最好去找老花，他最喜歡打獵了...\n",
                    "打獵" : "打獵的事情，你最好去找老花，他最喜歡打獵了...\n",
                    ]) );
    equip_armor(TARMOR"lion_helmet");
    wield_weapon(TWEAPON"ironlance");
    equip_armor(TARMOR"floral_cloak");
    equip_armor(TARMOR"mirror");
    equip_armor(TARMOR"bear_cloth");
}

