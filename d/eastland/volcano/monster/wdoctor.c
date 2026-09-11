#include "../oldcat.h"
inherit MONSTER ;

int be_get;
void create()
{
        object ob1;

	::create();
	set_level(16);
        set_name( "Old shaman", "老巫醫" );
        set_short( "老巫醫" );
	add( "id", ({ "shaman" }) );
	set_long(
@LONG
你看見一個年紀很大的老巫醫，滿臉都是皺紋，胖胖的，駝著背，滿口蛀牙，但他的
手仍能很穩的拿著醫療所必須用的器材，你在想他是不是吃太多糖果了，現在他正在
大鍋子旁邊照料著正在煉的藥。
LONG
	);
        set( "race", "human" );
        set( "gender", "male" );
        set_perm_stat( "int", 26 );
        set_perm_stat( "kar", 20 );
        set_perm_stat("str",25);
        set_perm_stat("con",25);
        set_perm_stat( "dex", 25 );
        set_skill( "dodge", 100 );
        set_skill( "dagger", 80 );
        set_skill( "anatomlogy", 80 );
        set("defense_type","dodge");
        set( "aim_difficulty", ([ "vascular":30,"weakest":30,"critical":30 ]) );
        set( "aiming_loc", "vascular" );
        set( "max_hp", 750 );
        set( "hit_points", 750 );
        set_natural_armor( 58, 16 );
        set( "natural_weapon_class1", 3 );
        set( "natural_min_damage1", 1 );
        set( "natural_max_damage1", 12 );
        set( "special_defense", ([ "all": 40,"none":20]) );
        set( "alignment", -500 );
        set( "wealth/gold", 50 );
        set( "inquiry", ([ 
             "candy":"@@ask_candy",
             "box":"@@ask_box",
             "heal":"@@ask_heal",
             "potion":"@@ask_heal",
             "pill":"@@ask_heal",
             ]) );
        ob1=new(OWEAPON"dagger02");
        ob1->move(this_object());
        wield_weapon(ob1);
        equip_armor(OARMOR"amulet1");
        equip_armor(OARMOR"boots2");
        equip_armor(OARMOR"cloak1");

}

void ask_candy(object who)
{
   if (be_get) {
     tell_object(who,
       "\n老巫醫說：你長的很報歉，喔 ! 不、不、糖果已被別人捷足先登了。\n");
     return;
   }
   tell_object(who,
     "\n老巫醫說道：想要我珍藏的糖果，就得用十塊金幣交換。\n");
   return;
}

void ask_box(object who)
{
  tell_object(who,
    "\n老巫醫說：那個黑盒子有可能是被冷無霜偷走了，我不知道她在那，不過沒有\n"
      "必要還是不要惹她比較好，連有名的京城四大名捕都對她無可耐何。\n\n");
  return ;
}

void ask_heal(object who)
{
  tell_object(who,
   "老巫醫說道：我正在作一種續命藥丸，無耐還缺一種藥引(人參果)，假如你能找\n來給我，我就分你一顆。\n");
  return;
}

void init()
{
    add_action( "do_pay", "pay");
}

int accept_item(object me, object item)
{
   string name;
   object ob;

   name=(string)item->query("name");
   if (!name || (name!="manlike fruit"))
     return 0;
   if (!item->query(me->query("name"))) {
     printf("老巫醫說：你是去那裡偷的人參果，偷盜之物我寧死不取。\n");
     item->move(me);
     return 1;
   }
   write("老巫醫說：啊、這正是我要的人參果，謝謝。\n\n");
   write("你見到老巫醫把人參果丟到大鍋子裡頭，只聽得嘶的一聲，一股濃濃的橘色煙霧從那鍋子\n中飄了出來，瀰漫整個帳篷之中，煙霧之中，你隱約見到老巫醫不知道在鍋子邊做什麼，等\n煙霧散去，你注意到那大鍋子裡已沒有任何東西了。\n\n");
   write("老巫醫說：這是我剛完成的兩顆藥丸，一顆分你吧。\n");
   item->remove();
   ob=new(OOBJ"wpill");
   ob->set(this_player()->query("name"),1);
   ob->move(this_player());
   return 1;
}

int do_pay(string arg)
{
        string who, type;
        int num;
        object ob1;

        if( !arg || arg=="" || sscanf( arg, "%s %d %s", who, num, type)!=3 )
                return notify_fail( 
                        "\n付誰？多少錢？\n" );
        if( !id(who ) ) return 0;

        if (be_get) {
           tell_object(this_player(),
              "\n老巫醫說道：糖果被別人拿去了，但是錢我是來者不拒。\n");
           return 1;
        }

        if( type != "gold" ) {
         tell_room( environment(), ({
             "\n老巫醫說道: 很抱歉，只有金幣才能打動我的心。\n" }),
          this_object() );
          return 1;
	}

       if( !this_player()->debit(type, num) ) 
           return notify_fail( 
           "\n你沒有那麼多金幣。\n" );

       if(num<10) {
         tell_room( environment(),
          "\n老巫醫說道: 錢不夠，請再給我一遍吧，這次就算老年津貼好了。\n" ,
          this_object() );
                return 1;
	}

        if (num>=10) {
          tell_object(this_player(), 
             "\n老巫醫說道: 好 ! 我就忍痛把這塊巧克力給你吧。\n");
        ob1=new(OOBJ"y_chocolate");
        ob1->move(this_player());
        be_get=1;
	return 1;
	}

}

void reset()
{
  be_get=0;
}
