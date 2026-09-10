#include "mudlib.h"

inherit OBJECT;

void create()
{
     set_name("salt bottle","鹽罐");
     set_short("鹽罐");
     set_long("鹽是做菜時不可或缺的幫手，不僅可以使食物更加美味，更可使食物常保新\n"
     "鮮。這個鹽罐就是裝鹽用的，但是由於蓋子是密封的，你也不知道裡面還\n"
     "有多少鹽。\n"
      );
     set("use_time",10);
     add("id",({ "bottle","salt" }) );
     set( "unit", "瓶");
     set("weight",10);
     set("value", ({ 400, "silver" }));
}
void init()
{
	add_action("do_cook","cook");
}
int do_cook(string arg)
{
	int skill1,skill2;
	object me,target,env;
	me = this_player();
	skill1 = me->query_skill("anatomlogy");
	skill2 = me->query_skill("cook");
    	if ( !skill2 || skill2=0 ) 
    	        return notify_fail("你想幹什麼?");
    	if (!arg) return notify_fail("你要用什麼材料展露你出色的廚藝？\n");
	env = environment(me);
	if( !env || !target = present(arg, env) )
		return notify_fail("你要烹飪的材料不在這裡。\n");
        if ( !target->id("corpse")) {    
	  tell_object(me,"你瘋了嗎?這個東西不能拿來煮啦!!\n");
	  tell_room( env, 
	             me->query("c_name")+"竟然企圖把"+
	             target->query("c_name")+"作為料理的材料。\n", me);
	             return 1;
	                            }
	if ( !me->query_vision() )
        return notify_fail("這裡一片漆黑 ! 你什麼也看不到 !!\n");
	if ( !present("carver",me) )
	        return notify_fail("你還需要一把菜刀才能表現你完美的廚藝。\n");
	tell_object(me,
		set_color("你掏出鹽罐和菜刀，蹲在路邊的屍體旁，開始剝洗...\n","HIY") );
	tell_room(environment(me),sprintf("%s掏出一把小菜刀和一個小罐子，鬼鬼祟祟的蹲在路邊的屍體旁邊...",
		me->query("c_name")),
		me );
        target->remove();
        seteuid(getuid());
        call_out("cook",3,me);
        return 1;
} 
int cook(object me)
{
        object meat;
        int heal1,heal,skill1,skill2,level;
        
        skill1 = me->query_skill("anatomlogy");
        skill2 = me->query_skill("cook");
        level = me->query_level();
        heal1 = 7*skill2+2*skill1+3*level-random(10);
        heal = heal1/20;
        if ( !random(skill1)>9 ) 
                return notify_fail("你企圖用菜刀割下屍體的肉，卻把屍體挖的面目全非..\n");
        tell_object(me,
        "你掏出菜刀，切下屍體身上的上肉，再撒上一些鹽，把它做成乾肉。\n");
        tell_room(environment(me),"你看到" +me->query("c_name")+                
        "用菜刀把屍體上的肉一片片切下來，又在肉上撒上一些東西...\n",me);
        meat = new("/d/adventurer/hall/obj/dry_meat");
        meat->set("heal",heal);
        if (skill2/2-random(5)<1) 
                 {
                 meat->set("rotten",1);
                 meat->move(me);
                 set("use_time",query("use_time")-1);
                 if ( query("use_time")<1 ) {
                       tell_object(me,
                       "你發現鹽罐已經空了，你隨手把它丟在路邊。\n");
                       remove();
                       return 1;
                                            }
                 return 1;
                 }
        meat->move(me);
        set("use_time",query("use_time")-1);
        if ( query("use_time")<1 ) {
                        tell_object(me,
                        "你發現鹽罐已經空了，你隨手把它丟在路邊。\n");
                        remove();
                        return 1;
                                   }
        return 1;
}
