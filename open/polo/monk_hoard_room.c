#include <mudlib.h>

#define TMP_FILE "/tmp/monk.paper."+getoid(this_player())
#define WALL_FILE "/d/monk/doc/wall.txt"

inherit ROOM;

void create()
{
  ::create();
  set_short("Monk's history room", "少林寺功德坊");
  set_long(
@C_LONG_DESCRIPTION
這裡是記錄少林武僧歷代以來建立所立下的功德的地方。偌大的空曠房間
左右兩邊都有名人排行榜(scroll)，你可以張大眼睛瞻仰瞻仰。房間的中央擺\
著的據說是少林寺開派祖師爺--達摩--的雕像(statue)。由於傳說中，只要你
誠心誠意撫摸它，功力會大增，所以這座雕像已經模糊不堪了。
    你的眼光快速的掃瞄四周，在不顯眼的牆角擺著一張滿是灰塵的榻榻米，
看來是前輩高僧們結跏趺坐的地方。榻榻米的上方有一卷紙畫(paper),上面到
處都是斷斷續續的線條，你心裡想著：難道是武功心得所在?
C_LONG_DESCRIPTION
  );

  set ( "light", 1 );
  set ( "item_func", ([
    "scroll" : "look",
    "paper"  : "look",
    "statue" : "look"
  ]) );
  set ( "exits", ([ 
    "west" : "/d/monk/guild/gonfu_room1"
  ]) );

  set( "objects", ([
    // "list"    : MATE"/daemons/list",
//    "mayumei" : MATE"/monster/toy_girl",
    "yuu"     : "/d/monk/guild/monsters/taker" ]) );
	reset();
}

int clean_up() { return 0; }

void init()
{
  add_action ( "do_look", "look" );
  add_action ( "do_touch", "touch" );
  add_action ( "do_brood", "brood" );
  add_action ( "do_write", "write" );
}

int do_look ( string arg )
{
  object player;
  string name;
  int i;
  object *me;

  player = this_player();
  name =  player->query( "c_name" );
    
  if ( !arg ) return 0;
  else if ( arg == "paper" ) {
    this_player()->more (WALL_FILE);
    return 1;
  }
  else if ( arg == "statue" ) {
    tell_object ( player, @LONG
由於年代久遠，眼前的達摩雕像，竟有八分像傳說中的小天使--Angel,一位有史以來
就被武僧公會的小光頭們傳為神話的喵喵。當你再仔細左瞧右瞧，發現了另一個神話
人物的影子--ruby。也許是她們兩位的精神灌注在這個雕像中的關係吧?!
    你一發現這事實，忍不住心中的衝動想去摸摸(touch)這個雕像(statue)。
LONG
  );
    tell_room (
      environment (player),
      name + "摸了摸眼前的達摩雕像，法喜充滿心中。\n",
      player );
    return 1;
  }
  else if ( arg == "scroll" ) {
    me = users();
    for( i=0; i<sizeof(me); i++ )
      "/d/monk/guild/misc/topmonks"->log_player(me[i]);
    write (
      (string)find_object_or_load ( "/d/monk/guild/misc/topmonks")->get_list() );
    tell_object ( player, "你盯著排行榜看呀看的，心中越來越崇拜前人所立下的功德\n" );
    tell_room (
      environment (player),
      name + "盯著排行榜看呀看的，滿臉激動興奮的表情。\n",
      player );
    return 1;
  }
  else if ( arg == "tatami" ) {
    tell_object ( player,
      "你把注意力集中在榻榻米上面，心裡想著:\n" +
      "  也許在上面打坐(brood) 可以感召到前輩們的精神!!\n");
    tell_room (
      environment (player),
      name + "盯著滿是灰塵的榻榻米看呀看的，不會是想睡一覺吧?!\n",
      player );
    return 1;
  }
  return 0;
}    

