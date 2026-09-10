// This is a room for storage eqs , and can filter some "garbage"
//       by Indra@EasternStories
//
//    This is ver2.0 with receive_object(), release_object()

#include <mudlib.h>

inherit ROOM;

int AMOUNT = 0 ;
nomask int my_clean_func(object it) ;

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
        set("no_clean_array",({ }) ) ;       //公會強制不清除的物品(ID)
         		     
        set("max_amount",60) ;	             //這個房間清過後物件儲存的最大值 
	set("class_name","NONE") ;           //這個房間所在公會名稱, 用以清除
	                                     //該公會成員不能用的裝備.
        
        //兩數分別代表最低容許之WC,dam平均值
        
	set("weapon_res",({23,17}) ) ; 

	//每種型別防具之ac,db最低容許值,限制為 ac+db 之合 
        //如果能改變AC DB的,請在防具 set("no_clean",1)
        
        set("armor_res",([                          
                         "body" : 20   , "legs"   : 7 ,
 	                 "feet" : 7    , "cloak"  : 7 , 
 	                 "head" : 7    , "arms"   : 6 , 
 	                 "misc" : 5    , "finger" : 5 , 
 	                 "hands" : 6   , "globe"  : 10 , 
 	                 "shield" : 7  , "saddle" : 9 , 
 	                 "kernal" : 6  , "tail"   : 7 ,
 	                 "others" : 7,
 	                 ]) ) ;
	
	//容器的限制
	set("container_res",200) ;
	
        // 以下是清除的訊息, 有必要的話請重寫 string cleaning_msg()
	set("clean_msg",
	    "儲藏室管理員%s對你搖了搖手說:這種沒用的東西丟這不太好吧。\n") ;
	set("msg_arg","雷神之子") ;
	set("clean_msg1",
	    "儲藏室管理員%s對你大喊:這□太多東西了, 你先清一點掉再放。\n") ;
	set("msg_arg1","雷神之子") ;
	
	
//	reset();
}

int query_amount(){ return AMOUNT ; }

int realease_object(object ob)
{
    if(living(ob)) return 1;
    AMOUNT-- ;
    return 1 ;
}

int receive_object(object arg)
{
    int result ;
    string msg ;
//    ::receive_object(arg) ;   
    if(living(arg)) return 1 ;    
    
    if( AMOUNT >(int)query("max_amount") ) 
       {
           tell_object(this_player(),
                       sprintf(query("clean_msg1"),query("msg_arg1"))) ;     
           return 0 ;
        }
    result = my_clean_func(arg) ;
    if(result)
      {
         AMOUNT++ ;
         return 1 ;
      }
    else
      {  
         msg = sprintf(query("clean_msg"),query("msg_arg")) ; 
         tell_object(this_player(),msg) ;     
         return 0 ;
      }
}

nomask int my_clean_func(object it)          // 防止用來做壞事..
{
     int res1,res2,temp1,temp2,temp3,flag ;    // 一堆變數..
     string type,inherit_from,ob_sort ;

     flag = 0 ;
     res1=res2=temp1=temp2=temp3=0 ;        // 再check 物品的種類.
                                            // 用inherit list 是怕只
     inherit_from = inherit_list(it)[0] ;   // 用物品的特徵設定可能誤判
     ob_sort = "/"+explode(inherit_from,".")[0] ;      
  
     switch(ob_sort)
       {
          case LIVING :
                        flag = 1 ;
                        break ;
          case WEAPON :
                        temp1 = it->query("weapon_class") ;
                        temp2 = it->query("max_damage") ;
                        temp3 = it->query("min_damage") ;
                        res1 = query("weapon_res")[0] ;
                        res2 = query("weapon_res")[1] ;
                        
                        if((temp1>res1)&&((temp2+temp3)>res2*2) )
                           flag = 1 ;
                        break ;
          case ARMOR  :                
                        temp1 = it->query("armor_class") ;
                        temp2 = it->query("defense_bonus") ;
                        type = it->query("type") ;
                        res1 = query("armor_res/"+type) ;
                        if(!res1) res1 = query("armor_res/others");
                   
                        if((temp1+temp2)>res1)
                           flag = 1 ;
                        break; 
          case CONTAINER :                
                        temp1 = it->query("max_load") ; 
                        res1 = query("container_res") ;
                        
                        if(temp1>res1 )
                            flag = 1 ;
                        break; 
          default : flag = 1 ;
                    break ;  
         }   
     return flag ;
}

int clean_up() 
{
     return 0;
}

