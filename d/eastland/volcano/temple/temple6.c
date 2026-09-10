#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮靈族神殿");
	set_long(
@LONG_DESCRIPTION
一間迷漫著神秘氣氛的矮靈族神殿正殿，正殿的頂端雕有火神的圖案，一根
有龍紋的巨大柱子(post)豎在腳落，牆壁上雕滿了許多奇怪的花紋，地板是用一
塊塊的火山岩拼成的。
LONG_DESCRIPTION
	);
set( "exits", ([
     "northeast": OTEMP"temple10",
     "west": OTEMP"temple4",
     "south": OTEMP"temple3",
     ]) );
set("item_desc",([
    "post" : @POST
一條死氣沉沉的黑龍，全身是亮黑色的，一層層的黑色鱗片閃閃發亮，兩眼
無神的看著你。
POST
       ]));
set( "search_desc", ([
     "post":"@@search_post",
 ]) );
set("light",1);
reset();
}

string search_post()
{
  string str;

  if ((this_player()->query_quest_level("Dragon_box"))>1) 
    return "\n黑龍道：希望你也能早日修成正果，早登仙界。\n\n";

  if (this_player()->query_temp("dragon_box")) {
    if (present("dragon_box",this_player())) {
      return "\n在這段日子裡，我每天在這裡和長老感應，聽了他的感化，我已決心定下心\n"+"來在這裡繼續修行，那個寶盒我不需要了，你拿給長老吧。\n\n";
     this_player()->set_temp("dragon_box",2);
    }
    return "\n我的寶盒呢? 找到了嗎? \n\n";
  }
   
  if (this_player()->query_temp("gogo")) {
    str="\n黑龍用心電感應告訴你：快去找吧，在這裡磨蹭磨蹭什麼。\n";
    return str;
  }
  
  if (this_player()->query_temp("dragon_help2")) {
    str="\n黑龍又一次的竄出來，\n"+
        "\n黑龍說：你耳聾嗎? 講這麼多次都不知道，明天再來吧!\n";
    return str;
  }

  if (this_player()->query_temp("dragon_help1")) {
    str="\n那黑龍又竄了出來，黑龍說道:又有啥事?\n"+
        "\n你說：到底是找什麼東東呢?\n"+
        "\n黑龍說：我剛剛不是告訴你了嗎，找我掉的寶盒(box)啊！\n"+
        "\n你說：喔．我明白了。\n"+
        "\n黑龍說：不要再忘了喔，我不會說第三次。\n"+
        "\n黑龍說完，又回到柱子上了。\n";
    this_player()->delete_temp("dragon_help1");
    this_player()->set_temp("dragon_help2",1);
    return str;
  }
  
  str="\n一條黑龍從柱子上竄了出來，你正準備攻擊它時，發現它飛舞在你的前面，\n"
     +"且眼睛眨呀眨的，看起來它對你是毫無敵意。\n"
     +"\n當你不知道該怎麼辦的時後，\n\n"
     +"黑龍突然開口對你說：可以幫我一個忙嗎 ?\n\n"
     +"你說：當然可以，只要我能力所及。\n\n"
     +"黑龍說：在很久很久以前，東方大陸曾發生鉅變，我的一個東西因此失落\n"
     +"        了，你可以幫我把它找回來嗎？\n\n"
     +"你說：喔 ! 小事一件，看我的吧 !\n\n";
  this_player()->set_temp("dragon_help1",1);
  this_player()->set_temp("gogo",1);
  call_out("forget",60,this_player());
  return str;
}

int forget(object who)
{
 this_player()->delete_temp("gogo");
 write("\n\n過了一會兒，你才想到，你根本就不知道黑龍到底要你找啥。\n\n");
  return 1;
}
