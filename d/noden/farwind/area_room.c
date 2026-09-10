//#pragma save_binary

#include <mudlib.h>
#define LAST_PAGE 5
#define AREA "/doc/area/area_"

inherit ROOM;

void create()
{
	::create();
	set_short( "冒險者之家" );
	set_long(@C_LONG
你現在正站在一間充滿著祥和氣氛的大廳之中，這個大廳是用某種白
中帶著淡藍色紋路的石材建成的，一些綠色的植物和漂亮的花卉裝飾著大
廳四周的圓柱。四面的牆壁上雕刻著極為優美的圖畫。而大廳的中央有著
一本很大的書本( book )置於其中。北方有個通道, 可以通向任務殿堂。
C_LONG
	);
	
	set("item_func", ([
	    "book":"area_book",
	]) );
	
	set( "light", 1 );
	
	set( "exits", ([
		"north" : "/d/noden/farwind/quest_room",
	]) );
	
	set("book_status","close");
	set("book_page",0);
}

void init()
{
     add_action("to_open","open");
     add_action("to_close","close");
     add_action("to_read","read");
     add_action("to_turn","turn");
}

int area_book()
{
    write( 
    "探險\n"
     "一本記載著由許許多多冒險者所記錄下的各個區域的書.\n"
    );
    return 1;
}

int to_open(string str)
{
    string can_look;
    
    if (!str||str!="book") return 0;
    can_look=query("book_status");
    if ( can_look=="open" ) 
      write("這書已經被打開了.\n");
    else {
      set("book_status","open");
      write("你打開探險者之書.\n");
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
      write("你合上探險者之書.\n");
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

int to_read(string str)
{
    if (!str||str!="book") return 0;
    if ( (string)query("book_status")=="close" )
            return notify_fail("請先打開書.\n"); 
    cat(AREA+query("book_page"));
    return 1;
}

