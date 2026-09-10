
#include "../echobomber.h"
inherit OBJECT;

void create()     
{
	seteuid(getuid());
	
	set("echo_quest_card",1);
	set("someone_id","0");
	set_name( "blackcard", "黑色卡片" );
	set_short("a blackcard","黑色卡片");
	set_long("a black card.\n", 
	   "@@query_c_long"
	    );
	add("id", ({ "card", }));
	set( "unit", "把" );
	set("weight", 30);
	set("no_sale",1);
	set("value", ({ 0, "copper" }));
}

string query_c_long()
{
      return "一張黑色的卡片,上面寫著:"+query("someone_id")+" \已經成功的證明他是一個勇者\n";

}    

void init()
{
   add_action("to_show","show");

}

int to_show(string str)
{
    string card_name,npc_name;
    object you,npc;
    if (!str) return 0; 
    if ( environment(this_object()) != ( you=this_player() ) ) return 0;
    if (sscanf(str,"%s to %s",card_name,npc_name)!=2) return 0;  
    if ( !id(card_name) ) return 0;   
    if ( !(npc=present(npc_name,environment(you))) ) { 
      write("這裡沒有這個人.\n");
      return 1;
      }
    if ( ! npc->query("echo_valor") ) { 
       write( sprintf("%s 看了一下你的卡片, 但是沒有任何反應.\n",npc->query("c_name")) );   
       return 1;
       }
    else return npc->echo_valor(you,this_object()); 

}