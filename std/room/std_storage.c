// This is a room for storage eqs , and can filter some "garbage"
//       by Indra@EasternStories
//
// This one is Ver1.1 use call_other , and old ver(ver1.0) use call_out
//

#include <mudlib.h>
#define DROP "/cmds/std/_drop.c"
#define GET "/cmds/std/_get.c"

inherit ROOM;

int AMOUNT = 0 ;
int COUNT = 0 ;
nomask int my_clean_func() ;
string cleaning_msg() ;

void create()
{
	::create();
        set_short("標準儲藏室");
	set_long(
@C_LONG_DESCRIPTION
用來作範例的標準公會儲藏室。牆上有張告示(note)。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_desc", ([
 		"note": "儲藏室是用來放武器防具容器等重要物資的,空間有限\n"
 		        "請不要當垃圾堆般的堆放無用途的東西。\n" 
 		           ]) );
	set( "exits", ([ 
		"out" : "/d/healer/building/healer_guild"
		       ]) ) ;

	//	     
	//以下各設定請各 arch 視自己需要及公會狀況做修改...
        //
		     
        set("max_amount",50) ;	             //這個房間清過後物件儲存的最大值 
	set("class_name","NONE") ;           //這個房間所在公會名稱, 用以清除
	                                     //該公會成員不能用的裝備.
        
        //兩數分別代表最低容許之WC,dam平均值
        
	set("weapon_res",({23,17}) ) ; 

	//每種型別防具之ac,db最低容許值,限制為 ac+db 之合 
        //如果能改變AC DB的,請在防具 set("no_clean",1)
        
        set("armor_res",([                          
                         "body" : 20   , "legs"   : 9 ,
 	                 "feet" : 7    , "cloak"  : 8 , 
 	                 "head" : 7    , "arms"   : 6 , 
 	                 "misc" : 5    , "finger" : 5 , 
 	                 "hands" : 6   , "globe"  : 25 , 
 	                 "shield" : 7  , "saddle" : 11 , 
 	                 "kernal" : 6  , "tail"   : 8 ,
 	                 "others" : 8,
 	                 ]) ) ;
	
	//容器的限制
	set("container_res",200) ;
	
        // 以下是清除的訊息, 有必要的話請重寫 string cleaning_msg()
	set("clean_msg",
	    "%s走進這個房間一看,搖了搖頭,招來一陣閃電,把沒用的東東燒成灰。\n") ;
	set("msg_arg","雷神之子") ;
	
	reset();
}

void init()
{
     add_action("do_drop","drop") ;
     add_action("do_get","get") ;
}

int do_get(string arg)
{
    if(GET->cmd_get(arg)==0)              // 直接使用正常的get 命令(房間呼叫)
         return 0 ;                       // 如果失敗(0), 則傳回0.
                                          // 再跑一次get 的動作(玩家呼叫)
    if(arg=="all")                        // 一次get all 視為五次get的效果
       AMOUNT -= 5 ;
    else 
       AMOUNT -- ;
       
    ( AMOUNT < 0 )? 0 : AMOUNT ;          // 數目小於0 時設回 0
    
    return 1 ;
}

int do_drop(string arg)
{
    if(DROP->cmd_drop(arg)==0)            // 同get
         return 0 ;
 
    if(arg=="all")                        // 一次drop all 視為五次drop 的效果
       {                                  // 但另增一個變數 COUNT
          AMOUNT += 5 ;                   // 以防止重複get all,drop all的情形
          COUNT++ ;
        }
    else
       AMOUNT++ ;
    
    if( AMOUNT > 25 || COUNT > 8 )
      { 
         this_object()->my_clean_func() ;
         AMOUNT = 0 ;
       }
    return 1 ;
}

nomask int my_clean_func()
{
     object *inv,temp,it ;              // 一堆變數..
     int i,number,res1,res2,temp1,temp2,temp3,check_flag ;
     string type,inherit_from,ob_sort ;

     inv = all_inventory(this_object()) ;          // 首先check房間中的東東
     number = sizeof(inv) ;
     
     for(i=0;i<number;i++)
        {
           it = inv[i] ;
           check_flag = 0 ;                       // 物品限制初始化
           res1=res2=temp1=temp2=temp3=0 ;        // 再check 物品的種類.
                                                  // 用inherit list 是怕
           inherit_from = inherit_list(it)[0] ;   // 用物品的特徵設定可能誤判
           ob_sort = "/"+explode(inherit_from,".")[0] ;      

           // if that item have no_clean flag , then skip 
           // 玩家和有 no_clean 設定的就直接跳過..

           if(it->query("no_clean")|| ob_sort==USER ) continue ;
           
           switch(ob_sort)
             {
                case LIVING :
                              check_flag = 1 ; 
                              break ;
                case WEAPON :
                              temp1 = it->query("weapon_class") ;
                              temp2 = it->query("max_damage") ;
                              temp3 = it->query("min_damage") ;
                              res1 = query("weapon_res")[0] ;
                              res2 = query("weapon_res")[1] ;
                              
                              if(((temp1<res1)||((temp2+temp3)<res2*2)) )
                                 check_flag = 1 ;                                 
                              break ;
                case ARMOR  :                
                              temp1 = it->query("armor_class") ;
                              temp2 = it->query("defense_bonus") ;
                              type = it->query("type") ;
                              res1 = query("armor_res/"+type) ;
                              if(!(res1)) res1 = query("armor_res/others");
                         
                              if((temp1+temp2)<res1)
                                  check_flag = 1 ;
                              break; 
                case CONTAINER :                
                              temp1 = it->query("max_load") ; 
                              res1 = query("container_res") ;
                              
                              if(temp1<res1 )
                                  check_flag = 1 ;
                              break; 
                default : check_flag = 1 ;
                          break ;  
              }                          
         
           if(check_flag)
             {
//               tell_room(this_object(),
//                           it->query("c_name")+"該被除去。\n",) ;
               it->remove() ;
               }
        }

     inv = all_inventory(this_object()) ;
     number = sizeof(inv) ;
     res1=res2=temp1=temp2=temp3=0 ;     
     res1 = query("max_amount") ;
  
 // 東東真的太多了, 不得不清 .. 連有no_clean flag 的也會清掉
 // 如果限制為50,則當超過 75 件時, 清掉 75-50 = 25 件.剩50樣
 
     if( number>(res1*3/2) )
        {  
           temp2 = number - res1 ; 
           for( i=number;;--i )
              {
                 if(temp1==temp2) break ;
                 if(living(inv[i])&&!(inv[i]->querry("npc")) )                 
                    continue ;
                    
                 inv[i]->remove() ;
                 temp1++ ;
              } 
         }
//  告訴玩家垃圾車剛剛開走..
                     
     tell_room(this_object(),cleaning_msg(),) ; 
     return 1 ;     
}

string cleaning_msg()
{
   return sprintf(query("clean_msg"),query("msg_arg")) ;
}

int clean_up() 
{
     return 0;
}

