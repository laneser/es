////#pragma save_binary
// acupunct.c
// 
// This is acupunct founction for chinese healers
// monsters can't use this command
// and players can only use this command on other players
// players can only be acupuncted when 
//     he placed himself in relax situation 
// create by Indra@Eastern_Story on 11.28.93
//

#include <mudlib.h>
#include "/d/healer/healer.h"
#define CHECK_USE "/d/healer/acupuncture/use_points"
#define CHECK_ALL "/d/healer/acupuncture/points"
#define part ({"不明部位","頭部","頸部","胸前","腹部","腰部","背部","手上","腿部"})

inherit DAEMON ;

int help() ;

//  this func is to check if the point have been acupuncture
//
int check_repeat(string tar_pt,string *acup_pts)
{
     if( member_array(tar_pt,acup_pts) != -1 ) return 0 ;     
     return 1 ;        
}
int remove_block(object obj)
{
    obj->delete_temp("block_command") ;
    return 1 ;
}
//
//  to do acupuncture
//
int do_acupuncture(string tar_point,object target)
{
       int dam,i,acu_sk,con_sk,my_dex,tar_con,tar_dex,living_flag,*result;
       string point,tar_name,part_name,*acuped,my_name;
       mapping learned_merid ;
       object me ;
       
       me = this_player() ;
       my_name = me->query("c_name") ;
 
       acu_sk = me->query_skill("acupuncture") ;
       con_sk = me->query_skill("concentrate") ;
       tar_name = target->query("c_name") ;  
       tar_con = target->query_perm_stat("con") ;
       tar_dex = target->query_perm_stat("dex") ;
       my_dex  = me->query_perm_stat("dex") ;
       if(acu_sk>100) acu_sk = 100 ;
       if(con_sk>100) con_sk = 100 ;

       living_flag = living(target) ;

       learned_merid = me->query("prac_meridians") ;
       if(!learned_merid) learned_merid = ([ ]) ; 

       result = CHECK_USE->do_check(tar_point,keys(learned_merid)) ;
       
       if( result[1] == -1 )
          {
           write("你沒練習過這條經絡,沒法肯定正確的位置,不敢下針。\n") ; 
           return 1 ;
           }  
       if( (result[0]==1) && (living_flag) )
         {
           part_name = part[result[1]] ;                  
           dam = "/d/healer/acupuncture/fatal"->damage(me,target,tar_point,part_name) ;

          write("damage is  :"+ dam +" this time\n") ;
           if(dam != -1) target->receive_damage(dam) ;
           
           return 1 ;
        }

// 不是死穴也不是有效穴, 到全表找

        if( result[0] == 0 )
            result = CHECK_ALL->do_check(tar_point) ;

       if( result[1] == -1 )
           return notify_fail("你沒練習過這條經絡,沒法肯定正確的位置,不敢下針。\n") ; 

// Ok , had checked point, now do effective acupuncture

        if(result[0]!=1&&result[0]!=2&&result[0]!=3)
           { 
            write("沒有這個穴道。\n") ;
            return 1 ;
           } 
           
        if(living_flag)
          acuped = target->query_temp("acupuncted_pts") ;
        else
          acuped = me->query_temp("practice_pts") ;
 
        if(!acuped) acuped = ({ }) ;

// check if the point once been acupuncture....
        
        if(check_repeat(tar_point,acuped)==0)
          {
             write("那個穴道已經有針在上面了。\n");
             return 1 ;
          }
        acuped = acuped + ({ tar_point }) ;

        part_name = part[result[1]] ;
        if((((string)target->query("race"))=="hawkman")&&(result[1]==7))
               part_name = "翅膀上" ;
        
        if(target==me)
            {
             tar_name = "自己" ;
             if(result[1]==6)
                { 
                  tell_object(me,"你針不到自己的背。\n") ;
                  return 1 ;
                }
             }   
        else{ 
             tell_object(target,sprintf("%s用銀針往你%s的%s穴紮了下去。\n"
                         ,my_name,part_name,tar_point)) ;          
             }
             
        write(sprintf("你用銀針往%s%s的%s穴紮了下去。\n"
                        ,tar_name,part_name,tar_point));

        tell_room(environment(me),sprintf("%s取出銀針往%s%s紮了下去。\n"
                                 ,my_name,tar_name,part_name),({me,target}) ) ;

        if(living_flag) target->set_temp("acupuncted_pts",acuped) ;       
        else me->set_temp("practice_pts",acuped) ;
       return 1 ;
}

// this is main part of acupuncture command,
// major for check all situations when u wanna do acupuncture

