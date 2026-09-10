#include "../oldcat.h"

inherit ROOM;

void create()
{
	::create();
    set_short("矮靈族部落");
	set_long( 
@LONG_DESCRIPTION
這裡是矮靈族部落群，西邊可通到廣場，這裡的建築物大都是石造的，少數人住
帳蓬，地上用很多石板鋪成的路貫穿整個部落，整個部落給人的感覺是非常寧靜且安
祥的，由於火山已經有很多年沒有爆發了，因此新一代的族人也慢慢的就淡忘了此事
，你見到在路的一旁有一口井(well)在這兒。
LONG_DESCRIPTION
	);
set( "exits", ([ 
     "west" : OGROUP"warea9",
     "southeast" : OGROUP"warea11",
     "northeast" : OGROUP"warea13" ]) );
set("item_desc",([
    "well":@Well
一個非常清澈的水井，但是深不見底，這是矮靈族人的水源，所以對他們很重要，
酋長派一個人在這裡看守著。
Well
   ]) );
set("objects", ([
    "wellguard":OMONSTER"wellguard" ]) );
set_outside("eastland");
reset();
}

void init()
{
  add_action("do_toss","toss");
  add_action("do_jump","jump");
}

int do_toss(string arg)
{
  string str;
  object ob,player;

  player=this_player();

  if (!arg || arg=="")
    return notify_fail("The Syntax: toss <object> into well\n");

  if (sscanf( arg,"%s into well",str) == 1) {
    ob=present(str,player);
    if (!ob)
       return notify_fail(
              "你沒有那樣東西。\n");
    if (ob->query("prevent_drop")||ob->query("secure"))
      return notify_fail(
              "你沒有辦法把它丟掉。\n");
    if (str!="bucket") {
      write("\n你把"+ob->query("c_name")+"丟入井中，只聽得噗通一聲，"+ob->query("c_name")+"慢慢的沉入井中。\n");
      ob->remove();
      return 1;
    }
    write("\n你把"+ob->query("c_name")+"丟入井中，只聽得叭□一聲，你見到"+ob->query("c_name")+"浮在水面上。\n");
    this_player()->set_temp("well",1);
    ob->remove();
    return 1;
  }
  printf("The Syntax: toss <object> into well\n");
  return 1;
}


int do_jump(string arg)
{

  if (!arg) {
    write("起乩嗎?\n");
    return 1;
  }

  if (arg=="well" || arg=="井")
  {
    if (this_player()->query_temp("mounting")) {
      write("進入井以前，請先下馬。\n");
      return 1;
    }
    if (!this_player()->query_temp("well")) {
      if ((this_player()->query_skill("swimming"))<50) {
        write("只聽得噗通一聲，你掉到水裡，你用不純熟的泳技劃了一下水，但...\n")
;
        write("咕嚕..咕嚕....你喝了好幾口水，你不禁大叫：救命啊!救命啊!\n");
        if (present("well guard",this_object())) {
          write("守衛聽到後，從井口往下望，'叫你不要自殺你偏不聽'，繩子接住，\n");
          write("你緊緊的握住繩子，守衛慢慢的把你拉出去。\n");
          return 1;
        }
        write("你見到一個人頭從井口往下望，'叫你不要自殺你偏不聽'，繩子接住，\n");
        write("你緊緊的握住繩子，那個人慢慢的把你拉出去。\n");
        return 1;
      }
      write("只聽得噗通一聲，你掉到水裡，你遊了一會兒，發現還是沒有路可以出去，\n");
      write("你只好張口呼救：救命啊! 救命啊!\n");
      if (present("well guard", this_object())) {
        write("守衛聽到後，從井口往下望，'叫你不要自殺你偏不聽'，繩子接住，\n");
        write("你把繩子綁在自己身上，守衛慢慢的把你拉出去。\n");
      return 1;
      }
      write("你見到一個人頭從井口往下望，'叫你不要自殺你偏不聽'，繩子接住，\n");
      write("你緊緊的握住繩子，那個人慢慢的把你拉出去。\n");
      return 1;
    }
    write("你奮不顧身的往井中跳去，咻.....砰，恰巧掉在你剛剛丟下去的大桶子裡。\n");
    this_player()->move_player(OTEMP"well1");
    return 1;
  }

  write("跳! 跳! '跳吼哩送' \n");
  return 1;
}
