#include <mudlib.h>
#include <ansi.h>

inherit REGROOM;

void create()
{
    set("short",  "����.��.����.���ϡ�ע�ᴦ" );
    set("long", 
    NOR"��ӭ����"+HIG"����.��.����.���ϡ�"NOR+"�Ĵ������磬 Ϊ���ܹ����ò���ʱ��\n"+
    "Ϊ���ṩ����������Ϣ���������뽭��֮ǰ������ϣ�����ܹ�ע������\n"+
    "�����ʼ���ַ�����ĵ����ʼ���ַ��������Ψһ����������ϵ��;����Ҳ\n"+
    "�������������Ψһ�ܹ���֤��ݵķ�ʽ������������ȷ��ע��������\n"+
    "����ַ��ע��ǰ������������"+CYN"��"+HIR"read notes"NOR+CYN"��"NOR+"���Ķ�ע����֪����Ҳ����\n"+
    "����"+CYN"��"+HIR"read rules"NOR+CYN"��"NOR"����ϸ�Ķ��������������һ��׼����������ͬ��\n"+
    "����������ע�����ĵ��������ַ�� ע�᷽ʽ���£�\n"
    
    CYN"��"HIR"register "NOR GRN"���������ַ"CYN"��\n"+
    CYN"��"HIR"zhuce "NOR GRN "   ���������ַ"CYN"��\n\n"+
    "����㲻Ը������ĵ����ʼ���ַ��������"HIR"leave"NOR+CYN"�뿪�˵ء�\n"+
    "\t\t\t\t"+HIG"����.��.����.���ϡ�"NOR+"��ʦЭ��\n"+
    "\t\t\t\t"+"   ������������¶�ʮ����\n"
        );
        set("no_fight", 1);
        setup();
}

void init()
{       object ob;
        ::init();
        add_action("do_read","read");
        add_action("do_leave","leave");
        if( interactive(ob = this_player()) ) 
       {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }

}

void greeting(object ob)
{
    write(HIR BLINK"\nHi!"NOR+HIC"��λ"HIW+RANK_D->query_respect(ob)+HIC", ��ӭ����"+CHINESE_MUD_NAME+",������ע�ᴦ��\n"+"    ��һ��Ҫ��ϸ�Ķ������֪ͨӴ!\n\n"NOR);
        return;
}
int do_read(string arg)
{
        switch(arg)
        {
                case "notes":
                        write(
                                "�����������ȷ�ĵ��������ַ����ȷ��ע���ż�����ȷ�͵������\n"+
                                "�����û�еõ�ע�����룬����ԭ���������¼����ע�ᡣ\n"+
                                "������������ʦ��ϵ������������ҳ�����ԡ�\n"+
                                GRN"jzbyt@sina.com\n"NOR
                                );
                        break;
                case "rules":
                        write(
                                "������help ����ȡ��ϸ����Ϸ��������Υ����Υ���ؾ���\n"+
                                "����㲻ͬ�����������ʦ��ϵ������ leave �˳�������\n"
                                );
                        break;
                default:
                        return 0;
        }
        return 1;
}

int do_leave(object ob, object link_ob)
{
    ob=this_player();
    if(wizardp(ob)||ob->query("registered"))
    {
        ob->move("/d/city/wumiao");
        tell_room(environment(ob),ob->name()+"�Ҵ�ææ���뿪��ע�����\n");
        return 1;
    }
    else {
    link_ob = ob->query_temp("link_ob");
    if( !link_ob ) return 0;   
    seteuid(getuid());
    rm( link_ob->query_save_file() + __SAVE_EXTENSION__ );
    rm( ob->query_save_file() + __SAVE_EXTENSION__ );
    write("�ðɣ��ټ�! ^&^��\n");
    destruct(ob);
    return 0;
    }
}

