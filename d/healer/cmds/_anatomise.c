//#pragma save_binary

#include <mudlib.h>

inherit DAEMON;

int cmd_anatomise(string str)
{
    object weapon;
	string text, name;
	int skill, exp, level, n;
	object targ, env, me, bild;
	mixed *ids;
	int i,j;
	int is_corpse;
	string *info, corpse, target;
	int difficulty;
	mapping data;
    
    	if (!str) return notify_fail("你要解剖什麼？\n");
	seteuid(getuid());
	data = ([]);
	info = explode( read_file("/d/healer/cmds/anatomise.dat"), "\n" );
	j=0;
	for( i=0; i<sizeof(info); i++ ) {
		// Skip comments
		if( info[i][0]=='#' ) continue;
		if( sscanf(info[i], "[%d]%s=%s", difficulty, corpse, target)==3 ) {
			data[j] = ({difficulty, corpse, target});
	        j++;
	    }
	}        
	me = this_player();
	weapon=(object) me->query("weapon1");
	if (!weapon || (string)weapon->query("type")!="dagger") {
	   tell_object(me,"你手上沒有適當的工具, 無法進行解剖。\n");
           return 1;
	}   
	env = environment(me);
	if( !env || !targ = present(str, env) )
		return notify_fail("你要解剖的東東不在這裡\n");

	skill = (int)this_player()->query_skill("anatomlogy");
	if( !skill ) 
	    return notify_fail( "哇勒!沒學過解剖學不能亂割啦!!\n");

    if (! targ->id("corpse")) {    
	  tell_object(me,"你瘋了嗎?這個東東不能解剖啦!!\n");
	  tell_room( env, 
	        sprintf("%s好像瘋了,竟然企圖解剖%s。\n",
		me->query("c_name"),targ->query("c_name")), me);
       return 1;	              
	}
	bild=new("/d/healer/reagent/corpse1.c");
	bild->move(environment(me));
    for (i=0;i<sizeof(data);i++) {
      if (random(skill) < data[i][0]) continue;
      if (targ->id(data[i][1])) {
        targ->remove();
        bild=new(data[i][2]);
        bild->move(me);
        tell_object(me,sprintf("恭喜你,成功的取出一%s%s了。\n",
	bild->query("unit"),bild->query("c_name")));
        tell_room(env,
	sprintf("%s從屍體中拿出一%s%s。\n",
		me->query("c_name"),bild->query("unit"),bild->query("c_name")),me);
        return 1;                      
      }
    }  
	tell_object(me,"你把屍體全身都翻遍了,仍然找不到有用的東東。\n");
	tell_room( env, 
		sprintf("%s用%s將屍體亂切一通。\n" ,me->query("c_name"),weapon->query("c_name")),me );
    targ->remove();
	return 1;
}

int help()
{
  write(
  @C_HELP
指令格式: anatomise <對象>

這個指令讓你對某個特定對象解剖。
如果指定的對象是屍體, 且屍體中有有價值的東西, 則會自動
取出。
C_HELP
  );
  return 1;
}
