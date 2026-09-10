//#pragma save_binary

// room desc translation done -Elon 03-10-94
// minor fix on informative text.. just to make English reading easier..
#include "../moyada.h"
inherit ROOM;

int move, open;
void create()
{
	::create();
	set( "move", 0);
	set( "open", 0);
	move = 0;
	open = 0;
	set( "clean", 0);
	set( "excavate", 1);
    set_short( "儲物室" );
	set_long( @C_TOPIC
這裡是一間老舊的儲藏室，牆角(wall)、天花板到處佈滿蜘蛛網，地上
一層厚厚的灰塵。一些雜七雜八的東西到處散置，也許你能整理好它。這裡
放了個大鐵箱(iron box)，地上還有一些奇怪的軌跡(track)。
C_TOPIC
	);
	set( "search_desc", ([
	  "boxes" : "@@search_box",
	  "box"   : "@@search_box",
	]) );
	set( "item_func", ([  "boxes" : "msg_box",
	                      "box"   : "msg_box",
	                      "track" : "msg_track",
	                      "hole"  : "msg_hole",
	                      "wall"  : "msg_wall",  ]) );
	set( "exits", ([ "up" : MOYADA"shop/wanfu_shop" ]) );
    set( "objects", ([
		"rat#1" : FARWIND"monster/rat",
		"rat#2" : FARWIND"monster/rat",
	]) );
	reset();
}

void init()
{
    add_action("to_move_box", "move");
    add_action("to_enter_hole", "enter");
}
string search_box()
{
    object ob;
    if( this_object()->query("clean") ) return 0;
    ob = new( MOYADA"obj/shovel" );
    ob->move(this_object());
    this_object()->set( "clean", 1 );
    return "你打開箱子仔細搜索，發現這箱子裡面原來放了一把小鏟子。\n"; 
}

int msg_box()
{
    write("生鏽的大鐵箱，上面刻著十分精製的圖案，好像是中國製造的。\n"
    );          /* hmm.. political issue here */
    return 1;
}

int msg_track()
{
    write( "這軌跡看起來像是移動重物造成的。\n");
    return 1;
}

int msg_hole()
{
    if( !move || !open )
      return notify_fail("這裡沒有洞啊!\n");
    write(
    "裡面烏漆麻黑的，不知道會有甚麼，也許你可以進去(enter)試試看。\n"
    );
    return 1;
}

int msg_wall()
{
    if( !move )
      write( "這些牆都是用上好的磚堆砌而成，看來十分堅硬。\n" );
    else if( !open )
      write( 
        "你仔細檢察鐵箱後的牆壁，發現磚堆得有點鬆散，而且好像是\n"
        "最近才砌成的。\n" 
      );
    else
      write( "鐵箱後的牆壁上有一個洞，不知是被誰鑿開的。\n" );
    return 1;
}

int to_move_box( string arg )
{
    string dir;
    
    if( !arg )
      return notify_fail("Syntax: move <object> to <direction>.\n");
    if( sscanf( arg, "box to %s", dir )==1 ) {
      if( dir == "south" && !move ) {
        write( "你把鐵箱向南一推，輕易的就把它推開。\n" );
        move = 1;
        set( "move", 1);
      } else if( dir == "north" && move ) {
        write( "你把鐵箱向北一推，輕易的就把它推回原位。\n" );
        move = 0;
        set( "move", 1);
      } else if( dir == "north" || dir == "south" || 
                 dir == "west" || dir == "east" )
        write( "你使盡吃奶的力氣，還是推不動它！\n" );
      else
        write( "你想把它推到那裡？\n" );
      return 1;
    } else 
      return notify_fail("Syntax: move <object> to <direction>.\n");
}

int to_enter_hole( string arg )
{
    if( !arg || arg != "hole" )
      return notify_fail("你要進哪裡去?\n");
    if( move && open )
      this_player()->move_player(MOYADA"shop/hole","SNEAK");
    else
      write("這裡沒有洞啊!\n");
    return 1;
}

void to_find_excavate( string arg )
{
      if( arg != "wall" )
        write("That can't be excavated!\n");
      else if( !move )
        write( can_read_chinese() ?
          "這裡的牆十分堅硬，差點就把工具弄壞！\n" :
          "The wall is so strong to excavate!\n"
        );
      else if( open )
        write( can_read_chinese() ?
          "這牆已經被鑿出一個洞了！\n":
          "That wall has been excavated!\n"
        );
      else {
        write(
          "你用盡了所有的力量鑿牆，流了滿身大汗。漸漸地，牆出現了\n"
          "裂縫。你最後奮力一擊，牆終於塌了，出現了一個洞穴(hole)。\n" 
        );
        this_player()->set_explore("noden#9");
        open = 1;
        set( "open", 1);
      }
}

void reset()
{
    ::reset();
    set( "clean",0);
    set( "move", 0);
    set( "open", 0);
    move = 0;
    open = 0;
}
