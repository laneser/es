// model.c 有兩個功用, 一是用來練習針灸, 另一個隱藏的功用是用
// 來在野外灑樹種, 每當model update 時, 灑樹種的function 就會
// 自動被呼叫到////#pragma save_binary
#include <mudlib.h>
#include "/d/healer/healer.h"
inherit OBJECT ;

// plant.dat 用來紀錄在各種地型該出現哪種植物, 以及出現的機率比
#define PLANTDATA "/d/healer/plant/plant.dat"
mapping P0,P1,F0,B0,S0,H0,R0,R1;

//  在灑樹種之前, 先將上次灑過的樹清掉, 以免update 幾次後, 到處
//  都是樹, 氾濫成災
//  kill_plant accept a argument, which is the tree's file
//  eg: kill_plant("/d/healer/plant/dang_guei_tree.c");
int kill_plant(string str) {
   object target;
   mixed *clones;
   string para, hold, tmp1, tmp2;
   int loop, dest, view, More, original;
 
   target = get_object( str );
 
   //	Oh well, couldn't find the object
 
   if(!target) return 1; 
 
   //	Try to located all copies of the object
   clones = children( file_name(target) );
   //	Its either the Master object or has no other copies around
   if(sizeof(clones) == 1) {
        tell_room(environment(target),"你發現"+target->query("c_name")+
                                      "在你面前枯萎而死了。\n");
	target->remove();
	if(target)  destruct(target);
        return 1; 
   }
   else clones -= ({ target });
 
   //	Try to remove all clone copies
   for ( loop= 0; loop<sizeof(clones); loop++){
     tell_room(environment(clones[loop]),
               "你發現"+clones[loop]->query("c_name")+
               "在你面前枯萎而死了。\n");
     clones[loop]->remove();
   } 
   clones = children( file_name(target) );
   clones -= ({ target });
   //	If there are any copies left...this should get rid of them
   for(loop=0; loop<sizeof(clones); loop++)
	destruct( clones[loop] );
   return 1; 
}

// This function plants a plant in a specified room
void make_plant (string room, string the_plant)
{
  object this_room;
  object this_plant;
  
  this_plant=new(the_plant);
  this_room=find_object(room);
  if ( this_room && this_plant) this_plant->move(this_room);
}  

// choose_plant accept 2 arguments, the first is the 
// file name of a room, the second is the type of the room
// for example, P0 means 平原
// choose_plant 根據room_type, 計算出是否該長樹, 以及該長
// 什麼樹後, 呼叫 make_plant在該房間種樹
void choose_plant(string room, string room_type)
{
  int i;
  int max;
  int decision;
  
  switch (room_type) {
    // P0 is 平原 , have 1/8 chance to have a plant
    case "P0" : max=P0[sizeof(P0)-1][0]*8;
                decision=random(max);
                for ( i = 0 ; i < sizeof(P0) ; i++ ) 
                  if (decision<P0[i][0]) { make_plant(room,P0[i][1]);
                                           return;
                                         }
                break;                           
     // P1 is 河邊, have 1/8 chance to have a plant           
    case "P1" : max=P1[sizeof(P1)-1][0]*8;
                decision=random(max);
                for ( i = 0 ; i < sizeof(P1) ; i++ ) 
                  if (decision<P1[i][0]) { make_plant(room,P1[i][1]);
                                           return;
                                         }
                break;  
     // F0 is 森林, have 1/10 chance to have a plant           
    case "F0" : max=F0[sizeof(F0)-1][0]*10;
                decision=random(max);
                for ( i = 0 ; i < sizeof(F0) ; i++ ) 
                  if (decision<F0[i][0]) { make_plant(room,F0[i][1]);
                                           return;
                                         }
                break;                           
     // B0 is 草地, have 1/7 chance to have a plant           
    case "B0" : max=B0[sizeof(B0)-1][0]*7;
                decision=random(max);
                for ( i = 0 ; i < sizeof(B0) ; i++ ) 
                  if (decision<B0[i][0]) { make_plant(room,B0[i][1]);
                                           return;
                                         }
                break;  
     // S0 is swamp, have 1/7 chance to have a plant           
    case "S0" : max=S0[sizeof(S0)-1][0]*7;
                decision=random(max);
                for ( i = 0 ; i < sizeof(S0) ; i++ ) 
                  if (decision<S0[i][0]) { make_plant(room,S0[i][1]);
                                           return;
                                         }
                break;                           
     // H0 is Hill, have 1/10 chance to have a plant           
    case "H0" : max=H0[sizeof(H0)-1][0]*10;
                decision=random(max);
                for ( i = 0 ; i < sizeof(H0) ; i++ ) 
                  if (decision<H0[i][0]) { make_plant(room,H0[i][1]);
                                           return;
                                         }
                break;  
     // R1 and R0 are both road, have only 1/15 chance to have a plant           
    case "R1" : max=R1[sizeof(R1)-1][0]*15;
                decision=random(max);
                for ( i = 0 ; i < sizeof(R1) ; i++ ) 
                  if (decision<R1[i][0]) { make_plant(room,R1[i][1]);
                                           return;
                                         }
                break;                           
    case "R0" : max=R0[sizeof(R0)-1][0]*15;
                decision=random(max);
                for ( i = 0 ; i < sizeof(R0) ; i++ ) 
                  if (decision<R0[i][0]) { make_plant(room,R0[i][1]);
                                           return;
                                         }
                break;
  }
}


