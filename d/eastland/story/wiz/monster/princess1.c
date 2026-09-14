#include "../../story.h"
inherit MONSTER;
void create ()
{
	::create();
	set_level(17);
	set_name( "Iorn-fan princess", "鐵扇公主" );
	add ("id", ({ "princess"}) );
	set_short( "鐵扇公主");
	set_long(@CLONG
鐵扇公主生得細眉鳳目，粉面朱唇，兩耳垂珠，鼻似瓊瑤，頭挽雙髻。身穿著一紅
緞地彩繡肚兜，頸戴琉璃珠項鍊，赤足不襪，又白又嫩，看去玉人也似。又見她稚
氣天真，面上常掛笑容，形成兩個小酒渦，看去不過十來歲光景，她也是巫羅王最
愛的掌上明珠。
CLONG
	);
        set("age",10);
        set( "forgetful",1);
	set("race","human");
	set("gender","female");
        set_perm_stat("str",23);
        set_perm_stat("dex",22);
        set_perm_stat("int",23);
        set("hit_points",550);
        set("max_hp",550);
        set("max_fp",300);
	set( "alignment", 500 );
	set_natural_weapon( 43, 22, 33 );
	set_natural_armor( 55, 26 );
        set("wealth/gold",50);
        set("stun_difficulty",100);
        set_skill("parry",70);
        set_skill("dodge",70);
        set_skill("blunt",70);
        set("tactic_func","my_tactic");
        wield_weapon(SWWEA"p_fan1");
        equip_armor(SWARM"p_amulet1");
        equip_armor(SWARM"p_cloth1");
        set("special_defense", ([ "all": 50,"none":30]) );
        set("aim_difficulty",
            (["critical":65,"vascular":40,"ganglion":70,"weakest":65]) );
}
int my_tactic()
{
    object victim;
    string name;
    
    if ( !victim=query_attacker() ) return 0;
    if(random(17)>1) return 0;
    name=victim->query("c_name");
    tell_object(victim,"\n只見鐵扇公主手中的芭蕉扇發出狂巨響，隨即你猶如一顆流星，飛出殿外～～\n\n");
    tell_room(environment(victim),sprintf(
      "\n只見鐵扇公主手中的芭蕉扇發出狂風巨響，%s那臃腫的身體隨即飛出殿外猶如一顆流星，咻咻咻～竟不知要飛往那裡～～～\n\n",name),victim);
    victim->move_player(SCITY"ice1","SNEAK");
    tell_object(victim,"\n咦，這是那裡啊？\n\n");
    tell_room(environment(victim),sprintf(
        "%s忽然從高空中摔下來，掉在你腳邊～～\n",name),victim);
    victim->receive_damage(30);
    return 1;
}
