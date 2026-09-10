//#pragma save_binary

#include <mudlib.h>
#include "/d/healer/healer.h"

inherit GUILD_OB;
inherit OBJECT;

void create()
{
	seteuid( getuid() );
	guild_ob::create();
	set( "extra_look", "@@query_extra_look");
	set_class_name("healer");
	set("short","銀針");	
#include <compress_obj.h>
	set_name("needle", "銀針");
	set_long( @LONG
這是一根細小的銀針，行醫者用來替人針灸治病，雖然它看起來
很脆弱，但是到了一個經驗豐富的行醫者手中，就會變成一個救
人或殺人的利器。如果你要知道有關銀針與行醫者的詳細用途，
可以用 help needle 指令。
LONG
	);

	set( "unit", "根" );
	set( "weight", 1 );
	set( "skills_effect", "lawful_only" );
	set( "bandage_reward_func", "bandage_reward" );

}

int help_bbpower();

string query_extra_look()
{
  string msg;
  int op_succ_count; 
  int op_fail_count;
  
  if (!op_succ_count=environment()->query("op_succ_count")) op_succ_count=0;
  if (!op_fail_count=environment()->query("op_fail_count")) op_fail_count=0;
  msg ="$N身上帶著行醫者用來替人針灸治病的銀針。\n";
  if ( op_succ_count==0 && op_fail_count==0 ) msg += "$N還不曾替人動過手術。\n";
  else if ( op_fail_count == 0 ) 
       msg += "$N這一輩子曾替人動過"+chinese_number(op_succ_count)+"次手術, 而且完全成功了。\n";
  else if ( op_succ_count == 0 )
       msg += "$N顯然是個大庸醫....替"+chinese_number(op_fail_count)+"個人動過手術, 結果全部死光了。\n"; 
  else msg += "$N曾替人動過"+chinese_number(op_succ_count+op_fail_count)+"次手術, 其中有"+ 
              chinese_number(op_succ_count)+"次是成功的。\n";
  return msg;
}  

void init()
{
	// Apply guild_ob checks
	guild_ob::init();

	add_action("help", "help");
	add_action("info", "info");
	add_action("do_healers", "healers");
	add_action("do_chat", "healer");
    	add_action("do_list_meridian","meridian") ;
	add_action("do_bandage_power", "bbpower");
}

int do_healers()
{
	return guild_ob::list_guild_members();
}

// The guild channel
int do_chat(string arg)
{
	if( !arg )
		return notify_fail( "你想對其它行醫者說什麼？\n");
	return guild_ob::guild_line(arg);
}

int do_bandage_power(string level)
{
    object p;
    int effect, ali, orig;

    p = this_player();
    if (p->query_temp("acup_effect/potential") == 1)
	return notify_fail("潛能激發的狀態下，無法正確調整包紮出力。\n");

    switch (level)
    {
	case "max": p->set("bandage_power", 1);
		    break;
        case "regular": p->set("bandage_power", 0.8);
                    break;
        case "normal": p->set("bandage_power", 0.6);
                    break;
        case "minor": p->set("bandage_power", 0.4);
                    break;
        case "mini": p->set("bandage_power", 0.2);
                    break;
	default:
		help_bbpower();
		return 1;
    }
    write("Ok.\n");
    orig = p->query_skill("bandage");
    effect = p->query_perm_skill("bandage");
    ali = p->query("alignment");
    if (ali < -400) effect += effect * ((ali<(-10000)?-10000:ali)+400) / 32000;
    effect = to_int(effect * (float)p->query("bandage_power")) - orig;
    p->modify_skill("bandage", effect);
    return 1;
}

int lawful_only(object me, string skill_name, int effect)
{
	// Changed by Lilia@ES Apr. 12, 1996

	int ali;
	
	ali = (int)me->query("alignment");
	if( ali < -400 )
	{
	    switch(skill_name)
	    {
		case "bandage":
		case "operation":
		case "first-aid":
		case "clotting":
		    effect += effect * ((ali<(-10000)?-10000:ali)+400) / 32000;
		    break;
		default: break;
	    }
	}
	if (me->query("bandage_power") && skill_name == "bandage")
	    effect = to_int(effect * (float)me->query("bandage_power"));
	return effect;
}

// the reward function when a healer bandage others.
void bandage_reward(object me, object dest)
{
	int skill, hp, max_hp, exp, dest_ali;
	
	max_hp = (int)dest->query("max_hp");
	hp = (int)dest->query("hit_points");
	skill = (int)me->query_skill("bandage", 1);
	dest_ali = (int)dest->query("alignment");

	if( dest_ali > 0 ) {
		me->add("alignment", 1);
		me->gain_experience( skill*(max_hp-hp)/max_hp );
	} else {
		me->add("alignment", dest_ali/100);
		me->gain_experience(1);
	}
	return;
}

int info(string arg)
{
	switch(arg) {
		case "history"  : cat( GUILD_DATA"c_healer_history" ); break;
		case "commands" : cat( GUILD_DATA"c_healer_commands" ); break;
		case "skills"   : cat( GUILD_DATA"c_healer_skills" ); break;
		case "topics"   :
		default: 
				cat( GUILD_DATA"c_topics");
			break;
	}
	return 1;
}

int help(string arg)
{
      if (arg == "bbpower") { help_bbpower(); return 1; }
      if( !arg || arg!="needle" ) return 0;
      cat( GUILD_DATA"c_needle");
      return 1;
}

int do_list_meridian()
{
      int i ,lenth; 
      string *temp ;
      mapping learned ;
  
      learned = this_player()->query("prac_meridians") ;
      if(!learned) 
          return notify_fail("你現在對每個穴道都不熟悉。\n") ;

      temp = keys(learned) ;      
      lenth = sizeof(temp) ;

      write(sprintf("你現在能掌握的經絡共有%d個。分別為：\n",lenth) ) ;
      for( i=0 ; i<lenth ; i++)
         {
           write(temp[i]+"。\n") ; 
         }
      return 1 ;           
}

int help_bbpower()
{
    cat(GUILD_DATA"c_bbpower");
    return 1;
}