void kill_plants()
{
  string *info;
  string area, file;
  int rate;
  int i;
  
  // read from plant data file to get all plants that 
  // maybe in ES now  
  info = explode( read_file(PLANTDATA), "\n" );
  // first, kill old plants
  for( i=0; i< sizeof(info); i++) {
    // skip comments
    if ( info[i][0]=='#') continue;
    if (sscanf(info[i],"%s:%d:%s",area,rate,file)==3) 
      kill_plant(file);
  }    
}

// plant accept an argument, indicates which map to be processed
// now only have plants on Noden and Eastland 

void plant(string map)
{
  string *info,*map_data,*temp_str;
  string area,file,name,area_file;
  int rate, i , j , k,temp,weight,height;

// initial all mapping for all 8 kinds of 地形 
  P0=([]);  P1=([]);  F0=([]);  B0=([]);
  S0=([]);  H0=([]);  R0=([]);  R1=([]);

// now.... read plants data from data file  
  info=explode( read_file(PLANTDATA), "\n" );
  for( i=0; i<sizeof(info); i++ ) {
    // Skip comments
    if( info[i][0]=='#') continue;
    if( sscanf(info[i],"%s:%d:%s",area,rate,file)==3 ) {
      switch(area) {
        case "P0": temp=sizeof(P0);if (temp>0) rate+=P0[temp-1][0];
                   P0[temp]=({rate,file});break;
        case "P1": temp=sizeof(P1);if (temp>0) rate+=P1[temp-1][0];
                   P1[temp]=({rate,file});break;
        case "F0": temp=sizeof(F0);if (temp>0) rate+=F0[temp-1][0];
                   F0[temp]=({rate,file});break;
        case "B0": temp=sizeof(B0);if (temp>0) rate+=B0[temp-1][0];
                   B0[temp]=({rate,file});break;
        case "S0": temp=sizeof(S0);if (temp>0) rate+=S0[temp-1][0];
                   S0[temp]=({rate,file});break;
        case "H0": temp=sizeof(H0);if (temp>0) rate+=H0[temp-1][0];
                   H0[temp]=({rate,file});break;
        case "R1": temp=sizeof(R1);if (temp>0) rate+=R1[temp-1][0];
                   R1[temp]=({rate,file});break;
        case "R0": temp=sizeof(R0);if (temp>0) rate+=R0[temp-1][0];
                   R0[temp]=({rate,file});break;
        default:   break;
      }   // end of switch          
    }    // end of if 
  }     // enf of for loop.... plant data read finished!

  // plant data read ok, now start to process the map
  map_data=explode( read_file(map),"\n");  
  for ( i = 0; i < sizeof (map_data); i++) {
    //skip comments
    if(map_data[i][0]=='#') continue;
    
    // get the weight and height of the map
    
    if( sscanf(map_data[i],"%s:%d%d",name,weight,height) == 3 ) {
      for ( j = 0 ; j < height ; j ++ ) {
        i++;
        temp_str=explode(map_data[i]," ");
        for ( k = 0 ; k < weight; k ++ ) {
          if (map=="/d/noden/noden.map")
          
          // get the file name from virtual map,
          // noden and eastland's file name r slightly different
          // so need to check map
            
            area_file="/d/noden/"+k+","+j+".noden";
          else
            area_file="/d/eastland/"+k+","+j+".east";
          
          // for each room, call choose_plant to decide if it should have
          // a plant, and which plant
            
          choose_plant(area_file,temp_str[k]);    
        }
      }
    }
  }
}


void create()
{
        seteuid(getuid()) ;
        set("id", ({"model","brass model"}) ) ;

	set_name("brass model", "銅人");
	set_short("銅人");
	set("long", "@@model_desc" );

	set( "unit", "具" );
	set( "weight", 1000000 );
        set("prevent_get",1);
        set("temp1",({ }) );
        set("temp2",({ }) );
        set("temp3",({ }) );        
        // call kill_plants before start to 種樹
        kill_plants();
        plant("/d/noden/noden.map");
        plant("/d/eastland/eastland.map");
}

