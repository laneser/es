#include "../echobomber.h"
//#define CART_OBJ "/obj_cart"

inherit ROOM;

object cartobj;

void create()
{
	::create();
	set("cart_moving",0);
//         set_name( "Cisklyph cart", "希斯克利夫運礦車");
	add( "id", ({ "cart" }) );
	set_short("Cisklyph cart", "希斯克利夫運礦車");
	set_long( "\n", "@@query_c_long" );
	set( "light", 1 );
	set("exits",(["leave":Mine"/factory"]));

}

void init()
{
  add_action("do_press","press");
}

void set_objcart(object ob1) {  cartobj=ob1; }
object query_objcart() { return cartobj; }
int clean_up() {  return 0; }

string query_c_long()
{
	string long;

	long = 
"你現在正坐在希斯克利夫運礦車裡面.這車已經被改裝成載人專用.\n"
"車子的前面有一個按鈕(button),似乎是啟動的開關.你可以試著去\n"
"按(press)它\n" ;	
	switch( query("cart_moving") ) {
		case 0:
			long += "目前希斯克利夫運礦車正停在精□廠裡.\n";
			break;
		case 1:
			long += "希斯克利夫運礦車緩緩地移動著.\n";
			break;
	    case 2:
	        long += "希斯克利夫運礦車飛速地移動著.\n";
	} 
	return long;
}

int do_press(string button)
{
    if (!button || button !="button") return 0;
    
    write("你伸手去按那個按鈕.\n");
    tell_room(this_object(),"你看到"+this_player()->query("c_name")+"伸手去按按鈕.\n"
              ,this_player());
    this_player()->set_explore("deathland#16");
    call_out("will_go",4);
    return 1;
}

int will_go()
{
    object Acart;
    
    set("cart_moving",1);
    set("exits",([]));
    tell_room(environment(this_object()),"一陣輕微的震動,希斯克利夫運礦車駛出精□廠,開始進入矮人礦坑.\n");
    if( cartobj )
      cartobj->travel_mine();
}

