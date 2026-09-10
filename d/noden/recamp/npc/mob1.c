
#include <mudlib.h>
#include "../camp.h"
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(10);
        set_name( "book fool", "書呆子" );
        add ("id",({ "book","fool","book fool" }));
        set_short( "書呆子");
        set("unit","位");
        set_long(
@C_LONG
世事如棋，乾坤莫測，笑盡英雄，百世經綸書呆子。
宇宙似幻，雲波譎詭，哭遍俠客，寰宇武典心中劍。
學貫古今，上知天文，下知地理，一目十行，過目不忘。
書一頁有張瀟傻的臉龐，卻透漏著尋找著什麼的眼神....
終日喃喃自語，瘋瘋癲癲的，比”三瘋″還傷腦筋，所以被稱為書呆子。
C_LONG
);
        set ("gender", "male");
        set ("race", "dwarf");
        set_natural_armor( 30, 20 );
	set_natural_weapon(25,5,15 );
	set("hit_points",300);
	set("max_hp",300);
	set( "wealth/silver",1000);
        set("aim_difficulty",
          (["critical":50,"vascular":50,"weakest":70,"ganglion":80])) ;
        set("weight",500) ;
        set_skill("dodge",60) ;
        set_skill("parry",70) ;

}

int accept_item(object who,object item)
{
  int code;

  if ( !item->query_inked() ) {
    tell_room( environment(), 
      "書呆子嘆了口氣: 大笨瓜，沒用的東西也當寶貝？\n");
      command("give paper to "+who->query("name"));
      return 1; 
  }
  if ( (int)who->query_quest_level("lulu") >=1 ) code=1; else 
  if (who->query_temp("lulu_active")) code=2; else code=3 ;  

  if (code==3)
  write("書呆子說:嗯..這上面大概是這樣說的.......\n"
        "遠古時代, 草原上的半獸人部落, 出現一位英明的領袖嘎姆(Gammu),\n"
        "並有水、火、雷、電四位年輕將軍輔佐她, 後來嘎姆臨終時傳位給她\n"
        "年輕的女兒露露(lulu), 四位爭風吃醋的將軍, 從此不斷的發生衝突\n"
        ", 突然有一天閃電將軍帶領著一群神秘的東方殺手, 不分青紅皂白的\n"
        "展開慘不忍賭的屠殺行動, 在眾人的合力還擊下, 終於擊退敵軍, 而\n"
        "負傷累累的閃電將軍竟以自己生命做賭注, 施展可怕的黑魔法, 將全\n"
        "部的人都變成石頭 .....措手不及的露露只得先將咒語及事件始末記\n"
        "錄於石壁上... 咒語是: 伊搭釋、瓦塔拉、烏阿達、颼颼庫拉醫際嬤\n"
        "壹而撒、僕類了、撲而噎恩街、股雷特佛力為....\n"
        "突然一陣耀眼的光芒照亮的讓你幾乎看不清楚眼前的東西......\n"
        "\n"
        "\n"
        "....\n"
        "\n") ;

  command("give paper to "+who->query("name"));

  write("咦？你不禁懷疑自己是不是眼花了...怎麼眼前多了個陌生的女子？\n") ;
  tell_room( environment(), 
     sprintf("露露向%s(%s)點頭微笑，說道: 謝謝！\n",
     who->query("c_name"),who->query("name") ), who ) ;

  if (code>=2) 
    tell_object( who,"露露點頭微笑，說道: 謝謝！請再為我尋找我的將軍吧!!\n");

  if (code==3) { 
    who->set_temp("lulu_active",1);
/*
    tell_object( who, 
       "[你開始了 露露(lulu) 任務，得到 1000 點經驗]\n"
       );
    who->gain_experience(1000);
*/
     if( who ) who->set_explore("noden#38");
  }

   if( present("lulu", environment(this_object())) )
   {   this_object()->remove();
       return 1;
   }

  set("alt_corpse",CAMPMOB"lulu") ;
  die() ;
  return 1;
}
void die()
{
   ::die(1) ;
   return;
}
