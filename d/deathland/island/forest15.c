
#include "../echobomber.h"

inherit ROOM;

void create()
{
	::create();
  set_short("forest house","森林小屋");
  set_long(@Long
Long
,@CLong
一間勉強只能遮住風雨的小木屋, 但是目前到處是灰塵與蜘蛛網, 你似乎覺得
這裡被一種詭異的力量所佔據著, 是一種來自虛幻的力量.
    這裡好像有著生物的存在, 但那是活在這世界的生物嗎?
CLong
);
set("echo_special_place",1);
set("exits",([
     "west" :Deathland"/island/forest12",
     ]) );
set("objects",([
    "wight":Monster"/wight03",
    ]) );     
 ::reset();
}

void release(object player,object box)
{
     int i;
     object *monster,leit;
     
     if ( (string)box->query("quest_action/bottle_lock")=="falady" ) {
       tell_object(player,
      "法拉第的靈魂被釋放後, 一下子就消失的無影無蹤了.\n");    
       box->delete("quest_action/bottle_lock");
       return; 
       }
     monster=all_inventory(this_object());
     for(i=0;i<sizeof(monster);i++) 
        if ( monster[i]->id("wight") && monster[i]->query("npc") ) {
          tell_object(player,
          "你釋放出萊特的靈魂.\n"
          "萊特慢慢地出現在你的面前.\n"
          );
          leit=new(Monster"/wight02");
          leit->move(this_object());
          box->delete("quest_action/bottle_lock");
          call_out("quest_info",2,player,monster[i],leit,0);
          return;
          } 
     box->delete("quest_action/bottle_lock");
     tell_object(player,
      "萊特的靈魂被釋放後, 一下子就消失的無影無蹤了.\n");
     return; 
}

void quest_info(object player,object kanni,object leit,int depth)
{
     switch(depth) {
     case 0:
            tell_room(this_object(),
            
            "萊特與肯尼兩個人似乎正在交談些甚麼...\n\n\n\n"
            );
            call_out("quest_info",5,player,kanni,leit,1);
            break;
     case 1:
            tell_room(this_object(),
            "一會兒後,肯尼舉起他的手來,而萊特也緩緩地點了頭.\n\n\n\n"
            );
            call_out("quest_info",2,player,kanni,leit,2);
            break;
     case 2:
            tell_room(this_object(),
            "一陣雷擊從肯尼的手中射出,把萊特的靈魂給摧毀了.\n"
            );
            leit->remove();
            tell_object(player,
            "肯尼說道:\n"
            "我們兄弟倆人的心願已經完成了, 可以安心地離開這個世界了.\n"
            "非常謝謝你的幫忙, 最後我再告訴你一個秘密, 謬思泉水的毒性\n"
            "可以用沼澤的灰色蘑菇緩和它, 當你嘗試要去喝下泉水的時候, \n"
            "記得要先放點蘑菇混( mix )在泉水之中.千萬要記得, 這是我們\n"
            "兄弟的忠告.\n"
            "還有一件事,把你的水晶卡片給我. 我將把我最後的力量附在其上.\n"
            "肯尼慢慢地放他的雙手於卡片上.\n"
            );            
            call_out("quest_info_2",5,player,kanni);               
            break; 
     }
     return;
}

void quest_info_2(object player,object kanni)
{
     object *items;
     int i;
     tell_object(player,
     "肯尼施展他的法術後,說:\n"
     "在我們城市圖書館中, 搜尋地板(floor),你將發現一瓶胡椒粉, 但那不是.\n"
     "普通的胡椒粉, 那是招魂粉, 我與萊特冒著九死一生的危險所得來的. 希望\n"
     "對你會有所幫助.\n"
     "言盡於此, 我的兄弟正等著我呢...\n"
     "這時, 肯尼用著雷擊向自己, 消失於世上了.\n"
     );
     kanni->remove();
     items=all_inventory(player);
     for(i=0;i<sizeof(items);i++) 
        if ( (string)items[i]->query("name")== "Black Box of Molader" )
           items[i]->set("quest_action/pepper_find",1);
     if ( (int)player->query_quest_level("queen_smile") < 4 )
       player->finish_quest("queen_smile",4);
     return;
}
