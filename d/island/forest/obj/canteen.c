#include <mudlib.h>
#include <daemons.h>
#include <conditions.h>

inherit OBJECT;

void create()
{
    set_name("Canteen", "乖乖壺");
    set_short( "乖乖壺" );
    set_long(@LONG
這是造型新穎又可愛的小水壺，你可以用它來裝水哦！
LONG
                );
    set("weight", 3 );
    set("times",10);
    set("filled",0);
    set("value",({50,"silver"}) );
}

void init()
{
    add_action( "fill_water", "fill" );
    add_action( "drink_water", "drink" );
}

int fill_water(string arg)
{
    object env;
    int hour;
    
    sscanf(WEATHER_D->query_game_time(),"%d",hour);    
    if( !arg || arg!="canteen" )
         return notify_fail("用什麼裝水？\n");

    env = environment(this_object());
    if( living(env) ) env = environment(env);

    if( this_object()->query("filled") >= 3){
      this_object()->add("filled",1);
      this_object()->set_name("Broken Canteen","破掉的乖乖壺");
      this_object()->set_short("破掉的乖乖壺");
      this_object()->set_long("這個乖乖壺已經破掉了，再也無法裝水了！\n");
      write("你想用這個乖乖壺來裝水，可是它已經破掉了！\n");
      this_player()->delete_temp("get_canteen");
      this_object()->set("useless");
      return 1;
      }
    if( (int)this_object()->query("times") == 0){
       write("已經裝滿水了啦!!\n");  
       return 1;
       }
    if( (string)env->query("short")=="香津美泉" ||
    	(string)env->query("short")=="小水池" ||
    	(string)env->query("short")=="千川樓前庭" ){
               if( hour >= 18 || hour <= 6 ){
            write("你在乖乖壺中裝滿了清淨的泉水。\n");
            tell_room(environment(this_player()),
              this_player()->query("c_name")+"掏出乖乖壺來裝水。\n"
              ,this_player() );
            this_object()->set("times",0);
	    this_object()->add("filled",1);
	    return 1;
	}
	else {
	  write("現在正值每日的乾枯期，沒有水可以裝，嗚～～～！\n");
	 tell_room( environment(this_player()),
	  this_player()->query("c_name")+"嘆了口氣，把掏出的壺又塞回懷中。\n"
	  ,this_player() );
	  return 1;
	    }
	 } 
	write("你裝這裡的水有什麼用？？又不乾淨，裝了你敢喝嗎？\n");
	return 1;
}

int drink_water(string arg)
{

    if( !arg || arg!="canteen" )
        return notify_fail("你想喝什麼？\n");
    
    if( this_object()->query("filled") >= 4 )
        return notify_fail("乖乖壺已經破了，不能再使用了...:P\n");    
    
    if( this_object()->query("times") >= 10 )
	return notify_fail("乖乖壺是空的。\n");
    if( (int)this_player()->query("wealth/silver") <= 100){
        write("你已經快破產了，還想喝這種奢侈的聖水啊？\n");
        return 1;
        }
/*        
    if( this_object()->query("times") >= 9 ){
      write("你掏出乖乖壺，想一口喝剩下的水光，結果......\n");
      this_object()->add( "times",1 );
      WEAK->apply_effect( this_player(),5,10 );
      return 1;
      }
 */     
    write("你大大口的喝了一口水，精神好多了，可是荷包好像變輕了，大概是錯覺吧!\n");
    tell_room(environment(this_player()),
       this_player()->query("c_name")+"拿出乖乖壺來，像灌蟋蟀似的猛喝....\n"
       ,this_player() );
        this_object()->add( "times",1 );	
    
       this_player()->add("medication_resistance",-20);
       this_player()->add("wealth/silver",-50);
      if( (int)this_player()->query("medication_resistance") < 0)
          this_player()->set("medication_resistance",0 );
       return 1;
}    
