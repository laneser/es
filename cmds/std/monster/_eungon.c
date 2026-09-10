// Created by Kyoko.
// modify by angel for monk guild... :P

#include <mudlib.h>
#include <gonfu.h>

inherit DAEMON ;

int gonfu_exists(string gonfu);

int help() ;

int cmd_eungon(string str)
{
	
         string type,targname,gonfu;
         int fp_cost,delay_time,skill,gonfu_level,kk;
         object code;
    
if( !str ) return help();

if( (int)this_player()->query("stop_attack")>0 )
		return notify_fail ("( 你上一個動作還沒有完成，無法施展招式。 )\n");
 // if (this_player()->query_temp("gonfu_busy") )
        
if( this_player()->query_temp("no_enhant") ||
        this_player()->query("no_enhant") )
               return notify_fail( "你正準備使用招式時，竟然發現你突然功力全失了。\n" );
if( environment(this_player())->query_temp("no_enhant") ||
         environment(this_player())->query("no_enhant") )
              return notify_fail( "這裡不能使用任何招式。\n" );
if (sscanf(str,"%s at %s", gonfu,targname)==2) 
   {
         if( undefinedp(this_player()->query("gonfus/"+gonfu)) )
	     return notify_fail( "白痴!!! 你跟本不會這種功夫啦。\n");
	
   }
        
else{
        gonfu=str;
        targname= "NONE";
        if( undefinedp(this_player()->query("gonfus/"+gonfu)) ) 
            return notify_fail( "你想練功想瘋了嗎? 你跟本就不會這種功夫啦! \n");

     }
code = GONFU_D->find_gonfu( gonfu );
        	       if( !code )
	        	return notify_fail( 
        	"沒有這種功夫 .... 請通知巫師或用 bug 指令報告招式名稱。\n");


	fp_cost = (int)code->query_fp_cost();
	delay_time = (int)code->query_delay_time();
	if( !fp_cost || (int)this_player()->query("force_points") < fp_cost )
		return notify_fail( "你的內力不夠！\n");

        if ( (string)this_player()->query_temp("gonfu_now")==gonfu)
        return notify_fail( "你目前正在施展這種功夫  "); 


skill=this_player()->query_skill("inner-control");
if (random( fp_cost>100?100:fp_cost)  >  skill) {
      write ("你試圖運氣發功\... 但失敗了..... \n");

      tell_room(environment(this_player()), 
        this_player()->query("c_name")+"突然大叫一聲... 似忽運功岔了氣了 \n",
        this_player() );
        this_player()->add("force_points", -fp_cost);
        return 1;
                                                         } else 
    { 
    gonfu_level=(int)this_player()->query("gonfus/"+gonfu); 
    this_player()->set_temp("gonfu_now", gonfu);
    this_player()->set_temp("gonfu_delay_time", delay_time);
       	if( code->eungon(gonfu_level,targname) )
          this_player()->add("force_points", -fp_cost );
	return 1;
    }
}

int help()
{
	if( can_read_chinese() )
		write( @C_HELP
指令格式: eungon <招式名稱> at <敵人>
      或  eungon <招式名稱>  // 即會做用於自己身上.... 

這個指令讓你用來施展招式。你可以用 gonfus 指令看你目前已經學會的招式列表。
C_HELP
		);
	else write ( @HELP
Usage:	eungon <gonfu name> at <mob>

This command let you enhant gonfus. You can type "gonfus" to see the 
gonfus you have learned.
HELP
    );
    return 1;
}
