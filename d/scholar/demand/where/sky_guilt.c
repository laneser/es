#include "../almuhara.h"

inherit MONSTER;

void create ()
{
	::create();
	seteuid( getuid() );
	set_level(19);
	set_name( "Sky Guilt", "『 天罪 』" );
	add ("id", ({ "sword","sky guilt","sky","guilt" }) );
	set_short( "『 天罪 』" );
	set_long( 
@C_LONG
這是『 天罪 』。一隻由上古神兵在吸取了這兒天地之靈氣所幻化成的奇獸。從它
身上散發出的邪氣，令你不寒而慄。
C_LONG
	);
	set( "alignment", -5000 );
        set( "unit", "把" );
	set_perm_stat( "dex", 25 );
	set_perm_stat( "str", 30 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 27 );
	set_perm_stat( "piety", 10 );
	set_perm_stat( "karma", 25 );
	set ("chat_chance", 5);
	set ("max_hp", 1600);
	set ("hit_points", 1600);
	set ("killer", 1);
	set("stun_difficulty/ma",40) ;
	set("aim_difficulty",(["critical":100,"weakest":80,
                               "vascular":60,"ganglion":80 ])) ;
	set_natural_weapon( 90, 40, 80 );
	set_natural_armor( 120, 50 );
    set ("weight", 150);
    set ("exp_reward", 32767 );
    set ("special_defense", 
         ([ "all":60, "none":50, "fire":"20", "cold":"30" ]) );
    set_skill("tactic",100);
    set_skill("dodge",100);
    set_skill("parry",100);
    set("tactic","assault");
    set_c_verbs( ({ "%s直刺%s", "%s橫斬%s","%s斜挑%s"}) );
    set_c_limbs( ({ "劍刃", "劍鋒","劍柄" }) );
    set( "alt_corpse", WEAPONS"/d_sky_guilt" );
    set( "c_death_msg", "%s發出一聲淒厲的悲嚎，化回原形。\n");
    set( "att_chat_output", ({
		"『天罪』狂笑說道: 放我出來就是你的死期到了!!\n",
	        "天罪冷冷地看著你。\n", }) );
}

void die()
{
	object ob;
	
	ob = query("last_attacker");
	ob->set_temp("GUILT",1);
        if ((string)ob->query("class")=="scholar") {
          tell_object(ob,set_color(
 "突然這個房間的劍氣凝成一人形：謝謝你把這邪惡的天罪給除去，我是在這裡修煉\n的劍魂，由於天罪的關係，我都不能好好的在這裡修煉，總而言之，假如須要我的幫忙，\n請不要客氣。\n"
          ,"HIW"));
          ob->set("demand/sword",2);
        }
	::die();
}
