#include <mudlib.h>
#include "/d/healer/healer.h"

#define DIV "...................."

inherit "/std/room/std_storage.c";

int view_note() ;
void create()
{
	::create();
        set_short("Healer's study room", "行醫者書房");
	set_long(
@C_LONG_DESCRIPTION
這裡是醫生傳承知識的地方。偌大的空曠房間, 在靠三邊的牆邊都有桌椅
供用功的行醫者鈔錄筆記, 記錄心得。而正面對你的那面牆, 則是放置全部的
醫經的書櫃(closet)。 你應該能從書櫃中找到許多有用的書, 並從中得到許多
寶貴的知識。而中間一根柱子上刻著『惜福』兩個大字。原來這裡也是醫生們
為照顧晚輩而專門設置的儲藏室。再仔細一看.. 似乎旁邊有一行字(note)。
C_LONG_DESCRIPTION
	);

	set( "light", 1 );
        set( "item_func", ([
 		"closet": "view_closet" 
 		           ]) );
	set( "exits", ([ 
		"north" : "/d/healer/building/healer_inner"
		       ]) );
	set( "max_amount",50) ;               //這個房間清過後物件儲存的最大值
        set("weapon_res",({10,0}) );
    set("class_name","healer") ;           //這個房間所在公會名稱, 用以清除
	                                      //該公會成員不能用的裝備.
	set("msg_arg","彩虹仙子");                                                     
//     reset();              //咦..儲藏室還加這行?....hch.
}

 int clean_up() {return 0; }

void init()
{
   ::init() ;
   add_action("do_read","read") ;
   add_action("view_closet","search") ;
}

string query_intro()
{
    string intro ;

    intro = "\t    針灸是由東方大陸發源的神秘醫技。相傳最早是由一位名為\n"
            "\t『如風』的醫生開始使用針療的方法來治病。然而最離奇的是\n"
            "\t張醫生總是來無影去無蹤,有怪病的地方就出現他的行跡,也順便\n"
            "\t教導他人針灸的方法。當針灸普及全大陸後, 就再沒人見過他的\n"
            "\t蹤跡。於是, 就有張大夫是wing大神的說法開始流傳。\n"
            "\t然而卻沒有人能證實這項說詞。但是我個人認為, 這就像醫界中\n"
            "\t傳言我是那個專門到處嚇人的色狼—雷神之子。一樣無稽。\n"
            "\t                                湘東儒醫  韓清逸\n"
            "\n\n\t下一頁則是本書的索引(index)。\n"
            "\t內容則是在各頁(page)中。\n" ;
 
    return intro ; 
}

string query_index()
{
    int i,size ;
    string msg, *merid, *eff ;
    
    merid = ALL_POINTS->query_meridians()  ;
    eff = USE_POINTS->now_working()   ; 
    
    msg = "\t索引:\n" ;    
    
    size = sizeof(merid) ;
    for(i=1;i<size;i++)        
       msg = msg + sprintf("%s%-20s%s%s%5d\n","\t\t",merid[i],DIV,"page",i) ;

    msg = msg + "\t以下是已知有作用的穴道群\n" ;
    size = sizeof(eff) ;
    for(i=0;i<size;i++)        
       msg = msg + sprintf("%s%-20s%s%s%5d\n","\t\t",eff[i],DIV,"page",i+100) ;
           
    return msg ;
                
}

string page_contain(int page)
{
    int i,size ;
    string msg,*merid_eff,describ ;
    
    i = page ; 
    if( page < 100 )
      {
        merid_eff = ALL_POINTS->query_meridians_by_no(page) ;
//        describ = ALL_POINTS->query_merid_describ(page) ;
       } 
    else
      {
        page =page - 100 ;
        merid_eff = USE_POINTS->query_eff_pts(page) ;
 //       describ = USE_POINTS->query_eff_describ(page) ;
       }     
    
    if(!merid_eff||(size=sizeof(merid_eff))==0)
       return "你把這本書上上下下左左右右前前後後全翻遍了,\n"
              "但就是找沒有這麼一頁。\n" ;

    msg = sprintf("\t第%d頁......%10s的穴道群, 共%d穴\n",i,merid_eff[0],size-1) ; 
//    msg = msg + describ ;

    for( i=1 ; i<size ; i++ ) {
      if (stringp(merid_eff[i]))
      msg = msg + (string)sprintf("\t\t%s\n",merid_eff[i]) ;
    }       
    return msg ;
}

int do_read(string str)
{
    int page_no ;
    string arg ;
        
    if(!str)
      return notify_fail("你想讀什麼 ??\n") ;

    if(str=="針灸治要"||str=="book"||str=="bible")
      { 
       write(query_intro()) ;
       return 1;
      }   
      
    if(str=="index"||str=="索引")   
      { 
       write(query_index()) ;
       return 1;
      }   
    else
      {
        if( sscanf(str,"%s %d",arg,page_no)==2 )
           {
             if(lower_case(arg) == "page" ) 
                write(page_contain(page_no)) ;    
            }
        else    
           { 
             if(lower_case(str)=="page")
                write("你想讀那一頁 ??\n" ) ;
             else
               return notify_fail("你想讀什麼 ??\n") ;     
            }
      }  
    return 1 ;     
}

int view_closet(string arg)
{
  write(
"   你在書櫃中翻了翻, 發現除了一本叫『 針灸治要 』的書(book)以外,其於\n"
"大多殘缺不全了。\n"
 )  ;
  return 1 ;
}
