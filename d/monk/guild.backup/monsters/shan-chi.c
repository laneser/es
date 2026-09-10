#include <mudlib.h>

inherit MONSTER;

void create()
{
        ::create();
        set_level(19);
        set_name( "Shan chi", "玄慈神僧" );
        add ("id", ({ "monk","shan","chi" }) );
        set_short( "Shan chi","玄慈神僧");
        set("unit","位");
        set_long("",@C_LONG
玄慈是少林寺僅存數位玄字輩的長老之一，也是前兩任的方丈。他年
輕的時候喜歡習武，所練就的九陽神功和易筋經至今仍然傲視武林。但是
他現在已經不問世事了，除了偶爾少林寺遇到重大變故的時候會出面解危
以外，平時都負責指導少林公會。
C_LONG
        );
        set("exp_reward",50000);
        set("alignment",2000);
        set("wealth/silver",100);
        set("gender","male");
        set("race","human");
        set("tactic_func","special_attack");
        set("hit_points",2000);
        set("force_points",2500);
        set("max_hp",2000);
        set("max_fp",2500);
        set_perm_stat("str",30);
        set_perm_stat("dex",26);
        set_perm_stat("pie",30);
        set_perm_stat("kar",24);
        set_perm_stat("con",29);
        set_perm_stat("int",25);
        set_natural_weapon(35, 14, 30);
        set_natural_armor(90, 30);
        set_skill("dodge",100);
        set_skill("blunt",100);
        set_skill("parry",100);
        set_skill("inner-force",100);
        wield_weapon("/d/monk/guild/weapons/kingkong_staff");
        equip_armor("/d/monk/guild/armors/sandal_beads");
        equip_armor("/d/monk/guild/armors/damo_plate");
        equip_armor("/d/monk/guild/armors/god_armband");
        equip_armor("/d/monk/guild/armors/holy_ring");
        equip_armor("/d/monk/guild/armors/cloud_boots");
}

int special_attack()
{
    object victim;
    int fp;
    
    if(random(20)>7) return 0;
    victim = query_attacker();
    if( !victim ) return 0;
    fp=(int)victim->query("force_points");
    tell_room(environment(victim),({" ",
"\n玄慈運起九陽神功\，一道渾厚的內力自丹田湧向雙手，向"+
(string)victim->query("c_name")+"直衝而去。\n"}),victim
	);
    tell_object(victim,can_read_chinese(victim)?@C_LONG
    
玄慈運起九陽神功\，霎時你被一股強大的內力籠罩著。突然這股勁力直衝
你的丹田，你覺得你的經脈似乎已經斷了。

C_LONG
        :" "
    );
    victim->receive_damage(60-random(fp/10));
    return 1;
}
