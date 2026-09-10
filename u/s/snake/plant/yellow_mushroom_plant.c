#include <mudlib.h>

inherit OBJECT;

void create()
{
	set_short("@@query_c_name");    
        
        set("c_realname","黃蘑菇");           // 玩家辨認成功傳回的名字
        set("realname","yellow mushroom");
	
   	set("unit","株");                     // 株,棵,盆.隨便用

   	set("weight", 50000);                 // 只要保證玩家搬不動就好了

   	set("value", ({0, "silver"}) );       // 野生的樹當然不值錢啊
      
        set("herb_file","yellow_mushroom.c") ;//提煉出來的東東的完整檔名
        set("herb_path","/d/healer/reagent/");//提煉出來的東東的目錄
                                              //記得用完整目錄
                                              //default 是 /d/healer/plant
                                                
        set("skill_require",40) ;             //要成功辨識這種植物所須之技能
        set("purified",3);                    //還能採幾次
       
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
    set("id",({"plant","tree"}) );
    set_name("a plant","孢子植物");
    set_long("這株孢子植物外形和一般的似乎有些不同, 可惜以你簡單的小腦袋瓜,\n"
             "很難說出個所以然來。\n");
    return "孢子植物";
  }
  else if ( ok==1 ) {
    set("id",({"plant","tree","mushroom","yellow mushroom"}) );
    set_name("yellow mushroom","黃蘑菇");
    set_long("根據你仔細鑑定的結果, 你判斷這是一顆黃蘑菇(yellow mushroom),\n"
             "如果你有藥鋤, 還可以挖(dig)一點回去。\n");
    return "黃蘑菇";
  }
  else {
    set("id",({"plant","tree"}) );
    set_name("a plant","蕈類植物");
    set_long("根據你在國中生物課本中得來的知識, 你判斷這是一種蕈類植物, \n"
             "不過正確的名稱, 還須要進一步的辨識。\n");
    return "蕈類植物";
  }  
}      
