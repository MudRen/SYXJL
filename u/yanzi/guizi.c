#include <ansi.h>
inherit ITEM;
int do_store(string);
int do_getout(string);
void create()
{
        string file = "/u/yanzi/cangku.o";        
        set_name("储藏柜", ({ "chucang gui" }) );
        set("long", @LONG
这里是一大大的储藏柜，里面放满了各种各样的杂物。
LONG
        );
        set("unit", "个");
        set("material","精铁");        
        set("no_get",1);
        set("no_steal",1);
        set("no_put",1);
        set("no_drop",1);
        if( file_size(file) > 0 )
                restore_object("/u/yanzi/cangku");        
        setup();
}
void init()
{
        add_action("do_store", "store");
        add_action("do_check", "chaxun");
        add_action("do_getout", "getout");      
}

//******************************************************//

int do_store(string arg)
{ 
    object ob,me,obj;
    mapping this_store;
    mapping *all_ob;
    me=this_player();
    obj=this_object();
    if( !arg||!(ob = present(arg, this_player())) )
       return notify_fail("你要把什么放到储藏柜里呢？\n");
    if( ob->query("money_id") )     
       return notify_fail("你要把钱往柜子里放，但又觉得不保险，只得作罢！\n");
    if( first_inventory(ob))
       return notify_fail("还是先把"+ob->name()+"里面的东西取出来再往柜子里放吧。\n");
    if (ob->is_character())
       return notify_fail("活物可不能生塞到柜子里呀！\n");
    all_ob = obj->query("store_ob");
    if(!all_ob) all_ob = ({});
    if(sizeof(all_ob) >= 5 )
       return notify_fail("柜子里已经塞了太多的东西了，还是先拿出一点再放吧。\n");
    this_store = ([ ]);
    this_store["file"] = base_name(ob);
    this_store["name"] = ob->name();
    all_ob += ({this_store});
    obj->set("store_ob",all_ob);
    save_object("/u/yanzi/cangku");
//    obj->set("store_ob",all_ob); 
    message_vision("$N把身上的" + ob->name() + "拿出来放进柜子里了。\n", me);
    destruct(ob);
    return 1;
}
/*******************************************/
int do_check()
{
        int i;
        string str;
        mapping this_store;
        mapping *all_store;
        mapping *all_ob;
        object me,obj;
        obj=this_object();
        me=this_player();
        all_store = obj->query("store_ob");
        if(!all_store ) return notify_fail("柜子里空空如也，啥也没有！\n");
        write("\n柜子里目前存放的物品有：\n");
        for(i=0;i<sizeof(all_store);i++)
        {
                this_store = all_store[i];         
                str=sprintf("%d            %s\n",i,this_store["name"]); 
                write(str);
        }
        return 1;
}
/**************************************************/
int do_getout( string arg )
{
        object ob,me,obj;
        int num;
        string file,err,name;
        mapping this_store;
        mapping *all_store;
        mapping *all_ob;        
        obj=this_object();
        me=this_player();
        if(!arg) return 0;
        if( !sscanf(arg, "%d" , num ) ) return 0;
        all_store = obj->query("store_ob");
        if((num<0)|| (num>=sizeof(all_store)) ) return 0;
        this_store = all_store[num];               
        file = this_store["file"] ;
        err = catch(ob = new(file));
        if( err || !ob ) {
                write("你觉得似乎失落了什麽重要的东西，最好通知一下巫师。\n");
                log_file("AUTOLOAD", sprintf("Fail to autoload %s of %s, error \n",
                        file, this_object()->query("name"), err));
                return 1;
                }
        export_uid(ob);
        ob->move(me);
        if( (name = this_store["name"]) != ob->name() ) ob->set("name",name);
        all_store[num] = 0;
        all_store -= ({0});
         if(!sizeof(all_store))
               obj->delete("store_ob");
          else obj->set("store_ob",all_ob);
        save_object("/u/yanzi/cangku");        
        message_vision("$N从柜子里取出了"+ob->name()+"\n",me );
        return 1;
}


