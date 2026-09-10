#include <mudlib.h>

inherit OBJECT;

void create()
{
        set_name("wineskin","牛皮酒袋");
	add( "id", ({ "skin" }) );
        set_short("酒袋");
        set( "weight", 10);
        set( "value", ({ 0, "coin" }));
        set("long", "一個牛皮縫的大酒袋，大概裝得八、九升的酒。\n");
        set("unit", "個");
	set("no_sale",1);
}

void init()
{
        add_action("to_drink","drink");
}

int to_drink(string arg)
{
	object me;
	int maxhp,maxsp,maxtp,maxfp;

	me = this_player();

        if( !arg || arg=="" || arg !="wine")
        {
                tell_object(this_player(),
                "你想幹什麼?\n"
                );
        }
	else 
	{
	        tell_object(this_player(),
        	"你一仰頭,咕嚕咕嚕地喝了幾口酒.\n");
        
        tell_room( environment( me ),
                me->query("c_name")+"一仰頭,咕嚕咕嚕地喝了幾口酒．\n"
                , me);

	maxhp = (int)me->query("max_hp");
        maxsp = (int)me->query("max_sp");
	maxtp = (int)me->query("max_tp");                            
	maxfp = (int)me->query("max_fp");
		
	me->add("force_points",1);
	if ((int)me->query("force_points") >= maxfp)
	{
		me->set("force_points" , maxfp);
	}
			
	me->add("hit_points", 1);
	if ((int)me->query("hit_points") >= maxhp) 
	{
		me->set("hit_points",maxhp) ;
	}
	
	me->add("spell_points", 1);
	if ((int)me->query("spell_points") >= maxsp) 
	{
		me->set("spell_points",maxsp) ;
	}
	
	me->add("talk_points", 1);
	if ((int)me->query("talk_points") >= maxtp) 
	{
		me->set("talk_points",maxtp) ;
	}
	
	}
        return 1;
}