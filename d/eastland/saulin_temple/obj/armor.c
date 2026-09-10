#include <mudlib.h>

inherit OBJECT;
int in_use;

void init()
{
	add_action( "drink_wine", "drink" );
}

void create(){

	set_name("angel kiss","天使之吻");
        add("id",({"wine","kiss","angel kiss"}) );  
	set_short("天使之吻");
	set_long(@C_LONG
天使之吻是一杯被天使祝福過的酒,它其中的紅色光澤散發出一股神秘而迷人的幽香 
它的來源,相傳有一個美麗而哀怨的吉普賽女郎的故事,可以用以預測愛情. 而此地的 
天使之吻,是由天使調製的,聽說喝了(drink)這杯酒(wine)後,將帶給你無比的幸運...
C_LONG
                 );
        set("value" , ({10,"silver"}) );
        set("weight",10);
	set("unit","杯");
}

int drink_wine(string arg)
{
        if( arg != "wine") return 0;
        if (!in_use)
       {  
        in_use =1;
        
	set("prevent_drop",1); 
        set_short("天使之吻正發揮效用中"); 

	write( 
"你喝下了這杯天使之吻，一股幸福快樂的感覺從你的心中升起，你覺得自己好幸運 \n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"喝下了一杯天使之吻，一群白色的天使圍繞在他的身旁。\n",
		this_player() );
 
	this_player()->set_temp("extra_db",20);
	call_out("restore",60,this_player());
	return 1;
        }
}

void restore(object player){

	tell_object(player, 
		"圍繞在你身旁的天使慢慢地飛走了...\n");
	this_player()->set_temp("extra_db",0);
        remove(); 
}
