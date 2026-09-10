#include <mudlib.h>

inherit OBJECT;

void create()
{
   //  以下四項均為外形的描述， realname 才是成功的辨識後傳回的名字     
        
	set_short("@@query_c_name");    
        
        set("c_realname","牛醉草");         // 玩家辨認成功傳回的名字
        set("realname","neo grass");
	
   	set("unit","株");                     // 株,棵,盆.隨便用

   	set("weight", 50000);                 // 只要保證玩家搬不動就好了

   	set("value", ({0, "silver"}) );       // 野生的樹當然不值錢啊
      
        set("herb_file","neo_grass.c") ;     //提煉出來的東東的完整檔名
        set("herb_path","/d/healer/reagent/");   //提煉出來的東東的目錄
                                              //記得用完整目錄
                                              //default 是 /d/healer/plant
                                                
        set("skill_require",30) ;             //要成功辨識這種植物所須之技能
        set("purified",5);                    //還能採幾次
       
        set("plant_type",0);                  //

}

string query_c_name()
{
  string* verified;
  string temp;
  string s;
  int i;
  int ok;
  
  if ( this_player()->query_temp("last_verify") ){
    verified=explode(this_player()->query_temp("last_verify"),"\n");
    ok = 0;
    sscanf(identify(this_object() ),"%s/%s",s,temp);
    for ( i = 0 ; i < sizeof(verified) ; i ++) {
      if ( (verified[i]) == temp )
        ok=1;
    }
  }
  else ok = 0;
   
  if (this_player()->query_stat("int") < 10 ) {
    set_name("A plant","小草");
    set_long("你對著這棵小草前前後後看了半天, 終於得到一個結論--看不懂有啥\n"
             "特別的。\n");
    set( "id" , ({ "plant","tree"}) );
    return "小草";
  }  
  else if ( ok==1 ) {
    set_name("neo grass","牛醉草");
    set_long("根據你仔細鑑定的結果, 你判斷這是棵牛醉草(neo grass),\n"
             "如果你有藥鋤, 還可以挖(dig)一點回去。\n");
    set( "id" , ({ "plant","tree","neo","grass"}) );
    return "牛醉草";
  }  
  else {
    set_name("a short life plant","一年生草本植物");        
    set_long( "根據你在國中生物課本中得來的知識, 你判斷這是一種一年生草本植物, \n"
              "不過正確的名稱, 還須要進一步的辨識。\n");
    set( "id" , ({ "plant","tree"}) );
    return "一年生草本植物";
  }   
}      

