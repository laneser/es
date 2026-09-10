#include <mudlib.h>

#define SCHOLAR_SUMMON_DIR "/d/scholar/demand/"
#define SCHOLAR_SUMMON_SKILL "demand/"
// 這些參數是隨便定的，數目一樣就可以了
#define spirits ({ "fire","water","dark","moon","wood","solid","grass" })
#define names ({ "火精靈","水精靈","黑暗精靈","月光精靈","木精靈","大地精靈","草精靈" })

#define files ({ "fire","water","dark","moon","wood","solid","grass"})
#define levels ({ 13,10,17,15,8,19,4 })
#define combat ({ 1,0,1,0,1,1,0 })
#define cost_sp ({ 13,15,17,23,8,19,6 })
#define stone ({ "ruby","sapphire","obsidian","crystal","agate","diamond","emerald"})
#define c_stone ({ "紅寶石","藍寶石","黑曜石","水晶","瑪瑙","鑽石","翡翠"})
#define need_str ({ 15,12,17,11,9,19,10 })
#define damage ({ 10,3,15,2,7,20,1 })

inherit OBJECT;
inherit DAEMON;

void create()
{
	int i;
	
	i = random(7);
	set_name(stone[i],c_stone[i]);
	set_short(stone[i],c_stone[i]);
	add( "id" , ({ stone[i] }) );
	set_long( 
		"這是一顆美麗的"+c_stone[i]+"，如果拿去店裡，應該能賣出不錯\n"
		"的價錢。不知道是怎樣的一種力量，可以造出如此美麗的寶石。\n"
	        "只有白痴才會把它隨處亂丟(throw)吧??\n"
	);
   	set("unit","顆");
   	set("no_sale",1);
   	set("weight", 20);
   	set("need_skill",(levels[i]+1)*4);
   	set("value",({ cost_sp[i]*300 , "silver" }) );
}
void init()
{
        add_action( "cmd_throw", "throw" );
}

int cmd_throw(string arg)
{
	object target,me,victim;
	string type,who,what;
	int i;

	type = this_object()->query("name");
	i = member_array(type,stone) ;
	me = this_player();
	if ( ! arg ) return notify_fail("丟什麼? 丟到那??\n");
	if( sscanf( arg, "%s to %s",what,who )==2 ) {
	if ( !(target = present( who,environment(this_player()))) )
		return notify_fail("這裡沒有叫"+who+"的東西。\n");
	if ( this_player()->query("class") != "adventurer" )
	        return notify_fail("這麼美麗的東西，你真的要把他丟掉嗎?\n");
	if ( what != stone[i] )
	        return notify_fail("你確定是丟"+what+"嗎?\n");  
	if ( ! living(target) ) { 
		write("你用力的把"+c_stone[i]+"丟向"
			+target->query("c_name")+"，除了"+c_stone[i]+"破碎以外，什麼事也沒發生。\n");
	        remove();
	        return 1;
	        }
	if ( !visible(target,this_player()) || target->query("invisible_player") )
		return notify_fail("你想拿"+c_stone[i]+"丟向誰?\n");
	if ( !this_player()->query_vision() )
		return notify_fail("這裡一片漆黑 ! 你什麼也看不到 !!\n");

	if( (int)me->query("stop_attack")>0 )
		return notify_fail (
			"( 你上一個動作還沒有完成，無法動作。 )\n");

	if( me->query_temp("aim_busy") )
    	  return notify_fail("你目前正忙著瞄準你的目標，沒空作別的事情。\n"); 

	if ( (int)me->query("spell_points") < cost_sp[i] ) {
	  write("你的精神狀況不足以使你瞄準目標。\n");
	  return 1;
	}
        me->add("spell_points",-cost_sp[i]);
        tell_object(me,set_color("你集中精神開始注意"+target->query("c_name")+"的一舉一動。\n","HIR"));
        me->set_temp("aim_busy",1);
        call_out("check_demand",1,me,target,i);
        return 1;
        }
        return notify_fail("丟什麼? 丟到那??\n");
} 
void check_demand(object me,object target,int i)
{
  object mob;

  me->delete_temp("aim_busy");
        if( environment(me)->query("no_summon")) {
        write("你用力的把這顆"+c_stone[i]+"丟出去，但除了清脆的破碎聲外，什麼事都沒發生。\n");
        remove();
        return ;
        }
    if ( (int)me->query_perm_stat("str") < need_str[i]) {
    write("你把"+c_stone[i]+"丟出去，但是什麼都沒發生，你趕快把它撿回來。\n");
    me->set("stop_attack",3);
    return ;
  }
    
    if ( !combat[i] && target->query_attacker()) {
	write("你把"+c_stone[i]+"丟出去，但除了清脆的破碎聲外，什麼都沒發生\n");
        remove();
        return ;
        }
        if ( combat[i] && !target->query_attacker()) {
        write("你把"+c_stone[i]+"丟出去，但除了清脆的破碎聲外，什麼都沒發生\n");  
        remove();
        return ;
        }
  else {
    seteuid(getuid());
    write("你把"+c_stone[i]+"丟向"+target->query("c_name")+"，一聲清脆的破碎"
          "聲後，一個"+names[i]+"從碎片中出現......\n");
    mob = new("/d/scholar/demand/spirit/"+files[i]);
// 去除與戰鬥無關的設定
    mob->set_perm_stat("str",random((int)me->query_perm_stat("str")*2/3)+levels[i]);
//    mob->set_perm_stat("int",random((int)me->query_perm_stat("int")*2/3)+levels[i]);
    mob->set_perm_stat("kar",random((int)me->query_perm_stat("kar")*2/3)+levels[i]);
//    mob->set_perm_stat("con",random((int)me->query_perm_stat("con")*2/3)+levels[i]);
    mob->set_perm_stat("dex",random((int)me->query_perm_stat("dex")*2/3)+levels[i]);
//    mob->set_perm_stat("pie",random((int)me->query_perm_stat("pie")*2/3)+levels[i]);
    mob->set_natural_weapon((int)me->query("weapon_class1")+levels[i],levels[i],(int)me->query("max_damage1")*3/5+levels[i]);
//    mob->set_temp("extra_ac",(int)me->query("armor_class")+levels[i]);
//    mob->set_temp("extra_db",(int)me->query("defense_bonus")+levels[i]);
    mob->set_skill("unarmed",100);
//    mob->set("max_hp","@@quer2y_max_hp");
//    mob->set("hit_points","@@query_max_hp");
    mob->set_temp("master",target);
    mob->my_action(target);
    target->receive_damage(damage[i]);
    remove();
    return;
  }
}

