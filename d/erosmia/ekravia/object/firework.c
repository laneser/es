#include <mudlib.h>
inherit OBJECT;
inherit MESSAGE;

void	create()
{
	set_name("firework", "煙火");
	set_short( "煙火");
	set_long( @CLONG
這是一個煙火, 點燃 (light) 它, 你將會獲得許多樂趣。
CLONG
    );
	set("id", ({"firework"}));
	set("unit", "個" );
	set( "weight", 10 );
	set( "value", ({ 500, "silver" }) );
}

void	init()
{
	add_action("do_light","light");
}

int		do_light(string s)
{
	object ob;
	string s1,s2;
	string msg, cmsg;
	int color;
	object *usr;
	int	i, user_number;
	
	if (!s) return notify_fail( "你想點燃什麼?\n" );
	if ( (!ob = present(s)) || (ob != this_object())) 
		return notify_fail( "這裡沒有這種東西\n" );
		
	color = random (6);
	switch (color) {
		case 0  : s1= "HIR"; s2= "紅"; break;
		case 1  : s1= "HIM"; s2= "粉紅"; break;
		case 2  : s1= "HIY"; s2= "黃"; break;
		case 3  : s1= "HIG"; s2= "綠"; break;
		case 4  : s1= "HIB"; s2= "藍"; break;
		case 5  : s1= "HIC"; s2= "紫"; break;
		default : s1= "HIR"; s2= "紅";
	}
	emote( "$NS將煙火點著, 然後掩住耳朵迅速地躲到一邊。\n", 
			this_player() );
	cmsg = "砰！的一聲，一枚美麗的"+ s2 + "色煙火在天空中迸射開來。\n";
    			
    usr = users();
    user_number = sizeof(usr);
    for ( i=0; i < user_number; i++ )
    {
    	tell_object( usr[i], set_color( cmsg, s1, usr[i]));
    }
	remove();
	return 1;
}
