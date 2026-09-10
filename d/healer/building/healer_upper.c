#include <mudlib.h>

inherit ROOM;

int view_note() ;
void create()
{
	::create();
        set_short("Healer's upper room", "行醫者練氣室");
	set_long(
@C_LONG_DESCRIPTION
這裡對行醫者而言是莊嚴肅穆的聖地，因為這裡是需要絕對安靜的
地方。靠牆角的蒲團上有幾個年齡不盡相同的行醫者在練習吐納之術。
看看牆上的告示(NOTE)可以得到關於吐納運氣的正確方法。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_func", ([
 		"note": "view_note" 
 		           ]) );
	set( "exits", ([ 
		"down" : "/d/healer/building/healer_inner"
		       ]) );
	
	reset();
}

void init()
{
   add_action("do_study","study") ;
   add_action("do_upgrade","upgrade") ;
}

int do_study(string str)
{
    int skill ;

    if(!str || str != "force")
      return view_note() ;
   
    if(this_player()->query("dou-in"))
       return notify_fail("你想學習更高段的導氣術的話請用 UPGRADE 這個指令\n") ;

    skill = this_player()->query_skill("concentrate") ;
    
    if( !skill || skill <35 )
       return notify_fail("你一坐上蒲團就想站起來,更不用說專心練氣了。\n") ;

    if((int)this_player()->query_exp_stock() < 1000)
        return notify_fail("你的經驗值不夠拿來練氣。\n") ;
            
    this_player()->set("dou-in",1) ;
    this_player()->gain_experience( -1000 );                
    write("你撩袍坐在一個蒲團之上。眼觀鼻,鼻觀心,意守丹田.....\n"
          "你感到四肢百穴有股暖流緩緩流向你的丹田。\n") ;            
                
    return 1 ;
}

int do_upgrade(string str)
{
    int lev,skill,exp ;

    if(!str || str != "force")
      return view_note() ;
    
    lev = this_player()->query("dou-in") ; 
        
    if( !(lev) || lev == 0 )
       return notify_fail("你想學習導氣術的話請用 STUDY 這個指令\n") ;   

    exp = (lev+1)*(lev+1)*(lev+1)*1000 ;

    skill = this_player()->query_skill("concentrate") ;    

    if( (int)this_player()->query_exp_stock() < exp ) 
      {
        return notify_fail("你還須要"+exp+"點經驗值來提升功力。\n") ;   
       }
              
    if( lev == 5 || skill < 30 + lev * 12 )   
       return notify_fail
         ("你撩袍坐在一個蒲團之上。眼觀鼻,鼻觀心,意守丹田.....\n"
          "你感到四肢百穴有股暖流緩緩流向你的丹田。\n"
          "但是你覺得體內的氣並沒有什麼變化。\n") ;            

    write("你撩袍坐在一個蒲團之上。眼觀鼻,鼻觀心,意守丹田.....\n"
          "你感到四肢百穴有股暖流緩緩流向你的丹田。\n"
          "慢慢的,你覺得體內的氣比以前還多。\n") ;            

    this_player()->gain_experience( -exp );
    this_player()->add("dou-in",1) ;
      
    return 1 ;
}


int view_note()
{
  write(
"  氣是人體中最奇妙的力量, 但是只有靠最專注的精神才能將其導出體外。\n"
"想學習導氣(study)和提升(upgrade)體內氣的量, 都和你能否集中精神有\n"
"絕對的關係。\n\n"
"  練習方法如下:\n"
"         學習導氣       :  study force \n"
"         提升氣的量     :  upgrade force \n\n"  )  ;

  return 1 ;
}



