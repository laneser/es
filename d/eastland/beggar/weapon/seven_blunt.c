#include <mudlib.h>

inherit WEAPON;

void create()
{
        set_name("seven blunt","七寶金幢");
        add("id",({"blunt",}) );
       set_short("七寶金幢");
       set_long(@C_LONG
七寶金幢傳說是降魔伏妖的稀世寶物。此物原來是放在七七四十九重天,用來鎮住
伏妖塔的咒物,但是,千百年前的一場神魔大戰而失落人間。因此,也讓被鎖在伏妖
塔裡的一百零八魔乘機跑了出來為害人間。傳說中,七寶金幢還有另一項用法, 那
就是...........『三十六記走為上策』,但時日已久不知道是否飛得動? 
C_LONG
               );
	set( "unit", "把" );
 	setup_weapon("blunt",30,10,25);
	set( "weight", 80 );
	set( "value", ({ 240, "gold" }) );
        set_c_verbs( ({ 
           "張開手裡的%s變成一件斗大的兵器向著%s的要害打去",
           "雙手高高地舉起%s,斜斜地砍向%s",
           "手持%s一招看似極為笨拙的棍法對著%s打去",
           "把%s插在背後的褲帶揉身而上向%s撲去"
        }) );
}
void init()
{
   add_action("do_fly","fly");
}
int do_fly(string arg)
{
   object me,*usr,target,env;
   string *envname ;
   
   if ( !living(environment(this_object())) ) {
      tell_object(this_player(),
        "你一直對著地上的七寶金幢喊『飛』,但它一動也不動地似乎不想理你～～\n");
      tell_room(environment(this_object()),this_player()->query("c_name")+
        "暴跳如雷地對著地上的七寶金幢喊『飛』,但七寶金幢似乎理也不理～～\n",
        this_player() );
      return 1;  
   }
   usr=users();
   me=this_player();
   target = usr[ random( sizeof(usr)-1 )];
   env = environment(target) ;
   
   if ( me->query("hit_points") < 120 ) {
      tell_object(me,"嗚,你太虛弱了～～\n");
      return 1;
   }
   if(!env) {
      tell_object(me,"再試一次～～\n");
      return 1 ;
   }  
   envname = explode(base_name(env),"/") ;
                
   if((envname[0] != "d")|| !environment(target)->query("outside")) {
     tell_object(me,"再試一次～～\n"); 
     return 1 ;
   }
   if( wizardp(target) || target == me ) {
     tell_object(me,"再試一次～～\n");
     return 1;
   }
   me->set("hit_points",30);
   tell_object(me,
      "你打開七寶金幢的傘翼,咻～～\n\n");  
   tell_room(environment(me),me->query("c_name")+
      "打開七寶金幢的傘翼,咻～～整個人就不見了～～\n\n",me);
   me->move_player(environment(target),"SNEAK");
   tell_object(me,
      "咻～～你乘著七寶金幢飛到了一個奇怪的地方.......這是那裡啊?\n\n");
   tell_room(environment(target),
      "咻～～～～某個東西摔在你身旁\n\n",me);
   return 1;   
}
