#include <mudlib.h>
inherit OBJECT;
int weted;

string query_c_long()
{
   if ( weted )
  	return  "這個沾了水的石頭似乎快要溶掉了，若不趕快把它弄乾(dry)，\n"
        	"你可得準備回去挨老婆的一頓臭罵或只得將衣服丟掉!!。\n";
	else
	return  "這個黑色石頭看來髒髒的、軟軟的，跟一般石頭不太一樣，上面\n"
		"似乎寫著三個字 w?t，中間的字被一個大 Ｘ 給蓋住而看不清楚。\n";
}

void create()
{
	set_name("black stone", "黑色石頭");
	add( "id", ({ "blackstone","stone" }) );
	set_short( "黑色石頭" );
	set("long","@@query_c_long");
	set( "weight", 3 );
	weted = 0;
}

int query_weted() { return weted; }

void init()
{
	add_action( "wet_stone", "wet" );
	add_action( "dry_stone", "dry" );
	add_action( "apply_wall", "apply" );
}

int wet_stone(string arg)
{
   object env;

   if( !arg || arg!="blackstone" && arg != "stone" )
     return notify_fail("將什麼弄溼？\n");
   if ( weted )
     return notify_fail("黑色石頭已經弄溼了,似乎用來用來塗墨(apply)!!。\n");

	env = environment(this_object());
	if( living(env) ) env = environment(env);
	if( !env->query("water_source") )
		return notify_fail("這裡沒有水....。\n");

	weted = 1;
	write("你把黑色石頭弄溼，似乎可以用來塗墨(apply)!!。\n");
	call_out("mess_up", 200);
	return 1;
}

int dry_stone(string arg)
{
        if( !arg || arg!="blackstone" && arg != "stone" )
		return notify_fail("弄乾什麼？\n");
	if( !weted )
		return notify_fail("手癢嗎? 黑色石頭已經是乾的呀!!。\n");
	weted = 0;
	write("你張開大口用千年薰人的功力把黑色石頭弄乾了。\n");
	return 1;
}

void mess_up()
{
	object owner;
        if (!weted) return ; 
	owner = environment(this_object());
	if( living(owner) ) {
	tell_object(owner, "黑色石頭已經弄髒了你的衣服，回去可得捱罵，你只得隨手將它扔了。\n");
	}
	remove();
	return;
}

int apply_wall(string str)
{
        object obj1, obj2;
   if (!weted) {
     write("你不禁敲敲自己的腦袋說：秀逗啦，沒水怎麼塗墨呢？\n") ;
     return 1;
   } else {
        if ( !str || str=="" || str !="wall" )
          write("你把自己弄的一身髒兮兮的，這樣可追不到帥哥或美女喔 !!\n");
        else {
          obj1=environment(this_object());
          if (living(obj1)) {
            obj2 = environment(obj1);
            if ((int)obj2->query("apply")==1) 
              obj2->to_find_wall(str);
            else
              write("這裡不能隨便塗墨，當心被抓到打屁股！\n");
          }
          else return notify_fail("你手上並沒有工具。\n");  
        }
        return 1;
  }
}
