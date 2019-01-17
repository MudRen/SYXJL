// Room: /d/wuguan/xiwuchang1.c
// Date: 99/05/30 by Byt

#include <ansi.h>
inherit ROOM;
int do_da(string arg);

void create()
{
        set("short", "�����䳡");
        set("long", @LONG
���Ǽ���ķ��ӣ�ʮ�ֿ����������������ﺹ��䤱��Ŀ����Ź���
������һЩ�����õĹ��ߣ�ǽ�߰���һ��ľ��׮(muren zhuang)��
LONG);
        set("exits", ([
                "east" : __DIR__"changlang5",
                "north" : __DIR__"xiwuchang1",                
        ]));
        set("item_desc", ([
          "muren zhuang" : "һ��ľ׮������ľ�˵����ӹ̶��ڵ��ϣ����˻���(da)������\n",
        ]));
        set("outdoors", "wuguan");
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

        me = this_player();
        if (me->is_busy()) return notify_fail("��������æ���أ�\n");
        if (me->is_fighting()) return notify_fail("������ս���У��޷�ר��������\n");
        if ( !living(me)) return notify_fail("�㷢���ˣ�\n");
        if( objectp( me->query_temp("weapon")) ) return notify_fail("ֻ�п��ֲ��ܴ�ľ��׮��\n");
        if (!arg || arg != "muren zhuang") return notify_fail("��Ҫ��ʲô��������\n");
        costj = random((int)me->query("con"))+1;
        costq = random((int)me->query("str"))+1;

        if ((int)me->query("jing") < costj || (int)me->query("qi") < costq){
              message_vision("$N��һ�ɣ�һ��С���Դ�ײ����ľ��׮�ϣ�\n",me);
              me->unconcious();
              return 1;
              }
        me->receive_damage("jing", costj);
        me->receive_damage("qi", costq);       
        message_vision("$Nվ������������ȭ����ʼ��ľ��׮�Դ�������\n", me);
        if ( (int)me->query_skill("cuff", 1) < 30 && random(10)>6 ){  
              write(HIM"���ں�ľ��׮�ĶԴ��������˲��ٻ�������\n"NOR);
             switch(random(4)){
                case 0: me->improve_skill("unarmed", (int)(me->query("int") / 10));
                case 1: me->improve_skill("parry", (int)(me->query("int") / 10));
                case 2: me->improve_skill("strike", (int)(me->query("int") / 10));
                case 3: me->improve_skill("cuff", (int)(me->query("int") / 10));
                }
              }
        if ( (int)me->query("combat_exp") < 30000) 
        {
             me->add("potential",random(2));
             me->add("combat_exp",random((int)(me->query("int") / 10)));
        }
        return 1;
}
