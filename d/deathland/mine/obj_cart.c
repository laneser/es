
#include "../echobomber.h"
#include <uid.h>

inherit OBJECT;

object roomcart;

void create()
{
	seteuid(getuid());
	set_name( "Cisklyph cart", "希斯克利夫運礦車" );
	add( "id", ({ "cart" }) );
	set_short( "Cisklyph cart", "希斯克利夫運礦車" );
	set_long( "@@query_long", "@@query_c_long" );
	set( "prevent_get", 1 );
	set( "prevent_drop", 1 );
	set( "weight", 10000 );
}

void set_roomcart(object ob1) { roomcart=ob1; }
object query_roomcart() { return roomcart; }

string query_long()
{
	return
		"You see the Cisklyph cart. You can \"board\" it.\n";
}

string query_c_long()
{
	return
		"這是一臺希斯克利夫運礦車,你如果想要搭乘它,可以\n"
		"用 board 指令搭車.\n";
}

void init()
{
	add_action( "do_board", "board" );
}

int do_board(string arg)
{
	if( !arg || !id(arg) ) return 0;
	if ( roomcart->query("cart_moving") ) 
	   return notify_fail("這運礦車正快速移動著.你無法坐上它.\n");
	this_player()->move_player( roomcart , ({
	  "%s board the cart.\n","%s 坐上運礦車.\n","%s board the cart.\n","%s 坐進了運礦車.\n",
	  }));
	return 1;
}

void travel_mine()
{
     call_out("traveling",3);
}

void traveling()
{
     string dir;
     object *items,outside,cart;
     int i;
     
     cart=this_object();
     roomcart->set( "cart_moving" , 2 );
     outside = environment(cart);
     dir = outside->query("direction");
               
     switch ( dir ) {
        case "block":  
                        tell_room(outside,
                          "你只見車子撞毀在這裡. 而一些人從車子裡被拋出來.\n"
                          );
                        tell_room(roomcart,
                          "忽然  迸一聲, 車子好像重重地撞上了巖壁\n"
                          "整臺車子解體了, 而你被拋出了車外......\n"
                          "你覺得天旋地轉, 一陣頭昏目眩.\n"
                          );
                        items=all_inventory(roomcart);
                        for(i=0;i<sizeof(items);i++) { 
                          if ( living(items[i]) )  
                            items[i]->receive_damage(15);
                          items[i]->move(environment(cart));
                          }
                        roomcart->remove();
                        cart->remove();
                        break;
        case "machine":       
                        tell_room(outside,
                        "車子飛駛進來後一直處在緊急煞車的狀態, 一些人陸陸續續.\n"
                        "地被拋出來.\n"
                        );
                        tell_room(roomcart,
                        "車子一陣緊急煞車後, 終於停了下來.\n"
                        "然而你卻不小心地被拋了出來.\n"
                         "你覺得天旋地轉, 一陣頭昏目眩.\n"
                         "幸運的是你毫髮無傷\n"
                          );
                        items=all_inventory(roomcart);
                        for(i=0;i<sizeof(items);i++) 
                          items[i]->move(environment(cart));
                        roomcart->remove();
                        cart->remove();
                        tell_room(outside,
                        "只見一些矮人礦工把礦車解體, 迅速而有效率地進行著他們的工作.\n"
                        );  
                        break;
        case "abyss" : tell_room(outside,
                       "只見車子飛越了深淵, 到達了對面.\n"
                       );
                       tell_room(roomcart,
                       "你感覺到車子好像飛了起來.\n"
                       );
                       cart->move(outside->query("another"));
                       call_out("traveling",1);
                       break;
        case "special":tell_room(outside, 
                       "你見到車子衝入亂石堆內, 到達了石堆的後面.\n"
                       );
                       tell_room(roomcart,
                       "你覺得車子好像撞到了一堆石頭.\n"
                       );
                       cart->move(outside->query("another"));
                       call_out("traveling",1);
                       break;
        default: 
               tell_room(outside,({
                 "You find the cart move out here and go "+dir+".\n",
                 "你看到運礦車離開這裡往"+to_chinese(dir)+"方飛駛而去.\n",
                 }),cart);           
               tell_room( roomcart,({ 
                 "The Cisklyph cart is moving very fast.\n",
                 "希斯克利夫運礦車飛速地移動著.\n"
               }) );
     
               cart->move(outside->query("exits/"+dir));
               tell_room(environment(cart),({
                 "You find the cart moves in very fast.\n",
                 "你看到一臺運礦車快速地衝進來...\n",
                 }),cart);
               
               call_out("traveling",1);
        };
        
}
