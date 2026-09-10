#include </d/eastland/liang_shan/takeda.h>
#include <conditions.h>

#define LONG1 "這是一個神秘的洞窟，灰暗而且陰溼，潺潺的水流不停的從角落一個裂\n縫(crack)中流出，看那裂縫的大小，應該可以讓你勉強出入。\n"
#define LONG2 "這是一個積滿了水的神秘洞窟，刺骨的寒意正經由你身處的冰水傳來，\n如果不趕快離開此處，恐怕還沒淹死之前，就會先被凍死了....\n" 
inherit ROOM;

void create()
{
	::create();
	set_short( "積水洞窟" );
        set( "long","@@query_long");	
        set("objects",(["skeleton" : "/d/eastland/liang_shan/obj/skeleton"]));
        set("underwater",1);
        
        reset();
}
string query_long()
{
    if ( !query("underwater")  )
      return LONG1;
    else
    return LONG2;
}

void init()
{
     UNDERWATER->apply_effect(this_player(),4,1);
     add_action("do_enter","enter");
     add_action("do_break","break");
     add_action("do_search","search");
}

int do_enter(string arg)
{
    if ( !arg || arg != "crack")
        return notify_fail("你想 enter 那裡呢!\n");
 
    if ( query("underwater") )
 	return notify_fail("這裡沒有任何你能進入的裂縫...\n");
    write ("你用盡吃奶的力氣，一頭鑽了進去...\n");
    tell_room(this_object(),
    "你看到"+this_player()->query("c_name")+ "一頭鑽進了牆上的一個裂縫.....\n" ,
    this_player());
    this_player()->move_player(TROOM"underjail2","SNEAK");
return 1;
}
int do_break(string arg)
{
 object weapon;
 int wc;
 
         if ( !arg || arg != "wall")
         return notify_fail("你想 break 那裡呢!\n");
         weapon = this_player()->query("weapon1");
         
         if ( !query("underwater") )
         return notify_fail("這裡沒有任何你能打破的牆...\n");
                 
         if ( !weapon && (string)this_player()->query("class") != "monk" &&
              (string)this_player()->query("class") != "mage") {
              write("除非是少林高僧或是法師的法術，否則空手是打不破牆壁的...\n");
                   return 1;
                        }
         if ( !weapon ) {
         
         if ((string)this_player()->query("class") == "monk") { 
         write("你運氣上手，吐氣開聲，兩掌平推，這牆應聲而破...\n");
         tell_room(this_object(),
             "你看到"+this_player()->query("c_name")+ "用他的內力將牆壁震出一條裂縫..\n"
          ,this_player());
         this_player()->set("force_points",(int)this_player()->query("force_points")/2);
         }
         
         if ((string)this_player()->query("class") == "mage") {
         write("你喃喃念起了火球術咒語，將手貼在牆壁上，一聲爆炸之後，\n"
               "牆應聲而破...\n");
         tell_room(this_object(),
             "你看到"+this_player()->query("c_name")+ "用他的法術將牆壁炸出一條裂縫..\n"
             ,this_player());
         this_player()->set("spell_points",(int)this_player()->query("spell_points")/2);
         }}    
    else {
    write("你用盡全身的力氣，揮舞手上的武器，成功地將牆開出一條裂縫來，但你\n"
          "的武器也因此受損了。\n");  
    tell_room(this_object(),
    "你看到"+this_player()->query("c_name")+ "用他的武器將牆壁開出一條裂縫..\n" ,
    this_player());
            wc = weapon->query("weapon_class");
            wc -= weapon->query("wc_damaged");
            if( !weapon->query("wc_damaged") ) {
                            weapon->add( "short", " (受損)" );
                                    }
            delete("underwater");
            weapon->add( "wc_damaged", wc/2 );
            this_player()->calc_weapon_class();
    }
    write("由於大量的水從你剛打破的裂縫中流出，你身不由己的被這股洪流捲走\n"
          "這難道就是你人生的終點嗎??\n");
    tell_room(this_object(),
    "隨著他打開一條縫隙，大量的水從那兒流出，可憐的"+this_player()->query("c_name")+ "因為站的太近，被滾滾\n"
    "的洪流吞噬，你因為站的比較遠，倖免於難....\n"
    ,this_player());
    "/d/eastland/liang_shan/underjail2"->set("exits/crack","/d/eastland/liang_shan/underjail1");
    this_player()->move_player(TROOM"underjail2","突然一個人被一股洪水捲了過來");
return 1;
}
int do_search(string arg)
{
 if ( arg == "wall") {   
    write("你仔細敲打每面巖壁，你發現有一個地方聲音特別空洞...\n"
    "也許你可以設法打破他...\n");
    return 1;
    } 
 if ( arg == "crack" ) { 
 if ( query("underwater") ) {
 	write("這裡沒有任何裂縫...\n");
 	return 0;
 	}
    write ("你仔細的觀察這個裂縫，應該可以讓你勉強進入(enter)...\n");
    return 1;
    }
 else 
   write("你在水底搜索了半天，除了堅硬的巖壁，好像沒啥特別的!\n"); 
   return 1;
}
int clean_up() { return 0; }             