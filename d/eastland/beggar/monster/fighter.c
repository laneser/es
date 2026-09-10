#include "../dony.h"

inherit MONSTER; 

void  create()
{
	::create();
	set_level(18);
	set_name( "japan fighter", "黑月" );
	add ("id", ({ "japan", "fighter" }) );
        set_short( "東瀛武士 黑月" );
	set("unit","位");
        set_long(@C_LONG
黑月身穿一襲黑色勁裝, 全身上下只露出眼睛的部分而己。從他的眼睛裡,你可以
看到一雙類似野獸的兇狠目光,似乎要把你給吞了下腹。他的殺人的技巧是一流的
,只要被他盯上,那麼那個人不出三天就會死了,而且往往死狀悽慘無比。他現在受
僱於某人, 似乎正在執行某件任務。 
C_LONG	
	);
        set("weight",680);
	set("alignment",-4000);
	set("wealth/gold",100);
	set_perm_stat("int", 23);
	set_perm_stat("str", 25);
	set_perm_stat("dex", 30);
	set_perm_stat("kar",21);
	set("max_hp",550);
	set("hit_points",550);
	set_natural_weapon( 39, 15, 25 );
	set_natural_armor( 30,45 );
	set ("gender", "male");
	set ("race", "human");
	set_skill("parry",70);
	set_skill("dodge",80);
        set_skill("longblade",70);
	set_skill("anatomlogy",100);
        set("aiming_loc","weakest");
        set("special_defense", ([ 
              "divine": -20,"evil":30,"none":30]) );
        set("aim_difficulty",
              (["critical":80,"vascular":40,"ganglion":50,"weakest":80]) );
	wield_weapon(DWEAPON"katana");      
	equip_armor(DARMOR"japan_cloth");
        set( "inquiry", ([
              "chan":"@@ask_chan"
        ]) );
        set( "tactic_func", "my_tactic" );
}
void ask_chan( object asker )
{
   tell_object( asker ,
      "黑月說道:你是全副幫主派來的?那他有沒有告訴你說下一步要做些什麼?\n");
   return ;   
} 
int accept_item(object me, object item)
{
      string name,my_name;
            
      name=(string)item->query("name");
      my_name=(string)me->query("name");
      
      if (name!="a white letter")
          return 0;
      
      if ( ( name=="a white letter" )&&( this_object()->query("be_asked") ) )
      {
         tell_object(me,
            "黑月說道:唉喲,不妙了,我把鑰匙給錯人了!!你快追!!\n");
         command("give a white letter to "+my_name);      
         return 1;
      }
      if ( ( item->query("master") ) != my_name ) {                               
         tell_object( me,
           "黑月說道:你這是打那兒的信件啊?\n");
         command("give a white letter to "+my_name);  
      } 
      else {
         tell_object( me,
           "黑月接過你的信件思考了一會兒。\n");
         item->remove();
         call_out("recover1",2,me);
         this_object()->set("be_asked",1);
         call_out("recover2",1800,this_object());
      }

}
void recover1( object obj )
{
     object ob1;
     ob1=new(DITEM"key.c");
     tell_object( obj ,
       "黑月說道:哦,原來是全副幫主說要你來拿鑰匙的喔,拿去吧!不過不要搞\n"
       "         丟喔,這是我去弄來的。\n");
     ob1->move(obj);   
}
void recover2( object obj )
{
     obj->delete("be_asked"); 
}
int my_tactic()
{
    object env,me,victim;
    string my_name,vic_name;  
      
      victim=query_attacker();
      me = this_object();
      my_name=(string)me->query("c_name");
      vic_name=(string)victim->query("c_name");
      env = environment(me);
       
      if ( !victim ) return 0;
        
      switch( random(40) ) {
      case 1..3 : 
                victim->receive_special_damage("evil",40);
                tell_room(env,my_name+
                      "手擬星天弓要訣,化黑暗的波動為一把利箭射向"+vic_name+"的要穴!!\n\n",victim);             
                tell_object(victim,my_name+
                      "手擬星天弓要訣,化黑暗的波動為一把利箭射向你的要穴!!\n\n");
                report(this_object(),victim);
                return 1;
      case 4 :  
                victim->receive_damage(25);
                tell_room(env,my_name+
                       "從身上掏出一支十字飛鏢射向"+vic_name+"的身上!!\n\n",victim);
                tell_object(victim,my_name+
                       "從身上掏出一支十字飛鏢射到你身上!!\n\n");                       
                report(this_object(),victim);
                return 1;       
      case 5..6 :
                victim->receive_damage(38);
                tell_room(env,my_name+
                       "幻化成十個人形,從想不到的方位,給"+vic_name+"一個痛擊!!\n\n",victim);
                tell_object(victim,my_name+
                       "幻化成十個人形,從你想不到的方位,給你一個痛擊!!\n\n");
                report(this_object(),victim);
                return 1;  
      default :
                return 0;
      }
}
