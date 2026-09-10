#include <mudlib.h>

inherit OBJECT;
int num;
void create()
{
        set_name("wineskin","牛皮酒袋");
        add( "id", ({ "skin" }) );
        set_short("酒袋");
        set( "weight", 10);
        set( "value", ({ 0, "coin" }));
        set("long", "@@query_desc");
        set("unit", "個");
        set("no_sale",1);
        num=100;
}

void init()
{
        add_action("to_drink","drink");
}

string query_desc()
{
        if(num>=100) return "一個裝滿酒的牛皮酒袋\n";
        if(num<100 && num >=70) return "一個七、八成滿的牛皮酒袋\n";
        if(num<70 && num >=40) return "一個半滿的牛皮酒袋\n";
        if(num<40 && num >0)   return "一個裝著一些酒的牛皮酒袋\n";
        if(num<=0) return "一個空了的牛皮酒袋\n";
}
int to_drink(string arg)
{
        object me;
        int maxhp,maxsp,maxtp,maxfp;

        me = this_player();

        if( !arg || arg=="" || arg !="wine")
        {
                tell_object(me,
                "你想幹什麼?\n"
                );
        }
        else 
        {
                if(num<=0) 
                {
                   tell_object(me,
                   "你一仰頭剛想喝酒, 卻發現酒袋已空了...\n");
                   tell_object(me,
                   "你氣得把酒袋撕個粉碎 ! \n");
                   this_object()->remove();
                   return 1;
                }
                num--;
                tell_object(this_player(),
                "你一仰頭,咕嚕咕嚕地喝了幾口酒.\n");
        
        tell_room( environment( me ),
                me->query("c_name")+"一仰頭,咕嚕咕嚕地喝了幾口酒．\n"
                , me);

        maxhp = (int)me->query("max_hp");
        maxsp = (int)me->query("max_sp");
        maxtp = (int)me->query("max_tp");                            
        maxfp = (int)me->query("max_fp");
                
        me->add("force_points",5);
        if ((int)me->query("force_points") >= maxfp)
        {
                me->set("force_points" , maxfp);
        }
                        
        me->add("hit_points", 5);
        if ((int)me->query("hit_points") >= maxhp) 
        {
                me->set("hit_points",maxhp) ;
        }
        
        me->add("spell_points", 5);
        if ((int)me->query("spell_points") >= maxsp) 
        {
                me->set("spell_points",maxsp) ;
        }
        
        me->add("talk_points", 5);
        if ((int)me->query("talk_points") >= maxtp) 
        {
                me->set("talk_points",maxtp) ;
        }
        
        }
        return 1;
}
