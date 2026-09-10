

#include "../../echobomber.h"

void drink_muse(int color,object you)
{
    int exp,con,kar;
    int correct;
    int i;
    object *items;
    
    exp=you->query_experience();
    con=you->query_perm_stat("con");
    kar=you->query_perm_stat("kar");
    
    
    correct=((exp+con+kar) % 9)+1;
    
    if ( correct!=color ) {
       tell_object(you,
       "當你喝下這泉水時,你的喉嚨忽然一陣抽□\n"
       );
       tell_room(environment(you),
       you->query("c_name")+"大叫一聲!!啊......\n");
       
       you->receive_damage((int)you->query("hit_points")+10);
       return;
       }
    items=all_inventory(you);   
    for(i=0;i<sizeof(items);i++) {
       if ( (string)items[i]->query("name")=="Black Box of Molader" )
          items[i]->set("quest_action/good_poet",1);
       }   
    tell_object(you,
      "當你喝下這泉水時,你覺得自己似乎變得更聰明瞭, 而且整個人的氣質與內涵\n"
      "都大幅度提升了, 你覺得自己好像成為一個具有高度文化的文學家一樣.\n"
      );
    return;   
}

int fill_muse_water(object you,int color)
{
     object *items;
     int i;
     
     items=all_inventory(you);
          
     for(i=0;i<sizeof(items);i++) 
       if ( (string)items[i]->query("name")=="Black Box of Molader" ) {
          if (!items[i]->query("quest_item/black_bottle")) {
            tell_object(you,
            "你沒有合適的容器來裝這泉水.\n"
            );
            return 1;
            }
          items[i]->set("quest_action/muse_filled",color);
          tell_object(you,
          "你用黑色瓶子把泉水裝滿.\n"
          );
          return 1;
          }
    return 0;   
}

void drink_bottle_muse(object you,object box)
{
    int exp,con,kar;
    int correct,color;
    
    
    exp=you->query_experience();
    con=you->query_perm_stat("con");
    kar=you->query_perm_stat("kar");
    
    correct=((exp+con+kar) % 9)+1;
    
    color=box->query("quest_action/muse_filled");
    
    if ( correct!=color ) {
       tell_object(you,
       "當你喝下這泉水時,你的喉嚨忽然一陣抽□\n"
       );
       tell_room(environment(you),
       you->query("c_name")+"大叫一聲!!啊......\n");
       if ( box->query("quest_action/mixed") ) 
          you->receive_damage(10);
       else 
          you->receive_damage( (int)you->query("hit_points")+10 );
       }
    else {
      box->set("quest_action/good_poet",1);
      tell_object(you,
      "當你喝下這泉水時,你覺得自己似乎變得更聰明瞭, 而且整個人的氣質與內涵\n"
      "都大幅度提升了, 你覺得自己好像成為一個具有高度文化的文學家一樣.\n"
      );
      }
    
    box->set("quest_action/mixed",0);
    box->set("quest_action/muse_filled",0);
    
    return;   
}     

string muse_color(int color)
{
   string *colors;
   colors=({"藍(blue)","綠(green)","紅(red)","紫(purple)",
   "橙(orange)","黃(yellow)","黑(black)","白(white)","褐(brown)" });
   
   return colors[color-1];   
}
