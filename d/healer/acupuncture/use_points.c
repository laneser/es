#include <mudlib.h>
#include "/d/healer/healer.h"

#define part ({"不明部位","頭部","頸部","胸前","腹部","腰部","背部","手上","腿部"})

#define dead ({"會陰","膻中","乳中","神闕","神道","靈臺","百會" })
#define dead_part ({ ({14,0}),({14,3}),({3,3}),({14,4}),({13,6}),({13,6}),({13,1}) })

// 俞和蓋肯定會出問題  
//  so i remove all points contain these 2 words
//                     Indra .. 94.12.10
//
// int *do_check(string tar_point,mapping known_merid)
// int check_allwork(string *acuped_points)
// string query_eff_file(int arg)
// string *now_working(string arg)
// string *query_eff_pts(int no)
// string query_eff_describ(int no)
// string query_effect_c_name(string str)

nomask string *eff_name = ({  "死穴",
                       "天神之力",
                       "敏捷如風",
                       "潛能激發",
                       "舒筋活血",
                       "提神醒腦",
                       "燃燒生命",
                       }) ;


nomask string *eff_describ = ({
          "\t 以下穴道均為人體血氣運行之要衝,切忌下針。\n",
          "\t 下針後將有如天神附體般,擁有超過常人的神力。\n",
          "\t 針後將有如捉摸不定的風,敵人更難掌握你的行動。\n",
          "\t 正如其一般,將會將你的潛能發揮出來,使得能力有超過極限的表現。\n",
          "\t 以下的穴道能加速新陳代謝,使傷勢能快些復原。\n",
          "\t 這些穴道能刺激神經中樞,使得精神更加集中。\n",
          "\t 燃燒生命就是借用你以後的生命力在現在消耗。\n\t 過去的呢 ? 唉,逝者已矣\n",
                         }) ;


nomask string *eff_file = ({ "/d/healer/acupuncture/failure",
                      "/d/healer/acupuncture/superpower",
                      "/d/healer/acupuncture/windex",
                      "/d/healer/acupuncture/potential",
                      "/d/healer/acupuncture/speedyhp",
                      "/d/healer/acupuncture/speedysp",
                      "/d/healer/acupuncture/overdrain",
                      }) ;

nomask mapping work = ([ 
          1:  ({ "合谷","太沖","氣海","肩貞","雲門" }) ,
          2:  ({ "環跳","陽陵泉","曲池","委中","下廉","風府" }) ,
          3:  ({ "合谷","頭維","風池","天井","上星" }) ,
          4:  ({ "內關","三陰交","中渚","合谷","神封" }) ,                  
          5:  ({ "天柱","曲澤","風市","湧泉","神門" }) ,
          6:  ({ "玉枕","委中","極泉","命門","俠白","大椎","水溝" }) ,
                ])  ;
//part ({"不明部位","頭部","頸部","胸前","腹部","腰部","背部","手上","腿部"})
nomask mapping wpart = ([
         1: ({ ({2,7}),({12,8}),({14,4}),({6,7}),({1,3}) }) ,
         2: ({ ({11,8}),({11,8}),({2,7}),({7,5}),({2,7}),({13,2}) }) ,
         3: ({ ({2,7}),({3,1}),({11,1}),({10,7}),({13,1}) }) ,
         4: ({ ({9,7}),({4,8}),({10,7}),({2,7}),({8,3}) }) ,
         5: ({ ({7,2}),({9,7}),({11,8}),({8,8}),({5,7}) }) ,
         6: ({ ({7,1}),({7,8}),({5,7}),({13,6}),({1,7}),({13,6}),({13,1}) }) ,
               ])   ;

//  這個是檢查是否為有功用的穴道之用,玩家大概不致於無聊到去針
//  無用的穴道
// i 經絡在mapping 中位置, j 是穴道在經絡中的位置
// linit_i limit_j 是 i j 的數目, part_name 是穴道在人體的位置
// ok_flag 1 表死穴,2 為有用穴, 3 為其它存在穴,0 則不存在,3用在points.c

nomask int *do_check(string tar_point,string *known_merid)
{
       int i,j,limit_i,limit_j,ok_flag,*part_info,*cur_part,if_know ;
       string point,*temp ;
       
       ok_flag = 0 ;

       if((j = member_array(tar_point,dead)) != -1)
          { 
            ok_flag = 1 ;
            part_info=dead_part[j] ;
           }

       limit_i = sizeof(work) ;

       for(i=1;i<=limit_i;++i)
          { 
            temp = work [i] ;
            limit_j = sizeof(temp);
            
            if(ok_flag == 0 && (j = member_array(tar_point,temp)) != -1)
               {
                     ok_flag = 2 ;
                     cur_part = wpart[i] ;
                     part_info = (int *)cur_part[j] ;
               }
            if(ok_flag!=0) break ;                
          }      
  
  // Following part check if player learned that very meridian
  
       if(ok_flag!=0)
         {
           temp = ALL_POINTS->query_meridians_by_no(part_info[0]) ;
            
           if((if_know = member_array(temp[0],known_merid)) == -1) 
                return ({ ok_flag , -1 }) ;
           else return ({ ok_flag , part_info[1] }) ;
          }
       return ({ ok_flag,1 }) ;      

}

//   這個函數檢查針過的穴道陣列是否為有作用的穴道
//   當!work 時,表示所有有用的point list 不見了
//   i 是有用穴在mapping 中的位置,j 為穴在陣列中位置,ok_flag 則為return 之數.

nomask int check_allwork(string *acuped_points)
{
     int i,j,numi,numj,ok_flag ;
     string *temp ;
     
     numi = sizeof(work)+1 ;
     ok_flag = 0 ;
     if(!work)
       {
         write("針灸系統似乎出了些問題,請回報給醫生公會的巫師知道。\n");
         return 0 ;
       }
       
     for(i=1;i<numi;i++)
        {                   
           temp = work[i] ;
           numj = sizeof(temp) ;
           if( sizeof(acuped_points) == numj )
             {
             for(j=0;j<numj;j++)
                {
                 if( acuped_points[j] != temp[j] ) break ;
                 if( j == numj-1 ) ok_flag = i ;
                }  
             }
           if(ok_flag!=0) break ;
        }        
//   acupunctured point is not in work list

     return ok_flag ;
}

nomask string query_eff_file(int arg)
{
   return eff_file[arg] ;
}

//  傳回現有的有作用之穴道,或是作用的名稱

nomask string *now_working(string arg)
{
     int i,j ;
     string *temp ;
     
     j = sizeof(eff_name) ;
          
     if(!arg) return eff_name ;
          
     for( i=0 ; i<j ; i++ )     
        {
          if(arg == eff_name[i])
             { 
                if(i==0) temp = dead  ;
                else temp = work[i] ; 
                break ;
             }     
        }
     return temp ;
}

// query 作用穴道群的穴道名稱
nomask string *query_eff_pts(int no)
{
   string *pts,*temp ;
   
   if (no==0 || work[no]) {
     pts = ({ eff_name[no] });
   
     if(no==0)
        pts = pts +  dead ;
     else     
        pts = pts + work[no] ;
   }
       
   return pts ;
}

// query 作用穴道群的作用敘述
nomask string query_eff_describ(int no)
{
    return eff_describ[no] ;
}

nomask string query_effect_c_name(string str)
{
     int i,j ;    
    
     for(i=0;i<sizeof(eff_file);i++)
        {
          if(("/d/healer/acupuncture/"+str)==eff_file[i])
               return eff_name[i] ; 
         }
     return "沒這種效用.請洽巫師Debug.\n";
}

void create()
{
    seteuid(getuid()) ;
}
