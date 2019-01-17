#include <ansi.h>
inherit ITEM;
int do_store(string);
int do_getout(string);
void create()
{
        string file = "/u/yanzi/cangku.o";        
        set_name("���ع�", ({ "chucang gui" }) );
        set("long", @LONG
������һ���Ĵ��ع���������˸��ָ��������
LONG
        );
        set("unit", "��");
        set("material","����");        
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
       return notify_fail("��Ҫ��ʲô�ŵ����ع����أ�\n");
    if( ob->query("money_id") )     
       return notify_fail("��Ҫ��Ǯ��������ţ����־��ò����գ�ֻ�����գ�\n");
    if( first_inventory(ob))
       return notify_fail("�����Ȱ�"+ob->name()+"����Ķ���ȡ��������������Űɡ�\n");
    if (ob->is_character())
       return notify_fail("����ɲ���������������ѽ��\n");
    all_ob = obj->query("store_ob");
    if(!all_ob) all_ob = ({});
    if(sizeof(all_ob) >= 5 )
       return notify_fail("�������Ѿ�����̫��Ķ����ˣ��������ó�һ���ٷŰɡ�\n");
    this_store = ([ ]);
    this_store["file"] = base_name(ob);
    this_store["name"] = ob->name();
    all_ob += ({this_store});
    obj->set("store_ob",all_ob);
    save_object("/u/yanzi/cangku");
//    obj->set("store_ob",all_ob); 
    message_vision("$N�����ϵ�" + ob->name() + "�ó����Ž��������ˡ�\n", me);
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
        if(!all_store ) return notify_fail("������տ���Ҳ��ɶҲû�У�\n");
        write("\n������Ŀǰ��ŵ���Ʒ�У�\n");
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
                write("������ƺ�ʧ����ʲ����Ҫ�Ķ��������֪ͨһ����ʦ��\n");
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
        message_vision("$N�ӹ�����ȡ����"+ob->name()+"\n",me );
        return 1;
}


