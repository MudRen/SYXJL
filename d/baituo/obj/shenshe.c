//shenshe.c
inherit ITEM;
void create()
{
        set_name("��·����", ({ "shenshe"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ����ʶ·���������ߣ����԰����˴�����
                      ��ɽ��(��Ҽ���home����)\n");
                set("unit", "��");
                set("value", 0);
        }
}
void init()
{
 add_action("do_home","home");
}
int do_home()
{
    object me = this_player();
   if(me->query("family/family_name") != "����ɽ��")
          return notify_fail("�㲻�ǰ���ɽ�ɵ��ӣ�����·���ߡ�������ʹ����\n");  
   if( base_name(environment(this_player())) == "/d/city/lao" ) 
          return notify_fail("���������ݼ���������·���ߡ�������ѽ������ҳ���ѽ��\n");     message_vision("$N�ӻ����ͳ�����·���ߡ������ﲻ֪����Щʲô��\n
   �ͼ�����·���ߡ�����о�ӣ�ҡͷ��β�ذ�$N������ɽ��ȥ������\n",me);
   me->move("/d/baituo/damen");
   return 1;
}

