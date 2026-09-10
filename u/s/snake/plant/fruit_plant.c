#include <mudlib.h>
inherit OBJECT;

void create()
{
   //  以下四項均為外形的描述， realname 才是成功的辨識後傳回的名字     
        
	set_short("@@query_c_name");    
        
        set("c_realname","無名果");         // 玩家辨認成功傳回的名字
        set("realname","fruit");
	
   	set("unit","棵");                     // 株,棵,盆.隨便用

   	set("weight", 50000);                 // 只要保證玩家搬不動就好了

   	set("value", ({0, "silver"}) );       // 野生的樹當然不值錢啊
      
        set("herb_file","fruit.c") ;   //提煉出來的東東的完整檔名
        set("herb_path","/d/healer/reagent/");   //提煉出來的東東的目錄
                                              //記得用完整目錄
                                              //default 是 /d/healer/plant
                                                
        set("skill_require",90) ;             //要成功辨識這種植物所須之技能
        set("purified",2);                    //是否被別人捷足先登,0為否,1為是
       
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
    set("id",({"plant","tree"}));
    set_long("這棵樹看起來好像和一般的樹不太一樣, 但是你前前後後看了好幾次,\n"
             "還是說不出有什麼不同。\n");
    set_name("A plant","奇怪的樹");         
    return "奇怪的樹";
  }  
  else if ( ok== 1 ) {
    set("id",({"plant","tree"}) );
    set_long("根據你仔細鑑定的結果, 你判斷現有典籍中並沒有這棵樹。\n不過樹上"
	     "有些果子(fruit),"
             "如果你有藥鋤, 還可以挖(dig)一點回去。\n");
    set_name("Plant","不知名的樹");          
    return "不知名的樹";
  }  
  else {
    set("id",({"plant","tree"}) );
    set_long("根據你在國中生物課本中得來的知識, 你判斷這是一棵多年生灌木, \n"
             "不過正確的名稱, 還須要進一步的辨識。\n");
    set_name("a plant","多年生灌木");         
    return "多年生灌木";
  }  
}      