void init()
{
	add_action("do_practice", "practice");
	add_action("do_exam", "exam");
}

string model_desc()
{
     int pts_no,i ;
     string msg;

     if((string)this_player()->query("class")!="healer")
       {   msg = "  一個不甚起眼的木製金漆假人, 細看後發現身上有一個個的小點。\n"
                "另外還有紅線黑線連接這些點。想必這個就是練習針灸用的銅人了。\n"
                "用 exam <經絡> 可以查已發現的所有穴道。\n"  ;
        }        
     else     
        {      
          msg = "  一個不甚起眼的木製金漆假人, 細看後發現身上有一個個的小點。\n"
                "另外還有紅線黑線連接這些點。想必這個就是練習針灸用的銅人了。\n"
                "用 exam <經絡> 可以查已發現的所有穴道。\n"  
                "而一個行醫者在踏出師門施針行醫救人前，必定要對銅人練到下針準\n"
                "確無誤的地步才能被允許使用針療。除熟讀醫書外，練習(practice)\n"
                "在銅人上施針才是學會針灸的不二法門。\n\n" ;
        }        
     return msg ;    
}

// i : position of the name array, j : length of the array,
// temp : array of point name, first_str : name of meridians
int do_exam(string arg)
{
   int    i,j ;
   string *temp,first_str ;

   if(!arg||arg=="經絡") arg="title" ;
   
   temp = ALL_POINTS->query_meridians(arg) ;
   first_str = temp[0]  ; 
   if(first_str=="NULL") return 0 ;

   if(arg=="title") 
       write("人體全身經絡共有十四條，分別為:\n") ;
   else
       write(first_str+"所含穴道如下:\n") ;   

   j = sizeof(temp);
   for(i=1;i<j;i++)
     {
        write(temp[i]) ;
        if(i!=j-1) write(", ") ;
        if((arg=="title")&&(i%5==0)) write("\n") ;
        else
         {
           if((arg!="title")&&(i%8==0)) write("\n") ;
         }
      }
    write(" 。\n") ;
    return 1 ;
}

int do_practice(string arg)
{
     int i , j , check_flag, *merid_no,difficulty,acu_skill;
     string *temp,*practiced ;
     temp      = ({ }) ;
     practiced = ({ }) ; 
     
     if((string)this_player()->query("class")!="healer")
          return notify_fail("小朋友 , 你想幹什麼 ???\n") ;

     if(!arg)
          return notify_fail
          ("要練習針灸技巧, 只要鍵入練習(practice)<經絡>, 就可以達到\n"
           "練習的效果。\n") ; 

     temp      = ({ arg }) ;
     acu_skill = this_player()->query_perm_skill("acupuncture") ;

     temp  = ALL_POINTS->query_meridians(arg) ;
     if(temp[0]=="NULL") 
        {
          write("沒有這條經絡..\n") ;
          return 1 ;
          }

     merid_no = ALL_POINTS->query_meridians_no(arg) ;

     difficulty = merid_no[1] ;
     difficulty = difficulty * 6 + 15 ;
     j = sizeof(temp);
     for ( i = 1 ; i < j ; i ++ ) {
       write ("你拿起銀針, 往銅人的"+temp[i]+"穴刺了進去。\n");
       tell_room(environment( this_player() ),
                 this_player()->query("c_name")+
                 "拿起銀針, 往銅人的"+temp[i]+"穴刺了進去。\n",
                 this_player() );
     }  
       
     if( ( acu_skill > difficulty ) || wizardp(this_player()) )     
       {
         this_player()->set("prac_meridians/"+arg,merid_no[0]) ;
         this_player()->delete_temp("practice_pts") ;
         this_player()->delete("practice_pts") ;
         
         write("看著銅人上"+arg+"的圖形,一幅鮮明的影像深刻的\n"
               "刻入你的腦海。\n") ;
         tell_room( environment( this_player() ),
           this_player()->query("c_name")+"拿出銀針,延著銅人身上的某一條經絡"+
           "一個穴道一個穴道往下扎。\n過了一會兒,只見他帶著微笑從沉思中張開眼。\n"
           ,this_player()  ) ;
       }
     else
        {
         this_player()->delete_temp("practice_pts") ;
         this_player()->delete("practice_pts") ;

         write("\n嗯...喔....啊.......你突然發覺你被銅人上的圖形弄迷糊了。\n"
               "你意識到這是由於自己技能不足, 於是決定要努力賺 EXP。\n ");

       }
     return 1 ;
}
