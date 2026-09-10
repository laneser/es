#include <mudlib.h>

#define COST_HP 60
#define TIME_QUOTA 20
#define INTERVAL 5 
inherit OBJECT;

void create()
{
        set_name( "life ball", "元氣玉" );
        add( "id", ({ "ball" }) );
        set_short( "元氣玉" );
        set_long(@C_LONG
這是一顆晶螢剔透的生命圓球。元氣玉是由『祠堂 老院長』多年研究長生不老之術
小成後的產物。據老院長透露, 你可以把你的生命力貯存( install )在這一顆小小
的圓球裡;假以時日,你又可以從圓球中取出( release )生命力;除此之外,你還可以
檢查( exam )看圓球是否有生命力,這實在是一件很奇妙的事情。
C_LONG        
        );
        set("unit","個");
        set( "weight", 20 );
        set("no_sale",1);
}

void init()
{
   add_action( "install_ball", "install" );
   add_action( "release_ball", "release" );
   add_action( "exam_ball", "exam" );
}   
   
int install_ball(string arg)
{
   object me,ball;
   int my_hp,my_int,my_ali,times;
   
   if( !arg )
      return notify_fail("你要 install 什麼東西?\n");
         
   me=this_player();
   if( !(ball=present( arg, me )) )
      return notify_fail("你沒有這樣東西。\n");
   if ( ball->query("name")!="life ball" )
      return notify_fail("Syntax <install ball>\n");
   
   my_ali=me->query("alignment");
   my_int=me->query("spell_points");
   my_hp=me->query("hit_points");      
   times=ball->query("install_times");   
      
               
      if ( ( times > 0 ) && ( ball->query("master") != ( me->query("name")) ) )
          return notify_fail( "\n對不起,這顆元氣玉的主人不是你。\n"); 
      
      if ( my_hp < COST_HP ) 
          return notify_fail( "\n因為你太虛弱了而無法把生命力注入圓球裡.....\n");    
      
      if ( times > TIME_QUOTA -1  )
          return notify_fail( "\n喔,這顆元氣玉已經完全充滿了生命力......\n"); 
      
      if ( ball->query("install_wait") )
         return notify_fail( "\n請不要操之過急,請待會兒再注入你的生命力.....\n");
             
      me->add( "hit_points", -COST_HP );
      times=times+1;    
      
      if ( times==1 ) ( ball->set( "master", ( me->query("name")) ) );
      
      ball->set("install_wait",1);    
      ball->set("install_times",times);
      tell_object(me,set_color(
         "\n這顆元氣玉一共吸收了你 "+times+" 次的生命力.......\n","HIG"));
      call_out( "install_out", INTERVAL , ball);
   return 1;
}

void install_out(object ball)
{
     tell_object( environment( ball ),set_color(
          "\n元氣玉極需要你的生命力.....\n","HIW")); 
     ball->delete("install_wait");   
}

int release_ball(string arg)
{
    object me,ball;
    int times;
    
    if( !arg )
         return notify_fail("你要 release 什麼東西?\n");
    me=this_player();
    if( !(ball=present( arg, me )) )
        return notify_fail("你沒有這樣東西。\n");
    if ( ball->query("name")!="life ball" )
        return notify_fail("Syntax <release ball>\n");
    times=ball->query("install_times");
      
    if ( times < 1 ) 
       return notify_fail( "\n喔,這顆元氣玉毫無生命力可言....\n");               

    if ( ball->query("release_wait") )
       return notify_fail( "\n請待會兒再從元氣玉里取出生命力........\n");
    
    if ( ball->query("master") == ( me->query("name")) )
      me->receive_healing( 48 );
    else me->receive_healing( 36 );
    
    times=times-1;
    ball->set("install_times",times);
    tell_object(me,set_color(
       "\n元氣玉里頭的生命力使你感到一陣溫暖,你還發現元氣玉留下 "+times+" 次生命力可以取出.....\n","HIC"));
    ball->set("release_wait",1);   
    call_out( "release_out",INTERVAL,ball);
    return 1;
}
void release_out(object ball)
{
     ball->delete("release_wait");
}

int exam_ball(string arg)
{
   object me,ball;
   int times;
   
   if( !arg )
         return notify_fail("你要 exam 什麼東西?\n");
            
   me=this_player();
   if( !(ball=present( arg, me )) )
      return notify_fail("你沒有這樣東西。\n");
   if ( ball->query("name")!="life ball" )
      return notify_fail("Syntax <exam ball>\n");
   
   times=ball->query("install_times");
   if ( times==0 )
      ball->set("master","???");
      
   tell_object(me,"\n這顆生命圓球的主人是 "+ball->query("master")+
       " 而且已經被注入了 "+times+" 次生命力了......\n");
   
   return 1;
}             