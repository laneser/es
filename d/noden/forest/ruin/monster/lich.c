// Modified by Yueh to let lich teach magic, in 1995/3/8
#include "/d/noden/forest/ruin/ruin.h"
inherit MONSTER;
#define STATS_D                 "/adm/daemons/statsd"
#define life_damage 30
#define auto_heal 20
void create ()
{
	::create();
	seteuid( getuid() );
	set_level(18);
	set_name( "Lich", "黑魔" );
	add ("id", ({ "lich", "mage", }) );
	set_short( "冥黑魔導士 黑魔" );
	set_long( @C_LONG
邪惡的冥黑魔導士為了使自己的永生，而對自己施與黑暗魔法。肉體均已腐爛，
全身覆蓋著黑衣，擁有再生的能力，能使用可怕黑魔法的骸骨。
C_LONG
	);
	set( "alignment", -8000 );
    set( "gender", "male" );
    set( "race", "undead" );
    set( "unit", "個" );
	set_perm_stat( "dex", 27 );
	set_perm_stat( "str", 15 );
	set_perm_stat( "int", 30 );
	set_perm_stat( "con", 14 );
	set_perm_stat( "piety", 1 );
	set_perm_stat( "karma", 20 );
	set ("max_hp", 1000);
	set ("max_sp", 2500);
	set ("hit_points", 1000);
	set ("spell_points", 2500);
	set ("wealth", ([ "gold": 10 ]) );
	set_natural_weapon( 33, 21, 32 );
	set_natural_armor( 87, 50 );
	set ("time_to_heal", 2);
	set ("unbleeding", 1);
	set ("aim_difficulty", ([ "critical":80, "weakest":100, "ganglion":100, ]) );
	set ("special_defense", ([ "all":90, "fire":45, "none":70 ]) );
    set ("weight", 400);
    set ("exp_reward",32590 );
    set_experience(950000);
    set ("tactic_func", "cast_spell");
    set_skill("wand",100);
    set_skill("dodge",70);
    set_skill("black-magic",100);
    set_skill("elemental",100);
    set_skill("target",100);
    set_skill("concentrate",100);
    set("magic_delay", 1);
    set("spells/sleet",3);
    set("spells/lightning",5);
    set("spells/ether-bolt",8);
    set("c_death_msg","%s的身體開始粉碎... 終至消失。\n");
    
    wield_weapon(OBJ"thunder_wand");
    equip_armor(OBJ"black_cloak");
    set( "inquiry", ([
                "magic" : "@@ask_magic"
        ]) );
}

int cast_spell()
{// 40% call demon -> 60% little 40% great and continue attack.
 // if( hp < 100 ) -> 100% 再生 hp add 20-40 and continue attack.
 // if( hp < 300 ) -> 25% steal life force, damage 30-40 stop.
 // else 40% cast spell -> 70% sleet 3,  21% ether-bolt 8, 9% lightning 5.
 //      60% normal attack.
    object victim, monster;
    int damage;
    victim = query_attacker();
    if( !victim ) return 0;
    if( (int)this_object()->query("spell_points") < 500 )
      this_object()->set("spell_points", 2500);
    if( (random(10)<4) && !present("daemon", environment(this_object())) ) {
      if( random(10) < 6 ) {
        tell_room( environment(this_object()),
          "黑魔呼喚出小惡魔來幫他攻擊。\n" );
        monster = new(MOB"little_demon");
      } else {
        tell_room( environment(this_object()),
          "黑魔呼喚出大惡魔來幫他攻擊。\n");
        monster = new(MOB"great_demon");
      }
      monster->move(environment(this_object()));
      monster->kill_ob(victim);
    }
    
    if( (this_object()->query("hit_points")<100) ) {
      tell_room( environment(victim),
        "黑魔的身體再生又復原了。\n");
      this_object()->receive_heal( auto_heal+random(auto_heal) );
    }
    
    if( (this_object()->query("hit_points")<300) && (random(20)<5) ) {
      tell_object( victim, "黑魔吸取你的生命力，你感覺有點虛脫。\n");
      tell_room( environment(victim), 
        "你看到一股無形的氣體從"+victim->query("c_name")+
        "飄至黑魔身上，\n黑魔的身體又復原了。\n" ,
        victim);
      damage = life_damage + random(10);
      victim->receive_special_damage("life", damage, 1);
      this_object()->receive_heal( damage );
      return 1;
    }
    
    if( random(10) < 4 ) return 0;
    
    if( random(10) < 7 )
      command("cast sleet on "+victim->query("name"));
    else if( random(10) < 7 )
      command("cast ether-bolt on "+victim->query("name"));
    else 
      command("cast lightning on "+victim->query("name"));
    return 1;
}

void die()
{
	object killer;

	if( killer = query("last_attacker") ) killer->set_explore("noden#23");
	::die();
}

void kick_out( object obj )
{
     tell_object( obj, "黑魔一腳把你踢了出去。\n"  );
     tell_room( environment(obj), "黑魔一腳把" + obj->query("c_name") + "踢了出去。\n" ,obj);
     obj->move_player(RUIN"tunnel_4", "你看到"+obj->query("c_cap_name")+"飛了出來，摔了四腳朝天。", "" );
}

void ask_magic(object who)
{
	int ali;
	string class1;
	class1 = (string)who->query("class");
	if( !class1 ) class1 = "adventurer";
	ali = (int) who->query("alignment");
	if ( class1 != "mage") {
	printf("黑魔說：%s也想跟我學魔法，沒有殺你就不錯了。\n",to_chinese(class1));
	kick_out(who);
	}
	else 
	if (ali > -200) {
		printf("黑魔說：%s的人也想跟我學魔法，沒有殺你就不錯了。\n", STATS_D->alignment_string(ali));
	kick_out(who);
	}
	else
	if ((int) who->query_quest_level("wanfu") < 1)
	tell_object(who,"黑魔說：要向我學魔法，你要先證明你自己的能力，去幫王虎的忙吧！\n");
     else {
         tell_object(who,
	"黑魔說道: 歡迎加入黑暗的勢力，黑暗的勢力是一個弱肉\n"
	"強食的殘酷世界。不但要對抗光明的勢力，躲避雷神的攻\n"
	"擊，還要接受來自黑暗勢力內部的挑戰，如果輸了，不是\n"
	"臣服，就是死亡。\n\n"
	"黑魔繼續說：黑暗的魔法，是召喚黑暗的力量，只有邪惡\n"
	"的人才可以施展，而且愈邪惡的人可以召喚到比較強大的\n"
	"力量。以下是我可以教給你的黑暗魔法：\n\n"
	"絞心術：呼喚黑暗的力量直接攻擊敵人的心臟，使敵人內\n"
	"        部受到傷害。但是如果敵人比你邪惡，召喚來的\n"
	"        力量反而會攻擊你。\n\n"
	"魔法護心盾：呼喚黑暗的力量來防止絞心術的攻擊，在面\n"
	"        對其它黑暗勢力的挑戰時，可以給你很大的幫助\n"
	"        。但是這個魔法卻會加強光明勢力中神聖系的魔\n"
	"        法，使用時要小心。\n\n"
	
	"黑魔繼續說：你可以學的魔法等級看索引(index)。\n\n"
         );
     }
}