int cmd_acupunc (string str)
{
	string targetname, point, code, donator,my_name;
	object target,me ;
  
        me = this_player() ;
        my_name = me->query("c_name") ;

	if( !str ) return help();

        if(!wizardp(me))
                return notify_fail("現在針灸暫時只開放給巫師測試用。\n") ;
                
        if(!( !(me->query_current_attacker()) ))
                return notify_fail("你還在戰鬥中,沒時間停下來拿針。\n");
         
	if( !me->query("vision") )
      		return notify_fail("你看不見目標，沒辦法下針 !!\n"); 
	
	if( me->query("weapon1") && ( me->query("weapon2") ||
	     me->query("armor/shield") ) )
	    return notify_fail( "你沒有多餘的手來取針 !!\n" );

        if( me->query_temp("no_concentrate"))
            return notify_fail("你的注意力還不能集中,無法專心下針。\n") ;
             
	if( (int)me->query("stop_attack")>0 )
	    return notify_fail ("你上一個動作還沒有完成，不能專心下針。\n" );
            
        if ( sscanf( str,"remove from %s",targetname)==1 || 
             sscanf( str,"remove %s",targetname)==1 )
            {
              if(!(targetname)) target = me ;
              else 
               {
                if(!(target=present(targetname,environment(me))))
                     return notify_fail("你想拔誰的針 ??\n") ;
               }  
              if(!target->query_temp("acupuncted_pts"))
                 return notify_fail("你連根毛都沒看到, 要拔什麼針 ? \n") ;
                 
              target->delete_temp("acupuncted_pts");   
              target->delete_temp("acupunct_healer") ;
              if(target==me)
                {
                  write("你將自己身上扎的針一根根的拔出來。\n") ;
                  targetname == "自己" ;
                }
              else 
                {
                  targetname = target->query("c_name") ;
                  write(sprintf("你將%s身上扎的針一根根的拔出來。\n"
                                 ,targetname)) ;
                  
                  tell_object(target,sprintf("%s將你身上扎的針一根根的拔出來。\n"
                         ,my_name)) ;
                }
              tell_room(environment(me),sprintf("%s將%s身上扎的針一根根的拔出來。\n"
                          ,my_name,targetname)
                          ,({me,target}) ) ;
                            
              return 1 ;
            }
            
	if ( sscanf( str,"%s at %s", targetname,point)==2|| 
             sscanf( str,"%s on %s", targetname,point)==2 )
	     {
	      if((targetname=="model")||(targetname=="brozen model"))
	        {
	          if(!(target=present(targetname,environment(me)))
	             &&(!(target=find_player(targetname))))
	               return notify_fail("這裡沒有這個東東。\n") ;
	         }
	      else if(!(target=find_player(targetname)))
	              return notify_fail("這個世界沒有這號人物。\n") ;
              
              if(!present( target,environment(me) ))
                 {
                   tell_room(environment(me),me->query("c_name")+
                       "拿起銀針對空中空點了兩下,然後看了看四周帶著恥笑神情的路人\n"+
                       "紅著臉收起了銀針。\n",me) ;                              
                   return notify_fail
                         ("你以為你是雷神之子嗎 ? 竟想隔空針灸。\n");
                   }
	      } 
	else {
	       if(sscanf( str,"%s",point)==1)
            	      target = me ;
               else
                  return help() ;
	      }

	if((target->query("npc"))&&(!target->query("acupunctable")) )
	       return notify_fail("你無法對非玩家角色施以針灸。\n ") ;    

        if(!( !(target->query_current_attacker()) ))
                return notify_fail("你的目標還在戰鬥中,沒時間停下來讓你下針。\n");

        donator = target->query_temp("acupunct_healer") ;

        if( donator && donator!=my_name )
                return notify_fail("你的對象正在接受針灸中,你不能中途介入。\n");
                
        if((string)target->query("race")=="beholder") 
           return notify_fail("對方長的太奇怪了,你不知從何下針。\n") ;
           
        do_acupuncture(point,target) ;
        
	return 1;
}
 
int help()
{
	write( @C_HELP
指令格式: acupunct <目標> [on|at] <穴道名稱>
          acupunct remove from <目標>

這個指令讓你用來施展你的針灸神技，不指定目標則會對自己下針，但有些穴道
你自己針不到。你可以用 meridian 指令看你目前已經學過的經絡列表。為免人多
手雜，一個患者必需完成針灸後，才能讓另一位醫生針。 針完後必須對患者施以
導引術<即氣功>以加快療效。(詳情請見 help douin)

運功出力可為 max, regular, normal, minor, mini 。
請先好好考慮清楚再下針，當血氣運行錯誤受阻時，可能會逆流衝向運功者。
輕者受傷，重者殘廢癱瘓，慎之慎之...

為求取穴正確，對人施針治療前必須要在銅人上將該穴道所屬的經絡練熟。
C_HELP
		);
    return 1;
}
