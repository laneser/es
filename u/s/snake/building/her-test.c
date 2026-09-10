#include <mudlib.h>
#include <guilds.h>
#include <move.h>
#include <guilds.h>

#define HERB_INFO "/d/healer/herb_info/"
#define MAX_ITEMS       10      //
#define DIGITS  ( { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" } )  //
#define REM_ITEM_PROP   "her_item"
#define REM_ITEM_PROP_  REM_ITEM_PROP+"_"

inherit ROOM;

//nosave mapping current_herbs=([ ]) ;

void create()
{
        ::create();
    set_short("藥庫");
        set_long( @C_LONG_DESCRIPTION
這裡是行醫者的藥庫，在這裡存放著行醫者自己出外收集回來的藥物，在大門門上
掛著一個登記簿，登記簿上寫著很多人名。靠牆邊是個大藥櫃(closet), 分開
很多個抽屜，抽屜上寫著其主人的名字。主要是每個醫生所需要的藥物不盡相同，
為免其混亂，每人只能拿自己抽屜裡的藥物。往西走是行醫者的調劑室。
C_LONG_DESCRIPTION
        );

        set( "item_desc", ([
                "closet":@CLOSET_DES
這是專為醫生而設的藥櫃, 上面有很多個抽屜。主要是備不時之需，避免藥材的
浪費而設立的。 每個行醫者只能拿自己抽屜裡的藥物。
你可以用 get/store <herb> from/in closet, 來存取藥材。
或是用 search closet 來看看藥材的存量 。
CLOSET_DES
 ]) );
        set("light",1);

        set("current_herb",([ ])) ;

        set( "exits", ([
                "west" : "/d/healer/building/healer_reagent" ]) );
        reset();
}

void init()
{
        add_action( "do_store", "store" ) ;
        add_action( "do_get", "get" ) ;
        add_action( "do_search","search" ) ;
}

int do_store(string str)
{
     string ob_name,ob_cname,ob_filename,ob_num,target  ;
     object ob,me,obs ;
     int i, j ,my_item_num;

     me= this_player();
     my_item_num = me->query( REM_ITEM_PROP );
     j=0;
     if(my_item_num > MAX_ITEMS) my_item_num=MAX_ITEMS;
     for ( i = 0; i < my_item_num; i ++ )
       {
          if( !undefinedp(me->query( REM_ITEM_PROP_+DIGITS[i]) ))
             j++;
             {
                me->set( REM_ITEM_PROP, my_item_num );
             }
       }
     if (j>=MAX_ITEMS) return notify_fail(
        "你存的東西太多了。\n" );

     j = me->query( REM_ITEM_PROP );

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

      me->set( REM_ITEM_PROP_+DIGITS[my_item_num],base_name( file_name(ob) ) ) ;
      my_item_num++;
      me->set( REM_ITEM_PROP, my_item_num);


     ob->remove() ;

     tell_object(this_player(),
                  "你把"+ob_cname+"放進藥櫥。\n") ;
     tell_room(environment(this_object()),
               this_player()->query("c_name")+"把"+ob_cname+"放進藥櫥。\n");
     return 1 ;
}

int do_get(string str)
{
     int i,no,j,found,amount,my_item_num ;
     string ob_name,ob_cname,*current_list,*ids,ob_filename  ;
     object ob,me,item ;

     if(!str) return 0;
     if(sscanf(str,"%s from closet",ob_name)!=1) return 0 ;

     me= this_player();
     my_item_num = me->query( REM_ITEM_PROP );

     if(!my_item_num||my_item_num==0)
        {
          write("現在藥櫥裡是空的。\n") ;
          return 1 ;
         }

     if (ob_name == "all") {
        j = me->query( REM_ITEM_PROP );
       for (i=0; i < my_item_num ; i ++)
        {
            ob = new(  me->query( REM_ITEM_PROP_+DIGITS[i] ) );
            me->delete(REM_ITEM_PROP_+DIGITS[i]);
            ob->move( me );
         }
         tell_object(this_player(),"你從藥櫥中拿出所有的藥物來。\n") ;
         tell_room(environment(this_player()),
                   this_player()->query("c_name")+"從藥櫥中拿出所有的藥物來。\n",this_player()) ;
         me->set( REM_ITEM_PROP, 0);
       return 1;
      }
       me= this_player();
       my_item_num = me->query( REM_ITEM_PROP );
       if(my_item_num > MAX_ITEMS) my_item_num=MAX_ITEMS;
       for ( i = 0; i < my_item_num; i ++ )
            ob_filename=me->query( REM_ITEM_PROP_+DIGITS[i];
            ob = find_object_or_load(ob_filename) ;
            ids = ob->query("id");
/*           if(me->query( REM_ITEM_PROP_+DIGITS[i])==base_name( file_name(ob) ) ) break; */
             if(ids[i]==ob_name) { found=1 ; break ; }
       if(i<my_item_num)  {
           for(j=i; j < my_item_num-1; j++)
              me->set(REM_ITEM_PROP_+DIGITS[j],me->query( REM_ITEM_PROP_+DIGITS[j+1]) );
              me->delete(REM_ITEM_PROP_+DIGITS[my_item_num-1]);
              me->set( REM_ITEM_PROP, my_item_num-1 );
        }
     if(!my_item_num||my_item_num==0)
            return notify_fail("藥櫥裡面沒有那種東東。\n") ;

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
     int i,no,my_item_num ;
     string msg,ob_name,ob_cname,*current_list ;
     object ob,me ;

     if(str!="closet")
        {
          write("你想找什麼 ?\n") ;
          return 1 ;
         }
     me= this_player();
     my_item_num = me->query( REM_ITEM_PROP );
     if(my_item_num > MAX_ITEMS) my_item_num=MAX_ITEMS;


     if(!my_item_num||my_item_num==0)
        {
          write("現在藥櫥裡是空的。\n") ;
          return 1 ;
         }
     msg = "你看了看藥櫥, 看到以下的藥井然有序的躺在櫃子中:\n" ;


     for(i=0;i<my_item_num;i++)
        {
           ob = me->query( REM_ITEM_PROP_+DIGITS[i] );
           ob_cname  = ob->query("short") ;
           ob_name = ob->query("name") ;

           ob_name=ob_cname+" ("+ob_name+")";

           msg = msg+sprintf("%-30s\n",ob_name);

        }
     tell_object(this_player(),msg) ;

     return 1 ;
}

int clean_up() { return 0; }
