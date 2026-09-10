#include <mudlib.h>

inherit OBJECT;
int in_use;

void init()
{
	add_action( "catch_tail", "catch" );
}

void create(){

	set_name("wind tail","風之尾巴");
        add("id",({"wind","tail",}) );  
	set_short("風之尾巴");
	set_long(@C_LONG
風之尾巴是一隻小小的尾巴,它是風神小時候貪玩而撞斷掉的尾巴... 
風神最討厭別人抓它的尾巴,所以把它的尾巴藏了起來,卻被快速龜偷拿出來玩 
聽說抓住(catch)這隻尾巴(tail)後,你將擁有風的速度...
C_LONG
                 );
        set("value" , ({10,"silver"}) );
        set("weight",10);
	set("unit","只");
}

int catch_tail(string arg)
{
        if( arg != "tail") return 0;
        if (!in_use)
       {  
        in_use =1;
        
	set("prevent_drop",1); 
        set_short("風之尾巴正發揮效用中"); 

	write( 
"你抓住了風之尾巴，一陣大風從你的身旁吹起，你覺得自己變輕了... \n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"抓住了風之尾巴，一陣大風吹動了他的身軀。\n",
		this_player() );
 
	this_player()->modify_stat("dexterity",2);
	call_out("restore",30,this_player());
	return 1;
        }
}

void restore(object player){

	tell_object(player, 
		"圍繞在你身旁的風聲漸漸的變小了...\n");
	this_player()->modify_stat("dexterity",-2);
        remove(); 
}
