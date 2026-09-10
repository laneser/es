#include <mudlib.h>

inherit OBJECT;
int in_use;

void init()
{
	add_action( "light_pastil", "light" );
}

void create(){

	set_name("pastil","奧丁的沉香");
	set_short("奧丁的沉香");
	set_long(@C_LONG
奧丁大神掌管天地間一切的力量,是戰士們最敬愛的守護神...
『奧丁的沉香』是大祭司用來祭祀奧丁大神的香料,是極其名貴的物品
相傳點燃(light)它的人可以得到大神的祝福,獲得無比的力量...
C_LONG
                 );
        set("value" , ({10,"silver"}) );
        set("weight",10);
	set("unit","束");
}

int light_pastil(string arg)
{
        if( arg != "pastil") return 0;
        if (!in_use)
       {  
        in_use =1;
        
	set("prevent_drop",1); 
        set_short("一股藍色的煙霧正籠罩著你"); 

	write( 
"你點燃了這束奧丁大神的沉香，一股藍色的煙霧籠罩住你的身體，你覺得自己變強了 \n"
	);
	tell_room( environment(this_player()), 
		this_player()->query("c_name")+"點燃了一束沉香，突然你見到奧丁大神的身影籠罩住他的身軀。\n",
		this_player() );
 
	this_player()->modify_stat("armor_class",10);
	call_out("restore",30,this_player());
	return 1;
        }
}

void restore(object player){

	tell_object(player, "籠罩住你身體的藍霧慢慢地消散了...\n");
	this_player()->modify_stat("natural_armor_class",-2);
        remove(); 
}
