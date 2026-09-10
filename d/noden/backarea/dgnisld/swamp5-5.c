#include "dgnisld.h"

inherit ROOM;

int  steps;
int  lights;
int  balls;
int  rdm;

void create()
{
	::create();
	steps = 1;
	lights = 1;
	balls = 1;
	rdm = 9;
	set( "light" , 1 ) ;
	set( "dig", 1 );
	set_short( "cellar",  "地洞" );
	set_long(
	    "A cellar under the swamp. You feel watery here. You can see\n"
	"a stair made of mire, it looks weak to load anyone. To the west\n"
	"you can see something under the wall. There has a fetor here, so\n"
	"you feel very ailing now. But it's queer in around. There is a \n"
	"torch on the wall near the stair.\n",
	    "沼澤下的地洞，這裡十分地潮溼。這裡有一座用泥土(mire)所造的\n"
        "樓梯(stair) ，西邊的牆(wall)好像有東西。整個房間瀰漫著一股刺鼻\n"
        "的惡臭，令你感到不舒服想吐！周圍(around)充滿了可疑的氣氛。靠近\n"
        "樓梯的牆上有一把火炬(torch)。\n" );
        
        set( "item_func", ([ "around" : "msg_around" ,
                             "wall"   : "msg_wall",
                             "stair"  : "msg_stair",
                             "mire"   : "msg_mire",
                             "torch"  : "msg_torch",    ]) );
                             
        set( "exits", ([  "up" : DGNISLD"swamp5-6",  ]) );
        set( "pre_exit_func", ([
                 "up"  : "to_up" ,    ])  );
}

void init()
{
       add_action("light_on_off"  , "light" );
       add_action("enter_hole", "enter" );
}

int to_up()
{
       object  obj;
       
       obj= present( "dragon ball", this_player() );
       if (( obj!=0) && ( (int)obj->query("dgnball")==1 )) {
         write( !can_read_chinese() ?
           "A magic power stop you to climb up!!\n":
           "突然有一股力量阻止你爬上去！\n");
         return 1;
       }
       else {
         write("You climd up the stair and go up.\n");
         return 0;
       }
}

int to_find_dig(string str)
{
       object obj;
       int chinese_mode;
       chinese_mode = can_read_chinese();
       
       if ( (str!="mire") || (steps<4) )
         write("You can't dig it!\n");
       else if ( (steps>3) && (steps<rdm) ) {
         write( !chinese_mode ?
           "You dig a lot of time, and you feel tired.\n":
           "你挖了一會兒而感到疲倦。\n");
          steps++;
       }
       else if ( (steps>(rdm-1)) && (balls==1) ) {
         write ( !chinese_mode ?
           "You dig and dig, finnally you find a light ball!\n"
           "But there appear someone and take it away.\n":
           "你一挖再挖，最後終於發現了一顆會發光的球。\n"
           "但是突然出現一個人把它拿走了。\n");
         obj = new(DGNISLD"monster/dgnbgrd.c");
         obj->move(this_object());
         balls = 0 ;
       }
       else write( !chinese_mode ?
            "You find nothing in there! :( \n" :
            "你發現裡面竟是空的！白廢力氣了。:( \n");
       return 1;     
}

int light_on_off(string str)
{
       int chinese_mode;
       chinese_mode = can_read_chinese();
       
       if (str=="off torch") {
         if (lights==1) {
           write( !chinese_mode ?
             "The torch is dead again.\n":"火炬的火熄滅了。\n");
           lights = 0;
           set ("light" ,0);
         }
         else write( !chinese_mode ?
           "The torch is not burning!\n":"火炬是熄滅的。\n");  
         return 1;
       }     
       else if (str=="on torch") {
         if (lights==0) {
           write( !can_read_chinese() ?
                "The torch becomes burning.\n" :
                "火炬開始燃燒，你聽到劈咧啪喇的聲音。\n");
           lights = 1;
           set("light" ,1);
         }
         else 
           write( !chinese_mode ?
             "The torch is burning!\n":"火炬已經是燃燒的。\n");
         return 1;
       }  
       else 
         return 0;
}

