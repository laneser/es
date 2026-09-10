#include <mudlib.h>
#define FRESH_TIME 600

inherit OBJECT;

void create()
{
	set_name("unknown plant","奇怪的植物");
	add( "id" , ({ "plant" }) );
	set_short("奇怪的植物");
	set_long(
		"這是一株看來頗特殊的植物，但由於附近的植物太茂密，\n"
		"你也不能確定他是不是有用，也許拿把花剪(cut)把它割下來才能\n"
		"搞清楚它是什麼...\n"
	);
   	set("unit","株");
//   	set("cropp",1);
   	set("weight", 10000);
   	set("value",({ 0, "silver" }) );
	set("cropp",1);
	set("is_fresh",1);
}
void init()
{
    add_action("do_cropp","cut");
}    
int do_cropp( string arg )
{
     object obj;
     int i,n;
     string str;      
           
           if ( !arg || arg != "plant") {
           write("你想割什麼??\n");
           return 1;
           }
           if ( !present("scissors",this_player()) ) {
           write("你沒有適合的工具喔...\n");
           return 1;
           }
           seteuid(getuid());
           write("你拿起花剪，把這株不明植物割了下來，並且仔細的觀察他！\n");
           
           tell_room( environment(this_player()),
           "\n"+this_player()->query("c_name")+"拿出一把鋒利的花剪，把路邊的一株植物割了下來\n"
           "，並且拿在手上仔細觀察...\n\n", ({this_player()}) );
           
           switch( n= random(2) ) {
           case 0: obj = new("/d/noden/farwind/items/branz_herb");break;
           case 1: obj = new("/d/adventurer/natural_history/herb");break;
           default : break;
           }
           
           if (obj->query("c_name")=="布蘭茲藥草")
           obj->set("need_skill",1);
           
           
           if ((int)obj->query("need_skill") < (int)this_player()->query_skill("natural_history")-1) {              
               
                write("根據你對博物學與自然生物的認識，你斷定這是一"+obj->query("unit")+"野生的\n"
                +obj->query("c_name")+"。你很快的把它收起來...\n");      
               
                tell_room( environment(this_player()),
                "\n"+this_player()->query("c_name")+"說道: 哈，找到一"+obj->query("unit")+"野生的"
                +obj->query("c_name")+"\n，真是賺到了...\n\n", ({this_player()}) );
                this_player()->gain_experience(5*(int)obj->query("need_skill"));
                obj->move(this_player());
                remove();
                return 1;
                } 
           
           else {
               
                write("你從來沒見過這玩意，或許它沒什麼用吧..你順手把它丟在路邊\n");
               
                tell_room( environment(this_player()),
                "\n"+this_player()->query("c_name")+"似乎不知道採到的植物是什麼，隨便把他\n"
                "丟在路邊...\n\n",({this_player()}) );
               
                remove();
                return 1;
                }
                }
int move(mixed ob)
{
	if ( ob && living(ob))
        call_out("not_fresh", FRESH_TIME, this_object() );
	return ::move(ob);
}

void not_fresh(object what)
{
	remove();
}
