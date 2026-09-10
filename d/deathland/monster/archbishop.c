#include "../echobomber.h"

inherit Echo+"/magic";
inherit MONSTER;

void create ()
{

	::create();
	seteuid( getuid() );
    set_level(19);
    set_name("archbishop Desyer","大主教底斯宜爾");
    add("id",({"dwarf","bishop","desyer"}) );
    set_short("Archbishop Desyer","大主教底斯宜爾");
	set_long(
@C_LONG
矮人大主教,他正在祈禱.你無法猜測他的年紀,因為他有一股迷人的風采及滿頭的
白髮,除此之外他的口才也是一流的.每次他在傳道的時候,教堂總是充滿了人潮.
C_LONG
	);
    set("weapon_master",1);
    set("alignment",1000);
    set( "gender", "male" );
    set( "race", "dwarf");
    set( "unit", "個" );
    set_perm_stat( "dex",19);
    set_perm_stat( "str",18);
    set_perm_stat( "int",28);
    set_perm_stat( "con",20);
    set_perm_stat( "piety",27);
    set_perm_stat( "karma",26);
	
    set ("max_hp",690);
    set ("max_sp",630);
    set ("hit_points",690);
    set("spell_points",630);
    set ("wealth", ([ "gold":3]) );
    set_natural_weapon(30,18,30);
	set_natural_armor(70,48);
	set ("aim_difficulty",([ "critical":33,"vascular":38]) );
        set("special_defense", (["all":45,"none":70,"monk":20,"scholar":20]) );
    set ("weight", 440);
    equip_armor(Armour"/cloth02");
    wield_weapon(Weapon"/blackmace");
    equip_armor(Armour"/cloak01");
    equip_armor(Armour"/amulet02");
    equip_armor(Armour"/ring01");
    set( "inquiry", ([
         "yang" : "@@ask_yang",
         "lucksis" : "@@ask_lucksis",
         ]) );
    set( "tactic_func", "cast_spell");
}

void ask_yang(object who)
{
     tell_object( who , @MSG1
   傳說中的惡神 Evil Yang,一個擁有無上法力的神. 根據古老的傳說他為了
能夠超越世上所有的神,而自己封閉於黑暗的深淵之中.
MSG1
       ); 
}

void ask_lucksis(object who)
{
     if (!(who->query_temp("lucksis_quest")) || (int)(who->query_temp("lucksis_quest/ask"))==0 ) 
       tell_object(who,"底斯宜爾繼續他的祈禱而不理會你\n"
                       );
     else
       {
         tell_object(who,@MSG2
底斯宜爾說:你是拉克希絲派來的?
我想我幾乎忘了她是誰,因為我是 Yang 的使者.
我的職責就是幫助 Yang 的 信徒.
底斯宜爾微笑的看著你說:要跟我一起祈禱嗎?


你想底斯宜爾是神職人員,所以如果建議拉克希絲和他在一起可能會
造成一悲劇.
MSG2
                    );
         who->set_temp("lucksis_quest/desyer",1);             
       }
     return;
}

int cast_spell()
{
    object victim;
    string name,c_name;
    if( !(victim = query_attacker()) ) return 0;
    
    name = victim->query("name");
    c_name= victim->query("c_name");
    
    if( random(10) < 3 ) {
      tell_room( environment(this_object()), 
        sprintf("大主教底斯宜爾大叫 : Yang 將摧毀你的靈魂\n\n一道強光忽然刺入%s的身體□.\n\n",c_name) );
      victim->receive_special_damage("divide", 40+random(25));
      report(this_object(),victim);
      return 1;
    }
   if(  random(10) < 3 && victim->query_temp("cast_busy") ) {
        tell_object(victim,
               "大主教發現你正使用魔法,於是開始施展吸魂魔法\n"
               );
        tell_room(environment(this_object()),
          sprintf("大主教底斯宜爾的魔法正毀滅%s的靈魂\n" ,c_name));
        victim->receive_damage(90-(int)(victim->query_stat("kar")));  
        report(this_object(),victim);
        return 1;
    }
    return 0;
}

