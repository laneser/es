#include "../iigima.h"
#include <stats.h>
#include <conditions.h>
// Created by Iigima , modified by Smore@Eastern.Stories in 8/20/1996
inherit MONSTER ;

void create ()
{
        ::create();
        set_level(15);
        set_name( "Salin","神官薩林" );
        add ("id", ({ "drow","salin" }) );
        set_short( "Salin","神官薩林" );
        set("unit","位");
        set("alignment",1100);
        set("weight",800);
        set("wealth/copper",4000);
        set( "weight", 600 );
        set( "tactic_func", "my_tactic" );
        set_long(
@C_LONG
這位老婦人是黑暗精靈的領導者，看她的外表好像已有數百歲了，戴
著一頂高高的帽子，想必她也曾是一位祭司吧，溫和的眼光中流露著
智者的風範，最近黑暗精靈村要將女祭司送往祭神 (god)，薩林正在
為此忙碌著。
C_LONG
        );
        set_perm_stat("int", 25);
        set_perm_stat("dex", 16);
        set_perm_stat("str",18);
        set("max_hp",550);
        set("hit_points",550);
        set_natural_weapon( 10, 10, 20 );
        set_natural_armor( 25, 20 );
        set( "special_defense", ([
                "all":30,"fire":-10,"cold":-10,
                "evil":80,"divine":-50,"none":20
                        ]) );
        set ("race", "drow");
        set ("gender", "female");
        set_c_limbs(({"身體","頭部","腳部"}));
        set( "chat_chance", 14 );
        set( "chat_output", ({
           "神官一臉難色，好像有很多困擾。\n",
           "薩林說：好煩喔，祭祀不能荒廢，可是村人又不諒解.....\n",
           "神官喃喃的說：如果拿到蛇窩草(snake herb)，一切就好辦了...\n"
                          }));
        set( "inquiry", ([
        "god" : ({
"哎...祭神是我們黑暗精靈的傳統，每年都要獻上一位女祭司給司娜可女神。\n"
                }),
        "teeder" : ({
"蒂德嗎？我也知道她是潘恩的心上人啦，但是她是祭司，我又能如何呢？\n"
               }),
        "snake herb" : ({
"蛇窩草？你有蛇窩草嗎？那是我製藥(drug)的關鍵耶！\n"
              }),
        "drug" : ({
"嗯，我正在製造一種能防止禁斷之地的蛇類(snake)進入我們村落的藥粉\n"
"但是就是獨缺這蛇窩草，所以作不出藥來，真糟糕！\n"
                 }),
        "snake" : ({
"你能幫我拿到蛇窩草嗎？但是禁斷之地是不能進去的，那裡很危險\n"
"嗯...聽說有個冒險家(adventurer)..好像曾經去過禁斷之地......\n"
                 }),
        "adventurer" : ({
"好像叫奇什麼的，你去找找吧，我也不認識這個人耶。\n"
                 })
            ]) );
   wield_weapon( OBJ"wand" );
   equip_armor( ARM"robe" );
   equip_armor( ARM"lucky_cloak" );
   equip_armor( ARM"lucky_shoes" );
   equip_armor( ARM"lucky_ring" );
}
int accept_item(object me, object item)
{
   string name;
   object ob;
   int i;

   name=(string)item->query("name");
   if (!name || (name!="snake herb"))
     return 1;
write("薩林說道：太好了！我就是要這蛇窩草，謝謝你幫助我們村落\n");
write("薩林在她的長袍裡摸摸找找，好像要拿出什麼東西......\n");
   if (!this_object()->query("key")){
     write("薩林說道：嗯，這鑰匙給你吧，多拿些蛇窩草給我喔！！\n");
     ob = new( OBJ"key" );
     ob->move(this_player());
     set("key",1);
   }
   else
write("神官薩林緩緩說道：看來有人捷足先登了，鑰匙已經沒有了。\n");
   return 1;
}
int my_tactic()
{
   object *victim,env;
   int i,n;
   env=environment(this_object());
   if ( !victim = query_attackers() ) return 0 ;
   if( random(20)>4 ) return 0;
    else {
    tell_room( environment(this_object()),
    "薩林緩緩吟誦黑魔法中恐黑術的咒文: 沙美翁，奈斯特羅.....\n"
            "你發現一陣黑霧籠罩在你身上，你的意識漸漸模糊...\n\n",
     this_object() );
      for( i=0; i<sizeof(victim); i++ ) {
      n = i + 1;
      if( n == sizeof(victim) ) n = 0;
      (CONDITION_PREFIX + "confused")->apply_effect( victim[i], 15, 5);
  if( sizeof(victim) == 1 ) {
      tell_room( env,
      victim[i]->query("c_name")+
      "突然開始攻擊"+victim[n]->query("c_name")+"。\n",
          victim[i]);
      victim[i]->cease_all_attacks();
      victim[i]->kill_ob(victim[n]);
  }
      return 1;
 }
 }
}
