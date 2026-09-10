#include <mudlib.h>
#define HERB_INFO "/d/healer/herb_info/"

inherit ROOM;

//nosave mapping current_herbs=([ ]) ;

void create()
{
	::create();
    set_short("調劑室");
	set_long( @C_LONG_DESCRIPTION
這裡是行醫者配藥的調劑室，在這裡所有的配藥工具都可以讓你自由使用，你
可以看到一張大工作臺，工作臺上放著一本「本草綱目」(book)。如果你要配藥的
話，請先閱讀牆上有關配藥的說明(sign)，靠牆則是個藥櫥(closet), 主要是要
讓醫生們互通有無, 不要造成藥材的浪費及濫用。往南走是行醫者書房。
C_LONG_DESCRIPTION
	);

	set( "item_desc", ([
		"book" : @LONG_BOOK
這本「本草綱目」是一位叫做李時珍的東方學者所撰的藥學經典，你可以查看
(read)這本書的藥方表(list)或藥材解說索引(index)。
LONG_BOOK
,
                "sign" :@LONG_TEXT
要想自己製藥, 除了藥方藥材, 最重要的還是你本身藥物學(medical)
的知識。大部份的藥材都可以在刑大娘的店裡買到, 但有少部份罕見的
便需要你自己到野外採集。
LONG_TEXT
,
                "closet":@CLOSET_DES
這是專為醫生而設的藥櫥, 主要是為互通有無, 增進醫生團結, 避免藥材
的浪費而設立的。 你可以用 get/store <herb> from/in closet, 來存取
藥材。 或是用 search closet 來看看藥材的存量 。
CLOSET_DES
 ]) );
 	set("light",1);

        set("current_herb",([ ])) ;

        set( "exits", ([
		"south" : "/d/healer/building/healer_inner" ]) );
	reset();
}

void init()
{
	    add_action( "do_read", "read" ) ;
        add_action( "do_store", "store" ) ;
        add_action( "do_get", "get" ) ;
        add_action( "do_search","search" ) ;
}

int do_store(string str)
{
     string  ob_name,ob_cname,ob_filename,ob_num,target  ;
     object  ob ;

     if (!str) return 0;
     if(sscanf(str,"%s in closet",ob_name)!=1) return 0 ;

     if( !(ob=present(ob_name,this_player())) )
         {
            write("你身上沒有叫"+ob_name+"的東西。\n") ;
            return 1 ;
          }
     if ( ! ob->query("ident") )
         {
           write("只有藥材才能放進藥櫥。\n") ;
           return 1 ;
          }

     sscanf(file_name(ob),"%s#%s",ob_filename,ob_num);
     ob_filename=replace_string(ob_filename,"/","*");
     ob_cname = ob->query("c_name") ;

     this_object()->add("current_herb/"+ob_filename,1) ;
     ob->remove() ;

     tell_object(this_player(),
                  "你把"+ob_cname+"放進藥櫥。\n") ;
     tell_room(environment(this_object()),
               this_player()->query("c_name")+"把"+ob_cname+"放進藥櫥。\n");
     return 1 ;
}

int do_get(string str)
{
     int     i,no,j,found,amount ;
     string  ob_name,ob_cname,*current_list,*ids,ob_filename  ;
     object  ob ;
     mapping herbs ;

     if(!str) return 0;
     if(sscanf(str,"%s from closet",ob_name)!=1) return 0 ;

     herbs = this_object()->query("current_herb") ;
     no = sizeof(herbs) ;

     if(!no||no==0)
        {
          write("現在藥櫥裡是空的。\n") ;
          return 1 ;
         }
     current_list = keys(herbs) ;

     if (ob_name == "all") {
       for (i=0; i < no ; i ++) {
         ob_filename=replace_string(current_list[i],"*","/");
         amount=this_object()->query("current_herb/"+current_list[i]);
         ob=new(ob_filename) ;
         ob->move(this_player()) ;
         ob_cname = ob->query("c_name") ;
         for (j=0; j < amount; j++) {
           ob=new(ob_filename) ;
           ob->move(this_player()) ;
           ob_cname = ob->query("c_name") ;
           tell_object(this_player(),"你從藥櫥中拿出"+ob_cname+"來。\n") ;
           tell_room(environment(this_player()),
                     this_player()->query("c_name")+"從藥櫥中拿出"+
                     ob_cname+"來。\n",this_player()) ;
         }
       }
       this_object()->delete("current_herb");
       return 1;
     }
     for(i=0;i<no;i++)
        {
           ob_filename=replace_string(current_list[i],"*","/");
           ob = find_object_or_load(ob_filename) ;
           ids = ob->query("id");
           found=0;
           for (j=0; j < sizeof(ids); j++) {
             if(ids[j]==ob_name) { found=1 ; break ; }
           }
           if (found==1) break;
           if(i==no-1)
              {
                tell_object(this_player(),"藥櫥中沒有那種東東。\n") ;
                return 1 ;
              }
        }
     no = this_object()->query("current_herb/"+current_list[i]);
     if(!no||no==0)
            return notify_fail("藥櫥裡面沒有那種東東。\n") ;

     if(no==1)
         this_object()->delete("current_herb/"+current_list[i]) ;
     else
         this_object()->add("current_herb/"+current_list[i],-1) ;

     ob=new(ob_filename) ;
     ob->move(this_player()) ;
     ob_cname = ob->query("c_name") ;

     tell_object(this_player(),"你從藥櫥中拿出"+ob_cname+"來。\n") ;

     tell_room(environment(this_player()),this_player()->query("c_name")+
               "從藥櫥中拿出"+ob_cname+"來。\n",this_player()) ;

     return 1 ;
}

int do_search(string str)
{
     int i,no,amount ;
     string msg,ob_name,ob_cname,*current_list ;
     object ob ;
     mapping herbs ;

     if(str!="closet")
        {
          write("你想找什麼 ?\n") ;
          return 1 ;
         }
     herbs = this_object()->query("current_herb") ;
     no = sizeof(herbs) ;

     if(!no||no==0)
        {
          write("現在藥櫥裡是空的。\n") ;
          return 1 ;
         }
     current_list = keys(herbs) ;
     msg = "你看了看藥櫥, 看到以下的藥井然有序的躺在櫃子中:\n" ;

     for(i=0;i<no;i++)
        {
           amount=this_object()->query("current_herb/"+current_list[i]);
           current_list[i]=replace_string(current_list[i],"*","/");
           ob = find_object_or_load(current_list[i]) ;
           ob_name  = ob->query("name") ;
           ob_cname = ob->query("c_name") ;

           ob_name=ob_cname+"("+ob_name+")";
           msg = msg+sprintf("%-30s還有%3d個\n",ob_name,amount);

        }
     tell_object(this_player(),msg) ;

     return 1 ;
}

int do_read( string str )
{
	int page;

	if( !str || str=="" )
	    return notify_fail("你要讀什麼東東？\n");
	if( str=="list" ) {
		cat(	HERB_INFO"c_list");
		return 1;
	} else if( str=="index" ) {
		cat( HERB_INFO"c_index");
		return 1;
	} else if( sscanf(str, "page %d", page)==1 ) {
	  if ( file_exists(HERB_INFO"c_page" + page ) ){
		cat( HERB_INFO"c_page" + page );
		return 1;
          } else {
                cat( HERB_INFO"c_no_page") ;
                return 1;
          }
	}
}

int clean_up() { return 0; }
