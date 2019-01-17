//room1.c
inherit ROOM;
int do_da(string arg);
void create()
{
  set("short","������");
  set("long",
      "�����ǰ���ɽ���ӵ������ҡ��м�������ľ׮(mu zhuang)���������ȷ���\n"
    );
  set("exits",([
      "out" : __DIR__"liangong",
     ]));
  set("item_desc", ([
       "muren zhuang" : "һ��ľ׮������ľ�˵����ӹ̶��ڵ��ϣ����˻���(da)������\n",
     ]));     

 setup();

}


void init()
{
        add_action("do_da", "da");
        
}
int do_da(string arg)
{
        object me;
        int costj, costq;
        object weapon;
        me = this_player();
        if (me->is_busy()) return notify_fail("��������æ���أ�\n");
        if (me->is_fighting()) return notify_fail("������ս���У��޷�ר��������\n");
        if ( !living(me)) return notify_fail("�㷢���ˣ�\n");
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "staff")
         return notify_fail("�������������ȷ��ġ�\n");
        if (!arg || arg != "mu zhuang") return notify_fail("��Ҫ��ʲô��������\n");
        costj = random((int)me->query("con"))+1;
        costq = random((int)me->query("str"))+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
              message_vision("$N��һ�ɣ�һ��С���Դ�ײ����ľ׮�ϣ�\n",me);
              me->unconcious();
              return 1;
              }
        me->receive_damage("jing", costj);
        me->receive_damage("qi", costq);       
        message_vision("$Nվ������������ȣ���ʼ��ľ׮�Դ�������\n", me);
        if ( (int)me->query_skill("cuff", 1) < 30 && random(10)>6 ){  
              me->improve_skill("staff", (int)(me->query("int") / 5));
              }
        if ( (int)me->query("combat_exp") < 30000) 
        {
             me->add("potential",random(2));
             me->add("combat_exp",random((int)(me->query("int") / 10)));
        }
        return 1;
}

