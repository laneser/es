
#include "../echobomber.h"
inherit OBJECT;

void create()     
{
	seteuid(getuid());
	set_name( "cutknife", "割耳小刀" );
	set_short("割耳小刀");
	set_long( 
	   "一把很銳利的小刀,似乎它是被用來從屍體上割下(cut)耳朵的好工具.\n"
	    );
	add("id", ({ "knife", }));
	set( "unit", "把" );
	set("weight", 30);
	set("no_sale",1);
	set("value", ({ 0, "copper" }));
}


void init()
{
	add_action("cut_ear", "cut");
}

int cut_ear(string str)
{
	string str1,str2;
	object room_1,ob1,ob2;
	
    if (!str) return 0;
    if (sscanf(str,"%s from %s",str1,str2)!=2) {
      write("語法如下: cut A from B.\n");
      return 1;
	  }
	if( str1!="ear") return 0;
    if( str2!="corpse") return 0;
    room_1=environment(this_player());
    if ( ( ob1=present(str2,room_1) ) )
      if ((int)(ob1->query("troll_ear"))==1) {   
         if (!(ob1->query("be_cut")))
           {
           write("你從巨人的屍體上割下了耳朵.\n");
           ob2=new(Object"/trollear");
           ob2->move(this_player());
           ob1->set("be_cut",1);
           }
         else 
         write("這屍體已經被割過耳朵了.\n");
         }
      else
         {
         write("割耳朵??是一個好主意但是似乎對於死者不敬.\n");
         }
    else
    write("這裡沒有任何屍體.\n");
    
    return 1;

}