int do_touch ( string arg )
{
  object player;
  string name;

  player = this_player();
  name =  player->query( "c_name" );
    
  if( !arg || arg != "statue" ) {
    tell_object ( player, "這是什麼地方你知道嗎? 不要隨處亂摸!!\n");
    tell_room (
      environment (player),
      name + "鬼鬼祟祟的在這兒亂摸，不知想幹什麼。\n",
      player );
    return 1;
  }
  tell_object ( player, 
    "  你恭恭敬敬地摸了達摩尊者的雕像，突然醒悟到:\n" +
    "啊! 原來更加勤奮的唸經、超渡、學武才是武僧之道啊!!\n" +
    "  於是你把眼光放到牆角的榻榻米(tatami)，看它陳舊的\n" +
    "樣子，大概是前輩們結跏打坐的地方吧!!\n"
  );
  tell_room (
    environment (player),
    name+"恭敬地在達摩尊者的雕像上摸了摸，似乎領悟到至理而發出會心一笑 ^_^\n" +
    name+"的眼光集中在放置在牆角的榻榻米上面。\n",
    player );
  return 1;
}

int do_brood (string arg)
{
  object me;

  me = this_player();
  if ( (int)me->query_temp ( "brood_flag" ) == 1 ) {
    tell_object ( me, "常常去找先聖先賢會被敲腦袋哦，等一下再入定參禪吧!!\n");
    return 1;
  }
  if ( !arg || arg != "tatami" ) {
    tell_object ( me, "隨處亂打坐怎麼對得起先聖先賢?\n");
    return 1;
  }
  tell_object ( me, "你靜下心來在榻榻米上結跏, 思想逐漸空明, 進入忘我無我之境...\n");
  tell_room ( environment (me), "你發現"+
    me->query ( "c_name" )+"不管三七二十一, 坐在榻榻米上面好像雕像一般。\n",
    me);
  me->set_temp ( "block_command", 1 );
  call_out ( "result", 2+random(2), me, 4+random(7), this_object() );
  return 1;
}

void result (object me, int count, object place)
{
  string mtd;
  int fp, max;
  int level, alignment, monk_score;
  int enough;

  fp = (int)me->query ( "force_points" );
  max = (int)me->query ( "max_fp" );
  level = (int)me->query_level ( );
  alignment = (int)me->query ( "alignment" );
  monk_score = (int)me->query ( "monk_score" );
  // tell_object ( me, "[Info from mate] level : "
  //   + level + " alignment : " + alignment + " monk_score : " + monk_score + "\n" );
  if ( level >= 15 && alignment >= 5000 && monk_score >= 1000 )
    enough = 1;
  else
    enough = 0;
  if ( count > 0 && fp < max ) {
    fp = fp + 8 + random (max/30);
    if ( fp > max ) fp = max;
    tell_object ( me, "..................................\n" );
    if ( enough == 1 ) me->set ( "force_points", fp );
    count--;
    call_out ( "result", 2+random(2), me, count, place );
    return ;
  }
  me->delete_temp ( "block_command" );
  tell_object ( me, "一陣沉思之後, 你的思想逐漸爽朗, 慢慢回到了現實。\n" );
  tell_room ( place,
    me->query ( "c_name" )+"滿臉灰塵地從榻榻米上站了起來。\n",
    me
  );
  me->set_temp ( "brood_flag", 1 );
  call_out ( "reset_brood", 200, me );
  return ;
}

int reset_brood (object me)
{
  if (me) {
    tell_object ( me, "你發現自己在先聖先賢們的思路中，漸行漸遠....\n" );
    me->delete_temp ( "brood_flag" );
  }
  return 1;
    
}

int do_write (string str)
{
  if (!str) return notify_fail ( "你要寫那裡啊?\n" );
  if ( str != "paper" ) return notify_fail("*** 這-裡-是-功-德-坊 *** 嚴-禁-亂-塗 ***\n" );
  write("請開始輸入文字 -->\n");
  this_player()->edit(TMP_FILE, "process", this_object());
  return 1;
}

int process()
{
  string text, title;

  // seteuid(getuid());
  text = read_file (TMP_FILE);
  rm (TMP_FILE);
  title = (string)this_player()->query("c_name")+" 於 "+
        "/adm/daemons/weather_d"->query_c_game_time()+" 寫下:\n";
  write_file ( WALL_FILE, title+text+"\n" );
  write ( "你終於將心得寫完了.\n" );
  return 1;
}
