// gate.c ���Ź�
// writed by shadow

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW "���Ź�" NOR );
        set("long",
"�������������������ڡ����Źء���������ǰ������һ���ߴ�ĺ�\n"
"ɫ��¥������������޿�������ж�ǰ������Ϊһ�����Źؾ��޷��ٻ���\n"
"���ˡ�\n");
        set("no_fight",1);

        set("exits", ([
                "north" : "/d/death/gateway",
        ]));
        set("no_dun",1);
        set("objects", ([
                __DIR__"npc/wgargoyle":1
        ]) );

        setup();
        replace_program(ROOM);
}
int heal_up(object who)
{
        who->set("eff_qi", (int)who->query("max_qi"));
        who->set("eff_jing", (int)who->query("max_jing"));

   message_vision("��Ȼһ��������ס��$N��\n", who);
   write("������Լ��ľ�����Ѫһ���Ӷ��ָ��ˡ�\n");

   return 1;
}

