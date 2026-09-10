#include "../takeda.h"

inherit MONSTER;

void create ()
{

	::create();
    set_level(17);
    set_name("Hua Rong","花榮");
    add("id",({"hua","rong"}) );
    set_short("花榮");
	set_long(@C_LONG
外號小李廣，青州人，嫉惡如仇，忠勇仗義，使一副弓箭，箭術通神，百步穿
楊，目前為梁山馬軍大驃騎兼先鋒使。他最大的嗜好是上山打獵。
C_LONG
	);
    set("alignment",400);
    set( "gender", "male" );
    set( "race", "human");
    set( "unit", "個" );
    set_perm_stat( "dex",30);
    set_perm_stat( "str",21);
    set_perm_stat( "int",20);
    set_perm_stat( "karma",20);
    set_skill("blunt",90);	
    set_skill("dodge",100);
    set ("max_hp",470);
    set ("hit_points",470);
    set ("time_to_heal",3);
    set ("wealth", ([ "gold":280]) );
    set_natural_weapon(25,15,25);
	set_natural_armor(40,22);
	set ("aim_difficulty",([ "weakest":20,"vascular":30]) );
	set("special_defense", (["magic":30,"none":10]) );
    set ("weight", 400);
    set( "inquiry", ([
             "hunt" :"@@ask_hunt1",
             "打獵" :"@@ask_hunt1",
             ]) );
    equip_armor(TARMOR"fur_hat");
    wield_weapon(TWEAPON"bow");
    equip_armor(TARMOR"mirror");
    equip_armor(TARMOR"beast_plate");
    equip_armor(TARMOR"darkgreen_cloak");
}
int ask_hunt1()
{
    command("sigh "+(string)this_player()->query("name"));
    call_out("ask_hunt2",5,this_player());
    return 1;
}
int ask_hunt2()
{
    write(@C_LONG
花榮說道: 打獵是我唯一的休閒娛樂，可是自從上次，有兩個笨蛋
在後山被一條金色的大蛇拖進那個山洞之後，山寨就再也不準大家上山
打獵了，其實，以我的功夫和箭術，一百條大蛇我也不放在眼裡。
C_LONG);
    command("snort ");
    return 1;
}           