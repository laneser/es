#include <mudlib.h>
#define FRESH_TIME 600

inherit OBJECT;

void create()
{
	set_name("unknown rock","奇怪的石頭");
	add( "id" , ({ "rock" }) );
	set_short("奇怪的石頭");
	set_long(
		"這是一顆看來頗特殊的石頭，但由於被沙石埋住了，只留下一點表面\n"
		"露出地表，你也不能非常確定他是什麼，也許把它挖出來才能\n"
		"搞清楚它是什麼...\n"
	);
   	set("unit","顆");
   	set("dig",1);
   	set("weight", 10000);
   	set("value",({ 0, "silver" }) );
	set("is_fresh",1);
}
void init()
{
      add_action("do_dig","dig");
}
int do_dig( string arg )
{
     object obj;
     int i,n;
     string str;      
           
           if ( !arg || arg != "rock") {
           write("你想挖什麼??\n");
           return 1;
           }
           seteuid(getuid());
           write("你雙手並用，把這顆怪石頭挖了出來，並且仔細的觀察他！\n");
           
           tell_room( environment(this_player()),
           "\n"+this_player()->query("c_name")+"雙手並用，把路邊的一顆石頭挖了出來\n"
           "，並且拿在手上仔細觀察...\n\n", ({this_player()}) );
           
           switch( n= random(2) ) {
           case 0: obj = new("/d/adventurer/natural_history/stone");break;
           case 1: obj = new("/d/adventurer/natural_history/gem");break;
           default : break;
           }
           
           if (obj->query("c_name")=="小石子") {
           obj->set("need_skill",1);
           str = "普通的\n";
           }
           else str = "罕見的\n";
           if ((int)obj->query("need_skill") < (int)this_player()->query_skill("natural_history")-1) {              
               
                write("根據你對博物學與自然生物的認識，你斷定這是一"+obj->query("unit")+ str
                +obj->query("c_name")+"。你很快的把它收起來...\n");      
               
                tell_room( environment(this_player()),
                "\n"+this_player()->query("c_name")+"說道: 哈，找到一"+obj->query("unit")+"寶貴的"
                +obj->query("c_name")+"，真是賺到了...\n\n", ({this_player()}) );
               
                this_player()->gain_experience(5*(int)obj->query("need_skill"));
                obj->move(this_player());
                remove();
                return 1;
                } 
           
           else {
               
                write("你從來沒見過這玩意，或許它沒什麼用吧..你順手把它丟在路邊\n");
               
                tell_room( environment(this_player()),
                "\n"+this_player()->query("c_name")+"似乎不知道挖出的東東是什麼，隨便把他\n"
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
