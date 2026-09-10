#include <mudlib.h>

inherit OBJECT;

void create()
{
   //  以下四項均為外形的描述， realname 才是成功的辨識後傳回的名字     
        
	set_name("Standard Plant","標準的不明植物");     
	add( "id" , ({ "plant","tree","ivy" }) );        
	set_short("Standard Plant","標準的不明植物");    
	set_long(".." , "名稱屬性形狀不明的植物。\n");   
        
        set("c_realname","黃大美女");         // 玩家辨認成功傳回的名字
        set("realname","beauty");
	
   	set("unit","株");                     // 株,棵,盆.隨便用

   	set("weight", 50000);                 // 只要保證玩家搬不動就好了

   	set("value", ({0, "silver"}) );       // 野生的樹當然不值錢啊
      
        set("herb_file","NULL") ;             //提煉出來的東東的完整檔名
        set("herb_path","/d/healer/plant/");   //提煉出來的東東的目錄
                                              //記得用完整目錄
                                              //default 是 /d/healer/plant
                                                
        set("skill_require",0) ;              //要成功辨識這種植物所須之技能
        set("purified",0);                    //是否被別人捷足先登,0為否,1為是
       
        set("plant_type",0);                  //

}
