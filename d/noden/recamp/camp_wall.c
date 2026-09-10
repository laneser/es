#include <mudlib.h>
#include "camp.h"
inherit ROOM;

int apply_wall ; // 表示已經上墨
int apply ;      // 表示 apply 可用於此
int papermob ;     

void create()
{
	::create();
	set( "clean", 0);
        apply = 1 ; 
	set( "apply",1) ;
	apply_wall = 0 ;
	set( "apply_wall",0) ;
        papermob = 0 ;
	
    set_short( "石室" );
	set_long( @C_TOPIC
這間石室空空湯湯的，而且光線又不太充足，角落處好像有什麼在動，石室
正前方壁上(wall)，則劃滿了一堆奇怪的古文。你上前仔細看看，不禁訝異是何
人以指力刻劃留下的。旁邊地上放了個箱子(box)，看來以很久沒人動過了。
C_TOPIC
);

	set( "search_desc", ([
	  "box"   : "@@search_box",
            "here" :  "@@search_here",
	]) );

	set( "item_func", ([ 
	                      "box"   : "msg_box",
	                      "wall"  : "msg_wall",  ]) );

	set( "exits", ([ "up" : CAMP"camp7" , "west" : CAMP"camp9" ]) );

        set("objects",([
           "cat#1" : CAMPMOB"cat", 
           "cat#2" : CAMPMOB"cat", 
           "rat" : CAMPMOB"rat", 
        ]) ) ;

	reset();
}

string search_box()
{
    object ob;
    if( this_object()->query("clean") ) return 0;
    ob = new( CAMPOBJ"bstone" );
    ob->move(this_object());
    this_object()->set( "clean", 1 );
    return "你打開箱子，結果掉出了一塊黑色石頭。\n"; 
}

string search_here()
{
    object ob;
    if ((papermob) || present("sheet",this_object()) ) return
      "你找了老半天，並沒有找到什麼東西!!\n" ; 
    else {
      ob = new( CAMPMOB"paper_mob" );
      ob->move(this_object());
      papermob = 1 ;
      return "突然間好像什麼一個白衣長髮的東西飄了過去，你不禁嚇出一身冷汗。\n"; 
    }
}

int msg_box()
{
    write("塵封的木箱，看來毫不起眼，還沾了些墨似的。\n"
    );         
    return 1;
}

int msg_wall()
{
  if (!apply_wall) {
  write("這片石壁上刻滿了奇怪的文字，也許是武林秘笈喔，想辦法拓印下來吧。\n" );
  } else {
  write("石壁上刻滿了奇怪的文字，而且已經上墨了，也許會乾掉吧!!\n") ;  
  }
  return 1;
}

void to_find_wall( string arg )
{
  write(
    "你用黑色石頭將石壁上文字都塗上一遍，累的滿身大汗。\n"
  );
//  this_player()->set_explore("noden#9");
  apply_wall = 1;
  set( "apply_wall", 1);
  call_out("ink_no",200) ;
}

void ink_no()
{
  set( "apply_wall", 0);
  apply_wall=0 ;
}

void reset()
{
    ::reset();
    set( "clean",0);
    apply_wall = 0 ;    
    set( "apply_wall",0) ;
   papermob = 0;
}
