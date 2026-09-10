//#pragma save_binary

#include <mudlib.h>
#define MOB_INFO "/d/adventurer/mob_info/"
#define LAST_PAGE 10
#define TMP_FILE "/tmp/adv_note."+getoid(this_player())
#define NOTE_FILE "/d/adventurer/data/note.txt"

inherit ROOM;
inherit DOORS;

int process();
void create()
{
	object shelter;
	::create();
        set_short("冒險者資料室");
	set_long( @C_LONG_DESCRIPTION
這裡是冒險者專屬的資料室，牆上掛著許許多多的地圖與留言板，房間的中間
是一張非常大的寫字檯，寫字檯上放著一本「旅行者手札」(note)  以及一本圖鑑
(book)。許多冒險者圍在寫字檯旁交頭接耳，不知在討論些什麼?
C_LONG_DESCRIPTION
	);

	set( "item_desc", ([ 
		"book" : @LONG_BOOK
這本「生物圖鑑」是一位叫做塔卡達的冒險家窮其一生所撰的心血結晶，圖鑑中記
載了王國內絕大部份的生物能力與簡介，某些生物極其罕見，某些則數量奇多，但
它們往往都成功的將恐懼深植人們心底。當冒險者們不小心遇上它們，經常伴隨著
恐怖且突然的死亡，但若是事前對該生物有所認識，就可以避免不幸的發生。在閱
讀之前，你可以先打開書，看看(read)這本書的索引(index)。
LONG_BOOK
,               "note" : @LONG_NOTE
這本「旅行者手札」記載了旅行者們在旅途中所見所聞，其中有些是真實的，也有
一些只是謠言及不切實際的幻想。但只有有經驗且聰明的旅行者才能分辯其真偽。
你可以使用read指令來看看上面記載的內容，也可以用write 把自己所見所聞記載
上去，但據說這本書是耶拉曼國王最喜歡的休閒讀物，在上面灌水的人將會受到皇
室嚴厲的處罰。
LONG_NOTE
 ]) );
 	set("light",1);
        set( "exits", ([
             "north" : "/d/adventurer/hall/office",
             "west" : "/d/adventurer/hall/adv_shop",
             "northeast" : "/d/adventurer/hall/adv_guild"
               ]) );
        
        set( "objects", ([
              "avery" : "/d/adventurer/hall/monsters/avery"
               ]) );
         shelter = new("/d/adventurer/hall/obj/shelter");
                 shelter->move(this_object());
         set( "pre_exit_func", ([
              "west" : "check_flag"
               ]));
        create_door("north","south",([
               "keyword":({"woodendoor","door"}),
               "status":"closed",
               "c_desc":"一個小小的木門",
               "c_name":"小木門",
               "name":"small wooden door",
               "desc":"a small wooden door",
                                ]) );
        set("book_status","close");
        set("book_page",0);       
        reset();
}

void init()
{
     add_action( "do_read", "read" ) ;
     add_action("to_open","open");
     add_action("to_close","close");
     add_action("to_turn","turn");
     add_action("write_note","write");
}
int to_open(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
    can_look=query("book_status");
    if ( can_look=="open" ) 
      write("這書已經被打開了。\n");
    else {
      set("book_status","open");
      write("你打開這本生物圖鑑。\n");
      }
    return 1;    
}

int to_close(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
    can_look=query("book_status");
    if ( can_look=="close" ) 
      write("這書已經被合上了.\n");
    else {
      set("book_status","close");
      set("book_page",0);
      write("你合上這本生物圖鑑。\n");
      }
    return 1;    
}

int to_turn(string str)
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
	if( str=="index" ) {
	    this_player()->more( MOB_INFO"c_list",0,1);
	    return 1;
	    }
	if( str=="note" ) {
	    this_player()->more(NOTE_FILE,0,1);
	    return 1;
	    }    
	if ( (string)query("book_status")=="close" ) {
	    write("請先打開書.\n");
	    return 1;
	    }
	  if ( file_exists(MOB_INFO"c_page" + query("book_page") ) ){
		this_player()->more( MOB_INFO"c_page" + query("book_page"),0,1);
		return 1;
          } else {
                cat( MOB_INFO"c_no_page") ;
                return 1;
          }          		
}
int write_note(string str)
{
	if (!str) return notify_fail("你要寫那裡啊?\n");
	if (str != "note") return notify_fail("不要亂畫喔... \n");
    write("請不要在此討論quest或灌水....\n");
    write("開始輸入文字....\n");
	this_player()->edit(TMP_FILE, "process", this_object());
	return 1;
}
 
int process()
{
    string text, title;
    seteuid(getuid());
    text = read_file(TMP_FILE);
    rm(TMP_FILE);
    title = (string)this_player()->query("c_name")+" 於 "+
        "/adm/daemons/weather_d"->query_c_game_time()+" 寫下:\n";
    write_file(NOTE_FILE, title+text+"\n");
    write("Ok.\n");
	return 1;
}
int check_flag()
{
      if ( wizardp(this_player()) || !present("avery")) return 0;
      if ((string)this_player()->query("class") != "adventurer" ) {
        tell_object( this_player(),
        "艾佛瑞說道: 那邊只有冒險者能進去...\n");
        return 1;
       }
       else return 0;                
} 

int clean_up() { return 0; }
