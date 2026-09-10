#include <mudlib.h>

#define TMP_FILE "/tmp/monk.paper."+getoid(this_player())
#define WALL_FILE "/d/monk/doc/wall.txt"
#define MONK_PAGE "/d/monk/doc/monk_info/"
#define LAST_PAGE 10

inherit ROOM;

void create()
{
  object yuu;
  ::create();
  set_short("Monk's history room", "少林寺功德坊");
  set_long(
@C_LONG_DESCRIPTION
這□是記錄少林武僧歷代以來建立所立下的功德的地方。偌大的空曠房間
左右兩邊都有名人排行榜(scroll)，你可以張大眼睛瞻仰瞻仰。房間的中央擺\
著的據說是少林寺開派祖師爺--達摩--的雕像(statue)。由於傳說中，只要你
誠心誠意撫摸它，功力會大增，所以這座雕像已經模糊不堪了。
    你的眼光快速的掃瞄四周，在不顯眼的牆角擺著一張滿是灰塵的□□米，
看來是前輩高僧們結跏趺坐的地方。□□米的上方有一卷紙畫(paper),上面到
處都是斷斷續續的線條，你心裡想著：難道是武功心得所在?
C_LONG_DESCRIPTION
  );

  set ( "light", 1 );
  set ( "item_desc", ([
        "book" : @BOOK_LONG
        這本書的封面寫著大大的幾個字 : 少林武僧錄
        
    這幾個字看來龍飛鳳舞的, 你心裡想這裡面記載的一定是十分有名的前輩的事蹟。
讓你很想將他翻開 (open) 來讀 (read) ....... 

BOOK_LONG
      ]) );
  set ( "book_statue" , "close" );
  set ( "book_page" , 0 );
  set ( "item_func", ([
    "scroll" : "look",
    "paper"  : "look",
    "statue" : "look"
  ]) );
  set ( "exits", ([ 
    "west" : "/d/monk/guild/gonfu_room1"
  ]) );

    yuu = new("/d/monk/guild/monsters/taker");
    yuu->move(this_object());
	reset();
}

int clean_up() { return 0; }

void init()
{
  add_action ( "do_look", "look" );
//  add_action ( "do_open", "open" );
//  add_action ( "do_close", "close");
//  add_action ( "do_read", "read" );
//  add_action ( "do_turn", "turn" );
  add_action ( "do_write", "write" );
}

int do_open(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
        can_look=query("book_status");
    if ( can_look=="open" )
        write("這書已經被打開了。\n");
    else {
        set("book_status","open");
        write("你打開這本少林武僧錄。\n");
    }
    return 1;
}

int do_close(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
        can_look=query("book_status");
    if ( can_look=="close" )
        write("這書已經被合上了.\n");
    else {
        set("book_status","close");
        set("book_page",0);
        write("你合上這本少林武僧錄。\n");
    }
    return 1;
} 

int do_turn(string str)
{
    mixed page;
    
    if (!str) return 0;
    else if ( str=="page" )
    {
       if ( (string)query("book_status")=="close" )
             return notify_fail("請先打開書.\n");
       page=(int)query("book_page")+1;
       page=(page==LAST_PAGE)?0:page;
       write("你把書翻到了第"+ page +"頁.\n");
       set("book_page",page);
    }
    else if ( sscanf(str,"page to %d",page)==1 )
    {
       if ( (string)query("book_status")=="close" )
            return notify_fail("請先打開書.\n");
       write("你把書翻到了第"+ page +"頁.\n");
       set("book_page",page);
    }
    else
       write("翻書的方法如下:turn page or turn page to <num>.\n");
    return 1;
}
                                                
int do_read( string str )
{

    if( !str || str=="" ) {
        write("你要讀什麼？\n");
        return 1;
    }
    if ( (string)query("book_status")=="close" ) {
        write("請先打開書.\n");
        return 1;
    }             
    if ( file_exists(MONK_PAGE"c_page" + query("book_page") ) ){
        this_player()->more( MONK_PAGE"c_page" + query("book_page"),0,1);
        return 1;
    } else {
        cat( MONK_PAGE"c_no_page") ;
        return 1;
      }
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
    這座達摩雕像正前方的桌子上放著一本書(book), 看起來還蠻新的。
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
  return 0;
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

  text = read_file (TMP_FILE);
  rm (TMP_FILE);
  title = (string)this_player()->query("c_name")+" 於 "+
        "/adm/daemons/weather_d"->query_c_game_time()+" 寫下:\n";
  write_file ( WALL_FILE, title+text+"\n" );
  write ( "你終於將心得寫完了.\n" );
  return 1;
}
