//#pragma save_binary
//   create by Indra@Eastern_Story
//
//  導引術(即氣功\) , 由spellpower 改成..
//  
#include <mudlib.h>
#include "/d/healer/healer.h"

inherit DAEMON;

int help();
string int_to_str(int arg) ;

int remove_block(object obj)
{
   obj->delete_temp("block_command") ;
   return 1 ;
}

int cmd_douin(string str)
{
    int eff_lv,eff_no,sp_cost,skill,needed ;
    string type,who,temp,*acu_pts,eff_file;
    object target,me ;

	skill = this_player()->query("dou-in") ;         
        if(!skill)
           return notify_fail("你還沒練過氣功, 不知道導氣的方法。\n") ; 

        temp = int_to_str(skill) ;

        if( !str ) 
          {
             write(sprintf("你的氣功目前練到%s。\n",temp)) ;
             return 1 ; 
           }
           
        if( (int)this_player()->query("stop_attack")>0 )
             return notify_fail (
                "( 你上一個動作還沒有完成，無法專心運氣。 )\n" );
        
                                                    
	if( sscanf( str, "%s on %s", type,who )==2 ) 
	        {  
	           who = lower_case(who) ;
	           if(who=="me") target = this_player() ;
	           else if(!target=present(who,environment(this_player()) ))
                          {
	                     write("你想導誰的氣 ?\n") ;
                             return 1 ;
                           }   
	         }
	else if( sscanf( str, "%s", type )==1 ) target = this_player() ;
 
        me = this_player() ;       
        if(!( !(me->query_current_attacker()) ))
                return notify_fail("你還在戰鬥中,沒時間停下來聚氣。\n");
         
	if( !me->query("vision") )
      		return notify_fail("你看不見目標，沒辦法導氣 !!\n"); 
	
	if( me->query("weapon1") && ( me->query("weapon2") ||
	     me->query("armor/shield") ) )
	    return notify_fail( "你沒有多餘的手來導氣 !!\n" );

        if( me->query_temp("no_concentrate"))
            return notify_fail("你的注意力還不能集中,無法專心。\n") ;

        if(!( !(target->query_current_attacker()) ))
                return notify_fail("你的目標還在戰鬥中,沒時間停下來讓你導氣。\n");
       
        switch(type)
               {
                 case "ultra"   : eff_lv = 7; break;               
                 case "super"   : eff_lv = 6; break;
		 case "max"     : eff_lv = 5; break;
		 case "regular" : eff_lv = 4; break;
		 case "normal"  : eff_lv = 3; break;
		 case "minor"   : eff_lv = 2; break;
		 case "mini"    : eff_lv = 1; break;
		 default : return help();
		}
	

        acu_pts = target->query_temp("acupuncted_pts") ;
        if(!(acu_pts)) return notify_fail
            ("光導氣,不施針是看不出什麼效果的。\n") ;
     
        eff_no  = USE_POINTS->check_allwork(acu_pts) ;
        if(eff_no!=0)
          {  
             eff_file = USE_POINTS->query_eff_file(eff_no) ; 
        
             if( file_size( eff_file + ".c" ) == -1 )
               return notify_fail("針灸中的效果部份檔案受損,請與巫師連繫。\n") ;
           }
        else
          {
             sp_cost = eff_lv*20 ;
             if((int)this_player()->query("spell_points")<sp_cost)
                  return notify_fail("你現有的精神不足以送出這麼強的氣。");

             this_player()->set_temp("block_command",1) ;
             this_player()->receive_damage(eff_lv*10) ;
             this_player()->add("spell_points",-sp_cost) ;
             this_player()->block_attack(3) ;
             me->set_temp("msg_stop_attack","你覺得全身劇痛,無法動彈。\n" ) ;
             target->receive_damage(eff_lv*3) ;             
             target->delete_temp("acupuncted_pts") ;
             
             tell_object( target,
                "你覺得體內的血氣開始快速流動，但是突然你全身開始劇痛....。\n"
                ) ;
                
             tell_room( environment(target),
                        sprintf("%s的臉開始發紅, 紅得像是要滲出血來了。\n"
                       ,target->query("c_name")),target );
            
             tell_object( this_player(),
                "你突然發現對方血氣向你激湯過來,當你想收手已經來不及....。\n"
                     );
             call_out("remove_block",5,this_player()) ;
             return 1 ;                          
          }    
        if(eff_lv>skill)
           return notify_fail("你現在的氣功只學到"+ temp +"。 \n"+
                              "強要用更高層的氣, 對你只是有害無益\n") ;
           
        sp_cost = eff_file->query_sp_cost(eff_lv,skill) ;
        if((int)this_player()->query("spell_points")<sp_cost)
           return notify_fail("你現有的精神不足以送出這麼強的氣。") ;
        
        needed = eff_file->query_need_level() ;
        if(!needed) return notify_fail("效果部份檔案損壞。\n") ;
                 
        if( needed > eff_lv)
           {
              temp = int_to_str(needed) ;
              return notify_fail("要發揮效果,至少須要"+temp+"的氣功。\n");
           }         
        this_player()->add("spell_points", -sp_cost );
        this_player()->gain_experience( eff_lv * 10 ) ;
        eff_file->acu_effect(eff_lv,target) ;

	return 1;
}

string int_to_str(int arg)
{
      string temp ;     
      switch(arg)
            {
              case 1 : temp = "第二層"; break ;
              case 2 : temp = "第四層"; break ;                
              case 3 : temp = "第六層"; break ;              
              case 4 : temp = "第八層"; break ;
              case 5 : temp = "第十層"; break ;
              case 6 : temp = "第十二層"; break ;              
              case 7 : temp = "第十四層"; break ;
              default: temp = "五脈俱斷,不遠人世" ;
            }
      return temp ; 
}

int help()
{
		write( @C_HELP
指令格式: douin [出力] on [玩家]

  氣是無所不在的能量, 醫生能以針灸配合氣功為人們療傷治病, 甚或
在短時間增強人的某些能力。在確定下針的穴道都正確後, 便可以施以
導引術來增快氣的流動, 使得針灸的效果能在最短的時間內顯現出來。
而氣導出的量可以設定為 max, regular, normal, minor, mini  五種
一般而言, 量越大則耗時越久, 消耗的精神力也越多, 然而其效果也越
好。
    直接打douin 可以知道你現在所學過,而能使用的最大出力。
C_HELP
		);
    return 1;
}

