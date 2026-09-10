#include <mudlib.h>
#include "camp.h"
inherit ROOM;

void create()
{
	::create();
   set_short("地道");
   set_long( @LONG_DESCRIPTION
這條神秘的地道，建造的年代似乎相當久遠，但是卻相當的寬敞與堅固，壁上鑲
鑲著耀眼明亮的珠子，照亮整個通道，壁上還繪著奇奇怪怪的動物圖案，與不知名的
古文，相當吸引人的留意。門上還各有個牌子(sign)。
LONG_DESCRIPTION
);

   set("light",1);
   set( "exits", ([ 
    "up"   : CAMP"camp4",   
    "east" : CAMP"camp6",  
    "west" : CAMP"camp8", 
   ]) ) ;

   set( "item_func", ([ 
    "sign":"look_sign", 
   ]) ) ;

   set( "objects", ([ 
	"mob1" : CAMPMOB"mob1"
   ]) );

   reset();
}

// int look_sign()
// {
//  write("    /~~~~~~~~~~~~~~~~~~~~~~~~~~~/~\\  \n"
//        "   | It is a great invention   |___| \n"
//        "   |     of ink && paper ..    |     \n"
//        "/~~~~~~~~~~~~~~~~~~~~~~~~~~/   |     \n"
//        "\\__________________________\\__/      \n") ;
//   return 1 ;
// }


int look_sign()
{
 write("    /~~~~~~~~~~~~~~~~~~~~~~~~~~~/~\\  \n"
       "   |    這是一大發明           |___| \n"
       "   |            墨水和紙張     |     \n"
       "/~~~~~~~~~~~~~~~~~~~~~~~~~~/   |     \n"
       "\\_________________________\\__/      \n") ;
  return 1 ;
}