int msg_around()
{
        int chinese_mode;
        chinese_mode = can_read_chinese();
        
        if (lights==1) {
          if (balls==1) write( !chinese_mode ?
            "There are a little light in around, it is so potty\n"
            "that you almost can't tell it form the one of your\n"
            "torch. Because ligtht of torch is too strong!\n":
            "你似乎看到一股很微弱的光閃了一閃，但是由於火炬太亮了，\n"                                   
            "你無法分辨閃光從哪兒來。\n");
          else write( !chinese_mode ?
            "This place is very dusty, you find nothing special here.\n":
            "這地方很髒亂，你並沒有找到任何特別的東西。\n");
        }
        else {
          if (balls==1) {
            steps = 2 ;
            write( !chinese_mode ?
              "In the dark, you see a potty light from the stair.\n":
              "在黑暗中你發現一股閃光由樓梯方向而來。\n" );
          } else write( !chinese_mode ?
            "You feel more dark now, but still nothing special.\n":
            "你覺得現在比較暗了，但仍然沒有找到任何特別的東西。\n");
        }  
        return 1;  
}

int msg_stair()
{
        int chinese_mode;
        chinese_mode = can_read_chinese();
        
        if ( (steps>1) && (lights==0) && (balls==1) ) {
          write( !chinese_mode ?
            "You canvass it and find the light is comimg from the\n"
            "mire near middle of the stair.\n":
            "你仔細看那樓梯，發現光從樓梯間的泥土中滲出來。\n");
          steps = 3;
        }
        else write( !chinese_mode ?
            "It is a normal stair and made by mire.\n"
            "You find nothing special on it.\n":
            "這是泥土堆成的樓梯，沒甚麼特別的。\n");
        return 1;
}

int msg_mire()
{
        int chinese_mode;
        chinese_mode = can_read_chinese();
        
        if (steps>(rdm-1))
          write( !chinese_mode ?
            "The mire has been digged deeply!\n":"它被挖得亂七八糟。\n");
        else if ( (steps>4) && (steps<rdm) )
          write( !chinese_mode ?
            "The mire has been a little digged!\n":"它被挖掉一些。\n");
        else if ( (steps<5) && (steps>2) && (lights==0) ) {
          write( !chinese_mode ?
            "There is some potty light transude in it.\n":
            "有微量的光線從這裡滲出來。\n");
          steps = 4;
          rdm = 6 + random(4) ;
        }
        else write( !chinese_mode ?
            "It's dusty, the ingredient of this stair.\n":
            "很髒的泥土，這樓梯的主要材料。\n");
        return 1;  
}

int msg_wall()
{
       int x;
       int chinese_mode;
       chinese_mode = can_read_chinese();
       x=(int)(DGNISLD"entrance.c"->get_cropps());

       if (x==0)
         write( !chinese_mode ?
           "It is a mired wall.\n":"這是普通的土牆。\n");  
       else if (x==1)
         write( !chinese_mode ?
           "You see a small hole which can let only one person enter\n"
           "and looks like very weak. You can type hole to enter.\n":
           "你看到一個小洞。它小到一次只能讓一人通過(enter)。\n"
           "它看起來危危欲墜，好像隨時都會崩壞。\n");         
       else write( !chinese_mode ?
           "You find a small hole, but it's broken.\n":
           "你找到一個小洞，可惜這洞已經毀了！\n");  
       return 1;                            
}

int msg_torch()
{
       int chinese_mode;
       chinese_mode = can_read_chinese();
       
       if ( lights == 1 )
         write( !chinese_mode ?
           "The torch is burning, you can light off it.\n":
           "火炬的火正在熊熊地燃燒著。你可以熄滅(light off) 它。\n");
       else
         write( !chinese_mode ?
           "The torch is not light, you can light on it.\n":
           "火炬安安靜靜地插在牆上。你可以點燃(light on) 它。\n"); 
       return 1;
}

int enter_hole(string str)
{
      int x;
      
      x = (int)(DGNISLD"entrance.c"->get_cropps());
      if( (!str) || (str=="") )
        return notify_fail("Enter what ?\n");
      if( (str!="hole") || (x==0) )
        return notify_fail( !can_read_chinese()?
          "There is no "+str+" here !\n":"這裡沒有"+str+"！\n");  
      else if (x==1)
        this_player()->move_player(DGNISLD"entrance", "", "enter hole") ;
      else if (x==2) 
        write( !can_read_chinese() ?
          "The hole is broken, you can't enter it!\n":
          "這洞已經毀了，你無法進入！\n");
      else 
        write("What?\n");
      return 1;    
}                    

void reset()
{
      ::reset();
      steps = 1;
      lights = 1;
      balls = 1;
      rdm = 9;
}
