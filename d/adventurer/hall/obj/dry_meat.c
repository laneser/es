#include <mudlib.h>
#include <stats.h>
#include <conditions.h>

inherit OBJECT;

void init()
{
	add_action( "eat_food", "eat" );
}

void create()
{
	set_name("dry meat","鹹肉乾");
	add( "id" , ({ "meat" }) );
	set_short("dry meat" , "鹹肉乾");
	set_long( 
		"這是一塊不知什麼東西作成的肉乾，上面有著一粒一粒的食鹽結\n"
		"晶，可想而知滋味並不是很好，但可能可以保存很久。\n"
	);
   	set("heal",1);
   	set("unit","塊");
   	set("weight", 10);
   	set("value",({ 1, "silver" }) );
}
int eat_food(string arg)
{
     object me;
     int num1,num2;
		me = this_player();
		if( !arg || arg != "meat" ) return notify_fail("吃什麼?\n");
		write( "你慢慢啃著這塊肉乾，哇，真鹹，但是至少還能用來填肚子..\n" );
                tell_room( environment(me),
                "你看到"+me->query("c_name")+"用力的啃著一塊肉乾"
                "，一邊露出奇怪的表情...\n" , this_player());
                num1 = query("heal");
                num2 = num1/2+10;
		me->receive_healing(num1);
	        me->add("talk_points",-num2);
// Eat too much meat tp <0 will sick
// add by Iris@ES Feb 6 1996	        
	if (me->query("talk_points")<0) {
		write("或許是肉乾吃多火氣大, 你覺得身體不太舒服...\n");
		(CONDITION_PREFIX+"sick")->apply_effect(me,3,2,2);
	}		        
       if ( query("rotten") != 1 ) {
        remove();
        return 1;
        }
       write( "奇怪，可能是做的時候不太衛生，你感覺有點不舒服...\n");
       (CONDITION_PREFIX + "weak")->apply_effect(me,6,5);
	remove();
	return 1;
}

