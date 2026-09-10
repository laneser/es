#include <mudlib.h>

#define HP_RECOVER ({-5,8,-5,0,-5,-2,30})
#define SP_RECOVER ({20,3,2,0,30,15,0})
#define FP_RECOVER ({0,0,25,15,0,0,0})
#define TP_RECOVER ({0,15,0,20,-20,0,0}) 
#define name ({"moon herb","red berry","black_head","monk fruit","red pepper","star herb","kira fruit"})
#define ID ({"herb","berry","head","fruit","pepper","herb","fruit"})
#define c_name ({"滿月草","小紅莓","何首烏","羅漢果","辣椒","天星草","吉拉果"})
#define value ({ 250,100,200,220,100,150,200 })
#define UNITS ({ "株","顆","塊","顆","條","株","顆" })
#define POWER ({ "提神","解渴","補氣","解渴","提神","提神","治傷" })
inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	int i;
	i = random(7);
	set_name(name[i],c_name[i]);
	add( "id" , ({ ID[i] }) );
	set_short(c_name[i]);
	set_long(
	"這是一"+UNITS[i]+"野生的"+c_name[i]+"，根據你所研讀過的植物圖鑑\n"
	"，它似乎具有"+POWER[i]+"的功效??\n"
	);
   	set("unit",UNITS[i]);
   	set("weight", 10);
   	set("need_skill",value[i]/5);
   	set("value",({ value[i], "silver" }) );
}

int eat_food(string arg)
{
     int i;
     string str;
     i = member_array(str,name) ;		
		if( ! arg  ) return 0;
		if ( !present(arg,this_player()) ) return 0;
		str = present(arg,this_player())->query("name");
		i = member_array(str,name) ;
		write("你吃下一"+ UNITS[i] +"野生的"+c_name[i] +"，感覺體內有一些變化產生。\n");
		tell_room( environment(this_player()), 
			this_player()->query("c_name")+
			"吃下一"+ UNITS[i] +"野生的"+ c_name[i] +"，並且露出一些奇怪的表情...\n" , this_player()
		);
		this_player()->receive_healing(HP_RECOVER[i]);

	    if ((int)this_player()->query("max_sp")> 0)
	    this_player()->set("spell_points",(int)this_player()->query("spell_points")+SP_RECOVER[i]);
	    if ((int)this_player()->query("max_fp")> 0)
	    this_player()->set("force_points",(int)this_player()->query("force_points")+FP_RECOVER[i]);
	    this_player()->set("talk_points",(int)this_player()->query("talk_points")+TP_RECOVER[i]);
	    if (this_player()->query("talk_points") < 1)  
	    this_player()->set("talk_points",1);
	present(arg,this_player())->remove();
	return 1;
}

