#include <uid.h>
#include <mudlib.h>
#include <daemons.h>

#define CAMP_FILE "/oepn/camp/"+(string)this_player()->query("name")+"_incamp.c"
#define SOURCE_FILE "/d/adventurer/hall/incamp.c"

inherit REF_D;
inherit DAEMON ;
inherit OBJECT;

void create()
{
	seteuid(getuid());
        set_name( "camp tools","露營工具包" );
	add( "id",({"camp","tool","camp tool"}) );
	set_short(set_color("露營工具包","HIB"));
	set_long("這是一個裝滿營釘，營帳，防水布，睡墊等工具的小包包。\n"
                 "你可以使用它在野外建造(build)一個溫暖的小帳篷。\n");
	set("unit","個");
	set("no_sale",1);
	set("weight",300);
        set("value",({ 3000,"silver" }));
        set("size",1);
        set("prevent_drop",1) ;
}

void init()
{
	add_action("help_camp","help");
	add_action("cmd_build","build");
        add_action("cmd_setsize","setsize");
}
int copy_file(string from, string to) {
    string str;
            str = read_file(from);
            if (file_exists(to))  rm(to);
            write_file(to,str);
            return 1;
}
void do_camp(object me, int skill, int size )
{ 
   object camp;
   string b_name,e_name;

   camp = new("/obj/camp");
   camp->move(environment(me));
   camp->set("size",size);
   camp->set("skill",skill);
   camp->set("last_locate",environment(me));
   b_name = me->query("c_name");
   e_name = me->query("name");   
   camp->set("creater",b_name);
   camp->set("creater_name",e_name);
   if (file_exists(CAMP_FILE)) rm(CAMP_FILE);
   write_file(CAMP_FILE,"#inherit "+SOURCE_FILE+";");
//   cp(SOURCE_FILE,CAMP_FILE);
   camp->set("TO_WHERE",CAMP_FILE);
   me->delete_temp("block_command");
   this_object()->remove();
   return;
}

int cmd_setsize(string size)
{
    if(!size)
        return notify_fail("現在的營帳大小設定在 "+ this_player()->query("camp_size") +"
人帳。用法請詳見 help camp。\n") ;
    switch(size)
       {
          case "1" : this_player()->set("camp_size", 1 ) ;
                     write("現在的營帳大小設定在 "+ size +"人帳 。\n") ;
                     break ;
          case "2" : this_player()->set("camp_size", 2 ) ;
                     write("現在的營帳大小設定在 "+ size +"人帳 。\n") ;
                     break ;
          case "3" : this_player()->set("camp_size", 3 ) ;
                     write("現在的營帳大小設定在 "+ size +"人帳 。\n") ;
                     break ;
          case "4" : this_player()->set("camp_size", 4 ) ;
                     write("現在的營帳大小設定在 "+ size +"人帳 。\n") ;
                     break ;
          case "5" : this_player()->set("camp_size", 5 ) ;
                     write("現在的營帳大小設定在 "+ size +"人帳 。\n") ;
                     break ;
          case "6" : this_player()->set("camp_size", 6 ) ;
                     write("現在的營帳大小設定在 "+ size +"人帳 。\n") ;
                     break ;

          default  : write("用法請詳見 help camp。\n") ;
                     break ;
        }
    return 1;
}
int cmd_build(string str)
{
    int skill, hp, alignment,time, size;
    object me,env;
	
    me = this_player();
    env = environment(me) ;
    skill = (int)me->query_skill("camp");
    size = this_player()->query("camp_size");
    time =  6 + size*2 - skill/10 ;
     
    if (!str || str!="camp") return 0 ;
    if( !skill ) return notify_fail("你沒有學過紮營，所以無法搭起帳蓬..。\n");
    if( skill < size*10 ) return
notify_fail("你的紮營技巧不足以搭起這麼大的帳蓬 。\n");
    if( (int)me->query_attacker()) {
      write("在戰鬥中紮營，想要找老黑泡茶嗎？\n");
      tell_room( env, me->query("c_name") + "想在戰鬥中紮營，難道他想找老黑泡茶嗎？\n",me) ;
      return 1;
    }
    if( !environment(me)->query("outside") )
            return notify_fail("這裡的地面太硬，不適合搭帳棚。\n");
    if( env->query( "underwater" ) )
            return notify_fail("在水中搭帳棚不是個好主意。\n");
    if( env->query( "flamezone" ) )
            return notify_fail("這裡好熱喔，搭了可能帳棚會燒掉。\n");        
    if( env->query_temp( "adv_camp" ) )
	return notify_fail("這裡已經有別人先搭帳棚了。\n");
    write("你捲起衣袖，把帳棚工具拿出來，用最快的速度開始搭帳棚。\n");
    		
    tell_room( env, 
	me->query("c_name")+"捲起衣袖，把帳棚工具拿出來，用最快的速度開始搭帳棚。\n",
		me );

    env->set_temp("adv_camp", 1);
    if( !wizardp( me ) ) {
	me->set_temp("block_command", 1 );
    }		
    call_out( "do_camp", time , me, skill, size );
    return 1;
}


int help_camp(string str)
{
    if (!str || ( str!="camp" && str!="build" ) ) return 0 ;
    write(@HELP
指令格式: build camp 

當你使用 build 這個指令，如果你所在的地方合適的話，你會
在你所在的房間中造出一間帳蓬，一間房間只能建一間帳蓬，在帳
蓬中睡眠或休息將會加快你生命點數，精神力，以及談話點數恢復
的速度，但若在睡眠時遭受攻擊，很可能就會因此一睡不醒。
你也可以使用setsize 這個指令設定帳蓬供多少人使用，通常建越
大的帳蓬能容納越多的人，休息的效果更好，但需要越久的時間與
越高的技術來建造它。
搭好的帳蓬可能被風給吹壞，所以當你不用時，馬上拆(destroy)
掉它是比較好的作法。
HELP
	);
    return 1;
}
