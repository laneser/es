// File: 7,2.island.c

#include <mudlib.h>
#include "island.h"
#define GATE_OBJ "/d/island/island_gate"

inherit ROOM;
string location;

string long=("你身處在一片美麗的桃花林中，這裡正是所謂的『落英繽紛，芳草鮮\n"+
       "美』，要是仔細觀察此處的桃樹，你會發現它們以某種特殊的次序排列著\n"+
       "；在這裡站的越久，你越覺這兒的桃樹好像太密了，而且....好像會移動\n"+
       "，事有蹊蹺，你想你最好仔細觀察一下，說不定會有收穫唷！\n" );

void create()
{
        ::create();
        set_short("桃花林");
        set("long","@@query_gate");

        set_outside( "island" );
        set( "exits", ([ 
                "down"  : "/d/noden/6,6.noden",
                "west"  : ISLAND"6,2.island", 
                "north" : ISLAND"7,1.island", 
                "east"  : ISLAND"8,2.island",
                "south" : ISLAND"7,3.island",
                ]) );
        set( "original", ISLAND"7,2" );
        set( "virtual_server", ISLAND"virtual/island_server" );
        set( "x_coordinate", 7 );
        set( "y_coordinate", 2 );
        set( "no_monster" , 1 );
        reset();
}
string query_gate()
{     
        string describe;
        if (location == "virtual" )
        {
              describe = long ;
              return describe ;
        }
        else
        {
              describe = long +"嚇！ 地上竟有個閃閃發光的大洞！\n" ;
              return describe ;
        }
        
}
varargs void set_location( string new_loc , string exit )
{
        location = new_loc ;
        if (location=="virtual" || !exit )
        {
          delete("exits");
          set( "exits" , ([
                 "west"  : ISLAND"6,2.island",
                 "north" : ISLAND"7,1.island",
                 "east"  : ISLAND"8,2.island",
                 "south" : ISLAND"7,3.island",
                 ]) );
          GATE_OBJ->move( "/d/island/chaos" );
          tell_room( find_object(ISLAND"7,2.island"),@LONG
          
白光一閃，一切都恢復原樣了。

LONG
              );
        }
        else
        {
         
          set("exits" , ([
                   "down"  : exit ,
                   "west"  : ISLAND"6,2.island",
                   "north" : ISLAND"7,1.island",
                   "east"  : ISLAND"8,2.island",
                   "south" : ISLAND"7,3.island"
                         ]) );
          GATE_OBJ->move( exit );
          tell_room( find_object(ISLAND"7,2.island"),@LONG
          
林中的地面忽然隱隱發光，接著便出現一個洞穴了！

LONG
             );
        }
        
 }       
      
  
